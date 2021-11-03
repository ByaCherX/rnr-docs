<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

We’ve been talking about type-checking, but we haven’t yet used our type-checker. Let’s get acquainted with our new friend `tsc`, the TypeScript compiler. First we’ll need to grab it via npm.
```npm
npm install -g typescript
```

##### Usage Tsc
```npm
npx tsc --version

npm tsc app.ts
```

In this case, there was very little for TypeScript to transform, so it looks identical to what we wrote. The compiler tries to emit clean readable code that looks like something a person would write. While that’s not always so easy, TypeScript indents consistently, is mindful of when our code spans across different lines of code, and tries to keep comments around.


