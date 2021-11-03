<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

As with other JavaScript language features, TypeScript adds type annotations and other syntax to allow you to express relationships between classes and other types.

## Class Members
Here’s the most basic class - an empty one:
```ts
class Point {}
```

### Fields
A field declaration creates a public writeable property on a class:
```ts
class Point {
  x: number;
  y: number;
}
 
const pt = new Point();
pt.x = 0;
pt.y = 0;
```

#### readonly
Fields may be prefixed with the `readonly` modifier. This prevents assignments to the field outside of the constructor.
```ts
class Greeter {
  readonly name: string = "world";
 
  constructor(otherName?: string) {
    if (otherName !== undefined) {
      this.name = otherName;
    }
  }
 
  err() {
    this.name = "not ok";    // Cannot assign to 'name' because it is a read-only property.
  }
}
const g = new Greeter();
g.name = "also not ok";      // Cannot assign to 'name' because it is a read-only property.
```

### Constructors
Class constructors are very similar to functions. You can add parameters with type annotations, default values, and overloads:
```ts
class Point {
  x: number;
  y: number;
 
  // Normal signature with defaults
  constructor(x = 0, y = 0) {
    this.x = x;
    this.y = y;
  }
}
```

### Methods
A function property on a class is called a method. Methods can use all the same type annotations as functions and constructors:
```ts
class Point {
  x = 10;
  y = 10;
 
  scale(n: number): void {
    this.x *= n;
    this.y *= n;
  }
}
```

#### Getters / Setters
Classes can also have accessors:
```ts
class C {
  _length = 0;
  get length() {
    return this._length;
  }
  set length(value) {
    this._length = value;
  }
}
```
TypeScript has some special inference rules for accessors:
* If `get` exists but no `set`, the property is automatically `readonly`
* If the type of the setter parameter is not specified, it is inferred from the return type of the getter
* Getters and setters must have the same Member Visibility
```ts
class Thing {
  _size = 0;
 
  get size(): number {
    return this._size;
  }
 
  set size(value: string | number | boolean) {
    let num = Number(value);
 
    // Don't allow NaN, Infinity, etc
 
    if (!Number.isFinite(num)) {
      this._size = 0;
      return;
    }
 
    this._size = num;
  }
```

### extends Clauses
Classes may `extend` from a base class. A derived class has all the properties and methods of its base class, and also define additional members.
```ts
class Animal {
  move() {
    console.log("Moving along!");
  }
}
 
class Dog extends Animal {
  woof(times: number) {
    for (let i = 0; i < times; i++) {
      console.log("woof!");
    }
  }
}
 
const d = new Dog();
d.move();      // Base class method
d.woof(3);     // Derived class method
```

## Member Visibility
You can use TypeScript to control whether certain methods or properties are visible to code outside the class.

#### public
The default visibility of class members is public. A public member can be accessed anywhere:
```ts
class Greeter {
  public greet() {console.log("hi!");}
}
const g = new Greeter();
g.greet();
```

#### private
`private` is like `protected`, but doesn’t allow access to the member even from subclasses:
```ts
class Base {
  private x = 0;
}
const b = new Base();
// Can't access from outside the class
console.log(b.x);     // Property 'x' is private and only accessible within class 'Base'.
```

#### protected
`protected` members are only visible to subclasses of the class they’re declared in.
```ts
class Greeter {
  public greet() {console.log("Hello, " + this.getName());}
  protected getName() {return "hi";}
}

class SpecialGreeter extends Greeter {
  public howdy() {
    // OK to access protected member here
    console.log("Howdy, " + this.getName());
  }
}
const g = new SpecialGreeter();
g.greet();        // OK
g.getName();      // Property 'getName' is protected and only accessible within class 'Greeter' and its subclasses.
```

## Static Members
Classes may have `static` members. These members aren’t associated with a particular instance of the class. They can be accessed through the class constructor object itself:
```ts
class MyClass {
  static x = 0;
  static printX() {console.log(MyClass.x);}
}
console.log(MyClass.x);
MyClass.printX();
```

## this Types
In classes, a special type called `this` refers dynamically to the type of the current class. Let’s see how this is useful:
```ts
class Box {
  contents: string = "";
  set(value: string) {
    this.contents = value;
    return this;
  }
}
```






