---
title: "Equality operators: == and !="
description: "The C++ standard language equal-to and not-equal-to operator syntax and use."
ms.date: 07/23/2020
f1_keywords: ["!=", "==", "not_eq_cpp"]
helpviewer_keywords: ["!= operator", "equality operator", "not equal to comparison operator", "equality operator [C++], syntax", "== operator", "not_eq operator", "equal to operator"]
ms.assetid: ba4e9659-2392-4fb4-be5a-910a2a6df45a
---
# Equality operators: == and !=

## Syntax

> *expression* **`==`** *expression*\
> *expression* **`!=`** *expression*

## Remarks

İkili eşitlik operatörleri, işlenenlerini katı eşitlik veya eşitsizlik açısından karşılaştırır.

(**`==`**) değerine eşit ve (**`!=`**) değerine eşit olmayan eşitlik operatörleri, ilişkisel operatörlerden daha düşük önceliğe sahiptir, ancak benzer şekilde davranırlar. Bu operatörler için sonuç türü **`bool`**

Eşittir operatörü (**`==`**) **`true`** her iki işlenen de aynı değere sahipse döner; aksi halde geri döner **`false`**. Eşit olmayan işleci (**`!=`**) **`true`**, işlenenler aynı değere sahip değilse döner; aksi halde geri döner **`false`**.

## Operator keyword for !=

C++ **`not_eq`** için alternatif bir yazım belirtir **`!=`**. ( için alternatif yazım yoktur **`==`**) C'de, alternatif yazım \iso646.h> başlığında bir makro olarak sağlanır. C++'da alternatif yazım bir anahtar kelimedir; \<iso646.h> veya C++ eşdeğeri \<ciso646> kullanımı kullanımdan kaldırılmıştır.

## Example

```cpp
// expre_Equality_Operators.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

int main() {
   cout  << boolalpha
         << "The true expression 3 != 2 yields: "
         << (3 != 2) << endl
         << "The false expression 20 == 10 yields: "
         << (20 == 10) << endl;
}
```

Eşitlik operatörleri, işaretçileri aynı türdeki üyelerle karşılaştırabilir. Böyle bir karşılaştırmada, işaretçiden üyeye dönüşümler gerçekleştirilir. Üyelere yönelik işaretçiler, 0 olarak değerlendirilen sabit bir ifadeyle de karşılaştırılabilir.

## See also

[Expressions with binary operators](../cpp/expressions-with-binary-operators.md)<br/>
[C++ built-in operators, precedence; and associativity](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[C relational and equality operators](../c-language/c-relational-and-equality-operators.md)
