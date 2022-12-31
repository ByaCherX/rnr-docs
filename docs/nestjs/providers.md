<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Providers</h1>

Providers are a fundamental concept in Nest. Many of the basic Nest classes may be treated as a provider – services, repositories, factories, helpers, and so on. The main idea of a provider is that it can be **injected** as a dependency; this means objects can create various relationships with each other, and the function of "wiring up" instances of objects can largely be delegated to the Nest runtime system.

## Services
Let's start by creating a simple CatsService. This service will be responsible for data storage and retrieval, and is designed to be used by the CatsController, so it's a good candidate to be defined as a provider.
```ts
import { Cat } from './interfaces/cat.interface';

@Injectable()
export class CatsService {
  private readonly cats: Cat[] = [];

  create(cat: Cat) {
    this.cats.push(cat);
  }
  findAll(): Cat[] {
    return this.cats;
  }
}
```

The CatsService is **injected** through the class constructor. Notice the use of the private syntax. This shorthand allows us to both declare and initialize the catsService member immediately in the same location.

## Dependency injection
Nest is built around the strong design pattern commonly known as Dependency injection.

In Nest, thanks to TypeScript capabilities, it's extremely easy to manage dependencies because they are resolved just by type. In the example below, Nest will resolve the catsService by creating and returning an instance of CatsService (or, in the normal case of a singleton, returning the existing instance if it has already been requested elsewhere). This dependency is resolved and passed to your controller's constructor (or assigned to the indicated property):
```ts
constructor(private catsService: CatsService) {}
```

