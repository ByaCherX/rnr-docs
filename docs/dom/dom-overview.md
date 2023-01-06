<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Introduction the DOM</h1>

The **Document Object Model** (DOM) is the data representation of the objects that comprise the structure and content of a document on the web. This guide will introduce the DOM, look at how the DOM represents an HTML document in memory and how to use APIs to create web content and applications.

> [!IMPORTANT]
> Document Object Model (DOM) Docs -> https://dom.spec.whatwg.org/#interface-element

### What is the DOM ?
The Document Object Model (DOM) is a programming interface for web documents. It represents the page so that programs can change the document structure, style, and content. The DOM represents the document as nodes and objects; that way, programming languages can interact with the page.

A web page is a document that can be either displayed in the browser window or as the HTML source. In both cases, it is the same document but the Document Object Model (DOM) representation allows it to be manipulated. As an object-oriented representation of the web page, it can be modified with a scripting language such as JavaScript.

For example, the DOM specifies that the `querySelectorAll` method in this code snippet must return a list of all the <p> elements in the document:
```jsx
const paragraphs = document.querySelectorAll("p");
// paragraphs[0] is the first <p> element
// paragraphs[1] is the second <p> element, etc.
alert(paragraphs[0].nodeName);
```
All of the properties, methods, and events available for manipulating and creating web pages are organized into objects. For example, the `document` object that represents the document itself, any table objects that implement the HTMLTableElement DOM interface for accessing HTML `tables`, and so forth, are all objects.

The DOM is built using multiple APIs that work together. The core DOM defines the entities describing any document and the objects within it. This is expanded upon as needed by other APIs that add new features and capabilities to the DOM. For example, the HTML DOM API adds support for representing HTML documents to the core DOM, and the SVG API adds support for representing SVG documents.

### DOM and JavaScript
The previous short example, like nearly all examples, is JavaScript. That is to say, it is written in JavaScript, but uses the DOM to access the document and its elements. The DOM is not a programming language, but without it, the JavaScript language wouldn't have any model or notion of web pages, HTML documents, SVG documents, and their component parts. The document as a whole, the head, tables within the document, table headers, text within the table cells, and all other elements in a document are parts of the document object model for that document. They can all be accessed and manipulated using the DOM and a scripting language like JavaScript.

The DOM is not part of the JavaScript language, but is instead a Web API used to build websites. JavaScript can also be used in other contexts. For example, Node.js runs JavaScript programs on a computer, but provides a different set of APIs, and the DOM API is not a core part of the Node.js runtime.

The DOM was designed to be independent of any particular programming language, making the structural representation of the document available from a single, consistent API. Even if most web developers will only use the DOM through JavaScript, implementations of the DOM can be built for any language, as this Python example demonstrates:
```python
# Python DOM example
import xml.dom.minidom as m
doc = m.parse(r"C:\Projects\Py\chap1.xml")
doc.nodeName # DOM property of document object
p_list = doc.getElementsByTagName("para")
```

Here’s a picture of links that allow for travel between DOM nodes:
```markdown
             | document | 
                   ^
                   |
     | document.documentElement | < html >
                   ^
                   |
           | document.body | (if inside body)
___________________________________________
                   ^
                   |
               parentNode
                   ^
 previousSibling   |     nextSibling
        <---- | < DIV > | ---->
               childNodes
              /          \
             /            \
        firstChild     lastChild
```
### On top: documentElement and body
The topmost tree nodes are available directly as `document` properties:
* **< html> = document.documentElement**
The topmost document node is `document.documentElement`. That’s the DOM node of the `<html>` tag.
* **< body> = document.body**
Another widely used DOM node is the `<body>` element – `document.body`.
* **< head> = document.head**
The `<head>` tag is available as `document.head`.

### Accessing the DOM
You don't have to do anything special to begin using the DOM. You use the API directly in JavaScript from within what is called a script, a program run by a browser.

