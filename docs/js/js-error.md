<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Error</h1>

`Error` objects are thrown when runtime errors occur. The `Error` object can also be used as a base object for user-defined exceptions. See below for standard built-in error types.

## Error types
* EvalError
* RangeError
* ReferenceError
* SyntaxError
* TypeError
* URIError
* AggregateError

### EvalError
The `EvalError` object indicates an error regarding the global eval() function. This exception is not thrown by JavaScript anymore, however the `EvalError` object remains for compatibility.
```js
new EvalError()
new EvalError(message)
new EvalError(message, fileName)
new EvalError(message, fileName, lineNumber)

// example
try {
  throw new EvalError('Hello', 'someFile.js', 10);
} catch (e) {
  console.log(e instanceof EvalError); // true
  console.log(e.message);              // "Hello"
  console.log(e.name);                 // "EvalError"
  console.log(e.fileName);             // "someFile.js"
  console.log(e.lineNumber);           // 10
  console.log(e.columnNumber);         // 0
  console.log(e.stack);                // "@Scratchpad/2:2:9\n"
}
```

### RangeError
The `RangeError` object indicates an error when a value is not in the set or range of allowed values.
```js
function check(n)
{
    if( !(n >= -500 && n <= 500) )
    {throw new RangeError("The argument must be between -500 and 500.")}
}

try {check(2000)}
catch(error)
{
    if (error instanceof RangeError)
    {// Handle the error}
}
```


### ReferenceError
The `ReferenceError` object represents an error when a non-existent variable is referenced.
```js
try {
  let a = undefinedVariable
} catch (e) {
  console.log(e instanceof ReferenceError)  // true
  console.log(e.message)                    // "undefinedVariable is not defined"
  console.log(e.name)                       // "ReferenceError"
  console.log(e.fileName)                   // "Scratchpad/1"
  console.log(e.lineNumber)                 // 2
  console.log(e.columnNumber)               // 6
  console.log(e.stack)                      // "@Scratchpad/2:2:7\n"
}

```

### SyntaxError
The `SyntaxError` object represents an error when trying to interpret syntactically invalid code. It is thrown when the JavaScript engine encounters tokens or token order that does not conform to the syntax of the language when parsing code.
```js
try {
  eval('hoo bar');
} catch (e) {
  console.error(e instanceof SyntaxError); // Unexpected identifier
  console.error(e.message);                // hoo bar
  console.error(e.name);                   // SyntaxError
  console.error(e.fileName);               // ?
  console.error(e.lineNumber);             // ?
  console.error(e.columnNumber);           // ?
  console.error(e.stack);                  // @debugger eval code:3:9
}
```

### TypeError
The `TypeError` object represents an error when an operation could not be performed, typically (but not exclusively) when a value is not of the expected type.
```js
try {
  null.f()
} catch (e) {
  console.log(e instanceof TypeError)  // true
  console.log(e.message)               // "null has no properties"
  console.log(e.name)                  // "TypeError"
  console.log(e.fileName)              // "Scratchpad/1"
  console.log(e.lineNumber)            // 2
  console.log(e.columnNumber)          // 2
  console.log(e.stack)                 // "@Scratchpad/2:2:3\n"
}
```

### URIError
The `URIError` object represents an error when a global URI handling function was used in a wrong way.
```js
try {
  decodeURIComponent('%')
} catch (e) {
  console.log(e instanceof URIError)  // true
  console.log(e.message)              // "malformed URI sequence"
  console.log(e.name)                 // "URIError"
  console.log(e.fileName)             // "Scratchpad/1"
  console.log(e.lineNumber)           // 2
  console.log(e.columnNumber)         // 2
  console.log(e.stack)                // "@Scratchpad/2:2:3\n"
}
```

### AggregateError
The `AggregateError` object represents an error when several errors need to be wrapped in a single error. It is thrown when multiple errors need to be reported by an operation, for example by *Promise.any()*, when all promises passed to it reject.
```js
try {
  throw new AggregateError([new Error("some error"),], 'Hello');
} catch (e) {
  console.log(e instanceof AggregateError); // true
  console.log(e.message);                   // "Hello"
  console.log(e.name);                      // "AggregateError"
  console.log(e.errors);                    // [ Error: "some error" ]
}
```

## Constructor

### Error() constructor
The `Error` constructor creates an error object.
```js
new Error()
new Error(message)
new Error(message, fileName)
new Error(message, fileName, lineNumber)
```

## Instance properties

### Error.prototype.message()
The `message` property is a human-readable description of the error.
```js
var myErr = new Error('Could not parse input');
throw e;
```

### Error.prototype. name()
The `name` property represents a name for the type of error. The initial value is "Error".
```js
var e = new Error('Malformed input'); // e.name is 'Error'

e.name = 'ParseError';
throw e;
// e.toString() would return 'ParseError: Malformed input'
```

### Custom Error
```js
class CustomError extends Error 
{
  constructor(foo = 'bar', ...params) 
  {
    // Pass remaining arguments (including vendor specific ones) to parent constructor
    super(...params)

    // Maintains proper stack trace for where our error was thrown (only available on V8)
    if (Error.captureStackTrace) {
      Error.captureStackTrace(this, CustomError)
    }

    this.name = 'CustomError'
    // Custom debugging information
    this.foo = foo
    this.date = new Date()
  }
}

try {
  throw new CustomError('baz', 'bazMessage')
} catch(e) {
  console.error(e.name)    //CustomError
  console.error(e.foo)     //baz
  console.error(e.message) //bazMessage
  console.error(e.stack)   //stacktrace
}
```

### Example
#### Throwing a generic error
Usually you create an `Error` object with the intention of raising it using the throw keyword. You can handle the error using the try...catch construct:
```js
try {
  throw new Error('Whoops!')
} catch (e) {
  console.error(e.name + ': ' + e.message)
}

```







