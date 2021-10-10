<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

CSS Grid Layout excels at dividing a page into major regions or defining the relationship in terms of size, position, and layer, between parts of a control built from HTML primitives.

Like tables, grid layout enables an author to align elements into columns and rows. However, many more layouts are either possible or easier with CSS grid than they were with tables. For example, a grid container's child elements could position themselves so they actually overlap and layer, similar to CSS positioned elements.

### Grid Properties

<div class="index">
 <ul> <li><a href="grid-template-columns"><code>grid-template-columns</code></a></li> <li><a href="grid-template-rows"><code>grid-template-rows</code></a></li> <li><a href="grid-template-areas"><code>grid-template-areas</code></a></li> <li><a href="grid-template"><code>grid-template</code></a></li> <li><a href="grid-auto-columns"><code>grid-auto-columns</code></a></li> <li><a href="grid-auto-rows"><code>grid-auto-rows</code></a></li> <li><a href="grid-auto-flow"><code>grid-auto-flow</code></a></li> <li><a href="grid"><code>grid</code></a></li> <li><a href="grid-row-start"><code>grid-row-start</code></a></li> <li><a href="grid-column-start"><code>grid-column-start</code></a></li> <li><a href="grid-row-end"><code>grid-row-end</code></a></li> <li><a href="grid-column-end"><code>grid-column-end</code></a></li> <li><a href="grid-row"><code>grid-row</code></a></li> <li><a href="grid-column"><code>grid-column</code></a></li> <li><a href="grid-area"><code>grid-area</code></a></li> <li><a href="row-gap"><code>row-gap</code></a></li> <li><a href="column-gap"><code>column-gap</code></a></li> <li><a href="gap"><code>gap</code></a></li>
 </li> </ul> 
</div>

### Grid Glossary
* Grid 
* Grid Lines
* Grid Tracks
* Grid Cell
* Grid Area
* Gutters
* Grid Axis
* Grid row
* Grid column

### Grid
The `grid` CSS property is a shorthand property that sets all of the explicit and implicit grid properties in a single declaration.

Using `grid` you specify one axis using *grid-template-rows* or *grid-template-columns*, you then specify how content should auto-repeat in the other axis using the implicit grid properties: *grid-auto-rows*, *grid-auto-columns*, and *grid-auto-flow*.
```css
/* <'grid-template'> values */
grid: none;
grid: "a" 100px "b" 1fr;
grid: [linename1] "a" 100px [linename2];
grid: "a" 200px "b" min-content;
grid: "a" minmax(100px, max-content) "b" 20%;
grid: 100px / 200px;
grid: minmax(400px, min-content) / repeat(auto-fill, 50px);

/* <'grid-template-rows'> /
   [ auto-flow && dense? ] <'grid-auto-columns'>? values */
grid: 200px / auto-flow;
grid: 30% / auto-flow dense;
grid: repeat(3, [line1 line2 line3] 200px) / auto-flow 300px;
grid: [line1] minmax(20em, max-content) / auto-flow dense 40%;

/* [ auto-flow && dense? ] <'grid-auto-rows'>? /
   <'grid-template-columns'> values */
grid: auto-flow / 200px;
grid: auto-flow dense / 30%;
grid: auto-flow 300px / repeat(3, [line1 line2 line3] 200px);
grid: auto-flow dense 40% / [line1] minmax(20em, max-content);
```

### grid-area
The `grid-area` CSS *shorthand property* specifies a grid item’s size and location within a *grid* by contributing a line, a span, or nothing (automatic) to its grid placement, thereby specifying the edges of its *grid area*.
```css
/* Keyword values */
grid-area: auto;
grid-area: auto / auto;
grid-area: auto / auto / auto;
grid-area: auto / auto / auto / auto;

/* <custom-ident> values */
grid-area: some-grid-area;
grid-area: some-grid-area / another-grid-area;

/* <integer> && <custom-ident>? values */
grid-area:  4 some-grid-area;
grid-area:  4 some-grid-area / 2 another-grid-area;

/* span && [ <integer> || <custom-ident> ] values */
grid-area: span 3;
grid-area: span 3 / span some-grid-area;
grid-area: 2 span / another-grid-area span;
```

