<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Data Defination - MERGE</h1>

The MERGE storage engine, also known as the MRG_MyISAM engine, is a collection of identical MyISAM tables that can be used as one. 
"Identical" means that all tables have identical column and index information. You cannot merge *MyISAM* tables in which the columns are listed in a different order, do not have exactly the same columns, or have the indexes in different order. 
However, any or all of the MyISAM tables can be compressed with myisampack. Columns names and indexes names can be different, as long as data types and NULL/NOT NULL clauses are the same.
Differences in table options such as AVG_ROW_LENGTH, MAX_ROWS, or PACK_KEYS do not matter.

Each index in a MERGE table must match an index in underlying MyISAM tables, but the opposite is not true. Also, a MERGE table cannot have a PRIMARY KEY or UNIQUE indexes, because it cannot enforce uniqueness over all underlying tables.

The following options are meaningful for MERGE tables:

* **UNION** This option specifies the list of the underlying MyISAM tables. The list is enclosed between parentheses and separated with commas.

* **INSERT_METHOD** This options specifies whether, and how, INSERTs are allowed for the table. Allowed values are: NO (INSERTs are not allowed), FIRST (new rows will be written into the first table specified in the UNION list), LAST (new rows will be written into the last table specified in the UNION list). The default value is NO.

```sql
--Examples--
CREATE TABLE t1 (
    a INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    message CHAR(20)) ENGINE=MyISAM;

CREATE TABLE t2 (
    a INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    message CHAR(20)) ENGINE=MyISAM;


INSERT INTO t1 (message) VALUES ('Testing'),('table'),('t1');

INSERT INTO t2 (message) VALUES ('Testing'),('table'),('t2');

CREATE TABLE total (
    a INT NOT NULL AUTO_INCREMENT,
    message CHAR(20), INDEX(a))
    ENGINE=MERGE UNION=(t1,t2) INSERT_METHOD=LAST;

SELECT * FROM total;
/*
+---+---------+
| a | message |
+---+---------+
| 1 | Testing |
| 2 | table   |
| 3 | t1      |
| 1 | Testing |
| 2 | table   |
| 3 | t2      |
+---+---------+
*/
```




