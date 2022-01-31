<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">TS - Triple Slash Directives</h1>

Triple-slash directives are single-line comments containing a single XML tag. The contents of the comment are used as compiler directives.

Triple-slash directives are only valid at the top of their containing file. A triple-slash directive can only be preceded by single or multi-line comments, including other triple-slash directives. If they are encountered following a statement or a declaration they are treated as regular single-line comments, and hold no special meaning.

```ts
/// <reference path="..." />
```
The `/// <reference path="..." />` directive is the most common of this group. It serves as a declaration of dependency between files.

Triple-slash references instruct the compiler to include additional files in the compilation process.

They also serve as a method to order the output when using out or outFile. Files are emitted to the output file location in the same order as the input after preprocessing pass.

### Preprocessing input files
The compiler performs a preprocessing pass on input files to resolve all triple-slash reference directives. During this process, additional files are added to the compilation.

The process starts with a set of root files; these are the file names specified on the command-line or in the files list in the `tsconfig.json` file. These root files are preprocessed in the same order they are specified. Before a file is added to the list, all triple-slash references in it are processed, and their targets included. Triple-slash references are resolved in a depth-first manner, in the order they have been seen in the file.

A triple-slash reference path is resolved relative to the containing file, if a relative path is used.






























