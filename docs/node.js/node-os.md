<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:left;">Node.js - OS</h1>

<t8s>Stability: 2 - Stable</t8s></br>
<t8s>Source Code: lib/os.js</t8s>

<t8s>Table of contents</t8s>

* Class: OS
  - os.EOL
  - os.arch()
  - os.constants
  - os.cpus()
  - os.devNull
  - os.endianness()
  - os.freemem()
  - os.getPriority([pid])
  - os.homedir()
  - os.hostname()
  - os.loadavg()
  - os.networkInterfaces()
  - os.platform()
  - os.release()
  - os.setPriority([pid, ]priority)
  - os.tmpdir()
  - os.totalmem()
  - os.type()
  - os.uptime()
  - os.userInfo([options])
  - os.version()

### os.EOL
The operating system-specific end-of-line marker.
* \n on POSIX
* \r\n on Windows

### os.arch()
Returns the operating system CPU architecture for which the Node.js binary was compiled. Possible values are 'arm', 'arm64', 'ia32', 'mips', 'mipsel', 'ppc', 'ppc64', 's390', 's390x', 'x32', and 'x64'.

### os.constants
Contains commonly used operating system-specific constants for error codes, process signals, and so on. The specific constants defined are described in ``OS constants``.

### os.cpus()
Returns an array of objects containing information about each logical CPU core.
The properties included on each object include:
* model `<string>`
* speed `<number>` (in MHz)
* times `<Object>`

### os.devNull
The platform-specific file path of the null device.
* ``\\.\nul on Windows``
* ``/dev/null on POSIX``

### os.endianness()
Returns a string identifying the endianness of the CPU for which the Node.js binary was compiled.

Possible values are `'BE'` for big endian and `'LE'` for little endian.

### os.freemem()
Returns the amount of free system memory in bytes as an integer.

### os.homedir()
Returns the string path of the current user's home directory.

On POSIX, it uses the `$HOME` environment variable if defined. Otherwise it uses the effective UID to look up the user's home directory.

On Windows, it uses the `USERPROFILE` environment variable if defined. Otherwise it uses the path to the profile directory of the current user.

### os.hostname()
Returns the host name of the operating system as a string.

### os.loadavg()
Returns an array containing the 1, 5, and 15 minute load averages.

The load average is a measure of system activity calculated by the operating system and expressed as a fractional number.

The load average is a Unix-specific concept. On Windows, the return value is always `[0, 0, 0]`.

### os.networkInterfaces()
Returns an object containing network interfaces that have been assigned a network address.

Each key on the returned object identifies a network interface. The associated value is an array of objects that each describe an assigned network address.

The properties available on the assigned network address object include:
* address `<string>` The assigned IPv4 or IPv6 address
* netmask `<string>` The IPv4 or IPv6 network mask
* family `<string>` Either `IPv4` or `IPv6`
* mac `<string>` The MAC address of the network interface
* internal `<boolean>` `true` if the network interface is a loopback or similar interface that is not remotely accessible; otherwise false
* scopeid `<number>` The numeric IPv6 scope ID (only specified when `family` is `IPv6`)
* cidr `<string>` The assigned IPv4 or IPv6 address with the routing prefix in CIDR notation. If the netmask is invalid, this property is set to null.

### os.platform()
Returns a string identifying the operating system platform for which the Node.js binary was compiled. The value is set at compile time. Possible values are 'aix', 'darwin', 'freebsd','linux', 'openbsd', 'sunos', and 'win32'.

### os.release()
Returns the operating system as a string.

On POSIX systems, the operating system release is determined by calling `uname(3)`. On Windows, GetVersionExW() is used. See https://en.wikipedia.org/wiki/Uname#Examples for more information.

### os.setPriority([pid,]priority)
* pid `<integer>` The process ID to set scheduling priority for. *Default: 0*.
* priority `<integer>` The scheduling priority to assign to the process.

### os.tmpdir()
Returns the operating system's default directory for temporary files as a string.

### os.totalmem()
Returns the total amount of system memory in bytes as an integer.

### os.type()
Returns the operating system name as returned by ``uname(3)``. For example, it returns 'Linux' on Linux, 'Darwin' on macOS, and 'Windows_NT' on Windows.

### os.uptime()
Returns the system uptime in number of seconds.

### os.userInfo([options])
* options ``<Object>``
  - encoding ``<string>`` Character encoding used to interpret resulting strings. If encoding is set to 'buffer', the username, shell, and homedir values will be Buffer instances. Default: 'utf8'.
* Returns: ``<Object>``

Returns information about the currently effective user. On POSIX platforms, this is typically a subset of the password file. The returned object includes the username, uid, gid, shell, and homedir. On Windows, the uid and gid fields are -1, and shell is null.

### os.version()
Returns a string identifying the kernel version.

On POSIX systems, the operating system release is determined by calling uname(3). On Windows, RtlGetVersion() is used, and if it is not available, `GetVersionExW()` will be used. See https://en.wikipedia.org/wiki/Uname#Examples for more information.


