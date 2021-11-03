<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">Type Script Documents</h1>

Each and every value in JavaScript has a set of behaviors you can observe from running different operations. That sounds abstract, but as a quick example, consider some operations we might run on a variable named `message`.
```ts
message.toLowerCase();
// Calling 'message'
message();
```
If we break this down, the first runnable line of code accesses a property called `toLowerCase` and then calls it. The second one tries to call `message` directly.

But assuming we don’t know the value of `message` - and that’s pretty common - we can’t reliably say what results we’ll get from trying to run any of this code. The behavior of each operation depends entirely on what value we had in the first place.

* Is `message` callable?
* Does it have a property called `toLowerCase` on it?
* If it does, is `toLowerCase` even callable?
* If both of these values are callable, what do they return?
The answers to these questions are usually things we keep in our heads when we write JavaScript, and we have to hope we got all the details right.

Let’s say `message` was defined in the following way.
```ts
const message = "Hello World!";
```



























