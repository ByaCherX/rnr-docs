<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### Backdrop-filter
The `backdrop-filter` CSS property lets you apply graphical effects such as blurring or color shifting to the area behind an element. Because it applies to everything behind the element, to see the effect you must make the element or its background at least partially transparent.
```css
/* Keyword value */
backdrop-filter: none;

/* URL to SVG filter */
backdrop-filter: url(commonfilters.svg#filter);

/* <filter-function> values */
backdrop-filter: blur(2px);
backdrop-filter: brightness(60%);
backdrop-filter: contrast(40%);
backdrop-filter: drop-shadow(4px 4px 10px blue);
backdrop-filter: grayscale(30%);
backdrop-filter: hue-rotate(120deg);
backdrop-filter: invert(70%);
backdrop-filter: opacity(20%);
backdrop-filter: sepia(90%);
backdrop-filter: saturate(80%);

/* Multiple filters */
backdrop-filter: url(filters.svg#filter) blur(4px) saturate(150%);
```

### blur()
The `blur()` CSS function applies a Gaussian blur to the input image. Its result is a `<filter-function>`.
```css
blur(0)        /* No effect */
blur(8px)      /* Blur with 8px radius */
blur(1.17rem)  /* Blur with 1.17rem radius */
```

### drop-shadow()
The `drop-shadow()` CSS function applies a drop shadow effect to the input image. Its result is a `<filter-function>`.
```css
drop-shadow(offset-x offset-y blur-radius color)
```

### opacity()
The `opacity()` CSS function applies transparency to the samples in the input image. Its result is a `<filter-function>`.
```css
opacity(0%)   /* Completely transparent */
opacity(50%)  /* 50% transparent */
opacity(1)    /* No effect */
```



















