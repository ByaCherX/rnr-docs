<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### Css basic box model
When laying out a document, the browser's rendering engine represents each element as a rectangular box according to the standard CSS basic box model. CSS determines the size, position, and properties (color, background, border size, etc.) of these boxes.
```
 _______________________________________
|                                       |
|           margin (transparent)        |
|   _________________________________   |
|  |                                 |  |
|  |        border                   |  |
|  |   ___________________________   |  |
|  |  |                           |  |  |
|  |  |     padding               |  |  |
|  |  |   _____________________   |  |  |
|  |  |  |                     |  |  |  |
|  |  |  |  content            |  |  |  |
|  |  |  |_____________________|  |  |  |
|  |  |___________________________|  |  |
|  |_________________________________|  |
|_______________________________________|

         |----element width----|
|---------------box width---------------|

=================================- Advanced -=================================

                           --------------- <-- top
                             top margin
                           ---------------
                             top border
                           ---------------
                            top padding
                           +-------------+ <-- inner top
|        |        |        |             |         |         |         |
|--left--|--left--|--left--|-- content --|--right--|--right--|--right--|
| margin | border | padding|             | padding | border  | margin  |
|        |        |        |             |         |         |         |
                           +-------------+ <-- inner bottom
^                          ^             ^                             ^
left         left inner edge             right inner edge          right
outer                                                              outer
edge                        bottom padding                          edge
                           ---------------
                             bottom border
                           ---------------
                             bottom margin
                           --------------- <-- bottom

```
### Margin
The `margin` CSS property sets the margin area on all four sides of an element. It is a shorthand for margin-top, margin-right, margin-bottom, and margin-left.
```css
/* Apply to all four sides */
margin: 1em;
margin: -3px;

/* vertical | horizontal */
margin: 5% auto;

/* top | horizontal | bottom */
margin: 1em auto 2em;

/* top | right | bottom | left */
margin: 2px 1em 0 auto;

/* Global values */
margin: inherit;
margin: initial;
margin: unset;
```

#### Margin properties
* Margin-bottom
* Margin-left
* Margin-right
* Margin-top

### Padding
The `padding` CSS shorthand property sets the padding area on all four sides of an element at once.
```css
/* Apply to all four sides */
padding: 1em;

/* vertical | horizontal */
padding: 5% 10%;

/* top | horizontal | bottom */
padding: 1em 2em 2em;

/* top | right | bottom | left */
padding: 5px 1em 0 2em;

/* Global values */
padding: inherit;
padding: initial;
padding: unset;
```

#### Padding properties
* padding-bottom
* padding-left
* padding-right
* padding-top

> [!TIP]
> For more information https://devdocs.io/css/css_box_model
