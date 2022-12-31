<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">TypeScript - Utility Types</h1>

TypeScript provides several utility types to facilitate common type transformations. These utilities are available globally.

## Awaited< Type>
This type is meant to model operations like `await` in `async` functions, or the `.then()` method on `Promises` - specifically, the way that they recursively unwrap Promises.
```ts
type A = Awaited<Promise<string>>;

type B = Awaited<Promise<Promise<number>>>;

type C = Awaited<boolean | Promise<number>>;
```

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
// Property 'b' is missing in type '{ a: number; }' but required in type 'Required<Props>'.
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
// Cannot assign to 'title' because it is a read-only property.
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
type T6 = Parameters<string>;    // err
type T7 = Parameters<Function>;  // err
```

## ConstructorParameters< Type>
Constructs a tuple or array type from the types of a constructor function type. It produces a tuple type with all the parameter types (or the type `never` if `Type` is not a function).
```ts
type T0 = ConstructorParameters<ErrorConstructor>;
type T1 = ConstructorParameters<FunctionConstructor>;
type T2 = ConstructorParameters<RegExpConstructor>;
type T3 = ConstructorParameters<any>;
 
type T4 = ConstructorParameters<Function>;  // err
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
type T7 = ReturnType<string>;    // err
type T8 = ReturnType<Function>;  // err
```

## InstanceType< Type>
Constructs a type consisting of the instance type of a constructor function in `Type`.
```ts
class C { x = 0;  y = 0; }
 
type T0 = InstanceType<typeof C>;
type T1 = InstanceType<any>;
type T2 = InstanceType<never>;
type T3 = InstanceType<string>;    // err
type T4 = InstanceType<Function>;  // err
```

## ThisParameterType< Type>
Extracts the type of the this parameter for a function type, or unknown if the function type has no `this` parameter.
```ts
function toHex(this: Number) {
  return this.toString(16);
}
 
function numberToString(n: ThisParameterType<typeof toHex>) {
  return toHex.apply(n);
}
```

## ThisType< Type>
This utility does not return a transformed type. Instead, it serves as a marker for a contextual `this` type. Note that the `noImplicitThis` flag must be enabled to use this utility.
```ts
type ObjectDescriptor<D, M> = {
  data?: D;
  methods?: M & ThisType<D & M>; // Type of 'this' in methods is D & M
};
 
function makeObject<D, M>(desc: ObjectDescriptor<D, M>): D & M {
  let data: object = desc.data || {};
  let methods: object = desc.methods || {};
  return { ...data, ...methods } as D & M;
}
 
let obj = makeObject({
  data: { x: 0, y: 0 },
  methods: {
    moveBy(dx: number, dy: number) {
      this.x += dx; // Strongly typed this
      this.y += dy; // Strongly typed this
    },
  },
});
 
obj.x = 10;
obj.y = 20;
obj.moveBy(5, 5);
```
In the example above, the methods object in the argument to makeObject has a contextual type that includes `ThisType<D & M>` and therefore the type of this in methods within the methods object is ``{ x: number, y: number } & { moveBy(dx: number, dy: number): number }``. Notice how the type of the methods property simultaneously is an inference target and a source for the this type in methods.

The `ThisType<T>` marker interface is simply an empty interface declared in lib.d.ts. Beyond being recognized in the contextual type of an object literal, the interface acts like any empty interface.






