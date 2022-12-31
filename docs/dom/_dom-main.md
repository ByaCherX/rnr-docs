<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

<h1 style="text-align:center">Document Object Model (DOM)</h1>

The Document Object Model (DOM) connects web pages to scripts or programming languages by representing the structure of a document—such as the HTML representing a web page—in memory. Usually it refers to JavaScript, even though modeling HTML, SVG, or XML documents as objects are not part of the core JavaScript language.

The DOM represents a document with a logical tree. Each branch of the tree ends in a node, and each node contains objects. DOM methods allow programmatic access to the tree. With them, you can change the document's structure, style, or content.

Nodes can also have event handlers attached to them. Once an event is triggered, the event handlers get executed.

To learn more about what the DOM is and how it represents documents, see our article [Introduction to the DOM](dom-overview.md).

## DOM interfaces
* Attr
* CDATASection
* CharacterData
* Comment
* CustomEvent
* [Document]()
* DocumentFragment
* DocumentType
* DOMError (deprected) 
* DOMException
* DOMImplementation
* DOMString
* DOMTimeStamp
* DOMStringList
* DOMTokenList
* Element
* Event
* EventTarget
* HTMLCollection
* MutationObserver
* MutationRecord
* NamedNodeMap
* Node
* NodeFilter
* NodeIterator
* NodeList
* ProcessingInstruction
* Selection (experimential)
* Range
* Text
* TextDecoder (experimential)
* TextEncoder (experimential)
* TimeRanges
* TreeWalker
* URL
* Window
* Worker
* XMLDocument (experimential)

## Obsolete DOM interfaces
The Document Object Model has been highly simplified. To achieve this, the following interfaces present in the different DOM level 3 or earlier specifications have been removed. It is uncertain whether some may be reintroduced in the future or not, but for the time being they should be considered obsolete and should be avoided:
* DOMConfiguration
* DOMErrorHandler
* DOMImplementationList
* DOMImplementationRegistry
* DOMImplementationSource
* DOMLocator
* DOMObject
* DOMSettableTokenList
* DOMUserData
* ElementTraversal
* Entity
* EntityReference
* NameList
* Notation
* TypeInfo
* UserDataHandler






