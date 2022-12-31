<link rel="stylesheet" href="../source.css">
<h1 id="h1c">HTML Elements</h1>

This page lists all the HTML elements, which are created using tags. They are grouped by function to help you find what you have in mind easily. An alphabetical list of all elements is provided in the sidebar on every element's page as well as this one.

## Main Root

| Element | Description |
|---------|-------------|
| `<html>`  | The `<html>` represents the root (top-level element) of an HTML document, so it is also referred to as the root element. All other elements must be descendants of this element. |


## Document metadata
Metadata contains information about the page. This includes information about styles, scripts and data to help software (search engines, browsers, etc.) use and render the page. Metadata for styles and scripts may be defined in the page or link to another file that has the information.

| Element | Description |
|---------|-------------|
| `<base>`  | The `<base>` specifies the base URL to use for all relative URLs in a document.|
| `<head>`  | The `<head>` contains machine-readable information (metadata) about the document, like its title, scripts, and style sheets.|
| `<link>`  | The `<link>` specifies relationships between the current document and an external resource. This element is most commonly used to link to CSS, but is also used to establish site icons (both "favicon" style icons and icons for the home screen and apps on mobile devices) among other things.|
| `<meta>`  | The `<meta>` represents Metadata that cannot be represented by other HTML meta-related elements, like base, link, script, style or title.|
| `<style>`  | The `<style>` contains style information for a document, or part of a document.|
| `<title`>  | The HTML Title element (`<title>`) defines the document's title that is shown in a Browser's title bar or a page's tab.|


## Sectioning root

| Element | Description |
|---------|-------------|
| `<body>`|The `<body>` represents the content of an HTML document. There can be only one `<body>` element in a document.|


## Content sectioning
Content sectioning elements allow you to organize the document content into logical pieces. Use the sectioning elements to create a broad outline for your page content, including header and footer navigation, and heading elements to identify sections of content.

| Element | Description |
|---------|-------------|
|`<address>`|	The `<address>` indicates that the enclosed HTML provides contact information for a person or people, or for an organization.|
|`<article>`|	The `<article>` represents a self-contained composition in a document, page, application, or site, which is intended to be independently distributable or reusable (e.g., in syndication).|
|`<aside>`|	The `<aside>` represents a portion of a document whose content is only indirectly related to the document's main content.|
|`<footer>`|	The `<footer>` represents a footer for its nearest sectioning content or sectioning root element. A `<footer>` typically contains information about the author of the section, copyright data or links to related documents.|
|`<header>`|	The `<header>` represents introductory content, typically a group of introductory or navigational aids. It may contain some heading elements but also a logo, a search form, an author name, and other elements.|
|`<h1>, <h2>, <h3>, <h4>, <h5>, <h6>`|	The HTML `<h1>–<h6>` elements represent six levels of section headings. `<h1>` is the highest section level and `<h6>` is the lowest.|
|`<main>`|	The `<main>` represents the dominant content of the body of a document. The main content area consists of content that is directly related to or expands upon the central topic of a document, or the central functionality of an application.|
|`<nav>`|	The `<nav>` represents a section of a page whose purpose is to provide navigation links, either within the current document or to other documents. Common examples of navigation sections are menus, tables of contents, and indexes.|
|`<section>`|	The `<section>` represents a generic standalone section of a document, which doesn't have a more specific semantic element to represent it.|

## Text content
Use HTML text content elements to organize blocks or sections of content placed between the opening `<body>` and closing `</body>` tags. Important for accessibility and SEO, these elements identify the purpose or structure of that content.

| Element | Description |
|---------|-------------|
|`<blockquote>`|	The `<blockquote>` (or HTML Block Quotation Element) indicates that the enclosed text is an extended quotation. Usually, this is rendered visually by indentation (see Notes for how to change it). A URL for the source of the quotation may be given using the cite attribute, while a text representation of the source can be given using the cite element.|
|`<dd>`|	The `<dd>` provides the description, definition, or value for the preceding term (dt) in a description list (dl).|
|`<div`|	The HTML Content Division element (`<div>`) is the generic container for flow content. It has no effect on the content or layout until styled in some way using CSS (e.g. styling is directly applied to it, or some kind of layout model like Flexbox is applied to its parent element).|
|`<dl>`|	The `<dl>` element represents a description list. The element encloses a list of groups of terms (specified using the dt element) and descriptions (provided by dd elements). Common uses for this element are to implement a glossary or to display metadata (a list of key-value pairs).|
|`<dt>`|	The `<dt>` specifies a term in a description or definition list, and as such must be used inside a dl element.|
|`<figcaption>`|	The `<figcaption>` represents a caption or legend describing the rest of the contents of its parent figure element.|
|`<figure>`|	The `<figure>` represents self-contained content, potentially with an optional caption, which is specified using the figcaption element.|
|`<hr>`|	The `<hr>` represents a thematic break between paragraph-level elements: for example, a change of scene in a story, or a shift of topic within a section.|
|`<li>`|	The `<li>` is used to represent an item in a list.|
|`<ol>`|	The `<ol>` represents an ordered list of items — typically rendered as a numbered list.|
|`<p>`|	The `<p>` represents a paragraph.|
|`<pre>`|	The `<pre>` represents preformatted text which is to be presented exactly as written in the HTML file.|
|`<ul>`|	The `<ul>` represents an unordered list of items, typically rendered as a bulleted list.|

