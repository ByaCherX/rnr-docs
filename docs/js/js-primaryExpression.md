<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Primary Expression

### This
A function's `this` keyword behaves a little differently in JavaScript compared to other languages. It also has some differences between strict mode and non-strict mode.

In most cases, the value of this is determined by how a function is called (runtime binding). It can't be set by assignment during execution, and it may be different each time the function is called.
```js
this
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


### Function 
> [!NOTE]
> the function subject is explained in more detail and will not be detailed in the primaryExpression section [Function-Declaration](js-function.md)

### Class
> [!NOTE]
> the class subject is explained in more detail and will not be detailed in the primaryExpression section [Class](js-class.md)

### yield
The `yield` keyword is used to pause and resume a generator function (function* or legacy generator function).
```js
[rv] = yield [expression]
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
The `yield*` is used to delegate to another generator or iterable object.
```js
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

### await
The `await` operator is used to wait for a Promise. It can only be used inside an *async function* within regular JavaScript code; however it can be used on its own with *JavaScript modules*.
```js
[rv] = await expression;
```
The `await` expression causes `async` function execution to pause until a `Promise` is settled (that is, fulfilled or rejected), and to resume execution of the `async` function after fulfillment. When resumed, the value of the `await` expression is that of the fulfilled `Promise`.

### Array
> [!NOTE]
> the Array subject is explained in more detail and will not be detailed in the primaryExpression section [Array](js-array.md)

### Object initializer
Objects can be initialized using *new Object()*, *Object.create()*, or using the literal notation (initializer notation). An object initializer is a comma-delimited list of zero or more pairs of property names and associated values of an object, enclosed in curly braces `( {} )`
```js
let o {}
let o {a: 'foo', ..., c:{} }
let o = {
    property: function (paramaters) {},
};
```

### RegExp
The `RegExp` object is used for matching text with a pattern. For an introduction to regular expressions, read the Regular Expressions chapter in the JavaScript Guide.

### Grouping operator ()
The grouping operator `( )` controls the precedence of evaluation in expressions.
```js
console.log(1 + 2 * 3);    // 7
console.log((1 + 2) * 3);  // 9
```



