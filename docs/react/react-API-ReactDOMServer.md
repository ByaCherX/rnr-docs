<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">ReactDOMServer</h1>

The `ReactDOMServer` object enables you to render components to static markup. Typically, it’s used on a Node server:
```jsx
// ES modules 
import ReactDOMServer from 'react-dom/server';

// CommonJS
var ReactDOMServer = require('react-dom/server');
```

## Overview
The following methods can be used in both the server and browser environments:
* [renderToString()]()
* [renderToStaticMarkup()]()

These additional methods depend on a package (`stream`) that is **only available on the server, and won’t work in the browser**.
* [renderToNodeStream()]
* [renderToStaticNodeStream]()

## Reference

### renderToString()
```jsx
ReactDOMServer.renderToString(element)
```
Render a React element to its initial HTML. React will return an HTML string. You can use this method to generate HTML on the server and send the markup down on the initial request for faster page loads and to allow search engines to crawl your pages for SEO purposes.

If you call [ReactDOM.hydrate()]() on a node that already has this server-rendered markup, React will preserve it and only attach event handlers, allowing you to have a very performant first-load experience.

### renderToStaticMarkup()
```jsx
ReactDOMServer.renderToStaticMarkup(element)
```
Similar to [renderToString](), except this doesn’t create extra DOM attributes that React uses internally, such as `data-reactroot`. This is useful if you want to use React as a simple static page generator, as stripping away the extra attributes can save some bytes.

If you plan to use React on the client to make the markup interactive, do not use this method. Instead, use [renderToString]() on the server and [ReactDOM.hydrate()]() on the client.

### renderToNodeStream()
```jsx
ReactDOMServer.renderToNodeStream(element)
```
Render a React element to its initial HTML. Returns a [Readable stream](https://nodejs.org/api/stream.html#stream_readable_streams) that outputs an HTML string. The HTML output by this stream is exactly equal to what ReactDOMServer.renderToString would return. You can use this method to generate HTML on the server and send the markup down on the initial request for faster page loads and to allow search engines to crawl your pages for SEO purposes.

If you call ReactDOM.hydrate() on a node that already has this server-rendered markup, React will preserve it and only attach event handlers, allowing you to have a very performant first-load experience.

> [!NOTE]
> Server-only. This API is not available in the browser.</br></br>
> The stream returned from this method will return a byte stream encoded in utf-8. If you need a stream in another encoding, take a look at a project like iconv-lite, which provides transform streams for transcoding text.