## Inline text semantics
Use the HTML inline text semantic to define the meaning, structure, or style of a word, line, or any arbitrary piece of text.

| Element | Description |
|---------|-------------|
|`<a>`|	The `<a>` (or anchor element), with its href attribute, creates a hyperlink to web pages, files, email addresses, locations in the same page, or anything else a URL can address.|
|`<abbr>`|	The HTML Abbreviation element (`<abbr>`) represents an abbreviation or acronym; the optional title attribute can provide an expansion or description for the abbreviation.|
|`<b>`|	The `<b>` is used to draw the reader's attention to the element's contents, which are not otherwise granted special importance.|
|`<bdi>`|	The HTML Bidirectional Isolate element (`<bdi>`) tells the browser's bidirectional algorithm to treat the text it contains in isolation from its surrounding text.|
|`<bdo>`|	The HTML Bidirectional Text Override element (`<bdo>`) overrides the current directionality of text, so that the text within is rendered in a different direction.|
|`<br>`|	The `<br>` produces a line break in text (carriage-return). It is useful for writing a poem or an address, where the division of lines is significant.|
|`<cite>`	|The HTML Citation element (`<cite>`) is used to describe a reference to a cited creative work, and must include the title of that work.|
|`<code>`	|The `<code>` displays its contents styled in a fashion intended to indicate that the text is a short fragment of computer code.|
|`<data>`	|The `<data>` links a given piece of content with a machine-readable translation. If the content is time- or date-related, the time element must be used.|
|`<dfn>`|	The HTML Definition element (`<dfn>`) is used to indicate the term being defined within the context of a definition phrase or sentence.|
|`<em>`|	The `<em>` marks text that has stress emphasis. The `<em>` element can be nested, with each level of nesting indicating a greater degree of emphasis.|
|`<i>`|	The `<i>` represents a range of text that is set off from the normal text for some reason, such as idiomatic text, technical terms, taxonomical designations, among others.|
|`<kbd>`|	The HTML Keyboard Input element (`<kbd>`) represents a span of inline text denoting textual user input from a keyboard, voice input, or any other text entry device.|
|`<mark>`|	The HTML Mark Text element (`<mark>`) represents text which is marked or highlighted for reference or notation purposes, due to the marked passage's relevance or importance in the enclosing context.|
|`<q>`|	The `<q>` indicates that the enclosed text is a short inline quotation. Most modern browsers implement this by surrounding the text in quotation marks.|
|`<rb>`|	The `<rb>` is used to delimit the base text component of a ruby annotation, i.e. the text that is being annotated.|
|`<rp>`|	The `<rp>` is used to provide fall-back parentheses for browsers that do not support display of ruby annotations using the ruby element.|
|`<rt>`|	The `<rt>` specifies the ruby text component of a ruby annotation, which is used to provide pronunciation, translation, or transliteration information for East Asian typography. The `<rt>` element must always be contained within a ruby element.|
|`<rtc>`|	The `<rtc>` embraces semantic annotations of characters presented in a ruby of rb elements used inside of ruby element. rb elements can have both pronunciation (rt) and semantic (rtc) annotations.|
|`<ruby>`|	The `<ruby>` represents small annotations that are rendered above, below, or next to base text, usually used for showing the pronunciation of East Asian characters. It can also be used for annotating other kinds of text, but this usage is less common.|
|`<s>`|	The `<s>` renders text with a strikethrough, or a line through it. Use the <s> element to represent things that are no longer relevant or no longer accurate. However, `<s>` is not appropriate when indicating document edits; for that, use the del and ins elements, as appropriate.|
|`<samp>`|	The HTML Sample Element (`<samp>`) is used to enclose inline text which represents sample (or quoted) output from a computer program.|
|`<small>`|	The `<small>` element represents side-comments and small print, like copyright and legal text, independent of its styled presentation. |By default, it renders text within it one font-size smaller, such as from small to x-small.|
|`<span>`	|The `<span>` is a generic inline container for phrasing content, which does not inherently represent anything. It can be used to group elements for styling purposes (using the class or id attributes), or because they share attribute values, such as lang.|
|`<strong>`|	The HTML Strong Importance Element (`<strong>`) indicates that its contents have strong importance, seriousness, or urgency. Browsers typically render the contents in bold type.|
|`<sub>`|	The HTML Subscript element (`<sub>`) specifies inline text which should be displayed as subscript for solely typographical reasons.|
|`<sup>`|	The HTML Superscript element (`<sup>`) specifies inline text which is to be displayed as superscript for solely typographical reasons.|
|`<time>`|	The HTML `<time>` represents a specific period in time.|
|`<u>`|	The HTML Unarticulated Annotation element (`<u>`) represents a span of inline text which should be rendered in a way that indicates that it has a non-textual annotation.|
|`<var>`|	The HTML Variable element (`<var>`) represents the name of a variable in a mathematical expression or a programming context.|
|`<wbr>`|	The `<wbr>` represents a word break opportunity—a position within text where the browser may optionally break a line, though its line-breaking rules would not otherwise create a break at that location.|

