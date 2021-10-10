<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/js_style.css">

## Description

`BigInt` is a built-in object whose constructor returns a `bigint` primitive — also called a BigInt value, or sometimes just a BigInt — to represent whole numbers larger than 253 - 1 (Number.MAX_SAFE_INTEGER), which is the largest number JavaScript can represent with a `number` primitive (or Number value). BigInt values can be used for arbitrarily large integers.

A BigInt value, also sometimes just called a BigInt, is a `bigint` primitive, created by appending `n` to the end of an integer literal, or by calling the BigInt() constructor (but without the `new` operator) and giving it an integer value or string value.
```js
const previouslyMaxSafeInteger = 9007199254740991n

const alsoHuge = BigInt(9007199254740991)
// ↪ 9007199254740991n

const hugeString = BigInt("9007199254740991")
// ↪ 9007199254740991n

const hugeHex = BigInt("0x1fffffffffffff")
// ↪ 9007199254740991n

const hugeOctal = BigInt("0o377777777777777777")
// ↪ 9007199254740991n

const hugeBin = BigInt("0b11111111111111111111111111111111111111111111111111111")
// ↪ 9007199254740991n
```

## Constructor

### BigInt() constructor
The `BigInt()` constructor returns a value of type bigint.
```js
BigInt(value);

// example
BigInt(123);
// 123n
```

## Static methods

### BigInt.asIntN()
The `BigInt.asIntN` static method clamps a BigInt value to a signed integer value, and returns that value.
```js
BigInt.asIntN(bits, bigint);

// example
const max = 2n ** (64n - 1n) - 1n;

BigInt.asIntN(64, max);
// ↪ 9223372036854775807n

BigInt.asIntN(64, max + 1n);
// ↪ -9223372036854775808n
// negative because of overflow
```

### BigInt.asUintN()
The `BigInt.asUintN` static method clamps a BigInt value to an unsigned integer value, and returns that value.
```js
BigInt.asUintN(bits, bigint);

// example
const max = 2n ** 64n - 1n;

BigInt.asUintN(64, max);
// ↪ 18446744073709551615n

BigInt.asUintN(64, max + 1n);
// ↪ 0n
// zero because of overflow
```

> [!CAUTION]
> The operations supported on BigInt values are not constant-time. BigInt values are therefore unsuitable for use in cryptography.












