<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

<h2 style="text-align:center">Relative length units</h2>

| Unit | Relative to       |
|------|-------------------|
| em   | Font size of the element.|
| ex   | x-height of the element's font.|
| cap  | Cap height (the nominal height of capital letters) of the element's font.|
| ch   | Average character advance of a narrow glyph in the element’s font, as represented by the “0” (ZERO, U | +0030) glyph.|
| ic   | Average character advance of a full width glyph in the element’s font, as represented by the “水” (CJK | water | ideograph, U+6C34) glyph.|
| rem  | Font size of the root element.|
| lh   | Line height of the element.|
| rlh  | Line height of the root element.|
| vw   | 1% of viewport's width.|
| vh   | 1% of viewport's height.|
| vi   | 1% of viewport's size in the root element's inline axis.|
| vb   | 1% of viewport's size in the root element's block axis.|
| vmin | 1% of viewport's smaller dimension.|
| vmax | 1% of viewport's larger dimension.|

<h2>Absolute length units</h2>

| Unit | Name                | Equivalent to       |
|------|---------------------|---------------------|
| cm   | Centimeters         | 1cm = 96px/2.54     |
| mm   | Millimeters         | 1mm = 1/10th of 1cm |
| Q    | Quarter-millimeters | 1Q = 1/40th of 1cm  |
| in   | Inches              | 1in = 2.54cm = 96px |
| pc   | Picas               | 1pc = 1/16th of 1in |
| pt   | Points              | 1pt = 1/72th of 1in |
| px   | Pixels              | 1px = 1/96th of 1in |

### Angle units

Angle values are represented by the type `<angle>` and accept the following values:

| Unit | Name     | Description                              |
|------|----------|------------------------------------------|
| deg  | Degrees  | There are 360 degrees in a full circle.  |
| grad | Gradians | There are 400 gradians in a full circle. |
| rad  | Radians  | There are 2π radians in a full circle.   |
| turn | Turns    | There is 1 turn in a full circle.        |

### Time units
Time values are represented by the type `<time>`. When including a time value, the unit identifier -- the s or ms -- is required. It accepts the following values.

| Unit | Name         | Description                               |
|------|--------------|-------------------------------------------|
| s    | Seconds      |                                           |
| ms   | Milliseconds | There are 1,000 milliseconds in a second. |

| Unit | Name      | Description                                     |
|------|-----------|-------------------------------------------------|
| Hz   | Hertz     | Represents the number of occurrences per second.|
| kHz  | KiloHertz | A kiloHertz is 1000 Hertz.                      |

`1Hz`, which can also be written as 1hz or 1HZ, is one cycle per second.

<h3>Resolution unit</h3>

Resolution units are represented by the type `<resolution>`. They represent the size of a single dot in a graphical representation, such as a screen, by indicating how many of these dots fit in a CSS inch, centimeter, or pixel. It accepts the following values:

| Unit  | Description          |
|-------|----------------------|
| dpi   | Dots per inch.       |
| dpcm  | Dots per centimeter. |
|dppx, x| Dots per px unit.    |








