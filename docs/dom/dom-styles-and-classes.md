<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">DOM Styles and Classes</h1>

Before we get into JavaScript’s ways of dealing with styles and classes – here’s an important rule. Hopefully it’s obvious enough, but we still have to mention it.

There are generally two ways to style an element:
1. Create a class in CSS and add it: `<div class="...">`
2. Write properties directly into `style`: `<div style="...">.`

For example, `style` is acceptable if we calculate coordinates of an element dynamically and want to set them from JavaScript, like this:
```js
let top = /* complex calculations */;
let left = /* complex calculations */;

elem.style.left = left; // e.g '123px', calculated at run-time
elem.style.top = top; // e.g '456px'
```


