### grid-column
The `grid-column` CSS *shorthand property* specifies a grid item's size and location within a *grid column* by contributing a line, a span, or nothing (automatic) to its grid placement, thereby specifying the inline-start and inline-end edge of its *grid area*.
```css
#grid {
    display: grid;
    height: 100px;
    grid-template-columns: repeat(6, 1fr);
    grid-template-rows: 100px;
}
#item1 {
    grid-column: 2 / 4;
}
#item2 {
    grid-column: span 2 / 7;
}
```

### grid-column-start
The `grid-column-start` CSS property specifies a grid item’s start position within the grid column by contributing a line, a span, or nothing (automatic) to its grid placement. This start position defines the block-start edge of the *grid area*.
```css
/* Keyword value */
grid-column-start: auto;

/* <custom-ident> value */
grid-column-start: somegridarea;

/* <integer> + <custom-ident> values */
grid-column-start: 2;
grid-column-start: somegridarea 4;

/* span + <integer> + <custom-ident> values */
grid-column-start: span 3;
grid-column-start: span somegridarea;
grid-column-start: span somegridarea 5;
```

### grid-column-end
The `grid-column-end` CSS property specifies a grid item’s end position within the grid column by contributing a line, a span, or nothing (automatic) to its grid placement, thereby specifying the block-end edge of its *grid area*.

### grid-row
The `grid-row` CSS *shorthand property* specifies a grid item’s size and location within the grid row by contributing a line, a span, or nothing (automatic) to its grid placement, thereby specifying the inline-start and inline-end edge of its *grid area*.
```css
/* Keyword values */
grid-row: auto;
grid-row: auto / auto;

/* <custom-ident> values */
grid-row: somegridarea;
grid-row: somegridarea / someothergridarea;

/* <integer> + <custom-ident> values */
grid-row: somegridarea 4;
grid-row: 4 somegridarea / 6;

/* span + <integer> + <custom-ident> values */
grid-row: span 3;
grid-row: span somegridarea;
grid-row: 5 somegridarea span;
grid-row: span 3 / 6;
grid-row: span somegridarea / span someothergridarea;
grid-row: 5 somegridarea span / 2 span;
```

### grid-row-start
The `grid-row-start` CSS property specifies a grid item’s start position within the grid row by contributing a line, a span, or nothing (automatic) to its grid placement, thereby specifying the inline-start edge of its *grid area*.

### grid-row-end
The `grid-row-end` CSS property specifies a grid item’s end position within the grid row by contributing a line, a span, or nothing (automatic) to its grid placement, thereby specifying the inline-end edge of its *grid area*.

### grid-auto-"row/columns"
The `grid-auto-columns` CSS property specifies the size of an implicitly-created grid column *track* or pattern of tracks.
```css
/* Keyword values */
grid-auto-"row/columns": min-content;
grid-auto-"row/columns": max-content;
grid-auto-"row/columns": auto;

/* <length> values */
grid-auto-"row/columns": 100px;
grid-auto-"row/columns": 20cm;
grid-auto-"row/columns": 50vmax;

/* <percentage> values */
grid-auto-"row/columns": 10%;
grid-auto-"row/columns": 33.3%;

/* <flex> values */
grid-auto-"row/columns": 0.5fr;
grid-auto-"row/columns": 3fr;

/* minmax() values */
grid-auto-"row/columns": minmax(100px, auto);
grid-auto-"row/columns": minmax(max-content, 2fr);
grid-auto-"row/columns": minmax(20%, 80vmax);

/* fit-content() values */
grid-auto-"row/columns": fit-content(400px);
grid-auto-"row/columns": fit-content(5cm);
grid-auto-"row/columns": fit-content(20%);

/* multiple track-size values */
grid-auto-"row/columns": min-content max-content auto;
grid-auto-"row/columns": 100px 150px 390px;
grid-auto-"row/columns": 10% 33.3%;
grid-auto-"row/columns": 0.5fr 3fr 1fr;
grid-auto-"row/columns": minmax(100px, auto) minmax(max-content, 2fr) minmax(20%, 80vmax);
grid-auto-"row/columns": 100px minmax(100px, auto) 10% 0.5fr fit-content(400px);
```

