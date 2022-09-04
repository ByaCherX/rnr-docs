<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## The Primitives
JavaScript has three very commonly used primitives: `string`, `number`, and `boolean`. Each has a corresponding type in TypeScript. As you might expect, these are the same names you’d see if you used the JavaScript typeof operator on a value of those types:

* `string` represents string values like `"Hello, world"`
* `number` is for numbers like 42. JavaScript does not have a special runtime value for integers, so there’s no equivalent to `int` or `float` - everything is simply `number`
* `boolean` is for the two values `true` and `false`

## Arrays
To specify the type of an array like <dclrTS>[1, 2, 3]</dclrTS>, you can use the syntax <dclrTS>number[]</dclrTS>; this syntax works for any type (e.g. <dclrTS>string[]</dclrTS> is an array of strings, and so on). You may also see this written as <dclrTS>Array<number></dclrTS>, which means the same thing. We’ll learn more about the syntax <dclrTS>T`<U>`</dclrTS> when we cover generics.

### any
TypeScript also has a special type, `any`, that you can use whenever you don’t want a particular value to cause typechecking errors.

When a value is of type `any`, you can access any properties of it (which will in turn be of type `any`), call it like a function, assign it to (or from) a value of any type, or pretty much anything else that’s syntactically legal:
```ts
let obj: any = { x: 0 };
// None of the following lines of code will throw compiler errors.
// Using `any` disables all further type checking, and it is assumed 
// you know the environment better than TypeScript.
obj.foo();
obj();
obj.bar = 100;
obj = "hello";
const n: number = obj;
```

## Type Annotations on Variables
When you declare a variable using `const`, `var`, or `let`, you can optionally add a type annotation to explicitly specify the type of the variable:
```ts
let myName: string = "Alice";
/* or */
let myName = "Alice";
```

## Functions
Functions are the primary means of passing data around in JavaScript. TypeScript allows you to specify the types of both the input and output values of functions.

### Parameter Type Annotations
When you declare a function, you can add type annotations after each parameter to declare what types of parameters the function accepts. Parameter type annotations go after the parameter name:
```ts
// Parameter type annotation
function greet(name: string) {
  console.log("Hello, " + name.toUpperCase() + "!!");
}
```

### Return Type Annotations
You can also add return type annotations. Return type annotations appear after the parameter list:
```ts
function getFavoriteNumber(): number {
  return 26;
}
```
Much like variable type annotations, you usually don’t need a return type annotation because TypeScript will infer the function’s return type based on its `return` statements.

## Object Types
Apart from primitives, the most common sort of type you’ll encounter is an object type. This refers to any JavaScript value with properties, which is almost all of them! To define an object type, we simply list its properties and their types.

For example, here’s a function that takes a point-like object:
```ts
// The parameter's type annotation is an object type
function printCoord(pt: { x: number; y: number }) {
  console.log("The coordinate's x value is " + pt.x);
  console.log("The coordinate's y value is " + pt.y);
}
printCoord({ x: 3, y: 7 });
```
Here, we annotated the parameter with a type with two properties - *x* and *y* - which are both of type `number`. You can use *,* or *;* to separate the properties, and the last separator is optional either way.

The type part of each property is also optional. If you don’t specify a type, it will be assumed to be `any`.

### Optional Properties
Object types can also specify that some or all of their properties are optional. To do this, add a <dclrTS>?</dclrTS> after the property name:
```ts
function printName(obj: { first: string; last?: string }) {
  // ...
}
// Both OK
printName({ first: "Bob" });
printName({ first: "Alice", last: "Alisson" });
```

## Union Types
TypeScript’s type system allows you to build new types out of existing ones using a large variety of operators. Now that we know how to write a few types, it’s time to start combining them in interesting ways.

### Defining a Union Type
The first way to combine types you might see is a union type. A union type is a type formed from two or more other types, representing values that may be any one of those types. We refer to each of these types as the union’s members.
```ts
function printId(id: number | string) {
  console.log("Your ID is: " + id);
}
printId(101);                // OK

printId("202");              // OK

printId({ myID: 22342 });    // Error
```

