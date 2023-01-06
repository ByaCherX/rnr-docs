<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - JSON</h1>

The `JSON` object contains methods for parsing [JavaScript Object Notation](https://www.json.org/json-en.html) (JSON) and converting values to JSON. It can't be called or constructed, and aside from its two method properties, it has no interesting functionality of its own.

### JavaScript and JSON differences
JSON is a syntax for serializing objects, arrays, numbers, strings, booleans, and null. It is based upon JavaScript syntax but is distinct from it: some JavaScript is not JSON.

**Objects and Arrays**</br>
Property names must be double-quoted strings; trailing commas are forbidden.

**Numbers**</br>
Leading zeros are prohibited. A decimal point must be followed by at least one digit. NaN and Infinity are unsupported.

**Any JSON text is a valid JavaScript expression...**</br>
...But only in JavaScript engines that have implemented the proposal to make all JSON text valid ECMA-262. In engines that haven't implemented the proposal, U+2028 LINE SEPARATOR and U+2029 PARAGRAPH SEPARATOR are allowed in string literals and property keys in JSON; but their use in these features in JavaScript string literals is a SyntaxError.

Consider this example where JSON.parse() parses the string as JSON and eval executes the string as JavaScript:
```js
let code = '"\u2028\u2029"'
JSON.parse(code)  // evaluates to "\u2028\u2029" in all engines
eval(code)        // throws a SyntaxError in old engines
```
Other differences include allowing only double-quoted strings and having no provisions for undefined or comments. For those who wish to use a more human-friendly configuration format based on JSON, there is JSON5, used by the Babel compiler, and the more commonly used YAML.

### Full JSON grammar
Valid JSON syntax is formally defined by the following grammar, expressed in ABNF, and copied from IETF JSON standard (RFC):
```command
JSON-text = object / array
begin-array     = ws %x5B ws  ; [ left square bracket
begin-object    = ws %x7B ws  ; { left curly bracket
end-array       = ws %x5D ws  ; ] right square bracket
end-object      = ws %x7D ws  ; } right curly bracket
name-separator  = ws %x3A ws  ; : colon
value-separator = ws %x2C ws  ; , comma
ws = *(
     %x20 /              ; Space
     %x09 /              ; Horizontal tab
     %x0A /              ; Line feed or New line
     %x0D                ; Carriage return
     )
value = false / null / true / object / array / number / string
false = %x66.61.6c.73.65   ; false
null  = %x6e.75.6c.6c      ; null
true  = %x74.72.75.65      ; true
object = begin-object [ member *( value-separator member ) ]
         end-object
member = string name-separator value
array = begin-array [ value *( value-separator value ) ] end-array
number = [ minus ] int [ frac ] [ exp ]
decimal-point = %x2E       ; .
digit1-9 = %x31-39         ; 1-9
e = %x65 / %x45            ; e E
exp = e [ minus / plus ] 1*DIGIT
frac = decimal-point 1*DIGIT
int = zero / ( digit1-9 *DIGIT )
minus = %x2D               ; -
plus = %x2B                ; +
zero = %x30                ; 0
string = quotation-mark *char quotation-mark
char = unescaped /
    escape (
        %x22 /          ; "    quotation mark  U+0022
        %x5C /          ; \    reverse solidus U+005C
        %x2F /          ; /    solidus         U+002F
        %x62 /          ; b    backspace       U+0008
        %x66 /          ; f    form feed       U+000C
        %x6E /          ; n    line feed       U+000A
        %x72 /          ; r    carriage return U+000D
        %x74 /          ; t    tab             U+0009
        %x75 4HEXDIG )  ; uXXXX                U+XXXX
escape = %x5C              ; \
quotation-mark = %x22      ; "
unescaped = %x20-21 / %x23-5B / %x5D-10FFFF

HEXDIG = DIGIT / %x41-46 / %x61-66   ; 0-9, A-F, or a-f
       ; HEXDIG equivalent to HEXDIG rule in [RFC5234]
DIGIT = %x30-39            ; 0-9
      ; DIGIT equivalent to DIGIT rule in [RFC5234]
```
Insignificant whitespace may be present anywhere except within a `JSONNumber` (numbers must contain no whitespace) or `JSONString` (where it is interpreted as the corresponding character in the string, or would cause an error). The tab character (U+0009), carriage return (U+000D), line feed (U+000A), and space (U+0020) characters are the only valid whitespace characters.

## Static methods

### JSON.parse()
The `JSON.parse()` method parses a JSON string, constructing the JavaScript value or object described by the string. An optional reviver function can be provided to perform a transformation on the resulting object before it is returned.

**syntax**
```js
JSON.parse(text[, reviver])

JSON.parse(text)
JSON.parse(text, reviver)
```

### JSON.stringify()
The `JSON.stringify()` method converts a JavaScript object or value to a JSON string, optionally replacing values if a replacer function is specified or optionally including only the specified properties if a replacer array is specified.

**Syntax**
```js
JSON.stringify(value)
JSON.stringify(value, replacer)
JSON.stringify(value, replacer, space)
```











