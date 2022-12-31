<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Account Management - ROLE</h1>


## CREATE ROLE
```sql
--Syntax--
CREATE [OR REPLACE] ROLE [IF NOT EXISTS] role 
  [WITH ADMIN 
    {CURRENT_USER | CURRENT_ROLE | user | role}]

--Example--
CREATE ROLE journalist;
CREATE ROLE developer WITH ADMIN lorinda@localhost;
```


## SET ROLE
```sql
--Syntax--
SET ROLE { role | NONE }

--Example--
SET ROLE staff;
SELECT CURRENT_ROLE;    --role: staff
SELECT CURRENT_ROLE();  --role: NULL
```


## DROP ROLE
```sql
--Syntax--
DROP ROLE [IF EXISTS] role_name [,role_name ...]
```
The ``DROP ROLE`` statement removes one or more MariaDB roles. 


## SET DEFAULT ROLE
```sql
--Syntax--
SET DEFAULT ROLE { role | NONE } [ FOR user@host ]

--Example--
SET DEFAULT ROLE journalist;
SET DEFAULT ROLE NONE;
```
The ``SET DEFAULT ROLE`` statement sets a default role for a specified (or current) user. A default role is automatically enabled when a user connects (an implicit ``SET ROLE`` statement is executed immediately after a connection is established).















