<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Description

The `class` expression is one way to define a class in ECMAScript 2015. Similar to function expressions, class expressions can be named or unnamed. If named, the name of the class is local to the class body only. and also supporting Re-declaration is allowed

## Constructor

The `constructor` method is a special method of a class for creating and initializing an object of that class.
```js
constructor() { ... }
constructor(argument0) { ... }
constructor(argument0, argument1) { ... }
constructor(argument0, argument1, ... , argumentN) { ... }

// example
class Polygon 
{
  constructor() {this.name = 'Polygon';}
}
const poly1 = new Polygon();

console.log(poly1.name);
// expected output: "Polygon"
```

## Extends

The `extends` keyword is used in *class declarations* or *class expressions* to create a class that is a child of another class.
```js
class ExtendedClass extends MainClass {...}
```

## Private class fields

Class properties are public by default and can be examined or modified outside the class. There is however a stage 3 proposal to allow defining private class fields using a hash *`#`* prefix.
```js
class ClassWithPrivateField {
  #privateField
}

class ClassWithPrivateMethod {
  #privateMethod() {
    return 'hello world'
  }
}

class ClassWithPrivateStaticField {
  static #PRIVATE_STATIC_FIELD
}
```

## Public class fields

Both static and instance public fields are writable, enumerable, and configurable properties. As such, unlike their private counterparts, they participate in prototype inheritance.
```js
class ClassWithInstanceField {
  instanceField = 'instance field'
}

class ClassWithPublicInstanceMethod {
  publicMethod() {
    return 'hello world'
  }
}

class ClassWithStaticField {
  static staticField = 'static field'
}

```

## Static

The `static` keyword defines a static method or property for a class. Neither static methods nor static properties can be called on instances of the class. Instead, they're called on the class itself.

Static methods are often utility functions, such as functions to create or clone objects, whereas static properties are useful for caches, fixed-configuration, or any other data you don't need to be replicated across instances.

Note that the examples throughout this article use public class fields (including static public class fields), which are not yet part of the ECMAScript specification, but are instead specified in a Public and private instance fields proposal at TC39.
```js
static methodName() {...}
static propertyName [= value];

// example
class Triple {
  static customName = 'Tripler';
  static description = 'I triple any number you provide';
  static calculate(n = 1) {
    return n * 3;
  }
}

class SquaredTriple extends Triple {
  static longDescription;
  static description = 'I square the triple of any number you provide';
  static calculate(n) {
    return super.calculate(n) * super.calculate(n);
  }
}

console.log(Triple.description);            // 'I triple any number you provide'
console.log(Triple.calculate());            // 3
console.log(Triple.calculate(6));           // 18

const tp = new Triple();

console.log(SquaredTriple.calculate(3));    // 81 (not affected by parent's instantiation)
console.log(SquaredTriple.description);     // 'I square the triple of any number you provide'
console.log(SquaredTriple.longDescription); // undefined
console.log(SquaredTriple.customName);      // 'Tripler'

// This throws because calculate() is a static member, not an instance member.
console.log(tp.calculate());                // 'tp.calculate is not a function'
```








