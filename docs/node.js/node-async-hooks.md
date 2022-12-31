<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

<h1 style="text-align:left;">Node.js - Async Hooks</h1>

**Stability**: 1 - Experimental
**Source Code**: lib\async_hooks.js

The `async_hooks` module provides an API to track asynchronous resources. It can be accessed using:
```js
import async_hooks from 'async_hooks';
```

### Terminology
An asynchronous resource represents an object with an associated callback. This callback may be called multiple times, for example, the `'connection'` event in `net.createServer()`, or just a single time like in `fs.open()`. A resource can also be closed before the callback is called. `AsyncHook` does not explicitly distinguish between these different cases but will represent them as the abstract concept that is a resource.

If Workers are used, each thread has an independent `async_hooks` interface, and each thread will use a new set of async IDs.




















