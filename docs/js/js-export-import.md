<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Export and Import</h1>

## Export

The `export` statement is used when creating JavaScript modules to export live bindings to functions, objects, or primitive values from the module so they can be used by other programs with the import statement. The value of an imported binding is subject to change in the module that exports it. When a module updates the value of a binding that it exports, the update will be visible in its imported value.

Exported modules are in strict mode whether you declare them as such or not. The export statement cannot be used in embedded scripts.

### Syntax
There are two types of exports:
1. Named Exports (Zero or more exports per module)
2. Default Exports (One per module)

```js
// Exporting individual features
export let name1, name2, …, nameN; // also var, const
export let name1 = …, name2 = …, …, nameN; // also var, const
export function functionName(){...}
export class ClassName {...}

// Export list
export { name1, name2, …, nameN };

// Renaming exports
export { variable1 as name1, variable2 as name2, …, nameN };

// Exporting destructured assignments with renaming
export const { name1, name2: bar } = o;

// Default exports
export default expression;
export default function (…) { … } // also class, function*
export default function name1(…) { … } // also class, function*
export { name1 as default, … };

// Aggregating modules
export * from …; // does not set the default export
export * as name1 from …; // ECMAScript® 2O20
export { name1, name2, …, nameN } from …;
export { import1 as name1, import2 as name2, …, nameN } from …;
export { default, … } from …;
```

#### Re-exporting / Aggregating
It is also possible to "import/export" from different modules in a parent module so that they are available to import from that module. In other words, one can create a single module concentrating various exports from various modules.

```js
export { default as function1, function2 } from 'bar.js';

import { default as function1, function2 } from 'bar.js';
export { function1, function2 };

```

## Import
The static `import` statement is used to import read only live bindings which are exported by another module.

Imported modules are in strict mode whether you declare them as such or not. The `import` statement cannot be used in embedded scripts unless such script has a `type="module"`. Bindings imported are called live bindings because they are updated by the module that exported the binding.

There is also a function-like dynamic `import()`, which does not require scripts of `type="module"`.

Backward compatibility can be ensured using attribute `nomodule` on the `<script>` tag.

### Syntax
```js
import defaultExport from "module-name";
import * as name from "module-name";
import { export1 } from "module-name";
import { export1 as alias1 } from "module-name";
import { export1 , export2 } from "module-name";
import { export1 , export2 as alias2 , [...] } from "module-name";
import defaultExport, { export1 [ , [...] ] } from "module-name";
import defaultExport, * as name from "module-name";
import "module-name";
var promise = import("module-name");
```

### Description
The `name` parameter is the name of the "module object" which will be used as a kind of namespace to refer to the exports. The `export` parameters specify individual named exports, while the `import * as name` syntax imports all of them. Below are examples to clarify the syntax.

### Dynamic Imports
The standard import syntax is static and will always result in all code in the imported module being evaluated at load time. In situations where you wish to load a module conditionally or on demand, you can use a dynamic import instead. The following are some reasons why you might need to use dynamic import:
* When importing statically significantly slows the loading of your code and there is a low likelihood that you will need the code you are importing, or you will not need it until a later time.
* When importing statically significantly increases your program's memory usage and there is a low likelihood that you will need the code you are importing.
* When the module you are importing does not exist at load time
* When the import specifier string needs to be constructed dynamically. (Static import only supports static specifiers.)
* When the module being imported has side effects, and you do not want those side effects unless some condition is true. (It is recommended not to have any side effects in a module, but you sometimes cannot control this in your module dependencies.)

Use dynamic import only when necessary. The static form is preferable for loading initial dependencies, and can benefit more readily from static analysis tools and tree shaking.

To dynamically import a module, the `import` keyword may be called as a function. When used this way, it returns a promise.
```js
import('/modules/my-module.js')
  .then((module) => {
    // Do something with the module.
  });
```

### Examples

#### Standard Import
The code below shows how to import from a secondary module to assist in processing an AJAX JSON request.

**The module: file.js**
```js
function getJSON(url, callback) {
  let xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText)
  };
  xhr.open('GET', url, true);
  xhr.send();
}

export function getUsefulContents(url, callback) {
  getJSON(url, data => callback(JSON.parse(data)));
}
```

**The main program: main.js**
```js
import { getUsefulContents } from '/modules/file.js';

getUsefulContents('http://www.example.com',
    data => { doSomethingUseful(data); });
```

#### Dynamic Import
```js
const main = document.querySelector("main");
for (const link of document.querySelectorAll("nav > a")) {
  link.addEventListener("click", e => {
    e.preventDefault();

    import('/modules/my-module.js')
      .then(module => {
        module.loadPageInto(main);
      })
      .catch(err => {
        main.textContent = err.message;
      });
  });
}
```