### Working with Union Types
It’s easy to provide a value matching a union type - simply provide a type matching any of the union’s members. If you have a value of a union type, how do you work with it?

TypeScript will only allow you to do things with the union if that thing is valid for every member of the union. For example, if you have the union `string | number`, you can’t use methods that are only available on `string`:
```ts
function printId(id: number | string) {
  console.log(id.toUpperCase());
}
//  Property 'toUpperCase' does not exist on type 'string | number'.
//    Property 'toUpperCase' does not exist on type 'number'.
```

The solution is to narrow the union with code, the same as you would in JavaScript without type annotations. *Narrowing* occurs when TypeScript can deduce a more specific type for a value based on the structure of the code.

Another example is to use a function like `Array.isArray`:
```ts
function welcomePeople(x: string[] | string) {
  if (Array.isArray(x)) {
    // Here: 'x' is 'string[]'
    console.log("Hello, " + x.join(" and "));
  } else {
    // Here: 'x' is 'string'
    console.log("Welcome lone traveler " + x);
  }
}
```

## Type Aliases
We’ve been using object types and union types by writing them directly in type annotations. This is convenient, but it’s common to want to use the same type more than once and refer to it by a single name.

A type *alias* is exactly that - a name for any *type*. The syntax for a type alias is:
```ts
type Point = {
  x: number;
  y: number;
};
 
// Exactly the same as the earlier example
function printCoord(pt: Point) {
  console.log("The coordinate's x value is " + pt.x);
  console.log("The coordinate's y value is " + pt.y);
}
 
printCoord({ x: 100, y: 100 });
```
You can actually use a type alias to give a name to any type at all, not just an object type. For example, a type alias can name a union type:
```ts
type ID = number | string;
type UserInputSanitizedString = string;
```

## Interfaces
An interface declaration is another way to name an object type:
```ts
interface Point {
  x: number;
  y: number;
}
 
function printCoord(pt: Point) {
  console.log("The coordinate's x value is " + pt.x);
  console.log("The coordinate's y value is " + pt.y);
}
 
printCoord({ x: 100, y: 100 });
```
Just like when we used a type alias above, the example works just as if we had used an anonymous object type. TypeScript is only concerned with the structure of the value we passed to `printCoord` - it only cares that it has the expected properties. Being concerned only with the structure and capabilities of types is why we call TypeScript a structurally typed type system.

#### Differences Between Type Aliases and Interfaces
Type aliases and interfaces are very similar, and in many cases you can choose between them freely. Almost all features of an `interface` are available in `type`, the key distinction is that a type cannot be re-opened to add new properties vs an interface which is always extendable.


## Type Assertions
Sometimes you will have information about the type of a value that TypeScript can’t know about.

For example, if you’re using `document.getElementById`, TypeScript only knows that this will return some kind of `HTMLElement`, but you might know that your page will always have an `HTMLCanvasElement` with a given ID.


In this situation, you can use a *type assertion* to specify a more specific type:
```ts
const myCanvas = document.getElementById("main_canvas") as HTMLCanvasElement;
```

## Literal Types
In addition to the general types `string` and `number`, we can refer to specific strings and numbers in type positions.

One way to think about this is to consider how JavaScript comes with different ways to declare a variable. Both `var` and `let` allow for changing what is held inside the variable, and `const` does not. This is reflected in how TypeScript creates types for literals.
```ts
let changingString: string
const constantString: "Hello World"
let x: "hello" = "hello";   // just only assign "hello"
```

### Non-null Assertion Operator (Postfix ! )
TypeScript also has a special syntax for removing `null` and `undefined` from a type without doing any explicit checking. Writing `!` after any expression is effectively a type assertion that the value isn’t `null` or `undefined`:
```ts
function liveDangerously(x?: number | null) {
  // No error
  console.log(x!.toFixed());
}
```

## Enums
Enums are a feature added to JavaScript by TypeScript which allows for describing a value which could be one of a set of possible named constants. Unlike most TypeScript features, this is not a type-level addition to JavaScript but something added to the language and runtime. Because of this, it’s a feature which you should know exists, but maybe hold off on using unless you are sure. You can read more about enums in the Enum reference page.







