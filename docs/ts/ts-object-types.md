<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Overview
In JavaScript, the fundamental way that we group and pass around data is through objects. In TypeScript, we represent those through object types.
```ts
function greet(person: { name: string; age: number }) {
  return "Hello " + person.name;
}
```
or they can be named by using either an interface
```ts
interface Person {
  name: string;
  age: number;
}
 
function greet(person: Person) {
  return "Hello " + person.name;
}
```

## Property Modifiers
Each property in an object type can specify a couple of things: the type, whether the property is optional, and whether the property can be written to.

### Optional Properties
Much of the time, we’ll find ourselves dealing with objects that might have a property set. In those cases, we can mark those properties as optional by adding a question mark (`?`) to the end of their names.
```ts
interface PaintOptions {
  str: string;
  xPos?: number;
  yPos?: number;
}
 
function paintShape(opts: PaintOptions) {// ...}

const shape = "hello";
paintShape({ shape });
paintShape({ shape, xPos: 100 });
paintShape({ shape, yPos: 100 });
paintShape({ shape, xPos: 100, yPos: 100 });
```

### Index Signatures
Sometimes you don’t know all the names of a type’s properties ahead of time, but you do know the shape of the values.

In those cases you can use an index signature to describe the types of possible values, for example:
```ts
interface StringArray {[index: number]: string;}
 
const myArray: StringArray = getStringArray();
const secondItem = myArray[1];
```

## Extending Types
It’s pretty common to have types that might be more specific versions of other types. For example, we might have a `BasicAddress` type that describes the fields necessary for sending letters and packages in the U.S.
```ts
interface BasicAddress {
  name?: string;
  street: string;
  city: string;
  country: string;
  postalCode: string;
}
```

**`interfaces`** can also extend from multiple types.
```ts
interface Colorful {color: string;}
interface Circle {radius: number;}

interface ColorfulCircle extends Colorful, Circle {}
const cc: ColorfulCircle = {
  color: "red",
  radius: 42,
};
```

## Intersection Types
`interfaces` allowed us to build up new types from other types by extending them. TypeScript provides another construct called intersection types that is mainly used to combine existing object types.

An intersection type is defined using the `&` operator.
```ts
interface Colorful {color: string;}
interface Circle {radius: number;}

type ColorfulCircle = Colorful & Circle;
```







