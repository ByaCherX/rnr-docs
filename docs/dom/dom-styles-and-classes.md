<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

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

### Element style
The property elem.style is an object that corresponds to what’s written in the "style" attribute. Setting `elem.style.width="100px"` works the same as if we had in the attribute `style` a string `width:100px`.

For multi-word property the camelCase is used:
```css
background-color  => elem.style.backgroundColor
z-index           => elem.style.zIndex
border-left-width => elem.style.borderLeftWidth
```
For instance:
```css
document.body.style.backgroundColor = prompt('background color?', 'green');
```

### Mind the units
Don’t forget to add CSS units to values.

For instance, we should not set `elem.style.top` to `10`, but rather to `10px`. Otherwise it wouldn’t work:
```html
<body>
  <script>
    // doesn't work!
    document.body.style.margin = 20;
    alert(document.body.style.margin); // '' (empty string, the assignment is ignored)

    // now add the CSS unit (px) - and it works
    document.body.style.margin = '20px';
    alert(document.body.style.margin); // 20px

    alert(document.body.style.marginTop); // 20px
    alert(document.body.style.marginLeft); // 20px
  </script>
</body>
```
Please note: the browser “unpacks” the property `style.margin` in the last lines and infers `style.marginLeft` and `style.marginTop` from it.



















