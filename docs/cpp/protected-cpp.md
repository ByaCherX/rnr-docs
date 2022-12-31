---
description: "Learn more about: protected (C++)"
title: "protected (C++)"
ms.date: "11/04/2016"
f1_keywords: ["protected_cpp"]
helpviewer_keywords: ["protected keyword [C++], member access", "protected keyword [C++]"]
ms.assetid: 863d299f-fc0d-45d5-a1a7-bd24b7778a93
---
# protected (C++)

## Syntax

```
protected:
   [member-list]
protected base-class
```

## Remarks

**`protected`** Anahtar kelime belirtir sınıf üyelerine erişmek *member-list*esindeki bir sonraki erişim belirteci (**`public`** or **`private`**) ya da sınıf tanımının sonuna. Olarak beyan edilen sınıf üyeleri **`protected`** yalnızca aşağıdakiler tarafından kullanılabilir:

- Başlangıçta bu üyeleri bildiren sınıfın üye işlevleri.

- Başlangıçta bu üyeleri ilan eden sınıfın arkadaşları.

- Bu üyeleri ilk olarak bildiren sınıftan genel veya korumalı erişimle türetilen sınıflar.

- Korunan üyelere özel erişimi de olan doğrudan özel olarak türetilmiş sınıflar.

Bir temel sınıfın adından önce geldiğinde, **`protected`** anahtar kelime , temel sınıfın genel ve korumalı üyelerinin, türetilmiş sınıflarının korumalı üyeleri olduğunu belirtir.

Korumalı üyeler, **`private`** yalnızca bildirildikleri sınıfın üyeleri tarafından erişilebilen üyeler kadar özel değildir , ancak **`public`** herhangi bir işlevde erişilebilen üyeler kadar genel de değildir .

Ayrıca **`static`** üretilmiş bir sınıfın herhangi bir arkadaş veya üye işlevi tarafından erişilebilir olarak bildirilen korumalı üyeler . **`static`** Türetilmiş bir sınıftaki arkadaşlar ve üye işlevleri tarafından yalnızca türetilmiş sınıfın bir işaretçisi, referansı veya nesnesi aracılığıyla erişilebilir olarak bildirilmeyen korumalı üyeler .

## /clr Specific

CLR türlerinde, C++ erişim belirteci anahtar sözcükleri (**`public`**, **`private`**, and **`protected`**), derlemelerle ilgili türlerin ve yöntemlerin görünürlüğünü etkileyebilir. Daha fazla bilgi için, bkz. [Member Access Control](member-access-control-cpp.md).

> [!NOTE]
> [/LN](../build/reference/ln-create-msil-module.md) ile derlenen dosyalar bu davranıştan etkilenmez. Bu durumda, yönetilen tüm sınıflar (genel veya özel) görünür olacaktır.

## END /clr Specific

## Example

```cpp
// keyword_protected.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class X {
public:
   void setProtMemb( int i ) { m_protMemb = i; }
   void Display() { cout << m_protMemb << endl; }
protected:
   int  m_protMemb;
   void Protfunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
   void useProtfunc() { Protfunc(); }
} y;

int main() {
   // x.m_protMemb;         error, m_protMemb is protected
   x.setProtMemb( 0 );   // OK, uses public access function
   x.Display();
   y.setProtMemb( 5 );   // OK, uses public access function
   y.Display();
   // x.Protfunc();         error, Protfunc() is protected
   y.useProtfunc();      // OK, uses public access function
                        // in derived class
}
```

## See also

[Controlling Access to Class Members](member-access-control-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)
