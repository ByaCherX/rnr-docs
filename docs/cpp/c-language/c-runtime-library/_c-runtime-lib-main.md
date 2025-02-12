---
title: "C runtime library reference"
description: "Links to information and reference for the Microsoft C runtime library functions."
ms.date: "3/5/2021"
f1_keywords: ["c.runtime"]
helpviewer_keywords: ["CRT", "runtime libraries", "CRT, reference"]
---
# Microsoft C runtime library (CRT) reference

The Microsoft runtime library provides routines for programming the Microsoft Windows operating system. These routines automate many common programming tasks that are not provided by the C and C++ languages.

## C runtime library (CRT) reference tree
---
* ### [C runtime library (CRT) reference](c-run-time-library-reference.md)
---
* ### [CRT library features](.)
---
* [Compatibility](compatibility.md)
  * [UWP Apps, the Windows Runtime, and the C runtime](../c-runtime-library/windows-store-apps-the-windows-runtime-and-the-c-run-time.md)
  * [ANSI C Compliance](../c-runtime-library/ansi-c-compliance.md)
  * [UNIX](../c-runtime-library/unix.md)
  * [Windows Platforms (CRT)](../c-runtime-library/windows-platforms-crt.md)
  * [Backward Compatibility](../c-runtime-library/backward-compatibility.md)
* [Recommendations for choosing between functions and macros](recommendations-for-choosing-between-functions-and-macros.md)
* [Type checking (CRT)](type-checking-crt.md)
* [Direction flag](direction-flag.md)
* [Security features in the (CRT)](security-features-in-the-crt.md)
  * [Security enhanced versions of crt functions](security-enhanced-versions-of-crt-functions.md)
  * [Parameter Validation](../c-runtime-library/parameter-validation.md)
  * [Secure Template Overloads](../c-runtime-library/secure-template-overloads.md)
* [SAL annotations](sal-annotations.md)
* [Multithreaded libraries performance](multithreaded-libraries-performance.md)
* [Link options](link-options.md)
* [Potential errors passing crt objects across dll boundaries](potential-errors-passing-crt-objects-across-dll-boundaries.md)
* [CRT initialization](crt-initialization.md)
* [Global state](global-state.md)
* [Type-generic math](tgmath.md)
* [C runtime (CRT) and C++ Standard Library (STL) .lib files](crt-library-features.md)
* ### [Universal C runtime routines by category](run-time-routines-by-category.md)
---
* [Argument Access](../c-runtime-library/argument-access.md)
* [Buffer Manipulation](../c-runtime-library/buffer-manipulation.md)
* [Byte Classification](../c-runtime-library/byte-classification.md)
* [Character Classification](../c-runtime-library/character-classification.md)
* [Complex math support](../c-runtime-library/complex-math-support.md)
* [Data Alignment](../c-runtime-library/data-alignment.md)
* [Data Conversion](../c-runtime-library/data-conversion.md)
* [Debug Routines](../c-runtime-library/debug-routines.md)
* [Directory Control](../c-runtime-library/directory-control.md)
* [Error Handling](../c-runtime-library/error-handling-crt.md)
* [Exception Handling Routines](../c-runtime-library/exception-handling-routines.md)
* [File Handling](../c-runtime-library/file-handling.md)
* [Floating-Point Support](../c-runtime-library/floating-point-support.md)
* [Input and Output](../c-runtime-library/input-and-output.md)
  * [Text and binary mode file I/O](text-and-binary-mode-file-i-o.md)
  * [Unicode stream I/O in text and binary modes](unicode-stream-i-o-in-text-and-binary-modes.md)
  * [Stream I/O](../c-runtime-library/stream-i-o.md)
  * [Low-level I/O](../c-runtime-library/low-level-i-o.md)
  * [Console and port I/O](../c-runtime-library/console-and-port-i-o.md)
* [Internationalization](../c-runtime-library/internationalization.md)
  * [Locale-related routines](../c-runtime-library/locale.md)
  * [Code pages](code-pages.md)
  * [Interpretation of multibyte character sequences](interpretation-of-multibyte-character-sequences.md)
  * [ISO646 operators](iso646-operators.md)
  * [Single byte and multibyte character sets](single-byte-and-multibyte-character-sets.md)
  * [SBCS and MBSC data types](sbcs-and-mbcs-data-types.md)
  * [Unicode the wide character set](unicode-the-wide-character-set.md)
  * [Using generic text mappings](using-generic-text-mappings.md)
  * [A sample generic-text program](a-sample-generic-text-program.md)
  * [Using tchar h data types withmbcs](using-tchar-h-data-types-with-mbcs.md)