## Scopes
Providers normally have a lifetime ("scope") synchronized with the application lifecycle. When the application is bootstrapped, every dependency must be resolved, and therefore every provider has to be instantiated. Similarly, when the application shuts down, each provider will be destroyed. However, there are ways to make your provider lifetime **request-scoped** as well. You can read more about these techniques [here](https://docs.nestjs.com/fundamentals/injection-scopes).

## Optional providers
Occasionally, you might have dependencies which do not necessarily have to be resolved. For instance, your class may depend on a **configuration object**, but if none is passed, the default values should be used. In such a case, the dependency becomes optional, because lack of the configuration provider wouldn't lead to errors.
```ts
@Injectable()
export class HttpService<T> {
  constructor(@Optional() @Inject('HTTP_OPTIONS') private httpClient: T) {}
}
```

## Property-based injection
The technique we've used so far is called constructor-based injection, as providers are injected via the constructor method. In some very specific cases, **property-based injection** might be useful. For instance, if your top-level class depends on either one or multiple providers, passing them all the way up by calling super() in sub-classes from the constructor can be very tedious. In order to avoid this, you can use the @Inject() decorator at the property level.
```ts
@Injectable()
export class HttpService<T> {
  @Inject('HTTP_OPTIONS') private readonly httpClient: T;
}
```

## Provider registration
Now that we have defined a provider (CatsService), and we have a consumer of that service (CatsController), we need to register the service with Nest so that it can perform the injection. We do this by editing our module file (app.module.ts) and adding the service to the providers array of the @Module() decorator.
```ts
@Module({
  controllers: [CatsController],
  providers: [CatsService],
})
export class AppModule {}
```


## DI fundemantals
Dependency injection is an inversion of control (IoC) technique wherein you delegate instantiation of dependencies to the IoC container (in our case, the NestJS runtime system), instead of doing it in your own code imperatively.
```ts
@Injectable()
export class CatsService {
  private readonly cats: Cat[] = [];

  findAll(): Cat[] {
    return this.cats;
  }
}
```

## Standard providers
```ts
@Module({
  controllers: [CatsController],
  providers: [CatsService],
})
```
Now that we see this explicit construction, we can understand the registration process. Here, we are clearly associating the token CatsService with the class CatsService. The short-hand notation is merely a convenience to simplify the most common use-case, where the token is used to request an instance of a class by the same name.

## Non-class-based provider tokens
This is matched by the standard pattern used with constructor based injection, where the token is also a class name. (Refer back to DI Fundamentals for a refresher on tokens if this concept isn't entirely clear). Sometimes, we may want the flexibility to use strings or symbols as the DI token. For example:
```ts
@Module({
  providers: [
    {
      provide: 'CONNECTION',
      useValue: connection,
    },
  ],
})
export class AppModule {}
```

We've previously seen how to inject a provider using the standard constructor based injection pattern. This pattern requires that the dependency be declared with a class name. The 'CONNECTION' custom provider uses a string-valued token. Let's see how to inject such a provider. To do so, we use the @Inject() decorator. This decorator takes a single argument - the token.
```ts
@Injectable()
export class CatsRepository {
  constructor(@Inject('CONNECTION') connection: Connection) {}
}
```

While we directly use the string 'CONNECTION' in the above examples for illustration purposes, for clean code organization, it's best practice to define tokens in a separate file, such as constants.ts. Treat them much as you would symbols or enums that are defined in their own file and imported where needed.

## Factory providers
The **useFactory** syntax allows for creating providers dynamically. The actual provider will be supplied by the value returned from a factory function. The factory function can be as simple or complex as needed. A simple factory may not depend on any other providers. A more complex factory can itself inject other providers it needs to compute its result. For the latter case, the factory provider syntax has a pair of related mechanisms:

1. The factory function can accept (optional) arguments.
2. The (optional) **inject** property accepts an array of providers that Nest will resolve and pass as arguments to the factory function during the instantiation process. Also, these providers can be marked as optional. The two lists should be correlated: Nest will pass instances from the **inject** list as arguments to the factory function in the same order. The example below demonstrates this.
```ts
const connectionProvider = {
  provide: 'CONNECTION',
  useFactory: (optionsProvider: OptionsProvider, optionalProvider?: string) => {
    const options = optionsProvider.get();
    return new DatabaseConnection(options);
  },
  inject: [OptionsProvider, { token: 'SomeOptionalProvider', optional: true }],
  //       \_____________/            \__________________/
  //        This provider              The provider with this
  //        is mandatory.              token can resolve to `undefined`.
};

@Module({
  providers: [
    connectionProvider,
    OptionsProvider,
    // { provide: 'SomeOptionalProvider', useValue: 'anything' },
  ],
})
export class AppModule {}
```

## Alias providers
The **useExisting** syntax allows you to create aliases for existing providers. This creates two ways to access the same provider. In the example below, the (string-based) token 'AliasedLoggerService' is an alias for the (class-based) token LoggerService. Assume we have two different dependencies, one for 'AliasedLoggerService' and one for LoggerService. If both dependencies are specified with **SINGLETON** scope, they'll both resolve to the same instance.
```ts
@Injectable()
class LoggerService {
  /* implementation details */
}

const loggerAliasProvider = {
  provide: 'AliasedLoggerService',
  useExisting: LoggerService,
};

@Module({
  providers: [LoggerService, loggerAliasProvider],
})
export class AppModule {}
```

## Asynchronous providers
At times, the application start should be delayed until one or more asynchronous tasks are completed. For example, you may not want to start accepting requests until the connection with the database has been established. You can achieve this using asynchronous providers.

The syntax for this is to use **async/await** with the **useFactory** syntax. The factory returns a **Promise**, and the factory function can **await** asynchronous tasks. Nest will await resolution of the promise before instantiating any class that depends on (injects) such a provider.
```ts
{ 
  provide: 'ASYNC_CONNECTION',
  useFactory: async () => {
    const connection = await createConnection(options);
    return connection;
  },
}
```

## Export custom provider
Like any provider, a custom provider is scoped to its declaring module. To make it visible to other modules, it must be exported. To export a custom provider, we can either use its token or the full provider object.
```ts
const connectionFactory = {
  provide: 'CONNECTION',
  useFactory: (optionsProvider: OptionsProvider) => {
    const options = optionsProvider.get();
    return new DatabaseConnection(options);
  },
  inject: [OptionsProvider],
};

@Module({
  providers: [connectionFactory],
  exports: ['CONNECTION'],
})
export class AppModule {}
```





