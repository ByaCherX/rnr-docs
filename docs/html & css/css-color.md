<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

## Color
The `color` CSS property sets the foreground color value of an element's text and text decorations, and sets the `<currentcolor>` value. `currentcolor` may be used as an indirect value on other properties and is the default for other color properties, such as border-color.
```css
/* Keyword values */
color: currentcolor;

/* <named-color> values */
color: red;

/* <hex-color> values */
color: #090;
color: #009900;
color: #090a;
color: #009900aa;

/* <rgb()> values */
color: rgb(34, 12, 64, 0.6);
color: rgb(34 12 64 / 0.6);
color: rgb(34.0 12 64 / 60%);

/* <hsl()> values */
color: hsl(30, 100%, 50%, 0.6);
```

### Color keywords
Color keywords are case-insensitive identifiers that represent a specific color, such as `red, blue, black, or lightseagreen`. Although the names more or less describes their respective colors, they are essentially artificial, without a strict rationale behind the names used.
Several keywords are aliases for each other:
  * `aqua` / `cyan`
  * `fuchsia` / `magenta`
  * `darkgray` / `darkgrey`
  * `darkslategray` / `darkslategrey`
  * `dimgray` / `dimgrey`
  * `lightgray` / `lightgrey`
  * `lightslategray` / `lightslategrey`
  * `gray` / `grey`
  * `slategray` / `slategrey`

### RGB colors
The RGB color model defines a given color according to its red, green, and blue components. An optional alpha component represents the color's transparency.

<h5 style="color:cadetblue">Hexadecimal notation: #RRGGBB[AA]</h5>
R (red), G (green), B (blue), and A (alpha) are hexadecimal characters (0–9, A–F). A is optional. For example, #ff0000 is equivalent to #ff0000ff.

<h5 style="color:cadetblue">Hexadecimal notation: #RGB[A]</h5>
<lk class="redcolor">R</lk> (red), <lk class="greencolor">G</lk> (green), <lk class="bluecolor">B</lk> (blue), and A (alpha) are hexadecimal characters (0–9, A–F). A is optional. The three-digit notation (<l>#<lk class="redcolor">R</lk><lk class="greencolor">G</lk><lk class="bluecolor">B</lk></l>) is a shorter version of the six-digit form (#RRGGBB). For example, #f09 is the same color as #ff0099. Likewise, the four-digit RGB notation (#RGBA) is a shorter version of the eight-digit form (#RRGGBBAA). For example, #0f38 is the same color as #00ff3388.

<h5 style="color:cadetblue">Functional notation: rgb[a](R, G, B[, A])</h5>
R (red), G (green), and B (blue) can be either < number>s or < percentage>s, where the number 255 corresponds to 100%. A (alpha) can be a < number> between 0 and 1, or a < percentage>, where the number 1 corresponds to 100% (full opacity).

<h5 style="color:cadetblue">Functional notation: rgb[a](R G B[ / A])</h5>
CSS Colors Level 4 adds support for space-separated values in the functional notation.


### HSL colors
The HSL color model defines a given color according to its hue, saturation, and lightness components. An optional alpha component represents the color's transparency.

Many designers find HSL more intuitive than RGB, since it allows hue, saturation, and lightness to each be adjusted independently. HSL can also make it easier to create a set of matching colors (such as when you want multiple shades of a single hue).

<h5 style="color:cadetblue">Functional notation: hsl[a](H, S, L[, A])</h5>
H (hue) is an < angle> of the color circle given in degs, rads, grads, or turns in CSS Color Module Level 4. When written as a unitless < number>, it is interpreted as degrees, as specified in CSS Color Module Level 3. By definition, red=0deg=360deg, with the other colors spread around the circle, so green=120deg, blue=240deg, etc. As an < angle>, it implicitly wraps around such that -120deg=240deg, 480deg=120deg, -1turn=1turn, etc.

S (saturation) and L (lightness) are percentages. 100% saturation is completely saturated, while 0% is completely unsaturated (gray). 100% lightness is white, 0% lightness is black, and 50% lightness is “normal.”

A (alpha) can be a < number> between 0 and 1, or a < percentage>, where the number 1 corresponds to 100% (full opacity).

### Opacity
The `opacity` CSS property sets the opacity of an element. Opacity is the degree to which content behind an element is hidden, and is the opposite of transparency.
```css
opacity: 0.5;
```

> [!TIP]
> For more information https://devdocs.io/css/color_value
