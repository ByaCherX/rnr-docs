<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Regular expressions</h1>

Regular expressions are patterns used to match character combinations in strings. In JavaScript, regular expressions are also objects. These patterns are used with the `exec()` and `test()` methods of `RegExp`, and with the `match()`, `matchAll()`, `replace()`, `replaceAll()`, `search()`, and `split()` methods of String. This chapter describes JavaScript regular expressions.

## Creating a regular expression
You construct a regular expression in one of two ways:

* Using a regular expression literal, which consists of a pattern enclosed between slashes, as follows:
```js
const re = /ab+c/;
```
Regular expression literals provide compilation of the regular expression when the script is loaded. If the regular expression remains constant, using this can improve performance.

* Or calling the constructor function of the ``RegExp`` object, as follows
```js
const re = new RegExp('ab+c');
```
Using the constructor function provides runtime compilation of the regular expression. Use the constructor function when you know the regular expression pattern will be changing, or you don't know the pattern and are getting it from another source, such as user input.

## Writing a regular expression pattern
A regular expression pattern is composed of simple characters, such as `/abc/`, or a combination of simple and special characters, such as `/ab*c/` or `/Chapter (\d+)\.\d*/`. The last example includes parentheses, which are used as a memory device. The match made with this part of the pattern is remembered for later use, as described in Using groups.

### Using simple patterns
Simple patterns are constructed of characters for which you want to find a direct match. For example, the pattern `/abc/` matches character combinations in strings only when the exact sequence `"abc"` occurs (all characters together and in that order). Such a match would succeed in the strings `"Hi, do you know your abc's?" and "The latest airplane designs evolved from slabcraft."`. In both cases the match is with the substring `"abc"`. There is no match in the string `"Grab crab"` because while it contains the substring `"ab c"`, it does not contain the exact substring "abc".

### Using special characters
When the search for a match requires something more than a direct match, such as finding one or more b's, or finding white space, you can include special characters in the pattern. For example, to match a single `"a"` followed by zero or more `"b"`s followed by `"c"`, you'd use the pattern `/ab*c/`: the `*` after `"b"` means "0 or more occurrences of the preceding item." In the string `"cbbabbbbcdebc"`, this pattern will match the substring `"abbbbc"`.

[Assertions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_Expressions/Assertions)
Assertions include boundaries, which indicate the beginnings and endings of lines and words, and other patterns indicating in some way that a match is possible (including look-ahead, look-behind, and conditional expressions).

[Character classes](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_Expressions/Character_Classes)
Distinguish different types of characters. For example, distinguishing between letters and digits.

[Groups and ranges](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_Expressions/Groups_and_Ranges)
Indicate groups and ranges of expression characters.

[Quantifiers](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_Expressions/Quantifiers)
Indicate numbers of characters or expressions to match.

[Unicode property escapes](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_Expressions/Unicode_Property_Escapes)
Distinguish based on unicode character properties, for example, upper- and lower-case letters, math symbols, and punctuation.

### Escaping
If you need to use any of the special characters literally (actually searching for a `"*"`, for instance), you must escape it by putting a backslash in front of it. For instance, to search for `"a"` followed by `"*"` followed by `"b"`, you'd use `/a\*b/` — the backslash "escapes" the `"*"`, making it literal instead of special.

Similarly, if you're writing a regular expression literal and need to match a slash ("/"), you need to escape that (otherwise, it terminates the pattern). For instance, to search for the string "/example/" followed by one or more alphabetic characters, you'd use ``/\/example\/[a-z]+/i``—the backslashes before each slash make them literal.

To match a literal backslash, you need to escape the backslash. For instance, to match the string "C:\" where "C" can be any letter, you'd use ``/[A-Z]:\\/`` — the first backslash escapes the one after it, so the expression searches for a single literal backslash.

If using the `RegExp` constructor with a string literal, remember that the backslash is an escape in string literals, so to use it in the regular expression, you need to escape it at the string literal level. `/a\*b/` and `new RegExp("a\\*b")` create the same expression, which searches for "a" followed by a literal "*" followed by "b".

If escape strings are not already part of your pattern you can add them using `String.replace`:
```js
function escapeRegExp(string) {
  return string.replace(/[.*+?^${}()|[\]\\]/g, '\\$&'); // $& means the whole matched string
}
```
The "g" after the regular expression is an option or flag that performs a global search, looking in the whole string and returning all matches. It is explained in detail below in Advanced Searching With Flags.

Why isn't this built into JavaScript? There is a proposal to add such a function to RegExp, but it was rejected by TC39.

### Using regular expressions in JavaScript
Regular expressions are used with the `RegExp` methods `test()` and `exec()` and with the `String` methods `match()`, `replace()`, `search()`, and `split()`.

|Method      |Description  |
|------------|-------------|
|exec()      |Executes a search for a match in a string. It returns an array of information or null on a mismatch.|
|test()      |Tests for a match in a string. It returns true or false.|
|match()     |Returns an array containing all of the matches, including capturing groups, or null if no match is found.|
|matchAll()  |Returns an iterator containing all of the matches, including capturing groups.|
|search()    |Tests for a match in a string. It returns the index of the match, or -1 if the search fails.|
|replace()   |Executes a search for a match in a string, and replaces the matched substring with a replacement substring.|
|replaceAll()|Executes a search for all matches in a string, and replaces the matched substrings with a replacement substring.|
|split()     |Uses a regular expression or a fixed string to break a string into an array of substrings.|

