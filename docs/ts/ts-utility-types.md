<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">TS - Utility Types</h1>

TypeScript provides several utility types to facilitate common type transformations. These utilities are available globally.

## Partial< Type>
Constructs a type with all properties of `Type` set to optional. This utility will return a type that represents all subsets of a given type.
```ts
interface Todo {
  title: string;
  description: string;
}

function updateTodo(todo: Todo, fieldsToUpdate: Partial<Todo>) {
  return { ...todo, ...fieldsToUpdate };
}

const todo1 = {
  title: "organize desk",
  description: "clear clutter",
};
 
const todo2 = updateTodo(todo1, {
  description: "throw out trash",
});
```

## Required< Type>
Constructs a type consisting of all properties of Type set to required. The opposite of Partial.
```ts
interface Props {
  a?: number;
  b?: string;
}
 
const obj: Props = { a: 5 };
 
const obj2: Required<Props> = { a: 5 };
```

## Readonly< Type>
Constructs a type with all properties of `Type` set to `readonly`, meaning the properties of the constructed type cannot be reassigned.
```ts
interface Todo {
  title: string;
}
 
const todo: Readonly<Todo> = {
  title: "Delete inactive users",
};
 
todo.title = "Hello";
```

## Record< Keys, Type>
Constructs an object type whose property keys are `Keys` and whose property values are `Type`. This utility can be used to map the properties of a type to another type.
```ts
interface CatInfo {
  age: number;
  breed: string;
}
 
type CatName = "miffy" | "boris" | "mordred";
 
const cats: Record<CatName, CatInfo> = {
  miffy: { age: 10, breed: "Persian" },
  boris: { age: 5, breed: "Maine Coon" },
  mordred: { age: 16, breed: "British Shorthair" },
};
 
cats.boris;
```

## Pick< Type, Keys>
Constructs a type by picking the set of properties `Keys` (string literal or union of string literals) from Type.
```ts
interface Todo {
  title: string;
  description: string;
  completed: boolean;
}
 
type TodoPreview = Pick<Todo, "title" | "completed">;
 
const todo: TodoPreview = {
  title: "Clean room",
  completed: false,
};
 
```

## Exclude< Type, ExcludedUnion>
Constructs a type by excluding from `Type` all union members that are assignable to `ExcludedUnion`.
```ts
type T0 = Exclude<"a" | "b" | "c", "a">;
type T1 = Exclude<"a" | "b" | "c", "a" | "b">;
type T2 = Exclude<string | number | (() => void), Function>;
```

## Extract< Type, Union>
Constructs a type by extracting from `Type` all union members that are assignable to `Union`.
```ts
type T0 = Extract<"a" | "b" | "c", "a" | "f">;
type T1 = Extract<string | number | (() => void), Function>;
```

## Parameters< Type>
Constructs a tuple type from the types used in the parameters of a function type Type.
```ts
declare function f1(arg: { a: number; b: string }): void;
 
type T0 = Parameters<() => string>;
type T1 = Parameters<(s: string) => void>;
type T2 = Parameters<<T>(arg: T) => T>;
type T3 = Parameters<typeof f1>;
type T4 = Parameters<any>;
type T5 = Parameters<never>;
type T6 = Parameters<string>;
type T7 = Parameters<Function>;
```

## ConstructorParameters< Type>
Constructs a tuple or array type from the types of a constructor function type. It produces a tuple type with all the parameter types (or the type `never` if `Type` is not a function).
```ts
type T0 = ConstructorParameters<ErrorConstructor>;
type T1 = ConstructorParameters<FunctionConstructor>;
type T2 = ConstructorParameters<RegExpConstructor>;
type T3 = ConstructorParameters<any>;
 
type T4 = ConstructorParameters<Function>;
```

## ReturnType< Type>
Constructs a type consisting of the return type of function Type.
```ts
declare function f1(): { a: number; b: string };
 
type T0 = ReturnType<() => string>;
type T1 = ReturnType<(s: string) => void>;
type T2 = ReturnType<<T>() => T>;
type T3 = ReturnType<<T extends U, U extends number[]>() => T>;
type T4 = ReturnType<typeof f1>;
type T5 = ReturnType<any>;
type T6 = ReturnType<never>;
type T7 = ReturnType<string>;
type T8 = ReturnType<Function>;
```

> [!IMPORTANT]
> for more detailed documentation -> https://devdocs.io/typescript/utility-types




