<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/js_style.css">

## Description
Strings are useful for holding data that can be represented in text form. Some of the most-used operations on strings are to check their length, to build and concatenate them using the *+ and += string operators*, checking for the existence or location of substrings with the indexOf() method, or extracting substrings with the `substring()` method.

## Constructor

### String() constructor
The `String` constructor is used to create a new String object. When called instead as a function, it performs type conversion to a *primitive string*, which is usually more useful.
```js
new String(thing)
String(thing)

// example
const string1 = "A string primitive";
const string2 = 'Also a string primitive';
const string3 = `Yet another string primitive`;

// type of String
typeof String('Hello world'); // string
typeof new String('Hello world'); // object
```

#### Escape sequences

|Escape sequence  | Unicode code point  |
|-----------------|---------------------|
| \0	 | null character (U+0000 NULL)|
| \'	 | single quote (U+0027 APOSTROPHE)|
| \"	 | double quote (U+0022 QUOTATION MARK)|
| `\\`| backslash (U+005C REVERSE SOLIDUS)|
| \n	 | newline (U+000A LINE FEED; LF)|
| \r	 | carriage return (U+000D CARRIAGE RETURN; CR)|
| \v	 | vertical tab (U+000B LINE TABULATION)|
| \t	 | tab (U+0009 CHARACTER TABULATION)|
| \b	 | backspace (U+0008 BACKSPACE)|
| \f	 | form feed (U+000C FORM FEED)|
| \uXXXX </br>…where XXXX is exactly 4 hex digits in the range 0000–FFFF; e.g., \u000A is the same as \n (LINE FEED); \u0021 is "!"	|Unicode code point between U+0000 and U+FFFF (the Unicode Basic Multilingual Plane)|
| \u{X}…\u{XXXXXX} </br>…where X…XXXXXX is 1–6 hex digits in the range 0–10FFFF; e.g., \u{A} is the same as \n (LINE FEED); \u{21} is "!"	|Unicode code point between U+0000 and U+10FFFF (the entirety of Unicode)|
| \xXX </br> …where XX is exactly 2 hex digits in the range 00–FF; e.g., \x0A is the same as \n (LINE FEED); \x21 is "!"	|Unicode code point between U+0000 and U+00FF (the Basic Latin and Latin-1 Supplement blocks; equivalent to ISO-8859-1)|

## Static methods
...


## Instance properties
...


## Instance methods
...



