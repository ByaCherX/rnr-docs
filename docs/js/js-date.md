<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

### The ECMAScript epoch and timestamps
A JavaScript date is fundamentally specified as the number of milliseconds that have elapsed since the ECMAScript epoch, which is defined as January 1, 1970, UTC (equivalent to the [UNIX epoch](https://en.wikipedia.org/wiki/Unix_time)).

It should be noted that the maximum `Date` is not of the same value as the maximum safe integer (`Number.MAX_SAFE_INTEGER` is 9,007,199,254,740,991). Instead, it is defined in ECMA-262 that a maximum of ±100,000,000 (one hundred million) days relative to January 1, 1970 UTC (that is, April 20, 271821 BCE ~ September 13, 275760 CE) can be represented by the standard `Date` object (equivalent to ±8,640,000,000,000,000 milliseconds).

## Constructor

### Data() constructor
Creates a JavaScript `Date` instance that represents a single moment in time in a platform-independent format.Date objects contain a Number that represents milliseconds since 1 January 1970 UTC.
```js
// syntax
new Date()
new Date(value)
new Date(dateString)
new Date(dateObject)

new Date(year, monthIndex)
new Date(year, monthIndex, day)
new Date(year, monthIndex, day, hours)
new Date(year, monthIndex, day, hours, minutes)
new Date(year, monthIndex, day, hours, minutes, seconds)
new Date(year, monthIndex, day, hours, minutes, seconds, milliseconds)

// example
let birthday = new Date('December 17, 1995 13:24:00')
let birthday = new Date('1995-12-17T13:24:00')
let birthday = new Date(1995, 11, 17)
```

## Static Methods

### Date.now()
The static `Date.now()` method returns the number of milliseconds elapsed since January 1, 1970 00:00:00 UTC.
```js
// syntax
Date.now()

// example
// reduced time precision (2ms) in Firefox 60
Date.now()
// 1519211809934
// 1519211810362
// 1519211811670
// ...
```

### Date.parse()
The `Date.parse()` method parses a string representation of a date, and returns the number of milliseconds since January 1, 1970, 00:00:00 UTC or NaN if the string is unrecognized or, in some cases, contains illegal date values (e.g. 2015-02-31).

It is not recommended to use `Date.parse` as until ES5, parsing of strings was entirely implementation dependent. There are still many differences in how different hosts parse date strings, therefore date strings should be manually parsed (a library can help if many different formats are to be accommodated).
```js
// syntax
Date.parse(dateString)

// example
Date.parse("2019-01-01")
Date.parse("2019-01-01T00:00:00.000Z")
Date.parse("2019-01-01T00:00:00.000+00:00")
```

### Date.UTC()
`UTC()` takes comma-delimited date and time parameters and returns the number of milliseconds between January 1, 1970, 00:00:00, universal time and the specified date and time.

Years between 0 and 99 are converted to a year in the 20th century `(1900 + year)`. For example, 95 is converted to the year 1995.
```js
// syntax
Date.UTC(year)
Date.UTC(year, month)
Date.UTC(year, month, day)
Date.UTC(year, month, day, hour)
Date.UTC(year, month, day, hour, minute)
Date.UTC(year, month, day, hour, minute, second)
Date.UTC(year, month, day, hour, minute, second, millisecond)

// example
let utcDate = new Date(Date.UTC(2018, 11, 1, 0, 0, 0));
```

## Instance Methods

### Date.getDate()
The `getDate()` method returns the day of the month for the specified date according to local time.
```js
// syntax
getDate()

// example
var Xmas95 = new Date('December 25, 1995 23:15:30');
var day = Xmas95.getDate();

console.log(day); // 25
```

### Date.getDay()
The `getDay()` method returns the day of the week for the specified date according to local time, where 0 represents Sunday. For the day of the month, see `Date.prototype.getDate()`.

### Date.getYear()

### Date.getFullYear()
The value returned by `getFullYear()` is an absolute number. For dates between the years 1000 and 9999, getFullYear() returns a four-digit number, for example, 1995. Use this function to make sure a year is compliant with years after 2000.

### Date.getHours()
The `getHours()` method returns the hour for the specified date, according to local time.

### Date.getMilliseconds()
The `getMilliseconds()` method returns the milliseconds in the specified date according to local time.

### Date.getMinutes()
The `getMinutes()` method returns the minutes in the specified date according to local time.

### Date.getMonth()
The `getMonth()` method returns the month in the specified date according to local time, as a zero-based value (where zero indicates the first month of the year).

### Date.getSecond()
The `getSeconds()` method returns the seconds in the specified date according to local time.

### Date.getTime()
The `getTime()` method returns the number of milliseconds since the ECMAScript epoch.

You can use this method to help assign a date and time to another Date object. This method is functionally equivalent to the valueOf() method.

### Date.getTimezoneOffset()
`date.getTimezoneOffset()` returns the difference, in minutes, between date as evaluated in the UTC time zone, and date as evaluated in the local time zone — that is, the time zone of the host system in which the browser is being used (if the code is run from the Web in a browser), or otherwise the host system of whatever JavaScript runtime (for example, a Node.js environment) the code is executed in.

### Date.getUTCDate()
The `getUTCDate()` method returns the day of the month(from 1 to 31) in the specified date according to universal time.

### Date.setDate()
The `setDate()` method changes the day of the month of a given Date instance, based on local time.

To instead change the day of the month for a given Date instance based on UTC time, use the setUTCDate() method.

### Date.setTime()
Use the `setTime()` method to help assign a date and time to another Date object.

### Date.toJSON()
Date instances refer to a specific point in time. Calling `toJSON()` returns a string (using toISOString()) representing the Date object's value. This method is generally intended to, by default, usefully serialize Date objects during JSON serialization.

### Date.toTimeString()
Date instances refer to a specific point in time. Calling toString() will return the date formatted in a human readable form in English. Sometimes it is desirable to obtain a string of the time portion; such a thing can be accomplished with the `toTimeString()` method.

The `toTimeString()` method is especially useful because compliant engines implementing ECMA-262 may differ in the string obtained from toString() for Date objects, as the format is implementation-dependent; simple string slicing approaches may not produce consistent results across multiple engines.










