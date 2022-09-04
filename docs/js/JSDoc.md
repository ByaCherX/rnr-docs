<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">Getting started</h1>

JSDoc 3 is an API documentation generator for JavaScript, similar to Javadoc or phpDocumentor. You add documentation comments directly to your source code, right alongside the code itself. The JSDoc tool will scan your source code and generate an HTML documentation website for you.

JSDoc's purpose is to document the API of your JavaScript application or library. It is assumed that you will want to document things like modules, namespaces, classes, methods, method parameters, and so on.
```js
/**
 * Represents a book.
 * @constructor
 * @param {string} title - The title of the book.
 * @param {string} author - The author of the book.
 */
function Book(title, author) {
}
```

<h1 style="text-align:center">JSDoc References</h1>

## Types

### @type
You can reference types with the “@type” tag. The type can be:
1. Primitive, like string or number.
2. Declared in a TypeScript declaration, either global or imported.
3. Declared in a JSDoc @typedef tag.
```js
/** @type {string} */
var s;
 
/** @type {Window} */
var win;

/** @type {string | boolean} */
var sb;
```

### @param and @returns
@param uses the same type syntax as @type, but adds a parameter name. The parameter may also be declared optional by surrounding the name with square brackets:
```js
// Parameters may be declared in a variety of syntactic forms
/**
 * @param {string}  p1 - A string param.
 * @param {string=} p2 - An optional param (Google Closure syntax)
 * @param {string} [p3] - Another optional param (JSDoc syntax).
 * @param {string} [p4="test"] - An optional param with a default value
 * @returns {string} This is the result
 */
function stringsStringStrings(p1, p2, p3, p4) {
  // TODO
}
```

### @typedef, @callback and @param
You can define complex types with @typedef. Similar syntax works with @param.
```js
/**
 * @typedef {object} SpecialType - creates a new type named 'SpecialType'
 * @property {string} prop1 - a string property of SpecialType
 * @property {number} prop2 - a number property of SpecialType
 * @property {number=} prop3 - an optional number property of SpecialType
 * @prop {number} [prop4] - an optional number property of SpecialType
 * @prop {number} [prop5=42] - an optional number property of SpecialType with default
 */
 
/** @type {SpecialType} */
var specialTypeObject;
specialTypeObject.prop3;
```

### @template
You can declare type parameters with the @template tag. This lets you make functions, classes, or types that are generic:
```js
/**
 * @template T
 * @param {T} x - A generic parameter that flows through to the return type
 * @returns {T}
 */
function id(x) {
  return x;
}
 
const a = id("string");
const b = id(123);
const c = id({});
```


## Classes
Classes can be declared as ES6 classes.
```js
class C {
  /**
   * @param {number} data
   */
  constructor(data) {
    // property types can be inferred
    this.name = "foo";
 
    // or set explicitly
    /** @type {string | null} */
    this.title = null;
 
    // or simply annotated, if they're set elsewhere
    /** @type {number} */
    this.size;
 
    this.initialize(data); // Should error, initializer expects a string
  }
  /**
   * @param {string} s
   */
  initialize = function (s) {
    this.size = s.length;
  };
}
 
var c = new C(0);
 
// C should only be called with new, but
// because it is JavaScript, this is allowed and
// considered an 'any'.
var result = C(1);
```

### Property Modifiers
@public, @private, and @protected work exactly like ``public``, ``private``, and ``protected`` in TypeScript:
```js
// @ts-check
 
class Car {
  constructor() {
    /** @private */
    this.identifier = 100;
  }
 
  printIdentifier() {
    console.log(this.identifier);
  }
}
 
const c = new Car();
console.log(c.identifier); //err 'identifier' is private and only accessible within class 'Car'
```

### @readonly
The @readonly modifier ensures that a property is only ever written to during initialization.

### @override
@override works the same way as in TypeScript; use it on methods that override a method from a base class:
```js
export class C {
  m() { }
}
class D extends C {
  /** @override */
  m() { }
}
```

### @extends
When JavaScript classes extend a generic base class, there is no JavaScript syntax for passing a type argument. The @extends tag allows this:
```js
/**
 * @template T
 * @extends {Set<T>}
 */
class SortableSet extends Set {
  // ...
}
```

### @implements
In the same way, there is no JavaScript syntax for implementing a TypeScript interface. The @implements tag works just like in TypeScript:
```js
/** @implements {Print} */
class TextBook {
  print() {
    // TODO
  }
}
```

### @constructor
The compiler infers constructor functions based on this-property assignments, but you can make checking stricter and suggestions better if you add a @constructor.

### @this
The compiler can usually figure out the type of this when it has some context to work with. When it doesn’t, you can explicitly specify the type of this with @this:
```js
/**
 * @this {HTMLElement}
 * @param {*} e
 */
function callbackForLater(e) {
  this.clientHeight = parseInt(e); // should be fine!
}
```


## Documentation

