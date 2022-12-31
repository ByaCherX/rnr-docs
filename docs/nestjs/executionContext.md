<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Execution Context</h1>

Nest provides several utility classes that help make it easy to write applications that function across multiple application contexts (e.g., Nest HTTP server-based, microservices and WebSockets application contexts). These utilities provide information about the current execution context which can be used to build generic **guards**, **filters**, and **interceptors** that can work across a broad set of controllers, methods, and execution contexts.

We cover two such classes in this chapter: ``ArgumentsHost`` and ``ExecutionContext``.

## ArgumentsHost class
The ArgumentsHost class provides methods for retrieving the arguments being passed to a handler. It allows choosing the appropriate context (e.g., HTTP, RPC (microservice), or WebSockets) to retrieve the arguments from. The framework provides an instance of ArgumentsHost, typically referenced as a host parameter, in places where you may want to access it. For example, the ``catch()`` method of an exception filter is called with an ArgumentsHostinstance.

ArgumentsHost simply acts as an abstraction over a handler's arguments. For example, for HTTP server applications (when ``@nestjs/platform-express`` is being used), the host object encapsulates Express's [request, response, next] array, where request is the request object, response is the response object, and next is a function that controls the application's request-response cycle. On the other hand, for GraphQL applications, the host object contains the [root, args, context, info] array.

## Current application context
When building generic guards, filters, and interceptors which are meant to run across multiple application contexts, we need a way to determine the type of application that our method is currently running in. Do this with the ``getType()`` method of ``ArgumentsHost``:
```ts
if (host.getType() === 'http') {
  // do something that is only important in the context of regular HTTP requests (REST)
} else if (host.getType() === 'rpc') {
  // do something that is only important in the context of Microservice requests
} else if (host.getType<GqlContextType>() === 'graphql') {
  // do something that is only important in the context of GraphQL requests
}
```

## Host handler arguments
To retrieve the array of arguments being passed to the handler, one approach is to use the host object's ``getArgs()`` method.
```ts
const [req, res, next] = host.getArgs();
```

You can pluck a particular argument by index using the ``getArgByIndex()`` method:
```ts
const request = host.getArgByIndex(0);
const response = host.getArgByIndex(1);
```

The ``host.switchToHttp()`` helper call returns an **HttpArgumentsHost** object that is appropriate for the HTTP application context. The **HttpArgumentsHost** object has two useful methods we can use to extract the desired objects. We also use the Express type assertions in this case to return native Express typed objects:
```ts
const ctx = host.switchToHttp();
const request = ctx.getRequest<Request>();
const response = ctx.getResponse<Response>();
```