## Image and multimedia
HTML supports various multimedia resources such as images, audio, and video.

| Element | Description |
|---------|-------------|
|`<area>`|	The `<area>` defines an area inside an image map that has predefined clickable areas. An image map allows geometric areas on an image to be associated with Hyperlink.|
|`<audio>`|	The `<audio>` is used to embed sound content in documents. It may contain one or more audio sources, represented using the src attribute or the source element: the browser will choose the most suitable one. It can also be the destination for streamed media, using a MediaStream.|
|`<img>`|	The `<img>` embeds an image into the document.|
|`<map>`|	The `<map>` is used with area elements to define an image map (a clickable link area).|
|`<track>`|	The `<track>` is used as a child of the media elements, audio and video. It lets you specify timed text tracks (or time-based data), for example to automatically handle subtitles.|
|`<video>`|	The HTML Video element (`<video>`) embeds a media player which supports video playback into the document. You can use `<video>` for audio content as well, but the audio element may provide a more appropriate user experience.|

## Embedded content
In addition to regular multimedia content, HTML can include a variety of other content, even if it's not always easy to interact with.

| Element | Description |
|---------|-------------|
|`<embed>`|	The `<embed>` embeds external content at the specified point in the document. This content is provided by an external application or other source of interactive content such as a browser plug-in.
|`<iframe>`|	The `<iframe>` represents a nested browsing context, embedding another HTML page into the current one.
|`<object>`|	The `<object>` represents an external resource, which can be treated as an image, a nested browsing context, or a resource to be handled by a plugin.
|`<param>`|	The `<param>` defines parameters for an object element.
|`<picture>`|	The `<picture>` contains zero or more source elements and one img element to offer alternative versions of an image for different display/device scenarios.
|`<portal>`|	The `<portal>` enables the embedding of another HTML page into the current one for the purposes of allowing smoother navigation into new pages.
|`<source>`|	The `<source>` specifies multiple media resources for the picture, the audio element, or the video element.

## SVG and MathML
You can embed *SVG* and *MathML* content directly into HTML documents, using the `<svg>` and `<math>` elements.

| Element | Description |
|---------|-------------|
|`<svg>`  | The svg element is a container that defines a new coordinate system and viewport. It is used as the outermost element of SVG documents, but it can also be used to embed an SVG fragment inside an SVG or HTML document.|
|`<math>` | The top-level element in MathML is `<math>`. Every valid MathML instance must be wrapped in `<math>` tags. In addition you must not nest a second `<math>` element in another, but you can have an arbitrary number of other child elements in it.|

## Scripting
| Element  | Description |
|----------|-------------|
|`<canvas>`  |	Use the `<canvas>` with either the canvas scripting API or the WebGL API to draw graphics and animations.|
|`<noscript>`|	The `<noscript>` defines a section of HTML to be inserted if a script type on the page is unsupported or if scripting is currently turned off in the browser.|
|`<script>`  |	The `<script>` is used to embed executable code or data; this is typically used to embed or refer to JavaScript code.|

## Demarcating edits
These elements let you provide indications that specific parts of the text have been altered.

