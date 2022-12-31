<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Python - Functions</h1>

Python Functions is a block of statements that return the specific task.

The idea is to put some commonly or repeatedly done tasks together and make a function so that instead of writing the same code again and again for different inputs, we can do the function calls to reuse code contained in it over and over again. 

```py
# Syntax
def function_name(parameters):
    # statement
    return expression

# Creating Func
def func():
    print("Welcome the GFG")

# Calling Func
func()

# Defining and calling func
def function_name(parameter: data_type) -> return_type:
    """Docstring"""
    # body of the function
    return expression
```

## Arguments
Arguments are the values passed inside the parenthesis of the function. A function can have any number of arguments separated by a comma.

In this example, we will create a simple function to check whether the number passed as an argument to the function is even or odd.

```py
def evenOdd(x):
    if (x % 2 == 0):
        print("even")
    else:
        print("odd")
 
 
# Driver code to call the function
evenOdd(2)
evenOdd(3)
```

### Default arguments
A default argument is a parameter that assumes a default value if a value is not provided in the function call for that argument. The following example illustrates Default arguments. 
```py
def myFun(x, y=50):
    print("x: ", x)
    print("y: ", y)
 
 
# Driver code (We call myFun() with only
# argument)
myFun(10)
```

### Keyword arguments
The idea is to allow the caller to specify the argument name with values so that caller does not need to remember the order of parameters.
```py
def student(firstname, lastname):
    print(firstname, lastname)
 
 
# Keyword arguments
student(firstname='Geeks', lastname='Practice')
student(lastname='Practice', firstname='Geeks')
```

### Variable-length arguments
In Python, we can pass a variable number of arguments to a function using special symbols. There are two special symbols:
- *args (Non-Keyword Arguments)
- **kwargs (Keyword Arguments)
```py
def myFun(*argv):
    for arg in argv:
        print(arg)
 
 
myFun('Hello', 'Welcome', 'to', 'GeeksforGeeks')
```

## Class method vs Static method


```py
# Syntax Python Class Method
class C(object):
    @classmethod
    def func(cls, arg1, arg2, ...):
        ...

# Syntax Python Static Method
class C(object):
    @staticmethod
    def func(arg1, arg2, ...):
        ...
```
**Class Method**

The ``@classmethod`` decorator is a built-in function decorator that is an expression that gets evaluated after your function is defined. The result of that evaluation shadows your function definition. A class method receives the class as an implicit first argument, just like an instance method receives the instance

* A class method is a method that is bound to the class and not the object of the class.
* They have the access to the state of the class as it takes a class parameter that points to the class and not the object instance.
* It can modify a class state that would apply across all the instances of the class. For example, it can modify a class variable that will be applicable to all the instances.

**Static Method**

A static method does not receive an implicit first argument. A static method is also a method that is bound to the class and not the object of the class. This method can’t access or modify the class state. It is present in a class because it makes sense for the method to be present in class.


### Class method vs Static method
The difference between the Class method and the static method is:

* A class method takes cls as the first parameter while a static method needs no specific parameters.
* A class method can access or modify the class state while a static method can’t access or modify it.
* In general, static methods know nothing about the class state. They are utility-type methods that take some parameters and work upon those parameters. On the other hand class methods must have class as a parameter.
* We use ``@classmethod`` decorator in python to create a class method and we use @staticmethod decorator to create a static method in python.

```py
from datetime import date

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
 
    # a class method to create a Person object by birth year.
    @classmethod
    def fromBirthYear(cls, name, year):
        return cls(name, date.today().year - year)
 
    # a static method to check if a Person is adult or not.
    @staticmethod
    def isAdult(age):
        return age > 18


person1 = Person('mayank', 21)
person2 = Person.fromBirthYear('mayank', 1996)
 
print(person1.age)
print(person2.age)
 
# print the result
print(Person.isAdult(22))
```

## Returning Multiple Values
In Python, we can return multiple values from a function. Following are different ways

