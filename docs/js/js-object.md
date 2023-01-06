<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Object</h1>

## Object Defination
The `Object` class represents one of *JavaScript's data types*. It is used to store various keyed collections and more complex entities. Objects can be created using the *Object()* constructor or the *object initializer / literal syntax*.

Nearly all objects in JavaScript are instances of Object; a typical object inherits properties (including methods) from `Object.prototype`, although these properties may be shadowed (a.k.a. overridden). However, an `Object` may be deliberately created for which this is not true (e.g. by Object.create(null)), or it may be altered so that this is no longer true (e.g. with *Object.setPrototypeOf*).

The Object constructor creates an object wrapper for the given value.

* If the value is *null* or *undefined*, it will create and return an empty object.
* Otherwise, it will return an object of a Type that corresponds to the given value.
* If the value is an object already, it will return the value.

## Constructor

### Object() constructor
The `Object` constructor creates an object wrapper for the given value.
```js
function User(name) {
  this.name = name;
  this.isAdmin = false;
}

let user = new User("Jack");

alert(user.name);     // Jack
alert(user.isAdmin);  // false
```

### Return from constructors
Usually, constructors do not have a `return` statement. Their task is to write all necessary stuff into `this`, and it automatically becomes the result.
```js
function BigUser() {
  this.name = "John";
  return { name: "Godzilla" };  // <-- returns this object
}

alert( new BigUser().name );    // Godzilla, got that object
```

## Static methods
* Object.assign()
* Object.create()
* Object.defineProperty()
* Object.defineProperties()
* Object.entries()
* Object.freeze()
* Object.fromEntries()
* Object.getPrototypeOf()
* Object.is()
* Object.keys()
* Object.values()

### Object.assign()
The `Object.assign()` method copies all enumerable own properties from one or more source objects to a target object. It returns the target object.
```js
Object.assign(target, ...sources)
// example
const target = { a: 1, b: 2 };
const source = { b: 4, c: 5 };
const returnedTarget = Object.assign(target, source);
console.log(target);// output: Object {a: 1, b: 4, c: 5}
```

### Object.create()
The `Object.create()` method creates a new object, using an existing object as the prototype of the newly created object.
```js
Object.create(proto)
Object.create(proto, propertiesObject)
// example
const person = {
    isHuman: false,
    printIntroduction: function() {
    console.log(`My name is ${this.name}. Am I human? ${this.isHuman}`);
  }
};
const me = Object.create(person);
me.name = 'Matthew';       // "name" is a property set on "me", but not on "person"
me.isHuman = true;         // inherited properties can be overwritten
me.printIntroduction();    // expected output: "My name is Matthew. Am I human? true"
```

### Object.defineProperty()
The static method `Object.defineProperty()` defines a new property directly on an object, or modifies an existing property on an object, and returns the object.
```js
Object.defineProperty(obj, prop, descriptor)

// example
const object1 = {};
Object.defineProperty(object1, 'property1', {value: 42, writable: false});
object1.property1 = 77;           // throws error !
console.log(object1.property1);   // output: 42

// --- Creating Property ---
var obj1 = {}; // Creates a new object
Object.defineProperty(obj1, 'a', {
  value: 37,
  writable: true,
  enumerable: true,
  configurable: true
});

var bValue = 38;
Object.defineProperty(obj1, 'b', {
  get() { return bValue; },
  set(newValue) { bValue = newValue; },
  enumerable: true,
  configurable: true
});
obj1.b;   // 38

// ---Inheritance of properties ---
function myclass() {}
var value;
Object.defineProperty(myclass.prototype, "x", {
  get() {return value;},
  set(x) {value = x;}
});

var aModule = new myclass();
var bModule = new myclass();
aModule.x = 1;
console.log(bModule.x); // 1
```

### Object.keys()

#### Explain
* **Configurable**</br>
*true & false* = if the type of this property descriptor may be changed and if the property may be deleted from the corresponding object.

* **Enumerable**</br>
*true & false* = if and only if this property shows up during enumeration of the properties on the corresponding object.

* **value**</br>
The value associated with the property. Can be any valid JavaScript value (number, object, function, etc). Defaults to *undefined*.

* **writable**</br>
*true & false* = true if the value associated with the property may be changed with an assignment operator.

* **get**</br>
A function which serves as a *get* for the property, when the property is accessed, *this* function is called without arguments and with this set to the object through which the property is accessed.

* **set**</br>
A function which serves as a *set* for the property, When the property is assigned, *this* function is called with one argument (the value being assigned to the property) and with *this* set to the object through which the property is assigned.

> More about this section: https://devdocs.io/javascript/global_objects/object/defineproperty

### Object.defineProperties()
The `Object.defineProperties()` method defines new or modifies existing properties directly on an object, returning the object.
```js
Object.defineProperties(obj, props)

// example
const object1 = {};
Object.defineProperties(object1, {
  property1: {value: 42, writable: true},
  property2: {}
});
console.log(object1.property1);
// expected output: 42
```

### Object.entries()
The `Object.entries()` method returns an array of a given object's own enumerable string-keyed property [key, value] pairs, in the same order as that provided by a *for...in* loop. (The only important difference is that a `for...in` loop enumerates properties in the prototype chain as well).
```js
Object.entries(obj)

// example
const object1 = {a: 'somestring', b: 42};
for (const [key, value] of Object.entries(object1)) {
  console.log(`${key}: ${value}`);
}
// expected output:
// "a: somestring"
// "b: 42"
```

### Object.freeze()
The `Object.freeze()` method freezes an object. A frozen object can no longer be changed; freezing an object prevents new properties from being added to it, existing properties from being removed, prevents changing the enumerability, configurability, or writability of existing properties, and prevents the values of existing properties from being changed. In addition, freezing an object also prevents its prototype from being changed. freeze() returns the same object that was passed in.
```js
Object.freeze(obj)

// example
const obj = {prop: 42};
Object.freeze(obj);

obj.prop = 33;           // Throws an error in strict mode
console.log(obj.prop);   // output: 42
```

### Object.fromEntries()
The `Object.fromEntries()` method takes a list of key-value pairs and returns a new object whose properties are given by those entries. The iterable argument is expected to be an object that implements an `@@iterator` method, that returns an iterator object, that produces a two element array-like object, whose first element is a value that will be used as a property key, and whose second element is the value to associate with that property key.
```js
// syntax
Object.fromEntries(iterable);

// example: Converting a Map to an Object
const map = new Map([ ['foo', 'bar'], ['baz', 42] ]);
const obj = Object.fromEntries(map);
console.log(obj); // { foo: "bar", baz: 42 }
```

### Object.getPrototypeOf()
The `Object.getPrototypeOf()` method returns the prototype (i.e. the value of the internal `[[Prototype]]` property) of the specified object.
```js
// Syntax
Object.getPrototypeOf(obj);
```

## Object methods "this"
Objects are usually created to represent entities of the real world, like users, orders and so on...

For a start, let’s teach the user to say hello:
```js
let user = {
  name: "John",
  age: 30
};

user.sayHi = function() {
  alert("Hello!");
};

user.sayHi(); // Hello!
```
### Method shorthand
There exists a shorter syntax for methods in an object literal:
```js
user = {
  sayHi: function() {
    alert("Hello");
  }
};

// method shorthand looks better, right?
user = {
  sayHi() { // same as "sayHi: function(){...}"
    alert("Hello");
  }
};

// more advanced method
let user = {name: "John", age: 30,
  sayHi() {
    // "this" is the "current object"
    alert(this.name);
  }
};
user.sayHi(); // John
```

## Instance properties



## Instance methods























