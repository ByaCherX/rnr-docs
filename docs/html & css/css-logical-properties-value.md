<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### block-size
The `block-size` CSS property defines the horizontal or vertical size of an element's block, depending on its writing mode. It corresponds to either the *width* or the *height* property, depending on the value of writing-mode.

If the writing mode is vertically oriented, the value of `block-size` relates to the width of the element; otherwise, it relates to the height of the element. A related property is *inline-size*, which defines the other dimension of the element.
```css
/* <length> values */
block-size: 300px;
block-size: 25em;

/* <percentage> values */
block-size: 75%;

/* Keyword values */
block-size: max-content;
block-size: min-content;
block-size: fit-content(20em);
block-size: auto;
```

### border-block
The `border-block` CSS property is a *shorthand property* for setting the individual logical block border property values in a single place in the style sheet.
```css
border-block: 1px;
border-block: 2px dotted;
border-block: medium dashed blue;
```

#### Constituent properties
- border-block-color
- border-block-style
- border-block-width
- border-block-end
- border-block-end-color
- border-block-end-style
- border-block-end-width
- border-block-start
- border-block-start-color
- border-block-start-style
- border-block-start-width
- ==============
- border-inline-color
- border-inline-style
- border-inline-width
- border-inline-end
- border-inline-end-color
- border-inline-end-style
- border-inline-end-width
- border-inline-start
- border-inline-start-color
- border-inline-start-style
- border-inline-start-width

## CSS logical Properties and Valurs
**CSS Logical Properties and Values** is a module of CSS introducing logical properties and values that provide the ability to control layout through logical, rather than physical, direction and dimension mappings.

The module also defines logical properties and values for properties previously defined in CSS 2.1. Logical properties define direction‐relative equivalents of their corresponding physical properties.

#### Block vs. inline
Logical properties and values use the abstract terms block and inline to describe the direction in which they flow. The physical meaning of these terms depends on the *writing mode*.

**Block dimension**
- The dimension perpendicular to the flow of text within a line, i.e., the vertical dimension in horizontal writing modes, and the horizontal dimension in vertical writing modes. For standard English text, it is the vertical dimension.</br>

**Inline dimension**
- The dimension parallel to the flow of text within a line, i.e., the horizontal dimension in horizontal writing modes, and the vertical dimension in vertical writing modes. For standard English text, it is the horizontal dimension.

### Properties for margin, borders and padding
<div class="index"> <ul> 
 <li><a href="border-block"><code>border-block</code></a></li> <li><a href="border-block-color"><code>border-block-color</code></a></li> <li><a href="border-block-end"><code>border-block-end</code></a></li> <li><a href="border-block-end-color"><code>border-block-end-color</code></a></li> <li><a href="border-block-end-style"><code>border-block-end-style</code></a></li> <li><a href="border-block-end-width"><code>border-block-end-width</code></a></li> <li><a href="border-block-start"><code>border-block-start</code></a></li> <li><a href="border-block-start-color"><code>border-block-start-color</code></a></li> <li><a href="border-block-start-style"><code>border-block-start-style</code></a></li> <li><a href="border-block-start-width"><code>border-block-start-width</code></a></li> <li><a href="border-block-style"><code>border-block-style</code></a></li> <li><a href="border-block-width"><code>border-block-width</code></a></li> <li>
 <a href="border-color"><code>border-color</code></a> <span style="white-space: nowrap;">(<code>logical</code>
 </li> <li><a href="border-inline"><code>border-inline</code></a></li> <li><a href="border-inline-color"><code>border-inline-color</code></a></li> <li><a href="border-inline-end"><code>border-inline-end</code></a></li> <li><a href="border-inline-end-color"><code>border-inline-end-color</code></a></li> <li><a href="border-inline-end-style"><code>border-inline-end-style</code></a></li> <li><a href="border-inline-end-width"><code>border-inline-end-width</code></a></li> <li><a href="border-inline-start"><code>border-inline-start</code></a></li> <li><a href="border-inline-start-color"><code>border-inline-start-color</code></a></li> <li><a href="border-inline-start-style"><code>border-inline-start-style</code></a></li> <li><a href="border-inline-start-width"><code>border-inline-start-width</code></a></li> <li><a href="border-inline-style"><code>border-inline-style</code></a></li> <li><a href="border-inline-width"><code>border-inline-width</code></a></li> <li><a href="border-start-start-radius"><code>border-start-start-radius</code></a></li> <li><a href="border-start-end-radius"><code>border-start-end-radius</code></a></li> <li><a href="border-end-start-radius"><code>border-end-start-radius</code></a></li> <li><a href="border-end-end-radius"><code>border-end-end-radius</code></a></li> <li>
 <a href="border-style"><code>border-style</code></a> <span style="white-space: nowrap;">(<code>logical</code>
 </li> <li>
 <a href="border-width"><code>border-width</code></a> <span style="white-space: nowrap;">(<code>logical</code> 
 </li> <li>
 <a href="margin"><code>margin</code></a> <span style="white-space: nowrap;">(<code>logical</code>
 </li> <li><a href="margin-block"><code>margin-block</code></a></li> <li><a href="margin-block-end"><code>margin-block-end</code></a></li> <li><a href="margin-block-start"><code>margin-block-start</code></a></li> <li><a href="margin-inline"><code>margin-inline</code></a></li> <li><a href="margin-inline-end"><code>margin-inline-end</code></a></li> <li><a href="margin-inline-start"><code>margin-inline-start</code></a></li> <li>
 <a href="padding"><code>padding</code></a> <span style="white-space: nowrap;">(<code>logical</code>
 </li> <li><a href="padding-block"><code>padding-block</code></a></li> <li><a href="padding-block-end"><code>padding-block-end</code></a></li> <li><a href="padding-block-start"><code>padding-block-start</code></a></li> <li><a href="padding-inline"><code>padding-inline</code></a></li> <li><a href="padding-inline-end"><code>padding-inline-end</code></a></li> <li><a href="padding-inline-start"><code>padding-inline-start</code></a></li> 
</ul> </div>


> [!TIP]
> More about > https://devdocs.io/css-logical-properties-values/
