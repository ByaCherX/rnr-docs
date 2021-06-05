---
description: "Learn more about: C++ Language Reference"
title: "C++ Language Reference"
ms.custom: "index-page"
ms.date: "29/05/2021"
helpviewer_keywords: ["C++, main"]
ms.assetid: 4be9cacb-c862-4391-894a-3a118c9c93ce
---
<style>
r { color: rgb(250,0,0) }
</style>

<h1 style="text-align:center;">C++ Language Reference Main</h1>

## C++ Document Libraries
|Section|Description|link|
|-|-|-|
|<r>➔ </r>C++ Language Main Documents|This documentation is the central location of the cpp|-----|
|C++ Standard Library Main Documents|Provides standard library for C language|[-----](../cpp/standard-library/_standard-library-main.md)|
|Active Template Library (ATL)|(ATL) is a set of template-based C++ classes that let you create|[-----](../cpp/atl/_ATL-main.md)|
|C/C++ Preprocessor Reference|The C/C++ preprocessor reference explains the preprocessor|[-----](../cpp/preprocessor/_Preprocessor-main.md)|
|C++/CX Language Reference|C++/CX is a set of extensions of the C++ language.|[-----](../cpp/cppcx/_cppcx-main.md)|

## Cpp Language Reference 

This reference explains the C++ programming language as implemented in the Microsoft C++ compiler. The organization is based on *The Annotated C++ Reference Manual* by Margaret Ellis and Bjarne Stroustrup and on the ANSI/ISO C++ International Standard (ISO/IEC FDIS 14882). Microsoft-specific implementations of C++ language features are included.

For an overview of Modern C++ programming practices, see [Welcome Back to C++](welcome-back-to-cpp-modern-cpp.md).

See the following tables to quickly find a keyword or operator:

- [C++ Keywords](../cpp/keywords-cpp.md)

- [C++ Operators](../cpp/cpp-built-in-operators-precedence-and-associativity.md)

## Cpp Language Reference Tree 

---

* #### [Lexical Conventions](../cpp/lexical-conventions.md)<br/>
   * [Tokens and character sets](../cpp/character-sets.md)
   * [Comments](../cpp/comments-cpp.md)
   * [Identifiers](../cpp/identifiers-cpp.md)
   * [Keywords](../cpp/keywords-cpp.md)
   * [Punctuators](../cpp/punctuators-cpp.md)
   * [Numeric, boolean, and pointer literals](../cpp/numeric-boolean-and-pointer-literals-cpp.md)
   * [String and character literals](../cpp/string-and-character-literals-cpp.md)
   * [User-defined literals](../cpp/user-defined-literals-cpp.md)
---
* #### [Basic Concepts](../cpp/basic-concepts-cpp.md)<br/>
   * [C++ type system](cpp-type-system-modern-cpp.md)
   * [Scope](scope-visual-cpp.md)
   * [Translation units and linkage](program-and-linkage-cpp.md)
   * [main function and command-line arguments](main-function-command-line-args.md)
   * [Program termination](program-termination.md)
   * [Lvalues and rvalues](lvalues-and-rvalues-visual-cpp.md)
   * [Temporary objects](temporary-objects.md)
   * [Alignment](alignment-cpp-declarations.md)
   * [Trivial, standard-layout and POD types](trivial-standard-layout-and-pod-types.md)
---
* #### [Built-in types](fundamental-types-cpp.md)
   * [Data type ranges](data-type-ranges.md)
   * [Nullptr](nullptr.md)
   * [Void](void-cpp.md)
   * [Bool](bool-cpp.md)
   * [True](../cpp/true-cpp.md)
   * [False](../cpp/false-cpp.md)
   * [Expressions](expressions-cpp.md)
   * [char, wchar_t, char8_t, char16_t, char32_t](char-wchar-t-char16-t-char32-t.md)
   * [__int8, __int16, __int32, __int64](int8-int16-int32-int64.md)
   * [__m64](m64.md)
   * [__m128](m128.md)
   * [__m128d](m128d.md)
   * [__m128i](m128i.md)
   * [__ptr32, __ptr64](ptr32-ptr64.md)
   * [Numerical limits](numerical-limits-cpp.md)
   * [Integer limits](integer-limits.md)
   * [Floating limits](floating-limits.md)
---
* #### [Declarations and definitions](declarations-and-definitions-cpp.md)
   * [Storage classes](storage-classes-cpp.md)
   * [auto](auto-cpp.md)
   * [const](const-cpp.md)
   * [constexpr](constexpr-cpp.md)
   * [extern](extern-cpp.md)
   * [Initializers](initializers.md)
   * [Aliases and typedefs](aliases-and-typedefs-cpp.md)
   * [using declaration](using-declaration.md)
   * [volatile](volatile-cpp.md)
   * [decltype](decltype-cpp.md)
   * [Attributes in C++](attributes.md)
