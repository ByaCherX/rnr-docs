<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Administrative - Analyze & Explain Statements</h1>

## ANALYZE Statement
The ``ANALYZE`` statement is similar to the ``EXPLAIN`` statement. ``ANALYZE`` statement will invoke the optimizer, execute the statement, and then produce ``EXPLAIN`` output instead of the result set. The ``EXPLAIN`` output will be annotated with statistics from statement execution.

```sql
ANALYZE explainable_statement;

ANALYZE SELECT * FROM [table]
```


## EXPLAIN
```sql
--Syntax--
EXPLAIN tbl_name [col_name | wild]
EXPLAIN [EXTENDED | PARTITIONS | FORMAT=JSON] 
  {SELECT select_options | UPDATE update_options | DELETE delete_options}

--Example--
SHOW EXPLAIN FOR 1;
```
The ``EXPLAIN`` statement can be used either as a synonym for ``DESCRIBE`` or as a way to obtain information about how MariaDB executes a ``SELECT``, ``UPDATE`` or ``DELETE`` statement:

<h3 class="h3color">Columns in EXPLAIN ... SELECT</h3>

| Column name | Description |
|-------------|-------------|
| id          | Sequence number that shows in which order tables are joined. |
| select_type | What kind of SELECT the table comes from. |
| table       | Alias name of table. Materialized temporary tables for sub queries are named < subquery#> |
| type        | How rows are found from the table (join type). |
| possible_keys | keys in table that could be used to find rows in the table |
| key         | The name of the key that is used to retrieve rows. NULL is no key was used. |
| key_len     | How many bytes of the key that was used (shows if we are using only parts of the multi-column key). |
| ref         | The reference that is used as the key value. |
| rows        | An estimate of how many rows we will find in the table for each key lookup. |
| Extra       | Extra information about this join. |



















