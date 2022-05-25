<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Description
Objects allow you to store keyed collections of values. That’s fine.

But quite often we find that we need an ordered collection, where we have a 1st, a 2nd, a 3rd element and so on. For example, we need that to store a list of something: users, goods, HTML elements etc.

It is not convenient to use an object here, because it provides no methods to manage the order of elements. We can’t insert a new property “between” the existing ones. Objects are just not meant for such use.

There exists a special data structure named Array, to store ordered collections.

### Array() constructor
The `Array()` constructor is used to create Array objects.
```js
// literal constructor
[element0, element1, ..., elementN]

// construct from elements
new Array(element0, element1, ..., elementN)

// construct from array length
new Array(arrayLength)
```

#### Example
```js
// Array literal notation
let fruits = ['apple','banana'];
console.log(fruits.length);    // 2
console.log(fruits[0]);        // "apple"

// Array a single parameter
let fruits = new Array(2);
console.log(fruits.length);    // 2
console.log(fruits[0]);        // undefined

// Array with multiple parameters
let fruits = new Array('apple', 'banana');
console.log(fruits.length);    // 2
console.log(fruits[0]);        // undefined
```


### Array
The JavaScript `Array` class is a global object that is used in the construction of arrays; which are high-level, list-like objects.

Arrays, prototipi çapraz geçiş ve mutasyon işlemlerini gerçekleştirme yöntemlerine sahip liste benzeri nesnelerdir. Ne bir JavaScript dizisinin uzunluğu ne de öğelerinin türleri sabit değildir. Bir dizinin uzunluğu herhangi bir zamanda değişebileceğinden ve veriler dizideki bitişik olmayan konumlarda saklanabileceğinden, JavaScript Arrays yoğun olması garanti edilmez; bu, programcının bunları nasıl kullanmayı seçtiğine bağlıdır. Genel olarak, bunlar uygun özelliklerdir; ancak bu özellikler özel kullanımınız için istenmiyorsa, yazılan dizileri kullanmayı düşünebilirsiniz.

#### Common operations

##### Create an Array
```js
let fruits = ['apple', 'banana']
console.log(fruits.length)      // 2
```

##### Access an Array item using the index position
```js
let first = fruits[0]
// apple

let last = fruits[fruits.length - 1]
// banana
```

##### loop over an Array
```js
fruits.forEach(function(item, index, array) {
    console.log(item, index)  // apple 0   // banana 1
})
```

##### Add an item to the end of an Array
```js
let newLength = fruits.push('Orange')
// final result:   ["Apple", "Banana", "Orange"]
```

##### Remove an item from the end of an Array
```js
let last = fruits.pop()    // remove Orange (from the end)
// final result:   ["Apple", "Banana"]
```

##### Remove an item from the beginning of an Array
```js
let first = fruits.shift() // remove Apple from the front
// final result:   ["Banana"]
```

##### Add an item to the beginning of an Array
```js
let newLength = fruits.unshift('Strawberry')    // add to the front
// final result:   ["Strawberry", "Banana"]
```

##### Find the index of an item in the Array
```js
fruits.push('Mango')
// final result:   ["Strawberry", "Banana", "Mango"]

let pos = fruits.indexOf('Banana')    // 1
```

##### Remove an item by index position
```js
let romovedItem = fruits.splice(pos, 1)   // remove index_1 (Banana)
// final result:   ["Strawberry", "Mango"]
```

##### Remove items from an index position
```js
let list = ['a', 'b', 'c', 'd']
console.log(list)    // ['a', 'b', 'c', 'd']

let pos = 1
let   n = 2

let removedItems = list.splice(pos, n)

console.log(list)
// ['a', 'd']

console.log(removedItems)
// ['b', 'c']
```

##### Copy an Array
```js
let shallowCopy = fruits.slice()    // ["Strawberry", "Mango"]
```

## Static methods