<h1 style="text-align:center">Assertions</h1>

Assertions include boundaries, which indicate the beginnings and endings of lines and words, and other patterns indicating in some way that a match is possible (including look-ahead, look-behind, and conditional expressions).

### Types

|Chracters  |Meaning  |
|---------|---------|
|^     | Matches the beginning of input. If the multiline flag is set to true, also matches immediately after a line break character. For example, ``/^A/`` does not match the "A" in "an A", but does match the first "A" in "An A".|
|$     | Matches the end of input. If the multiline flag is set to true, also matches immediately before a line break character. For example, ``/t$/`` does not match the "t" in "eater", but does match it in "eat".|
|\b  | Matches a word boundary. This is the position where a word character is not followed or preceded by another word-character, such as between a letter and a space. Note that a matched word boundary is not included in the match. In other words, the length of a matched word boundary is zero.|
|\B  | Matches a non-word boundary. This is a position where the previous and next character are of the same type: Either both must be words, or both must be non-words, for example between two letters or between two spaces. The beginning and end of a string are considered non-words. Same as the matched word boundary, the matched non-word boundary is also not included in the match. For example, ``/\Bon/`` matches "on" in "at noon", and ``/ye\B/`` matches "ye" in "possibly yesterday".|
|x(?=y)  | Lookahead assertion: Matches "x" only if "x" is followed by "y". For example, /Jack(?=Sprat)/ matches "Jack" only if it is followed by "Sprat".|
|x(?!y)  | Negative lookahead assertion: Matches "x" only if "x" is not followed by "y".|
|(?<=y)x  | Lookbehind assertion: Matches "x" only if "x" is preceded by "y".|
|(?<!y)x  | Negative lookbehind assertion: Matches "x" only if "x" is not preceded by "y".|

<h1 style="text-align:center">Character Classes</h1>

Character classes distinguish kinds of characters such as, for example, distinguishing between letters and digits.

### Types
|Chracters  |Meaning  |
|---------|---------|
| . | `/.y/` matches "my" and "ay", but not "yes", in "yes make my day".|
| \d | Matches any digit (Arabic numeral). Equivalent to `[0-9]`. For example, `/\d/` or `/[0-9]/` matches "2" in "B2 is the suite number".|
| \D | Matches any character that is not a digit (Arabic numeral). Equivalent to `[^0-9]`. For example, `/\D/` or `/[^0-9]/` matches "B" in "B2 is the suite number".|
| \w | Matches any alphanumeric character from the basic Latin alphabet, including the underscore. Equivalent to `[A-Za-z0-9_]`. For example, `/\w/` matches "a" in "apple", "5" in "$5.28", "3" in "3D" and "m" in "Émanuel".|
| \W | Matches any character that is not a word character from the basic Latin alphabet. Equivalent to `[^A-Za-z0-9_]`. For example, `/\W/` or `/[^A-Za-z0-9_]/` matches "%" in "50%" and "É" in "Émanuel".|
| \s | Matches a single white space character, including space, tab, form feed, line feed, and other Unicode spaces. Equivalent to `[ \f\n\r\t\v\u00a0\u1680\u2000-\u200a\u2028\u2029\u202f\u205f\u3000\ufeff]`. For example, `/\s\w*/` matches " bar" in "foo bar".|
| \S | Matches a single character other than white space. Equivalent to `[^ \f\n\r\t\v\u00a0\u1680\u2000-\u200a\u2028\u2029\u202f\u205f\u3000\ufeff]`. For example, `/\S\w*/` matches "foo" in "foo bar".|
| \t | Matches a horizontal tab.|
| \r | Matches a carriage return.|
| \n | Matches a linefeed.|
| \v | Matches a vertical tab.|
| \f | Matches a form-feed.|
| [\b] | Matches a backspace. If you're looking for the word-boundary character (`\b`), see Assertions.|
| \0 | Matches a NUL character. Do not follow this with another digit.|
| \cX | Matches a control character using caret notation, where "X" is a letter from A–Z (corresponding to codepoints `U+0001–U+001A`). For example, `/\cM\cJ/` matches "\r\n".|
| \xhh | Matches the character with the code `hh` (two hexadecimal digits).|
| \uhhh | Matches a UTF-16 code-unit with the value `hhhh` (four hexadecimal digits).|
| \u{hhhh} or \u{hhhhh} | (Only when the `u` flag is set.) Matches the character with the Unicode value `U+hhhh` or `U+hhhhh` (hexadecimal digits).|
| \p{UnicodeProperty} | Matches a character based on its Unicode character properties (to match just, for example, emoji characters, or Japanese katakana characters, or Chinese/Japanese Han/Kanji characters, etc.).|
| \ | For characters that are usually treated literally, indicates that the next character is special and not to be interpreted literally. For example, ``/b/`` matches the character "b". By placing a backslash in front of "b", that is by using ``/\b/``, the character becomes special to mean match a word boundary.|

---
> For a more detailed document on Regular Expressions, you should now look at [MDN Documents](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_Expressions).
