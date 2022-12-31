<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Built-in Functions - Date & Time Functions </h1>

## Date and Time Units
The INTERVAL keyword can be used to add or subtract a time interval of time to a DATETIME, DATE or TIME value

```sql
INTERVAL time_quantity time_unit
```

For example, the ``SECOND`` unit is used below by the ``DATE_ADD()`` function:
```sql
SELECT '2008-12-31 23:59:59' + INTERVAL 1 SECOND;
```

The following units are valid:
| Unit | Description |
|--|--|
| MICROSECOND | Microseconds |
| SECOND      | Seconds      |
| MINUTE      | Minutes      |
| HOUR        | Hourse       |
| DAY         | Days         |
| WEEK        | Weeks        |
| MONTH       | Months       |
| QUARTER     | Quarters     |
| YEAR        | Years        |
| SECOND_MICROSECOND | Seconds Microseconds |
| ... | ... |


Date & Time Functions:
* ADD_MONTH
* ADDDATE
* ADDTIME
* CONVERT_TZ
* CURDATE
* CURRENT_DATE
* CURRENT_TIME
* CURRENT_TIMESTAMP
* CURTIME
* DATE Function
* DATEDIFF
* DATE_ADD
* DATE_FORMAT
* DATE_SUB
* DAY
* DAYNAME
* DAYOFMONTH
* DAYOFWEEK
* EXTRACT
* FROM_DAYS
* FROM_UNIXTIME
* GET_FORMAT
* HOUR
* LAST_DAY
* LOCALTIME
* MAKEDATE
* MICROSECOND
* MINUTE
* MONTH
* NOW
* PERIOD_ADD
* QUARTER
* SECOND
* STR_TO_DATE
* SUBDATE
* SUBTIME
* SYSDATE
* TIME Function
* UTC_DATE
* UTC_TIME
* WEEK
* YEAR
