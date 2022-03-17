<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">Document</h1>

The `Document` interface represents any web page loaded in the browser and serves as an entry point into the web page's content, which is the DOM tree.

The DOM tree includes elements such as ``<body>`` and ``<table>``, among many others. It provides functionality globally to the document, like how to obtain the page's URL and create new elements in the document.

| EventTarget | <---- | Node | <---- | Document |

The ``Document`` interface describes the common properties and methods for any kind of document. Depending on the document's type (e.g. HTML, XML, SVG, …), a larger API is available: HTML documents, served with the ``"text/html"`` content type, also implement the HTMLDocument interface, whereas XML and SVG documents implement the XMLDocument interface.

# Properties
-------------
This interface also inherits from the [Node](https://developer.mozilla.org/en-US/docs/Web/API/Node) and [EventTarget](https://developer.mozilla.org/en-US/docs/Web/API/EventTarget) interfaces.

* [Docuemnt.activeElement](https://developer.mozilla.org/en-US/docs/Web/API/Document/activeElement)
* [Document.body](https://developer.mozilla.org/en-US/docs/Web/API/Document/body)
* [Document.characterSet](https://developer.mozilla.org/en-US/docs/Web/API/Document/characterSet)
* [Document.childElementCount](https://developer.mozilla.org/en-US/docs/Web/API/Document/childElementCount)
* [Document.children](https://developer.mozilla.org/en-US/docs/Web/API/Document/children)
* [Document.campatMode](https://developer.mozilla.org/en-US/docs/Web/API/Document/compatMode)
* [Document.contentType](https://developer.mozilla.org/en-US/docs/Web/API/Document/contentType)
* [Document.currentScript](https://developer.mozilla.org/en-US/docs/Web/API/Document/currentScript)
* [Document.doctype](https://developer.mozilla.org/en-US/docs/Web/API/Document/doctype)
* [Document.documentElement](https://developer.mozilla.org/en-US/docs/Web/API/Document/documentElement)
* [Document.documentURI](https://developer.mozilla.org/en-US/docs/Web/API/Document/documentURI)
* [Document.embeds](https://developer.mozilla.org/en-US/docs/Web/API/Document/embeds)
* [Document.firstElementChild](https://developer.mozilla.org/en-US/docs/Web/API/Document/firstElementChild)
* [Document.fonts](https://developer.mozilla.org/en-US/docs/Web/API/Document/fonts)
* [Document.forms](https://developer.mozilla.org/en-US/docs/Web/API/Document/forms)
* [Document.fullscreenElement](https://developer.mozilla.org/en-US/docs/Web/API/Document/fullscreenElement)
* [Document.head](https://developer.mozilla.org/en-US/docs/Web/API/Document/head)
* [Document.hidden](https://developer.mozilla.org/en-US/docs/Web/API/Document/hidden)
* [Document.images](https://developer.mozilla.org/en-US/docs/Web/API/Document/images)
* [Document.implementation](https://developer.mozilla.org/en-US/docs/Web/API/Document/implementation)
* [Document.lastElementChild](https://developer.mozilla.org/en-US/docs/Web/API/Document/lastElementChild)
* [Document.links](https://developer.mozilla.org/en-US/docs/Web/API/Document/links)
* [Document.pictureInPictureElement](https://developer.mozilla.org/en-US/docs/Web/API/Document/pictureInPictureElement)
* [Document.plugins](https://developer.mozilla.org/en-US/docs/Web/API/Document/plugins)
* [Document.pointerLockElement](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerLockElement)
* [Document.featurePolicy](https://developer.mozilla.org/en-US/docs/Web/API/Document/featurePolicy)
* [Document.scripts](https://developer.mozilla.org/en-US/docs/Web/API/Document/scripts)
* [Document.scroolingElement](https://developer.mozilla.org/en-US/docs/Web/API/Document/scrollingElement)
* [Document.styleSheets](https://developer.mozilla.org/en-US/docs/Web/API/Document/styleSheets)
* [Document.timeline](https://developer.mozilla.org/en-US/docs/Web/API/Document/timeline)
* [Document.visibilityState](https://developer.mozilla.org/en-US/docs/Web/API/Document/visibilityState)

## Extensions for HTMLDocument
------------------------------
The ``Document`` interface for HTML documents inherits from the HTMLDocument interface or, since HTML5, is extended for such documents.

* [Document.cookie](https://developer.mozilla.org/en-US/docs/Web/API/Document/cookie)
* [Document.defaultView](https://developer.mozilla.org/en-US/docs/Web/API/Document/defaultview)
* [Document.designMode](https://developer.mozilla.org/en-US/docs/Web/API/Document/designmode)
* [Document.dir](https://developer.mozilla.org/en-US/docs/Web/API/Document/dir)
* [Document.lastModified](https://developer.mozilla.org/en-US/docs/Web/API/Document/lastmodified)
* [Document.location](https://developer.mozilla.org/en-US/docs/Web/API/Document/location)
* [Document.readyState](https://developer.mozilla.org/en-US/docs/Web/API/Document/readystate)
* [Docuemnt.referrer](https://developer.mozilla.org/en-US/docs/Web/API/Document/referrer)
* [Document.title](https://developer.mozilla.org/en-US/docs/Web/API/Document/title)
* [Document.URL](https://developer.mozilla.org/en-US/docs/Web/API/Document/url)

## Event handlers
-----------------
The ``Document`` interface is extended with additional event handlers defined in

* [GlobalEventHandlers.onselectionchange](https://developer.mozilla.org/en-US/docs/Web/API/GlobalEventHandlers/onselectionchange)
* [Document.onvisibilitychange](https://developer.mozilla.org/en-US/docs/Web/API/Document/onvisibilitychange)

# Methods
----------

* [Document.adoptNode()](https://developer.mozilla.org/en-US/docs/Web/API/Document/adoptnode)
* [Document.append()](https://developer.mozilla.org/en-US/docs/Web/API/Document/append)
* [Document.caretPositionFromPoint()](https://developer.mozilla.org/en-US/docs/Web/API/Document/caretPositionFromPoint)
* [Document.createAttribute()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createAttribute)
* [Document.createCDATASeciton()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createCDATASection)
* [Document.createComment()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createComment)
* [Document.createDocumentFragment()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createDocumentFragment)
* [Document.createElement()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createElement)
* [Document.createElementNS()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createElementNS)
* [Document.createEvent()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createEvent)
* [Document.createNodeIterator()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createNodeIterator)
* [Document.createRange()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createRange)
* [Document.createTextNode()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createTextNode)
* [Document.createTreeWalker()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createTreeWalker)
* [Document.elementFromPoint()](https://developer.mozilla.org/en-US/docs/Web/API/Document/elementFromPoint)
* [Document.elementsFromPoint()](https://developer.mozilla.org/en-US/docs/Web/API/Document/elementsFromPoint)
* [Document.getAnimations()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getAnimations)
* [Document.getElementById()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementById)
* [Document.getElementsByClassName()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementsByClassName)
* [Document.getElementsByTagName()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementsByTagName)
* [Document.getElementsByTagNameNS()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementsByTagNameNS)
* [Document.hasStorageAccess()](https://developer.mozilla.org/en-US/docs/Web/API/Document/hasStorageAccess)
* [Document.importNode()](https://developer.mozilla.org/en-US/docs/Web/API/Document/importNode)
* [Document.getSelection()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getSelection)
* [Document.importNode()](https://developer.mozilla.org/en-US/docs/Web/API/Document/importNode)
* [Document.prepend()](https://developer.mozilla.org/en-US/docs/Web/API/Document/prepend)
* [Document.querySelector()](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector)
* [Document.querySelectorAll()](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelectorAll)
* [Document.requestStorageAccess()](https://developer.mozilla.org/en-US/docs/Web/API/Document/requestStorageAccess)
* [Document.createExpression()](https://developer.mozilla.org/en-US/docs/Web/API/Document/createExpression)
* [Document.evaluate()](https://developer.mozilla.org/en-US/docs/Web/API/Document/evaluate)

### Extension for HTML documents
--------------------------------
The ``Document`` interface for HTML documents inherit from the HTMLDocument interface or, since HTML5, is extended for such documents:

* [Document.close()](https://developer.mozilla.org/en-US/docs/Web/API/Document/close)
* [Document.execCommand()](https://developer.mozilla.org/en-US/docs/Web/API/Document/execCommand)
* [Document.getElementByName()](https://developer.mozilla.org/en-US/docs/Web/API/Document/getElementsByName)
* [Document.hasFocus()](https://developer.mozilla.org/en-US/docs/Web/API/Document/hasFocus)
* [Document.open()](https://developer.mozilla.org/en-US/docs/Web/API/Document/open)
* [Document.queryCommandState()](https://developer.mozilla.org/en-US/docs/Web/API/Document/queryCommandState)
* [Document.write()](https://developer.mozilla.org/en-US/docs/Web/API/Document/write)
* [Document.writeln()](https://developer.mozilla.org/en-US/docs/Web/API/Document/writeln)

# Events
--------
Listen to these events using ``addEventListener()`` or by assigning an event listener to the ``oneventname`` property of this interface.

* [scrool](https://developer.mozilla.org/en-US/docs/Web/API/Document/scroll_event)
* [visibilitychange](https://developer.mozilla.org/en-US/docs/Web/API/Document/visibilitychange_event)
* [wheel](https://developer.mozilla.org/en-US/docs/Web/API/Document/wheel_event)

### Animations events
---------------------

* [animationstart](https://developer.mozilla.org/en-US/docs/Web/API/Document/animationstart_event)
* [animationend](https://developer.mozilla.org/en-US/docs/Web/API/Document/animationend_event)
* [animationcancel](https://developer.mozilla.org/en-US/docs/Web/API/Document/animationcancel_event)
* [animationiteration](https://developer.mozilla.org/en-US/docs/Web/API/Document/animationiteration_event)

### Clipboard events
--------------------

* [copy](https://developer.mozilla.org/en-US/docs/Web/API/Document/copy_event)
* [cut](https://developer.mozilla.org/en-US/docs/Web/API/Document/cut_event)
* [paste](https://developer.mozilla.org/en-US/docs/Web/API/Document/paste_event)

### Drag & drop events
----------------------

* [drag](https://developer.mozilla.org/en-US/docs/Web/API/Document/drag_event)
* [dragstart](https://developer.mozilla.org/en-US/docs/Web/API/Document/dragstart_event)
* [dragend](https://developer.mozilla.org/en-US/docs/Web/API/Document/dragend_event)
* [dragleave](https://developer.mozilla.org/en-US/docs/Web/API/Document/dragleave_event)
* [dragover](https://developer.mozilla.org/en-US/docs/Web/API/Document/dragover_event)
* [drop](https://developer.mozilla.org/en-US/docs/Web/API/Document/drop_event)

### Fullscreen events
---------------------

* [fullscreenchange](https://developer.mozilla.org/en-US/docs/Web/API/Document/fullscreenchange_event)
* [fullscreenerror](https://developer.mozilla.org/en-US/docs/Web/API/Document/fullscreenerror_event)

### Keyboard events
-------------------

* [keyup](https://developer.mozilla.org/en-US/docs/Web/API/Document/keyup_event)
* [keydown](https://developer.mozilla.org/en-US/docs/Web/API/Document/keydown_event)
* [keypress](https://developer.mozilla.org/en-US/docs/Web/API/Document/keypress_event)

### Load & unload events
------------------------

* [DOMContentLoaded](https://developer.mozilla.org/en-US/docs/Web/API/Document/DOMContentLoaded_event)
* [readystatechange](https://developer.mozilla.org/en-US/docs/Web/API/Document/readystatechange_event)

### Pointer events
------------------

* [gotpointercapture](https://developer.mozilla.org/en-US/docs/Web/API/Document/gotpointercapture_event)
* [lostpointercapture](https://developer.mozilla.org/en-US/docs/Web/API/Document/lostpointercapture_event)
* [pointerenter](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerenter_event)
* [pointercancel](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointercancel_event)
* [pointerdown](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerdown_event)
* [pointerleave](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerleave_event)
* [pointerlockchange](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerlockchange_event)
* [pointerlockerror](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerlockerror_event)
* [pointermove](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointermove_event)
* [pointerout](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerout_event)
* [pointover](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerover_event)
* [pointerup](https://developer.mozilla.org/en-US/docs/Web/API/Document/pointerup_event)

### Selection events
--------------------

* [selectionchange](https://developer.mozilla.org/en-US/docs/Web/API/Document/selectionchange_event)
* [slectstart](https://developer.mozilla.org/en-US/docs/Web/API/Document/selectstart_event)

### Touch events
----------------

* [touchstart](https://developer.mozilla.org/en-US/docs/Web/API/Document/touchstart_event)
* [touchend](https://developer.mozilla.org/en-US/docs/Web/API/Document/touchend_event)
* [touchmove](https://developer.mozilla.org/en-US/docs/Web/API/Document/touchmove_event)
* [touchcancel](https://developer.mozilla.org/en-US/docs/Web/API/Document/touchcancel_event)

### Transition events
---------------------

* [transitionstart](https://developer.mozilla.org/en-US/docs/Web/API/Document/transitionstart_event)
* [transitionrun](https://developer.mozilla.org/en-US/docs/Web/API/Document/transitionrun_event)
* [transitionend](https://developer.mozilla.org/en-US/docs/Web/API/Document/transitionend_event)
* [transitioncancel](https://developer.mozilla.org/en-US/docs/Web/API/Document/transitioncancel_event)

> [!NOTE]
> Specifications
> [DOM Standard](https://dom.spec.whatwg.org/#interface-document)