* [Memory Allocation](../c-runtime-library/memory-allocation.md)
* [Process and Environment Control](../c-runtime-library/process-and-environment-control.md)
* [Robustness](../c-runtime-library/robustness.md)
* [Run-Time Error Checking](../c-runtime-library/run-time-error-checking.md)
* [Searching and Sorting](../c-runtime-library/searching-and-sorting.md)
* [String Manipulation (CRT)](../c-runtime-library/string-manipulation-crt.md)
* [System Calls](../c-runtime-library/system-calls.md)
* [Time Management](../c-runtime-library/time-management.md)
* [Windows runtime unsupported CRT functions](windows-runtime-unsupported-crt-functions.md)
* [**Internal CRT globals and functions**](internal-crt-globals-and-functions.md)
* ### [Global variables and standard types](global-variables-and-standard-types.md)
---
* [Global variables](../c-runtime-library/global-variables.md)
* [Control flags](../c-runtime-library/control-flags.md)
  * [_CRTDBG_MAP_ALLOC](../c-runtime-library/crtdbg-map-alloc.md)
  * [_DEBUG](../c-runtime-library/debug.md)
  * [_crtDbgFlag](../c-runtime-library/crtdbgflag.md)
* [Standard types](../c-runtime-library/standard-types.md)
* ### [Global constants](global-constants.md)
---
* [32-Bit Windows Time/Date Formats](../c-runtime-library/32-bit-windows-time-date-formats.md)
* [BUFSIZ](../c-runtime-library/bufsiz.md)
* [CLOCKS_PER_SEC, CLK_TCK](../c-runtime-library/clocks-per-sec-clk-tck.md)
* [Commit-To-Disk Constants](../c-runtime-library/commit-to-disk-constants.md)
* [_CRT_DISABLE_PERFCRIT_LOCKS](../c-runtime-library/crt-disable-perfcrit-locks.md)
* [Data Type Constants](../c-runtime-library/data-type-constants.md)
* [Environmental Constants](../c-runtime-library/environmental-constants.md)
* [EOF, WEOF](../c-runtime-library/eof-weof.md)
* [errno Constants](../c-runtime-library/errno-constants.md)
* [Exception-Handling Constants](../c-runtime-library/exception-handling-constants.md)
* [EXIT_SUCCESS, EXIT_FAILURE](../c-runtime-library/exit-success-exit-failure.md)
* [File Attribute Constants](../c-runtime-library/file-attribute-constants.md)
* [File Constants](../c-runtime-library/file-constants.md)
* [File Permission Constants](../c-runtime-library/file-permission-constants.md)
* [File Read/Write Access Constants](../c-runtime-library/file-read-write-access-constants.md)
* [File Translation Constants](../c-runtime-library/file-translation-constants.md)
* [FILENAME_MAX](../c-runtime-library/filename-max.md)
* [FOPEN_MAX, _SYS_OPEN](../c-runtime-library/fopen-max-sys-open.md)
* [_FREEENTRY, _USEDENTRY](../c-runtime-library/freeentry-usedentry.md)
* [fseek, _lseek Constants](../c-runtime-library/fseek-lseek-constants.md)
* [Heap Constants](../c-runtime-library/heap-constants.md)
* [_HEAP_MAXREQ](../c-runtime-library/heap-maxreq.md)
* [HUGE_VAL, _HUGE](../c-runtime-library/huge-val-huge.md)
* [Locale Categories](../c-runtime-library/locale-categories.md)
* [_locking Constants](../c-runtime-library/locking-constants.md)
* [Math Constants](../c-runtime-library/math-constants.md)
* [Math Error Constants](../c-runtime-library/math-error-constants.md)
* [_MAX_ENV](../c-runtime-library/max-env.md)
* [MB_CUR_MAX](../c-runtime-library/mb-cur-max.md)
* [NULL](../c-runtime-library/null-crt.md)
* [Path Field Limits](../c-runtime-library/path-field-limits.md)
* [RAND_MAX](../c-runtime-library/rand-max.md)
* [setvbuf Constants](../c-runtime-library/setvbuf-constants.md)
* [Sharing Constants](../c-runtime-library/sharing-constants.md)
* [signal Constants](../c-runtime-library/signal-constants.md)
* [signal Action Constants](../c-runtime-library/signal-action-constants.md)
* [spawn Constants](../c-runtime-library/spawn-constants.md)
* [_stat Structure st_mode Field Constants](../c-runtime-library/stat-structure-st-mode-field-constants.md)
* [stdin, stdout, stderr](../c-runtime-library/stdin-stdout-stderr.md)
* [TMP_MAX, L_tmpnam](../c-runtime-library/tmp-max-l-tmpnam.md)
* [Translation Mode Constants](../c-runtime-library/translation-mode-constants.md)
* [_TRUNCATE](../c-runtime-library/truncate.md)
* [TZNAME_MAX](../c-runtime-library/tzname-max.md)
* [_WAIT_CHILD, _WAIT_GRANDCHILD](../c-runtime-library/wait-child-wait-grandchild.md)
* [WCHAR_MAX](../c-runtime-library/wchar-max.md)
* [WCHAR_MIN](../c-runtime-library/wchar-min.md)
* ### [Generic-text mappings](generic-text-mappings.md)
---
* [Using Generic-Text Mappings](../c-runtime-library/using-generic-text-mappings.md)
* [Data types](../c-runtime-library/data-type-mappings.md)
* [Constants and global variables](../c-runtime-library/constant-and-global-variable-mappings.md)
* [Routine mappings](../c-runtime-library/routine-mappings.md)
* ### [Language and country/region strings](locale-names-languages-and-country-region-strings.md)
---
[Language Strings](../c-runtime-library/language-strings.md)
[Country/Region Strings](../c-runtime-library/country-region-strings.md)
* ### [Function family overviews](function-family-overviews.md)
---
* [_exec, _wexec](exec-wexec-functions.md)
* [Filename search functions](filename-search-functions.md)
* [Format specification syntax for 'printf' and 'wprintf'](format-specification-syntax-printf-and-wprintf-functions.md)
* [Format specification field characters: 'scanf' and 'wscanf'](format-specification-fields-scanf-and-wscanf-functions.md)
* ['is', 'isw' functions](is-isw-routines.md)
* ['_ismbb' functions](ismbb-routines.md)
* ['_ismbc' functions](ismbc-routines.md)
* [operator 'delete' (CRT)](delete-operator-crt.md)
* [operator 'new' (CRT)](new-operator-crt.md)
* ['printf' positional parameter functions](printf-p-positional-parameters.md)
* ['scanf' type field characters](scanf-type-field-characters.md)
* ['scanf' width specification](scanf-width-specification.md)
* [_spawn, _wspawn functions](spawn-wspawn-functions.md)
* ['strcoll' functions](strcoll-functions.md)
* [String to numeric value functions](string-to-numeric-value-functions.md)
* ['vprintf' functions](vprintf-functions.md)
* ### [Obsolete function](obsolete-function.md)
---
**⚠️ This documentation is not included in VS 2019**

