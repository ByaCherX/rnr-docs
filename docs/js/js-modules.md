<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Modules</h1>

As our application grows bigger, we want to split it into multiple files, so called “modules”. A module may contain a class or a library of functions for a specific purpose.

For a long time, JavaScript existed without a language-level module syntax. That wasn’t a problem, because initially scripts were small and simple, so there was no need.

But eventually scripts became more and more complex, so the community invented a variety of ways to organize code into modules, special libraries to load modules on demand.

To name some (for historical reasons):
* AMD – one of the most ancient module systems, initially implemented by the library require.js.
* CommonJS – the module system created for Node.js server.
* UMD – one more module system, suggested as a universal one, compatible with AMD and CommonJS.

Now all these slowly become a part of history, but we still can find them in old scripts.

The language-level module system appeared in the standard in 2015, gradually evolved since then, and is now supported by all major browsers and in Node.js. So we’ll study the modern JavaScript modules from now on.

## What is module?
A module is just a file. One script is one module. As simple as that.

Modules can load each other and use special directives `export` and `import` to interchange functionality, call functions of one module from another one:

* `export` keyword labels variables and functions that should be accessible from outside the current module.
* `import` allows the import of functionality from other modules.

For instance, if we have a file sayHi.js exporting a function:
```js
// 📁 sayHi.js
export function sayHi(user) {
  alert(`Hello, ${user}!`);
}
```
…Then another file may import and use it:
```js
// 📁 main.js
import {sayHi} from './sayHi.js';

alert(sayHi); // function...
sayHi('John'); // Hello, John!
```

The `import` directive loads the module by path `./sayHi.js` relative to the current file, and assigns exported function sayHi to the corresponding variable.

Let’s run the example in-browser.

As modules support special keywords and features, we must tell the browser that a script should be treated as a module, by using the attribute `<script type="module">`.

## Core module features
What’s different in modules, compared to “regular” scripts?

There are core features, valid both for browser and server-side JavaScript.

### Module-level scope
Each module has its own top-level scope. In other words, top-level variables and functions from a module are not seen in other scripts.

In the example below, two scripts are imported, and hello.js tries to use user variable declared in user.js. It fails, because it’s a separate module (you’ll see the error in the console):
```js
// 📁 index.html
<!doctype html>
<script type="module" src="hello.js"></script>

// 📁 user.js
export let user = "Jhon";

// 📁 hello.js
import {user} from './user.js';

document.body.innerHTML = user; // John
```
In the browser, if we talk about HTML pages, independent top-level scope also exists for each `<script type="module">`.

### External scripts
External scripts that have type="module" are different in two aspects:
External scripts with the same src run only once:
```js
<!-- the script my.js is fetched and executed only once -->
<script type="module" src="my.js"></script>
<script type="module" src="my.js"></script>
```
External scripts that are fetched from another origin (e.g. another site) require CORS headers, as described in the chapter Fetch: Cross-Origin Requests. In other words, if a module script is fetched from another origin, the remote server must supply a header Access-Control-Allow-Origin allowing the fetch.

```js
<!-- another-site.com must supply Access-Control-Allow-Origin -->
<!-- otherwise, the script won't execute -->
<script type="module" src="http://another-site.com/their.js"></script>
```
That ensures better security by default.

## Build tools
In real-life, browser modules are rarely used in their “raw” form. Usually, we bundle them together with a special tool such as Webpack and deploy to the production server.

One of the benefits of using bundlers – they give more control over how modules are resolved, allowing bare modules and much more, like CSS/HTML modules.

Build tools do the following:

1. Take a “main” module, the one intended to be put in `<script type="module">` in HTML.
2. Analyze its dependencies: imports and then imports of imports etc.
3. Build a single file with all modules (or multiple files, that’s tunable), replacing native import calls with bundler functions, so that it works. “Special” module types like HTML/CSS modules are also supported.
4. In the process, other transformations and optimizations may be applied:

* Unreachable code removed.
* Unused exports removed (“tree-shaking”).
* Development-specific statements like console and debugger removed.
* Modern, bleeding-edge JavaScript syntax may be transformed to older one with similar functionality using Babel.
* The resulting file is minified (spaces removed, variables replaced with shorter names, etc).

If we use bundle tools, then as scripts are bundled together into a single file (or few files), `import/export` statements inside those scripts are replaced by special bundler functions. So the resulting “bundled” script does not contain any `import/export`, it doesn’t require `type="module"`, and we can put it into a regular script:

<h1 style="text-align:center">Export and Import</h1>

Export and import directives have several syntax variants.

In the previous article we saw a simple use, now let’s explore more examples.

### Export before declarations
We can label any declaration as exported by placing `export` before it, be it a variable, function or a class.

