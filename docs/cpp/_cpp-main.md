---
description: "C++ Language Reference"
title: "C++ Language Reference"
ms.custom: "index-page"
ms.date: "29/05/2021"
helpviewer_keywords: ["C++, main"]
ms.assetid: unknown ?
---
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<style>
r {color: rgb(250,0,0)}
</style>

<h1 style="text-align:center;">C++ Language Reference Main <i class="bi bi-code-slash"></i></h1>

![GitHub repo size](https://img.shields.io/github/repo-size/ByaCherX/rds-docs) 

## C++ Document Libraries <i class="bi bi-journals"></i>
|Section|Description|
|-|-|
|<r>➔ </r>C++ Language Main Documents|This documentation is the central location of the cpp|
|[➔](c-language/_c-main.md) C Language Reference (*dev)|C programming language as implemented in Microsoft C.|
|[➔](../cpp/standard-library/_standard-library-main.md) C++ Standard Library Main Documents|Provides standard library for C language|
|[➔](c-language/c-runtime-library/_c-runtime-lib-main.md) C Runtime Library (CRT)|Microsoft runtime library provides routines for programming operating system|
|[➔](../cpp/atl/_ATL-main.md) Active Template Library (ATL)|(ATL) is a set of template-based C++ classes that let you create|
|[➔](../cpp/preprocessor/_Preprocessor-main.md) C/C++ Preprocessor Reference|The C/C++ preprocessor reference explains the preprocessor|
|[➔](../cpp/cppcx/_cppcx-main.md) C++/CX Language Reference|C++/CX is a set of extensions of the C++ language.|
|[➔](../cpp/assembler/_asm-main.md) Compiler Intrinsics and assembly language|processor-specific code for maximum performance and control.|
|[➔](sanitizers/_code-sanitizers-main.md) C/C++ Code Sanitizers (Beta)|class of bugs that affect program correctness and program security.|
|[➔](parallel-programming/_parallel-programming-main.md) Parallel Programming in Visual C++|C++ Accelerated Massive Parallelism (C++ AMP)|

## C++ Language Reference

For an overview of Modern C++ programming practices, see [Welcome Back to C++](welcome-back-to-cpp-modern-cpp.md).

## C++ Language Reference Tree <i class="bi bi-list-nested"></i>
---

* ### [C++ Getting Started](../cpp/cpp-overview.md)
   * [C++ basics overview](../cpp/cpp-basics-overview.md)

* ### [Lexical Conventions](../cpp/lexical-conventions.md)<br/> 
   * [Tokens and character sets](../cpp/character-sets.md)
   * [Comments](../cpp/comments-cpp.md) /düzeltme
   * [Identifiers](../cpp/identifiers-cpp.md)
   * [Keywords](../cpp/keywords-cpp.md)
   * [Punctuators](../cpp/punctuators-cpp.md)
   * [Numeric, boolean, and pointer literals](../cpp/numeric-boolean-and-pointer-literals-cpp.md)
   * [String and character literals](../cpp/string-and-character-literals-cpp.md)
   * [User-defined literals](../cpp/user-defined-literals-cpp.md)
---
* ### [Basic Concepts](../cpp/basic-concepts-cpp.md)<br/>
   * [C++ type system](cpp-type-system-modern-cpp.md) /düzeltme
   * [Scope](scope-visual-cpp.md) /düzeltme
   * [Header files](header-files-cpp.md) /düzeltme
   * [Translation units and linkage](program-and-linkage-cpp.md) /düzeltme
   * [main function and command-line arguments](main-function-command-line-args.md) /later
   * [Program termination](program-termination.md) /düzeltme
   * [Lvalues and rvalues](lvalues-and-rvalues-visual-cpp.md) /later
   * [Temporary objects](temporary-objects.md) /later 2
   * [Alignment](alignment-cpp-declarations.md) /later (unknown)
   * [Trivial, standard-layout and POD types](trivial-standard-layout-and-pod-types.md)
---
* ### [Built-in types](fundamental-types-cpp.md)
   * [Data type ranges](data-type-ranges.md) /düzeltme
   * [Nullptr](nullptr.md) /düzeltme
   * [Void](void-cpp.md) /düzeltme
   * [Bool](bool-cpp.md) /düzeltme
   * [True](../cpp/true-cpp.md) /combine {True/False} -\main
   * [False](../cpp/false-cpp.md) /combine {True/False}
   * [Expressions](expressions-cpp.md)
   * [char, wchar_t, char8_t, char16_t, char32_t](char-wchar-t-char16-t-char32-t.md)
   * [__int8, __int16, __int32, __int64](int8-int16-int32-int64.md)
   * [__m64](m64.md)
   * [__m128](m128.md)
   * [__m128d](m128d.md)
   * [__m128i](m128i.md)
   * [__ptr32, __ptr64](ptr32-ptr64.md)
   * [Numerical limits](numerical-limits-cpp.md) -\main {Built-in types}
   * [Integer limits](integer-limits.md) -\main {Built-in types}
   * [Floating limits](floating-limits.md) -\main {Built-in types}
---
* ### [Declarations and definitions](declarations-and-definitions-cpp.md) /düzeltme***
   * [Storage classes](storage-classes-cpp.md) /düzeltme (-)
   * [auto](auto-cpp.md)
   * [const](const-cpp.md) /düzeltme
   * [constexpr](constexpr-cpp.md)
   * [extern](extern-cpp.md)
   * [Initializers](initializers.md)
   * [Aliases and typedefs](aliases-and-typedefs-cpp.md)
   * [using declaration](using-declaration.md)
   * [volatile](volatile-cpp.md)
   * [decltype](decltype-cpp.md)
   * [Attributes in C++](attributes.md)
---
* ### [Operators, Precedence and Associativity](../cpp/cpp-built-in-operators-precedence-and-associativity.md) 
   * [Scope resolution](../cpp/scope-resolution-operator.md) /düzeltme
   * [Member selection (object or pointer)](../cpp/member-access-operators-dot-and.md)
   * [Array subscript](../cpp/subscript-operator.md)
   * [Function call](../cpp/function-call-operator-parens.md)
   * [Postfix increment](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)
   * [Postfix decrement](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)
   * [Type name](../cpp/typeid-operator.md)
   * [Constant type conversion](../cpp/const-cast-operator.md)
   * [Dynamic type conversion](../cpp/dynamic-cast-operator.md)
   * [Reinterpreted type conversion](../cpp/reinterpret-cast-operator.md)
   * [Static type conversion](../cpp/static-cast-operator.md)
   * [Size of object or type](../cpp/sizeof-operator.md)
   * [Prefix increment](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)
   * [Prefix decrement](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)
   * [One's complement](../cpp/one-s-complement-operator-tilde.md)
   * [Logical not](../cpp/logical-negation-operator-exclpt.md)
   * [Unary plus/negation](../cpp/unary-plus-and-negation-operators-plus-and.md) /düzeltme (-)
   * [Address-of](../cpp/address-of-operator-amp.md)
   * [Indirection](../cpp/indirection-operator-star.md)
   * [Create object](../cpp/new-operator-cpp.md)
   * [Destroy object](../cpp/delete-operator-cpp.md)
   * [Cast](../cpp/cast-operator-parens.md)
   * [Pointer-to-member (objects or pointers)](../cpp/pointer-to-member-operators-dot-star-and-star.md)
   * [Multiplication](../cpp/multiplicative-operators-and-the-modulus-operator.md)
   * [Division](../cpp/multiplicative-operators-and-the-modulus-operator.md)
   * [Modulus](../cpp/multiplicative-operators-and-the-modulus-operator.md)
   * [Addition](../cpp/additive-operators-plus-and.md)
   * [Subtraction](../cpp/additive-operators-plus-and.md)
   * [Left shift](../cpp/left-shift-and-right-shift-operators-input-and-output.md)
   * [Right shift](../cpp/left-shift-and-right-shift-operators-input-and-output.md)
   * [Less than](../cpp/relational-operators-equal-and-equal.md)
   * [Greater than](../cpp/relational-operators-equal-and-equal.md)
   * [Less than or equal to](../cpp/relational-operators-equal-and-equal.md)
   * [Greater than or equal to](../cpp/relational-operators-equal-and-equal.md) 
   * [Equality](../cpp/equality-operators-equal-equal-and-exclpt-equal.md) /düzeltme
   * [Bitwise AND](../cpp/bitwise-and-operator-amp.md) /düzeltme (-)
   * [Bitwise exclusive OR](../cpp/bitwise-exclusive-or-operator-hat.md) 
   * [Bitwise inclusive OR](../cpp/bitwise-inclusive-or-operator-pipe.md)
   * [Logical AND](../cpp/logical-and-operator-amp-amp.md) /düzeltme
   * [Logical OR](../cpp/logical-or-operator-pipe-pipe.md) /düzeltme
   * [Conditional](../cpp/conditional-operator-q.md)
   * [Assignment](../cpp/assignment-operators.md) /düzeltme
   * [Multiplication assignment](../cpp/assignment-operators.md)
   * [Division assignment](../cpp/assignment-operators.md)
   * [Modulus assignment](../cpp/assignment-operators.md)
   * [Addition assignment](../cpp/assignment-operators.md)
   * [Subtraction assignment](../cpp/assignment-operators.md)
   * [Left-shift assignment](../cpp/assignment-operators.md)
   * [Right-shift assignment](../cpp/assignment-operators.md)
   * [Bitwise AND assignment](../cpp/assignment-operators.md)
   * [Bitwise inclusive OR assignment](../cpp/assignment-operators.md)
   * [Bitwise exclusive OR assignment](../cpp/assignment-operators.md)
   * [throw expression](../cpp/try-throw-and-catch-statements-cpp.md) 
   * [Comma](../cpp/comma-operator.md)
---
* ### [Expressions](../cpp/expressions-cpp.md)<br/>
   * [Types of Expressions](types-of-expressions.md)
     * [Ellipses and variadic Templates]()
     * [Primary expressions](../cpp/primary-expressions.md)
     * [Postfix expressions](../cpp/postfix-expressions.md)
     * [Expressions with unary operators](../cpp/expressions-with-unary-operators.md)
     * [Expressions with binary operators](../cpp/expressions-with-binary-operators.md)
     * [Constant expressions](../cpp/cpp-constant-expressions.md)
     * [Conditional operator](../cpp/conditional-operator-q.md)
   * [Semantics of expressions](semantics-of-expressions.md)
   * [Casting](casting.md)
     * [Casting operators](../cpp/casting-operators.md)
     * [Dynamic_cast](../cpp/dynamic-cast-operator.md)
     * [Bad cast exception](bad-cast-exception.md)
     * [Static_cast](../cpp/static-cast-operator.md) /düzeltme /later
     * [Const_cast](../cpp/const-cast-operator.md)
     * [Reinterpret_cast](../cpp/reinterpret-cast-operator.md)
     * [Safe_cast](../extensions/safe-cast-cpp-component-extensions.md)
   * [Run-time type information (RTTI)](../cpp/run-time-type-information.md)
     * [Bad_typeid exception](bad-typeid-exception.md)
     * [type_info](../cpp/type-info-class.md)
---
* ### [Statements](../cpp/statements-cpp.md)<br/>
     * [Overview](../cpp/overview-of-cpp-statements.md)
     * [Labeled Statements](../cpp/labeled-statements.md)
     * [Expression statements](../cpp/expression-statement.md)
       * [Null statements](../cpp/null-statement.md)
     * [Compound statements](../cpp/compound-statements-blocks.md)
     * [Selection statements](../cpp/selection-statements-cpp.md) /merge -\main ??
       * [if-else statement](if-else-statement-cpp.md) /düzeltme
       * [Switch](../cpp/switch-statement-cpp.md) /düzeltme
       * [__if_exists](../cpp/if-exists-statement.md)
       * [__if_not_exists](../cpp/if-not-exists-statement.md)
     * [Iteration statements](../cpp/iteration-statements-cpp.md) /merge -\main ??
       * [while](../cpp/while-statement-cpp.md) /düzeltme
       * [do](../cpp/do-while-statement-cpp.md) /düzeltme
       * [for](../cpp/for-statement-cpp.md) /düzeltme
       * [Range-based for](../cpp/range-based-for-statement-cpp.md) /düzeltme (unknown)
     * [Jump statements](../cpp/jump-statements-cpp.md)
       * [Break Statement](../cpp/break-statement-cpp.md) /düzeltme
       * [Continue Statement](../cpp/continue-statement-cpp.md) /düzeltme
       * [Return Statement](../cpp/return-statement-cpp.md) /düzeltme
       * [Goto Statement](../cpp/goto-statement-cpp.md) /düzeltme
       * [Transfers of control](transfers-of-control.md)
---
* ### [Namespaces](namespaces-cpp.md)<br/>
---
* ### [Enumerations](enumerations-cpp.md)<br/> /düzeltme (-) *Important
---
* ### [Unions](unions.md)<br/>
---
* ### [Functions](functions-cpp.md)<br/> *Important /düzeltme -\Main
   * [Functions with variable argument list](function-with-variable-argument-list-cpp.md)
   * [Function Overloading](../cpp/function-overloading.md)
   * [Explicitly defaulted and deleted functions](explicitly-defaulted-and-deleted-functions.md)
   * [argument dependent name koenig lookup on functions](argument-dependent-name-koenig-lookup-on-functions.md)
   * [Virtual Functions](../cpp/virtual-functions.md)
   * [Default arguments](default-arguments.md)
   * [Inline Functions](../cpp/inline-functions-cpp.md) /düzeltme (-)
---
* ### [Operator Overloading](operator-overloading.md)<br/> /düzeltme (-)
   * [General rules for operator overloading](general-rules-for-operator-overloading.md)
   * [Unary Operators](../cpp/overloading-unary-operators.md)
   * [Binary Operators](../cpp/binary-operators.md)
   * [Assignment](../cpp/assignment.md)
   * [Function Call](../cpp/function-call-cpp.md)
   * [Subscripting](../cpp/subscripting.md)
   * [Class-Member Access](../cpp/member-access.md)
   * [Increment and Decrement](../cpp/increment-and-decrement-operator-overloading-cpp.md).
   * [User-Defined Type Conversions](../cpp/user-defined-type-conversions-cpp.md)
---
* ### [Classes and structs](../cpp/classes-and-structs-cpp.md)<br/>
   * [class](../cpp/class-cpp.md) /düzeltme
   * [Struct](../cpp/struct-cpp.md) /*
   * [Class Member Overview](../cpp/class-member-overview.md)
   * [Member Access Control](../cpp/member-access-control-cpp.md) combine {main-{member access}}
     * [Public](../cpp/public-cpp.md) /combine {member access}
     * [Private](../cpp/private-cpp.md) /combine {member access}
     * [Friend](../cpp/friend-cpp.md) /combine {member access}
     * [Protected](../cpp/protected-cpp.md) /combine {member access}
   * [Inheritance](../cpp/inheritance-cpp.md)
   * [Static Members](../cpp/static-members-cpp.md)
   * [User-Defined Type Conversions](../cpp/user-defined-type-conversions-cpp.md)
   * [Mutable Data Members (mutable specifier)](../cpp/mutable-data-members-cpp.md)
   * [Nested Class Declarations](../cpp/nested-class-declarations.md)
   * [Anonymous Class Types](../cpp/anonymous-class-types.md)
   * [Pointers to Members](../cpp/pointers-to-members.md)
   * [this Pointer](../cpp/this-pointer.md)
   * [C++ Bit Fields](../cpp/cpp-bit-fields.md)
---
* ### [Standard Conversions](../cpp/standard-conversions.md)<br/>
---
* ### [Lambda Expressions](../cpp/lambda-expressions-in-cpp.md)<br/>
---
* ### [Derived Classes](../cpp/inheritance-cpp.md)<br/>
---
* ### [Arrays](../cpp/arrays-cpp.md)<br/> /düzeltme (-)
---
* ### [Member-Access Control](../cpp/member-access-control-cpp.md)<br/>
---
* ### [Exception Handling](../cpp/exception-handling-in-visual-cpp.md)<br/>
---
* ### [Assertion and User-Supplied Messages](../cpp/assertion-and-user-supplied-messages-cpp.md)<br/>
---
* ### [Templates](../cpp/templates-cpp.md)<br/>
---
* ### [Event Handling](../cpp/event-handling.md)<br/>
---
* ### [Microsoft-Specific Modifiers](../cpp/microsoft-specific-modifiers.md)<br/>
---
* ### [Inline Assembler](../assembler/inline/inline-assembler.md)<br/>
---
* ### [Compiler COM Support](../cpp/compiler-com-support.md)<br/>
---
* ### [Microsoft Extensions](../cpp/microsoft-extensions.md)<br/>
---
* ### [Nonstandard Behavior](../cpp/nonstandard-behavior.md)<br/>