When you create a script, whether inline in a `<script>` element or included in the web page, you can immediately begin using the API for the *document* or *window* objects to manipulate the document itself, or any of the various elements in the web page (the descendant elements of the document). Your DOM programming may be something as simple as the following example, which displays a message on the console by using the *console.log()* function:
```jsx
<body onload="console.log('Welcome to my home page!');">
```
As it is generally not recommended to mix the structure of the page (written in HTML) and manipulation of the DOM (written in JavaScript), the JavaScript parts will be grouped together here, and separated from the HTML.

For example, the following function creates a new *`<h1>`* element, adds text to that element, and then adds it to the tree for the document:
```html
<html>
  <head>
    <script>
       // run this function when the document is loaded
       window.onload = function() {

         // create a couple of elements in an otherwise empty HTML page
         const heading = document.createElement("h1");
         const heading_text = document.createTextNode("Big Head!");
         heading.appendChild(heading_text);
         document.body.appendChild(heading);
      }
    </script>
  </head>
  <body>
  </body>
</html>
```

### Fundamental data types
This page tries to describe the various objects and types in simple terms. But there are a number of different data types being passed around the API that you should be aware of.

> [!NOTE]
> Because the vast majority of code that uses the DOM revolves around manipulating HTML documents, it's common to refer to the nodes in the DOM as elements, although strictly speaking not every node is an element.

The following table briefly describes these data types.

|Data type (Interface)  |Description  |
|------------------|---------|
|Document     |When a member returns an object of type document (e.g., the ownerDocument property of an element returns the document to which it belongs), this object is the root document object itself. The DOM document Reference chapter describes the document object.|
|Node     |Every object located within a document is a node of some kind. In an HTML document, an object can be an element node but also a text node or attribute node.|
|Element     |The element type is based on node. It refers to an element or a node of type element returned by a member of the DOM API. Rather than saying, for example, that the document.createElement() method returns an object reference to a node, we just say that this method returns the element that has just been created in the DOM. element objects implement the DOM Element interface and also the more basic Node interface, both of which are included together in this reference. In an HTML document, elements are further enhanced by the HTML DOM API's HTMLElement interface as well as other interfaces describing capabilities of specific kinds of elements (for instance, HTMLTableElement for <table> elements).|
|NodeList     |A nodeList is an array of elements, like the kind that is returned by the method document.querySelectorAll(). Items in a nodeList are accessed by index in either of two ways ( `list.item(1) list[1]` )|
|Attr     |When an attribute is returned by a member (e.g., by the createAttribute() method), it is an object reference that exposes a special (albeit small) interface for attributes. Attributes are nodes in the DOM just like elements are, though you may rarely use them as such.|
|NamedNodeMap     |A namedNodeMap is like an array, but the items are accessed by name or index, though this latter case is merely a convenience for enumeration, as they are in no particular order in the list. A namedNodeMap has an item() method for this purpose, and you can also add and remove items from a `namedNodeMap`.|

### DOM Interfaces
This guide is about the objects and the actual things you can use to manipulate the DOM hierarchy. There are many points where understanding how these work can be confusing. For example, the object representing the HTML `form` element gets its `name` property from the `HTMLFormElement` interface but its `className` property from the `HTMLElement` interface. In both cases, the property you want is in that form object.

But the relationship between objects and the interfaces that they implement in the DOM can be confusing, and so this section attempts to say a little something about the actual interfaces in the DOM specification and how they are made available.

#### Interfaces and objects
Many objects borrow from several different interfaces. The table object, for example, implements a specialized HTMLTableElement interface, which includes such methods as `createCaption` and `insertRow`. But since it's also an HTML element, `table` implements the `Element` interface described in the DOM Element Reference chapter. And finally, since an HTML element is also, as far as the DOM is concerned, a node in the tree of nodes that make up the object model for an HTML or XML page, the table object also implements the more basic `Node` interface, from which `Element` derives.

