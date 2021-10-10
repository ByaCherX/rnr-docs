<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/js_style.css">

## Description
`Symbol` is a built-in object whose constructor returns a `symbol` primitive — also called a Symbol value or just a Symbol — that’s guaranteed to be unique. Symbols are often used to add unique property keys to an object that won’t collide with keys any other code might add to the object, and which are hidden from any mechanisms other code will typically use to access the object. That enables a form of weak encapsulation, or a weak form of information hiding.

## Constructor

### Symbol() constructor
The `Symbol()` constructor returns a value of type symbol, but is incomplete as a constructor because it does not support the syntax "`new Symbol()`" and it is not intended to be subclassed. It may be used as the value of an *extends* clause of a *class* definition but a *super* call to it will cause an exception.
```js
Symbol()
Symbol(description)

// example
const symbol1 = Symbol();
const symbol2 = Symbol(42);
const symbol3 = Symbol('foo');
```









