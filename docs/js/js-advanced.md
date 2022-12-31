<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

<h1 style="text-align:center">Java Script Advanced Documents</h1>

## JavaScript Fundamentals

### The modern mode, "use strict"
For a long time, JavaScript evolved without compatibility issues. New features were added to the language while old functionality didn’t change.

That had the benefit of never breaking existing code. But the downside was that any mistake or an imperfect decision made by JavaScript’s creators got stuck in the language forever.

This was the case until 2009 when ECMAScript 5 (ES5) appeared. It added new features to the language and modified some of the existing ones. To keep the old code working, most such modifications are off by default. You need to explicitly enable them with a special directive: "use strict".

### Variables
A variable is a “named storage” for data. We can use variables to store goodies, visitors, and other data.

To create a variable in JavaScript, use the `let` keyword.

The statement below creates (in other words: declares) a variable with the name “message”:
```js
let message;
```

#### Uppercase Constant
There is a widespread practice to use constants as aliases for difficult-to-remember values that are known prior to execution.

Such constants are named using capital letters and underscores.

For instance, let’s make constants for colors in so-called “web” (hexadecimal) format:
```js
const COLOR_RED = "#F00";
const COLOR_GREEN = "#0F0";
const COLOR_BLUE = "#00F";
const COLOR_ORANGE = "#FF7F00";

// ...when we need to pick a color
let color = COLOR_ORANGE;
alert(color); // #FF7F00
```

### Data Types
A value in JavaScript is always of a certain type. For example, a string or a number.

There are eight basic data types in JavaScript. Here, we’ll cover them in general and in the next chapters we’ll talk about each of them in detail.

**a few Data types and definition**
- **`number`** for numbers of any kind: integer or floating-point, integers are limited by ±(253-1).
- **`bigint`** is for integer numbers of arbitrary length.
- **`string`** for strings. A string may have zero or more characters, there’s no separate single-character type.
- **`boolean`** for true/false.
- **`null`** for unknown values – a standalone type that has a single value null.
- **`undefined`** for unassigned values – a standalone type that has a single value undefined.
- **`object`** for more complex data structures.
- **`symbol`** for unique identifiers.









