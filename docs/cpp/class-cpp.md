---
description: "Learn more about: class (C++)"
title: "class (C++)"
ms.date: "11/04/2016"
f1_keywords: ["class_cpp"]
helpviewer_keywords: ["class types [C++], class statements", "class keyword [C++]"]
ms.assetid: dd23c09f-6598-4069-8bff-69c7f2518b9f
---
# class (C++)

The **`class`** keyword declares a class type or defines an object of a class type.

## Syntax

```
[template-spec]
class [ms-decl-spec] [tag [: base-list ]]
{
   member-list
} [declarators];
[ class ] tag declarators;
```

#### Parameters

*template-spec*<br/>
İsteğe bağlı şablon belirtimleri. Daha fazla bilgi için [Templates](templates-cpp.md) bölümüne bakın.

*class*<br/>
The **`class`** keyword.

*ms-decl-spec*<br/>
İsteğe bağlı depolama sınıfı belirtimi. Daha fazla bilgi için [__declspec](../cpp/declspec.md) anahtar sözcüğüne bakın .

*tag*<br/>
Sınıfa verilen tür adı. Etiket, sınıf kapsamında ayrılmış bir kelime haline gelir. Etiket isteğe bağlıdır. Atlanırsa, anonim bir sınıf tanımlanır. Daha fazla bilgi için, bkz. [Anonymous Class Types](../cpp/anonymous-class-types.md).

*base-list*<br/>
Bu sınıfın üyelerini türeteceği isteğe bağlı sınıflar veya yapılar listesi. Daha fazla bilgi için Temel Sınıflara bakın . Her temel sınıf veya yapı adından önce bir erişim belirteci (public, private, protected) ve virtual anahtar sözcüğü gelebilir . Daha fazla bilgi için Sınıf Üyelerine Erişimi Kontrol Etme bölümündeki [Controlling Access to Class Members](member-access-control-cpp.md) bakın.

*member-list*<br/>
Sınıf üyelerinin listesi. Daha fazla bilgi için [Class Member Overview](../cpp/class-member-overview.md)'a bakın .

*declarators*<br/>
Sınıf türünün bir veya daha fazla örneğinin adlarını belirten Bildirici listesi. Bildiriler, sınıfın tüm veri üyeleri ise başlatıcı listelerini içerebilir **`public`**. Bu, veri üyeleri **`public`** varsayılan olarak sınıflara göre olan yapılarda daha yaygındır. Daha fazla bilgi için [Overview of Declarators](./declarations-and-definitions-cpp.md) bölümüne bakın .

## Remarks

Genel olarak sınıflar hakkında daha fazla bilgi için aşağıdaki konulardan birine bakın:

- [struct](../cpp/struct-cpp.md)

- [union](../cpp/unions.md)

- [__multiple_inheritance](../cpp/inheritance-keywords.md)

- [__single_inheritance](../cpp/inheritance-keywords.md)

- [__virtual_inheritance](../cpp/inheritance-keywords.md)

For information on managed classes and structs in C++/CLI and C++/CX, see [Classes and Structs](../extensions/classes-and-structs-cpp-component-extensions.md)

## Example

```cpp
// class.cpp
// compile with: /EHsc
// Example of the class keyword
// Exhibits polymorphism/virtual functions.

#include <iostream>
#include <string>
using namespace std;

class dog
{
public:
   dog()
   {
      _legs = 4;
      _bark = true;
   }

   void setDogSize(string dogSize)
   {
      _dogSize = dogSize;
   }
   virtual void setEars(string type)      // virtual function
   {
      _earType = type;
   }

private:
   string _dogSize, _earType;
   int _legs;
   bool _bark;

};

class breed : public dog
{
public:
   breed( string color, string size)
   {
      _color = color;
      setDogSize(size);
   }

   string getColor()
   {
      return _color;
   }

   // virtual function redefined
   void setEars(string length, string type)
   {
      _earLength = length;
      _earType = type;
   }

protected:
   string _color, _earLength, _earType;
};

int main()
{
   dog mongrel;
   breed labrador("yellow", "large");
   mongrel.setEars("pointy");
   labrador.setEars("long", "floppy");
   cout << "Cody is a " << labrador.getColor() << " labrador" << endl;
}
```

## See also

[Keywords](../cpp/keywords-cpp.md)<br/>
[Classes and Structs](../cpp/classes-and-structs-cpp.md)
