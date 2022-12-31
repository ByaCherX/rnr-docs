<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Proxy</h1>

A `Proxy` object wraps another object and intercepts operations, like reading/writing properties and others, optionally handling them on its own, or transparently allowing the object to handle them.

Proxies are used in many libraries and some browser frameworks. We’ll see many practical applications in this article.

**Syntax**
```js
let proxy = new Proxy(target, handler)
```
* `target` – is an object to wrap, can be anything, including functions.
* `handler` – proxy configuration: an object with “traps”, methods that intercept operations. – e.g. `get` trap for reading a property of `target`, `set` trap for writing a property into `target`, and so on.

For operations on `proxy`, if there’s a corresponding trap in `handler`, then it runs, and the proxy has a chance to handle it, otherwise the operation is performed on `target`.

As a starting example, let’s create a proxy without any traps:
```js
let target = {};
let proxy = new Proxy(target, {}); // empty handler

proxy.test = 5; // writing to proxy (1)
alert(target.test); // 5, the property appeared in target!

alert(proxy.test); // 5, we can read it from proxy too (2)

for(let key in proxy) alert(key); // test, iteration works (3)
```
As there are no traps, all operations on `proxy` are forwarded to `target`.
1. A writing operation `proxy.test=` sets the value on `target`.
2. A reading operation `proxy.test` returns the value from `target`.
3. Iteration over `proxy` returns values from `target`.

As we can see, without any traps, `proxy` is a transparent wrapper around `target`.

`Proxy` is a special “exotic object”. It doesn’t have own properties. With an empty `handler` it transparently forwards operations to `target`.

For most operations on objects, there’s a so-called “internal method” in the JavaScript specification that describes how it works at the lowest level. For instance ``[[Get]]``, the internal method to read a property, ``[[Set]]``, the internal method to write a property, and so on. These methods are only used in the specification, we can’t call them directly by name.

Proxy traps intercept invocations of these methods. They are listed in the Proxy specification and in the table below.

For every internal method, there’s a trap in this table: the name of the method that we can add to the `handler` parameter of `new Proxy` to intercept the operation:


|Internal Method       |Handler Merhod  |Triggers when...  |
|----------------------|----------------|------------------|
| [[Get]]	             |  get	          |reading a property |
| [[Set]]	             |  set	          |writing to a property |
| [[HasProperty]]      |	has	          |in operator |
| [[Delete]]           |	deleteProperty|delete operator |
| [[Call]]             |	apply       	|function call |
| [[Construct]]        |	construct	    |new operator |
| [[GetPrototypeOf]]   |	getPrototypeOf|Object.getPrototypeOf |
| [[SetPrototypeOf]]   |	setPrototypeOf|Object.setPrototypeOf |
| [[IsExtensible]]     |	isExtensible	|Object.isExtensible |
| [[PreventExtensions]]|	preventExtensions	|Object.preventExtensions |
| [[DefineOwnProperty]]|	defineProperty|Object.defineProperty, Object.defineProperties |
| [[GetOwnProperty]]   |	getOwnPropertyDescriptor |	Object.getOwnPropertyDescriptor, for..in, Object.keys/values/entries |
| [[OwnPropertyKeys]]  |	ownKeys	      |Object.getOwnPropertyNames, Object.getOwnPropertySymbols, for..in, Object.keys/values/entries |

## Default value with "get" trap
The most common traps are for reading/writing properties.

To intercept reading, the `handler` should have a method `get(target, property, receiver)`.

It triggers when a property is read, with following arguments:

* **`target`** – is the target object, the one passed as the first argument to `new Proxy`,
* **`property`** – property name,
* **`receiver`** – if the target property is a getter, then `receiver` is the object that’s going to be used as this in its call. Usually that’s the `proxy` object itself (or an object that inherits from it, if we inherit from proxy). Right now we don’t need this argument, so it will be explained in more detail later.

Let’s use `get` to implement default values for an object.

We’ll make a numeric array that returns 0 for nonexistent values.

Usually when one tries to get a non-existing array item, they get `undefined`, but we’ll wrap a regular array into the proxy that traps reading and returns 0 if there’s no such property:
```js
let numbers = [0, 1, 2];

numbers = new Proxy(numbers, {
  get(target, prop) {
    if (prop in target) {
      return target[prop];
    } else {return 0;} // default value
  }
});

alert( numbers[1] );   // 1
alert( numbers[123] ); // 0 (no such item)
```

