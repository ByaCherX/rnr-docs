---
description: "Learn more about: Compiler Intrinsics and Assembler"
title: "Compiler intrinsics and Assembler"
ms.date: "05/06/2021"
helpviewer_keywords: ["assembler, compiler", "compiler assembler", "cl.exe compiler, performance", "cl.exe compiler, assembler"]
ms.assetid: 48bb9929-7d78-4fd8-a092-ae3c9f971858
---

# Compiler intrinsics and assembly language 

If a function is an intrinsic, the code for that function is usually inserted inline, avoiding the overhead of a function call and allowing highly efficient machine instructions to be emitted for that function. An intrinsic is often faster than the equivalent inline assembly, because the optimizer has a built-in knowledge of how many intrinsics behave, so some optimizations can be available that are not available when inline assembly is used. Also, the optimizer can expand the intrinsic differently, align buffers differently, or make other adjustments depending on the context and arguments of the call.

The use of intrinsics affects the portability of code, because intrinsics that are available in Visual C++ might not be available if the code is compiled with other compilers and some intrinsics that might be available for some target architectures are not available for all architectures. However, intrinsics are usually more portable than inline assembly. The intrinsics are required on 64-bit architectures where inline assembly is not supported.

Some intrinsics, such as __assume and __ReadWriteBarrier, provide information to the compiler, which affects the behavior of the optimizer.

## Compiler intrinsics tree
---
   * [ARM intrinsics](./intrinsics/arm-intrinsics.md)
   * [ARM64 intrinsics](./intrinsics/arm64-intrinsics.md)
   * [x86 intrinsics list](./intrinsics/x86-intrinsics-list.md)
   * [x64 (amd64) Intrinsics List](./intrinsics/x64-amd64-intrinsics-list.md)
   * [Intrinsics available on all architectures](./intrinsics/intrinsics-available-on-all-architectures.md)
   * [Alphabetical listing of intrinsic functions](./intrinsics/alphabetical-listing-of-intrinsic-functions.md)

## Microsoft C/C++ x86 inline assembler
---
   * [Inline Assembler Overview](./inline/inline-assembler-overview.md)
   * [Advantages of Inline Assembly](./inline/advantages-of-inline-assembly.md)
   * [__asm](./inline/asm.md)
   * [Using Assembly Language in __asm Blocks](./inline/using-assembly-language-in-asm-blocks.md)
     * [Instruction Set for Inline Assembly](../../assembler/inline/instruction-set-for-inline-assembly.md)
     * [MASM Expressions in Inline Assembly](../../assembler/inline/masm-expressions-in-inline-assembly.md)
     * [Data Directives and Operators in Inline Assembly](../../assembler/inline/data-directives-and-operators-in-inline-assembly.md)
     * [EVEN and ALIGN Directives](../../assembler/inline/even-and-align-directives.md)
     * [MASM Macro Directives in Inline Assembly](../../assembler/inline/masm-macro-directives-in-inline-assembly.md)
     * [Segment References in Inline Assembly](../../assembler/inline/segment-references-in-inline-assembly.md)
     * [Type and Variable Sizes in Inline Assembly](../../assembler/inline/type-and-variable-sizes-in-inline-assembly.md)
     * [Assembly-Language Comments](../../assembler/inline/assembly-language-comments.md)
     * [The _emit Pseudoinstruction](../../assembler/inline/emit-pseudoinstruction.md)
     * [Debugging and Listings for Inline Assembly](../../assembler/inline/debugging-and-listings-for-inline-assembly.md)
     * [Intel's MMX Instruction Set](../../assembler/inline/intel-s-mmx-instruction-set.md)
   * [Using C or C++ in __asm Blocks](./inline/using-c-or-cpp-in-asm-blocks.md)
     * [Using Operators in __asm Blocks](../../assembler/inline/using-operators-in-asm-blocks.md)
     * [Using C or C++ Symbols_in __asm Blocks](../../assembler/inline/using-c-or-cpp-symbols-in-asm-blocks.md)
     * [Accessing C or C++ Data in __asm Blocks](../../assembler/inline/accessing-c-or-cpp-data-in-asm-blocks.md)
     * [Writing Functions with Inline Assembly](../../assembler/inline/writing-functions-with-inline-assembly.md)
   * [Using and Preserving Registers in Inline Assembly](./inline/using-and-preserving-registers-in-inline-assembly.md)
   * [Jumping to Labels in Inline Assembly](./inline/jumping-to-labels-in-inline-assembly.md)
   * [Calling C Functions in Inline Assembly](./inline/calling-c-functions-in-inline-assembly.md)
   * [Calling C++ Functions in Inline Assembly](./inline/calling-cpp-functions-in-inline-assembly.md)
   * [Defining __asm Blocks as C Macros](./inline/defining-asm-blocks-as-c-macros.md)
   * [Optimizing Inline Assembly](./inline/optimizing-inline-assembly.md)

## Arm Assembler Reference 
---
   * [ARM assembler reference](./arm/arm-assembler-reference.md)
   * [ARM Assembler Command-Line Reference](../../assembler/arm/arm-assembler-command-line-reference.md)
   * [ARM Assembler Diagnostic Messages](../../assembler/arm/arm-assembler-diagnostic-messages.md)
   * [ARM Assembler Directives](../../assembler/arm/arm-assembler-directives.md)
   * [ARM Architecture Reference Manual](https://developer.arm.com/search#q=ARM%20Architecture%20Reference%20Manual)
   * [ARM Compiler armasm User Guide](https://developer.arm.com/search#q=ARM%20Compiler%20armasm%20User%20Guide)

## x86 and x64 assembler reference
---
   * [Microsoft macro assembler reference](./masm/microsoft-macro-assembler-reference.md)
   * [MASM for x64 (ml64.exe)](./masm/masm-for-x64-ml64-exe.md)
   * [ML and ML64 command-line reference](./masm/ml-and-ml64-command-line-reference.md)
   * [ML error messages](./masm/ml-error-messages.md)
   * [Directives reference (MASM)](./masm/directives-reference.md)
   * [Symbols Reference](./masm/symbols-reference.md)
   * [MASM Operators Reference](./masm/operators-reference.md)
   * [Processor Manufacturer Programming Manuals](./masm/processor-manufacturer-programming-manuals.md)
   * [MASM BNF Grammar](./masm/masm-bnf-grammar.md)
