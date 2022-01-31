<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

The purpose of this guide is to teach you how to write a high-quality definition file. This guide is structured by showing documentation for some API, along with sample usage of that API, and explaining how to write the corresponding declaration.

These examples are ordered in approximately increasing order of complexity.

## Objects with Properties

**Code**
```ts
let result = myLib.makeGreeting("hello, world");
console.log("The computed greeting is:" + result);

let count = myLib.numberOfGreetings;
```
**Declaration**
```ts
declare namespace myLib {
  function makeGreeting(s: string): string;
  let numberOfGreetings: number;
}
```

## Overloaded Functions

**Code**
```ts
let x: Widget = getWidget(43);

let arr: Widget[] = getWidget("all of them");
```
**Declaration**
```ts
declare function getWidget(n: number): Widget;
declare function getWidget(s: string): Widget[];
```

## Reusable Types (Interfaces)

**Code**
```ts
greet({
  greeting: "hello world",
  duration: 4000
});
```
**Declaration**
```ts
interface GreetingSettings {
  greeting: string;
  duration?: number;
  color?: string;
}

declare function greet(setting: GreetingSettings): void;
```












