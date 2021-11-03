<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

JavaScript has a long history of different ways to handle modularizing code. TypeScript having been around since 2012, has implemented support for a lot of these formats, but over time the community and the JavaScript specification has converged on a format called ES Modules (or ES6 modules). You might know it as the `import/export` syntax.

ES Modules was added to the JavaScript spec in 2015, and by 2020 had broad support in most web browsers and JavaScript runtimes.

For focus, the handbook will cover both ES Modules and its popular pre-cursor CommonJS `module.exports =` syntax, and you can find information about the other module patterns in the reference section under Modules.

## Non-modules
Before we start, it’s important to understand what TypeScript considers a module. The JavaScript specification declares that any JavaScript files without an export or top-level await should be considered a script and not a module.

Inside a script file variables and types are declared to be in the shared global scope, and it’s assumed that you’ll either use the outFile compiler option to join multiple input files into one output file, or use multiple `<script>` tags in your HTML to load these files (in the correct order!).

If you have a file that doesn’t currently have any imports or exports, but you want to be treated as a module, add the line:
```ts
export {}
```

## Modules in TypeScript
There are three main things to consider when writing module-based code in TypeScript:
* **Syntax:** What syntax do I want to use to import and export things?
* **Module Resolution:** What is the relationship between module names (or paths) and files on disk?
* **Module Output Target:** What should my emitted JavaScript module look like?

### ES Module Syntax
A file can declare a main export via `export default`:
```ts
// @filename: hello.ts
export default function helloWorld() {
  console.log("Hello, world!");
}
/* imported via: */
import hello from "./hello.js";
hello();
```

In addition to the default export, you can have more than one export of variables and functions via the `export` by omitting `default`:
```ts
// @filename: maths.ts
export var pi = 3.14;
export let squareTwo = 1.41;
export const phi = 1.61;
 
export class RandomNumberGenerator {}
 
export function absolute(num: number) {
  if (num < 0) return num * -1;
  return num;
}
```
These can be used in another file via the `import` syntax:
```ts
import { pi, phi, absolute } from "./maths.js";
 
console.log(pi);
const absPhi = absolute(phi);
```

### Additional Import Syntax
An import can be renamed using a format like `import {old as new}`:
```ts
import { pi as π } from "./maths.js";
 
console.log(π);
```

### TypeScript Specific ES Module Syntax
Types can be exported and imported using the same syntax as JavaScript values:
```ts
// @filename: animal.ts
export type Cat = { breed: string; yearOfBirth: number };
 
export interface Dog {
  breeds: string[];
  yearOfBirth: number;
}
 
// @filename: app.ts
import { Cat, Dog } from "./animal.js";
type Animals = Cat | Dog;
```

### ES Module Syntax with CommonJS Behavior
TypeScript has ES Module syntax which directly correlates to a CommonJS and AMD `require`. Imports using ES Module are for most cases the same as the `require` from those environments, but this syntax ensures you have a 1 to 1 match in your TypeScript file with the CommonJS output:
```ts
import fs = require("fs");
const code = fs.readFileSync("hello.ts", "utf8");
```
Then these files can be imported via a `require` statement:
```ts
const maths = require("maths");
maths.pi;

const { squareTwo } = require("maths");
squareTwo;
```









