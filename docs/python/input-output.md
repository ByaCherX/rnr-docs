<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Python - Input/Output</h1>

While Python provides us with two inbuilt functions to read the input from the keyboard. 
 
* input ( prompt )
* raw_input ( prompt )

``input ()``: This function first takes the input from the user and converts it into a string.

```py
val = input("Enter your value: ")
print(val)
```

``raw_input()``: This function works in older version (like Python 2.x). This function takes exactly what is typed from the keyboard, converts it to string, and then returns it to the variable in which we want to store it.

```py
g = raw_input("Enter your name: ")
print g
```

## Taking multiple inputs
The developer often wants a user to enter multiple values or inputs in one line. In C++/C user can take multiple inputs in one line using scanf but in Python user can take multiple values or inputs in one line by two methods.

* Using split() method
* Using List comprehension

``split() method``: This function helps in getting multiple inputs from users. It breaks the given input by the specified separator. If a separator is not provided then any white space is a separator. Generally, users use a split() method to split a Python string but one can use it in taking multiple inputs.

```py
# Syntax
input().split(separator, maxsplit)

# taking two inputs at a time
x, y = input("Enter two values: ").split()
print("Number of boys: ", x)
print("Number of girls: ", y)
  
# taking three inputs at a time
x, y, z = input("Enter three values: ").split()
print("Total number of students: ", x)
print("Number of boys is : ", y)
print("Number of girls is : ", z)
  
# taking two inputs at a time
a, b = input("Enter two values: ").split()
print("First number is {} and second number is {}".format(a, b))
  
# taking multiple inputs at a time 
# and type casting using list() function
x = list(map(int, input("Enter multiple values: ").split()))
print("List of students: ", x)
```

``List comprehension``: List comprehension is an elegant way to define and create list in Python. We can create lists just like mathematical statements in one line only. It is also used in getting multiple inputs from a user. 

```py
# taking two input at a time
x, y = [int(x) for x in input("Enter two values: ").split()]
print("First Number is: ", x)
print("Second Number is: ", y)
print()
  
# taking three input at a time
x, y, z = [int(x) for x in input("Enter three values: ").split()]
print("First Number is: ", x)
print("Second Number is: ", y)
print("Third Number is: ", z)
print()
  
# taking two inputs at a time
x, y = [int(x) for x in input("Enter two values: ").split()]
print("First number is {} and second number is {}".format(x, y))
print()
  
# taking multiple inputs at a time 
x = [int(x) for x in input("Enter multiple values: ").split()]
print("Number of list is: ", x) 
```