For instance, here all exports are valid:
```js
// export an array
export let months = ['Jan', 'Feb', 'Mar','Apr', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];

// export a constant
export const MODULES_BECAME_STANDARD_YEAR = 2015;

// export a class
export class User {
  constructor(name) {
    this.name = name;
  }
}
```

### Import *
Usually, we put a list of what to import in curly braces `import {...}`, like this:
```js
// 📁 main.js
import * as say from './say.js';

say.sayHi('John');
say.sayBye('John');
```

### Import "as"
We can also use `as` to import under different names.

For instance, let’s import `sayHi` into the local variable `hi` for brevity, and import `sayBye` as `bye`:
```js
// 📁 main.js
import {sayHi as hi, sayBye as bye} from './say.js';

hi('John'); // Hello, John!
bye('John'); // Bye, John!
```

### Export "as"
The similar syntax exists for `export`.

Let’s export functions as `hi` and `bye`:
```js
// 📁 say.js
...
export {sayHi as hi, sayBye as bye};
```

Now `hi` and `bye` are official names for outsiders, to be used in imports:
```js
// 📁 main.js
import * as say from './say.js';

say.hi('John'); // Hello, John!
say.bye('John'); // Bye, John!
```

### Export default
In practice, there are mainly two kinds of modules.

Modules that contain a library, pack of functions, like say.js above.
Modules that declare a single entity, e.g. a module user.js exports only class User.
Mostly, the second approach is preferred, so that every “thing” resides in its own module.

Naturally, that requires a lot of files, as everything wants its own module, but that’s not a problem at all. Actually, code navigation becomes easier if files are well-named and structured into folders.

Modules provide a special `export default` (“the default export”) syntax to make the “one thing per module” way look better.

Put `export default` before the entity to export:
```js
// 📁 user.js
export default class User { // just add "default"
  constructor(name) {
    this.name = name;
  }
}
```
…And then import it without curly braces:
```js
// 📁 main.js
import User from './user.js'; // not {User}, just User

new User('John');
```
Imports without curly braces look nicer. A common mistake when starting to use modules is to forget curly braces at all. So, remember, `import` needs curly braces for named exports and doesn’t need them for the default one.

### The "default" name
In some situations the `default` keyword is used to reference the default export.

For example, to export a function separately from its definition:
```js
function sayHi(user) {
  alert(`Hello, ${user}!`);
}

// same as if we added "export default" before the function
export {sayHi as default};
```
Or, another situation, let’s say a module `user.js` exports one main “default” thing, and a few named ones (rarely the case, but it happens):
```js
// 📁 user.js
export default class User {
  constructor(name) {
    this.name = name;
  }
}

export function sayHi(user) {
  alert(`Hello, ${user}!`);
}
```
Here’s how to import the default export along with a named one:
```js
// 📁 main.js
import {default as User, sayHi} from './user.js';

new User('John');
```
And, finally, if importing everything * as an object, then the `default` property is exactly the default export:
```js
// 📁 main.js
import * as user from './user.js';

let User = user.default; // the default export
new User('John');
```

### Re-export
“Re-export” syntax `export ... from ...` allows to import things and immediately export them (possibly under another name), like this:
```js
export {sayHi} from './say.js'; // re-export sayHi

export {default as User} from './user.js'; // re-export default
```

<h1 style="text-align:center">Dynamic Imports</h1>
Export and import statements that we covered in previous chapters are called “static”. The syntax is very simple and strict.

First, we can’t dynamically generate any parameters of `import`.

The module path must be a primitive string, can’t be a function call. This won’t work:
```js
import ... from getModuleName(); // Error, only from "string" is allowed
```
Second, we can’t import conditionally or at run-time !

That’s because `import/export` aim to provide a backbone for the code structure. That’s a good thing, as code structure can be analyzed, modules can be gathered and bundled into one file by special tools, unused exports can be removed (“tree-shaken”). That’s possible only because the structure of imports/exports is simple and fixed.

But how can we import a module dynamically, on-demand?

## The import() expression
The `import(module)` expression loads the module and returns a promise that resolves into a module object that contains all its exports. It can be called from any place in the code.

We can use it dynamically in any place of the code, for instance:
```js
let modulePath = prompt("Which module to load?");

import(modulePath)
  .then(obj => <module object>)
  .catch(err => <loading error, e.g. if no such module>)
```
Or, we could use `let module = await import(modulePath)` if inside an async function.

```js
// 📁 say.js
export function hi() {
  alert(`Hello`);
}

export function bye() {
  alert(`Bye`);
}
```
…Then dynamic import can be like this:
```js
let {hi, bye} = await import('./say.js');

hi();
bye();
```





