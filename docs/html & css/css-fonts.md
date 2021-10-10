<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### CSS Fonts
**CSS Fonts** is a module of CSS that defines font-related properties and how font resources are loaded. It lets you define the style of a font, such as its family, size and weight, line height, and the glyph variants to use when multiple are available for a single character.
```css
font-family: "Helvetica Neue", "Arial", sans-serif;
font-style: italic;
font-weight: 100;
font-variant-ligatures: normal;
font-size: 2rem;
```

#### Font properties
* font
* font-family
* font-feature-settings
* font-kerning
* font-language-override
* font-optical-sizing
* font-size
* font-size-adjust
* font-stretch
* font-style
* font-synthesis
* font-variant
* font-variant-alternates
* font-variant-caps
* font-variant-east-asian
* font-variant-ligatures
* font-variant-numeric
* font-variant-position
* font-variation-settings
* font-weight
* line-height

### font-family
The `font-family` CSS property specifies a prioritized list of one or more font family names and/or generic family names for the selected element.
```css
/* A font family name and a generic family name */
font-family: Gill Sans Extrabold, sans-serif;
font-family: "Goudy Bookletter 1911", sans-serif;

/* A generic family name only */
font-family: serif;
font-family: sans-serif;
font-family: monospace;
font-family: cursive;
font-family: fantasy;
font-family: system-ui;
font-family: ui-serif;
font-family: ui-sans-serif;
font-family: ui-monospace;
font-family: ui-rounded;
font-family: emoji;
font-family: math;
font-family: fangsong;
```

### font-size
The `font-size` CSS property sets the size of the font. Changing the font size also updates the sizes of the font size-relative `<length>` units, such as `em`, `ex`, and so forth.

```css
/* <absolute-size> values */
font-size: small;
font-size: medium;
font-size: large;

/* <relative-size> values */
font-size: smaller;

/* <length> values */
font-size: 12px;

/* <percentage> values */
font-size: 80%;
```

### font-style
The `font-style` CSS property sets whether a font should be styled with a normal, italic, or oblique face from its font-family.
```css
font-style: normal;
font-style: italic;
font-style: oblique;
font-style: oblique 10deg;
```

### font-weight
The `font-weight` CSS property sets the weight (or boldness) of the font. The weights available depend on the font-family that is currently set.
```css
/* Keyword values */
font-weight: normal;
font-weight: bold;

/* Keyword values relative to the parent */
font-weight: lighter;
font-weight: bolder;

/* Numeric keyword values */
font-weight: 100;
font-weight: 400;// normal
font-weight: 700;// bold
font-weight: 900;
```






















