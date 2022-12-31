<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Indexed Collections</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

### Indexed constructor
The `Int8Array()` constructor creates a typed array of twos-complement 8-bit signed integers. The contents are initialized to 0. Once established, you can reference elements in the array using the object's methods, or using standard array index syntax (that is, using bracket notation).
```js
new &ConstructorName(); // new in ES2017
new &ConstructorName(length);
new &ConstructorName(typedArray);
new &ConstructorName(object);

new &ConstructorName(buffer);
new &ConstructorName(buffer, byteOffset);
new &ConstructorName(buffer, byteOffset, length);
```

# Int8Array
### Int8Array() Constructor
```js
// From a length
var int8 = new Int8Array(2);
int8[0] = 42;
console.log(int8[0]); // 42
console.log(int8.length); // 2
console.log(int8.BYTES_PER_ELEMENT); // 1

// From an array
var arr = new Int8Array([21,31]);
console.log(arr[1]); // 31

// From another TypedArray
var x = new Int8Array([21, 31]);
var y = new Int8Array(x);
console.log(y[0]); // 21

// From an ArrayBuffer
var buffer = new ArrayBuffer(8);
var z = new Int8Array(buffer, 1, 4);

// From an iterable
var iterable = function*(){ yield* [1,2,3]; }();
var int8 = new Int8Array(iterable);
// Int8Array[1, 2, 3]
```

### Int8Array.BYTES_PER_ELEMENT
The `TypedArray.BYTES_PER_ELEMENT` property represents the size in bytes of each element in an typed array.
```js
Int8Array.BYTES_PER_ELEMENT;         // 1
Uint8Array.BYTES_PER_ELEMENT;        // 1
Uint8ClampedArray.BYTES_PER_ELEMENT; // 1
Int16Array.BYTES_PER_ELEMENT;        // 2
Uint16Array.BYTES_PER_ELEMENT;       // 2
Int32Array.BYTES_PER_ELEMENT;        // 4
Uint32Array.BYTES_PER_ELEMENT;       // 4
Float32Array.BYTES_PER_ELEMENT;      // 4
Float64Array.BYTES_PER_ELEMENT;      // 8
```

### TypedArray.from()
The `TypedArray.from()` method creates a new *typed array* from an array-like or iterable object. This method is nearly the same as *Array.from()*.
```js
// Arrow function
TypedArray.from(arrayLike, (currentValue, index, array) => { ... } )

// Mapping function
TypedArray.from(arrayLike, mapFn, thisArg)

// Inline mapping function
TypedArray.from(arrayLike, function mapFn(currentValue, index, array){ ... })
```

# Uint8Array
### Uint8Array() constructor
```js
// From a length
var uint8 = new Uint8Array(2);
uint8[0] = 42;
console.log(uint8[0]); // 42
console.log(uint8.length); // 2
console.log(uint8.BYTES_PER_ELEMENT); // 1

// From an array
var arr = new Uint8Array([21,31]);
console.log(arr[1]); // 31

// From another TypedArray
var x = new Uint8Array([21, 31]);
var y = new Uint8Array(x);
console.log(y[0]); // 21

// From an ArrayBuffer
var buffer = new ArrayBuffer(8);
var z = new Uint8Array(buffer, 1, 4);

// From an iterable
var iterable = function*(){ yield* [1,2,3]; }();
var uint8 = new Uint8Array(iterable);
// Uint8Array[1, 2, 3]
```

# Uint8ClampedArray
### Uint8ClampedArray() constructor
```js
// From a length
var uintc8 = new Uint8ClampedArray(2);
uintc8[0] = 42;
uintc8[1] = 1337;
console.log(uintc8[0]); // 42
console.log(uintc8[1]); // 255 (clamped)
console.log(uintc8.length); // 2
console.log(uintc8.BYTES_PER_ELEMENT); // 1

// From an array
var arr = new Uint8ClampedArray([21,31]);
console.log(arr[1]); // 31

// From another TypedArray
var x = new Uint8ClampedArray([21, 31]);
var y = new Uint8ClampedArray(x);
console.log(y[0]); // 21

// From an ArrayBuffer
var buffer = new ArrayBuffer(8);
var z = new Uint8ClampedArray(buffer, 1, 4);

// From an iterable
var iterable = function*(){ yield* [1,2,3]; }();
var uintc8 = new Uint8ClampedArray(iterable);
// Uint8ClampedArray[1, 2, 3]
```
# Int16Array
### Int16Array() constructor
```js
// From a length
var int16 = new Int16Array(2);
int16[0] = 42;
console.log(int16[0]); // 42
console.log(int16.length); // 2
console.log(int16.BYTES_PER_ELEMENT); // 2

// From an array
var arr = new Int16Array([21,31]);
console.log(arr[1]); // 31

// From another TypedArray
var x = new Int16Array([21, 31]);
var y = new Int16Array(x);
console.log(y[0]); // 21

// From an ArrayBuffer
var buffer = new ArrayBuffer(8);
var z = new Int16Array(buffer, 0, 4);

// From an iterable
var iterable = function*(){ yield* [1,2,3]; }();
var int16 = new Int16Array(iterable);
// Int16Array[1, 2, 3]
```

