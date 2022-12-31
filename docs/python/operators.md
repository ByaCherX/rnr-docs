<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Python - Operators</h1>

## Arithmetic Operators
Arithmetic operators are used to performing mathematical operations like addition, subtraction, multiplication, and division.

|Operator |Description  |Syntax  |
|---------|-------------|--------|
|+  |Addition: adds two operands| x + y |
|-  |Subtraction: subtracts two operands| x – y |
|*  |Multiplication: multiplies two operands| x * y |
|/  |Division (float): divides the first operand by the second| x / y |
|// |Division (floor): divides the first operand by the second| x // y |
|%  |Modulus: returns the remainder when the first operand is divided by the second| x % y |
|** |Power: Returns first raised to power second| x ** y |


## Comparison Operators
Comparison of Relational operators compares the values. It either returns True or False according to the condition.

|Operator|Description  |Syntax  |
|--------|-------------|--------|
|>       |Greater than: True if the left operand is greater than the right| x > y |
|<       |Less than: True if the left operand is less than the right| x < y |
|==      |Equal to: True if both operands are equal| x == y |
|!=      |Not equal to – True if operands are not equal| x != y |
|>=      |Greater than or equal to True if the left operand is greater than or equal to the right| x >= y |
|<=      |Less than or equal to True if the left operand is less than or equal to the right| x <= |
|is      |x is the same as y| x is y |
|is not  |x is not the same as y| x is not y |


## Logical Operators
Logical operators perform Logical AND, Logical OR, and Logical NOT operations. It is used to combine conditional statements.

|Operator|Description  |Syntax  |
|--------|-------------|--------|
|and     |Logical AND: True if both the operands are true| x and y |
|or      |Logical OR: True if either of the operands is true| x or y |
|not     |Logical NOT: True if the operand is false | not x |


## Bitwise Operators
Bitwise operators act on bits and perform the bit-by-bit operations. These are used to operate on binary numbers.

|Operator|Description        |Syntax |
|--------|-------------------|-------|
|&       |Bitwise AND        | x & y |
||       |Bitwise OR         | x | y |
|~       |Bitwise NOT        |  ~x   |
|^       |Bitwise XOR        | x ^ y |
|>>      |Bitwise right shift|  x>>  |
|<<      |Bitwise left shift |  x<<  |


## Assignment Operators
Assignment operators are used to assign values to the variables.

|Operator   |Description   |Syntax   |
|----------|------------|-----------|
|=  |Assign value of right side of expression to left side operand| 	x = y + z|
|+=  |Add AND: Add right-side operand with left side operand and then assign to left operand|	a+=b </br> a=a+b|
|-=  |Subtract AND: Subtract right operand from left operand and then assign to left operand|	a-=b </br> a=a-b|
|*=  |Multiply AND: Multiply right operand with left operand and then assign to left operand|	a*=b </br> a=a*b|
|/=  |Divide AND: Divide left operand with right operand and then assign to left operand|	a/=b </br> a=a/b|
|%=  |Modulus AND: Takes modulus using left and right operands and assign the result to left operand|	a%=b </br> a=a%b|
|//= |Divide(floor) AND: Divide left operand with right operand and then assign the value(floor) to left operand|	a//=b </br> a=a//b|
|**= |Exponent AND: Calculate exponent(raise power) value using operands and assign value to left operand|	a**=b </br> a=a**b|
|&=  |Performs Bitwise AND on operands and assign value to left operand|	a&=b </br> a=a&b|
|\|=  |Performs Bitwise OR on operands and assign value to left operand|	a\|=b </br> a=a\|b|
|^=  |Performs Bitwise xOR on operands and assign value to left operand|	a^=b </br> a=a^b|
|>>= |Performs Bitwise right shift on operands and assign value to left operand|	a>>=b </br> a=a>>b|
|<<= |Performs Bitwise left shift on operands and assign value to left operand|	a <<= b </br> a= a << b|


## Identity Operators
is and is not are the identity operators both are used to check if two values are located on the same part of the memory. Two variables that are equal do not imply that they are identical. 

- **is** : True if the operands are identical
- **is not** : True if the operands are not identical 

## Membership Operators
in and not in are the membership operators; used to test whether a value or variable is in a sequence.

- **in** : True if value is found in the sequence
- **not in** : True if value is not found in the sequence

## Ternary Operator
Ternary operators are also known as conditional expressions are operators that evaluate something based on a condition being true or false. It was added to Python in version 2.5. 
It simply allows testing a condition in a single line replacing the multiline if-else making the code compact.
```py
# Syntax
[on_true] if [expression] else [on_false] 
```

**Example**
```py
# Program to demonstrate conditional operator
a, b = 10, 20
# Copy value of a in min if a < b else copy b
min = a if a < b else b
print(min) #10

# Direct Method by using Tuples, Dictionary and Lambda
print( (b, a) [a < b] )  #Tuples
print({True: a, False: b} [a < b])  #Dictionary
print((lambda: b, lambda: a) [a < b]())  #Lambda

# Other Ternary operator
# [statement_on_true] if [condition] else [statement_on_false]
print(a,"is greater") if (a>b) else print(b,"is Greater")
```




















