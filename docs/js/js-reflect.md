<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">Reflect</h1>
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Reflect</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

`Reflect` is a built-in object that simplifies creation of `Proxy`.

It was said previously that internal methods, such as `[[Get]]`, `[[Set]]` and others are specification-only, they can’t be called directly.

The `Reflect` object makes that somewhat possible. Its methods are minimal wrappers around the internal methods.

Here are examples of operations and `Reflect` calls that do the same:
| Operation |	Reflect call |	Internal method |
|----------|---------------|------------------|
| obj[prop] |	Reflect.get(obj, prop) |	[[Get]] |
| obj[prop] = value |	Reflect.set(obj, prop, value) |	[[Set]] |
| delete obj[prop] |	Reflect.deleteProperty(obj, prop) |	[[Delete]] |
| new F(value) |	Reflect.construct(F, value) |	[[Construct]] |

In particular, `Reflect` allows us to call operators (`new, delete…`) as functions (`Reflect.construct`, `Reflect.deleteProperty, …`). That’s an interesting capability, but here another thing is important.

So we can use `Reflect` to forward an operation to the original object.

In this example, both traps `get` and `set` transparently (as if they didn’t exist) forward reading/writing operations to the object, showing a message:
```js
let user = {
  name: "John",
};

user = new Proxy(user, {
  get(target, prop, receiver) {
    alert(`GET ${prop}`);
    return Reflect.get(target, prop, receiver); // (1)
  },
  set(target, prop, val, receiver) {
    alert(`SET ${prop}=${val}`);
    return Reflect.set(target, prop, val, receiver); // (2)
  }
});

let name = user.name; // shows "GET name"
user.name = "Pete"; // shows "SET name=Pete"
```
Here:
* `Reflect.get` reads an object property.
* `Reflect.set` writes an object property and returns `true` if successful, `false` otherwise.

That is, everything’s simple: if a trap wants to forward the call to the object, it’s enough to call `Reflect.<method>` with the same arguments.

In most cases we can do the same without `Reflect`, for instance, reading a property `Reflect.get(target, prop, receiver)` can be replaced by target[prop]. There are important nuances though.

### Proxying a getter
Let’s see an example that demonstrates why `Reflect.get` is better. And we’ll also see why get/set have the third argument `receiver`, that we didn’t use before.

We have an object `user` with `_name` property and a getter for it.

Here’s a proxy around it:
```js
let user = {
  _name: "Guest",
  get name() { return this._name; }
};

let userProxy = new Proxy(user, {
  get(target, prop, receiver) { return target[prop]; }
});

alert(userProxy.name); // Guest
```
The `get` trap is “transparent” here, it returns the original property, and doesn’t do anything else. That’s enough for our example.

Everything seems to be all right. But let’s make the example a little bit more complex.

After inheriting another object `admin` from `user`, we can observe the incorrect behavior:
```js
let user = {
  _name: "Guest",
  get name() { return this._name; }
};

let userProxy = new Proxy(user, {
  get(target, prop, receiver) { return target[prop]; // (*) target = user }
});

let admin = {
  __proto__: userProxy,
  _name: "Admin"
};

// Expected: Admin
alert(admin.name); // outputs: Guest (?!?)
```

> [!TIP]
> for more detailed documentation: https://javascript.info/proxy

Now `receiver` that keeps a reference to the correct `this` (that is `admin`), is passed to the getter using `Reflect.get` in the line `(*)`.

## Proxy limitations
Proxies provide a unique way to alter or tweak the behavior of the existing objects at the lowest level. Still, it’s not perfect. There are limitations.

### Built-in objects: Internal slots
Many built-in objects, for example `Map`, `Set`, `Date`, `Promise` and others make use of so-called “internal slots”.

These are like properties, but reserved for internal, specification-only purposes. For instance, `Map` stores items in the internal slot `[[MapData]]`. Built-in methods access them directly, not via `[[Get]]/[[Set]]` internal methods. So `Proxy` can’t intercept that.

Why care? They’re internal anyway!

Well, here’s the issue. After a built-in object like that gets proxied, the proxy doesn’t have these internal slots, so built-in methods will fail.

For example:
```js
let map = new Map();
let proxy = new Proxy(map, {});
proxy.set('test', 1); // Error
```

Internally, a `Map` stores all data in its `[[MapData]]` internal slot. The proxy doesn’t have such a slot. The built-in method `Map.prototype.set` method tries to access the internal property this.[[MapData]], but because `this=proxy`, can’t find it in `proxy` and just fails.

Fortunately, there’s a way to fix it:
```js
let map = new Map();

let proxy = new Proxy(map, {
  get(target, prop, receiver) {
    let value = Reflect.get(...arguments);
    return typeof value == 'function' ? value.bind(target) : value;
  }
});

proxy.set('test', 1);
alert(proxy.get('test')); // 1 (works!)
```
Now it works fine, because `get` trap binds function properties, such as `map.set`, to the target object (`map`) itself.

