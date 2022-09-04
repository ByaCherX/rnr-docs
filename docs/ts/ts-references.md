<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">TS - References</h1>

Project references are a new feature in TypeScript 3.0 that allow you to structure your TypeScript programs into smaller pieces.

By doing this, you can greatly improve build times, enforce logical separation between components, and organize your code in new and better ways.

We’re also introducing a new mode for tsc, the --build flag, that works hand in hand with project references to enable faster TypeScript builds.

``tsconfig.json`` files have a new top-level property, references. It’s an array of objects that specifies projects to reference:
```json
{
    "compilerOptions": {
        // The usual
    },
    "references": [
        { "path": "../src" }
    ]
}
```
The path property of each reference can point to a directory containing a ``tsconfig.json`` file, or to the config file itself (which may have any name).

* Importing modules from a referenced project will instead load its output declaration file (.d.ts)

* If the referenced project produces an outFile, the output file .d.ts file’s declarations will be visible in this project

* Build mode (see below) will automatically build the referenced project if needed

## Build Mode for TypeScript
A long-awaited feature is smart incremental builds for TypeScript projects. In 3.0 you can use the `--build` flag with tsc. This is effectively a new entry point for tsc that behaves more like a build orchestrator than a simple compiler.

There are also some flags specific to ``tsc --build``:
* **``--verbose``** : Prints out verbose logging to explain what’s going on (may be combined with any other flag)
* **``--dry``** : Shows what would be done but doesn’t actually build anything
* **``--clean``** : Deletes the outputs of the specified projects (may be combined with --dry)
* **``--force``** : Act as if all projects are out of date
* **``--watch``** : Watch mode (may not be combined with any flag except --verbose)












