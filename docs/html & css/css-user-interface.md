<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### Appearance
The `appearance` CSS property is used to display an element using platform-native styling, based on the operating system's theme. The `-moz-appearance` and `-webkit-appearance` properties are non-standard versions of this property, used (respectively) by Gecko (Firefox) and by WebKit-based (e.g., Safari) and Blink-based (e.g., Chrome, Opera) browsers to achieve the same thing. Note that Firefox and Edge also support `-webkit-appearance`, for compatibility reasons.

### caret-color
The `caret-color` CSS property sets the color of the insertion caret, the visible marker where the next character typed will be inserted. This is sometimes referred to as the text input cursor. The caret appears in elements such as `<input>` or those with the contenteditable attribute. The caret is typically a thin vertical line that flashes to help make it more noticeable. By default, it is black, but its color can be altered with this property.
```css
/* Keyword values */
caret-color: auto;
caret-color: transparent;
caret-color: currentcolor;

/* <color> values */
caret-color: red;
caret-color: #5729e9;
caret-color: rgb(0, 200, 0);
caret-color: hsla(228, 4%, 24%, 0.8);
```

### Cursor
The `cursor` CSS property sets the type of mouse cursor, if any, to show when the mouse pointer is over an element.
```css
/* Keyword value */
cursor: pointer;
cursor: auto;

/* URL, with a keyword fallback */
cursor: url(hand.cur), pointer;

/* URL and coordinates, with a keyword fallback */
cursor: url(cursor1.png) 4 12, auto;
cursor: url(cursor2.png) 2 2, pointer;

/* Global values */
cursor: inherit;
cursor: initial;
cursor: unset;
```
<code>More about this section and cursor list: https://devdocs.io/css/cursor</code>

### Outline
The `outline` CSS shorthand property set all the outline properties in a single declaration.
```css
/* style */
outline: solid;

/* color | style */
outline: #f66 dashed;

/* style | width */
outline: inset thick;

/* color | style | width */
outline: green solid 3px;

/* Global values */
outline: inherit;
outline: initial;
outline: unset;

/* offset */
outline-offset: 3px;
outline-offset: 0.2em;
```

### Resize
The `resize` CSS property sets whether an element is resizable, and if so, in which directions.
```css
/* Keyword values */
resize: none;
resize: both;
resize: horizontal;
resize: vertical;
resize: block;
resize: inline;

/* Global values */
resize: inherit;
resize: initial;
resize: unset;  
```

### User-select
The `user-select` CSS property controls whether the user can select text. This doesn't have any effect on content loaded as part of a browser's user interface (its chrome), except in textboxes.
```css
/* Keyword values */
user-select: none;
user-select: auto;
user-select: text;
user-select: contain;
user-select: all;

/* Global values */
user-select: inherit;
user-select: initial;
user-select: unset;

/* Mozilla-specific values */
-moz-user-select: none;
-moz-user-select: text;
-moz-user-select: all;

/* WebKit-specific values */
-webkit-user-select: none;
-webkit-user-select: text;

/* Microsoft-specific values */
-ms-user-select: none;
-ms-user-select: text;
-ms-user-select: element;
```

> [!TIP]
> More about > https://devdocs.io/css-basic-user-interface/
