<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Validation</h1>

It is best practice to validate the correctness of any data sent into a web application. To automatically validate incoming requests, Nest provides several pipes available right out-of-the-box:
  * ValidationPipe
  * ParseIntPipe
  * ParseBoolPipe
  * ParseArrayPipe
  * ParseUUIDPipe

The ``ValidationPipe`` makes use of the powerful ``class-validator`` package and its declarative validation decorators. The ``ValidationPipe`` provides a convenient approach to enforce validation rules for all incoming client payloads, where the specific rules are declared with simple annotations in local class/DTO declarations in each module.

> Using the built-in ValidationPipe, we first install the required dependency -> class-validator & class-transformer

## Auto-validation
We'll start by binding ``ValidationPipe`` at the application level, thus ensuring all endpoints are protected from receiving incorrect data.
```ts
async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  app.useGlobalPipes(new ValidationPipe());
  await app.listen(3000);
}
bootstrap();
```

Now we can add a few validation rules in our **CreateUserDto**. We do this using decorators provided by the ``class-validator`` package, described in detail here. In this fashion, any route that uses the **CreateUserDto** will automatically enforce these validation rules.
```ts
import { IsEmail, IsNotEmpty } from 'class-validator';

export class CreateUserDto {
  @IsEmail()
  email: string;

  @IsNotEmpty()
  password: string;
}
```

..... ! Experimential
















