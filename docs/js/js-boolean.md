<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Boolean</h1>

## Description

The value passed as the first parameter is converted to a boolean value, if necessary. If the value is omitted or is `0`, `-0`, `null`, `false`, NaN, undefined, or the empty string (""), the object has an initial value of false. All other values, including any object, an empty array ([]), or the string "`false`", create an object with an initial value of `true`.

## Constructor

### Boolean() constructor
The `Boolean()` constructor is used to create Boolean objects.
```js
new Boolean()
new Boolean(value)

// example
const flag = new Boolean();

console.log(flag);  // output: false

// Creating Boolean object (false)
var bNoParam = new Boolean();
var bZero = new Boolean(0);
var bNull = new Boolean(null);
var bEmptyString = new Boolean('');
var bfalse = new Boolean(false);

// Creating Boolean object (true)
var btrue = new Boolean(true);
var btrueString = new Boolean('true');
var bfalseString = new Boolean('false');
var bSuLin = new Boolean('Su Lin');
var bArrayProto = new Boolean([]);
var bObjProto = new Boolean({});
```

## Instance methods

### Boolean.toString()
The `toString()` method returns a string representing the specified Boolean object.
```js
toString()

// example
const flag1 = new Boolean(true);
console.log(flag1.toString());    // output: "true"
```

### Boolean.valueOf()
The `valueOf()` method returns the primitive value of a Boolean object.
```js
valueOf()

// example
const x = new Boolean();
console.log(x.valueOf());    // output: false

const y = new Boolean('Mozilla');
console.log(y.valueOf());    // output: true
```

