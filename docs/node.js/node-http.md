<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:left;">Node.js - HTTP</h1>

<t8s>Stability: 2 - Stable</t8s></br>
<t8s>Source Code: lib/events.js</t8s>

<t8s>Table of contents</t8s>

* Class: http.Agent
  - new Agent([options])
  - agent.createConnection(options[, callback])
  - agent.keepSocketAlive(socket)
  - agent.reuseSocket(socket, request)
  - agent.destroy()
  - agent.freeSockets
  - agent.getName(options)
  - agent.maxFreeSockets
  - agent.maxSockets
  - agent.maxTotalSockets
  - agent.requests
  - agent.sockets
* Class: http.ClientRequest
  - Event: 'connect'
  - Event: 'continue'
  - Event: 'information'
  - Event: 'response'
  - Event: 'socket'
  - Event: 'timeout'
  - Event: 'upgrade'
  - request.end([data[, encoding]][, callback])
  - request.destroy([error])
  - request.destroyed
  - request.flushHeaders()
  - request.getHeader(name)
  - request.getRawHeaderNames()
  - request.maxHeadersCount
  - request.path
  - request.method
  - request.host
  - request.protocol
  - request.removeHeader(name)
  - request.reusedSocket
  - request.setHeader(name, value)
  - request.setNoDelay([noDelay])
  - request.setSocketKeepAlive([enable][, initialDelay])
  - request.setTimeout(timeout[, callback])
  - request.socket
  - request.writableEnded
  - request.writableFinished
  - request.write(chunk[, encoding][, callback])
* Class: http.Server
  - Event: 'checkContinue'
  - Event: 'checkExpectation'
  - Event: 'clientError'
  - Event: 'close'
  - Event: 'connect'
  - Event: 'connection'
  - Event: 'request'
  - Event: 'upgrade'
  - server.close([callback])
  - server.headersTimeout
  - server.listen()
  - server.listening
  - server.maxHeadersCount
  - server.requestTimeout
  - server.setTimeout([msecs][, callback])
  - server.maxRequestsPerSocket
  - server.timeout
  - server.keepAliveTimeout
* Class: http.ServerResponse
  - Event: 'close'
  - Event: 'finish'
  - response.addTrailers(headers)
  - response.cork()
  - response.end([data[, encoding]][, callback])
  - response.flushHeaders()
  - response.getHeader(name)
  - response.getHeaderNames()
  - response.getHeaders()
  - response.hasHeader(name)
  - response.headersSent
  - response.removeHeader(name)
  - response.req
  - response.sendDate
  - response.setHeader(name, value)
  - response.setTimeout(msecs[, callback])
  - response.socket
  - response.statusCode
  - response.statusMessage
  - response.uncork()
  - response.writableEnded
  - response.writableFinished
  - response.write(chunk[, encoding][, callback])
  - response.writeContinue()
  - response.writeHead(statusCode[, statusMessage][, headers])
  - response.writeProcessing()
* Class: http.IncomingMessage
  - Event: 'close'
  - message.complete
  - message.destroy([error])
  - message.headers
  - message.httpVersion
  - message.method
  - message.rawHeaders
  - message.rawTrailers
  - message.setTimeout(msecs[, callback])
  - message.socket
  - message.statusCode
  - message.statusMessage
  - message.trailers
  - message.url
* Class: http.OutgoingMessage
  - Event: drain
  - Event: finish
  - Event: prefinish
  - outgoingMessage.addTrailers(headers)
  - outgoingMessage.connection
  - outgoingMessage.cork()
  - outgoingMessage.destroy([error])
  - outgoingMessage.end(chunk[, encoding][, callback])
  - outgoingMessage.flushHeaders()
  - outgoingMessage.getHeader(name)
  - outgoingMessage.getHeaderNames()
  - outgoingMessage.getHeaders()
  - outgoingMessage.hasHeader(name)
  - outgoingMessage.headersSent
  - outgoingMessage.pipe()
  - outgoingMessage.removeHeader()
  - outgoingMessage.setHeader(name, value)
  - outgoingMessage.setTimeout(msesc[, callback])
  - outgoingMessage.socket
  - outgoingMessage.uncork()
  - outgoingMessage.writableCorked
  - outgoingMessage.writableEnded
  - outgoingMessage.writableFinished
  - outgoingMessage.writableHighWaterMark
  - outgoingMessage.writableLength
  - outgoingMessage.writableObjectMode
  - outgoingMessage.write(chunk[, encoding][, callback])
