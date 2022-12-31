<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">JavaScript - Control Flow</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

### Block
A block statement (or compound statement in other languages) is used to group zero or more statements.
```js
{
   StatementList
}
```

### Break
The break terminates the current *loop*, *switch*, or *label* statement and transfers program control to the statement following the terminated statement.
```js
break;
break [label];
```

### Continue
The continue terminates execution of the statements in the current iteration of the current or labeled loop, and continues execution of the loop with the next iteration.
```js
continue;
continue [label];
```

### Empty
An empty statement is used to provide no statement, although the JavaScript syntax would expect one.
```js
;
/* example */ 
const array1 = [];
```

### if...else
The if statement executes a statement if a specified condition is *True*. If the condition is *False*, another statement can be executed.
```js
if (condition) {
    statement1
} else {
    statement2
}
```

### switch
The *switch* statement evaluates an expression, matching the expression's value to a *case* clause, and executes statements associated with that *case*, as well as statements in *case*s that follow the matching *case*.
```js
switch (expression) {
   case value1:
      statement1
      break;
   case value2:
      ...
}
```

### throw
The *throw* throws a user-defined exception. Execution of the current function will stop (the statements after *throw* won't be executed), and control will be passed to the first *catch* block in the call stack. If no *catch* block exists among caller functions, the program will terminate.
```js
throw expression;
throw new ErrorFunctionName1('errorMessage');
```

### try...catch
The *try...catch* statement marks a block of statements to try and specifies a response should an exception be thrown.
```js
try {
   try_statements
}
catch (exception_var) {
   catch_statements
}
finally {
   finally_statements
}
```