---
* #### [Operators, Precedence and Associativity](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
   * [Scope resolution](../cpp/scope-resolution-operator.md)
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
   * [Unary negation](../cpp/unary-plus-and-negation-operators-plus-and.md)
   * [Unary plus](../cpp/unary-plus-and-negation-operators-plus-and.md)
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
   * [Equality](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)
   * [Inequality](../cpp/equality-operators-equal-equal-and-exclpt-equal.md) 
   * [Bitwise AND](../cpp/bitwise-and-operator-amp.md)
   * [Bitwise exclusive OR](../cpp/bitwise-exclusive-or-operator-hat.md) 
   * [Bitwise inclusive OR](../cpp/bitwise-inclusive-or-operator-pipe.md)
   * [Logical AND](../cpp/logical-and-operator-amp-amp.md)
   * [Logical OR](../cpp/logical-or-operator-pipe-pipe.md) 
   * [Conditional](../cpp/conditional-operator-q.md)
   * [Assignment](../cpp/assignment-operators.md)
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
* #### [Expressions](../cpp/expressions-cpp.md)<br/>
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
     * [Static_cast](../cpp/static-cast-operator.md)
     * [Const_cast](../cpp/const-cast-operator.md)
     * [Reinterpret_cast](../cpp/reinterpret-cast-operator.md)
     * [Safe_cast](../extensions/safe-cast-cpp-component-extensions.md)
   * [Run-time type information (RTTI)](../cpp/run-time-type-information.md)
     * [Bad_typeid exception](bad-typeid-exception.md)
     * [type_info](../cpp/type-info-class.md)
---
* #### [Statements](../cpp/statements-cpp.md)<br/>
     * [Overview](../cpp/overview-of-cpp-statements.md)
     * [Labeled Statements](../cpp/labeled-statements.md)
     * [Expression statements](../cpp/expression-statement.md)
       * [Null statements](../cpp/null-statement.md)
     * [Compound statements](../cpp/compound-statements-blocks.md)
     * [Selection statements](../cpp/selection-statements-cpp.md)
       * [if-else statement](if-else-statement-cpp.md)
       * [if](../cpp/if-else-statement-cpp.md)
       * [Switch](../cpp/switch-statement-cpp.md)
       * [__if_exists](../cpp/if-exists-statement.md)
       * [__if_not_exists](../cpp/if-not-exists-statement.md)
     * [Iteration statements](../cpp/iteration-statements-cpp.md)
       * [break](../cpp/break-statement-cpp.md)
       * [continue](../cpp/continue-statement-cpp.md)
       * [while](../cpp/while-statement-cpp.md)
       * [do](../cpp/do-while-statement-cpp.md)
       * [for](../cpp/for-statement-cpp.md)
       * [Range-based for](../cpp/range-based-for-statement-cpp.md)
     * [Jump statements](../cpp/jump-statements-cpp.md)
       * [Break Statement](../cpp/break-statement-cpp.md)
       * [Continue Statement](../cpp/continue-statement-cpp.md)
       * [Return Statement](../cpp/return-statement-cpp.md)
       * [Goto Statement](../cpp/goto-statement-cpp.md)
       * [Transfers of control](transfers-of-control.md)
     * [Declaration statements](declarations-and-definitions-cpp.md)
---
* #### [Namespaces](namespaces-cpp.md)<br/>
---
* #### [Enumerations](enumerations-cpp.md)<br/>
---
* #### [Unions](unions.md)<br/>
---
* #### [Functions](functions-cpp.md)<br/>
   * [Functions with variable argument list](function-with-variable-argument-list-cpp.md)
   * [Function Overloading](../cpp/function-overloading.md)
   * [Explicitly defaulted and deleted functions](explicitly-defaulted-and-deleted-functions.md)
   * [argument dependent name koenig lookup on functions](argument-dependent-name-koenig-lookup-on-functions.md)
   * [Virtual Functions](../cpp/virtual-functions.md)
   * [Default arguments](default-arguments.md)
   * [Inline Functions](../cpp/inline-functions-cpp.md)
---
* #### [Operator Overloading](operator-overloading.md)<br/>
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
* #### [Classes and structs](../cpp/classes-and-structs-cpp.md)<br/>
   * [class](../cpp/class-cpp.md)
   * [Struct](../cpp/struct-cpp.md)
   * [Class Member Overview](../cpp/class-member-overview.md)
   * [Member Access Control](../cpp/member-access-control-cpp.md)
     * [Friend](../cpp/friend-cpp.md)
     * [Private](../cpp/private-cpp.md)
     * [Protected](../cpp/protected-cpp.md)
     * [Public](../cpp/public-cpp.md)
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
* #### [Standard Conversions](../cpp/standard-conversions.md)<br/>
---
* #### [Lambda Expressions](../cpp/lambda-expressions-in-cpp.md)<br/>
---
* #### [Derived Classes](../cpp/inheritance-cpp.md)<br/>
---
* #### [Member-Access Control](../cpp/member-access-control-cpp.md)<br/>
---
* #### [Exception Handling](../cpp/exception-handling-in-visual-cpp.md)<br/>
---
* #### [Assertion and User-Supplied Messages](../cpp/assertion-and-user-supplied-messages-cpp.md)<br/>
---
* #### [Templates](../cpp/templates-cpp.md)<br/>
---
* #### [Event Handling](../cpp/event-handling.md)<br/>
---
* #### [Microsoft-Specific Modifiers](../cpp/microsoft-specific-modifiers.md)<br/>
---
* #### [Inline Assembler](../assembler/inline/inline-assembler.md)<br/>
---
* #### [Compiler COM Support](../cpp/compiler-com-support.md)<br/>
---
* #### [Microsoft Extensions](../cpp/microsoft-extensions.md)<br/>
---
* #### [Nonstandard Behavior](../cpp/nonstandard-behavior.md)<br/>

