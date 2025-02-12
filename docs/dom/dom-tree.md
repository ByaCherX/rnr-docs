<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">DOM Tree</h1>

The backbone of an HTML document is tags.

According to the Document Object Model (DOM), every HTML tag is an object. Nested tags are “children” of the enclosing one. The text inside a tag is an object as well.

All these objects are accessible using JavaScript, and we can use them to modify the page.

For example, `document.body` is the object representing the `<body>` tag.

Running this code will make the `<body>` red for 3 seconds:
```js
document.body.style.background = 'red'; // make the background red

setTimeout(() => document.body.style.background = '', 3000); // return back
```
Here we used `style.background` to change the background color of `document.body`, but there are many other properties, such as:
* `innerHTML` – HTML contents of the node.
* `offsetWidth` – the node width (in pixels)
* …and so on.

Soon we’ll learn more ways to manipulate the DOM, but first we need to know about its structure.



































