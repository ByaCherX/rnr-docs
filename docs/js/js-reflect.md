<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/js_style.css">

## Description
`Reflect` is a built-in object that provides methods for interceptable JavaScript operations. The methods are the same as those of proxy handlers. `Reflect` is not a function object, so it's not constructible.

Unlike most global objects, `Reflect` is not a constructor. You cannot use it with a *new operator* or invoke the `Reflect` object as a function. All properties and methods of `Reflect` are static (just like the Math object).

The `Reflect` object provides the following static functions which have the same names as the p*roxy handler methods*.

Some of these methods are also the same as corresponding methods on *Object*, although they do have *some subtle differences* between them.

## Static methods

### Reflect.construct()
The static `Reflect.construct()` method acts like the *new* operator, but as a function. It is equivalent to calling new target(...args). It gives also the added option to specify a different prototype.
```js
Reflect.construct(target, argumentsList)
Reflect.construct(target, argumentsList, newTarget)

// example
function func1(a, b, c) {this.sum = a + b + c;}

const args = [1, 2, 3];
const object1 = new func1(...args);
const object2 = Reflect.construct(func1, args);

console.log(object2.sum);    // output: 6
console.log(object1.sum);    // output: 6
```

### Reflect.apply()
The static `Reflect.apply()` method calls a target function with arguments as specified.
```js
Reflect.apply(target, thisArgument, argumentsList)

// example
Reflect.apply(Math.floor, undefined, [1.75]);
// 1;

Reflect.apply(String.fromCharCode, undefined, [104, 101, 108, 108, 111])
// "hello"

Reflect.apply(RegExp.prototype.exec, /ab/, ['confabulation']).index
// 4

Reflect.apply(''.charAt, 'ponies', [3])
// "i"
```

### Reflect.defineProperty()
```js

```

### Reflect.deleteProperty()
```js

```

### Reflect.get()
```js

```

### Reflect.getOwnPropertyDescriptor()
```js

```

### Reflect.getPrototypeOf()
```js

```

### Reflect.set()
```js

```

### Reflect.setPrototypeOf()
```js

```

### Reflect.has()
```js

```

### Reflect.isExtensible()
```js

```

### Reflect.ownKeys()
```js

```

### Reflect.preventExtensions()
```js

```





















