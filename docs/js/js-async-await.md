<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

<h1 style="text-align:center">Promises, Async/Await</h1>

Many functions are provided by JavaScript host environments that allow you to schedule asynchronous actions. In other words, actions that we initiate now, but they finish later.

For instance, one such function is the `setTimeout` function.

There are other real-world examples of asynchronous actions, e.g. loading scripts and modules (we’ll cover them in later chapters).

## Promise 
The analogy isn’t terribly accurate, because JavaScript promises are more complex than a simple subscription list: they have additional features and limitations. But it’s fine to begin with.

The constructor syntax for a promise object is:
```js
let promise = new Promise(function(resolve, reject) {
  // executor (the producing code, "singer")
});
```
The function passed to `new Promise` is called the executor. When `new Promise` is created, the executor runs automatically. It contains the producing code which should eventually produce the result. In terms of the analogy above: the executor is the “singer”.

The Promise object represents the eventual completion (or failure) of an asynchronous operation and its resulting value.

A `Promise` is a proxy for a value not necessarily known when the promise is created. It allows you to associate handlers with an asynchronous action's eventual success value or failure reason. This lets asynchronous methods return values like synchronous methods: instead of immediately returning the final value, the asynchronous method returns a promise to supply the value at some point in the future.

A `Promise` is in one of these states:

* *pending*: initial state, neither fulfilled nor rejected.
* *fulfilled*: meaning that the operation was completed successfully.
* *rejected*: meaning that the operation failed.

A pending promise can either be fulfilled with a value or rejected with a reason (error). When either of these options happens, the associated handlers queued up by a promise's `then` method are called. If the promise has already been fulfilled or rejected when a corresponding handler is attached, the handler will be called, so there is no race condition between an asynchronous operation completing and its handlers being attached.

### Chained Promises
The methods `promise.then()`, `promise.catch()`, and `promise.finally()` are used to associate further action with a promise that becomes settled.

The `.then()` method takes up to two arguments; the first argument is a callback function for the resolved case of the promise, and the second argument is a callback function for the rejected case. Each `.then()` returns a newly generated promise object, which can optionally be used for chaining; for example:
```js
const myPromise = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve('foo');
  }, 300);
});

myPromise
  .then(handleResolvedA, handleRejectedA)
  .then(handleResolvedB, handleRejectedB)
  .then(handleResolvedC, handleRejectedC);
```

### Example 
```js
let myFirstPromise = new Promise((resolve, reject) => {
  // We call resolve(...) when what we were doing asynchronously was successful, and reject(...) when it failed.
  // In this example, we use setTimeout(...) to simulate async code.
  // In reality, you will probably be using something like XHR or an HTML5 API.
  setTimeout( function() {
    resolve("Success!")  // Yay! Everything went well!
  }, 250)
})

myFirstPromise.then((successMessage) => {
  // successMessage is whatever we passed in the resolve(...) function above.
  // It doesn't have to be a string, but if it is only a succeed message, it probably will be.
  console.log("Yay! " + successMessage)
});
```

# Static methods

## Promise.then()
The `then()` method returns a Promise. It takes up to two arguments: callback functions for the success and failure cases of the `Promise`.

**Syntax**
```js
p.then(onFulfilled[, onRejected]);

p.then(value => {
  // fulfillment
}, reason => {
  // rejection
});
```

### Example
#### Using the then method
```js
var p1 = new Promise((resolve, reject) => {
  resolve('Success!');
  // or
  // reject(new Error("Error!"));
});

p1.then(value => {
  console.log(value); // Success!
}, reason => {
  console.error(reason); // Error!
});
```

#### Chaining
The `then` method returns a `Promise` which allows for method chaining.

