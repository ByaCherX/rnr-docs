<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

<h1 style="text-align:left;">Node.js - Console</h1>

<t8s>Stability: 2 - Stable</t8s></br>
<t8s>Source Code: lib/events.js</t8s>

Much of the Node.js core API is built around an idiomatic asynchronous event-driven architecture in which certain kinds of objects (called "emitters") emit named events that cause Function objects ("listeners") to be called.

For instance: a ``net.Server`` object emits an event each time a peer connects to it; a ``fs.ReadStream`` emits an event when the file is opened; a stream emits an event whenever data is available to be read.

All objects that emit events are instances of the ``EventEmitter`` class. These objects expose an ``eventEmitter.on()`` function that allows one or more functions to be attached to named events emitted by the object. Typically, event names are camel-cased strings but any valid JavaScript property key can be used.

When the ``EventEmitter`` object emits an event, all of the functions attached to that specific event are called synchronously. Any values returned by the called listeners are ignored and discarded.

The following example shows a simple ``EventEmitter`` instance with a single listener. The ``eventEmitter.on()`` method is used to register listeners, while the ``eventEmitter.emit()`` method is used to trigger the event.

```js
const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();
myEmitter.on('event', () => {
  console.log('an event occurred!');
});
myEmitter.emit('event');
```

## Passing arguments and this to listeners
The ``eventEmitter.emit()`` method allows an arbitrary set of arguments to be passed to the listener functions. Keep in mind that when an ordinary listener function is called, the standard this keyword is intentionally set to reference the ``EventEmitter`` instance to which the listener is attached.
```js
const myEmitter = new MyEmitter();
myEmitter.on('event', function(a, b) {
  console.log(a, b, this, this === myEmitter);
  // Prints:
  //   a b MyEmitter {
  //     domain: null,
  //     _events: { event: [Function] },
  //     _eventsCount: 1,
  //     _maxListeners: undefined } true
});
myEmitter.emit('event', 'a', 'b');
```
It is possible to use ES6 Arrow Functions as listeners, however, when doing so, the this keyword will no longer reference the EventEmitter instance:
```js
const myEmitter = new MyEmitter();
myEmitter.on('event', (a, b) => {
  console.log(a, b, this);
  // Prints: a b {}
});
myEmitter.emit('event', 'a', 'b');
```

### Asynchronous vs. synchronous
The ``EventEmitter`` calls all listeners synchronously in the order in which they were registered. This ensures the proper sequencing of events and helps avoid race conditions and logic errors. When appropriate, listener functions can switch to an asynchronous mode of operation using the ``setImmediate()`` or ``process.nextTick()`` methods:
```js
const myEmitter = new MyEmitter();
myEmitter.on('event', (a, b) => {
  setImmediate(() => {
    console.log('this happens asynchronously');
  });
});
myEmitter.emit('event', 'a', 'b');
```

## Handling events only once
When a listener is registered using the ``eventEmitter.on()`` method, that listener is invoked every time the named event is emitted.
```js
const myEmitter = new MyEmitter();
let m = 0;
myEmitter.on('event', () => {
  console.log(++m);
});
myEmitter.emit('event');
// Prints: 1
myEmitter.emit('event');
// Prints: 2
```
Using the ``eventEmitter.once()`` method, it is possible to register a listener that is called at most once for a particular event. Once the event is emitted, the listener is unregistered and then called.
```js
const myEmitter = new MyEmitter();
let m = 0;
myEmitter.once('event', () => {
  console.log(++m);
});
myEmitter.emit('event');
// Prints: 1
myEmitter.emit('event');
// Ignored
```

## Error events
When an error occurs within an ``EventEmitter`` instance, the typical action is for an ``'error'`` event to be emitted. These are treated as special cases within Node.js.

If an ``EventEmitter`` does not have at least one listener registered for the ``'error'`` event, and an ``'error'`` event is emitted, the error is thrown, a stack trace is printed, and the Node.js process exits.
```js
const myEmitter = new MyEmitter();
myEmitter.emit('error', new Error('whoops!'));
// Throws and crashes Node.js
```
To guard against crashing the Node.js process the ``domain`` module can be used. (Note, however, that the ``domain`` module is deprecated.)

As a best practice, listeners should always be added for the ``'error'`` events.
```js
const myEmitter = new MyEmitter();
myEmitter.on('error', (err) => {
  console.error('whoops! there was an error');
});
myEmitter.emit('error', new Error('whoops!'));
// Prints: whoops! there was an error
```

It is possible to monitor ``'error'`` events without consuming the emitted error by installing a listener using the symbol ``events.errorMonitor``.
```js
const { EventEmitter, errorMonitor } = require('events');

const myEmitter = new EventEmitter();
myEmitter.on(errorMonitor, (err) => {
  MyMonitoringTool.log(err);
});
myEmitter.emit('error', new Error('whoops!'));
// Still throws and crashes Node.js
```

## Class: EventEmitter
The ``EventEmitter`` class is defined and exposed by the ``events`` module:
```js
const EventEmitter = require('events');
```
All ``EventEmitters`` emit the event ``'newListener'`` when new listeners are added and ``'removeListener'`` when existing listeners are removed.

#### Section
* Event: 'newListener'
* Event: 'removeListener'
* emitter.addListener(eventName, listener)
* emitter.emit(eventName[, ...args])
* emitter.eventNames()
* emitter.getMaxListeners()
* emitter.listenerCount(eventName)
* emitter.listeners(eventName)
* emitter.off(eventName, listener)
* emitter.on(eventName, listener)
* emitter.once(eventName, listener)
* emitter.prependListener(eventName, listener)
* emitter.prependOnceListener(eventName, listener)
* emitter.removeAllListeners([eventName])
* emitter.removeListener(eventName, listener)
* emitter.setMaxListeners(n)
* emitter.rawListeners(eventName)
* emitter[Symbol.for('nodejs.rejection')](err, eventName[, ...args])