When you get a reference to a `table` object, as in the following example, you routinely use all three of these interfaces interchangeably on the object, perhaps without knowing it.
```js
const table = document.getElementById("table");
const tableAttrs = table.attributes; // Node/Element interface
for (let i = 0; i < tableAttrs.length; i++) {
  // HTMLTableElement interface: border attribute
  if(tableAttrs[i].nodeName.toLowerCase() == "border")
    table.border = "1";
}
// HTMLTableElement interface: summary attribute
table.summary = "note: increased border";
```

#### Core interfaces in the DOM
This section lists some of the most commonly-used interfaces in the DOM. The idea is not to describe what these APIs do here but to give you an idea of the sorts of methods and properties you will see very often as you use the DOM. These common APIs are used in the longer examples in the DOM Examples chapter at the end of this book.

The `document` and `window` objects are the objects whose interfaces you generally use most often in DOM programming. In simple terms, the window object represents something like the browser, and the `document` object is the root of the document itself. `Element` inherits from the generic Node interface, and together these two interfaces provide many of the methods and properties you use on individual elements. These elements may also have specific interfaces for dealing with the kind of data those elements hold, as in the `table` object example in the previous section.

The following is a brief list of common APIs in web and XML page scripting using the DOM.
* document.querySelector(selector)
* document.querySelectorAll(name)
* document.createElement(name)
* parentNode.appendChild(node)
* element.innerHTML
* element.style.left
* element.setAttribute()
* element.getAttribute()
* element.addEventListener()
* window.content
* GlobalEventHandlers/onload
* window.scrollTo()

<h1 style="text-align:center">Walking the DOM</h1>

The DOM allows us to do anything with elements and their contents, but first we need to reach the corresponding DOM object.

All operations on the DOM start with the `document` object. That’s the main “entry point” to DOM. From it we can access any node.

Here’s a picture of links that allow for travel between DOM nodes:

### documentElement and body
The topmost tree nodes are available directly as document properties:

* **`<html>`** = `document.documentElement`
The topmost document node is `document.documentElement`. That’s the DOM node of the `<html>` tag.
* **`<body>`** = `document.body`
Another widely used DOM node is the `<body>` element – `document.body`.
* **`<head>`** = `document.head`
The `<head>` tag is available as `document.head`.

## Searching: getElement*, querySelector*
DOM navigation properties are great when elements are close to each other. What if they are not? How to get an arbitrary element of the page?

There are additional searching methods for that.

### document.getElementById or just id
If an element has the `id` attribute, we can get the element using the method `document.getElementById(id)`, no matter where it is.

For instance:
```html
<div id="elem">
  <div id="elem-content">Element</div>
</div>

<script>
  // get the element
  let elem = document.getElementById('elem');

  // make its background red
  elem.style.background = 'red';
</script>
```

### querySelectorAll
By far, the most versatile method, `elem.querySelectorAll(css)` returns all elements inside `elem` matching the given CSS selector.

Here we look for all `<li>` elements that are last children:
```html
<ul>  <li>The</li><li>test</li>  </ul>
<ul>  <li>has</li><li>passed</li>  </ul>
<script>
  let elements = document.querySelectorAll('ul > li:last-child');

  for (let elem of elements) {
    console.log(elem.innerHTML); // "test", "passed"
  }
</script>
```

## Node properties: type, tag and contents
Let’s get a more in-depth look at DOM nodes.

In this chapter we’ll see more into what they are and learn their most used properties.

### DOM node classes
Different DOM nodes may have different properties. For instance, an element node corresponding to tag `<a>` has link-related properties, and the one corresponding to `<input>` has input-related properties and so on. Text nodes are not the same as element nodes. But there are also common properties and methods between all of them, because all classes of DOM nodes form a single hierarchy.

Each DOM node belongs to the corresponding built-in class.

The root of the hierarchy is EventTarget, that is inherited by Node, and other DOM nodes inherit from it.

Here’s the picture, explanations to follow:

