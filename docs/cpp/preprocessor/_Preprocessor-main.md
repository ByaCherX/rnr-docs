---
title: "C/C++ preprocessor main reference"
description: "Reference for the Microsoft C/C++ compiler preprocessor main"
ms.date: 02/06/2021
helpviewer_keywords: ["preprocessor", "preprocessor, reference main"]
ms.assetid: e4a52843-7016-4f6d-8b40-cb1ace18f805
---

<h1 style="text-align: center">C/C++ Preprocessor Reference</h1>

The C/C++ preprocessor reference explains the preprocessor as it is implemented in Microsoft C/C++. The preprocessor performs preliminary operations on C and C++ files before they are passed to the compiler. You can use the preprocessor to conditionally compile code, insert files, specify compile-time error messages, and apply machine-specific rules to sections of code.

In Visual Studio 2019 the /Zc:preprocessor compiler option provides a fully conformant C11 and C17 preprocessor. This is the default when you use the compiler flag /std:c11 or /std:c17.

## Preprocessor Reference Tree

* ### [Preprocessor](preprocessor.md)
    * [Preprocessor Experimental Overview](preprocessor-experimental-overview.md)
    * [Phases of translation](phases-of-translation.md)
    * [Preprocessor directives](../preprocessor/preprocessor-directives.md)
      * [#define](../preprocessor/hash-define-directive-c-cpp.md)
      * [#elif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)
      * [#else](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)
      * [#endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)
      * [#error](../preprocessor/hash-error-directive-c-cpp.md)
      * [#if](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)
      * [#ifdef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)
      * [#ifndef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)
      * [#import](../preprocessor/hash-import-directive-cpp.md)
      * [#include](../preprocessor/hash-include-directive-c-cpp.md)
      * [#line](../preprocessor/hash-line-directive-c-cpp.md)
      * [#pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
      * [null directive](null-directive-md)
      * [#undef](../preprocessor/hash-undef-directive-c-cpp.md)
      * [#using](../preprocessor/hash-using-directive-cpp.md)
   * [Preprocessor operators](../preprocessor/preprocessor-operators.md)
      * [Stringizing operator (#)](../preprocessor/stringizing-operator-hash.md)
      * [Charizing operator (#@)](../preprocessor/charizing-operator-hash-at.md)
      * [Token-pasting operator (##)](../preprocessor/token-pasting-operator-hash-hash.md)
      * [defined operator](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)
   * [Preprocessor Macros (C/C++)](macros-c-cpp.md)
      * [Macros and C++](../preprocessor/macros-and-cpp.md)
      * [Variadic Macros](../preprocessor/variadic-macros.md)
      * [Predefined macros](../preprocessor/predefined-macros.md)
      * [Predefined macros](../preprocessor/predefined-macros.md)
 * ### [Preprocessor Grammar summary (C/C++)](grammar-summary-c-cpp.md)
 * ### [Pragmas](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
    * [alloc_text](../preprocessor/alloc-text.md)
    * [auto_inline](../preprocessor/auto-inline.md)
    * [bss_seg](../preprocessor/bss-seg.md)
    * [check_stack](../preprocessor/check-stack.md)
    * [code_seg](../preprocessor/code-seg.md)
    * [comment](../preprocessor/comment-c-cpp.md)
    * [component](../preprocessor/component.md)
    * [conform](../preprocessor/conform.md)
    * [const_seg](../preprocessor/const-seg.md)
    * [data_seg](../preprocessor/data-seg.md)
    * [deprecated](../preprocessor/deprecated-c-cpp.md)
    * [detect_mismatch](../preprocessor/detect-mismatch.md)
    * [endregion](../preprocessor/region-endregion.md)
    * [fenv_access](../preprocessor/fenv-access.md)
    * [float_control](../preprocessor/float-control.md)
    * [fp_contract](../preprocessor/fp-contract.md)
    * [function](../preprocessor/function-c-cpp.md)
    * [hdrstop](../preprocessor/hdrstop.md)
    * [include_alias](../preprocessor/include-alias.md)
    * [init_seg](../preprocessor/init-seg.md)
    * [inline_depth](../preprocessor/inline-depth.md)
    * [inline_recursion](../preprocessor/inline-recursion.md)
    * [intrinsic](../preprocessor/intrinsic.md)
    * [loop](../preprocessor/loop.md)
    * [make_public](../preprocessor/make-public.md)
    * [managed](../preprocessor/managed-unmanaged.md)
    * [message](../preprocessor/message.md)
    * [omp](../preprocessor/omp.md)
    * [once](../preprocessor/once.md)
    * [optimize](../preprocessor/optimize.md)
    * [pack](../preprocessor/pack.md)
    * [pointers_to_members](../preprocessor/pointers-to-members.md)
    * [pop_macro](../preprocessor/pop-macro.md)
    * [push_macro](../preprocessor/push-macro.md)
    * [region](../preprocessor/region-endregion.md)
    * [runtime_checks](../preprocessor/runtime-checks.md)
    * [section](../preprocessor/section.md)
    * [setlocale](../preprocessor/setlocale.md)
    * [strict_gs_check](../preprocessor/strict-gs-check.md)
    * [unmanaged](../preprocessor/managed-unmanaged.md)
    * [vtordisp](../preprocessor/vtordisp.md)
    * [warning](../preprocessor/warning.md)
---

