<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### Background
The `background` shorthand CSS property sets all background style properties at once, such as color, image, origin and size, or repeat method.
```css
/* Using a <background-color> */
background: green;

/* Using a <bg-image> and <repeat-style> */
background: url("test.jpg") repeat-y;

/* Using a <box> and <background-color> */
background: border-box red;

/* A single image, centered and scaled */
background: no-repeat center/80% url("../img/image.png");
```

#### Background properties
* background-attachment
* background-clip
* background-image
* background-origin
* background-position
* background-position-x
* background-position-y
* background-repeat
* background-size

### Border
The `border` shorthand CSS property sets an element's border. It sets the values of border-width, border-style, and border-color.
```css
/* style */
border: solid;

/* width | style */
border: 2px dotted;

/* style | color */
border: outset #f33;

/* width | style | color */
border: medium dashed green;

/* Global values */
border: inherit;
border: initial;
border: unset;
```

#### Border properties
* border-width
  * border-top-width
  * border-right-width
  * border-left-width
  * border-bottom-width
* border-style
  * border-top-style
  * border-right-style
  * border-left-style
  * border-bottom-style
* border-color
  * border-top-color
  * border-right-color
  * border-left-color
  * border-bottom-color
* border-image
  * border-image-outset
  * border-image-repeat
  * border-image-slice
  * border-image-source
  * border-image-width
* border-`<length>`-`<style>` 
* border-radius
  * border-top-left|right-radius
  * border-bottom-left|right-radius

### Box-shadow
The `box-shadow` CSS property adds shadow effects around an element's frame. You can set multiple effects separated by commas. A box shadow is described by X and Y offsets relative to the element, blur and spread radius, and color.
```css
/* Keyword values */
box-shadow: none;

/* offset-x | offset-y | color */
box-shadow: 60px -16px teal;

/* offset-x | offset-y | blur-radius | color */
box-shadow: 10px 5px 5px black;

/* offset-x | offset-y | blur-radius | spread-radius | color */
box-shadow: 2px 2px 2px 1px rgba(0, 0, 0, 0.2);

/* inset | offset-x | offset-y | color */
box-shadow: inset 5em 1em gold;

/* Any number of shadows, separated by commas */
box-shadow: 3px 3px red, -1em 0 0.4em olive;

/* Global keywords */
box-shadow: inherit;
box-shadow: initial;
box-shadow: unset;
```




