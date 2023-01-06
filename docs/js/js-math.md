<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Math</h1>

## Description

`Math` is a built-in object that has properties and methods for mathematical constants and functions. It’s not a function object.

> [!IMPORTANT]
> `Math` works with the *Number* type. It doesn't work with BigInt. 

Unlike many other global objects, Math is not a constructor. All properties and methods of Math are static. You refer to the constant pi as Math.PI and you call the sine function as Math.sin(x), where x is the method’s argument. Constants are defined with the full precision of real numbers in JavaScript.

> [!NOTE]
> Many Math functions have a precision that’s implementation-dependent. This means that different browsers can give a different result. Even the same JavaScript engine on a different OS or architecture can give different results!

## Static properties
* Math.E
* Math.LN2
* Math.LN10
* Math.LOG2E
* Math.LOG10E
* Math.PI
* Math.SQRT1_2
* Math.SQRT2

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
### Math.abs(x)
Returns the absolute value of x.

### Math.acos(x)
Returns the arccosine of x.

### Math.acosh(x)
Returns the hyperbolic arccosine of x.

### Math.asin(x)
Returns the arcsine of x.

### Math.asinh(x)
Returns the hyperbolic arcsine of a number.

### Math.atan(x)
Returns the arctangent of x.

### Math.atanh(x)
Returns the hyperbolic arctangent of x.

### Math.atan2(y, x)
Returns the arctangent of the quotient of its arguments.

### Math.cbrt(x)
Returns the cube root of x.

### Math.ceil(x)
Returns the smallest integer greater than or equal to x.

### Math.clz32(x)
Returns the number of leading zero bits of the 32-bit integer x.

### Math.cos(x)
Returns the cosine of x.

### Math.cosh(x)
Returns the hyperbolic cosine of x.

### Math.exp(x)
Returns e^x, where x is the argument, and e is Euler's constant (2.718…, the base of the natural logarithm).

### Math.expm1(x)
Returns subtracting 1 from exp(x).

### Math.floor(x)
Returns the largest integer less than or equal to x.

### Math.fround(x)
Returns the nearest single precision float representation of x.

### Math.hypot([x[, y[, …]]])
Returns the square root of the sum of squares of its arguments.

### Math.imul(x, y)
Returns the result of the 32-bit integer multiplication of x and y.

### Math.log(x)
Returns the natural logarithm (㏒e; also, ㏑) of x.

### Math.log1p(x)
Returns the natural logarithm (㏒e; also ㏑) of 1 + x for the number x.

### Math.log10(x)
Returns the base-10 logarithm of x.

### Math.log2(x)
Returns the base-2 logarithm of x.

### Math.max([x[, y[, …]]])
Returns the largest of zero or more numbers.

### Math.min([x[, y[, …]]])
Returns the smallest of zero or more numbers.

### Math.pow(x, y)
Returns base x to the exponent power y (that is, x^y).

### Math.random()
Returns a pseudo-random number between 0 and 1.

### Math.round(x)
Returns the value of the number x rounded to the nearest integer.

### Math.sign(x)
Returns the sign of the x, indicating whether x is positive, negative, or zero.

### Math.sin(x)
Returns the sine of x.

### Math.sinh(x)
Returns the hyperbolic sine of x.

### Math.sqrt(x)
Returns the positive square root of x.

### Math.tan(x)
Returns the tangent of x.

### Math.tanh(x)
Returns the hyperbolic tangent of x.

### Math.trunc(x)
Returns the integer portion of x, removing any fractional digits.


**More Detailed İnformation** > (https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math)