```py
# Using Object
class Test: 
    def __init__(self):
        self.str = "geeksforgeeks"
        self.x = 20   
  
## This function returns an object of Test
def func(): return Test()
      
## Driver code to test above method
t = func() 
print(t.str)
print(t.x)


# Using Tuple
def func():
    str = "geeksforgeeks"
    x   = 20
    return str, x;  ## Return tuple, we could also
                    ## write (str, x)
  
## Driver code to test above method
str, x = func() ## Assign returned tuple
print(str)
print(x)


# Using List
def func():
    str = "geeksforgeeks"
    x = 20   
    return [str, x];  
  
## Driver code to test above method
list = func() 
print(list)


# Using Dictionary
def func():
    d = dict(); 
    d['str'] = "GeeksforGeeks"
    d['x']   = 20
    return d
  
## Driver code to test above method
d = func() 
print(d)  ## {'x':20,'str':'GeeksforGeeks'}


# Using Data Class
from dataclasses import dataclass
@dataclass
class Book_list:
    name: str
    perunit_cost: float
    quantity_available: int = 0
          
    ## function to calculate total cost    
    def total_cost(self) -> float:
        return self.perunit_cost * self.quantity_available
      
book = Book_list("Introduction to programming.", 300, 3)
x = book.total_cost()
  
## print the total cost
## of the book
print(x)
  
## print book details
print(book)
  
## 900
Book_list(name='Python programming.',
          perunit_cost=200,
          quantity_available=3)
```

## Partial Functions
Partial functions allow us to fix a certain number of arguments of a function and generate a new function.

```py
from functools import partial
  
# A normal function
def f(a, b, c, x):
    return 1000*a + 100*b + 10*c + x
  
# A partial function that calls f with
# a as 3, b as 1 and c as 4.
g = partial(f, 3, 1, 4)
  
# Calling g()
print(g(5))   #3145


# Another Example
def add(a, b, c):
    return 100 * a + 10 * b + c
  
# A partial function with b = 1 and c = 2
add_part = partial(add, c = 2, b = 1)
  
# Calling partial function
print(add_part(3))
```

## First Class functions
First class objects in a language are handled uniformly throughout. They may be stored in data structures, passed as arguments, or used in control structures. A programming language is said to support first-class functions if it treats functions as first-class objects. Python supports the concept of First Class functions.

**Properties of first class functions:**
  - A function is an instance of the Object type.
  - You can store the function in a variable.
  - You can pass the function as a parameter to another function.
  - You can return the function from a function.
  - You can store them in data structures such as hash tables, lists, …

```py
# Functions are objects
def shout(text):
    return text.upper()
  
print (shout('Hello'))
yell = shout
print (yell('Hello'))


# Functions can be passed as arguments to other func
def shout(text):
    return text.upper()

def whisper(text):
    return text.lower()
  
def greet(func):
    # storing the function in a variable
    greeting = func("""Hi, I am created by a function
                    passed as an argument.""")
    print (greeting) 
  
greet(shout)
greet(whisper)


# Functions can return another function
def create_adder(x):
    def adder(y):
        return x+y
  
    return adder
  
add_15 = create_adder(15)
  
print (add_15(10))
```

## Precision Handling
- **Using “%”:**- “%” operator is used to format as well as set precision in python. This is similar to “printf” statement in C programming.
- **Using format():**- This is yet another way to format the string for setting precision.
- **Using round(x,n):**- This function takes 2 arguments, number, and the number till which we want decimal part rounded.

```py
# initializing value
a = 3.4536

print("The value of number till 2 decimal place(using %) is : ", end="")
print('%.2f' % a)  #3.45
 
# using format() to print value till 3 decimal places
print("The value of number till 2 decimal place(using format()) is : ", end="")
print("{0:.3f}".format(a))  #3.453
```

## *args and **kwargs
In this article, we will cover what ** (double star/asterisk) and * (star/asterisk) do for parameters in Python,  Here, we will also cover args and kwargs examples in Python. We can pass a variable number of arguments to a function using special symbols. 
```py
def myFun(*argv):
    for arg in argv:
        print(arg)
 
myFun('Hello', 'Welcome', 'to', 'GeeksforGeeks')

# **kywargs
def myFun(**kwargs):
    for key, value in kwargs.items():
        print("%s == %s" % (key, value))
 
 
# Driver code
myFun(first='Geeks', mid='for', last='Geeks')
```

## Function Decorators
A decorator is a function that takes a function as its only parameter and returns a function. This is helpful to “wrap” functionality with the same code over and over again. For example, above code can be re-written as following.
We use ``@func_name`` to specify a decorator to be applied on another function.

```py
def decorate_message(fun):
  
    # Nested function
    def addWelcome(site_name):
        return "Welcome to " + fun(site_name)
  
    # Decorator returns a function
    return addWelcome
  
@decorate_message
def site(site_name):
    return site_name;
  
# Driver code
  
# This call is equivalent to call to
# decorate_message() with function
# site("GeeksforGeeks") as parameter
print site("GeeksforGeeks")
```

























