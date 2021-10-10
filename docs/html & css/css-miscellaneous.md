<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

### Containing Block
The size and position of an element are often impacted by its **containing block**. Most often, the containing block is the *content area* of an element's nearest *block-level* ancestor, but this is not always the case. In this article, we examine the factors that determine an element's containing block.</br>

When a user agent (such as your browser) lays out a document, it generates a box for every element. Each box is divided into four areas:
1. Content area
1. Padding area
1. Border area
1. Margin area

:::image type="content" source="../media/css-box-model.png" alt-text="containing_block":::

#### Identifying the containing block

The process for identifying the containing block depends entirely on the value of the element's *position* property:

1. If the `position` property is `static`, `relative`, or `sticky`, the containing block is formed by the edge of the content box of the nearest ancestor element that is either **a block container** (such as an inline-block, block, or list-item element) or establishes a formatting context (such as a table container, flex container, grid container, or the block container itself).

1. If the `position` property is `absolute`, the containing block is formed by the edge of the padding box of the nearest ancestor element that has a position value other than `static` (`fixed`, `absolute`, `relative`, or `sticky`).

1. If the `position` property is `fixed`, the containing block is established by the viewport (in the case of continuous media) or the page area (in the case of paged media).

1. If the `position` property is `absolute` or `fixed`, the containing block may also be formed by the edge of the padding box of the nearest ancestor element that has the following:</br>
<span class="c1s1">a.</span> A transform or perspective value other than none</br>
<span class="c1s1">b.</span> A will-change value of transform or perspective</br>
<span class="c1s1">c.</span> A filter value other than none or a will-change value of filter (only works on Firefox).</br>
<span class="c1s1">d.</span> A contain value of paint (e.g. contain: paint;)</br>

### CSS Length
The `<length>` CSS data type represents a distance value. Lengths can be used in numerous CSS properties, such as width, height, margin, padding, border-width, font-size, and text-shadow.

<span class="c1s1">**Relative length units**</span></br>
Relative lengths represent a measurement in terms of some other distance. Depending on the unit, this can be the size of a specific character, the line height, or the size of the viewport.

<span class="c1s1">**Font-relative lengths**</span></br>
Font-relative lengths define the <length> value in terms of the size of a particular character or font attribute in the font currently in effect in an element or its parent.

### CSS Text
**CSS Text** is a module of CSS that defines how to perform text manipulation, like line breaking, justification and alignment, white space handling, and text transformation.

<div class="index"> <ul> 
 <li><a href="hanging-punctuation"><code>hanging-punctuation</code></a></li> <li><a href="hyphens"><code>hyphens</code></a></li> <li><a href="letter-spacing"><code>letter-spacing</code></a></li> <li><a href="line-break"><code>line-break</code></a></li> <li><a href="overflow-wrap"><code>overflow-wrap</code></a></li> <li><a href="tab-size"><code>tab-size</code></a></li> <li><a href="text-align"><code>text-align</code></a></li> <li><a href="text-align-last"><code>text-align-last</code></a></li> <li><a href="text-indent"><code>text-indent</code></a></li> <li><a href="text-justify"><code>text-justify</code></a></li> <li><a href="text-size-adjust"><code>text-size-adjust</code></a></li> <li><a href="text-transform"><code>text-transform</code></a></li> <li><a href="white-space"><code>white-space</code></a></li> <li><a href="word-break"><code>word-break</code></a></li> <li><a href="word-spacing"><code>word-spacing</code></a></li> 
</ul> </div>

---
<div class="index"> <ul> <li>
 <a href="letter-spacing"><code>letter-spacing</code></a></li> <li><a href="text-align"><code>text-align</code></a></li> <li><a href="text-decoration"><code>text-decoration</code></a></li> <li><a href="text-decoration-color"><code>text-decoration-color</code></a></li> <li><a href="text-decoration-line"><code>text-decoration-line</code></a></li> <li><a class="page-not-created"><code>text-decoration-offset</code></a></li> <li><a href="text-decoration-skip-ink"><code>text-decoration-skip-ink</code></a></li> <li><a href="text-decoration-style"><code>text-decoration-style</code></a></li> <li><a href="text-decoration-thickness"><code>text-decoration-thickness</code></a></li> <li><a href="text-emphasis"><code>text-emphasis</code></a></li> <li><a href="text-emphasis-color"><code>text-emphasis-color</code></a></li> <li><a href="text-emphasis-position"><code>text-emphasis-position</code></a></li> <li><a href="text-emphasis-style"><code>text-emphasis-style</code></a></li> <li><a href="text-indent"><code>text-indent</code></a></li> <li><a href="text-rendering"><code>text-rendering</code></a></li> <li><a href="text-shadow"><code>text-shadow</code></a></li> <li><a href="text-transform"><code>text-transform</code></a></li> <li><a href="white-space"><code>white-space</code></a></li> <li><a href="word-spacing"><code>word-spacing</code></a></li> 
</ul> </div>

> [!NOTE]
> The document of this section is given in devdocs.io  (https://devdocs.io/css/css_text & https://devdocs.io/css/css_text_decoration)

### text-overflow
The `text-overflow` CSS property sets how hidden overflow content is signaled to users. It can be clipped, display an ellipsis ('…'), or display a custom string.
```css
text-overflow: clip;
text-overflow: ellipsis;
text-overflow: "";
```




