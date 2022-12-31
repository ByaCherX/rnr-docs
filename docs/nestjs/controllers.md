<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Controllers</h1>

Controllers are responsible for handling incoming **requests** and returning **responses** to the client.

A controller's purpose is to receive specific requests for the application. The **routing** mechanism controls which controller receives which requests. Frequently, each controller has more than one route, and different routes can perform different actions.

In order to create a basic controller, we use classes and **decorators**. Decorators associate classes with required metadata and enable Nest to create a routing map (tie requests to the corresponding controllers).

## Routing
In the following example we'll use the ``@Controller()`` decorator, which is required to define a basic controller. We'll specify an optional route path prefix of cats. Using a path prefix in a ``@Controller()`` decorator allows us to easily group a set of related routes, and minimize repetitive code. For example, we may choose to group a set of routes that manage interactions with a customer entity under the route /customers. In that case, we could specify the path prefix customers in the ``@Controller()`` decorator so that we don't have to repeat that portion of the path for each route in the file.
```ts
@Controller('cats')
export class CatsController {
  @Get()
  findAll(): string {
    return 'This action returns all cats';
  }
}
```

The ``@Get()`` HTTP request method decorator before the ``findAll()`` method tells Nest to create a handler for a specific endpoint for HTTP requests. The endpoint corresponds to the HTTP request method (GET in this case) and the route path. What is the route path? The route path for a handler is determined by concatenating the (optional) prefix declared for the controller, and any path specified in the method's decorator. Since we've declared a prefix for every route ( cats), and haven't added any path information in the decorator, Nest will map GET /cats requests to this handler. As mentioned, the path includes both the optional controller path prefix and any path string declared in the request method decorator. For example, a path prefix of customers combined with the decorator ``@Get('profile')`` would produce a route mapping for requests like GET /customers/profile.

|       Decorator       |   Express   |
|-----------------------|-------------|
| @Request(), @Req()    | req         |
| @Response(), @Res()   | res         |
| @Next()               | next        |
| @Session()            | req.session |
| @Param(key?:string)   | req.params  |
| @Body(key?:string)    | req.body    |
| @Query(key?:string)   | req.query   |
| @Headers(name?:string)| req.headers |
| @Ip()                 | req.ip      |
| @HostParam()          | req.hosts   |

## Resources
Earlier, we defined an endpoint to fetch the cats resource (GET route). We'll typically also want to provide an endpoint that creates new records. For this, let's create the POST handler:
```ts
@Controller('cats')
export class CatsController {
  @Post()
  create(): string {
    return 'This action adds a new cat';
  }
}
```

## Headers
To specify a custom response header, you can either use a ``@Header()`` decorator or a library-specific response object (and call res.header() directly).
```ts
@Post()
@Header('Cache-Control', 'none')
create() {
  return 'This action adds a new cat';
}
```

## Redirection
To redirect a response to a specific URL, you can either use a ``@Redirect()`` decorator or a library-specific response object (and call res.redirect() directly).
```ts
@Get()
@Redirect('https://nestjs.com', 301)
```

## Asynchronicity
We love modern JavaScript and we know that data extraction is mostly asynchronous. That's why Nest supports and works well with **async** functions.
```ts
@Get()
async findAll(): Promise<any[]> {
  return [];
}
```

## Request payloads
we need to determine the **DTO** (Data Transfer Object) schema. A DTO is an object that defines how the data will be sent over the network. We could determine the DTO schema by using TypeScript interfaces, or by simple classes. Interestingly, we recommend using classes here. Why? Classes are part of the JavaScript ES6 standard, and therefore they are preserved as real entities in the compiled JavaScript. On the other hand, since TypeScript interfaces are removed during the transpilation, Nest can't refer to them at runtime. This is important because features such as Pipes enable additional possibilities when they have access to the metatype of the variable at runtime.
```ts
export class CreateCatDto {
  name: string,
  age: number,
  breed: string
}
```








