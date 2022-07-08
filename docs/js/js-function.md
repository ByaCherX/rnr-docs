<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Constructor

### Function() Constructor 
Creates a new Function object. Calling the constructor directly can create functions dynamically but suffers from security and similar (but far less significant) performance issues to Global_Objects/eval. However, unlike eval, the Function constructor creates functions that execute in the global scope only.
```js
function name( [param [, param, [..., param]]] ) {
   [statements]
```

### Function Default parameters
Default function parameters allow named parameters to be initialized with default values if no value or ``undefined`` is passed.
```js
function funcName1( param1 = defaultValue1, paramN = defaultValueN ) {...}
```

### Function Arguments Object
arguments is an Array-like object accessible inside functions that contains the values of the arguments passed to that function.
```js
arguments[0] // first argument function
/* Example */
function func1(a,b,c) { console.log(arguments[0]) ... };
func1(1,2,3);
```
Each argument can also be set or reassigned:
```js
arguments[1] = 'new value';
```

## Instance properties
* Function.length()
* Function.name()

### Function.length()
The length property indicates the number of parameters expected by the function.
```js
funcName1.length
```
``length`` bir fonksiyon nesnesinin bir özelliğidir ve fonksiyonun kaç tane argüman beklediğini, yani resmi parametre sayısını gösterir. Bu sayı rest parametresini hariç tutar ve yalnızca varsayılan değere sahip ilkinden önceki parametreleri içerir. Buna karşılık, *arguments.length* bir işlev için yereldir ve işleve fiilen iletilen argümanların sayısını sağlar.

### Function.name()
A Function object's read-only ``name`` property indicates the function's name as specified when it was created, or it may be either ``anonymous`` or ``''`` (an empty string) for functions created anonymously.
```js
funcName1.name
```

## Instance methods
* Function.apply()
* Function.bind()
* Function.call()
* Function.toString()

### Function.apply()
The ``apply()`` method calls a function with a given *this* value, and *arguments* provided as an array (or an array-like object).
```js
apply(thisArg, argsArray)
```

### Function.bind()
The ``bind()`` method creates a new function that, when called, has its ``this`` keyword set to the provided value, with a given sequence of arguments preceding any provided when the new function is called.
```js
bind(thisArg)
bind(thisArg, arg1, ..., argN)
```
!!! not aviable more documents \ coming later.

### Function.call()
The call() method calls a function with a given this value and arguments provided individually.
```js
call(thisArg)
call(thisArg, arg1, ..., argN)
```

### Function.toString()
The ``toString()`` method returns a string representing the source code of the function.
```js
toString()
```

## Function Advanced
* Function*
* [AsyncFunction](js-async-await.md)

### Function*
The function* keyword can be used to define a generator function inside an expression.
```js
function* [name]( [param1 [, param2[, ..., paramN]]] ) {
    statements
}
```

### Async function 
An async function is a function declared with the `async` keyword, and the `await` keyword is permitted within them. The `async` and `await` keywords enable asynchronous, promise-based behavior to be written in a cleaner style, avoiding the need to explicitly configure promise chains.
```js
async function name([param [, ...paramN]]) {
   statements
}

// example
function resolve2Seconds() 
{
  return new Promise(resolve => {
    setTimeout(() => {resolve('resolved');}, 2000);
  });
}

async function asyncCall() 
{
  console.log('calling');
  const result = await resolve2Seconds();
  console.log(result);
  // expected output: "resolved"
}
asyncCall();
```
Async functions can contain zero or more *await* expressions. Await expressions make promise-returning functions behave as though they're synchronous by suspending execution until the returned promise is fulfilled or rejected. The resolved value of the promise is treated as the return value of the await expression. Use of `async` and `await` enables the use of ordinary `try` / `catch` blocks around asynchronous code.

> [!IMPORTANT]
> The `await` keyword is only valid inside async functions within regular JavaScript code. If you use it outside of an async function's body, you will get a *SyntaxError*.











