---
description: "Learn more about: private (C++)"
title: "private (C++)"
ms.date: "11/04/2016"
f1_keywords: ["private_cpp"]
helpviewer_keywords: ["private keyword [C++]"]
ms.assetid: 94e99983-46a5-4e21-800c-28f8a7c6a8ff
---
# private (C++)

## Syntax

```
private:
   [member-list]
private base-class
```

## Remarks

Bir sınıf üyeleri listesinden önce privateanahtar sözcük, bu üyelere yalnızca sınıfın üye işlevlerinden ve arkadaşlarından erişilebilir olduğunu belirtir. Bu, bir sonraki erişim belirtecine veya sınıfın sonuna kadar bildirilen tüm üyeler için geçerlidir.

Temel sınıfın adından önce privateanahtar sözcük , temel sınıfın genel ve korumalı üyelerinin türetilmiş sınıfın özel üyeleri olduğunu belirtir.

Bir sınıftaki üyelerin varsayılan erişimi özeldir. Bir yapı veya birlik içindeki üyelerin varsayılan erişimi herkese açıktır.

Bir temel sınıfın varsayılan erişimi, sınıflar için özel ve yapılar için geneldir. Sendikaların temel sınıfları olamaz.

İlgili bilgiler için, Sınıf Üyelerine Erişimi Kontrol Etme bölümündeki friend , public , protected ve üye erişim tablosuna bakın .

## /clr Specific

CLR türlerinde, C++ erişim belirteci anahtar sözcükleri (**`public`**, **`private`**, and **`protected`**), derlemelerle ilgili türlerin ve yöntemlerin görünürlüğünü etkileyebilir. Daha fazla bilgi için, bkz. [Member Access Control](member-access-control-cpp.md).

> [!NOTE]
>  [/LN](../build/reference/ln-create-msil-module.md) ile derlenen dosyalar bu davranıştan etkilenmez. Bu durumda, yönetilen tüm sınıflar (public veya private) görünür olacaktır.

## END /clr Specific

## Example

```cpp
// keyword_private.cpp
class BaseClass {
public:
   // privMem accessible from member function
   int pubFunc() { return privMem; }
private:
   void privMem;
};

class DerivedClass : public BaseClass {
public:
   void usePrivate( int i )
      { privMem = i; }   // C2248: privMem not accessible
                         // from derived class
};

class DerivedClass2 : private BaseClass {
public:
   // pubFunc() accessible from derived class
   int usePublic() { return pubFunc(); }
};

int main() {
   BaseClass aBase;
   DerivedClass aDerived;
   DerivedClass2 aDerived2;
   aBase.privMem = 1;     // C2248: privMem not accessible
   aDerived.privMem = 1;  // C2248: privMem not accessible
                          //    in derived class
   aDerived2.pubFunc();   // C2247: pubFunc() is private in
                          //    derived class
}
```

## See also

[Controlling Access to Class Members](member-access-control-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)
