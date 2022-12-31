<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Operators</h1>

## Increment & decrement 

### Increment (++)
The increment operator (``++``) increments (adds one to) its operand and returns a value.

### Decrement (--)
```js
x++   // Postfix increment (önce normal değer yazıdırlır ve sonra arttırılır)
++x   // Prefix increment (arttırlır ve sonra yazdırılır.)
```

## Unary operator

### Delete operator
The JavaScript ``delete`` removes a property from an object; if no more references to the same property are held, it is eventually released automatically.
```js
delete expression
delete object.property
delete object['property']
```
The delete operator removes a given property from an object. On successful deletion, it will return true, else false will be returned.

> [!NOTE]
> `var`, `let`, `const`, `function` olarak tanımlanan değerler veya objeler silinemez (false değeri döndürür.)


### Void operator
The ``void`` evaluates the given ``expression`` and then returns undefined.
```js
void expression
// example
void function test() {
console.log('message');
}();
```

### Typeof operator
The ``typeof`` operator returns a string indicating the type of the unevaluated operand.
```js
typeof operand
typeof(operand)
```

| Type       | Result      |
|------------|-------------|
| Undefined  | "undefined" |
| Null       | "object"    |
| Boolen     | "boolean"   |
| Number     | "number"    |
| BigInt     | "bigint"    |
| String     | "string"    |
| Symbol     | "symbol"    |
| Function   | "function"  |
| Any object | "object"    |

### Unary (+)
The unary plus operator (+) precedes its operand and evaluates to its operand but attempts to convert it into a number, if it isn't already.
```js
+x
```

### Unary (-)
The unary negation operator (-) precedes its operand and negates it.
```js
-x
// example
const x = 4;
const y = -x;
console.log(y); // output: -4
```

### Bitwise Not (~)
The bitwise NOT operator (`~`) inverts the bits of its operand. Like other bitwise operators, it converts the operand to a 32-bit signed integer
```js
~a
```

### Logical Not (!)
The logical NOT (!) operator (logical complement, negation) takes truth to falsity and vice versa. It is typically used with Boolean (logical) values. When used with non-Boolean values, it returns false if its single operand can be converted to `true`; otherwise, returns `true`.
```js
!expr
// example
n1 = !true     // !t returns false
n2 = !false    // !f returns true
n3 = !''       // !f returns true
n4 = !'Cat'    // !t returns false
```
#### Double Not (!!)
It is possible to use a couple of NOT operators in series to explicitly force the conversion of any value to the corresponding boolean primitive.
```js
n1 = !!true                   // !!truthy returns true
n2 = !!{}                     // !!truthy returns true: any object is truthy...
n3 = !!(new Boolean(false))   // ...even Boolean objects with a false .valueOf()!
n4 = !!false                  // !!falsy returns false
n5 = !!""                     // !!falsy returns false
n6 = !!Boolean(false)         // !!falsy returns false
```

## Arithmetic operators

### Addition (+) operator
The addition operator (`+`) produces the sum of numeric operands or string concatenation.
```js
x + y
2 + true               // 3
'hello ' + 'everyone'  //hello everyone
```

### Substraction (-) operator
The subtraction operator (`-`) subtracts the two operands, producing their difference.
```js
x - y
3.5 - 5   // -1.5
5 - true  // 4 
```

### Division (/) operator
The division operator (/) produces the quotient of its operands where the left operand is the dividend and the right operand is the divisor.
```js
x / y
1 / 2     // 0.5
2.0 / 0   // Infinity
```

### Multiplication (*) operator
The multiplication operator (*) produces the product of the operands.
```js
x * y
3 * 4     // 12
-3 * 4    // -12
'3' * 2   // 6
```


### Remainder (%) operator
The remainder operator (%) returns the remainder left over when one operand is divided by a second operand. It always takes the sign of the dividend.
```js
x % y
12 % 5     // 2
-12 % 5    // -2
4 % 2      // 0
-4 % 2     // -0
```

### Exponentiation (**) operator
The exponentiation operator (**) returns the result of raising the first operand to the power of the second operand. It is equivalent to `Math.pow`, except it also accepts BigInts as operands.
```js
x ** y
3 ** 4       // 81
10 ** -2     // 0.01
2 ** 3 ** 2  // 512
(2 ** 3)**2  // 64
```

## Relational operators

### in operator
The `in` returns `true` if the specified property is in the specified object or its prototype chain.
```js
prop in object
// example
const car={make: 'honda',...};
console.log('make'in car);  // output: true
```

