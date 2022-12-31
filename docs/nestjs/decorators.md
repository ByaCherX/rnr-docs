<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Decorators</h1>

Nest is built around a language feature called **decorators**. Decorators are a well-known concept in a lot of commonly used programming languages, but in the JavaScript world, they're still relatively new. In order to better understand how decorators work, we recommend reading [this article](https://medium.com/google-developers/exploring-es7-decorators-76ecb65fb841).

In order to make your code more readable and transparent, you can create a ``@User()`` decorator and reuse it across all of your controllers.

```ts
import { createParamDecorator, ExecutionContext } from '@nestjs/common';

export const User = createParamDecorator(
  (data: unknown, ctx: ExecutionContext) => {
    const request = ctx.switchToHttp().getRequest();
    return request.user;
  },
);
```

Then, you can simply use it wherever it fits your requirements.
```ts
@Get()
async findOne(@User() user: UserEntity) {
  console.log(user);
}
```

......