If the function passed as handler to `then` returns a `Promise`, an equivalent `Promise` will be exposed to the subsequent then in the method chain. The below snippet simulates asynchronous code with the `setTimeout` function.
```js
Promise.resolve('foo')
  // 1. Receive "foo", concatenate "bar" to it, and resolve that to the next then
  .then(function(string) {
    return new Promise(function(resolve, reject) {
      setTimeout(function() {
        string += 'bar';
        resolve(string);
      }, 1);
    });
  })
  // 2. receive "foobar", register a callback function to work on that string
  // and print it to the console, but not before returning the unworked on
  // string to the next then
  .then(function(string) {
    setTimeout(function() {
      string += 'baz';
      console.log(string); // foobarbaz
    }, 1)
    return string;
  })
  // 3. print helpful messages about how the code in this section will be run
  // before the string is actually processed by the mocked asynchronous code in the
  // previous then block.
  .then(function(string) {
    console.log("Last Then:  oops... didn't bother to instantiate and return " +
                "a promise in the prior then so the sequence may be a bit " +
                "surprising");

    // Note that `string` will not have the 'baz' bit of it at this point. This
    // is because we mocked that to happen asynchronously with a setTimeout function
    console.log(string); // foobar
  });

// logs, in order:
// Last Then: oops... didn't bother to instantiate and return a promise in the prior then so the sequence may be a bit surprising
// foobar
// foobarbaz
```


## Promise.all()
The `Promise.all()` method takes an iterable of promises as an input, and returns a single Promise that resolves to an array of the results of the input promises. This returned promise will resolve when all of the input's promises have resolved, or if the input iterable contains no promises. It rejects immediately upon any of the input promises rejecting or non-promises throwing an error, and will reject with this first rejection message / error.

**Syntax**
```js
Promise.all(iterable);
```

**Return value**
* An already resolved Promise if the iterable passed is empty.
* An asynchronously resolved Promise if the iterable passed contains no promises. Note, Google Chrome 58 returns an already resolved promise in this case.
* A pending Promise in all other cases. This returned promise is then resolved/rejected asynchronously (as soon as the stack is empty) when all the promises in the given iterable have resolved, or if any of the promises reject. See the example about "Asynchronicity or synchronicity of Promise.all" below. Returned values will be in order of the Promises passed, regardless of completion order.

### Fulfillment
The returned promise is fulfilled with an array containing all the resolved values (including non-promise values) in the iterable passed as the argument.

* If an empty iterable is passed, then the promise returned by this method is fulfilled synchronously. The resolved value is an empty array.
* If a nonempty iterable is passed, and all of the promises fulfill, or are not promises, then the promise returned by this method is fulfilled asynchronously.

### Example
#### Using Promise.all
`Promise.all` waits for all fulfillments (or the first rejection).
```js
var p1 = Promise.resolve(3);
var p2 = 1337;
var p3 = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("foo");
  }, 100);
});

Promise.all([p1, p2, p3]).then(values => {
  console.log(values); // [3, 1337, "foo"]
});
```
```js
// this will be counted as if the iterable passed is empty, so it gets fulfilled
var p = Promise.all([1,2,3]);
// this will be counted as if the iterable passed contains only the resolved promise with value "444", so it gets fulfilled
var p2 = Promise.all([1,2,3, Promise.resolve(444)]);
// this will be counted as if the iterable passed contains only the rejected promise with value "555", so it gets rejected
var p3 = Promise.all([1,2,3, Promise.reject(555)]);

// using setTimeout we can execute code after the stack is empty
setTimeout(function() {
    console.log(p);
    console.log(p2);
    console.log(p3);
});

// logs
// Promise { <state>: "fulfilled", <value>: Array[3] }
// Promise { <state>: "fulfilled", <value>: Array[4] }
// Promise { <state>: "rejected", <reason>: 555 }
```
#### Asynchronicity or synchronicity of Promise.all
This following example demonstrates the asynchronicity (or synchronicity, if the iterable passed is empty) of Promise.all:
```js
var resolvedPromisesArray = [Promise.resolve(33), Promise.resolve(44)];

var p = Promise.all(resolvedPromisesArray);
// immediately logging the value of p
console.log(p);

// using setTimeout we can execute code after the stack is empty
setTimeout(function() {
    console.log('the stack is now empty');
    console.log(p);
});

// logs, in order:
// Promise { <state>: "pending" }
// the stack is now empty
// Promise { <state>: "fulfilled", <value>: Array[2] }
```

