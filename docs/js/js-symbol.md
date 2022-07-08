<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

## Description
`Symbol` is a built-in object whose constructor returns a `symbol` primitive — also called a Symbol value or just a Symbol — that’s guaranteed to be unique. Symbols are often used to add unique property keys to an object that won’t collide with keys any other code might add to the object, and which are hidden from any mechanisms other code will typically use to access the object. That enables a form of weak encapsulation, or a weak form of information hiding.

## Constructor

### Symbol() constructor
The `Symbol()` constructor returns a value of type symbol, but is incomplete as a constructor because it does not support the syntax "`new Symbol()`" and it is not intended to be subclassed. It may be used as the value of an *extends* clause of a *class* definition but a *super* call to it will cause an exception.
```js
Symbol()
Symbol(description)
let sym = new Symbol() // TypeError


// example
const symbol1 = Symbol();
const symbol2 = Symbol(42);
const symbol3 = Symbol('foo');
```

## Static Properties
* Symbol.asyncIterator
* Symbol.hasInstance
* Symbol.isConcatSpreadable
* Symbol.iterator
* Symbol.match
* Symbol.matchAll
* Symbol.replace
* Symbol.search
* Symbol.split
* Symbol.species
* Symbol.toPrimitive
* Symbol.toStringTag
* Symbol.unscopables

### Symbol.asyncIterator
The `Symbol.asyncIterator` well-known symbol specifies the default AsyncIterator for an object. If this property is set on an object, it is an async iterable and can be used in a for await...of loop.
```js
const myAsyncIterable = {
    async* [Symbol.asyncIterator]() {
        yield "hello";
        yield "async";
        yield "iteration!";
    }
};

(async () => {
    for await (const x of myAsyncIterable) {
        console.log(x);
        // expected output:
        //    "hello"
        //    "async"
        //    "iteration!"
    }
})();
```

### Symbol.hasInstance
The Symbol.hasInstance well-known symbol is used to determine if a constructor object recognizes an object as its instance. The instanceof operator's behavior can be customized by this symbol.

### Symbol.isConcatSpreadable
The Symbol.isConcatSpreadable well-known symbol is used to configure if an object should be flattened to its array elements when using the Array.prototype.concat() method.

### Symbol.iterator
The well-known Symbol.iterator symbol specifies the default iterator for an object. Used by for...of.

### Symbol.match
The Symbol.match well-known symbol specifies the matching of a regular expression against a string. This function is called by the String.prototype.match() method.

### Symbol.matchAll
The Symbol.matchAll well-known symbol returns an iterator, that yields matches of the regular expression against a string. This function is called by the String.prototype.matchAll() method.

### Symbol.replace
The Symbol.replace well-known symbol specifies the method that replaces matched substrings of a string. This function is called by the String.prototype.replace() method.

### Symbol.search
The Symbol.search well-known symbol specifies the method that returns the index within a string that matches the regular expression. This function is called by the String.prototype.search() method.

### Symbol.split
The Symbol.split well-known symbol specifies the method that splits a string at the indices that match a regular expression. This function is called by the String.prototype.split() method.

### Symbol.species
The well-known symbol Symbol.species specifies a function-valued property that the constructor function uses to create derived objects.

### Symbol.toPrimitive
The Symbol.toPrimitive is a symbol that specifies a function valued property that is called to convert an object to a corresponding primitive value.

### Symbol.toStringTag
The Symbol.toStringTag well-known symbol is a string valued property that is used in the creation of the default string description of an object. It is accessed internally by the Object.prototype.toString() method.

### Symbol.unscopables
The Symbol.unscopables well-known symbol is used to specify an object value of whose own and inherited property names are excluded from the with environment bindings of the associated object.

## Static Methods

### Symbol.for()
The `Symbol.for(key)` method searches for existing symbols in a runtime-wide symbol registry with the given key and returns it if found. Otherwise a new symbol gets created in the global symbol registry with this key.

### Symbol.keyFor(sym)
The Symbol.keyFor(sym) method retrieves a shared symbol key from the global symbol registry for the given symbol.

## Instane Methods

### Symbol.toString()
The toString() method returns a string representing the specified Symbol object.

### Symbol.valueOf()
The valueOf() method of Symbol returns the primitive value of a Symbol object as a Symbol data type.

### Symbol.prototype[]
The `[@@toPrimitive]()` method converts a Symbol object to a primitive value.


