<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

## Multi Column Layout

### columns
The `columns` CSS shorthand property sets the number of columns to use when drawing an element's contents, as well as those columns' widths.
```css
/* Column width */
columns: 18em;

/* Column count */
columns: auto;
columns: 2;

/* Both column width and count */
columns: 2 auto;
columns: auto 12em;
columns: auto auto;
```

### column-count
The `column-count` *CSS* property breaks an element's content into the specified number of columns.
```css
/* Keyword value */
column-count: auto;

/* <integer> value */
column-count: 3;
```

### column-fill
The `column-fill` CSS property controls how an element's contents are balanced when broken into columns.
```css
/* Keyword values */
column-fill: auto;
column-fill: balance;
column-fill: balance-all;
```

### column-rule
The `column-rule` *shorthand CSS* property sets the width, style, and color of the line drawn between columns in a multi-column layout.
```css
column-rule: dotted;
column-rule: solid 8px;
column-rule: solid blue;
column-rule: thick inset blue;
```















