<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

## Motion Path

### offset
The `offset` CSS *shorthand property* sets all the properties required for animating an element along a defined path.
```css
/* Offset position */
offset: auto;
offset: 10px 30px;
offset: none;

/* Offset path */
offset: ray(45deg closest-side);
offset: path('M 100 100 L 300 100 L 200 300 z');
offset: url(arc.svg);
offset-path: path('M-70,-40 C-70,70 70,70 70,-40');

/* Offset path with distance and/or rotation */
offset: url(circle.svg) 100px;
offset: url(circle.svg) 40%;
offset: url(circle.svg) 30deg;
offset: url(circle.svg) 50px 20deg;

/* Including offset anchor */
offset: ray(45deg closest-side) / 40px 20px;
offset: url(arc.svg) 2cm / 0.5cm 3cm;
offset: url(arc.svg) 30deg / 50px 100px;

```

#### Constituent properties
This property is a shorthand for the following CSS properties:
* offset-anchor
* offset-distance
* offset-path
* offset-position
* offset-rotate

















