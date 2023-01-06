<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Array Advanced</h1>

## TypedArray
A TypedArray object describes an array-like view of an underlying binary data buffer. There is no global property named `TypedArray`, nor is there a directly visible `TypedArray` constructor. Instead, there are a number of different global properties, whose values are typed array constructors for specific element types, listed below. On the following pages you will find common properties and methods that can be used with any typed array containing elements of any type.

**Description**
ECMAScript 2015 defines a `TypedArray` constructor that serves as the `[[Prototype]]` of all `TypedArray` constructors. This constructor is not directly exposed: there is no global `%TypedArray%` or `TypedArray` property. It is only directly accessible through `Object.getPrototypeOf(Int8Array)` and similar. All TypedArrays constructors inherit common properties from the `%TypedArray%` constructor function. Additionally, all typed array prototypes (`TypedArray.prototype`) have `%TypedArray%.prototype` as their `[[Prototype]]`.

When creating an instance of a `TypedArray` (e.g. `Int8Array`), an array buffer is created internally in memory or, if an `ArrayBuffer` object is given as constructor argument, then this is used instead. The buffer address is saved as an internal property of the instance and all the methods of %TypedArray%.prototype, i.e. set value and get value etc., operate on that array buffer address.

### TypedArray objects

| Type | Value Range | Size in bytes | Description | Web IDL type | Equivalent C type |
|--|--|--|--|--|--|
| Int8Array | -128 to 127 | 1 | 8-bit two's complement signed integer | byte | int8_t |
| Uint8Array | 0 to 255 | 1 | 8-bit unsigned integer | octet | uint8_t |
| Uint8ClampedArray | 0 to 255 | 1 | 8-bit unsigned integer (clamped) | octet | uint8_t |
| Int16Array | -32768 to 32767 | 2 | 16-bit two's complement signed integer | short | int16_t |
| Uint16Array | 0 to 65535 | 2 | 16-bit unsigned integer | unsigned short | uint16_t |
| Int32Array | -2147483648 to 2147483647 | 4 | 32-bit two's complement signed integer | long | int32_t |
| Uint32Array | 0 to 4294967295 | 4 | 32-bit unsigned integer | unsigned long | uint32_t |
| Float32Array | -3.4E38 to 3.4E38 and 1.2E-38 is the min positive number | 4 | 32-bit IEEE floating point number (7 significant digits e.g., 1.234567) | unrestricted float | float |
| Float64Array | -1.8E308 to 1.8E308 and 5E-324 is the min positive number | 8 | 64-bit IEEE floating point number (16 significant digits e.g., 1.23456789012345) | unrestricted double | double |
| BigInt64Array | -2^63 to 2^63 - 1 | 8 | 64-bit two's complement signed integer | bigint | int64_t (signed long long) |
| BigUint64Array | 0 to 2^64 - 1 | 8 | 64-bit unsigned integer | bigint | uint64_t (unsigned long long) |

### Constructor
```js
new TypedArray()
new TypedArray(length)
new TypedArray(typedArray)
new TypedArray(object)

new TypedArray(buffer)
new TypedArray(buffer, byteOffset)
new TypedArray(buffer, byteOffset, length)
```

#### Parameters
**Length**: When called with a `length` argument, an internal array buffer is created in memory, of size `length` multiplied by BYTES_PER_ELEMENT bytes, containing zeros.

**typedArray**: When called with a `typedArray` argument, which can be an object of any of the non-bigint typed-array types (such as Int32Array), the `typedArray` gets copied into a new typed array. Each value in `typedArray` is converted to the corresponding type of the constructor before being copied into the new array. The length of the new typed array will be same as the length of the `typedArray` argument.

**object**
When called with an `object` argument, a new typed array is created as if by the `TypedArray.from()` method.

**buffer, byteOffset, length**
When called with a `buffer`, and optionally a `byteOffset` and a `length` argument, a new typed array view is created that views the specified [ArrayBuffer](https://devdocs.io/javascript/global_objects/arraybuffer). The `byteOffset` and `length` parameters specify the memory range that will be exposed by the typed array view. If both are omitted, all of `buffer` is viewed; if only length is omitted, the remainder of `buffer` is viewed.

## Static properties

### TypedArray.BYTES_PER_ELEMENT
The ``TypedArray.BYTES_PER_ELEMEN``T property represents the size in bytes of each element in an typed array.
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


### TypedArray.name
The ``TypedArray.name`` property represents a string value of the typed array constructor name.
```js
Int8Array.name;         // "Int8Array"
Uint8Array.name;        // "Uint8Array"
Uint8ClampedArray.name; // "Uint8ClampedArray"
Int16Array.name;        // "Int16Array"
Uint16Array.name;       // "Uint16Array"
Int32Array.name;        // "Int32Array"
Uint32Array.name;       // "Uint32Array"
Float32Array.name;      // "Float32Array"
Float64Array.name;      // "Float64Array"
```









