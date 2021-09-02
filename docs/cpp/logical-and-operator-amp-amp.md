---
title: "Logical AND Operator: &amp;&amp;"
description: "The C++ standard language logical AND operator syntax and use."
ms.date: 07/23/2020
f1_keywords: ["&&", "and_cpp"]
helpviewer_keywords: ["logical AND operator", "AND operator", "&& operator"]
ms.assetid: 50cfa664-a8c4-4b31-9bab-2f80d7cd2d1f
---
# Logical AND operator: &amp;&amp;

## Syntax

> *expression* **`&&`** *expression*

## Remarks

Mantıksal AND operatörü (**&&**) **`true`**, her iki işlenen de ise **`true`** döner, **`false`** aksi halde döner. İşlenenler, **`bool`** değerlendirmeden önce örtük olarak type'a dönüştürülür ve sonuç type olur **`bool`**. Mantıksal AND, soldan sağa ilişkilendirilebilirliğe sahiptir.

Mantıksal AND operatörünün işlenenlerinin aynı tipte olması gerekmez, ancak boolean, integral veya işaretçi tipine sahip olmaları gerekir. İşlenenler genellikle ilişkisel veya eşitlik ifadeleridir.

İlk işlenen tamamen değerlendirilir ve mantıksal AND ifadesinin değerlendirilmesi devam etmeden önce tüm yan etkiler tamamlanır.

İkinci işlenen, yalnızca ilk işlenen **`true`** (sıfır olmayan) olarak değerlendirilirse değerlendirilir . Bu değerlendirme, mantıksal AND ifadesi olduğunda ikinci işlenenin gereksiz değerlendirmesini ortadan kaldırır **`false`**. Bu kısa devre değerlendirmesini, aşağıdaki örnekte gösterildiği gibi boş işaretçi referansını kaldırmayı önlemek için kullanabilirsiniz:

```cpp
char *pch = 0;
// ...
(pch) && (*pch = 'a');
```

Eğer pchboş (0) 'dir, ifadenin sağ tarafı değerlendirilir asla. Bu kısa devre değerlendirmesi, bir boş gösterici aracılığıyla atamayı imkansız hale getirir.

## Operator keyword for &&

C++ **`and`** için alternatif bir yazım belirtir **`&&`**. C'de alternatif yazım, \<iso646.h> başlığında bir makro olarak sağlanır. C++'da alternatif yazım bir anahtar kelimedir; \<iso646.h> veya C++ eşdeğeri \<ciso646> kullanımı kullanımdan kaldırılmıştır. Microsoft C++' [`/permissive-`](../build/reference/permissive-standards-conformance.md) or [`/Za`](../build/reference/za-ze-disable-language-extensions.md), alternatif yazımı etkinleştirmek için veya derleyici seçeneği gereklidir.

## Example

```cpp
// expre_Logical_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate logical AND
#include <iostream>

using namespace std;

int main() {
   int a = 5, b = 10, c = 15;
   cout  << boolalpha
         << "The true expression "
         << "a < b && b < c yields "
         << (a < b && b < c) << endl
         << "The false expression "
         << "a > b && b < c yields "
         << (a > b && b < c) << endl;
}
```

## See also

[C++ built-in operators, precedence, and associativity](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[C logical operators](../c-language/c-logical-operators.md)
