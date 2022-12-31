<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

## Primary Expression
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Primary Expression</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

### This
A function's `this` keyword behaves a little differently in JavaScript compared to other languages. It also has some differences between strict mode and non-strict mode.

In most cases, the value of this is determined by how a function is called (runtime binding). It can't be set by assignment during execution, and it may be different each time the function is called.
```js
this.

// In web browsers, the window object is also the global object:
console.log(this === window); // true
```
#### Examples
```js
// example 1 (this in function contexts)
var obj = {a: 'Custom'};
var a = 'Global';
function whatsThis() {return this.a;}

whatsThis();             // 'Global'
whatsThis.call(obj);     // 'Custom'
whatsThis.apply(obj);    // 'Custom'

// example 2 (this and object conversion)
function add(c,d) {return this.a + this.b + c + d;}
var o = {a:1, b:3};

add.call(o, 5, 7);         // 16
add.apply(o, [10, 20]);    // 34
```

### yield
The `yield` keyword pauses generator function execution and the value of the expression following the `yield` keyword is returned to the generator's caller. It can be thought of as a generator-based version of the `return` keyword.

yield can only be called directly from the generator function that contains it. It cannot be called from nested functions or from callbacks.

The `yield` keyword causes the call to the generator's `next()` method to return an IteratorResult object with two properties: value and done. The value property is the result of evaluating the `yield` expression, and done is false, indicating that the generator function has not fully completed.

Once paused on a `yield` expression, the generator's code execution remains paused until the generator's `next()` method is called. Each time the generator's `next()` method is called, the generator resumes execution, and runs until it reaches one of the following:
* A `yield`, which causes the generator to once again pause and return the generator's new value. The next time `next()` is called, execution resumes with the statement immediately after the `yield`.

* throw is used to throw an exception from the generator. This halts execution of the generator entirely, and execution resumes in the caller (as is normally the case when an exception is thrown).

* The end of the generator function is reached. In this case, execution of the generator ends and an `IteratorResult` is returned to the caller in which the value is undefined and `done` is `true`.

* A return statement is reached. In this case, execution of the generator ends and an `IteratorResult` is returned to the caller in which the `value` is the value specified by the return statement and `done` is `true`.
```js
/* === Syntax === */
[rv] = yield [expression] 
// [expression]: Defines the value to return from the generator function via the iterator protocol.

// example
function* counter() {
    let saleList = [3,7,5]
    for (let i=0; i < saleList.length; i++) {
       yield saleList[i]
    }
}
let Storage = counter()        // generator { }
console.log(Storage.next())    // { value: 3, done: false }
console.log(Storage.next())    // { value: 7, done: false }
console.log(Storage.next())    // { value: 5, done: false }
console.log(Storage.next())    // { value: undefined, done: true }
```

### yield*
The `yield*` expression iterates over the operand and `yields` each value returned by it.
```js
/* === Syntax === */
yield* expression;

// example 
function* g1() {yield 2; yield 3;}
function* g2() {yield 1; yield* g1(); yield 4;}
const iterator = g2();
console.log(iterator.next());   // value:1 done: false
console.log(iterator.next());   // value:2 done: false
console.log(iterator.next());   // value:3 done: false
console.log(iterator.next());   // value:4 done: false
console.log(iterator.next());   // value:undefined done: true
```

### Grouping operator ()
The grouping operator `( )` controls the precedence of evaluation in expressions.
```js
console.log(1 + 2 * 3);    // 7
console.log((1 + 2) * 3);  // 9
```


