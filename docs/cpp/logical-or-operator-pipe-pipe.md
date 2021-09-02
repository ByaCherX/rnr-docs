---
title: "Logical OR operator: &#124;&#124;"
description: "The C++ standard language logical OR operator syntax and use."
ms.date: 07/23/2020
f1_keywords: ["||", "or_cpp"]
helpviewer_keywords: ["OR operator [C++], logical", "|| operator", "OR operator", "logical OR operator"]
ms.assetid: 31837c99-2655-4bf3-8ded-f13b7a9dc533
---
# Logical OR operator: &#124;&#124;

## Syntax

> *logical-or-expression* **`||`** *logical-and-expression*

## Remarks

Mantıksal VEYA operatörü (**`||`**), **`true`** işlenenlerden biri veya her ikisi ise boole değerini **`true`** döndürür ve **`false`** aksi halde döndürür . İşlenenler, **`bool`** değerlendirmeden önce örtük olarak type'a dönüştürülür ve sonuç type olur **`bool`**. Mantıksal VEYA soldan sağa ilişkilendirilebilirliğe sahiptir.

Mantıksal VEYA operatörünün işlenenlerinin aynı türde olması gerekmez, ancak boolean, integral veya işaretçi türünde olmaları gerekir. İşlenenler genellikle ilişkisel veya eşitlik ifadeleridir.

İlk işlenen tamamen değerlendirilir ve mantıksal OR ifadesinin değerlendirilmesine devam edilmeden önce tüm yan etkiler tamamlanır.

**`false`** Mantıksal VEYA ifadesi olduğunda değerlendirme gerekli olmadığından, ikinci işlenen yalnızca ilk işlenen olarak değerlendirilirse değerlendirilir **`true`**. Kısa devre değerlendirmesi olarak bilinir .

```cpp
printf( "%d" , (x == w || x == y || x == z) );
```

Yukarıdaki örnekte, `x` eşitse `w`, `y`, or `z`, printfişlevin ikinci argümanı olarak değerlendirilir **`true`**, bu daha sonra bir tamsayıya yükseltilir ve 1 değeri yazdırılır. Aksi takdirde, olarak değerlendirilir **`false`**ve 0 değeri yazdırılır. Koşullardan biri olarak değerlendirilir **`true`** değerlendirmez değerlendirme durur.

## Operator keyword for &#124;&#124;

C++ **`or`** için alternatif bir yazım belirtir **`||`**. C'de alternatif yazım, \<iso646.h> başlığında bir makro olarak sağlanır. C++'da alternatif yazım bir anahtar kelimedir; \<iso646.h> veya C++ eşdeğeri \<ciso646> kullanımı kullanımdan kaldırılmıştır.

## Example

```cpp
// expre_Logical_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate logical OR
#include <iostream>
using namespace std;
int main() {
   int a = 5, b = 10, c = 15;
   cout  << boolalpha
         << "The true expression "
         << "a < b || b > c yields "
         << (a < b || b > c) << endl
         << "The false expression "
         << "a > b || b > c yields "
         << (a > b || b > c) << endl;
}
```

## See also

[C++ built-in operators, precedence, and associativity](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[C logical operators](../c-language/c-logical-operators.md)
