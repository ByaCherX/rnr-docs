<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">TypeScript - Deep Dive</h1>

Structuring modules to give the exact API shape you want can be tricky. For example, we might want a module that can be invoked with or without new to produce different types, has a variety of named types exposed in a hierarchy, and has some properties on the module object as well.

By reading this guide, you’ll have the tools to write complex declaration files that expose a friendly API surface. This guide focuses on module (or UMD) libraries because the options here are more varied.

## Types
If you’re reading this guide, you probably already roughly know what a type in TypeScript is. To be more explicit, though, a type is introduced with:
* A type alias declaration (type sn = number | string;)
* An interface declaration (interface I { x: number[]; })
* A class declaration (class C { })
* An enum declaration (enum E { A, B, C })
* An import declaration which refers to a type

Each of these declaration forms creates a new type name.

## Values
As with types, you probably already understand what a value is. Values are runtime names that we can reference in expressions. For example ``let x = 5;`` creates a value called x.

Again, being explicit, the following things create values:
* let, const, and var declarations
* A namespace or module declaration which contains a value
* An enum declaration
* A class declaration
* An import declaration which refers to a value
* A function declaration

## User Combinations
Let’s say we wrote a module file foo.d.ts:
```ts
export var SomeVar: { a: SomeType };
export interface SomeType {
  count: number;
}
```

Then consumed it:
```ts
import * as foo from "./foo";
let x: foo.SomeType = foo.SomeVar.a;
console.log(x.count);
```

This works well enough, but we might imagine that SomeType and SomeVar were very closely related such that you’d like them to have the same name. We can use combining to present these two different objects (the value and the type) under the same name Bar:
```ts
export var Bar: { a: Bar };
export interface Bar {
  count: number;
}
```

This presents a very good opportunity for destructuring in the consuming code:
```ts
import { Bar } from "./foo";
let x: Bar = Bar.a;
console.log(x.count);
```
Again, we’ve used Bar as both a type and a value here. Note that we didn’t have to declare the Bar value as being of the Bar type — they’re independent.






























