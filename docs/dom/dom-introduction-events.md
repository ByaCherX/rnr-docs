<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">Introduction to Events</h1>

## Bubbling and capturing

This handler is assigned to `<div>`, but also runs if you click any nested tag like `<em>` or `<code>`:
```html
<div onclick="alert('The handler!')">
  <em>If you click on <code>EM</code>, the handler on <code>DIV</code> runs.</em>
</div>
```

### Bubbling
When an event happens on an element, it first runs the handlers on it, then on its parent, then all the way up on other ancestors.

Let’s say we have 3 nested elements `FORM > DIV > P` with a handler on each of them:
```html
<style>
  body * {
    margin: 10px;
    border: 1px solid blue;
  }
</style>

<form onclick="alert('form')">FORM
  <div onclick="alert('div')">DIV
    <p onclick="alert('p')">P</p>
  </div>
</form>
```
A click on the inner `<p>` first runs `onclick`:
1. On that `<p>`.
2. Then on the outer `<div>`.
3. Then on the outer `<form>`.
4. And so on upwards till the `document` object.

The process is called “bubbling”, because events “bubble” from the inner element up through parents like a bubble in the water.

### event.target
A handler on a parent element can always get the details about where it actually happened.

The most deeply nested element that caused the event is called a target element, accessible as `event.target`.

Note the differences from `this` (=`event.currentTarget`):
* `event.target` – is the “target” element that initiated the event, it doesn’t change through the bubbling process.
* `this` – is the “current” element, the one that has a currently running handler on it.

For instance, if we have a single handler `form.onclick`, then it can “catch” all clicks inside the form. No matter where the click happened, it bubbles up to `<form>` and runs the handler.

In `form.onclick` handler:

`this` (=`event.currentTarget`) is the `<form>` element, because the handler runs on it.
`event.target` is the actual element inside the form that was clicked.

### Stopping bubbling
A bubbling event goes from the target element straight up. Normally it goes upwards till `<html>`, and then to `document` object, and some events even reach `window`, calling all handlers on the path.

But any handler may decide that the event has been fully processed and stop the bubbling.

The method for it is `event.stopPropagation()`.

For instance, here `body.onclick` doesn’t work if you click on `<button>`:
```html
<body onclick="alert(`the bubbling doesn't reach here`)">
  <button onclick="event.stopPropagation()">Click me</button>
</body>
```

### Capturing
There’s another phase of event processing called “capturing”. It is rarely used in real code, but sometimes can be useful.

The standard DOM Events describes 3 phases of event propagation:
1. Capturing phase – the event goes down to the element.
2. Target phase – the event reached the target element.
3. Bubbling phase – the event bubbles up from the element.

Here’s the picture of a click on `<td>` inside a table, taken from the specification:
:::image type="content" source="../media/dom/dom-Bubbling-and-capturing.jpg" alt-text="dom-bubbling-and-capturing":::

That is: for a click on `<td>` the event first goes through the ancestors chain down to the element (capturing phase), then it reaches the target and triggers there (target phase), and then it goes up (bubbling phase), calling handlers on its way.

Before we only talked about bubbling, because the capturing phase is rarely used. Normally it is invisible to us.

Handlers added using `on<event>`-property or using HTML attributes or using two-argument `addEventListener(event, handler)` don’t know anything about capturing, they only run on the 2nd and 3rd phases.

To catch an event on the capturing phase, we need to set the handler `capture` option to `true`:
```js
elem.addEventListener(..., {capture: true})
// or, just "true" is an alias to {capture: true}
elem.addEventListener(..., true)
```
There are two possible values of the `capture` option:
* If it’s `false` (default), then the handler is set on the bubbling phase.
* If it’s `true`, then the handler is set on the capturing phase.

Note that while formally there are 3 phases, the 2nd phase (“target phase”: the event reached the element) is not handled separately: handlers on both capturing and bubbling phases trigger at that phase.

Let’s see both capturing and bubbling in action:
```html
<style>
  body * { margin: 10px; border: 1px solid blue; }
</style>

<form>FORM
  <div>DIV <p>P</p> </div>
</form>

<script>
  for(let elem of document.querySelectorAll('*')) {
    elem.addEventListener("click", e => alert(`Capturing: ${elem.tagName}`), true);
    elem.addEventListener("click", e => alert(`Bubbling: ${elem.tagName}`));
  }
</script>
```

## Event delegation
Capturing and bubbling allow us to implement one of the most powerful event handling patterns called event delegation.

The idea is that if we have a lot of elements handled in a similar way, then instead of assigning a handler to each of them – we put a single handler on their common ancestor.

In the handler we get `event.target` to see where the event actually happened and handle it.

Let’s see an example – the Ba-Gua diagram reflecting the ancient Chinese philosophy.

Instead of assign an `onclick` handler to each `<td>` (can be many) – we’ll setup the “catch-all” handler on `<table>` element.

It will use `event.target` to get the clicked element and highlight it.

The code:
```js
let selectedTd;

table.onclick = function(event) {
  let target = event.target; // where was the click?

  if (target.tagName != 'TD') return; // not on TD? Then we're not interested

  highlight(target); // highlight it
};