### Array.from()
The `Array.from()` static method creates a new, shallow-copied `Array` instance from an array-like or iterable object.
```js
// Arrow function
Array.from(arrayLike, (currentValue) => {...})
Array.from(arrayLike, (currentValue, index) => {...})
Array.from(arrayLike, (currentValue, index, array) => {...})

// Mapping function
Array.from(arrayLike, mapFn)
Array.from(arrayLike, mapFn, thisArg)

// Inline mapping function
Array.from(arrayLike, function mapFn(currentValue) {...})
Array.from(arrayLike, function mapFn(currentValue, index) {...})
Array.from(arrayLike, function mapFn(currentValue, index, array){...})
Array.from(arrayLike, function mapFn(currentValue, index, array) {...}, thisArg)
```

### Array.isArray()
The `Array.isArray()` method determines whether the passed value is an Array.
```js
Array.isArray(value)
```

## Instance properties

### Array.length
The `length` property of an object which is an instance of type `Array` sets or returns the number of elements in that array. The value is an unsigned, 32-bit integer that is always numerically greater than the highest index in the array.
```js
// example
const list = ['a', 'b', 'c', 'd']
console.log(list.length);    // output: 4
```

## Instance Methods

### Array.at()
The `at()` method takes an integer value and returns the item at that index, allowing for positive and negative integers. Negative integers count back from the last item in the array.
```js
at(index)
// example
const array1 = [5, 12, 8, 130, 44];
let index = 2;
console.log(`item returned is ${array1.at(index)}`);  // output 8

index = -2;
console.log(`item returned is ${array1.at(index)}`);  // output 130
```

### Array.concat()
The `concat()` method is used to merge two or more arrays. This method does not change the existing arrays, but instead returns a new array.
```js
concat()
concat(value0)
concat(value0, value1, ..., valueN)
// example
const array1 = ['a', 'b', 'c'];
const array2 = ['d', 'e', 'f'];
const array3 = array1.concat(array2);

console.log(array3);
// output: Array ["a","b","c","d","e","f"]
```

### Array.copyWithin()
The `copyWithin()` method shallow copies part of an array to another location in the same array and returns it without modifying its length.
```js
copyWithin(target)
copyWithin(target, start)
copyWithin(target, start, end)
```

### Array.entries()
The `entries()` method returns a new *Array Iterator* object that contains the key/value pairs for each index in the array.
```js
entries()
// example
const a = ['a', 'b', 'c'];
for (const [index, element] of a.entries())
   console.log(index, element);
// 0 'a'
// 1 'b'
// 2 'c'
```

### Array.every()
The `every()` method tests whether all elements in the array pass the test implemented by the provided function. It returns a Boolean value.
```js
// Arrow function
every((element) => {...})
every((element, index) => {...})
every((element, index, array) => {...})

// Callback function
every(callbackFn)
every(callbackFn, thisArg)

// Inline callback function
every(function callbackFn(element) {...})
every(function callbackFn(element, index) {...})
every(function callbackFn(element, index, array){...})
every(function callbackFn(element, index, array) {...}, thisArg)
```

### Array.fill()
The `fill()` method changes all elements in an array to a static value, from a start index (default 0) to an end index (default array.length). It returns the modified array.
```js
fill(value)
fill(value, start)
fill(value, start, end)
// example
const array1 = [1, 2, 3, 4];
console.log(array1.fill(0, 2, 4));
// expected output: [1, 2, 0, 0]
```

### Array.filter()
The `filter()` method creates a new array with all elements that pass the test implemented by the provided function.
```js
// Arrow function
filter((element) => {...})
filter((element, index) => {...})
filter((element, index, array) => {...})
// example
const words = ['spray', 'limit', 'elite', 'exuberant', 'destruction'];
const result = words.filter(word => word.length > 6);
console.log(result);
// expected output: Array ["exuberant", "destruction", "present"]
```

### Array.find()
The `find()` method returns the value of the first element in the provided array that satisfies the provided testing function. If no values satisfy the testing function, undefined is returned.
```js
// Arrow function
find((element) => {...})
find((element, index) => {...})
find((element, index, array) => {...})
```

