<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### aspect-ratio
The `aspect-ratio` CSS property sets a preferred aspect ratio for the box, which will be used in the calculation of auto sizes and some other layout functions.
```css
aspect-ratio: 1 / 1;
```

### box-sizing
The `box-sizing` CSS property sets how the total width and height of an element is calculated.
```css
div {
  width: 160px;
  height: 80px;
  padding: 20px;
  border: 8px solid red;
  background: yellow;
}

.content-box {
  box-sizing: content-box;
  /* Total width: 160px + (2 * 20px) + (2 * 8px) = 216px
     Total height: 80px + (2 * 20px) + (2 * 8px) = 136px
     Content box width: 160px
     Content box height: 80px */
}

.border-box {
  box-sizing: border-box;
  /* Total width: 160px
     Total height: 80px
     Content box width: 160px - (2 * 20px) - (2 * 8px) = 104px
     Content box height: 80px - (2 * 20px) - (2 * 8px) = 24px */
}
```

By default in the CSS box model, the `width` and `height` you assign to an element is applied only to the element's content box. If the element has any border or padding, this is then added to the `width` and `height` to arrive at the size of the box that's rendered on the screen. This means that when you set `width` and `height`, you have to adjust the value you give to allow for any border or padding that may be added. For example, if you have four boxes with `width: 25%;`, if any has left or right padding or a left or right border, they will not by default fit on one line within the constraints of the parent container.

### column-width
The `column-width` CSS property sets the ideal column width in a multi-column layout. The container will have as many columns as can fit without any of them having a width less than the `column-width` value. If the width of the container is narrower than the specified value, the single column's width will be smaller than the declared column width.
```css
/* Keyword value */
column-width: auto;

/* <length> values */
column-width: 60px;
column-width: 15.5em;
column-width: 3.3vw;
```

### fit-content
The `fit-content` behaves as `fit-content(stretch)`. In practice this means that the box will use the available space, but never more than max-content.

### fit-content()
The `fit-content()` CSS function clamps a given size to an available size according to the formula `min(maximum size, max(minimum size, argument)).`
```css
/* <length> values */
fit-content(length)

/* <percentage> value */
fit-content(40%)
```

### height
The `height` CSS property specifies the height of an element. By default, the property defines the height of the content area. If box-sizing is set to `border-box`, however, it instead determines the height of the border area.
```css
/* <length> values */
height: 120px;

/* <percentage> value */
height: 75%;

/* Keyword values */
height: max-content;
height: min-content;
height: fit-content(20em);
height: auto;
```

### width
The `width` CSS property sets an element's width. By default, it sets the width of the content area, but if box-sizing is set to `border-box`, it sets the width of the border area.

### max-height
The `max-height` CSS property sets the maximum height of an element. It prevents the used value of the height property from becoming larger than the value specified for `max-height`.
```css
/* <length> value */
max-height: 3.5em;

/* <percentage> value */
max-height: 75%;

/* Keyword values */
max-height: none;
max-height: max-content;
max-height: min-content;
max-height: fit-content(20em);
```

### max-width
The `max-width` CSS property sets the maximum width of an element. It prevents the used value of the width property from becoming larger than the value specified by `max-width`.

### min-height
The `min-height` CSS property sets the minimum height of an element. It prevents the used value of the height property from becoming smaller than the value specified for `min-height`.

### min-width
The `min-width` CSS property sets the minimum width of an element. It prevents the used value of the width property from becoming smaller than the value specified for `min-width`.

> [!TIP]
> For more information https://devdocs.io/css/box-sizing