### grid-template
The `grid-template` CSS property is a *shorthand property* for defining *grid columns*, *rows*, and *areas*.
```css
/* Keyword value */
grid-template: none;

/* grid-template-rows / grid-template-columns values */
grid-template: 100px 1fr / 50px 1fr;
grid-template: auto 1fr / auto 1fr auto;
grid-template: [linename] 100px / [columnname1] 30% [columnname2] 70%;
grid-template: fit-content(100px) / fit-content(40%);

/* grid-template-areas grid-template-rows / grid-template-column values */
grid-template: "a a a"
               "b b b";
grid-template: "a a a" 20%
               "b b b" auto;
grid-template: [header-top] "a a a"     [header-bottom]
                 [main-top] "b b b" 1fr [main-bottom]
                            / auto 1fr auto;

/* grid-template-areas */
grid-template-areas: "a b";
grid-template-areas: "a b b"
                     "a c d";
/* grid-template-columns */
grid-template-columns: 100px 1fr;
grid-template-columns: 200px repeat(auto-fill, 100px) 300px;
/* grid-template-rows */
grid-template-rows: 100px 1fr;
grid-template-rows: 200px repeat(auto-fill, 100px) 300px;
```

## CSS grid function
### minmax()
The `minmax()` *CSS function* defines a size range greater than or equal to min and less than or equal to max. It is used with *CSS Grids*.
```css
/* <inflexible-breadth>, <track-breadth> values */
minmax(200px, 1fr)
minmax(400px, 50%)
minmax(30%, 300px)
minmax(100px, max-content)
minmax(min-content, 400px)
minmax(max-content, auto)
minmax(auto, 300px)
minmax(min-content, auto)

/* <fixed-breadth>, <track-breadth> values */
minmax(200px, 1fr)
minmax(30%, 300px)
minmax(400px, 50%)
minmax(50%, min-content)
minmax(300px, max-content)
minmax(200px, auto)

/* <inflexible-breadth>, <fixed-breadth> values */
minmax(400px, 50%)
minmax(30%, 300px)
minmax(min-content, 200px)
minmax(max-content, 200px)
minmax(auto, 300px)
```

### repeat()
The `repeat()` *CSS function* represents a repeated fragment of the track list, allowing a large number of columns or rows that exhibit a recurring pattern to be written in a more compact form.
```css
/* <track-repeat> values */
repeat(4, 1fr)
repeat(4, [col-start] 250px [col-end])
repeat(4, [col-start] 60% [col-end])
repeat(4, [col-start] 1fr [col-end])
repeat(4, [col-start] min-content [col-end])
repeat(4, [col-start] max-content [col-end])
repeat(4, [col-start] auto [col-end])
repeat(4, [col-start] minmax(100px, 1fr) [col-end])
repeat(4, [col-start] fit-content(200px) [col-end])
repeat(4, 10px [col-start] 30% [col-middle] auto [col-end])
repeat(4, [col-start] min-content [col-middle] max-content [col-end])

/* <auto-repeat> values */
repeat(auto-fill, 250px)
repeat(auto-fit, 250px)
repeat(auto-fill, [col-start] 250px [col-end])
repeat(auto-fit, [col-start] 250px [col-end])
repeat(auto-fill, [col-start] minmax(100px, 1fr) [col-end])
repeat(auto-fill, 10px [col-start] 30% [col-middle] 400px [col-end])

/* <fixed-repeat> values */
repeat(4, 250px)
repeat(4, [col-start] 250px [col-end])
repeat(4, [col-start] 60% [col-end])
repeat(4, [col-start] minmax(100px, 1fr) [col-end])
repeat(4, [col-start] fit-content(200px) [col-end])
repeat(4, 10px [col-start] 30% [col-middle] 400px [col-end])
```

> [!TIP]
> More about > https://devdocs.io/css-grid-layout/