Unlike the previous example, the value of `this` inside `proxy.set(...)` will be not `proxy`, but the original `map`. So when the internal implementation of `set` tries to access `this.[[MapData]]` internal slot, it succeeds.

### Private fields
A similar thing happens with private class fields.

For example, `getName()` method accesses the private `#name` property and breaks after proxying:
```js
class User {
  #name = "Guest";
  getName() { return this.#name; }
}

let user = new User();
user = new Proxy(user, {});

alert(user.getName()); // Error
```
The reason is that private fields are implemented using internal slots. JavaScript does not use `[[Get]]/[[Set]]` when accessing them.

In the call `getName()` the value of `this` is the proxied `user`, and it doesn’t have the slot with private fields.

Once again, the solution with binding the method makes it work:
```js
class User {
  #name = "Guest";
  getName() { return this.#name; }
}

let user = new User();

user = new Proxy(user, {
  get(target, prop, receiver) {
    let value = Reflect.get(...arguments);
    return typeof value == 'function' ? value.bind(target) : value;
  }
});

alert(user.getName()); // Guest
```
That said, the solution has drawbacks, as explained previously: it exposes the original object to the method, potentially allowing it to be passed further and breaking other proxied functionality.

### Proxy != target
The proxy and the original object are different objects. That’s natural, right?

So if we use the original object as a key, and then proxy it, then the proxy can’t be found:
```js
let allUsers = new Set();

class User {
  constructor(name) {
    this.name = name;
    allUsers.add(this);
  }
}

let user = new User("John");
alert(allUsers.has(user)); // true

user = new Proxy(user, {});
alert(allUsers.has(user)); // false
```

## Revocable proxies
A revocable proxy is a proxy that can be disabled.

Let’s say we have a resource, and would like to close access to it any moment.

What we can do is to wrap it into a revocable proxy, without any traps. Such a proxy will forward operations to object, and we can disable it at any moment.

The syntax is:
```js
let {proxy, revoke} = Proxy.revocable(target, handler)
```
The call returns an object with the `proxy` and `revoke` function to disable it.

Here’s an example:
```js
let object = {
  data: "Valuable data"
};

let {proxy, revoke} = Proxy.revocable(object, {});

// pass the proxy somewhere instead of object...
alert(proxy.data); // Valuable data

// later in our code
revoke();

// the proxy isn't working any more (revoked)
alert(proxy.data); // Error
```

A call to `revoke()` removes all internal references to the target object from the proxy, so they are no longer connected.

Initially, revoke is separate from `proxy`, so that we can pass `proxy` around while leaving `revoke` in the current scope.

We can also bind `revoke` method to proxy by setting `proxy.revoke = revoke`.

Another option is to create a `WeakMap` that has `proxy` as the key and the corresponding `revoke` as the value, that allows to easily find `revoke` for a proxy:
```js
let revokes = new WeakMap();

let object = {
  data: "Valuable data"
};

let {proxy, revoke} = Proxy.revocable(object, {});

revokes.set(proxy, revoke);

// ..somewhere else in our code..
revoke = revokes.get(proxy);
revoke();

alert(proxy.data); // Error (revoked)
```




## Static methods

### Reflect.construct()
The static `Reflect.construct()` method acts like the *new* operator, but as a function. It is equivalent to calling new target(...args). It gives also the added option to specify a different prototype.
```js
Reflect.construct(target, argumentsList)
Reflect.construct(target, argumentsList, newTarget)

// example
function func1(a, b, c) {this.sum = a + b + c;}

const args = [1, 2, 3];
const object1 = new func1(...args);
const object2 = Reflect.construct(func1, args);

console.log(object2.sum);    // output: 6
console.log(object1.sum);    // output: 6
```

### Reflect.apply()
The static `Reflect.apply()` method calls a target function with arguments as specified.
```js
Reflect.apply(target, thisArgument, argumentsList)

// example
Reflect.apply(Math.floor, undefined, [1.75]);
// 1;

Reflect.apply(String.fromCharCode, undefined, [104, 101, 108, 108, 111])
// "hello"

Reflect.apply(RegExp.prototype.exec, /ab/, ['confabulation']).index
// 4

Reflect.apply(''.charAt, 'ponies', [3])
// "i"
```

### Reflect.defineProperty()
```js

```

### Reflect.deleteProperty()
```js

```

### Reflect.get()
```js

```

### Reflect.getOwnPropertyDescriptor()
```js

```

### Reflect.getPrototypeOf()
```js

```

### Reflect.set()
```js

```

### Reflect.setPrototypeOf()
```js

```

### Reflect.has()
```js

```

### Reflect.isExtensible()
```js

```

### Reflect.ownKeys()
```js

```

### Reflect.preventExtensions()
```js

```





















