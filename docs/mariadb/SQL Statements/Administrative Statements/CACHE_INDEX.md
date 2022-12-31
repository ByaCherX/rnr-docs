<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Administrative - CACHE_INDEX</h1>

```sql
--Syntax--
CACHE INDEX                      
  tbl_index_list [, tbl_index_list] ...
  IN key_cache_name                    

tbl_index_list:
  tbl_name [[INDEX|KEY] (index_name[, index_name] ...)]

--Example--
CACHE INDEX t1, t2, t3 IN hot_cache;
```
The ``CACHE INDEX`` statement assigns table indexes to a specific key cache. It is used only for MyISAM tables.

A default key cache exists and cannot be destroyed. To create more key caches, the key_buffer_size server system variable.












