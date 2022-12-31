<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Advanced functions</h1>

## Recursion and Stack
Let’s return to functions and study them more in-depth.

Our first topic will be recursion.

If you are not new to programming, then it is probably familiar and you could skip this chapter.

Recursion is a programming pattern that is useful in situations when a task can be naturally split into several tasks of the same kind, but simpler. Or when a task can be simplified into an easy action plus a simpler variant of the same task. Or, as we’ll see soon, to deal with certain data structures.

When a function solves a task, in the process it can call many other functions. A partial case of this is when a function calls itself. That’s called recursion.

### Two ways of thinking
For something simple to start with – let’s write a function `pow(x, n)` that raises x to a natural power of n. In other words, multiplies x by itself n times.
```js
pow(2, 2) = 4
pow(2, 3) = 8
pow(2, 4) = 16
```

<dclr>**1.**</dclr> Iterative thinking: the for loop:

```js
function pow(x, n) {
  let result = 1;

  // multiply result by x n times in the loop
  for (let i = 0; i < n; i++) {
    result *= x;
  }

  return result;
}

alert( pow(2, 3) ); // 8
```

<dclr>**2.**</dclr> Recursive thinking: simplify the task and call self:

```js
function pow(x, n) {
  if (n == 1) {
    return x;
  } else {
    return x * pow(x, n - 1);
  }
}

alert( pow(2, 3) ); // 8
```

## Rest parameters and spread syntax
Many JavaScript built-in functions support an arbitrary number of arguments.

### Rest parameters
A function can be called with any number of arguments, no matter how it is defined.
```js
function sum(a, b) {return a + b;}

alert( sum(1, 2, 3, 4, 5) );
```
The rest of the parameters can be included in the function definition by using three dots ... followed by the name of the array that will contain them. The dots literally mean “gather the remaining parameters into an array”.

For instance, to gather all arguments into array args:
```js
function sumAll(...args) {   // args is the name for the array
  let sum = 0;
  for ( let arg of args ) sum += arg;
  return sum;
}

alert( sumAll(1) ); // 1
alert( sumAll(1, 2, 3) ); // 6
```

## The "new Function" syntax
There’s one more way to create a function. It’s rarely used, but sometimes there’s no alternative.

### Syntax
The syntax for creating a function:
```js
let func = new Function ([arg1, arg2, ...argN], functionBody);
```

The function is created with the arguments arg1...argN and the given functionBody.

It’s easier to understand by looking at an example. Here’s a function with two arguments:
```js
let sum = new Function('a', 'b', 'return a + b');

alert( sum(1, 2) ); // 3
```

## Scheduling: setTimeout and setInterval
We may decide to execute a function not right now, but at a certain time later. That’s called “scheduling a call”.

There are two methods for it:

setTimeout allows us to run a function once after the interval of time.
setInterval allows us to run a function repeatedly, starting after the interval of time, then repeating continuously at that interval.

These methods are not a part of JavaScript specification. But most environments have the internal scheduler and provide these methods. In particular, they are supported in all browsers and Node.js.

### setTimeout
**The syntax:**
```js
let timerId = setTimeout( func|code, [delay], [arg1], [arg2], ... )
```
**Parameters:**

<dclr>func|code</dclr></br>
Function or a string of code to execute. Usually, that’s a function. For historical reasons, a string of code can be passed, but that’s not recommended.

<dclr>delay</dclr></br>
The delay before run, in milliseconds (1000 ms = 1 second), by default 0.

<dclr>arg1, arg2…</dclr></br>
Arguments for the function (not supported in IE9-)

**Example:**
```js
function sayHi() {alert('Hello');}

setTimeout(sayHi, 1000);

// with arguments
function sayHi(phrase, who) {alert( phrase + ', ' + who );}

setTimeout(sayHi, 1000, "Hello", "John"); // Hello, John

// But using strings is not recommended, use arrow functions instead of them, like this:
setTimeout(() => alert('Hello'), 1000);
```

### setInterval
The setInterval method has the same syntax as setTimeout:
```js
let timerId = setInterval( func|code, [delay], [arg1], [arg2], ... )
```
All arguments have the same meaning. But unlike setTimeout it runs the function not only once, but regularly after the given interval of time.

To stop further calls, we should call ``clearInterval(timerId)``.

The following example will show the message every 2 seconds. After 5 seconds, the output is stopped:

## Decorators and forwarding, call/apply
JavaScript gives exceptional flexibility when dealing with functions. They can be passed around, used as objects, and now we’ll see how to forward calls between them and decorate them.

### Transparent Caching
Let’s say we have a function `slow(x)` which is CPU-heavy, but its results are stable. In other words, for the same x it always returns the same result.

If the function is called often, we may want to cache (remember) the results to avoid spending extra-time on recalculations.

But instead of adding that functionality into `slow()` we’ll create a wrapper function, that adds caching. As we’ll see, there are many benefits of doing so.

Here’s the code, and explanations follow:
```js
function slow(x) {
  // there can be a heavy CPU-intensive job here
  alert(`Called with ${x}`);
  return x;
}

function cachingDecorator(func) {
  let cache = new Map();

  return function(x) {
    if (cache.has(x)) {    // if there's such key in cache
      return cache.get(x); // read the result from it
    }

    let result = func(x);  // otherwise call func

    cache.set(x, result);  // and cache (remember) the result
    return result;
  };
}

slow = cachingDecorator(slow);

alert( slow(1) );               // slow(1) is cached and the result returned
alert( "Again: " + slow(1) );   // slow(1) result returned from cache

alert( slow(2) );               // slow(2) is cached and the result returned
alert( "Again: " + slow(2) );   // slow(2) result returned from cache
```
In the code above `cachingDecorator` is a decorator: a special function that takes another function and alters its behavior.

The idea is that we can call `cachingDecorator` for any function, and it will return the caching wrapper. That’s great, because we can have many functions that could use such a feature, and all we need to do is to apply `cachingDecorator` to them.

By separating caching from the main function code we also keep the main code simpler.

The result of `cachingDecorator(func)` is a “wrapper”: `function(x)` that “wraps” the call of `func(x)` into caching logic</br>
From an outside code, the wrapped `slow` function still does the same. It just got a caching aspect added to its behavior.

To summarize, there are several benefits of using a separate `cachingDecorator` instead of altering the code of `slow` itself:
* The `cachingDecorator` is reusable. We can apply it to another function.
* The caching logic is separate, it did not increase the complexity of `slow` itself (if there was any).
* We can combine multiple decorators if needed (other decorators will follow).

## Arrow functions revisited
Let’s revisit arrow functions.

Arrow functions are not just a “shorthand” for writing small stuff. They have some very specific and useful features.

JavaScript is full of situations where we need to write a small function that’s executed somewhere else.

**For instance:**
* arr.forEach(func) – func is executed by forEach for every array item.
* setTimeout(func) – func is executed by the built-in scheduler.
* …there are more.

It’s in the very spirit of JavaScript to create a function and pass it somewhere.

And in such functions we usually don’t want to leave the current context. That’s where arrow functions come in handy.



