* [iswctype](../c-runtime-library/reference/isctype-iswctype-isctype-l-iswctype-l.md)
* [GetProcAddress](../build/getprocaddress.md)
* ### [Alphabetical function reference](reference/crt-alphabetical-function-reference.md)
---
* [abort](abort.md)
* [abs](abs-labs-llabs-abs64.md)
* [_abs64](abs-labs-llabs-abs64.md)
* [access](access-crt.md)
* [_access](access-waccess.md)
* [_access_s](access-s-waccess-s.md)
* [acos](acos-acosf-acosl.md)
* [acosf](acos-acosf-acosl.md)
* [acosh](acosh-acoshf-acoshl.md)
* [acoshf](acosh-acoshf-acoshl.md)
* [acoshl](acosh-acoshf-acoshl.md)
* [acosl](acos-acosf-acosl.md)
* [_aligned_free](aligned-free.md)
* [_aligned_free_dbg](aligned-free-dbg.md)
* [_aligned_malloc](aligned-malloc.md)
* [_aligned_malloc_dbg](aligned-malloc-dbg.md)
* [_aligned_msize](aligned-msize.md)
* [_aligned_msize_dbg](aligned-msize-dbg.md)
* [_aligned_offset_malloc](aligned-offset-malloc.md)
* [_aligned_offset_malloc_dbg](aligned-offset-malloc-dbg.md)
* [...](reference/crt-alphabetical-function-reference.md)
---
