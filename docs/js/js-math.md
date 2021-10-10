<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/js_style.css">

## Description

`Math` is a built-in object that has properties and methods for mathematical constants and functions. It’s not a function object.

> [!IMPORTANT]
> `Math` works with the *Number* type. It doesn't work with BigInt. 

Unlike many other global objects, Math is not a constructor. All properties and methods of Math are static. You refer to the constant pi as Math.PI and you call the sine function as Math.sin(x), where x is the method’s argument. Constants are defined with the full precision of real numbers in JavaScript.

> [!NOTE]
> Many Math functions have a precision that’s implementation-dependent. This means that different browsers can give a different result. Even the same JavaScript engine on a different OS or architecture can give different results!

## Static properties

### Math.E
The `Math.E` property represents Euler's number, the base of natural logarithms, e, which is approximately 2.718.
```js
console.log(Math.E);
// expected output: 2.718281828459045

console.log((1 + (1 / 1000000)) ** 1000000);
// expected output: 2.718280469 (approximately)
```

### Math.LN2
The `Math.LN2` property represents the natural logarithm of 2, approximately 0.693:
```js
console.log(Math.LN2);
// expected output: 0.6931471805599453
```

### Math.LN10
The `Math.LN10` property represents the natural logarithm of 10, approximately 2.302:
```js
console.log(Math.LN10);
// expected output: 2.302585092994046
```

### Math.LOG2E
The `Math.LOG2E` property represents the base 2 logarithm of e, approximately 1.442:
```js
console.log(Math.LOG2E);
// expected output: 1.4426950408889634
```

### Math.LOG10E
The `Math.LOG10E` property represents the base 10 logarithm of e, approximately 0.434:
```js
console.log(Math.LOG10E);
// expected output: 0.4342944819032518
```

### Math.PI
The `Math.PI` property represents the ratio of the circumference of a circle to its diameter, approximately 3.14159:
```js
console.log(Math.PI);
// expected output: 3.141592653589793
```

### Math.SQRT1_2
The `Math.SQRT1_2` property represents the square root of 1/2 which is approximately 0.707:
```js
console.log(Math.SQRT1_2);
// expected output: 0.7071067811865476
```

### Math.SQRT2
The `Math.SQRT2` property represents the square root of 2, approximately 1.414:
```js
console.log(Math.SQRT2);
// expected output: 1.4142135623730951
```

## Static methods
 
















