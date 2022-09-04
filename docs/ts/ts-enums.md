  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">TS - Enums</h1>

nums are one of the few features TypeScript has which is not a type-level extension of JavaScript.

Enums allow a developer to define a set of named constants. Using enums can make it easier to document intent, or create a set of distinct cases. TypeScript provides both numeric and string-based enums.

## Numeric enums
We’ll first start off with numeric enums, which are probably more familiar if you’re coming from other languages. An enum can be defined using the `enum` keyword.
```ts
enum Direction {
  Up = 1,
  Down,
  Left,
  Right,
}
```
Above, we have a numeric enum where Up is initialized with 1. All of the following members are auto-incremented from that point on. In other words, Direction.Up has the value 1, Down has 2, Left has 3, and Right has 4.

Using an enum is simple: just access any member as a property off of the enum itself, and declare types using the name of the enum:
```ts 
enum UserResponse {
  No = 0,
  Yes = 1,
}
function respond(recipient: string, message: UserResponse): void {
  // ...
}
respond("Princess Caroline", UserResponse.Yes);
```
Numeric enums can be mixed in computed and constant members (see below). The short story is, enums without initializers either need to be first, or have to come after numeric enums initialized with numeric constants or other constant enum members. In other words, the following isn’t allowed:
```ts
enum E {
  A = getSomeValue(),
  B,
}
```

## String enums
String enums are a similar concept, but have some subtle runtime differences as documented below. In a string enum, each member has to be constant-initialized with a string literal, or with another string enum member.
```ts
enum Direction {
  Up = "UP",
  Down = "DOWN",
  Left = "LEFT",
  Right = "RIGHT",
}
```

## Enums at compile time
Even though Enums are real objects that exist at runtime, the `keyof` keyword works differently than you might expect for typical objects. Instead, use `keyof typeof` to get a Type that represents all Enum keys as strings.
```ts
enum LogLevel {
  ERROR,
  WARN,
  INFO,
  DEBUG,
}
 
/**
 * This is equivalent to:
 * type LogLevelStrings = 'ERROR' | 'WARN' | 'INFO' | 'DEBUG';
 */
type LogLevelStrings = keyof typeof LogLevel;
 
function printImportant(key: LogLevelStrings, message: string) {
  const num = LogLevel[key];
  if (num <= LogLevel.WARN) {
    console.log("Log level key is:", key);
    console.log("Log level value is:", num);
    console.log("Log level message is:", message);
  }
}
printImportant("ERROR", "This is a message");
```

### Reverse mappings
In addition to creating an object with property names for members, numeric enums members also get a reverse mapping from enum values to enum names. For example, in this example:
```ts
enum Enum {
  A,
}
 
let a = Enum.A;
let nameOfA = Enum[a]; // "A"
```

### const enums
In most cases, enums are a perfectly valid solution. However sometimes requirements are tighter. To avoid paying the cost of extra generated code and additional indirection when accessing enum values, it’s possible to use `const` enums. Const enums are defined using the `const` modifier on our enums:
```ts
const enum Enum {
  A = 1,
  B = A * 2,
}
```