:::image type="content" source="../media/dom/DOM-node-classes.jpg" alt-text="dom-node-classes":::

The classes are:
* EventTarget – is the root “abstract” class. Objects of that class are never created. It serves as a base, so that all DOM nodes support so-called “events”, we’ll study them later.

* Node – is also an “abstract” class, serving as a base for DOM nodes. It provides the core tree functionality: `parentNode`, `nextSibling`, `childNodes` and so on (they are getters). Objects of `Node` class are never created. But there are concrete node classes that inherit from it, namely: Text for text nodes, `Element` for element nodes and more exotic ones like `Comment` for comment nodes.

* Element – is a base class for DOM elements. It provides element-level navigation like `nextElementSibling`, children and searching methods like `getElementsByTagName`, querySelector. A browser supports not only HTML, but also XML and SVG. The `Element` class serves as a base for more specific classes: `SVGElement`, `XMLElement` and `HTMLElement`.

* HTMLElement – is finally the basic class for all HTML elements. It is inherited by concrete HTML elements:
  - HTMLInputElement – the class for `<input>` elements,
  - HTMLBodyElement – the class for `<body>` elements,
  - HTMLAnchorElement – the class for `<a>` elements,
  - …and so on.

## Modifying the document
DOM modification is the key to creating “live” pages.

Here we’ll see how to create new elements “on the fly” and modify the existing page content.

### Creating an element
To create DOM nodes, there are two methods:

* <span class="hltext">document.createElement(tag)</span>

Creates a new element node with the given tag:
```js
let div = document.createElement('div');
```

* <span class="hltext">document.createTextNode(text)</span>

Creates a new text node with the given text:
```js
let textNode = document.createTextNode('Here I am');
```

### Insertion methods
To make the `div` show up, we need to insert it somewhere into `document`. For instance, into `<body>` element, referenced by `document.body`.

There’s a special method `append` for that: `document.body.append(div)`.

```html
<style>
.alert {
  padding: 15px;
  border: 1px solid #d6e9c6;
  border-radius: 4px;
  color: #3c763d;
  background-color: #dff0d8;
}
</style>

<script>
  let div = document.createElement('div');
  div.className = "alert";
  div.innerHTML = "<strong>Hi there!</strong> You've read an important message.";

  document.body.append(div);
</script>
```
Here we called `append` on `document.body`, but we can call `append` method on any other element, to put another element into it. For instance, we can append something to `<div>` by calling `div.append(anotherElement)`.

Here are more insertion methods, they specify different places where to insert:
* `node.append(...nodes or strings)` – append nodes or strings at the end of `node`,
* `node.prepend(...nodes or strings)` – insert nodes or strings at the beginning of `node`,
* `node.before(...nodes or strings)` –- insert nodes or strings before `node`,
* `node.after(...nodes or strings)` –- insert nodes or strings after `node`,
* `node.replaceWith(...nodes or strings)` –- replaces `node` with the given nodes or strings.

### InsertAdjacentHTML/Text/Element
For that we can use another, pretty versatile method: `elem.insertAdjacentHTML(where, html)`.

* <span class="hltext">beforebegin</span>elem.insertAdjacentText(where, text)</span> – the same syntax, but a string of text is inserted “as text” instead of HTML,
* <span class="hltext">beforebegin</span>elem.insertAdjacentElement(where, elem)</span> – the same syntax, but inserts an element.

The first parameter is a code word, specifying where to insert relative to `elem`. Must be one of the following:

* <span class="hltext">beforebegin</span> – insert html immediately before elem,
* <span class="hltext">afterbegin</span> – insert html into elem, at the beginning,
* <span class="hltext">beforeend</span> – insert html into elem, at the end,
* <span class="hltext">afterend</span> – insert html immediately after elem.

For instance:
```html
<div id="div"></div>
<script>
  div.insertAdjacentHTML('beforebegin', '<p>Hello</p>');
  div.insertAdjacentHTML('afterend', '<p>Bye</p>');
</script>
```