## Promise.any()
`Promise.any()` takes an iterable of Promise objects. It returns a single promise that resolves as soon as any of the promises in the iterable fulfills, with the value of the fulfilled promise. If no promises in the iterable fulfill (if all of the given promises are rejected), then the returned promise is rejected with an AggregateError, a new subclass of Error that groups together individual errors.

**Syntax**
```js
Promise.any(iterable);
```

**Description**
This method is useful for returning the first promise that fulfills. It short-circuits after a promise fulfills, so it does not wait for the other promises to complete once it finds one. Unlike Promise.all(), which returns an array of fulfillment values, we only get one fulfillment value (assuming at least one promise fulfills). This can be beneficial if we need only one promise to fulfill but we do not care which one does. Note another difference: This method rejects upon receiving an empty iterable, since, truthfully, the iterable contains no items that fulfill.

Also, unlike Promise.race(), which returns the first settled value (either fulfillment or rejection), this method returns the first fulfilled value. This method will ignore all rejected promises up until the first promise that fulfils.

### Example
#### First to fulfill
`Promise.any()` resolves with the first promise to fulfil, even if a promise rejects first. This is in contrast to Promise.race(), which resolves or rejects with the first promise to settle.
```js
const pErr = new Promise((resolve, reject) => {
  reject("Always fails");
});

const pSlow = new Promise((resolve, reject) => {
  setTimeout(resolve, 500, "Done eventually");
});

const pFast = new Promise((resolve, reject) => {
  setTimeout(resolve, 100, "Done quick");
});

Promise.any([pErr, pSlow, pFast]).then((value) => {
  console.log(value);
  // pFast fulfils first
})
// expected output: "Done quick"
```

#### Displaying the first image loaded
In this example, we have a function that fetches an image and returns a blob. We use `Promise.any()` to fetch a couple of images and display the first one available (i.e. whose promise has resolved).
```js
function fetchAndDecode(url) {
  return fetch(url).then(response => {
    if(!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    } else {
      return response.blob();
    }
  })
}

let coffee = fetchAndDecode('coffee.jpg');
let tea = fetchAndDecode('tea.jpg');

Promise.any([coffee, tea]).then(value => {
  let objectURL = URL.createObjectURL(value);
  let image = document.createElement('img');
  image.src = objectURL;
  document.body.appendChild(image);
})
.catch(e => {
  console.log(e.message);
});
```

## Promise.catch()
The `catch()` method returns a Promise and deals with rejected cases only. It behaves the same as calling Promise.prototype.then(undefined, onRejected) (in fact, calling `obj.catch(onRejected)` internally calls `obj.then(undefined, onRejected)`). This means that you have to provide an onRejected function even if you want to fall back to an undefined result value - for example `obj.catch(() => {}`).

**Syntax**
```js
p.catch(onRejected);

p.catch(function(reason) {
    // rejection
});
```
### Example
#### Using and chaining the catch method
```js
var p1 = new Promise(function(resolve, reject) {
  resolve('Success');
});

p1.then(function(value) {
  console.log(value); // "Success!"
  throw new Error('oh, no!');
}).catch(function(e) {
  console.error(e.message); // "oh, no!"
}).then(function(){
  console.log('after a catch the chain is restored');
}, function () {
  console.log('Not fired due to the catch');
});

// The following behaves the same as above
p1.then(function(value) {
  console.log(value); // "Success!"
  return Promise.reject('oh, no!');
}).catch(function(e) {
  console.error(e); // "oh, no!"
}).then(function(){
  console.log('after a catch the chain is restored');
}, function () {
  console.log('Not fired due to the catch');
});
```
#### If it is resolved
```js
//Create a promise which would not call onReject
var p1 = Promise.resolve("calling next");

var p2 = p1.catch(function (reason) {
    //This is never called
    console.error("catch p1!");
    console.error(reason);
});

p2.then(function (value) {
    console.log("next promise's onFulfilled"); /* next promise's onFulfilled */
    console.log(value); /* calling next */
}, function (reason) {
    console.log("next promise's onRejected");
    console.log(reason);
});
```

