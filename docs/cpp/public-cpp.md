---
description: "Learn more about: public (C++)"
title: "public (C++)"
ms.date: "11/04/2016"
f1_keywords: ["public_cpp"]
helpviewer_keywords: ["public keyword [C++]"]
ms.assetid: f3e10a59-39f6-4bcd-827e-3e99f8f89497
---
# public (C++)

## Syntax

```
public:
   [member-list]
public base-class
```

## Remarks

Bir sınıf üyeleri listesinden önce **`public`** anahtar kelime, bu üyelere herhangi bir işlevden erişilebileceğini belirtir. Bu, bir sonraki erişim belirtecine veya sınıfın sonuna kadar bildirilen tüm üyeler için geçerlidir.

Bir temel sınıfın adından önce **`public`** anahtar sözcük, temel sınıfın genel ve korumalı üyelerinin, türetilmiş sınıfın sırasıyla genel ve korumalı üyeleri olduğunu belirtir.

Bir sınıftaki üyelerin varsayılan erişimi özeldir. Bir yapı veya birlik içindeki üyelerin varsayılan erişimi herkese açıktır.

Bir temel sınıfın varsayılan erişimi, sınıflar için özel ve yapılar için geneldir. Sendikaların temel sınıfları olamaz.

## /clr Specific

CLR türlerinde, C++ erişim belirteci anahtar sözcükleri (**`public`**, **`private`**, and **`protected`**), derlemelerle ilgili türlerin ve yöntemlerin görünürlüğünü etkileyebilir. Daha fazla bilgi için, bkz. [Member Access Control](member-access-control-cpp.md)

> [!NOTE]
> [/LN](../build/reference/ln-create-msil-module.md) ile derlenen dosyalar bu davranıştan etkilenmez. Bu durumda, yönetilen tüm sınıflar (genel veya özel) görünür olacaktır.

## END /clr Specific

## Example

```cpp
// keyword_public.cpp
class BaseClass {
public:
   int pubFunc() { return 0; }
};

class DerivedClass : public BaseClass {};

int main() {
   BaseClass aBase;
   DerivedClass aDerived;
   aBase.pubFunc();       // pubFunc() is accessible
                          //    from any function
   aDerived.pubFunc();    // pubFunc() is still public in
                          //    derived class
}
```

## See also

[Controlling Access to Class Members](member-access-control-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)
