<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">TS - Config</h1>
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">TypeScript - Config</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

The presence of a `tsconfig.json` file in a directory indicates that the directory is the root of a TypeScript project. The `tsconfig.json` file specifies the root files and the compiler options required to compile the project.

JavaScript projects can use a jsconfig.json file instead, which acts almost the same but has some JavaScript-related compiler flags enabled by default.

> If you want a more detailed version of the TypeScript Config document, see TypeScript's own documentation site. (https://www.typescriptlang.org/tsconfig)

# Root Fields
* [files](#files)
* [extends](#extends)
* [include](#include)
* [exclude](#exclude)
* [references](#references)

## Files
Specifies an allowlist of files to include in the program. An error occurs if any of the files can’t be found.
```json
{
  "compilerOptions": {},
  "files": [
    "core.ts",
    "sys.ts",
    "types.ts",
    "scanner.ts",
    "parser.ts",
    "utilities.ts",
    "binder.ts",
    "checker.ts",
    "tsc.ts"
  ]
}
```

## Extends
The value of extends is a string which contains a path to another configuration file to inherit from. The path may use Node.js style resolution.

The configuration from the base file are loaded first, then overridden by those in the inheriting config file. All relative paths found in the configuration file will be resolved relative to the configuration file they originated in.

It’s worth noting that files, include and exclude from the inheriting config file overwrite those from the base config file, and that circularity between configuration files is not allowed.

Currently, the only top-level property that is excluded from inheritance is references.
```json
// configs/base.json
{
  "compilerOptions": {
    "noImplicitAny": true,
    "strictNullChecks": true
  }
}
// tsconfig.json
{
    "extends": "./configs/base",
    "files": ["main.ts", "supplemental.ts"]
}
```

## Include
Specifies an array of filenames or patterns to include in the program. These filenames are resolved relative to the directory containing the ``tsconfig.json`` file.
```json
{
  "include": ["src/**/*", "tests/**/*"]
}
```
``*`` matches zero or more characters (excluding directory separators)</br>
``?`` matches any one character (excluding directory separators)</br>
``**/`` matches any directory nested to any level</br>

## Exclude
Specifies an array of filenames or patterns that should be skipped when resolving include.

Important: exclude only changes which files are included as a result of the include setting. A file specified by exclude can still become part of your codebase due to an `import` statement in your code, a types inclusion, a ``/// <reference`` directive, or being specified in the files list.

It is not a mechanism that prevents a file from being included in the codebase - it simply changes what the include setting finds.

## References
Project references are a way to structure your TypeScript programs into smaller pieces. Using Project References can greatly improve build and editor interaction times, enforce logical separation between components, and organize your code in new and improved ways.

You can read more about how references works in the [Project References](https://www.typescriptlang.org/docs/handbook/project-references.html) section of the handbook

# Type Checking
* [allowUnreachableCode](https://www.typescriptlang.org/tsconfig)
* [allowUnusedLabels](https://www.typescriptlang.org/tsconfig)
* [alwaysStrict](https://www.typescriptlang.org/tsconfig)
* [exactOptionalPropertyTypes](https://www.typescriptlang.org/tsconfig)
* [noFallthroughCasesInSwitch](https://www.typescriptlang.org/tsconfig)
* [noImplicitAny](https://www.typescriptlang.org/tsconfig)
* [noImplicitOverride](https://www.typescriptlang.org/tsconfig)
* [noImplicitReturns](https://www.typescriptlang.org/tsconfig)
* [noImplicitThis](https://www.typescriptlang.org/tsconfig)
* [noPropertyAccessFromIndexSignature](https://www.typescriptlang.org/tsconfig)
* [noUncheckedIndexedAccess](https://www.typescriptlang.org/tsconfig)
* [noUnusedLocals](https://www.typescriptlang.org/tsconfig)
* [noUnusedParameters](https://www.typescriptlang.org/tsconfig)
* [strict](https://www.typescriptlang.org/tsconfig)
* [strictBindCallApply](https://www.typescriptlang.org/tsconfig)
* [strictFunctionTypes](https://www.typescriptlang.org/tsconfig)
* [strictNullChecks](https://www.typescriptlang.org/tsconfig)
* [strictPropertyInitialization](https://www.typescriptlang.org/tsconfig)
* [useUnknownInCatchVariables](https://www.typescriptlang.org/tsconfig)

# Modules
* [allowUmdGlobalAccess](https://www.typescriptlang.org/tsconfig)
* [baseUrl](https://www.typescriptlang.org/tsconfig)
* [module](https://www.typescriptlang.org/tsconfig)
* [moduleResolution](https://www.typescriptlang.org/tsconfig)
* [moduleSuffixes](https://www.typescriptlang.org/tsconfig)
* [noResolve](https://www.typescriptlang.org/tsconfig)
* [paths](https://www.typescriptlang.org/tsconfig)
* [resolveJsonModule](https://www.typescriptlang.org/tsconfig)
* [rootDir](https://www.typescriptlang.org/tsconfig)
* [rootDirs](https://www.typescriptlang.org/tsconfig)
* [typeRoots](https://www.typescriptlang.org/tsconfig)
* [types](https://www.typescriptlang.org/tsconfig)

# Emit
* [declaration](https://www.typescriptlang.org/tsconfig)
* [declarationDir](https://www.typescriptlang.org/tsconfig)
* [declarationMap](https://www.typescriptlang.org/tsconfig)
* [downlevelIteration](https://www.typescriptlang.org/tsconfig)
* [emitBOM](https://www.typescriptlang.org/tsconfig)
* [emitDeclarationOnly](https://www.typescriptlang.org/tsconfig)
* [importHelpers](https://www.typescriptlang.org/tsconfig)
* [importsNotUsedAsValues](https://www.typescriptlang.org/tsconfig)
* [inlineSourceMap](https://www.typescriptlang.org/tsconfig)
* [inlineSources](https://www.typescriptlang.org/tsconfig)
* [mapRoot](https://www.typescriptlang.org/tsconfig)
* [newLine](https://www.typescriptlang.org/tsconfig)
* [noEmit](https://www.typescriptlang.org/tsconfig)
* [noEmitHelpers](https://www.typescriptlang.org/tsconfig)
* [noEmitOnError](https://www.typescriptlang.org/tsconfig)
* [outDir](https://www.typescriptlang.org/tsconfig)
* [outFile](https://www.typescriptlang.org/tsconfig)
* [preserveConstEnums](https://www.typescriptlang.org/tsconfig)
* [preserveValueImports](https://www.typescriptlang.org/tsconfig)
* [removeComments](https://www.typescriptlang.org/tsconfig)
* [sourceMap](https://www.typescriptlang.org/tsconfig)
* [sourceRoot](https://www.typescriptlang.org/tsconfig)
* [stripInternal](https://www.typescriptlang.org/tsconfig)

# JavaScript Support
* [allowJs](https://www.typescriptlang.org/tsconfig)
* [checkJs](https://www.typescriptlang.org/tsconfig)
* [maxNodeModuleJsDepth](https://www.typescriptlang.org/tsconfig)

# Editor Support
* [disableSizeLimit](https://www.typescriptlang.org/tsconfig)
* [plugins](https://www.typescriptlang.org/tsconfig)

# Interop Constraints
* [allowSyntheticDefaultImports](https://www.typescriptlang.org/tsconfig)
* [esModuleInterop](https://www.typescriptlang.org/tsconfig)
* [forceConsistentCasingInFileNames](https://www.typescriptlang.org/tsconfig)
* [isolatedModules](https://www.typescriptlang.org/tsconfig)
* [andpreserveSymlinks](https://www.typescriptlang.org/tsconfig)

# Backwards Compatibility
* [charset](https://www.typescriptlang.org/tsconfig)
* [keyofStringsOnly](https://www.typescriptlang.org/tsconfig)
* [noImplicitUseStrict](https://www.typescriptlang.org/tsconfig)
* [noStrictGenericChecks](https://www.typescriptlang.org/tsconfig)
* [out](https://www.typescriptlang.org/tsconfig)
* [suppressExcessPropertyErrors](https://www.typescriptlang.org/tsconfig)
* [andsuppressImplicitAnyIndexErrors](https://www.typescriptlang.org/tsconfig)

# Language and Environment
* [emitDecoratorMetadata](https://www.typescriptlang.org/tsconfig)
* [experimentalDecorators](https://www.typescriptlang.org/tsconfig)
* [jsx](https://www.typescriptlang.org/tsconfig)
* [jsxFactory](https://www.typescriptlang.org/tsconfig)
* [jsxFragmentFactory](https://www.typescriptlang.org/tsconfig)
* [jsxImportSource](https://www.typescriptlang.org/tsconfig)
* [lib](https://www.typescriptlang.org/tsconfig)
* [moduleDetection](https://www.typescriptlang.org/tsconfig)
* [noLib](https://www.typescriptlang.org/tsconfig)
* [reactNamespace](https://www.typescriptlang.org/tsconfig)
* [target](https://www.typescriptlang.org/tsconfig)
* [useDefineForClassFields](https://www.typescriptlang.org/tsconfig)

# Compiler Diagnostics
* [diagnostics](https://www.typescriptlang.org/tsconfig)
* [explainFiles](https://www.typescriptlang.org/tsconfig)
* [extendedDiagnostics](https://www.typescriptlang.org/tsconfig)
* [generateCpuProfile](https://www.typescriptlang.org/tsconfig)
* [listEmittedFiles](https://www.typescriptlang.org/tsconfig)
* [listFiles](https://www.typescriptlang.org/tsconfig)
* [andtraceResolution](https://www.typescriptlang.org/tsconfig)

# Projects
* [composite](https://www.typescriptlang.org/tsconfig)
* [disableReferencedProjectLoad](https://www.typescriptlang.org/tsconfig)
* [disableSolutionSearching](https://www.typescriptlang.org/tsconfig)
* [disableSourceOfProjectReferenceRedirect](https://www.typescriptlang.org/tsconfig)
* [incremental](https://www.typescriptlang.org/tsconfig)
* [tsBuildInfoFile](https://www.typescriptlang.org/tsconfig)

# Output Formatting
* [noErrorTruncation](https://www.typescriptlang.org/tsconfig)
* [preserveWatchOutput](https://www.typescriptlang.org/tsconfig)
* [pretty](https://www.typescriptlang.org/tsconfig)

# Completeness
* [skipDefaultLibCheck](https://www.typescriptlang.org/tsconfig)
* [skipLibCheck](https://www.typescriptlang.org/tsconfig)

# Watch Options
* [assumeChangesOnlyAffectDirectDependencies](https://www.typescriptlang.org/tsconfig)