## Promise.finally()
The `finally()` method returns a Promise. When the promise is settled, i.e either fulfilled or rejected, the specified callback function is executed. This provides a way for code to be run whether the promise was fulfilled successfully or rejected once the Promise has been dealt with.

This helps to avoid duplicating code in both the promise's then() and catch() handlers.

**Syntax**
```js
p.finally(onFinally);

p.finally(function() {
    // settled (fulfilled or rejected)
})
```

**Description**
The `finally()` method can be useful if you want to do some processing or cleanup once the promise is settled, regardless of its outcome.

The `finally()` method is very similar to calling `.then(onFinally, onFinally)` however there are a couple of differences:

* When creating a function inline, you can pass it once, instead of being forced to either declare it twice, or create a variable for it
* A `finally` callback will not receive any argument, since there's no reliable means of determining if the promise was fulfilled or rejected. This use case is for precisely when you do not care about the rejection reason, or the fulfillment value, and so there's no need to provide it. So for example:
  - Unlike `Promise.resolve(2).then(() => {}, () => {})` (which will be resolved with undefined), `Promise.resolve(2).finally(() => {})` will be resolved with 2.
  - Similarly, unlike `Promise.reject(3).then(() => {}, () => {})` (which will be fulfilled with undefined), `Promise.reject(3).finally(() => {})` will be rejected with 3.

### Example
#### Using finally
```js
let isLoading = true;

fetch(myRequest).then(function(response) {
    var contentType = response.headers.get("content-type");
    if(contentType && contentType.includes("application/json")) {
      return response.json();
    }
    throw new TypeError("Oops, we haven't got JSON!");
  })
  .then(function(json) { /* process your JSON further */ })
  .catch(function(error) { console.error(error); /* this line can also throw, e.g. when console = {} */ })
  .finally(function() { isLoading = false; });
```

## Promise.reject()
The `Promise.reject()` method returns a `Promise` object that is rejected with a given reason.

**Syntax**
```js
Promise.reject(reason);
```

**Description**
The static `Promise.reject` function returns a `Promise` that is rejected. For debugging purposes and selective error catching, it is useful to make reason an instanceof Error.

### Example
#### Using the static Promise.reject() method
```js
Promise.reject(new Error('fail')).then(function() {
  // not called
}, function(error) {
  console.error(error); // Stacktrace
});
```

## Promise.resolve()
The `Promise.resolve()` method returns a Promise object that is resolved with a given value. If the value is a promise, that promise is returned; if the value is a thenable (i.e. has a "then" method), the returned promise will "follow" that thenable, adopting its eventual state; otherwise the returned promise will be fulfilled with the value. This function flattens nested layers of promise-like objects (e.g. a promise that resolves to a promise that resolves to something) into a single layer.

**Syntax**
```js
Promise.resolve(value);
```

### Example
#### Using the static Promise.resolve method
```js
Promise.resolve('Success').then(function(value) {
  console.log(value); // "Success"
}, function(value) {
  // not called
});
```
#### Resolving an array
```js
var p = Promise.resolve([1,2,3]);
p.then(function(v) {
  console.log(v[0]); // 1
});
```
#### Resolving another Promise
```js
var original = Promise.resolve(33);
var cast = Promise.resolve(original);
cast.then(function(value) {
  console.log('value: ' + value);
});
console.log('original === cast ? ' + (original === cast));

// logs, in order:
// original === cast ? true
// value: 33
```

# Microtask
Promise handlers `.then/.catch/.finally` are always asynchronous.

Even when a Promise is immediately resolved, the code on the lines below `.then/.catch/.finally` will still execute before these handlers.

Here’s a demo:
```js
let promise = Promise.resolve();

promise.then(() => alert("promise done!"));

console.log("code finished"); // this alert shows first
```

## Microtasks queue
Asynchronous tasks need proper management. For that, the ECMA standard specifies an internal queue `PromiseJobs`, more often referred to as the “microtask queue” (V8 term).

As stated in the specification:
* The queue is first-in-first-out: tasks enqueued first are run first.
* Execution of a task is initiated only when nothing else is running.