## Validation with "set" trap
Let’s say we want an array exclusively for numbers. If a value of another type is added, there should be an error.

The `set` trap triggers when a property is written.

**set(target, property, value, receiver):**

* **`target`** – is the target object, the one passed as the first argument to new Proxy,
* **`property`** – property name,
* **`value`** – property value,
* **`receiver`** – similar to get trap, matters only for setter properties.

The `set` trap should return true if setting is successful, and `false` otherwise (triggers `TypeError`).

Let’s use it to validate new values:
```js
let numbers = [];

numbers = new Proxy(numbers, { // (*)
  set(target, prop, val) { // to intercept property writing
    if (typeof val == 'number') {
      target[prop] = val;
      return true;
    } else {return false;}
  }
});

numbers.push(1); // added successfully
numbers.push(2); // added successfully
alert("Length is: " + numbers.length); // 2

numbers.push("test"); // TypeError ('set' on proxy returned false)

alert("This line is never reached (error in the line above)");
```
Please note: the built-in functionality of arrays is still working! Values are added by `push`. The `length` property auto-increases when values are added. Our proxy doesn’t break anything.

We don’t have to override value-adding array methods like `push` and `unshift`, and so on, to add checks in there, because internally they use the ``[[Set]]`` operation that’s intercepted by the proxy.

So the code is clean and concise.

## Iteration with "ownKeys" and "getOwnPropertyDescriptor"
`Object.keys`, `for..in` loop and most other methods that iterate over object properties use `[[OwnPropertyKeys]]` internal method (intercepted by `ownKeys` trap) to get a list of properties.

Such methods differ in details:
* `Object.getOwnPropertyNames(obj)` returns non-symbol keys.
* `Object.getOwnPropertySymbols(obj)` returns symbol keys.
* `Object.keys/values()` returns non-symbol keys/values with `enumerable` flag (property flags were explained in the article Property flags and descriptors).
* `for..in` loops over non-symbol keys with `enumerable` flag, and also prototype keys.

In the example below we use `ownKeys` trap to make `for..in` loop over `user`, and also `Object.keys` and `Object.values`, to skip properties starting with an underscore _:
```js
let user = {
  name: "John",
  age: 30,
  _password: "***"
};

user = new Proxy(user, {
  ownKeys(target) { return Object.keys(target).filter(key => !key.startsWith('_')); }
});

// "ownKeys" filters out _password
for(let key in user) alert(key); // name, then: age

// same effect on these methods:
alert( Object.keys(user) ); // name,age
alert( Object.values(user) ); // John,30
```
Although, if we return a key that doesn’t exist in the object, `Object.keys` won’t list it:
```js
let user = { };

user = new Proxy(user, {
  ownKeys(target) { return ['a', 'b', 'c']; }
});

alert( Object.keys(user) ); // <empty>
```
Why? The reason is simple: `Object.keys` returns only properties with the `enumerable` flag. To check for it, it calls the internal method `[[GetOwnProperty]]` for every property to get its descriptor. And here, as there’s no property, its descriptor is empty, no `enumerable` flag, so it’s skipped.

For `Object.keys` to return a property, we need it to either exist in the object, with the `enumerable` flag, or we can intercept calls to `[[GetOwnProperty]]` (the trap `getOwnPropertyDescriptor` does it), and return a descriptor with `enumerable: true`.

Here’s an example of that:
```js
let user = { };

user = new Proxy(user, {
  ownKeys(target) { // called once to get a list of properties
    return ['a', 'b', 'c'];
  },

  getOwnPropertyDescriptor(target, prop) { // called for every property
    return {
      enumerable: true,
      configurable: true
      /* ...other flags, probable "value:..." */
    };
  }

});

alert( Object.keys(user) ); // a, b, c
```

## Protected properties with "deleteProperty" and other traps
There’s a widespread convention that properties and methods prefixed by an underscore _ are internal. They shouldn’t be accessed from outside the object.

Technically that’s possible though:
```js
let user = {
  name: "John",
  _password: "secret"
};

alert(user._password); // secret
```
Let’s use proxies to prevent any access to properties starting with `_`.

We’ll need the traps:

* `get` to throw an error when reading such property,
* `set` to throw an error when writing,
* `deleteProperty` to throw an error when deleting,
* `ownKeys` to exclude properties starting with _ from `for..in` and methods like `Object.keys`.

