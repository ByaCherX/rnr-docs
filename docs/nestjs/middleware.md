<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Middleware</h1>

Middleware is a function which is called before the route handler. Middleware functions have access to the **request** and **response** objects, and the ``next()`` middleware function in the application’s request-response cycle. The next middleware function is commonly denoted by a variable named next.

Middleware functions can perform the following tasks:
* execute any code.
* make changes to the request and the response objects.
* end the request-response cycle.
* call the next middleware function in the stack.
* if the current middleware function does not end the request-response cycle, it must call next() to pass control to the next middleware function. Otherwise, the request will be left hanging.

You implement custom Nest middleware in either a function, or in a class with an ``@Injectable()`` decorator. The class should implement the NestMiddleware interface, while the function does not have any special requirements. Let's start by implementing a simple middleware feature using the class method.
```ts
@Injectable()
export class LoggerMiddleware implements NestMiddleware {
  use(req: Request, res: Response, next: NextFunction) {
    console.log('Request...');
    next();
  }
}
```

## Applying middleware
There is no place for middleware in the ``@Module()`` decorator. Instead, we set them up using the ``configure()`` method of the module class. Modules that include middleware have to implement the NestModule interface. Let's set up the **LoggerMiddleware** at the **AppModule** level.
```ts
@Module({
  imports: [CatsModule],
})
export class AppModule implements NestModule {
  configure(consumer: MiddlewareConsumer) {
    consumer
      .apply(LoggerMiddleware)
      .forRoutes({ path:'cats', method: RequestMethod.GET });
  }
}
```

## Excluding routes
At times we want to exclude certain routes from having the middleware applied. We can easily exclude certain routes with the ``exclude()`` method. This method can take a single string, multiple strings, or a RouteInfo object identifying routes to be excluded, as shown below:
```ts
consumer
  .apply(LoggerMiddleware)
  .exclude(
    { path: 'cats', method: RequestMethod.GET },
    { path: 'cats', method: RequestMethod.POST },
    'cats/(.*)',
  )
  .forRoutes(CatsController);
```

## Functional middleware
The **LoggerMiddleware** class we've been using is quite simple. It has no members, no additional methods, and no dependencies. Why can't we just define it in a simple function instead of a class? In fact, we can. This type of middleware is called functional middleware. Let's transform the logger middleware from class-based into functional middleware to illustrate the difference:
```ts
export function logger(req: Request, res: Response, next: NextFunction) {
  console.log(`Request...`);
  next();
};
```

## Multiple middleware
As mentioned above, in order to bind multiple middleware that are executed sequentially, simply provide a comma separated list inside the ``apply()`` method:
```ts
consumer.apply(cors(), helmet(), logger).forRoutes(CatsController);
```






