<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:left;">Node.js - Process</h1>

<t8s>Stability: 2 - Stable</t8s></br>
<t8s>Source Code: lib/process.js</t8s>

<t8s>Table of contents</t8s>


* Class: Process
  - Process events
    - Event: 'beforeExit'
    - Event: 'disconnect'
    - Event: 'exit'
    - Event: 'message'
    - Event: 'multipleResolves'
    - Event: 'rejectionHandled'
    - Event: 'uncaughtException'
    - Event: 'uncaughtExceptionMonitor'
    - Event: 'unhandledRejection'
    - Event: 'warning'
    - Event: 'worker'
    - Signal events
  - process.abort()
  - process.allowedNodeEnvironmentFlags
  - process.arch
  - process.argv
  - process.argv0
  - process.channel
    - process.channel.ref()
    - process.channel.unref()
  - process.chdir(directory)
  - process.config
  - process.connected
  - process.cpuUsage([previousValue])
  - process.cwd()
  - process.debugPort
  - process.disconnect()
  - process.dlopen(module, filename[, flags])
  - process.emitWarning(warning[, options])
  - process.emitWarning(warning[, type[, code]][, ctor])
  - process.env
  - process.execArgv
  - process.execPath
  - process.exit([code])
  - process.exitCode
  - process.getActiveResourcesInfo()
  - process.getegid()
  - process.geteuid()
  - process.getgid()
  - process.getgroups()
  - process.getuid()
  - process.hasUncaughtExceptionCaptureCallback()
  - process.hrtime([time])
  - process.hrtime.bigint()
  - process.initgroups(user, extraGroup)
  - process.kill(pid[, signal])
  - process.memoryUsage()
  - process.memoryUsage.rss()
  - process.nextTick(callback[, ...args])
  - process.noDeprecation
  - process.pid
  - process.platform
  - process.ppid
  - process.release
  - process.report
    - process.report.compact
    - process.report.directory
    - process.report.filename
    - process.report.getReport([err])
    - process.report.reportOnFatalError
    - process.report.reportOnSignal
    - process.report.reportOnUncaughtException
    - process.report.signal
    - process.report.writeReport([filename][, err])
  - process.resourceUsage()
  - process.send(message[, sendHandle[, options]][, callback])
  - process.setegid(id)
  - process.seteuid(id)
  - process.setgid(id)
  - process.setgroups(groups)
  - process.setuid(id)
  - process.setSourceMapsEnabled(val)
  - process.setUncaughtExceptionCaptureCallback(fn)
  - process.stderr
  - process.stdin
  - process.stdout
  - process.throwDeprecation
  - process.title
  - process.traceDeprecation
  - process.umask(mask)
  - process.uptime()
  - process.version
  - process.versions
  - Exit codes

## Process
The `process` object provides information about, and control over, the current Node.js process. While it is available as a global, it is recommended to explicitly access it via require or import:

### Event: 'beforeExit'
The 'beforeExit' event is emitted when Node.js empties its event loop and has no additional work to schedule. Normally, the Node.js process will exit when there is no work scheduled, but a listener registered on the 'beforeExit' event can make asynchronous calls, and thereby cause the Node.js process to continue.

### Event: 'disconnect'
If the Node.js process is spawned with an IPC channel (see the Child Process and Cluster documentation), the 'disconnect' event will be emitted when the IPC channel is closed.

### Event: 'exit'
The 'exit' event is emitted when the Node.js process is about to exit as a result of either:

The `process.exit()` method being called explicitly;
* The Node.js event loop no longer having any additional work to perform.
* There is no way to prevent the exiting of the event loop at this point, and once all 'exit' listeners have finished running the Node.js process will terminate.

### Event: 'message'
* message `<Object>` | `<boolean>` | `<number>` | `<string>` | `<null>` a parsed JSON object or a serializable primitive value.
* sendHandle `<net.Server>` | `<net.Socket>` a net.Server or net.Socket object, or undefined.
If the Node.js process is spawned with an IPC channel (see the Child Process and Cluster documentation), the 'message' event is emitted whenever a message sent by a parent process using `childprocess.send()` is received by the child process.

### Event: 'multipleResolves'
* type `<string>` The resolution type. One of 'resolve' or 'reject'.
* promise `<Promise>` The promise that resolved or rejected more than once.
* value `<any>` The value with which the promise was either resolved or rejected after the original resolve.

The 'multipleResolves' event is emitted whenever a `Promise` has been either:

### Event: 'rejectionHandled'
* promise `<Promise>` The late handled promise.
The 'rejectionHandled' event is emitted whenever a Promise has been rejected and an error handler was attached to it (using `promise.catch()`, for example) later than one turn of the Node.js event loop.

The `Promise` object would have previously been emitted in an 'unhandledRejection' event, but during the course of processing gained a rejection handler.

### Event: 'uncaughtException'
* err `<Error>` The uncaught exception.
* origin `<string>` Indicates if the exception originates from an unhandled rejection or from an synchronous error. Can either be 'uncaughtException' or 'unhandledRejection'. The latter is used when in an exception happens in a Promise based async context (or if a Promise is rejected) and --unhandled-rejections flag set to strict or throw (which is the default) and the rejection is not handled, or when a rejection happens during the command line entry point's ES module static loading phase.

The 'uncaughtException' event is emitted when an uncaught JavaScript exception bubbles all the way back to the event loop. By default, Node.js handles such exceptions by printing the stack trace to stderr and exiting with code 1, overriding any previously set `process.exitCode`. Adding a handler for the 'uncaughtException' event overrides this default behavior. Alternatively, change the `process.exitCode` in the 'uncaughtException' handler which will result in the process exiting with the provided exit code. Otherwise, in the presence of such handler the process will exit with 0.

### Event: 'uncaughtExceptionMonitor'
err `<Error>` The uncaught exception.
...

### Event: 'unhandledRejection'
* reason `<Error>` | `<any>` The object with which the promise was rejected (typically an Error object).
* promise `<Promise>` The rejected promise.
The 'unhandledRejection' event is emitted whenever a `Promise` is rejected and no error handler is attached to the promise within a turn of the event loop. When programming with Promises, exceptions are encapsulated as "rejected promises". Rejections can be caught and handled using `promise.catch()` and are propagated through a `Promise` chain. The 'unhandledRejection' event is useful for detecting and keeping track of promises that were rejected whose rejections have not yet been handled.

### Event: 'warning'
The 'warning' event is emitted whenever Node.js emits a process warning.

### Event: 'worker'
* worker `<Worker>` The `<Worker>` that was created.
The 'worker' event is emitted after a new `<Worker>` thread has been created.

### Signal events
Signal events will be emitted when the Node.js process receives a signal. Please refer to `signal(7)` for a listing of standard POSIX signal names such as `'SIGINT'`, `'SIGHUP'`, etc.

Signals are not available on Worker threads.

The signal handler will receive the signal's name (`'SIGINT'`, `'SIGTERM'`, etc.) as the first argument.

The name of each event will be the uppercase common name for the signal (e.g. `'SIGINT'` for `SIGINT` signals).

> [!IMPORTANT]
> For more details visit the official documentation page. [Node.js Process](https://nodejs.org/dist/latest-v16.x/docs/api/process.html#process)





