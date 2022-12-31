<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Operators </h1>

## Arithmetic Operators

### Addition Operator (+)
If both operands are integers, the result is calculated with BIGINT precision. If either integer is unsigned, the result is also an unsigned integer.
```sql
SELECT 3+5;
```

### Subtraction Operators (-)
If both operands are integers, the result is calculated with ``BIGINT`` precision.
```sql
SELECT 96-9;
SELECT 3.66 + 1.333;
```

### Division Operator (/)
Division operator. Dividing by zero will return NULL
```sql
SELECT 4/5;        --0.8000
SELECT 300/(2-2);  --NULL
SELECT 300/7;      --42.8571
```

### Modulo Operator (%)
Modulo operator. Returns the remainder of N divided by M. See also MOD.
```sql
SELECT 1042 % 50;  --42
```

### Multiplication Operator (*)
Multiplication operator.
```sql
SELECT 7*6;                   --42
SELECT 1234567890*9876543210; -- -6253480962446024716
```

### MOD
Modulo operation. Returns the remainder of N divided by M. See also Modulo Operator.
```sql
SELECT 1042 % 50;  --42
SELECT 253 % 7;    --1
SELECT MOD(29,9);  --2
```


## Assignment Operators
The equal sign is used as both an assignment operator in certain contexts, and as a ``comparison operator``. When used as assignment operator, the value on the right is assigned to the variable (or column, in some contexts) on the left.

Unlike the = operator, := can always be used to assign a value to a variable.
```sql
--Syntax--
var_name := expr

--Example--
UPDATE table_name SET x = 2 WHERE x > 100;
SET @x = 1, @y := 2;

SELECT @x := 10;
```


## Bit Functions and Operators

### Bitwise (&)
```sql
SELECT 2&1;      --0
SELECT 3&1;      --1
SELECT 29 & 15;  --13
```

### Left Shif (<<)
```sql
value1 << value2

SELECT 1 << 2;  --4
```

### Right Shift (>>)
```sql
value1 >> value2

SELECT 4 >> 2;  --1
```

### Bitwise XOR (^)
```sql
SELECT 1 ^ 1;   --0

SELECT 1 ^ 0;   --1
```

### Bitwise OR (|)
```sql
SELECT 2|1;      --3
SELECT 29 | 15;  --31
```

### Bitwise NOT (~)
```sql
SELECT 3 & ~1;  --2
SELECT 5 & ~1;  --4
```

## Comparison Operators

### Not equal (!=)
```sql
<>, !=
SELECT (t1.a, t1.b) != (t2.x, t2.y) 
FROM t1 INNER JOIN t2;

SELECT (t1.a != t2.x) OR (t1.b != t2.y)
FROM t1 INNER JOIN t2;
```

### Less than (<)
```sql
SELECT (t1.a, t1.b) < (t2.x, t2.y) 
FROM t1 INNER JOIN t2;

SELECT (t1.a < t2.x) OR ((t1.a = t2.x) AND (t1.b < t2.y))
FROM t1 INNER JOIN t2;
```

### Less than or equal (<=)
```sql
SELECT (t1.a, t1.b) <= (t2.x, t2.y) 
FROM t1 INNER JOIN t2;

SELECT (t1.a < t2.x) OR ((t1.a = t2.x) AND (t1.b <= t2.y))
FROM t1 INNER JOIN t2;
```

### NULL-safe equal (<=>)
```sql
SELECT (t1.a, t1.b) <=> (t2.x, t2.y) 
FROM t1 INNER JOIN t2;

SELECT (t1.a <=> t2.x) AND (t1.b <=> t2.y)
FROM t1 INNER JOIN t2;
```

### Equal (=)
```sql
left_expr = right_expr

SELECT (t1.a, t1.b) = (t2.x, t2.y) FROM t1 INNER JOIN t2;

SELECT (t1.a = t2.x) AND (t1.b = t2.y) FROM t1 INNER JOIN t2;
```

### Greater than (>)
```sql
SELECT (t1.a, t1.b) > (t2.x, t2.y) 
FROM t1 INNER JOIN t2;

SELECT (t1.a > t2.x) OR ((t1.a = t2.x) AND (t1.b > t2.y))
FROM t1 INNER JOIN t2;
```

### Greater than or equal (>=)
```sql
SELECT (t1.a, t1.b) >= (t2.x, t2.y) 
FROM t1 INNER JOIN t2;

SELECT (t1.a > t2.x) OR ((t1.a = t2.x) AND (t1.b >= t2.y))
FROM t1 INNER JOIN t2;
```

### IN
```sql
expr IN (value,...)

SELECT 2 IN (0,3,5,7);
SELECT 'wefwf' IN ('wee','wefwf','weg');
```
Returns 1 if expr is equal to any of the values in the IN list, else returns 0. If all values are constants, they are evaluated according to the type of expr and sorted. The search for the item then is done using a binary search. This means IN is very quick if the IN value list consists entirely of constants. Otherwise, type conversion takes place according to the rules described at Type Conversion, but applied to all the arguments.

### INTERVAL
```sql
INTERVAL(N,N1,N2,N3,...)

SELECT INTERVAL(23, 1, 15, 17, 30, 44, 200);  --3
SELECT INTERVAL(10, 1, 10, 100, 1000);        --2
```

### IS
```sql
IS boolean_value

SELECT 1 IS TRUE, 0 IS FALSE, NULL IS UNKNOWN;  --1,1,1
```

### IS NOT
```sql
IS NOT boolean_value

SELECT 1 IS NOT UNKNOWN, 0 IS NOT UNKNOWN, NULL IS NOT UNKNOWN;  --1,1,0
```

### LEAST
```sql
LEAST(value1,value2,...)

SELECT LEAST(2,0);  --0
SELECT LEAST(34.0,3.0,5.0,767.0);   --3.0
```


## Logical Operators

### Logical NOT (!)
```sql
SELECT NOT 10;  --10
SELECT ! (1+1); --0
SELECT ! 1+1;   --1
```

### Logical AND (&&)
```sql
SELECT 1 && 1;  --1
SELECT 1 && 0;  --0
```

### Logical XOR (XOR)
```sql
SELECT 1 XOR 1;  --0
SELECT 1 XOR 0;  --1
```

### Logical OR (||)
```sql
SELECT 1 || 1;  --1
SELECT 1 || 0;  --1
SELECT 0 || 0;  --0
```
Logical OR. When both operands are non-NULL, the result is 1 if any operand is non-zero, and 0 otherwise.


## Operator Precedence
The precedence is the order in which the SQL operators are evaluated.

The following list shows the SQL operator precedence. Operators that appear first in the list have a higher precedence. Operators which are listed together have the same precedence.

* INTERVAL
* BINARY, COLLATE
* !
* - (unary minus), [[bitwise-not|]] (unary bit inversion)
* || (string concatenation)
* ^
* *, /, DIV, %, MOD
* -, +
* <<, >>
* &
* |
* = (comparison), <=>, >=, >, <=, <, <>, !=, IS, LIKE, REGEXP, IN
* BETWEEN, CASE, WHEN, THEN, ELSE, END
* NOT
* &&, AND
* XOR
* || (logical or), OR
* = (assignment), :=