### Array.findIndex()
The `findIndex()` method returns the index of the first element in the array that satisfies the provided testing function. Otherwise, it returns -1, indicating that no element passed the test.
```js
// Arrow function
findIndex((element) => {...})
findIndex((element, index) => {...})
findIndex((element, index, array) => {...})

// example
const array1 = [5, 12, 8, 130, 44];
const isLargeNumber = (element) => element > 13;
console.log(array1.findIndex(isLargeNumber));
// expected output: 3
```

### Array.forEach()
The `forEach()` method executes a provided function once for each array element.
```js
// Arrow function
forEach((element) => {...})
forEach((element, index) => {...})
forEach((element, index, array) => {...})

// Callback function
forEach(callbackFn)
forEach(callbackFn, thisArg)
```

### Array.includes()
The `includes()` method determines whether an array includes a certain value among its entries, returning *true* or *false* as appropriate.
```js
includes(searchElement)
includes(searchElement, fromIndex)
// example
const array1 = [1,2,3];
console.log(array.includes(2));   // true
```

### Array.indexOf()
The `indexOf()` method returns the first index at which a given element can be found in the array, or -1 if it is not present.
```js
indexOf(searchElement)
indexOf(searchElement, fromIndex)
// example
const beasts = ['ant', 'bison', 'camel', 'duck', 'bison'];
console.log(beasts.indexOf('bison'));       // expected output: 1

// start from index 2
console.log(beasts.indexOf('bison', 2));    // expected output: 4
```

### Array.join()
The `join()` method creates and returns a new string by concatenating all of the elements in an array (or an array-like object), separated by commas or a specified separator string. If the array has only one item, then that item will be returned without using the separator.
```js
join()
join(separator)
// example
const elements = ['Fire', 'Air', 'Water'];
console.log(elements.join());      // expected output: "Fire,Air,Water"
console.log(elements.join(''));    // expected output: "FireAirWater"
console.log(elements.join('-'));   // expected output: "Fire-Air-Water"
```

### Array.keys()
The `keys()` method returns a new Array Iterator object that contains the keys for each index in the array.
```js
keys()
```

### Array.lastIndexOf()
The `lastIndexOf()` method returns the last index at which a given element can be found in the array, or -1 if it is not present. The array is searched backwards, starting at `fromIndex`.
```js
lastIndexOf(searchElement)
lastIndexOf(searchElement, fromIndex)
// example
const animals = ['Dodo', 'Tiger', 'Penguin', 'Dodox'];
console.log(animals.lastIndexOf('Dodox'));   // expected output: 3
console.log(animals.lastIndexOf('Tiger'));   // expected output: 1
```

### Array.map()
The `map()` method creates a new array populated with the results of calling a provided function on every element in the calling array.
```js
// Arrow function
map((element) => {...})
map((element, index) => {...})
map((element, index, array) => {...})
// example
const array1 = [1, 4, 9, 16];
const map1 = array1.map(x => x * 2);
console.log(map1);
// expected output: Array [2, 8, 18, 32]
```

### Array.pop()
The `pop()` method removes the last element from an array and returns that element. This method changes the length of the array.
```js
pop()
// example
const plants = ['broccoli','cauliflower','cabbage','kale','tomato'];
console.log(plants.pop());
// expected output: "tomato"

console.log(plants);
// expected output: Array ["broccoli", "cauliflower", "cabbage", "kale"]
```

### Array.push()
The `push()` method adds one or more elements to the end of an array and returns the new length of the array.
```js
push(element0)
push(element0, element1)
push(element0, element1, ... , elementN)
// example
const array1 = [1,2,3,4];
array1.push(5);
console.log(array1);   // [1,2,3,4,5]

// Merging two arrays
let vegetables = ['parsnip', 'potato']
let moreVegs = ['celery', 'beetroot']
Array.prototype.push.apply(vegetables, moreVegs)
console.log(vegetables)  // ['parsnip', 'potato', 'celery', 'beetroot']
```

### Array.reduce()
The `reduce()` method executes a reducer function (that you provide) on each element of the array, resulting in a single output value.
```js
// Arrow function
...
// Reducer function
reduce(reducerFn)
reduce(reducerFn, initialValue)
```
More About this section: https://devdocs.io/javascript/global_objects/array/reduce