Or, to put it more simply, when a promise is ready, its .then/catch/finally handlers are put into the queue; they are not executed yet. When the JavaScript engine becomes free from the current code, it takes a task from the queue and executes it.

That’s why “code finished” in the example above shows first.

## Unhandled rejection
Normally, if we expect an error, we add .catch to the promise chain to handle it:
```js
let promise = Promise.reject(new Error("Promise Failed!"));
promise.catch(err => alert('caught'));

// doesn't run: error handled
window.addEventListener('unhandledrejection', event => alert(event.reason));
```
But if we forget to add .catch, then, after the microtask queue is empty, the engine triggers the event:
```js
let promise = Promise.reject(new Error("Promise Failed!"));

// Promise Failed!
window.addEventListener('unhandledrejection', event => alert(event.reason));
```
What if we handle the error later? Like this:
```js
let promise = Promise.reject(new Error("Promise Failed!"));
setTimeout(() => promise.catch(err => alert('caught')), 1000);

// Error: Promise Failed!
window.addEventListener('unhandledrejection', event => alert(event.reason));
```
Now, if we run it, we’ll see Promise Failed! first and then caught.

If we didn’t know about the microtasks queue, we could wonder: “Why did `unhandledrejection` handler run? We did catch and handle the error!”

But now we understand that `unhandledrejection` is generated when the microtask queue is complete: the engine examines promises and, if any of them is in the “rejected” state, then the event triggers.

In the example above, .catch added by setTimeout also triggers. But it does so later, after `unhandledrejection` has already occurred, so it doesn’t change anything.

# Async / await
There’s a special syntax to work with promises in a more comfortable fashion, called “async/await”. It’s surprisingly easy to understand and use.

## Async functions
Let’s start with the `async` keyword. It can be placed before a function, like this:
```js
async function f() {
  return 1;
}
```
The word “async” before a function means one simple thing: a function always returns a promise. Other values are wrapped in a resolved promise automatically.

For instance, this function returns a resolved promise with the result of 1; let’s test it:
```js
async function f() {
  return 1;
}

f().then(alert); // 1
```
So, `async` ensures that the function returns a promise, and wraps non-promises in it. Simple enough, right? But not only that. There’s another keyword, `await`, that works only inside `async` functions, and it’s pretty cool.

## Await

**Syntax**
```js
// works only inside async functions
let value = await promise;
```

The keyword `await` makes JavaScript wait until that promise settles and returns its result.

Here’s an example with a promise that resolves in 1 second:
```js
async function f() {

  let promise = new Promise((resolve, reject) => {
    setTimeout(() => resolve("done!"), 1000)
  });

  let result = await promise; // wait until the promise resolves (*)

  alert(result); // "done!"
}

f();
```
The function execution “pauses” at the line (*) and resumes when the promise settles, with result becoming its result. So the code above shows “done!” in one second.

Let’s emphasize: `await` literally suspends the function execution until the promise settles, and then resumes it with the promise result. That doesn’t cost any CPU resources, because the JavaScript engine can do other jobs in the meantime: execute other scripts, handle events, etc.

It’s just a more elegant syntax of getting the promise result than `promise.then`. And, it’s easier to read and write.

### Async class methods
To declare an async class method, just prepend it with `async`:
```js
class Waiter {
  async wait() {
    return await Promise.resolve(1);
  }
}

new Waiter()
  .wait()
  .then(alert); // 1 (this is the same as (result => alert(result)))
```

### await accepts "thenables"
Like `promise.then`, `await` allows us to use thenable objects (those with a callable then method). The idea is that a third-party object may not be a promise, but promise-compatible: if it supports .then, that’s enough to use it with `await`.

Here’s a demo `Thenable` class; the `await` below accepts its instances:
```js
class Thenable {
  constructor(num) { this.num = num; }

  then(resolve, reject) {
    alert(resolve);
    // resolve with this.num*2 after 1000ms
    setTimeout(() => resolve(this.num * 2), 1000); // (*)
  }
}

async function f() {
  // waits for 1 second, then result becomes 2
  let result = await new Thenable(1);
  alert(result);
}

f();
```




