### @deprecated
When a function, method, or property is deprecated you can let users know by marking it with a `/** @deprecated */` JSDoc comment. That information is surfaced in completion lists and as a suggestion diagnostic that editors can handle specially. In an editor like VS Code, deprecated values are typically displayed in a strike-through style like this.
```js
/** @deprecated */
const apiV1 = {};
const apiV2 = {};
```

### @see
@see lets you link to other names in your program:
```js
type Box<T> = { t: T }
/** @see Box for implementation details */
type Boxify<T> = { [K in keyof T]: Box<T> };
```

### @link
@link is like @see, except that it can be used inside other tags:
```js
type Box<T> = { t: T }
/** @returns A {@link Box} containing the parameter. */
function box<U>(u: U): Box<U> {
  return { t: u };
}
```


## Other

### @enum
The @enum tag allows you to create an object literal whose members are all of a specified type. Unlike most object literals in JavaScript, it does not allow other members. @enum is intended for compatibility with Google Closure’s @enum tag.
```js
/** @enum {number} */
const JSDocState = {
  BeginningOfLine: 0,
  SawAsterisk: 1,
  SavingComments: 2,
};
 
JSDocState.SawAsterisk;
```

### @author
You can specify the author of an item with @author:
```js
/**
 * Welcome to awesome.ts
 * @author Ian Awesome <i.am.awesome@example.com>
 */
```


<h1 style="text-align:center">Block Tags</h1>

* @abstract (synonyms: @virtual)
This member must be implemented (or overridden) by the inheritor.

* @access
Specify the access level of this member (private, package-private, public, or protected).
```js
function Thingy() {
    /** @access private | protected | public | package */
    var foo = 0;
    // same as...
    /** @private | @protected | @public | @package */
}
```

* @alias
Treat a member as if it had a different name.

* @async
Indicate that a function is asynchronous.

* @augments (synonyms: @extends)
Indicate that a symbol inherits from, and adds to, a parent symbol.

* @author
Identify the author of an item.

* @borrows
This object uses something from another object.

* @callback
Document a callback function.

* @class (synonyms: @constructor)
This function is intended to be called with the "new" keyword.

* @classdesc
Use the following text to describe the entire class.

* @constant (synonyms: @const)
Document an object as a constant.

* @constructs
This function member will be the constructor for the previous class.

* @copyright
Document some copyright information.

* @default (synonyms: @defaultvalue)
Document the default value.

* @deprecated
Document that this is no longer the preferred way.

* @description (synonyms: @desc)
Describe a symbol.

* @enum
Document a collection of related properties.

* @event
Document an event.

* @example
Provide an example of how to use a documented item.

* @exports
Identify the member that is exported by a JavaScript module.

* @external (synonyms: @host)
Identifies an external class, namespace, or module.

* @file (synonyms: @fileoverview, @overview)
Describe a file.

* @fires (synonyms: @emits)
Describe the events this method may fire.

* @function (synonyms: @func, @method)
Describe a function or method.

* @generator
Indicate that a function is a generator function.

* @global
Document a global object.

* @hideconstructor
Indicate that the constructor should not be displayed.

* @ignore
Omit a symbol from the documentation.

* @implements
This symbol implements an interface.

* @inheritdoc
Indicate that a symbol should inherit its parent's documentation.

* @inner
Document an inner object.

* @instance
Document an instance member.

* @interface
This symbol is an interface that others can implement.

* @kind
What kind of symbol is this?

* @lends
Document properties on an object literal as if they belonged to a symbol with a given name.

* @license
Identify the license that applies to this code.

* @listens
List the events that a symbol listens for.

* @member (synonyms: @var)
Document a member.

* @memberof
This symbol belongs to a parent symbol.

* @mixes
This object mixes in all the members from another object.

* @mixin
Document a mixin object.

* @module
Document a JavaScript module.

* @name
Document the name of an object.

* @namespace
Document a namespace object.

* @override
Indicate that a symbol overrides its parent.

* @package
This symbol is meant to be package-private.

* @param (synonyms: @arg, @argument)
Document the parameter to a function.

* @private
This symbol is meant to be private.

* @property (synonyms: @prop)
Document a property of an object.

* @protected
This symbol is meant to be protected.
* @public
This symbol is meant to be public.

* @readonly
This symbol is meant to be read-only.

* @requires
This file requires a JavaScript module.

* @returns (synonyms: @return)
Document the return value of a function.

* @see
Refer to some other documentation for more information.

* @since
When was this feature added?

* @static
Document a static member.

* @summary
A shorter version of the full description.

* @this
What does the 'this' keyword refer to here?

* @throws (synonyms: @exception)
Describe what errors could be thrown.

* @todo
Document tasks to be completed.

* @tutorial
Insert a link to an included tutorial file.

* @type
Document the type of an object.

* @typedef
Document a custom type.

* @variation
Distinguish different objects with the same name.

* @version
Documents the version number of an item.

* @yields (synonyms: @yield)
Document the value yielded by a generator function.



