<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">DOM Elements</h1>
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">React - DOM Elements</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

React implements a browser-independent DOM system for performance and cross-browser compatibility. We took the opportunity to clean up a few rough edges in browser DOM implementations.

In React, all DOM properties and attributes (including event handlers) should be camelCased. For example, the HTML attribute `tabindex` corresponds to the attribute `tabIndex` in React. The exception is `aria-*` and `data-*` attributes, which should be lowercased. For example, you can keep `aria-label` as `aria-label`.

## Differences In Attributes
There are a number of attributes that work differently between React and HTML:

### checked
The `checked` attribute is supported by `<input>` components of type `checkbox` or `radio`. You can use it to set whether the component is checked. This is useful for building controlled components. `defaultChecked` is the uncontrolled equivalent, which sets whether the component is checked when it is first mounted.

### className
To specify a CSS class, use the `className` attribute. This applies to all regular DOM and SVG elements like `<div>`, `<a>`, and others.

If you use React with Web Components (which is uncommon), use the class attribute instead.

### dangerouslySetInnerHTML
`dangerouslySetInnerHTML` is React’s replacement for using `innerHTML` in the browser DOM. In general, setting HTML from code is risky because it’s easy to inadvertently expose your users to a cross-site scripting (XSS) attack. So, you can set HTML directly from React, but you have to type out `dangerouslySetInnerHTML` and pass an object with a `__html` key, to remind yourself that it’s dangerous. For example:
```jsx
function createMarkup() {
  return {__html: 'First &middot; Second'}; }

function MyComponent() {
  return <div dangerouslySetInnerHTML={createMarkup()} />; }
```

### htmlFor
Since `for` is a reserved word in JavaScript, React elements use `htmlFor` instead.

### onChange
The `onChange` event behaves as you would expect it to: whenever a form field is changed, this event is fired. We intentionally do not use the existing browser behavior because `onChange` is a misnomer for its behavior and React relies on this event to handle user input in real time.

### selected
If you want to mark an `<option>` as selected, reference the value of that option in the `value` of its `<select>` instead. Check out “The select Tag” for detailed instructions.

### style
The `style` attribute accepts a JavaScript object with camelCased properties rather than a CSS string. This is consistent with the DOM `style` JavaScript property, is more efficient, and prevents XSS security holes. For example:
```jsx
const divStyle = {
  color: 'blue',
  backgroundImage: 'url(' + imgUrl + ')', };

function HelloWorldComponent() {
  return <div style={divStyle}>Hello World!</div>; }
```
React will automatically append a “px” suffix to certain numeric inline style properties. If you want to use units other than “px”, specify the value as a string with the desired unit. For example:
```jsx
// Result style: '10px'
<div style={{ height: 10 }}>
  Hello World!
</div>

// Result style: '10%'
<div style={{ height: '10%' }}>
  Hello World!
</div>
```




### suppressContentEditableWarning
### suppressHydrationWarning
### value
























