<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

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



## Static methods



## Instance methods
