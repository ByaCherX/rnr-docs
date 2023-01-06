<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Prototypal inheritance</h1>

In programming, we often want to take something and extend it.

For instance, we have a user object with its properties and methods, and want to make admin and guest as slightly modified variants of it. We’d like to reuse what we have in user, not copy/reimplement its methods, just build a new object on top of it.

Prototypal inheritance is a language feature that helps in that.

### [[ Prototype ]]
In JavaScript, objects have a special hidden property `[[Prototype]]` (as named in the specification), that is either null or references another object. That object is called “a prototype

When we read a property from `object`, and it’s missing, JavaScript automatically takes it from the prototype. In programming, this is called “prototypal inheritance”. And soon we’ll study many examples of such inheritance, as well as cooler language features built upon it.

The property `[[Prototype]]` is internal and hidden, but there are many ways to set it.

One of them is to use the special name `__proto__`, like this:
```js
let animal = {eats: true};
let rabbit = {jumps: true};

rabbit.__proto__ = animal; // sets rabbit.[[Prototype]] = animal
```

> [!NOTE]
> #### __proto__ is a historical getter/setter for [[Prototype]]
>It’s a common mistake of novice developers not to know the difference between these two.
>
>Please note that `__proto__` is not the same as the internal `[[Prototype]]` property. It’s a getter/setter for `[[Prototype]]`. Later we’ll see situations where it matters, for >now let’s just keep it in mind, as we build our understanding of JavaScript language.
>
>The `__proto__` property is a bit outdated. It exists for historical reasons, modern JavaScript suggests that we should use ``Object.getPrototypeOf/Object.setPrototypeOf`` >functions instead that get/set the prototype. We’ll also cover these functions later.
>
>By the specification, `__proto__` must only be supported by browsers. In fact though, all environments including server-side support `__proto__`, so we’re quite safe using it.
>
>As the `__proto__` notation is a bit more intuitively obvious, we use it in the examples.

## F.prototype
Remember, new objects can be created with a constructor function, like `new F()`.

If `F.prototype` is an object, then the `new` operator uses it to set `[[Prototype]]` for the new object.

**example:**
```js
let animal = {eats: true};

function Rabbit(name) {
this.name = name;
}
Rabbit.prototype = animal;

let rabbit = new Rabbit("White Rabbit");  // rabbit.__proto__ == animal
alert( rabbit.eats ); // true
```

### …JavaScript itself does not ensure the right "constructor" value.
Yes, it exists in the default "prototype" for functions, but that’s all. What happens with it later – is totally on us.

In particular, if we replace the default prototype as a whole, then there will be no "constructor" in it.

**For instance:**
```js
function Rabbit() {}
Rabbit.prototype = {jumps: true /*constructor: Rabbit*/};

let rabbit = new Rabbit();
alert(rabbit.constructor === Rabbit); // false
```





