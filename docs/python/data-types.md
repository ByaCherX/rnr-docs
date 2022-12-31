<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Python - Data Types</h1>

## Strings
In Python, Strings are arrays of bytes representing Unicode characters.

```py
# Creating a String in Python
String1 = 'Welcome to the rnr World'
String2 = "I'm a rnr"
String3 = '''I'm a rnr and I live in a world of "Software"'''
String4 = '''Software
            For
            Life'''

# Accessing characters in Python String
gfg = "geeksforgeeks"
print(String1[0])
print(gfg[-1])

# Reverse the strinh using reversed and join function
gfg = "".join(reversed(gfg))

# String Slicing
print(String1[3:12])
print(String1[3:-2])

# Deleting/Updating from a String
list1 = list(String1)
list1[2] = 'p'
del String1
```

### Formatting of Strings
Strings in Python can be formatted with the use of ``format()`` method which is a very versatile and powerful tool for formatting Strings.
```py
# Default order
String1 = "{} {} {}".format('Geeks', 'For', 'Life')
print("Print String in default order: ")
print(String1)
 
# Positional Formatting
String1 = "{1} {0} {2}".format('Geeks', 'For', 'Life')
print("\nPrint String in Positional order: ")
print(String1)
 
# Keyword Formatting
String1 = "{l} {f} {g}".format(g='Geeks', f='For', l='Life')
print("\nPrint String in order of Keywords: ")
print(String1)
```

|Built-In Function   |Description   |
|--------------------|--------------|
|str.|    |


## List
Python Lists are just like dynamically sized arrays, declared in other languages (vector in C++ and ArrayList in Java). In simple language, a list is a collection of things, enclosed in [ ] and separated by commas.

```py
# Creating a List in Python
List = [10, 20, 14]
List = ["Geeks", "For", "Geeks"]
List = [['Geeks', 'For'], ['Geeks']]

# Accessing elements from the list
print(List[0])
print(List[0][1])

# Getting the size of Python list
print(len(List1))

# Taking Input of a Python List
string = input("Enter elements (Space-Separated): ")
lst = string.split()  

# Adding Elements to a Python List
List.append(1)
List.append((5, 6))
List.append(['For', 'Geeks'])

## Addition of Element (using Insert Method)
List.insert(3, 12) # insert(index, value)

## Addition of Element (using Extend Method)
List.extend([8, 'Always'])

# Reversing a List
mylist = [1, 2, 3, 4, 5, 'Geek', 'Python']
mylist.reverse()

# Removing Elements from the List 
List.remove(1)  # Value
List.pop(1)     # Index

# Slicing of a List
List[3:8]  #[Start : End]
```

|Function   |Description   |
|-----------|--------------|
|Append()   |Add an element to the end of the list      |
|Extend()   |Add all elements of a list to another list |
|Insert()   |Insert an item at the defined index        |
|Remove()   |Removes an item from the list              |
|Clear()    |Removes all items from the list            |
|Index()    |Returns the index of the first matched item|
|Count()    |Returns the count of the number of items passed as an argument|
|Sort()     |Sort items in a list in ascending order    |
|Reverse()  |Reverse the order of items in the list     |
|copy()     |Returns a copy of the list                 |


## Tuples
Tuple is a collection of Python objects much like a list. The sequence of values stored in a tuple can be of any type, and they are indexed by integers. 

Values of a tuple are syntactically separated by ‘commas’. Although it is not necessary, it is more common to define a tuple by closing the sequence of values in parentheses. This helps in understanding the Python tuples more easily.

```py
# Creating a Tuple
Tuple1 = ('Geeks', 'For')
list1 = [1, 2, 4, 5, 6]
print(tuple(list1))

# Nested Tuples
Tuple1 = (0, 1, 2, 3)
Tuple2 = ('python', 'geek')
Tuple3 = (Tuple1, Tuple2)

# Accessing Tuple
print(Tuple1[0])
a, b, c = Tuple1
print(a)

# Concatenation of Tuples
Tuple1 = (0, 1, 2, 3)
Tuple2 = ('Geeks', 'For', 'Geeks')
 
Tuple3 = Tuple1 + Tuple2

# Slicing of Tuple
Tuple1[2:5]
```


## Sets
In Python, a Set is an unordered collection of data types that is iterable, mutable and has no duplicate elements. The order of elements in a set is undefined though it may consist of various elements. The major advantage of using a set, as opposed to a list, is that it has a highly optimized method for checking whether a specific element is contained in the set.

```py
# Creating a Set
set1 = set("GeeksForGeeks")
set1 = set(["Geeks", "For", "Geeks"])
print(set1) # {'Geeks', 'For'}

my_set = {1, 2, 3}
print(my_set)

# Adding Elements to a Set
set1.add(8)

# Updating Elements
set1.update([10, 11])

# Removing elements from the Set
set1.remove(5)
set1.discard(8)
set1.pop()     # removing element front
```

|Function      |Description   |
|--------------|--------------|
|add()         |Adds an element to a set|
|remove()      |Removes an element from a set. If the element is not present in the set|
|clear()       |Removes all elements form a set|
|copy()        |Returns a shallow copy of a set|
|pop()         |Removes and returns an arbitrary set element. Raise KeyError if the set is empty|
|update()      |Updates a set with the union of itself and others|
|union()       |Returns the union of sets in a new set|
|difference()  |Returns the difference of two or more sets as a new set|
|discard()     |Removes an element from set if it is a member.|
|intersection()|Returns the intersection of two sets as a new set|


## Dictionary
Dictionary in Python is a collection of keys values, used to store data values like a map, which, unlike other data types which hold only a single value as an element.

```py
# Creating a Dictionary
Dict = {1: 'Geeks', 2: 'For', 3: 'Geeks'}
Dict = {'Name': 'Geeks', 1: [1, 2, 3, 4]}

Dict = dict({1: 'Geeks', 2: 'For', 3: 'Geeks'})
Dict = dict([(1, 'Geeks'), (2, 'For')])

# Nested Dictionary
Dict = {1: 'Geeks', 2: 'For', 3: {'A': 'Welcome', 'B': 'To', 'C': 'Geeks'}}

# Adding elements to a Dictionary
Dict[0] = 'Geeks'
Dict['Value_set'] = 2, 3, 4

# Accessing elements of a Dictionary
print(Dict['name'])
print(Dict.get(3))

# Accessing elements of a nested dictionary
print(Dict['Dict1'][1])
```
|Function  |Description   |
|----------|--------------|
|clear()   |Remove all the elements from the dictionary|
|copy()    |Returns a copy of the dictionary|
|get()     |Returns the value of specified key|
|items()   |Returns a list containing a tuple for each key value pair|
|keys()    |Returns a list containing dictionary’s keys|
|pop()     |Remove the element with specified key|
|popitem() |Removes the last inserted key-value pair|
|update()  |Updates dictionary with specified key-value pairs|
|values()  |Returns a list of all the values of dictionary|

