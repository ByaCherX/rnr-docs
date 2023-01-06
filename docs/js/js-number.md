<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Number</h1>

## Description
Number is a primitive wrapper object used to represent and manipulate numbers like 37 or -9.25.
The `Number` constructor contains constants and methods for working with numbers. Values of other types can be converted to numbers using the `Number()`.

The JavaScript Number type is a double-precision 64-bit binary format IEEE 754 value, like double in Java or C#. This means it can represent fractional values, but there are some limits to what it can store. A Number only keeps about 17 decimal places of precision; arithmetic is subject to rounding. The largest value a Number can hold is about 1.8×10308. Numbers beyond that are replaced with the special Number constant Infinity.

A number literal like 37 in JavaScript code is a floating-point value, not an integer. There is no separate integer type in common everyday use. (JavaScript now has a BigInt type, but it was not designed to replace Number for everyday uses. 37 is still a Number, not a BigInt.)

Number may also be expressed in literal forms like *0b101*, *0o13*, *0x0A*. Learn more on numeric lexical grammar here.

## constructor

### Number() constructor
The `Number()` creates a Number object.
```js
new Number(value)

// example
const a = new Number('123'); // a === 123 is false
const b = Number('123');     // b === 123 is true
a instanceof Number;         // is true
b instanceof Number;         // is false
```

#### Literal syntax
```js
123    // one-hundred twenty-three
123.0  // same
123 === 123.0  // true
```

#### Function syntax
```js
Number('123')  // returns the number 123
Number('123') === 123  // true

Number("unicorn")  // NaN
Number(undefined)  // NaN
```

#### More ways to write a number
Imagine we need to write 1 billion. The obvious way is:
```js
let billion = 1000000000;

//we also can underscore _ as the separator:
let billion = 1_000_000_000;
```

In JavaScript, we can shorten a number by appending the letter `"e"` to it and specifying the zeroes count:
```js
let billion = 1e9;  // 1 billion, literally: 1 and 9 zeroes

alert( 7.3e9 );     // 7.3 billions (same as 7300000000 or 7_300_000_000)
```

In other words, e multiplies the number by 1 with the given zeroes count.
```js
1e3 === 1 * 1000; // e3 means *1000
1.23e6 === 1.23 * 1000000; // e6 means *1000000
```

Now let’s write something very small. Say, 1 microsecond (one millionth of a second):
```js
let ms = 0.000001;

// Just like before, using "e" can help. If we’d like to avoid writing the zeroes explicitly, we could say the same a
let ms = 1e-6;  // six zeroes to the left from 1
```

#### Hex, binary and octal numbers
Hexadecimal numbers are widely used in JavaScript to represent colors, encode characters, and for many other things. So naturally, there exists a shorter way to write them: 0x and then the number.

For instance:
```js
alert( 0xff );   // 255
alert( 0xFF );   // 255 (the same, case doesn't matter)
```

Binary and octal numeral systems are rarely used, but also supported using the 0b and 0o prefixes:
```js
let a = 0b11111111; // binary form of 255
let b = 0o377; // octal form of 255

alert( a == b ); // true, the same number 255 at both sides
```

## toString(base)
The method num.toString(base) returns a string representation of num in the numeral system with the given base.

For example:
```js
let num = 255;

alert( num.toString(16) );  // ff
alert( num.toString(2) );   // 11111111
```

## Static properties
* Number.EPSILON
* Number.MAX_SAFE_INTEGER
* Number.MAX_VALUE
* Number.MIN_VALUE
* Number.NaN
* Number.NEGATIVE_INFINITY
* Number.POSITIVE_INFINITY
* Number.prototype

### Number.EPSILON
The `Number.EPSILON` property represents the difference between 1 and the smallest floating point number greater than 1.
You do not have to create a Number object to access this static property (use `Number.EPSILON`).

The `EPSILON` property has a value of approximately `2.2204460492503130808472633361816E-16`, or `2^-52`.

