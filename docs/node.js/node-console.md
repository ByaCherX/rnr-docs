<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:left;">Node.js - Console</h1>

#### Stability: 2 - Stable
#### Source Code: lib/console.js

The console module provides a simple debugging console that is similar to the JavaScript console mechanism provided by web browsers.

The module exports two specific components:

* A `Console` class with methods such as `console.log()`, `console.error()` and `console.warn()` that can be used to write to any Node.js stream.
* A global `console` instance configured to write to process.stdout and process.stderr. The global `console` can be used without calling `require('console')`.

**Warning:** The global console object's methods are neither consistently synchronous like the browser APIs they resemble, nor are they consistently asynchronous like all other Node.js streams. See the note on process I/O for more information.

Example using the global `console`:
```js
console.log('hello world');
console.log('hello %s', 'world')
console.error(new Error('Whoops, something bad happened'));
console.warn('Danger ${name}! Danger!');
```

## Class: Console
The Console class can be used to create a simple logger with configurable output streams and can be accessed using either require('console').Console or console.Console (or their destructured counterparts):
```js
import {Console} from 'console';
```

#### sections
* new Console(options)
* console.assert(value[, ...message])
* console.clear()
* console.count([label])
* console.countReset([label])
* console.debug(data[, ...args])
* console.dir(obj[, options])
* console.dirxml(...data)
* console.error([data][, ...args])
* console.group([...label])
* console.groupCollapsed()
* console.groupEnd()
* console.info([data][, ...args])
* console.log([data][, ...args])
* console.table(tabularData[, properties])
* console.time([label])
* console.timeEnd([label])
* console.timeLog([label][, ...data])
* console.trace([message][, ...args])
* console.warn([data][, ...args])

### new Console(options)
#### Options
* stdout ``<stream.Writable>``
* stderr ``<stream.Writable>``
* ignoreErrors ``<boolean>`` Ignore errors when writing to the underlying streams. Default: true.
* colorMode ``<boolean> | <string>`` Set color support for this Console instance. Setting to true enables coloring while inspecting values. Setting to false disables coloring while inspecting values. Setting to 'auto' makes color support depend on the value of the isTTY property and the value returned by getColorDepth() on the respective stream. This option can not be used, if  inspectOptions.colors is set as well. Default: 'auto'.
* inspectOptions ``<Object>`` Specifies options that are passed along to util.inspect().
* groupIndentation ``<number>`` Set group indentation. Default: 2.

---

**More Detailed Docs -> https://nodejs.org/dist/latest-v16.x/docs/api/console.html#console**

