# Uint16Array
### Uint16Array() constructor
> this section is mentioned in devdocs. so it will not be included in indexed Collections. For information about Uint16Array: https://devdocs.io/javascript/global_objects/uint16array

# Int32Array
### Int32Array() constructor
```js
// From a length
var int32 = new Int32Array(2);
int32[0] = 42;
console.log(int32[0]); // 42
console.log(int32.length); // 2
console.log(int32.BYTES_PER_ELEMENT); // 4

// From an array
var arr = new Int32Array([21,31]);
console.log(arr[1]); // 31

// From another TypedArray
var x = new Int32Array([21, 31]);
var y = new Int32Array(x);
console.log(y[0]); // 21

// From an ArrayBuffer
var buffer = new ArrayBuffer(16);
var z = new Int32Array(buffer, 0, 4);

// From an iterable
var iterable = function*(){ yield* [1,2,3]; }();
var int32 = new Int32Array(iterable);
// Int32Array[1, 2, 3]
```

# Uint32Array
### Uint32Array() constructor
> this section is mentioned in devdocs. so it will not be included in indexed Collections. For information about Uint32Array: https://devdocs.io/javascript/global_objects/uint32array

# Float32Array
### Float32Array() constructor
```js
// From a length
var float32 = new Float32Array(2);
float32[0] = 42;
console.log(float32[0]); // 42
console.log(float32.length); // 2
console.log(float32.BYTES_PER_ELEMENT); // 4

// From an array
var arr = new Float32Array([21,31]);
console.log(arr[1]); // 31

// From another TypedArray
var x = new Float32Array([21, 31]);
var y = new Float32Array(x);
console.log(y[0]); // 21

// From an ArrayBuffer
var buffer = new ArrayBuffer(16);
var z = new Float32Array(buffer, 0, 4);

// From an iterable
var iterable = function*(){ yield* [1,2,3]; }();
var float32 = new Float32Array(iterable);
// Float32Array[1, 2, 3]
```

# Float64Array
### Float64Array() constructor
```js
// From a length
var float32 = new Float32Array(2);
float32[0] = 42;
console.log(float32[0]); // 42
console.log(float32.length); // 2
console.log(float32.BYTES_PER_ELEMENT); // 4

// From an array
var arr = new Float32Array([21,31]);
console.log(arr[1]); // 31

// From another TypedArray
var x = new Float32Array([21, 31]);
var y = new Float32Array(x);
console.log(y[0]); // 21

// From an ArrayBuffer
var buffer = new ArrayBuffer(16);
var z = new Float32Array(buffer, 0, 4);

// From an iterable
var iterable = function*(){ yield* [1,2,3]; }();
var float32 = new Float32Array(iterable);
// Float32Array[1, 2, 3]
```

# BigInt64Array
### BigInt64Array() constructor
```js
// From a length
var bigint64 = new BigInt64Array(2);
bigint64[0] = 42n;
console.log(bigint64[0]); // 42n
console.log(bigint64.length); // 2
console.log(bigint64.BYTES_PER_ELEMENT); // 8

// From an array
var arr = new BigInt64Array([21n,31n]);
console.log(arr[1]); // 31n

// From another TypedArray
var x = new BigInt64Array([21n, 31n]);
var y = new BigInt64Array(x);
console.log(y[0]); // 21n

// From an ArrayBuffer
var buffer = new ArrayBuffer(32);
var z = new BigInt64Array(buffer, 0, 4);

// From an iterable
var iterable = function*(){ yield* [1n, 2n, 3n]; }();
var bigint64 = new BigInt64Array(iterable);
// BigInt64Array[1n, 2n, 3n]
```

# BigUint64Array
### BigUint64Array() constructor
> this section is mentioned in devdocs. so it will not be included in indexed Collections. For information about BigUint64Array: https://devdocs.io/javascript/global_objects/uint64array
































