<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center;">JavaScript - Web Assembly</h1>

The `WebAssembly` JavaScript object acts as the namespace for all WebAssembly-related functionality.

Unlike most other global objects, `WebAssembly` is not a constructor (it is not a function object). You can compare it to Math, which is also a namespace object for mathematical constants and functions, or to Intl which is the namespace object for internationalization constructors and other language-sensitive functions.

### Description
The primary uses for the `WebAssembly` object are:
* Loading WebAssembly code, using the WebAssembly.instantiate() function.
* Creating new memory and table instances via the WebAssembly.Memory()/WebAssembly.Table() constructors.
* Providing facilities to handle errors that occur in WebAssembly via the WebAssembly.CompileError()/WebAssembly.LinkError()/WebAssembly.RuntimeError() constructors.

## Constructor properties

### WebAssembly.CompileError()
The `WebAssembly.CompileError()` constructor creates a new WebAssembly `CompileError` object, which indicates an error during WebAssembly decoding or validation.

#### Syntax
```js
new WebAssembly.CompileError()
new WebAssembly.CompileError(message)
new WebAssembly.CompileError(message, fileName)
new WebAssembly.CompileError(message, fileName, lineNumber)
```

#### Examples
```js
try {
  throw new WebAssembly.CompileError('Hello', 'someFile', 10);
} catch (e) {
  console.log(e instanceof CompileError); // true
  console.log(e.message);                 // "Hello"
  console.log(e.name);                    // "CompileError"
  console.log(e.fileName);                // "someFile"
  console.log(e.lineNumber);              // 10
  console.log(e.columnNumber);            // 0
  console.log(e.stack);                   // returns the location where the code was run
}
```

### WebAssembly.Global() constructor
A `WebAssembly.Global()` constructor creates a new `Global` object representing a global variable instance, accessible from both JavaScript and importable/exportable across one or more WebAssembly.Module instances. This allows dynamic linking of multiple modules.

#### Syntax
```js
new WebAssembly.Global(descriptor, value)
```

#### Parameters
**descriptor**
A `GlobalDescriptor` dictionary object, which contains two properties:

* `value`: A USVString representing the data type of the global. This can be any one of:
  - i32: A 32-bit integer.
  - i64: A 64-bit integer.
  - f32: A 32-bit floating point number.
  - f64: A 64-bit floating point number.
  - v128: A 128-bit vector - note that although this is in the specification, in chrome this produces a TypeError.
  - externref: A host reference.
  - anyfunc: A function reference.
* `mutable`: A boolean value that determines whether the global is mutable or not. By default, this is `false`.

### WebAssembly.RuntimeError() constructor
The `WebAssembly.RuntimeError()` constructor creates a new WebAssembly `RuntimeError` object — the type that is thrown whenever WebAssembly specifies a trap.

#### Syntax
```js
new WebAssembly.RuntimeError()
new WebAssembly.RuntimeError(message)
new WebAssembly.RuntimeError(message, fileName)
new WebAssembly.RuntimeError(message, fileName, lineNumber)
```

#### Examples
```js
try {
  throw new WebAssembly.RuntimeError('Hello', 'someFile', 10);
} catch (e) {
  console.log(e instanceof WebAssembly.RuntimeError); // true
  console.log(e.message);                             // "Hello"
  console.log(e.name);                                // "RuntimeError"
  console.log(e.fileName);                            // "someFile"
  console.log(e.lineNumber);                          // 10
  console.log(e.columnNumber);                        // 0
  console.log(e.stack);                               // returns the location where the code was run
}
```
















