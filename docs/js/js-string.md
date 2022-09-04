<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

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
* String.fromCharCode()
* String.fromCodePoint()
* String.raw()

### String.fromCharCode()
Returns a string created by using the specified sequence of Unicode values.

### String.fromCodePoint()
Returns a string created by using the specified sequence of code points.

### String.raw()
Returns a string created from a raw template string.

## Instance methods
* String.prototype.at(index)
* String.prototype.charAt(index)
* String.prototype.charCodeAt(index)
* String.prototype.codePointAt(pos)
* String.prototype.concat(str,)
* String.prototype.includes(searchString [, position])
* String.prototype.endsWith(searchString [, length])
* String.prototype.indexOf(searchValue [, fromIndex])
* String.prototype.lastIndexOf(searchValue [, fromIndex])
* String.prototype.localeCompare(compareString)
* String.prototype.match(regexp)
* String.prototype.matchAll(regexp)
* String.prototype.normalize([ form])
* String.prototype.padEnd(targetLength [, padString])
* String.prototype.padStart(targetLength [, padString])
* String.prototype.repeat(count)
* String.prototype.replace(searchFor, replaceWith)
* String.prototype.replaceAll(searchFor, replaceWith)
* String.prototype.search(regexp)
* String.prototype.slice(beginIndex[,...)
* String.prototype.split([sep [,...)
* String.prototype.startsWith(searchString [, length])
* String.prototype.substring(indexStart [, indexEnd])
* String.prototype.toLocaleLowerCase( [locale, ...locales])
* String.prototype.toLocaleUpperCase( [locale, ...locales])
* String.prototype.toLowerCase()
* String.prototype.toString()
* String.prototype.toUpperCase()
* String.prototype.trim()
* String.prototype.trimStart()
* String.prototype.trimEnd()
* String.prototype.valueOf()

### String.prototype.at(index)
Returns the character (exactly one UTF-16 code unit) at the specified index. Accepts negative integers, which count back from the last string character.

### String.prototype.charAt(index)
Returns the character (exactly one UTF-16 code unit) at the specified index.

### String.prototype.charCodeAt(index)
Returns a number that is the UTF-16 code unit value at the given index.

### String.prototype.codePointAt(pos)
Returns a nonnegative integer Number that is the code point value of the UTF-16 encoded code point starting at the specified pos.

### String.prototype.concat(str,)
Combines the text of two (or more) strings and returns a new string.

### String.prototype.includes(searchString [, position])
Determines whether the calling string contains searchString.

### String.prototype.endsWith(searchString [, length])
Determines whether a string ends with the characters of the string searchString.

### String.prototype.indexOf(searchValue [, fromIndex])
Returns the index within the calling String object of the first occurrence of searchValue, or -1 if not found.

### String.prototype.lastIndexOf(searchValue [, fromIndex])
Returns the index within the calling String object of the last occurrence of searchValue, or -1 if not found.

### String.prototype.localeCompare(compareString)
Returns a number indicating whether the reference string compareString comes before, after, or is equivalent to the given string in sort order.

### String.prototype.match(regexp)
Used to match regular expression regexp against a string.

### String.prototype.matchAll(regexp)
Returns an iterator of all regexp's matches.

### String.prototype.normalize([ form])
Returns the Unicode Normalization Form of the calling string value.

### String.prototype.padEnd(targetLength [, padString])
Pads the current string from the end with a given string and returns a new string of the length targetLength.

### String.prototype.padStart(targetLength [, padString])
Pads the current string from the start with a given string and returns a new string of the length targetLength.

### String.prototype.repeat(count)
Returns a string consisting of the elements of the object repeated count times.

### String.prototype.replace(searchFor, replaceWith)
Used to replace occurrences of searchFor using replaceWith. searchFor may be a string or Regular Expression, and replaceWith may be a string or function.

### String.prototype.replaceAll(searchFor, replaceWith)
Used to replace all occurrences of searchFor using replaceWith. searchFor may be a string or Regular Expression, and replaceWith may be a string or function.

### String.prototype.search(regexp)
Search for a match between a regular expression regexp and the calling string.

### String.prototype.slice(beginIndex[,...)
Extracts a section of a string and returns a new string.

### String.prototype.split([sep [,...)
Returns an array of strings populated by splitting the calling string at occurrences of the substring sep.

### String.prototype.startsWith(searchString [, length])
Determines whether the calling string begins with the characters of string searchString.

### String.prototype.substring(indexStart [, indexEnd])
Returns a new string containing characters of the calling string from (or between) the specified index (or indices).

### String.prototype.toLocaleLowerCase( [locale, ...locales])
The characters within a string are converted to lowercase while respecting the current locale.

### String.prototype.toLocaleUpperCase( [locale, ...locales])
The characters within a string are converted to uppercase while respecting the current locale.

### String.prototype.toLowerCase()
Returns the calling string value converted to lowercase.

### String.prototype.toString()
Returns a string representing the specified object. Overrides the Object.prototype.toString() method.

### String.prototype.toUpperCase()
Returns the calling string value converted to uppercase.

### String.prototype.trim()
Trims whitespace from the beginning and end of the string. Part of the ECMAScript 5 standard.

### String.prototype.trimStart()
Trims whitespace from the beginning of the string.

### String.prototype.trimEnd()
Trims whitespace from the end of the string.

### String.prototype.valueOf()
Returns the primitive value of the specified object. Overrides the Object.prototype.valueOf() method.


