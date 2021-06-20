<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<img src="../../media/index/markdown-mark-white.svg" alt="MarkdownLogo" class="center">
<h1 style="text-align: center">Markdown Language Documents <sub class="trlng">US</sub> </h1>

## What is Markdown 
---
Markdown is a lightweight markup language that you can use to add formatting elements to plaintext text documents. Created by John Gruber in 2004, Markdown is now one of the world’s most popular markup languages.

## Why use Markdowm
---
- Markdown can be used for everything. People use it to create websites, documents, notes, books, presentations, email messages, and technical documentation.

- Markdown is portable. Files containing Markdown-formatted text can be opened using virtually any application. If you decide you don’t like the Markdown application you’re currently using, you can import your Markdown files into another Markdown application. That’s in stark contrast to word processing applications like Microsoft Word that lock your content into a proprietary file format.

- Markdown is platform independent. You can create Markdown-formatted text on any device running any operating system.

- Markdown is future proof. Even if the application you’re using stops working at some point in the future, you’ll still be able to read your Markdown-formatted text using a text editing application. This is an important consideration when it comes to books, university theses, and other milestone documents that need to be preserved indefinitely.

- Markdown is everywhere. Websites like Reddit and GitHub support Markdown, and lots of desktop and web-based applications support it.

## How Does it Work?
---
Markdown applications use something called a Markdown processor (also commonly referred to as a “parser” or an “implementation”) to take the Markdown-formatted text and output it to HTML format. At that point, your document can be viewed in a web browser or combined with a style sheet and printed. You can see a visual representation of this process below.

### What does Markdown do?
---
Markdown is a fast and easy way to take notes, create content for a website, and produce print-ready documents.

It doesn’t take long to learn the Markdown syntax, and once you know how to use it, you can write using Markdown just about everywhere. Most people use Markdown to create content for the web, but Markdown is good for formatting everything from email messages to grocery lists.

### Support Markdown
---
for more information see ['markdown-support.md'](markdown-support.md) .

<h1 class="h1color" style="text-align:center">Basic Syntax</h1> <i class="fab fa-aws"></i>

---

> It features the basic syntax outlined in John Gruber's original design document. There are minor inconsistencies and inconsistencies between Markdown operations - they are ideal for that. they are not inline.

## Header
---
To create a heading, add number signs (#) in front of a word or phrase. The number of number signs you use should correspond to the heading level. For example, to create a heading level three (`<h3>`), use three number signs (e.g., ### My Header).

| Markdown               | HTML                       | Rendered Output          |
|------------------------|----------------------------|--------------------------|
| # Heading level 1      | `<h1>Heading level 1</h1>` | <h1>Heading level 1</h1> |
| ## Heading level 2     | `<h2>Heading level 2</h2>` | <h2>Heading level 2</h2> |
| ### Heading level 3    | `<h3>Heading level 3</h3>` | <h3>Heading level 3</h3> |
| #### Heading level 4   | `<h4>Heading level 4</h4>` | <h4>Heading level 4</h4> |
| ##### Heading level 5  | `<h5>Heading level 5</h5>` | <h5>Heading level 5</h5> |
| ###### Heading level 6 | `<h6>Heading level 6</h6>` | <h6>Heading level 6</h6> |

## Alternate Syntax
---
Alternatively, on the line below the text, add any number of == characters for heading level 1 or -- characters for heading level 2.

| Markdown                               | HTML                       | Rendered Output          |
|----------------------------------------|----------------------------|--------------------------|
| Heading level 1</br> ==========        | `<h1>Heading level 1</h1>` | <h1>Heading level 1</h1> |
| Heading level 2</br> ----------------- | `<h2>Heading level 2</h2>` | <h2>Heading level 2</h2> |

## Paragraphs
---
To create paragraphs, use a blank line to separate one or more lines of text.

| Markdown | HTML |
|----------|------|
|I really like using Markdown.</br></br>I think I'll use it to format all of my documents from now on.|	`<p>I really like using Markdown.</p>`</br></br>`<p>I think I'll use it to format all of my documents from now on.</p>`|

## Line Breaks
---
To create a line break (`<br>`), end a line with two or more spaces, and then type return.

| Markdown | HTML |
|----------|------|
|This is the first line.</br>And this is the second line.|`<p>This is the first line.<br>`</br>`And this is the second line.</p>`|

## Bold text
---
To bold text, add two asterisks or underscores before and after a word or phrase. To bold the middle of a word for emphasis, add two asterisks without spaces around the letters.

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|I just love `**bold text**`. | `I just love <strong>bold text</strong>.` | I just love **bold text.**|
|I just love `__bold text__`. | `I just love <strong>bold text</strong>.` | I just love __bold text.__|
|Love`**is**`bold | `Love<strong>is</strong>bold` | Love**is**bold|

## Italic
---
To italicize text, add one asterisk or underscore before and after a word or phrase. To italicize the middle of a word for emphasis, add one asterisk without spaces around the letters.

|Markdown | Html |Rendered Output  |
|---------|------|-----------------|
|Italicized text is the `*cat's meow*`. |Italicized text is the `<em>cat's meow</em>`.|Italicized text is the *cat’s meow*.|
|Italicized text is the `_cat's meow_`. |Italicized text is the `<em>cat's meow</em>`.|Italicized text is the *cat’s meow*.|
|A`*cat*`meow |A`<em>cat</em>`meow|A*cat*meow|
 
## Bold and Italic
---
To emphasize text with bold and italics at the same time, add three asterisks or underscores before and after a word or phrase. To bold and italicize the middle of a word for emphasis, add three asterisks without spaces around the letters.

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|This text is `***really important***`. | `This text is <strong><em>really important</em></strong>`. | This text is ***really important***.|

## Blockquotes
---
To create a blockquote, add a `>` in front of a paragraph.

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|> Hello world | `<blockquote>Hello world</blockquote>` | <blockquote>Hello world</blockquote> |
|> Hello</br>></br>> world | `<blockquote> <p>Hello</p><p>world</p> </blockquote>` | <blockquote><p>Hello</p><p>world</p></blockquote> |
|> Hello</br>>> world | `<blockquote> <p>Hello</p><blockquote>world</blockquote> </blockquote>` | <blockquote><p>Hello</p><blockquote>world</blockquote></blockquote> |
|> #### Header</br>> - hello</br>> *world | `<blockquote>`</br>`<h4><p>Header</p></h4> <ul><li>text1</li> <li>text2</li></ul>`</br>`</blockquote>` | <blockquote><h4><p>Header</p></h4><ul><li>text1</li><li>text2</li></ul></blockquote> |

## Lists
---
| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|1. first item</br>2. second item</br>---1. Indented item</br>3. third item | `<ol>`</br>`<li>First item</li><li>Second item</li>`</br>`<ol><li>Indented item</li></ol></li>`</br>`<li>Third item</li>`</br>`</ol>` | <ol><li>First item</li><li>Second item</li><ol><li>Indented item</li></ol></li><li>third item</li></ol> |
|1. first item</br>1. seond item</br>1. third item | `<ol>`</br>`<li>First item</li><li>Second item</li><li>Third item</li>`</br>`</ol>` | <ol><li>First item</li><li>Second item</li><li>Third item</li></ol> |
|- First item</br>* Second item</br>+ Third item</br> ///- Indented item| `<ul>`</br>`<li>First item</li><li>Second item</li><li>Third item`</br>`<ul><li>Indented item</li></ul></li>`</br>`</ul>` | <ul><li>First item</li><li>Second item</li><li>Third item<ul><li>Indented item</li></ul></li></ul> |

## Code Blocks
---

To denote a word or phrase as code, enclose it in backticks (`).

