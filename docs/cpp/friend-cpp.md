---
description: "Learn more about: friend (C++)"
title: "friend (C++)"
ms.date: "07/15/2019"
f1_keywords: ["friend_cpp"]
helpviewer_keywords: ["member access, from friend functions", "friend classes [C++]", "friend keyword [C++]"]
ms.assetid: 8fe9ee55-d56f-40cd-9075-d9fb1375aff4
---
# friend (C++)

Bazı durumlarda, bir sınıfın üyesi olmayan işlevlere veya ayrı bir sınıftaki tüm üyelere üye düzeyinde erişim vermek daha uygundur. Sadece sınıf uygulayıcısı arkadaşlarının kim olduğunu bildirebilir. Bir işlev veya sınıf, kendisini herhangi bir sınıfın arkadaşı olarak ilan edemez. Bir sınıf tanımında, **`friend`** sınıfınızın özel ve korumalı üyelerine erişim sağlamak için üye olmayan bir işlevin veya başka bir sınıfın anahtar sözcüğünü ve adını kullanın . Bir şablon tanımında, bir tür parametresi arkadaş olarak bildirilebilir.

## Syntax

```
class friend F
friend F;
```

## Friend declarations

Daha önce bildirilmemiş bir arkadaş işlevi bildirirseniz, bu işlev çevreleyen sınıf dışı kapsama aktarılır.

Bir arkadaş bildiriminde bildirilen işlevler, **`extern`** anahtar kelime kullanılarak bildirilmiş gibi değerlendirilir . Daha fazla bilgi için, bkz [extern](extern-cpp.md).

Genel kapsamlı işlevler prototiplerinden önce arkadaş olarak bildirilebilse de, üye işlevler tam sınıf bildirimi görünmeden önce arkadaş olarak bildirilemez. Aşağıdaki kod bunun neden başarısız olduğunu gösterir:

```cpp
class ForwardDeclared;   // Class name is known.
class HasFriends
{
    friend int ForwardDeclared::IsAFriend();   // C2039 error expected
};
```

The preceding example enters the class name `ForwardDeclared` into scope, but the complete declaration — specifically, the portion that declares the function `IsAFriend` — is not known. Therefore, the **`friend`** declaration in class `HasFriends` generates an error.

C++ 11'den başlayarak, bir sınıf için iki tür arkadaş bildirimi vardır:

```cpp
friend class F;
friend F;
```

İlk form, en içteki ad alanında bu ada sahip mevcut bir sınıf bulunmazsa, yeni bir F sınıfı sunar. **C++11**: İkinci form yeni bir sınıf tanıtmıyor; sınıf zaten bildirildiğinde kullanılabilir ve bir şablon türü parametresi veya bir typedef'i arkadaş olarak bildirirken kullanılmalıdır.

Kullanım `class friend F` başvurulan türü henüz ilan edilmemiştir zaman:

```cpp
namespace NS
{
    class M
    {
        class friend F;  // Introduces F but doesn't define it
    };
}
```

```cpp
namespace NS
{
    class M
    {
        friend F; // error C2433: 'NS::F': 'friend' not permitted on data declarations
    };
}
```

Aşağıdaki örnekte, NS kapsamı dışında bildirilen sınıfı `friend F` ifade eder `F`.

```cpp
class F {};
namespace NS
{
    class M
    {
        friend F;  // OK
    };
}
```

`friend F` Bir şablon parametresini arkadaş olarak bildirmek için kullanın :

```cpp
template <typename T>
class my_class
{
    friend T;
    //...
};
```

`friend F` Bir typedef'i arkadaş olarak bildirmek için kullanın :

```cpp
class Foo {};
typedef Foo F;

class G
{
    friend F; // OK
    friend class F // Error C2371 -- redefinition
};
```

Birbirinin arkadaşı olan iki sınıfı ilan etmek için, ikinci sınıfın tamamının birinci sınıfın arkadaşı olarak belirtilmesi gerekir. Bu kısıtlamanın nedeni, derleyicinin yalnızca ikinci sınıfın bildirildiği noktada bireysel arkadaş işlevlerini bildirecek kadar bilgiye sahip olmasıdır.

> [!NOTE]
> İkinci sınıfın tamamının birinci sınıfın arkadaşı olması gerekse de, birinci sınıftaki hangi işlevlerin ikinci sınıfın arkadaşı olacağını seçebilirsiniz.

## friend functions

Bir **`friend`** fonksiyon bir sınıfın üyesi olmayan ancak sınıfının özel ve korumalı üyeler erişimi olan bir fonksiyondur. Arkadaş işlevleri, sınıf üyeleri olarak kabul edilmez; bunlar, özel erişim ayrıcalıkları verilen normal harici işlevlerdir. Arkadaşlar sınıfın kapsamında değildir ve başka bir sınıfın üyesi olmadıkça üye seçim operatörleri (**.** and -**>**) kullanılarak çağrılmazlar . **`friend`** Erişim sağlayan sınıf tarafından bir işlev bildirilir. **`friend`** Beyan sınıf bildiriminde herhangi bir yere yerleştirilebilir. Erişim denetimi anahtar sözcüklerinden etkilenmez.