### instanceof operator
The ``instanceof`` tests to see if the ``prototype`` property of a constructor appears anywhere in the prototype chain of an object. The return value is a boolean value.
```js
object instanceof constructor
```

### Less than (<)
The less than operator (`<`) returns true if the left operand is less than the right operand, and `false` otherwise.
```js
x < y
```

### Greater than (>)
The greater than operator (`>`) returns `true` if the left operand is greater than the right operand, and `false` otherwise.
```js
x > y
```

### Less than or equal (<=)
The less than or equal operator (`<=`) returns `true` if the left operand is less than or equal to the right operand, and `false` otherwise.
```js
x <= y
```

### Greater than or equal (>=)
The greater than or equal operator (`>=`) returns `true` if the left operand is greater than or equal to the right operand, and `false` otherwise.
```js
x >= y
```

## Equality operators

### Equality (==) operator
The equality operator (`==`) checks whether its two operands are equal, returning a Boolean result. Unlike the strict equality operator, it attempts to convert and compare operands that are of different types.
```js
x == y
1 == 1               // true
'hello' == 'hello'   // true
'1' == 1             // true
0 == false           // true
```


### Inequality (!=) operator
The inequality operator (`!=`) checks whether its two operands are not equal, returning a Boolean result. Unlike the strict inequality operator, it attempts to convert and compare operands that are of different types.
```js
x != y
```

### Strict equality (===) operator
The strict equality operator (`===`) checks whether its two operands are equal, returning a Boolean result. Unlike the equality operator, the strict equality operator always considers operands of different types to be different.
```js
x === y
1 === 1               // true
'hello' === 'hello'   // true
'1' === 1             // false
```

### Strict inequality (!==) operator
The strict inequality operator (`!==`) checks whether its two operands are not equal, returning a Boolean result. Unlike the inequality operator, the strict inequality operator always considers operands of different types to be different.
```js
x !== y
3 !== "3"   // true
```

## Bitwise shift operators

### Left shift (<<)
The left shift operator (`<<`) shifts the first operand the specified number of bits to the left. Excess bits shifted off to the left are discarded. Zero bits are shifted in from the right.
```js
a << b
// example
9 << 3;  // 9 * (2 ** 3) = 9 * (8) = 72
```
Bu operatör, ilk işleneni belirtilen bit sayısı kadar sola kaydırır. Sola kaydırılan fazla bitler atılır. Sıfır bitleri sağdan kaydırılır.


### Right shift (>>)
The right shift operator (`>>`) shifts the first operand the specified number of bits to the right. Excess bits shifted off to the right are discarded. Copies of the leftmost bit are shifted in from the left. Since the new leftmost bit has the same value as the previous leftmost bit, the sign bit (the leftmost bit) does not change. Hence the name "sign-propagating".
```js
a >> b
```

### Unsigned right shift (>>>)
The unsigned right shift operator (`>>>`) (zero-fill right shift) shifts the first operand the specified number of bits to the right.
```js
a >>> b
9 >>> 2;   // 2
-9 >>> 2;  // 1073741821
```

## Binary bitwise operators

### Bitwise And (&)
The bitwise AND operator (`&`) returns a 1 in each bit position for which the corresponding bits of both operands are 1s.
```js
a & b
```

### Bitwise Or (|)
The bitwise OR operator (`|`) returns a 1 in each bit position for which the corresponding bits of either or both operands are 1s.
```js
a | b
```

### Bitwise Xor (^)
The bitwise XOR operator (`^`) returns a 1 in each bit position for which the corresponding bits of either but not both operands are 1s.
```js
a ^ b
```

## Binary logical operators

### Logical And (&&)
The logical AND (`&&`) operator (logical conjunction) for a set of operands is true if and only if all of its operands are true. It is typically used with Boolean (logical) values. When it is, it returns a Boolean value. However, the `&&` operator actually returns the value of one of the specified operands, so if this operator is used with non-Boolean values, it will return a non-Boolean value.
```js
expr1 && expr2
// Operator precedence
true || false && false      // returns true, because && is executed first
(true || false) && false    // returns false, because operator precedence cannot apply
// example
a1 = true && true        // returns true
a1 = true && false       // returns false
a1 = false && true       // returns false
a1 = 'cat' && 'dog'      // returns "dog"
```