function highlight(td) {
  if (selectedTd) { // remove the existing highlight if any
    selectedTd.classList.remove('highlight');
  }
  selectedTd = td;
  selectedTd.classList.add('highlight'); // highlight the new td
}
```
Such a code doesn’t care how many cells there are in the table. We can add/remove <td> dynamically at any time and the highlighting will still work.

### Behavior: Counter
For instance, here the attribute `data-counter` adds a behavior: “increase value on click” to buttons:
```html
Counter: <input type="button" value="1" data-counter>
One more counter: <input type="button" value="2" data-counter>

<script>
  document.addEventListener('click', function(event) {

    if (event.target.dataset.counter != undefined) { // if the attribute exists...
      event.target.value++;
    }

  });
</script>
```

### Behavior: Toggler
One more example of behavior. A click on an element with the attribute `data-toggle-id` will show/hide the element with the given `id`:
```html
<button data-toggle-id="subscribe-mail">
  Show the subscription form
</button>

<form id="subscribe-mail" hidden>
  Your mail: <input type="email">
</form>

<script>
  document.addEventListener('click', function(event) {
    let id = event.target.dataset.toggleId;
    if (!id) return;

    let elem = document.getElementById(id);

    elem.hidden = !elem.hidden;
  });
</script>
```

## Browser default actions
Many events automatically lead to certain actions performed by the browser.

For instance:
* A click on a link – initiates navigation to its URL.
* A click on a form submit button – initiates its submission to the server.
* Pressing a mouse button over a text and moving it – selects the text.

If we handle an event in JavaScript, we may not want the corresponding browser action to happen, and want to implement another behavior instead.

### Preventing browser actions
There are two ways to tell the browser we don’t want it to act:

The main way is to use the `event` object. There’s a method `event.preventDefault()`.
If the handler is assigned using `on<event>` (not by `addEventListener`), then returning `false` also works the same.

> [!IMPORTANT]
> Browser default actions section is described in  for more detailed document javascript.info/default-browser-action.

## Dispatching custom events
We can not only assign handlers, but also generate events from JavaScript.

Custom events can be used to create “graphical components”. For instance, a root element of our own JS-based menu may trigger events telling what happens with the menu: `open` (menu open), `select` (an item is selected) and so on. Another code may listen for the events and observe what’s happening with the menu.

We can generate not only completely new events, that we invent for our own purposes, but also built-in ones, such as `click`, `mousedown` etc. That may be helpful for automated testing.

### Event constructor
Built-in event classes form a hierarchy, similar to DOM element classes. The root is the built-in Event class.

We can create `Event` objects like this:
```js
let event = new Event(type[, options]);
```
Arguments:
* *type* – event type, a string like `"click"` or our own like `"my-event"`.
* *options* – the object with two optional properties:
  - `bubbles: true/false` – if `true`, then the event bubbles.
  - `cancelable: true/false` – if `true`, then the “default action” may be prevented. Later we’ll see what it means for custom events.

By default both are false: `{bubbles: false, cancelable: false}`.

### dispatchEvent
After an event object is created, we should “run” it on an element using the call `elem.dispatchEvent(event)`.

Then handlers react on it as if it were a regular browser event. If the event was created with the `bubbles` flag, then it bubbles.

In the example below the `click` event is initiated in JavaScript. The handler works same way as if the button was clicked:
```html
<button id="elem" onclick="alert('Click!');">Autoclick</button>

<script>
  let event = new Event("click");
  elem.dispatchEvent(event);
</script>
```

### Bubbling example
We can create a bubbling event with the name `"hello"` and catch it on `document`.

All we need is to set `bubbles` to `true`:
```html
<h1 id="elem">Hello from the script!</h1>

<script>
  // catch on document...
  document.addEventListener("hello", function(event) { // (1)
    alert("Hello from " + event.target.tagName); // Hello from H1
  });

  // ...dispatch on elem!
  let event = new Event("hello", {bubbles: true}); // (2)
  elem.dispatchEvent(event);

  // the handler on document will activate and display the message.

</script>
```

### MouseEvent, keyboardEvent and others
Here’s a short list of classes for UI Events from the UI Event specification:
* UIEvent
* FocusEvent
* MouseEvent
* WheelEvent
* KeyboardEvent
* …

We should use them instead of `new Event` if we want to create such events. For instance, `new MouseEvent("click")`.

The right constructor allows to specify standard properties for that type of event.

Like `clientX/clientY` for a mouse event:
```js
let event = new MouseEvent("click", {
  bubbles: true,
  cancelable: true,
  clientX: 100,
  clientY: 100
});

alert(event.clientX); // 100
```
Technically, we can work around that by assigning directly `event.clientX=100` after creation. So that’s a matter of convenience and following the rules. Browser-generated events always have the right type.

### Custom events
For our own, completely new events types like `"hello"` we should use `new CustomEvent`. Technically CustomEvent is the same as `Event`, with one exception.

In the second argument (object) we can add an additional property `detail` for any custom information that we want to pass with the event.

For instance:
```html
<h1 id="elem">Hello for John!</h1>

<script>
  // additional details come with the event to the handler
  elem.addEventListener("hello", function(event) {
    alert(event.detail.name);
  });

  elem.dispatchEvent(new CustomEvent("hello", {
    detail: { name: "John" }
  }));
</script>
```