| Element | Description |
|---------|-------------|
|`<del>` |The `<del>` represents a range of text that has been deleted from a document.|
|`<ins>` |The `<ins>` represents a range of text that has been added to a document.|

## Table content
The elements here are used to create and handle tabular data.

| Element  | Description |
|----------|-------------|
|`<caption>` |	The `<caption>` specifies the caption (or title) of a table.
|`<col>`     |	The `<col>` defines a column within a table and is used for defining common semantics on all common cells. It is generally found within a colgroup element.|
|`<colgroup>`|	The `<colgroup>` defines a group of columns within a table.|
|`<table>`  |	The `<table>` represents tabular data — that is, information presented in a two-dimensional table comprised of rows and columns of cells containing data.|
|`<tbody>`   |	The HTML Table Body element (`<tbody>`) encapsulates a set of table rows (tr elements), indicating that they comprise the body of the table (table).|
|`<td>`      |	The `<td>` defines a cell of a table that contains data. It participates in the table model.|
|`<tfoot>`   |	The `<tfoot>` defines a set of rows summarizing the columns of the table.|
|`<th>`      |	The `<th>` defines a cell as header of a group of table cells. The exact nature of this group is defined by the scope and headers attributes.|
|`<thead>`   |	The `<thead>` defines a set of rows defining the head of the columns of the table.|
|`<tr>`      |	The `<tr>` defines a row of cells in a table. The row's cells can then be established using a mix of td (data cell) and th (header cell) elements.|

## Forms
HTML provides a number of elements which can be used together to create forms which the user can fill out and submit to the Web site or application. There's a great deal of further information about this available in the *HTML forms guide*.

| Element  | Description |
|----------|-------------|
|`<button>` | The `<button>` represents a clickable button, used to submit forms or anywhere in a document for accessible, standard button functionality.|
|`<datalist>`| The `<datalist>` contains a set of option elements that represent the permissible or recommended options available to choose from within other controls.|
|`<fieldset>`| The `<fieldset>` is used to group several controls as well as labels (label) within a web form.|
|`<form>` The `<form>` represents a document section containing interactive controls for submitting information.|
|`<input>`   | The `<input>` is used to create interactive controls for web-based forms in order to accept data from the user; a wide variety of types of input data and control widgets are available, depending on the device and user agent.|
|`<label>`   | The `<label> `represents a caption for an item in a user interface.|
|`<legend>`  | The `<legend>` represents a caption for the content of its parent fieldset.|
|`<meter>`   | The `<meter>` represents either a scalar value within a known range or a fractional value.|
|`<optgroup>`| The `<optgroup>` creates a grouping of options within a select element.|
|`<option>`  | The `<option>` is used to define an item contained in a select, an optgroup, or a datalist element. As such, `<option>` can represent menu items in popups and other lists of items in an HTML document.|
|`<output>`  | The HTML Output element (`<output>`) is a container element into which a site or app can inject the results of a calculation or the outcome of a user action.|
|`<progress>`| The `<progress>` displays an indicator showing the completion progress of a task, typically displayed as a progress bar.|
|`<select>`  | The `<select>` represents a control that provides a menu of options|
|`<textarea>`| The `<textarea>` represents a multi-line plain-text editing control, useful when you want to allow users to enter a sizeable amount of free-form text, for example a comment on a review or feedback form.|

## Interactive elements
HTML offers a selection of elements which help to create interactive user interface objects.
| Element   | Description |
|-----------|-------------|
|`<details>`|The `<details>` creates a disclosure widget in which information is visible only when the widget is toggled into an "open" state.|
|`<dialog>` |The `<dialog>` represents a dialog box or other interactive component, such as a dismissible alert, inspector, or subwindow.|
|`<menu>`   |The `<menu>` represents a group of commands that a user can perform or activate. This includes both list menus, which might appear across the top of a screen, as well as context menus, such as those that might appear underneath a button after it has been clicked.|
|`<summary>`| The HTML Disclosure Summary element (`<summary>`) element specifies a summary, caption, or legend for a details element's disclosure box.|

## Web Components
Web Components is an HTML-related technology which makes it possible to, essentially, create and use custom elements as if it were regular HTML. In addition, you can create custom versions of standard HTML elements.

| Element  | Description |
|----------|-------------|
|`<slot>`|	The `<slot>`—part of the Web Components technology suite—is a placeholder inside a web component that you can fill with your own markup, which lets you create separate DOM trees and present them together.|
|`<template>`|	The `<template>` is a mechanism for holding HTML that is not to be rendered immediately when a page is loaded but may be instantiated subsequently during runtime using JavaScript.|