Aşağıdaki örnek, bir `Point` sınıf ve bir arkadaş işlevini gösterir, `ChangePrivate`. **`friend`** Fonksiyonu, özel veri elemanına erişimi `Point`, bir parametre olarak alır nesne.

```cpp
// friend_functions.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class Point
{
    friend void ChangePrivate( Point & );
public:
    Point( void ) : m_i(0) {}
    void PrintPrivate( void ){cout << m_i << endl; }

private:
    int m_i;
};

void ChangePrivate ( Point &i ) { i.m_i++; }

int main()
{
   Point sPoint;
   sPoint.PrintPrivate();
   ChangePrivate(sPoint);
   sPoint.PrintPrivate();
// Output: 0
           1
}
```

## Class members as friends

Sınıf üyesi işlevleri, diğer sınıflarda arkadaş olarak bildirilebilir. Aşağıdaki örneği göz önünde bulundurun:

```cpp
// classes_as_friends1.cpp
// compile with: /c
class B;

class A {
public:
   int Func1( B& b );

private:
   int Func2( B& b );
};

class B {
private:
   int _b;

   // A::Func1 is a friend function to class B
   // so A::Func1 has access to all members of B
   friend int A::Func1( B& );
};

int A::Func1( B& b ) { return b._b; }   // OK
int A::Func2( B& b ) { return b._b; }   // C2248
```

Önceki örnekte, yalnızca işleve `A::Func1( B& )` sınıfa arkadaş erişimi verilir `B`. Bu nedenle, özel üyeye erişim sınıfta `_b` doğrudur, ancak `Func1` `A` `Func2`

Bir **`friend`**sınıf, tüm üye işlevleri bir sınıfın arkadaş işlevleri olan, yani üye işlevleri diğer sınıfın özel ve korumalı üyelerine erişimi olan bir sınıftır. **`friend`** Sınıftaki bildirimin şöyle olduğunu varsayalım `B`:

```cpp
friend class A;
```

Bu durumda, sınıftaki tüm üye işlevlere, sınıfa `A` arkadaş erişimi verilmiş olur `B`. Aşağıdaki kod, bir arkadaş sınıfının bir örneğidir:

```cpp
// classes_as_friends2.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class YourClass {
friend class YourOtherClass;  // Declare a friend class
public:
   YourClass() : topSecret(0){}
   void printMember() { cout << topSecret << endl; }
private:
   int topSecret;
};

class YourOtherClass {
public:
   void change( YourClass& yc, int x ){yc.topSecret = x;}
};

int main() {
   YourClass yc1;
   YourOtherClass yoc1;
   yc1.printMember();
   yoc1.change( yc1, 5 );
   yc1.printMember();
}
```

Arkadaşlık, açıkça belirtilmediği sürece karşılıklı değildir. Yukarıdaki örnekte, öğesinin üye işlevleri, öğesinin `YourClass` özel üyelerine erişemez `YourOtherClass`.

Yönetilen bir tür (C++/CLI'de) herhangi bir arkadaş işlevine, arkadaş sınıfına veya arkadaş arabirimine sahip olamaz.

Arkadaşlık kalıtsal değildir, yani türetilen sınıflar 'in özel üyelerine  `YourOtherClass` erişemez `YourClass`. Arkadaşlık geçişli değildir, bu nedenle arkadaş olan sınıflar 'in özel üyelerine `YourOtherClass` erişemez `YourClass`.

Aşağıdaki şekilde dört sınıf bildirimi gösterilmektedir: `Base`, `Derived`, `aFriend`, ve `anotherFriend`. Yalnızca sınıfın `aFriend` özel üyelerine `Base` (ve herhangi bir üyeye `Base` miras kalmış olabilir) doğrudan erişimi vardır .

![Implications of friend relationship](../cpp/media/vc38v41.gif "Implications of friend relationship") <br/>
Implications of friend relationship

## Inline friend definitions

Arkadaş işlevleri, sınıf bildirimleri içinde tanımlanabilir (bir işlev gövdesi verilir). Bu işlevler satır içi işlevlerdir ve üye satır içi işlevler gibi, tüm sınıf üyeleri görüldükten hemen sonra, ancak sınıf kapsamı kapatılmadan önce (sınıf bildiriminin sonu) tanımlanmış gibi davranırlar. Sınıf bildirimleri içinde tanımlanan arkadaş işlevleri, çevreleyen sınıfın kapsamındadır.

## See also

[Keywords](../cpp/keywords-cpp.md)
