<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Pipes</h1>

A pipe is a class annotated with the ``@Injectable()`` decorator, which implements the **PipeTransform** interface

Pipes have two typical use cases:

* **transformation**: transform input data to the desired form (e.g., from string to integer)
* **validation**: evaluate input data and if valid, simply pass it through unchanged; otherwise, throw an exception when the data is incorrect

In both cases, pipes operate on the arguments being processed by a controller route handler. Nest interposes a pipe just before a method is invoked, and the pipe receives the arguments destined for the method and operates on them. Any transformation or validation operation takes place at that time, after which the route handler is invoked with any (potentially) transformed arguments.

Nest comes with a number of built-in pipes that you can use out-of-the-box. You can also build your own custom pipes. In this chapter, we'll introduce the built-in pipes and show how to bind them to route handlers. We'll then examine several custom-built pipes to show how you can build one from scratch.

## Built-in pipes
Nest comes with nine pipes available out-of-the-box:
* ValidationPipe
* ParseIntPipe
* ParseFloatPipe
* ParseBoolPipe
* ParseArrayPipe
* ParseUUIDPipe
* ParseEnumPipe
* DefaultValuePipe
* ParseFilePipe

Let's take a quick look at using ParseIntPipe. This is an example of the transformation use case, where the pipe ensures that a method handler parameter is converted to a JavaScript integer (or throws an exception if the conversion fails).

## Binding pipes
To use a pipe, we need to bind an instance of the pipe class to the appropriate context. In our **ParseIntPipe** example, we want to associate the pipe with a particular route handler method, and make sure it runs before the method is called. We do so with the following construct, which we'll refer to as binding the pipe at the method parameter level:
```ts
@Get(':id')
async findOne(@Param('id', ParseIntPipe) id: number) {
  return this.catsService.findOne(id);
}
```

## Custom pipes
As mentioned, you can build your own custom pipes. While Nest provides a robust built-in **ParseIntPipe** and **ValidationPipe**, let's build simple custom versions of each from scratch to see how custom pipes are constructed.

We start with a simple **ValidationPipe**. Initially, we'll have it simply take an input value and immediately return the same value, behaving like an identity function.

```ts
@Injectable()
export class ValidationPipe implements PipeTransform {
  transform(value: any, metadata: ArgumentMetadata) {
    return value;
  }
}
```

Every pipe must implement the ``transform()`` method to fulfill the PipeTransform interface contract. This method has two parameters:
* value
* metadata

The value parameter is the currently processed method argument (before it is received by the route handling method), and **metadata** is the currently processed method argument's metadata. The metadata object has these properties:
```ts
export interface ArgumentMetadata {
  type: 'body' | 'query' | 'param' | 'custom';
  metatype?: Type<unknown>;
  data?: string;
}
```

## Schema based validation
Let's make our validation pipe a little more useful. Take a closer look at the ``create()`` method of the **CatsController**, where we probably would like to ensure that the post body object is valid before attempting to run our service method.

Nest works well with the [class-validator](https://github.com/typestack/class-validator) library. This powerful library allows you to use decorator-based validation. Decorator-based validation is extremely powerful, especially when combined with Nest's Pipe capabilities since we have access to the metatype of the processed property. Before we start, we need to install the required packages (class-validator & class-transformer)

Once these are installed, we can add a few decorators to the CreateCatDto class. Here we see a significant advantage of this technique: the CreateCatDto class remains the single source of truth for our Post body object (rather than having to create a separate validation class).

```ts
import { IsString, IsInt } from 'class-validator';

export class CreateCatDto {
  @IsString()
  name: string;

  @IsInt()
  age: number;

  @IsString()
  breed: string;
}
```

Now we can create a **ValidationPipe** class that uses these annotations.

```ts
import { PipeTransform, Injectable, ArgumentMetadata, BadRequestException } from '@nestjs/common';
import { validate } from 'class-validator';
import { plainToInstance } from 'class-transformer';

@Injectable()
export class ValidationPipe implements PipeTransform<any> {
  async transform(value: any, { metatype }: ArgumentMetadata) {
    if (!metatype || !this.toValidate(metatype)) {
      return value;
    }
    const object = plainToInstance(metatype, value);
    const errors = await validate(object);
    if (errors.length > 0) {
      throw new BadRequestException('Validation failed');
    }
    return value;
  }

  private toValidate(metatype: Function): boolean {
    const types: Function[] = [String, Boolean, Number, Array, Object];
    return !types.includes(metatype);
  }
}
```
Let's go through this code. First, note that the ``transform()`` method is marked as async. This is possible because Nest supports both synchronous and asynchronous pipes. We make this method async because some of the class-validator validations can be async (utilize Promises).

Next note that we are using destructuring to extract the metatype field (extracting just this member from an **ArgumentMetadata**) into our metatype parameter. This is just shorthand for getting the full **ArgumentMetadata** and then having an additional statement to assign the metatype variable.

Next, note the helper function ``toValidate()``. It's responsible for bypassing the validation step when the current argument being processed is a native JavaScript type (these can't have validation decorators attached, so there's no reason to run them through the validation step).

Next, we use the class-transformer function plainToInstance() to transform our plain JavaScript argument object into a typed object so that we can apply validation. The reason we must do this is that the incoming post body object, when deserialized from the network request, does not have any type information (this is the way the underlying platform, such as Express, works). Class-validator needs to use the validation decorators we defined for our DTO earlier, so we need to perform this transformation to treat the incoming body as an appropriately decorated object, not just a plain vanilla object.

Finally, as noted earlier, since this is a validation pipe it either returns the value unchanged, or throws an exception.

The last step is to bind the **ValidationPipe**. Pipes can be parameter-scoped, method-scoped, controller-scoped, or global-scoped. Earlier, with our Joi-based validation pipe, we saw an example of binding the pipe at the method level. In the example below, we'll bind the pipe instance to the route handler ``@Body()`` decorator so that our pipe is called to validate the post body.