* http.METHODS
* http.STATUS_CODES
* http.createServer([options][, requestListener])
* http.get(options[, callback])
* http.get(url[, options][, callback])
* http.globalAgent
* http.maxHeaderSize
* http.request(options[, callback])
* http.request(url[, options][, callback])
* http.validateHeaderName(name)
* http.validateHeaderValue(name, value)


> [!IMPORTANT]
> This document only covers certain topics. For more detailed documentation, see the [node.js official documentation](https://nodejs.org/dist/latest-v16.x/docs/api/).

## Class: http.Agent
An `Agent` is responsible for managing connection persistence and reuse for HTTP clients. It maintains a queue of pending requests for a given host and port, reusing a single socket connection for each until the queue is empty, at which time the socket is either destroyed or put into a pool where it is kept to be used again for requests to the same host and port. Whether it is destroyed or pooled depends on the `keepAlive` option.

Pooled connections have TCP Keep-Alive enabled for them, but servers may still close idle connections, in which case they will be removed from the pool and a new connection will be made when a new HTTP request is made for that host and port. Servers may also refuse to allow multiple requests over the same connection, in which case the connection will have to be remade for every request and cannot be pooled. The Agent will still make the requests to that server, but each one will occur over a new connection.

When a connection is closed by the client or the server, it is removed from the pool. Any unused sockets in the pool will be unrefed so as not to keep the Node.js process running when there are no outstanding requests. (see ``socket.unref()``).

It is good practice, to ``destroy()`` an Agent instance when it is no longer in use, because unused sockets consume OS resources.

Sockets are removed from an agent when the socket emits either a 'close' event or an 'agentRemove' event. When intending to keep one HTTP request open for a long time without keeping it in the agent, something like the following may be done:
```js
http.get(options, (res) => {
  // Do stuff
}).on('socket', (socket) => {
  socket.emit('agentRemove');
});
```
An agent may also be used for an individual request. By providing `{agent: false}` as an option to the `http.get()` or `http.request()` functions, a one-time use `Agent` with default options will be used for the client connection.

**``agent:false:``**
```js
http.get({
  hostname: 'localhost',
  port: 80,
  path: '/', 
  agent: false  // Create a new agent just for this one request
}, (res) => { 
  // Do stuff with response
});
```

### new Agent([options])
#### options < Object>
* ``keepAlive`` `<boolean>` Keep sockets around even when there are no outstanding requests, so they can be used for future requests without having to reestablish a TCP connection. Not to be confused with the `keep-alive` value of the Connection header. The `Connection: keep-alive` header is always sent when using an agent except when the `Connection` header is explicitly specified or when the keepAlive and maxSockets options are respectively set to false and `Infinity`, in which case `Connection: close` will be used. Default: false.

* ``keepAliveMsecs`` `<number>` When using the `keepAlive` option, specifies the initial delay for TCP Keep-Alive packets. Ignored when the `keepAlive` option is false or undefined. Default: 1000.

* ``maxSockets`` `<number>` Maximum number of sockets to allow per host. If the same host opens multiple concurrent connections, each request will use new socket until the `maxSockets` value is reached. If the host attempts to open more connections than `maxSockets`, the additional requests will enter into a pending request queue, and will enter active connection state when an existing connection terminates. This makes sure there are at most `maxSockets` active connections at any point in time, from a given host. Default: Infinity.

* ``maxTotalSockets`` `<number>` Maximum number of sockets allowed for all hosts in total. Each request will use a new socket until the maximum is reached. Default: Infinity.

* ``maxFreeSockets`` `<number>` Maximum number of sockets per host to leave open in a free state. Only relevant if `keepAlive` is set to true. Default: 256.

* ``scheduling`` `<string>` Scheduling strategy to apply when picking the next free socket to use. It can be 'fifo' or 'lifo'. The main difference between the two scheduling strategies is that 'lifo' selects the most recently used socket, while 'fifo' selects the least recently used socket. In case of a low rate of request per second, the 'lifo' scheduling will lower the risk of picking a socket that might have been closed by the server due to inactivity. In case of a high rate of request per second, the 'fifo' scheduling will maximize the number of open sockets, while the 'lifo' scheduling will keep it as low as possible. Default: 'lifo'.

* ``timeout`` `<number>` Socket timeout in milliseconds. This will set the timeout when the socket is created.

To configure any of them, a custom [http.Agent](https://nodejs.org/dist/latest-v16.x/docs/api/http.html#class-httpagent) instance must be created.
```js
const http = require('http');
const keepAliveAgent = new http.Agent({ keepAlive: true });
options.agent = keepAliveAgent;
http.request(options, onResponseCallback);
```





