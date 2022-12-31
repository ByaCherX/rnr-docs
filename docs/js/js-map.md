<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Map</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

## Description
The `Map` object holds key-value pairs and remembers the original insertion order of the keys. Any value (both objects and primitive values) may be used as either a key or a value.

A Map object iterates its elements in insertion order — a for...of loop returns an array of [key, value] for each iteration.

### Object vs. Maps
`Object` is similar to `Map`—both let you set keys to values, retrieve those values, delete keys, and detect whether something is stored at a key. For this reason (and because there were no built-in alternatives), Object has been used as Map historically.

| Type | Map | Object |
|------|-----|--------|
|Accidental Keys |A Map does not contain any keys by default. It only contains what is explicitly put into it.|An `Object` has a prototype, so it contains default keys that could collide with your own keys if you're not careful.|
|Key Types|A Map's keys can be any value (including functions, objects, or any primitive).|The keys of an Object must be either a String or a Symbol|
|Key Order|The keys in Map are ordered in a simple, straightforward way: A Map object iterates entries, keys, and values in the order of entry insertion.|Although the keys of an ordinary Object are ordered now, this was not always the case, and the order is complex. As a result, it's best not to rely on property order.|
|Size|The number of items in a Map is easily retrieved from its size property.|The number of items in an Object must be determined manually.|
|Iteration|A Map is an iterable, so it can be directly iterated.|`Object` does not implement an iteration protocol, and so objects are not directly iterable using the JavaScript for...of statement (by default).|
|Performance|Performs better in scenarios involving frequent additions and removals of key-value pairs.|Not optimized for frequent additions and removals of key-value pairs.|

## Constructor
* Map.clear()
* Map.delete()
* Map.set()
* Map.get()
* Map.has()
* Map.keys()
* Map.values()
* Map.entries()

### Map() constructor
The `Map()` creates *Map* objects.
```js
new Map()
new Map(iterable)
```

## Instance methods

### Map.clear()
The `clear()` method removes all elements from a `Map` object.
```js
clear()
// example
var myMap = new Map();
myMap.set('bar', 'baz');
myMap.size;       // 1

myMap.clear();

myMap.size;       // 0
myMap.has('bar')  // false
```

### Map.delete()
The `delete()` method removes the specified element from a `Map` object by key.
```js
delete(key)
//example
const map1 = new Map();
map1.set('bar', 'foo');

console.log(map1.delete('bar'));
// expected result: true
```

### Map.set()
The `set()` method adds or updates an element with a specified key and a value to a Map object.
```js
set(key, value)
// example
const map1 = new Map();
map1.set('bar', 'foo');

console.log(map1.get('bar'));   // output: "foo"
```

### Map.get()
The `get()` method returns a specified element from a `Map` object. If the value that is associated to the provided key is an object, then you will get a reference to that object and any change made to that object will effectively modify it inside the `Map` object.
```js
const map1 = new Map();
map1.set('bar', 'foo');

console.log(map1.get('bar'));
// expected output: "foo"
```

### Map.has()
The `has()` method returns a boolean indicating whether an element with the specified key exists or not.
```js
has(key)
// example
const map1 = new Map();
map1.set('bar', 'foo');

console.log(map1.has('bar'));   // output: true
console.log(map1.has('baz'));   // output: false
```

### Map.keys()
The `keys()` method returns a new *Iterator* object that contains the keys for each element in the `Map` object in insertion order.
```js
keys()
// example
const map1 = new Map();

map1.set('0', 'foo');
map1.set(1, 'bar');

const iterator1 = map1.keys();

console.log(iterator1.next().value);    // output: "0"
console.log(iterator1.next().value);    // output: 1
```

### Map.values()
The `values()` method returns a new *Iterator* object that contains the values for each element in the `Map` object in insertion order.
```js
values()
// example
const map1 = new Map();

map1.set('0', 'foo');
map1.set(1, 'bar');

const iterator1 = map1.values();

console.log(iterator1.next().value);    // output: "foo"
console.log(iterator1.next().value);    // output: "bar"
```

### Map.entries()
The `entries()` method returns a new Iterator object that contains the `[key, value]` pairs for each element in the `Map` object in insertion order. In this particular case, this iterator object is also an iterable, so the for-of loop can be used. When the protocol `[Symbol.iterator]` is used, it returns a function that, when invoked, returns this iterator itself.
```js
entries()
// example
const map1 = new Map();

map1.set('0', 'foo');
map1.set(1, 'bar');

const iterator1 = map1.entries();

console.log(iterator1.next().value);    // output: ["0", "foo"]
console.log(iterator1.next().value);    // output: [1, "bar"]
```

















