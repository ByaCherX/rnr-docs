<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

<h1 style="text-align:center">Browser environment, specs</h1>
The JavaScript language was initially created for web browsers. Since then it has evolved and become a language with many uses and platforms.

A platform may be a browser, or a web-server or another host, even a “smart” coffee machine, if it can run JavaScript. Each of them provides platform-specific functionality. The JavaScript specification calls that a host environment.

A host environment provides own objects and functions additional to the language core. Web browsers give a means to control web pages. Node.js provides server-side features, and so on.

Here’s a bird’s-eye view of what we have when JavaScript runs in a web browser:
:::image type="content" source="../media/dom/browser-env.jpg" alt-text="DOM-Browser-environment":::

here’s a “root” object called `window`. It has two roles:
1. First, it is a global object for JavaScript code, as described in the chapter Global object.
2. Second, it represents the “browser window” and provides methods to control it.

For instance, here we use it as a global object:
```js
function sayHi() { alert("Hello"); }

// global functions are methods of the global object:
window.sayHi();
```

## DOM (Document Object Model)
Document Object Model, or DOM for short, represents all page content as objects that can be modified.

The `document` object is the main “entry point” to the page. We can change or create anything on the page using it.

For instance:
```js
// change the background color to red
document.body.style.background = "red";

// change it back after 1 second
setTimeout(() => document.body.style.background = "", 1000);
```
Here we used `document.body.style`, but there’s much, much more. Properties and methods are described in the specification: DOM Living Standard.

> [!IMPORTANT]
> The DOM specification explains the structure of a document and provides objects to manipulate it. There are non-browser instruments that use DOM too. </br></br> For instance, server-side scripts that download HTML pages and process them can also use DOM. They may support only a part of the specification though.

> [!IMPORTANT]
> There’s also a separate specification, [CSS Object Model (CSSOM)](https://www.w3.org/TR/cssom-1/) for CSS rules and stylesheets, that explains how they are represented as objects, and how to read and write them. </br></br> CSSOM is used together with DOM when we modify style rules for the document. In practice though, CSSOM is rarely required, because we rarely need to modify CSS rules from JavaScript (usually we just add/remove CSS classes, not modify their CSS rules), but that’s also possible.


## BOM (Browser Object Model)
The Browser Object Model (BOM) represents additional objects provided by the browser (host environment) for working with everything except the document.

For instance:
* The navigator object provides background information about the browser and the operating system. There are many properties, but the two most widely known are: navigator.userAgent – about the current browser, and `navigator.platform` – about the platform (can help to differ between Windows/Linux/Mac etc).
* The location object allows us to read the current URL and can redirect the browser to a new one.
Here’s how we can use the location object:

```js
alert(location.href); // shows current URL
if (confirm("Go to Wikipedia?")) {
  location.href = "https://wikipedia.org"; // redirect the browser to another URL
}
```

> [!IMPORTANT]
> BOM is the part of the general HTML specification. </br></br> Yes, you heard that right. The HTML spec at https://html.spec.whatwg.org is not only about the “HTML language” (tags, attributes), but also covers a bunch of objects, methods and browser-specific DOM extensions. That’s “HTML in broad terms”. Also, some parts have additional specs listed at https://spec.whatwg.org.























