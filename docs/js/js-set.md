<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Description
The `Set` object lets you store unique values of any type, whether primitive values or object references.

`Set` objects are collections of values. You can iterate through the elements of a set in insertion order. A value in the `Set` may only occur once; it is unique in the `Set`'s collection.

## Constructor
The `Set` lets you create `Set` objects that store unique values of any type, whether *primitive values* or object references.
```js
new Set()
new Set(iterable)
// example
let mySet = new Set()

mySet.add(1)           // Set [ 1 ]
mySet.add(5)           // Set [ 1, 5 ]
mySet.add(5)           // Set [ 1, 5 ]
mySet.add('some text') // Set [ 1, 5, 'some text' ]
```

## Instance methods
> this instance uses the same features of methods map.