other example

        <html>
          <head>
            <title>Test</title>
          </head>


| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
| At the command prompt, type \`nano.\` | At the command prompt, type `<code>nano</code>.` | At the command prompt, type `nano.` |

## Images
---
You can add a photo as in the example. `![markdown svg logo](../../media/index/markdown-mark.svg)`
the result will be like this <img src="../../media/index/markdown-mark.svg" style="width: 90px;">

## Links
---
To create a link, enclose the link text in brackets (e.g., [github]) and then follow it immediately with the URL in parentheses (e.g., (https://github.com)).

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|`[github](https://github.com)`|`<a href="https://github.com">github</a>`|[github](https://github.com)|
|`[github](https://github.com "this is github link")`|`<a href="https://github.com">github</a>`|[github](https://github.com "this is github link")|
|`<https://github.com>`| - |<https://github.com>|
|`**[github link](https://github.com)**`| - |**[github link](https://github.com)**|
| [![image](/assets/images/shiprock.jpg "text")](link) | - | - |

## Escaping Chracters
To display a literal character that would otherwise be used to format text in a Markdown document, add a backslash (`\`) in front of the character.

| Character | Name                                           |
|-----------|------------------------------------------------|
| \         | backslash                                      |
| `         | backtick (see also escaping backticks in code) |
| *         | asterisk                                       |
| _         | underscore                                     |
| { }       | curly braces                                   |
| [ ]       | brackets                                       |
| < >       | angle brackets                                 |
| ( )       | parentheses                                    |
| #         | pound sign                                     |
| +         | plus sign                                      |
| -         | minus sign (hyphen)                            |
| .         | dot                                            |
| !         | exclamation mark                               |
|\|         | pipe (see also escaping pipe in tables)        |


<h1 class="h1color" style="text-align:center">Compatibility recommendations</h1>

### Header Practices
Markdown applications don’t agree on how to handle a missing space between the number signs (`#`) and the heading name. For compatibility, always put a space between the number signs and the heading name.

| ✅ Do this         | ❌ Don't do this |
|--------------------|-------------------|
| # Here's a Heading | #Here's a Heading |

### Italic Practices
Markdown applications don’t agree on how to handle underscores in the middle of a word. For compatibility, use asterisks to italicize the middle of a word for emphasis.

| ✅ Do this  | ❌ Don't do this  |
|------------- |-------------------|
| A`*cat*`meow | A`_cat_`meow      |

### Link Practices
Markdown applications don’t agree on how to handle spaces in the middle of a URL. For compatibility, try to URL encode any spaces with %20.

| ✅ Do this | ❌ Don't do this |
|------------ |------------------|
| `[link](https://www.example.com/my%20great%20page)` | `[link](https://www.example.com/my great page)`|






