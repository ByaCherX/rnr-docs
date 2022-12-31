---
description: "Learn more about: void (C++)"
title: "void (C++)"
ms.date: "11/04/2016"
f1_keywords: ["void_cpp"]
helpviewer_keywords: ["void keyword [C++]", "functions [C++], void", "pointers, void"]
ms.assetid: d203edba-38e6-4056-8b89-011437351057
---
# void (C++)

Bir işlev döndürme türü olarak kullanıldığında, **`void`** anahtar sözcük, işlevin bir değer döndürmediğini belirtir. Bir fonksiyonun parametre listesi için kullanıldığında, fonksiyonun parametre **`void`** almadığını belirtir. İşaretçi bildiriminde kullanıldığında **`void`**, işaretçinin "evrensel" olduğunu belirtir.

İşaretçinin türü **void\*** ise, işaretçi **`const`** veya **`volatile`** anahtar sözcüğüyle bildirilmeyen herhangi bir değişkene işaret edebilir . Bir **void\*** işaretçisi, başka bir türe dönüştürülmediği sürece başvurudan kaldırılamaz. Bir **void\*** işaretçisi, başka herhangi bir veri işaretçisine dönüştürülebilir.

Bir **`void`** işaretçi bir işlevi işaret edebilir, ancak C++'da bir sınıf üyesine işaret edemez.

türünde bir değişken bildiremezsiniz **`void`**.

## Example

```cpp
// void.cpp
void vobject;   // C2182
void *pv;   // okay
int *pint; int i;
int main() {
   pv = &i;
   // Cast optional in C required in C++
   pint = (int *)pv;
}
```

## See also

[Keywords](../cpp/keywords-cpp.md)<br/>
[Built-in types](../cpp/fundamental-types-cpp.md)
