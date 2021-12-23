<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Value Properties

### Infinity
The global property `Infinity` is a numeric value representing infinity.
```js
console.log(Infinity);   /* Infinity */
```

### NaN
The global `NaN` property is a value representing Not-A-Number.
```js
valueIsNaN(1);       // false
valueIsNaN(NaN);     // true
```

### Undefined
The global `undefined` property represents the primitive value *undefined*. It is one of JavaScript's primitive types.
```js
undefined
```

### globalThis
The global `globalThis` property contains the global this value, which is akin to the global object.
```js
function canMakeHTTPRequest() {
  return typeof globalThis.XMLHttpRequest === 'function';}

console.log(canMakeHTTPRequest());
// expected output (in a browser): true
```













