<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Python - Control Flow</h1>

Python programming language provides the following types of loops to handle looping requirements. Python provides three ways for executing the loops. While all the ways provide similar basic functionality, they differ in their syntax and condition checking time.

## While Loop
In python, a while loop is used to execute a block of statements repeatedly until a given condition is satisfied. And when the condition becomes false, the line immediately after the loop in the program is executed.

```py
# Syntax
while expression:
    statement(s)

while condition:
    # execute theese statements
else:
    # execute theese statements

# while loop
while (count < 3):
    count = count + 1
    print("Hello Geek")
else:
    print("In Else Block")
```

## For Loop
For loops are used for sequential traversal. For example: traversing a list or string or array etc. In Python, there is no C style for loop, i.e., for ``(i=0; i<n; i++)``. There is “for in” loop which is similar to for each loop in other languages. Let us learn how to use for in loop for sequential traversals.

```py
# Syntax
for iterator_var in sequence:
    statements(s)

# Iterating over range
n = 4
for i in range(0, n):
    print(i)

```

## Nested Loops
Python programming language allows to use one loop inside another loop. Following section shows few examples to illustrate the concept. 

```py
# Syntax
for iterator_var in sequence:
    for iterator_var in sequence:
        statements(s)
        statements(s)
```

## Loop Control Statements
Loop control statements change execution from their normal sequence. When execution leaves a scope, all automatic objects that were created in that scope are destroyed. Python supports the following control statements. 

```py
# Continue Statement
for letter in 'geeksforgeeks_':
    if letter == 'e' or letter == 's':
        continue
    if letter == '_':
        break
    print('Current Letter:', letter)
    var = 10
```

## Switch Case
In Python, a dictionary is an unordered collection of data values that can be used to store data values. Unlike other data types, which can only include a single value per element, dictionaries can also contain a key: value pair.
The key value of the dictionary data type functions as cases in a switch statement when we use the dictionary to replace the Switch case statement.

```py
def number_to_string(argument):
    match argument:
        case 0:
            return "zero"
        case 1:
            return "one"
        case 2:
            return "two"
        case default:
            return "something"
 
 
if __name__ = "__main__":
    argument = 0
    number_to_string(argument)
```

## Iterable & Iterator
Iterable is an object, that one can iterate over. It generates an Iterator when passed to ``iter()`` method. An iterator is an object, which is used to iterate over an iterable object using the ``__next__()`` method. Iterators have the ``__next__()`` method, which returns the next item of the object.

```py
s="GFG"
s=iter(s)
print(s)        #<str_iterator object at 0xf8..>
print(next(s))  # G
print(next(s))  # F
print(next(s))  # G
```

## Generators
Generator-Function: A generator-function is defined like a normal function, but whenever it needs to generate a value, it does so with the yield keyword rather than return. If the body of a def contains yield, the function automatically becomes a generator function. 

```py
def simpleGeneratorFun():
    yield 1
    yield 2
    yield 3
for value in simpleGeneratorFun():
    print(value)

# Other way
x = simpleGeneratorFun()
print(next(x))
```














