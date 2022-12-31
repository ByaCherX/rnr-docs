<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Exception filters</h1>

Nest comes with a built-in **exceptions layer** which is responsible for processing all unhandled exceptions across an application. When an exception is not handled by your application code, it is caught by this layer, which then automatically sends an appropriate user-friendly response.

Out of the box, this action is performed by a built-in global exception filter, which handles exceptions of type **HttpException** (and subclasses of it). When an exception is unrecognized (is neither HttpException nor a class that inherits from HttpException), the built-in exception filter generates the following default JSON response:
```ts
{ "statusCode": 500, "message": "Internal server error" }
```

## Throwing standard exceptions
Nest provides a built-in HttpException class, exposed from the ``@nestjs/common`` package. For typical HTTP REST/GraphQL API based applications, it's best practice to send standard HTTP response objects when certain error conditions occur.

For example, in the CatsController, we have a ``findAll()`` method (a GET route handler). Let's assume that this route handler throws an exception for some reason. To demonstrate this, we'll hard-code it as follows:
```ts
@Get()
async findAll() {
  throw new HttpException('Forbidden', HttpStatus.FORBIDDEN);
}
```

Here's an example overriding the entire response body:
```ts
@Get()
async findAll() {
  throw new HttpException({
    status: HttpStatus.FORBIDDEN,
    error: 'This is a custom message',
  }, HttpStatus.FORBIDDEN);
}
// response: { "status": 403, "error": "This is a custom message" }
```

## Custom Exception
In many cases, you will not need to write custom exceptions, and can use the built-in Nest HTTP exception, as described in the next section. If you do need to create customized exceptions, it's good practice to create your own exceptions hierarchy, where your custom exceptions inherit from the base HttpException class. With this approach, Nest will recognize your exceptions, and automatically take care of the error responses. Let's implement such a custom exception:
```ts
export class ForbiddenException extends HttpException {
  constructor() {
    super('Forbidden', HttpStatus.FORBIDDEN);
  }
}
```

Since **ForbiddenException** extends the base **HttpException**, it will work seamlessly with the built-in exception handler, and therefore we can use it inside the ``findAll()`` method.

```ts
@Get()
async findAll() {
  throw new ForbiddenException();
}
```

## Built-in HTTP exceptions
Nest provides a set of standard exceptions that inherit from the base **HttpException**. These are exposed from the ``@nestjs/common`` package, and represent many of the most common HTTP exceptions:
* BadRequestException
* UnauthorizedException
* NotFoundException
* ForbiddenException
* NotAcceptableException
* RequestTimeoutException
* ConflictException
* GoneException
* HttpVersionNotSupportedException
* PayloadTooLargeException
* UnsupportedMediaTypeException
* UnprocessableEntityException
* InternalServerErrorException
* NotImplementedException
* ImATeapotException
* MethodNotAllowedException
* BadGatewayException
* ServiceUnavailableException
* GatewayTimeoutException
* PreconditionFailedException

## Exception filters
While the base (built-in) exception filter can automatically handle many cases for you, you may want full control over the exceptions layer. For example, you may want to add logging or use a different JSON schema based on some dynamic factors. **Exception filters** are designed for exactly this purpose. They let you control the exact flow of control and the content of the response sent back to the client.

Let's create an exception filter that is responsible for catching exceptions which are an instance of the ``HttpException`` class, and implementing custom response logic for them. To do this, we'll need to access the underlying platform Request and Response objects. We'll access the Request object so we can pull out the original url and include that in the logging information. We'll use the Response object to take direct control of the response that is sent, using the ``response.json()`` method.

```ts
@Catch(HttpException)
export class HttpExceptionFilter implements ExceptionFilter {
  catch(exception: HttpException, host: ArgumentsHost) {
    const ctx = host.switchToHttp();
    const response = ctx.getResponse<Response>();
    const request = ctx.getRequest<Request>();
    const status = exception.getStatus();

    response
      .status(status)
      .json({
        statusCode: status,
        timestamp: new Date().toISOString(),
        path: request.url,
      });
  }
}
```

The ``@Catch(HttpException)`` decorator binds the required metadata to the exception filter, telling Nest that this particular filter is looking for exceptions of type **HttpException** and nothing else. The ``@Catch()`` decorator may take a single parameter, or a comma-separated list. This lets you set up the filter for several types of exceptions at once.

## Arguments host
Let's look at the parameters of the ``catch()`` method. The exception parameter is the exception object currently being processed. The host parameter is an ArgumentsHost object. ArgumentsHost is a powerful utility object that we'll examine further in the [execution context]() chapter*. In this code sample, we use it to obtain a reference to the Request and Response objects that are being passed to the original request handler (in the controller where the exception originates). In this code sample, we've used some helper methods on ArgumentsHost to get the desired **Request** and **Response** objects. Learn more about ArgumentsHosthere.

*The reason for this level of abstraction is that **ArgumentsHost** functions in all contexts (e.g., the HTTP server context we're working with now, but also Microservices and WebSockets). In the execution context chapter we'll see how we can access the appropriate underlying arguments for any execution context with the power of **ArgumentsHost** and its helper functions. This will allow us to write generic exception filters that operate across all contexts.

## Binding filters
Let's tie our new **HttpExceptionFilter** to the CatsController's ``create()`` method.
```ts
@Post()
@UseFilters(new HttpExceptionFilter())
async create(@Body() createCatDto: CreateCatDto) {
  throw new ForbiddenException();
}
```




