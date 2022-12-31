<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">TypeScript - JSX</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

*JSX* is an embeddable XML-like syntax. It is meant to be transformed into valid JavaScript, though the semantics of that transformation are implementation-specific. JSX rose to popularity with the *React* framework, but has since seen other implementations as well. TypeScript supports embedding, type checking, and compiling JSX directly to JavaScript.

## Basic usage
In order to use JSX you must do two things.
- Name your files with a `.tsx` extension
- Enable the `jsx` option

TypeScript ships with three JSX modes: preserve, react, and `react-native`. These modes only affect the emit stage - type checking is unaffected. The preserve mode will keep the JSX as part of the output to be further consumed by another transform step (e.g. Babel). Additionally the output will have a .jsx file extension. The react mode will emit React.createElement, does not need to go through a JSX transformation before use, and the output will have a .js file extension. The `react-native` mode is the equivalent of preserve in that it keeps all JSX, but the output will instead have a .js file extension.

## The as operator
Recall how to write a type assertion:
```js
const foo = <foo>bar;
```
This asserts the variable `bar` to have the type `foo`. Since TypeScript also uses angle brackets for type assertions, combining it with JSX’s syntax would introduce certain parsing difficulties. As a result, TypeScript disallows angle bracket type assertions in `.tsx` files.

Since the above syntax cannot be used in `.tsx` files, an alternate type assertion operator should be used: as. The example can easily be rewritten with the `as` operator.
```js
const foo = bar as foo;
```
The `as` operator is available in both `.ts` and `.tsx` files, and is identical in behavior to the angle-bracket type assertion style.
