### Logical Or (||)
The logical OR (`||`) operator (logical disjunction) for a set of operands is true if and only if one or more of its operands is true. It is typically used with Boolean (logical) values. When it is, it returns a Boolean value. However, the `||` operator actually returns the value of one of the specified operands, so if this operator is used with non-Boolean values, it will return a non-Boolean value.
```js
expr1 || expr2
// example
o1 = true || true        // returns true
o1 = false || true       // returns true
o1 = true || false       // returns true
o1 = 'cat' || 'dog'      // returns "cat"
o1 = true || true        // returns true
```

### Nullish coalescing operator (??)
The nullish coalescing operator (`??`) is a logical operator that returns its right-hand side operand when its left-hand side operand is *null* or *undefined*, and otherwise returns its left-hand side operand.
```js
leftExpr ?? rightExpr
```

### Conditional (ternary) operator
The conditional (ternary) operator is the only JavaScript operator that takes three operands: a condition followed by a question mark (`?`), then an expression to execute if the condition is truthy followed by a colon (`:`), and finally the expression to execute if the condition is *falsy*. This operator is frequently used as a shortcut for the *if* statement.
```js
condition ? exprIfTrue : exprIfFalse
// example
function a(mp) {mp ? '1(t)' : '0(f)'};
console.log(a(true))    // output "1(t)"
console.log(a(false))   // output "0()"
```

## Assignment Operators

### Assignment (=) operator
The simple assignment operator (`=`) is used to assign a value to a variable. The assignment operation evaluates to the assigned value. Chaining the assignment operator is possible in order to assign a single value to multiple variables
```js
x = y
```

### Multiplication (*=) assignment
The multiplication assignment operator (*=) multiplies a variable by the value of the right operand and assigns the result to the variable.
```js
x *= y    // x = x * y 
```

### Exponentiation (**=) assignment
The exponentiation assignment operator (`**=`) raises the value of a variable to the power of the right operand.
```js
x **= y    // x = x ** y
3 /= 2     // 1.5
```

### Division (/=) assignment
The division assignment operator (`/=`) divides a variable by the value of the right operand and assigns the result to the variable.
```js
x /= y     // x = x / y
```

### Addition (+=) assignment
The addition assignment operator (`+=`) adds the value of the right operand to a variable and assigns the result to the variable. The types of the two operands determine the behavior of the addition assignment operator. Addition or concatenation is possible.
```js
x += y     // x = x + y
```


### Remainder (%=) assignment
The remainder assignment operator (`%=`) divides a variable by the value of the right operand and assigns the remainder to the variable.
```js
x %= y     // x = x % y
```

### Subtraction (-=) assignment
The subtraction assignment operator (`-=`) subtracts the value of the right operand from a variable and assigns the result to the variable.
```js
x -= y     // x = x - y
```

### Left shift (<<=) assignment
The left shift assignment operator (`<<=`) moves the specified amount of bits to the left and assigns the result to the variable.
```js
x <<= y    // x = x << y
```

### Right shift (>>=) assignment
The right shift assignment operator (`>>=`) moves the specified amount of bits to the right and assigns the result to the variable.
```js
x >>= y    // x = x >> y
```

### Unsigned right shift (>>>=) assignment
The unsigned right shift assignment operator (`>>>=`) moves the specified amount of bits to the right and assigns the result to the variable.
```js
x >>>= y    // x = x >>> y
```

### Bitwise And (&=) assignment
The bitwise AND assignment operator (`&=`) uses the binary representation of both operands, does a bitwise AND operation on them and assigns the result to the variable.
```js
x &= y     // x = x & y
```

### Bitwise Xor (^=) assignment
The bitwise XOR assignment operator (`^=`) uses the binary representation of both operands, does a bitwise XOR operation on them and assigns the result to the variable.
```js
x ^= y     // x = x ^ y
```

### Bitwise Or (|=) assignment
The bitwise OR assignment operator (`|=`) uses the binary representation of both operands, does a bitwise OR operation on them and assigns the result to the variable.
```js
x |= y     // x = x | y
```

### Logical And (&&=) assignment
The logical AND assignment (`x &&= y`) operator only assigns if x is truthy.
```js
expr1 &&= expr2
```

### Logical Or (||=) assignment
The logical OR assignment (`x ||= y`) operator only assigns if x is *falsy*.
```js
expr1 ||= expr2
```

### Logical nullish (??=) assignment
The logical nullish assignment (`x ??= y`) operator only assigns if x is *nullish* (null or undefined).
```js
expr1 ??= expr2
```







