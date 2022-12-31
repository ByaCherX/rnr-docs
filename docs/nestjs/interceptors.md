<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Interceptors</h1>

An interceptor is a class annotated with the ``@Injectable()`` decorator and implements the **NestInterceptor** interface.

Interceptors have a set of useful capabilities which are inspired by the **Aspect Oriented Programming (AOP)** technique. They make it possible to:
  * bind extra logic before / after method execution
  * transform the result returned from a function
  * transform the exception thrown from a function
  * extend the basic function behavior
  * completely override a function depending on specific conditions (e.g., for caching purposes)

## Basics
Each interceptor implements the ``intercept()`` method, which takes two arguments. The first one is the ExecutionContext instance (exactly the same object as for guards). The ExecutionContext inherits from ArgumentsHost. We saw ArgumentsHost before in the exception filters chapter. There, we saw that it's a wrapper around arguments that have been passed to the original handler, and contains different arguments arrays based on the type of the application. You can refer back to the **exception filters** for more on this topic.


### Execution context
By extending **ArgumentsHost**, **ExecutionContext** also adds several new helper methods that provide additional details about the current execution process. These details can be helpful in building more generic interceptors that can work across a broad set of controllers, methods, and execution contexts.

## Call handler
The second argument is a **CallHandler**. The CallHandler interface implements the ``handle()`` method, which you can use to invoke the route handler method at some point in your interceptor. If you don't call the handle() method in your implementation of the intercept() method, the route handler method won't be executed at all.

This approach means that the intercept() method effectively wraps the request/response stream. As a result, you may implement custom logic both before and after the execution of the final route handler. It's clear that you can write code in your intercept() method that executes before calling handle(), but how do you affect what happens afterward? Because the handle() method returns an Observable, we can use powerful *RxJS* operators to further manipulate the response. Using Aspect Oriented Programming terminology, the invocation of the route handler (i.e., calling handle()) is called a Pointcut, indicating that it's the point at which our additional logic is inserted.

Consider, for example, an incoming ``POST /cats`` request. This request is destined for the create() handler defined inside the **CatsController**. If an interceptor which does not call the handle() method is called anywhere along the way, the create() method won't be executed. Once handle() is called (and its Observable has been returned), the ``create()`` handler will be triggered. And once the response stream is received via the **Observable**, additional operations can be performed on the stream, and a final result returned to the caller.

## Aspect interception
The first use case we'll look at is to use an interceptor to log user interaction (e.g., storing user calls, asynchronously dispatching events or calculating a timestamp). We show a simple **LoggingInterceptor** below:
```ts
import { Injectable, NestInterceptor, ExecutionContext, CallHandler } from '@nestjs/common';
import { Observable } from 'rxjs';
import { tap } from 'rxjs/operators';

@Injectable()
export class LoggingInterceptor implements NestInterceptor {
  intercept(context: ExecutionContext, next: CallHandler): Observable<any> {
    console.log('Before...');

    const now = Date.now();
    return next
      .handle()
      .pipe(
        tap(() => console.log(`After... ${Date.now() - now}ms`)),
      );
  }
}
```
Since ``handle()`` returns an RxJS **Observable**, we have a wide choice of operators we can use to manipulate the stream. In the example above, we used the ``tap()`` operator, which invokes our anonymous logging function upon graceful or exceptional termination of the observable stream, but doesn't otherwise interfere with the response cycle.














