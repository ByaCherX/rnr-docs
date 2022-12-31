<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Python - Variables</h1>




```py
a = 2
A = 4
```

## Global and Local Variables
Global variables are those which are not defined inside any function and have a global scope whereas local variables are those which are defined inside a function and its scope is limited to that function only. 
In other words, we can say that local variables are accessible only inside the function in which it was initialized whereas the global variables are accessible throughout the program and inside every function. 
Local variables are those which are initialized inside a function and belong only to that particular function. It cannot be accessed anywhere outside the function. Let’s see how to create a local variable.

```py
def f():
    s = "local"
    print(s)
# Global scope
s = "global"
f()

def ff():
    global s
    print(s)
ff()
```





















