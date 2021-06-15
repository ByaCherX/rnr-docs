---
title: "AddressSanitizer"
description: "Top-level description of the AddressSanitizer feature for Microsoft C/C++."
ms.date: 03/05/2021
f1_keywords: ["AddressSanitizer"]
helpviewer_keywords: ["ASan", "AddressSanitizer", "Address Sanitizer", "compiling for AddressSanitizer"]
---
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<h1 style="text-align:center">C/C++ Code Sanitizers <i class="bi bi-bug-fill"></i></h1>

The C & C++ languages are powerful, but can suffer from a class of bugs that affect program correctness and program security. Starting in Visual Studio 2019 version 16.9, the Microsoft C/C++ compiler (MSVC) and IDE supports the *AddressSanitizer*. AddressSanitizer (ASan) is a compiler and runtime technology that exposes many hard-to-find bugs with **zero** false positives:

Use AddressSanitizer to reduce your time spent on:

- Basic correctness
- Cross platform portability
- Security
- Stress testing
- Integrating new code

ddressSanitizer is integrated with the Visual Studio project system, the CMake build system, and the IDE. Projects can enable AddressSanitizer by setting a project property, or by using one extra compiler option: **`/fsanitize=address`**. The new option is compatible with all levels of optimization and configurations of x86 and x64. However, it's incompatible with [edit-and-continue](/visualstudio/debugger/edit-and-continue-visual-cpp), [incremental linking](../build/reference/incremental-link-incrementally.md), and [`/RTC`](../build/reference/rtc-run-time-error-checks.md).

## Code Sanitizers Tree
---

* #### [Adress Sanitizers Overview](asan.md)
   * [Asan Build and Language Reference](asan-building.md)
   * [AddressSanitizer build and language reference](./asan-building.md)
   * [AddressSanitizer runtime reference](./asan-runtime.md)
   * [AddressSanitizer debugger integration](./asan-debugger-integration.md)
   * [AddressSanitizer shadow bytes](./asan-shadow-bytes.md)
   * [AddressSanitizer cloud or distributed testing](./asan-offline-crash-dumps.md)
   * [AddressSanitizer Know Issues](asan-known-issues.md)

* #### [AddressSanitizer error examples](./asan-error-examples.md)
   * [Error: alloc-dealloc-mismatch](./error-alloc-dealloc-mismatch.md)
   * [Error: allocation-size-too-big](./error-allocation-size-too-big.md)
   * [Error: calloc-overflow](./error-calloc-overflow.md)
   * [Error: double-free](./error-double-free.md)
   * [Error: dynamic-stack-buffer-overflow](./error-dynamic-stack-buffer-overflow.md)
   * [Error: global-overflow](./error-global-buffer-overflow.md)
   * [Error: heap-buffer-overflow](./error-heap-buffer-overflow.md)
   * [Error: heap-use-after-free](./error-heap-use-after-free.md)
   * [Error: invalid-allocation-alignment](./error-invalid-allocation-alignment.md)
   * [Error: memcpy-param-overlap](./error-memcpy-param-overlap.md)
   * [Error: new-delete-type-mismatch](./error-new-delete-type-mismatch.md)
   * [Error: stack-buffer-overflow](./error-stack-buffer-overflow.md)
   * [Error: stack-buffer-underflow](./error-stack-buffer-underflow.md)
   * [Error: stack-use-after-return](./error-stack-use-after-return.md)
   * [Error: stack-use-after-scope](./error-stack-use-after-scope.md)
   * [Error: strncat-param-overlap](./error-strncat-param-overlap.md)
   * [Error: use-after-poison](./error-use-after-poison.md)
