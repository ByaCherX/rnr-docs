<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Administrative - Table Statements</h1>

## ANALYZE TABLE
```sql
ANALYZE [NO_WRITE_TO_BINLOG | LOCAL] TABLE tbl_name [,tbl_name ...] 
  [PERSISTENT FOR [ALL|COLUMNS ([col_name [,col_name ...]])] 
    [INDEXES ([index_name [,index_name ...]])]]
```
MariaDB uses the stored key distribution to decide the order in which tables should be joined when you perform a join on something other than a constant. In addition, key distributions can be used when deciding which indexes to use for a specific table within a query.





..........