Code:
```js
let user = {
  name: "John",
  _password: "***"
};

user = new Proxy(user, {
  get(target, prop) {
    if (prop.startsWith('_')) {
      throw new Error("Access denied");
    }
    let value = target[prop];
    return (typeof value === 'function') ? value.bind(target) : value; // (*)
  },
  set(target, prop, val) { // to intercept property writing
    if (prop.startsWith('_')) {
      throw new Error("Access denied");
    } else {
      target[prop] = val;
      return true;
    }
  },
  deleteProperty(target, prop) { // to intercept property deletion
    if (prop.startsWith('_')) {
      throw new Error("Access denied");
    } else {
      delete target[prop];
      return true;
    }
  },
  ownKeys(target) { // to intercept property list
    return Object.keys(target).filter(key => !key.startsWith('_'));
  }
});

// "get" doesn't allow to read _password
try {
  alert(user._password); // Error: Access denied
} catch(e) { alert(e.message); }

// "set" doesn't allow to write _password
try {
  user._password = "test"; // Error: Access denied
} catch(e) { alert(e.message); }

// "deleteProperty" doesn't allow to delete _password
try {
  delete user._password; // Error: Access denied
} catch(e) { alert(e.message); }

// "ownKeys" filters out _password
for(let key in user) alert(key); // name
```

## "In range" with "has" trap
We have a range object:
```js
let range = {
    start: 1,
    end: 10
};
```
We’d like to use the `in` operator to check that a number is in `range`.

The `has` trap intercepts `in` calls.

`has(target, property)`

* `target` – is the target object, passed as the first argument to `new Proxy`,
* `property` – property name

Here’s the demo:
```js
let range = {
  start: 1,
  end: 10
};

range = new Proxy(range, {
  has(target, prop) {
    return prop >= target.start && prop <= target.end;
  }
});

alert(5 in range); // true
alert(50 in range); // false
```

## Wrapping functions: "apply"
We can wrap a proxy around a function as well.

The `apply(target, thisArg, args)` trap handles calling a proxy as function:

* `target` is the target object (function is an object in JavaScript),
* `thisArg` is the value of this.
* `args` is a list of arguments.

For example, let’s recall `delay(f, ms)` decorator, that we did in the article Decorators and forwarding, call/apply.

In that article we did it without proxies. A call to `delay(f, ms)` returned a function that forwards all calls to f after ms milliseconds.

Here’s the previous, function-based implementation:
```js
function delay(f, ms) {
  // return a wrapper that passes the call to f after the timeout
  return function() { // (*)
    setTimeout(() => f.apply(this, arguments), ms);
  };
}

function sayHi(user) {
  alert(`Hello, ${user}!`);
}

// after this wrapping, calls to sayHi will be delayed for 3 seconds
sayHi = delay(sayHi, 3000);

sayHi("John"); // Hello, John! (after 3 seconds)
```
As we’ve seen already, that mostly works. The wrapper function `(*)` performs the call after the timeout.

But a wrapper function does not forward property read/write operations or anything else. After the wrapping, the access is lost to properties of the original functions, such as `name`, `length` and others:
```js
function delay(f, ms) {
  return function() {
    setTimeout(() => f.apply(this, arguments), ms);
  };
}

function sayHi(user) {
  alert(`Hello, ${user}!`);
}

alert(sayHi.length); // 1 (function length is the arguments count in its declaration)

sayHi = delay(sayHi, 3000);

alert(sayHi.length); // 0 (in the wrapper declaration, there are zero arguments)
```
`Proxy` is much more powerful, as it forwards everything to the target object.

Let’s use `Proxy` instead of a wrapping function:
```js
function delay(f, ms) {
  return new Proxy(f, {
    apply(target, thisArg, args) {
      setTimeout(() => target.apply(thisArg, args), ms);
    }
  });
}

function sayHi(user) {
  alert(`Hello, ${user}!`);
}

sayHi = delay(sayHi, 3000);

alert(sayHi.length); // 1 (*) proxy forwards "get length" operation to the target

```
The result is the same, but now not only calls, but all operations on the proxy are forwarded to the original function. So `sayHi.length` is returned correctly after the wrapping in the line `(*)`.

We’ve got a “richer” wrapper.

Other traps exist: the full list is in the beginning of this article. Their usage pattern is similar to the above.

