### Number.MAX_SAFE_INTEGER
The `MAX_SAFE_INTEGER` constant has a value of `9007199254740991` (9,007,199,254,740,991 or ~9 quadrillion). The reasoning behind that number is that JavaScript uses [double-precision floating-point format](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) numbers as specified in IEEE 754 and can only safely represent integers between `-(2^53 - 1)` and `2^53 - 1`.

### Number.MAX_VALUE
The `MAX_VALUE` property has a value of approximately `1.79E+308`, or 1.7976931348623157 * (10^308). Values larger than `MAX_VALUE` are represented as Infinity.

### Number.MIN_VALUE
`Number.MIN_VALUE` is the smallest positive number (not the most negative number) that can be represented within float precision — in other words, the number closest to 0. That's approximately `5E-324`. The ECMAScript spec doesn't define a precise value that implementations are required to support — instead the spec says, "must be the smallest non-zero positive value that can actually be represented by the implementation". But in practice, its precise value in browsers and in Node.js is `2^-1074`.

### Number.NaN
The `Number.NaN` property represents Not-A-Number. Equivalent of NaN.

### Number.NEGATIVE_INFINITY
The value of `Number.NEGATIVE_INFINITY` is the same as the negative value of the global object's Infinity property.

This value behaves slightly differently than mathematical infinity:

Any positive value, including POSITIVE_INFINITY, multiplied by NEGATIVE_INFINITY is NEGATIVE_INFINITY.
Any negative value, including NEGATIVE_INFINITY, multiplied by NEGATIVE_INFINITY is POSITIVE_INFINITY.
Any positive value divided by NEGATIVE_INFINITY is negative zero (as defined in IEEE 754).
Any negative value divided by NEGATIVE_INFINITY is positive zero (as defined in IEEE 754).
Zero multiplied by NEGATIVE_INFINITY is NaN.
NaN multiplied by NEGATIVE_INFINITY is NaN.
NEGATIVE_INFINITY, divided by any negative value except NEGATIVE_INFINITY, is POSITIVE_INFINITY.
NEGATIVE_INFINITY, divided by any positive value except POSITIVE_INFINITY, is NEGATIVE_INFINITY.
NEGATIVE_INFINITY, divided by either NEGATIVE_INFINITY or POSITIVE_INFINITY, is NaN.
x > Number.NEGATIVE_INFINITY is true for any number x that isn't NEGATIVE_INFINITY.

You might use the `Number.NEGATIVE_INFINITY` property to indicate an error condition that returns a finite number in case of success. Note, however, that isFinite would be more appropriate in such a case.

Because `NEGATIVE_INFINITY` is a static property of Number, you always use it as `Number.NEGATIVE_INFINITY`, rather than as a property of a Number object you created.

### Number.POSITIVE_INFINITY
The value of `Number.POSITIVE_INFINITY` is the same as the value of the global object's Infinity property.

This value behaves slightly differently than mathematical infinity:

Any positive value, including POSITIVE_INFINITY, multiplied by POSITIVE_INFINITY is POSITIVE_INFINITY.
Any negative value, including NEGATIVE_INFINITY, multiplied by POSITIVE_INFINITY is NEGATIVE_INFINITY.
Any positive number divided by POSITIVE_INFINITY is positive zero (as defined in IEEE 754).
Any negative number divided by POSITIVE_INFINITY is negative zero (as defined in IEEE 754.
Zero multiplied by POSITIVE_INFINITY is NaN.
NaN multiplied by POSITIVE_INFINITY is NaN.
POSITIVE_INFINITY, divided by any negative value except NEGATIVE_INFINITY, is NEGATIVE_INFINITY.
POSITIVE_INFINITY, divided by any positive value except POSITIVE_INFINITY, is POSITIVE_INFINITY.
POSITIVE_INFINITY, divided by either NEGATIVE_INFINITY or POSITIVE_INFINITY, is NaN.
Number.POSITIVE_INFINITY > x is true for any number x that isn't POSITIVE_INFINITY.

You might use the `Number.POSITIVE_INFINITY` property to indicate an error condition that returns a finite number in case of success. Note, however, that isFinite would be more appropriate in such a case.

Because `POSITIVE_INFINITY` is a static property of Number, you always use it as `Number.POSITIVE_INFINITY`, rather than as a property of a Number object you created.

### Number.prototype
Number is a [primitive wrapper object](https://developer.mozilla.org/en-US/docs/Glossary/Primitive#primitive_wrapper_objects_in_javascript) used to represent and manipulate numbers like 37 or -9.25.
The `Number` constructor contains constants and methods for working with numbers. Values of other types can be converted to numbers using the `Number()` function.

The JavaScript Number type is a [double-precision 64-bit binary format IEEE 754](https://en.wikipedia.org/wiki/Floating-point_arithmetic) value, like double in Java or C#. This means it can represent fractional values, but there are some limits to what it can store. A Number only keeps about 17 decimal places of precision; arithmetic is subject to rounding. The largest value a Number can hold is about 1.8E308. Values higher than that are replaced with the special Number constant Infinity.

A number literal like 37 in JavaScript code is a floating-point value, not an integer. There is no separate integer type in common everyday use. (JavaScript now has a BigInt type, but it was not designed to replace Number for everyday uses. 37 is still a Number, not a BigInt.)

Number may also be expressed in literal forms like 0b101, 0o13, 0x0A. Learn more on numeric [lexical grammar here](https://devdocs.io/javascript/lexical_grammar#numeric_literals).

## Static methods
* Number.isNaN()
* Number.isFinite()
* Number.isInteger()
* Number.isSafeInteger()
* Number.parseFloat(string)
* Number.parseInt(string, [ radix])

### Number.isNaN()
The `Number.isNaN()` method determines whether the passed value is NaN and its type is Number. It is a more robust version of the original, global isNaN().
```js
// Syntax
Number.isNaN(value)
```

### Number.isFinite()
In comparison to the global isFinite() function, this method doesn't first convert the parameter to a number. This means only values of the type number and are finite return true.
```js
// syntax
Number.isFinite(value)
```

### Number.isInteger()
If the target value is an integer, return true, otherwise return false. If the value is NaN or Infinity, return false. The method will also return true for floating point numbers that can be represented as integer.
```js
// syntax
Number.isInteger(value)
```

### Number.isSafeInteger()
The `Number.isSafeInteger()` method determines whether the provided value is a number that is a safe integer.
* can be exactly represented as an IEEE-754 double precision number, and
* whose IEEE-754 representation cannot be the result of rounding any other integer to fit the IEEE-754 representation.

For example, `2^53 - 1` is a safe integer: it can be exactly represented, and no other integer rounds to it under any IEEE-754 rounding mode. In contrast, `2^53` is not a safe integer: it can be exactly represented in IEEE-754, but the integer `2^53 + 1` can't be directly represented in IEEE-754 but instead rounds to `2^53` under round-to-nearest and round-to-zero rounding. The safe integers consist of all integers from `-(2^53 - 1)` inclusive to `2^53 - 1` inclusive (± `9007199254740991` or ± 9,007,199,254,740,991).
```js
// syntax
Number.isSafeInteger(testValue)

// example
Number.isSafeInteger(3);                    // true
Number.isSafeInteger(Math.pow(2, 53));      // false
Number.isSafeInteger(Math.pow(2, 53) - 1);  // true
Number.isSafeInteger(NaN);                  // false
Number.isSafeInteger(Infinity);             // false
Number.isSafeInteger('3');                  // false
Number.isSafeInteger(3.1);                  // false
Number.isSafeInteger(3.0);                  // true
```

### Number.parseFloat(string)
The `Number.parseFloat()` method parses an argument and returns a floating point number. If a number cannot be parsed from the argument, it returns NaN.
```js
Number.parseFloat(string)
```

### Number.parseInt(string, [ radix])
The `Number.parseInt()` method parses a string argument and returns an integer of the specified radix or base.
```js
Number.parseInt(string)
Number.parseInt(string, radix)
```

## Instance methods
* Number.toExponential(fractionDigits)
* Number.toFixed(digits)
* Number.toLocaleString([ locales [, options]])
* Number.toPrecision(precision)
* Number.toString([ radix])
* Number.valueOf()

### Number.toExponential(fractionDigits)
If the `fractionDigits` argument is omitted, the number of digits after the decimal point defaults to the number of digits necessary to represent the value uniquely.

If you use the `toExponential()` method for a numeric literal and the numeric literal has no exponent and no decimal point, leave whitespace(s) before the dot that precedes the method call to prevent the dot from being interpreted as a decimal point.

If a number has more digits than requested by the `fractionDigits` parameter, the number is rounded to the nearest number represented by `fractionDigits` digits. See the discussion of rounding in the description of the toFixed() method, which also applies to `toExponential()`.
```js
// syntax
toExponential()
toExponential(fractionDigits)

// example
var numObj = 77.1234;
console.log(numObj.toExponential());  // logs 7.71234e+1
console.log(numObj.toExponential(4)); // logs 7.7123e+1
console.log(numObj.toExponential(2)); // logs 7.71e+1
console.log(77.1234.toExponential()); // logs 7.71234e+1
console.log(77 .toExponential());     // logs 7.7e+1

```

### Number.toFixed(digits)
`toFixed()` returns a string representation of `numObj` that does not use exponential notation and has exactly `digits` digits after the decimal place. The number is rounded if necessary, and the fractional part is padded with zeros if necessary so that it has the specified length. If the absolute value of `numObj` is greater or equal to `1e+21`, this method calls Number.prototype.toString() and returns a string in exponential notation.
```js
// syntax
toFixed()
toFixed(digits)

// example
let numObj = 12345.6789

numObj.toFixed()       // Returns '12346': note rounding, no fractional part
numObj.toFixed(1)      // Returns '12345.7': note rounding
numObj.toFixed(6)      // Returns '12345.678900': note added zeros
(1.23e+20).toFixed(2)  // Returns '123000000000000000000.00'
(1.23e-10).toFixed(2)  // Returns '0.00'
2.34.toFixed(1)        // Returns '2.3'
2.35.toFixed(1)        // Returns '2.4'. Note it rounds up
2.55.toFixed(1)        // Returns '2.5'. Note it rounds down - see warning above
-2.34.toFixed(1)       // Returns -2.3 (due to operator precedence, negative number literals don't return a string...)
(-2.34).toFixed(1)     // Returns '-2.3'
```

### Number.toLocaleString([ locales [, options]])
The `toLocaleString()` method returns a string with a language-sensitive representation of this number.
```js
// syntax
toLocaleString()
toLocaleString(locales)
toLocaleString(locales, options)

// example
var number = 3500;
console.log(number.toLocaleString()); // Displays "3,500" if in U.S. English locale
```

### Number.toPrecision(precision)
The `toPrecision()` method returns a string representing the Number object to the specified precision.
```js
// syntax
toPrecision()
toPrecision(precision)

// example
let numObj = 5.123456
console.log(numObj.toPrecision())    // logs '5.123456'
console.log(numObj.toPrecision(2))   // logs '5.1'
console.log(numObj.toPrecision(1))   // logs '5'

numObj = 0.000123

console.log(numObj.toPrecision())    // logs '0.000123'
console.log(numObj.toPrecision(5))   // logs '0.00012300'
console.log(numObj.toPrecision(2))   // logs '0.00012'
console.log(numObj.toPrecision(1))   // logs '0.0001'

// note that exponential notation might be returned in some circumstances
console.log((1234.5).toPrecision(2)) // logs '1.2e+3'
```

### Number.toString([ radix])
The Number object overrides the `toString()` method of the Object object. (It does not inherit Object.prototype.toString()). For Number objects, the `toString()` method returns a string representation of the object in the specified radix.

### Number.valueOf()
This method is usually called internally by JavaScript and not explicitly in web code.
```js
// syntax
valueOf()

// example
let numObj = new Number(10)
console.log(typeof numObj)  // object

let num = numObj.valueOf()
console.log(num)            // 10
console.log(typeof num)     // number
```