### Array.reduceRight()
The `reduceRight()` method applies a function against an accumulator and each value of the array (from right-to-left) to reduce it to a single value.
```js
// Arrow function 
...
// Callback function
reduceRight(callbackFn)
reduceRight(callbackFn, initialValue)
```

### Array.reverse()
The `reverse()` method reverses an array in place. The first array element becomes the last, and the last array element becomes the first.
```js
reverse()
// example
const array1 = ['one', 'two', 'three'];
const reversed = array1.reverse();
console.log(array1);
// expected output: ["three", "two", "one"]
```

### Array.shift()
The `shift()` method removes the first element from an array and returns that removed element. This method changes the length of the array.
```js
shift()
// example
const array1 = [1, 2, 3];
const firstElement = array1.shift();
console.log(array1);     // expected output: Array [2, 3]
```

### Array.unshift()
The `unshift()` method adds one or more elements to the beginning of an array and returns the new length of the array.
```js
unshift(element0)
unshift(element0, element1)
unshift(element0, element1, ... , elementN)
// example
const array1 = [1, 2, 3];
array1.unshift(8, 11);
console.log(array1);
// expected output: Array [8, 11, 1, 2, 3]
```

### Array.slice()
The `slice()` method returns a shallow copy of a portion of an array into a new array object selected from *start* to *end* (end not included) where *start* and *end* represent the index of items in that array. The original array will not be modified.
```js
slice()
slice(start)
slice(start, end)
// example
const array1 = [1,2,3,4,5];
console.log(array1.slice(2));  // output: ??..
```

### Array.some()
The `some()` method tests whether at least one element in the array passes the test implemented by the provided function. It returns true if, in the array, it finds an element for which the provided function returns true; otherwise it returns false. It doesn't modify the array.
```js
// Arrow function
some((element, index, array) => {...})

// Callback function
some(callbackFn)
some(callbackFn, thisArg)

// Inline callback function
some(function callbackFn(element, index, array){ ... })

// example 
const array = [1, 2, 3, 4, 5];
const even = (element) => element * 2 === 8;
console.log(array.some(even));
// expected output: true
```

### Array.sort() !-undefined-!
The `sort()` method sorts the elements of an array in place and returns the sorted array. The default sort order is ascending, built upon converting the elements into strings, then comparing their sequences of UTF-16 code units values.
```js
// Functionless
sort()

// Arrow function
sort((firstEl, secondEl) => { ... } )

// Compare function
sort(compareFn)

// Inline compare function
sort(function compareFn(firstEl, secondEl) { ... })
```

### Array.splice()
The `splice()` method changes the contents of an array by removing or replacing existing elements and/or adding new elements in place
```js
splice(start)
splice(start, deleteCount)
splice(start, deleteCount, item1)
splice(start, deleteCount, item1, itemN)

// example
const array1 = [0,1,2,3];
array1.splice(1, 0, 50);
console.log(array1)   // output: [0,50,1,2,3]
```

### Array.toLocaleString()
The `toLocaleString()` method returns a string representing the elements of the array. The elements are converted to Strings using their `toLocaleString` methods and these Strings are separated by a locale-specific String (such as a comma “,”).
```js
toLocaleString();
toLocaleString(locales);
toLocaleString(locales, options);

// example
var prices = ['&$',45,78,62,12];
prices.toLocaleString('en-US', { style: 'currency', currency: '$' });
```

### Array.toString()
The `toString()` method returns a string representing the specified array and its elements.
```js
toString()
// example
const array1 = [1, 2, 'a', '1a'];
console.log(array1.toString());
// expected output: "1,2,a,1a"
```

### Array.values()
The `values()` method returns a new *Array Iterator* object that contains the values for each index in the array.
```js
values()
// example
const array1 = ['a', 'b', 'c'];
const iterator = array1.values();
for (const value of iterator) {console.log(value);}
// output: "a"  "b"  "c"
```

