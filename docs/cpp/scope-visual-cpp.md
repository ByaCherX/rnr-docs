---
description: "Learn more about: Scope (C++)"
title: "Scope (C++)"
ms.date: "11/19/2018"
helpviewer_keywords: ["classes [C++], scope", "scope [C++]", "function prototypes [C++], scope", "class scope", "prototype scope", "functions [C++], scope", "scope, C++ names"]
ms.assetid: 81fecbb0-338b-4325-8332-49f33e716352
---
# Scope (C++)

Sınıf, işlev veya değişken gibi bir program öğesi bildirdiğinizde, adı yalnızca programınızın belirli bölümlerinde "görülebilir" ve kullanılabilir. Bir adın görünür olduğu bağlam, kapsamı olarak adlandırılır . Örneğin, `x` bir işlev içinde bir değişken `x` bildirirseniz, yalnızca o işlev gövdesi içinde görünür. It has yerel kapsamını . Programınızda aynı isimde başka değişkenler olabilir; farklı kapsamlarda oldukları sürece Tek Tanım Kuralını ihlal etmezler ve hata oluşmaz.

Otomatik statik olmayan değişkenler için kapsam, bunların program belleğinde ne zaman oluşturulduğunu ve yok edildiğini de belirler.

Altı çeşit kapsam vardır:

- **Global scope** Genel ad, herhangi bir sınıf, işlev veya ad alanının dışında bildirilen addır. Ancak, C++'da bu adlar bile örtük bir global ad alanıyla bulunur. Genel adların kapsamı, bildirim noktasından bildirildikleri dosyanın sonuna kadar uzanır. Genel adlar için görünürlük, adın programdaki diğer dosyalarda görünür olup olmadığını belirleyen bağlantı kuralları tarafından da yönetilir. [linkage](program-and-linkage-cpp.md)

- **Namespace scope** Bir ad alanı içinde , herhangi bir sınıf veya numaralandırma tanımının veya işlev bloğunun dışında bildirilen bir [namespace](namespaces-cpp.md), bildirim noktasından ad alanının sonuna kadar görünür. Bir ad alanı, farklı dosyalar arasında birden çok blokta tanımlanabilir.

- **Local scope** Parametre adları da dahil olmak üzere bir işlev veya lambda içinde bildirilen bir ad, yerel kapsama sahiptir. Genellikle "yerli" olarak adlandırılırlar. Yalnızca bildirim noktalarından işlevin veya lambda gövdesinin sonuna kadar görünürler. Yerel kapsam, bu makalenin ilerleyen kısımlarında tartışılacak olan bir tür blok kapsamıdır.

- **Class scope** Sınıf üyelerinin adları, bildirim noktasından bağımsız olarak sınıf tanımı boyunca uzanan sınıf kapsamına sahiptir. Sınıf üyesi erişilebilirlik ayrıca kontrol edilir, **`public`**, **`private`**, ve **`protected`** anahtar kelimeler. Genel veya korumalı üyelere yalnızca üye seçim operatörleri (**.** veya **->**) veya işaretçiden üyeye operatörler (**.**<strong>\*</strong> veya **->**<strong>\*</strong>).0U

- **Statement scope** Deyim kapsamı Bir **`for`**, **`if`**, **`while`**, or **`switch`** deyiminde bildirilen adlar , deyim bloğunun sonuna kadar görünür.

- **Function scope** Bir [label](labeled-statements.md) işlev kapsamı vardır; bu, onun, bildirim noktasından önce bile bir işlev gövdesinde görünür olduğu anlamına gelir. İşlev kapsamı `goto cleanup`, `cleanup` etiket bildirilmeden önceki gibi ifadeler yazmayı mümkün kılar .

## Hiding Names

Bir adı kapalı bir blokta bildirerek gizleyebilirsiniz. Aşağıdaki şekilde, `i` iç blok içinde yeniden bildirilir, böylece `i` dış blok kapsamında ilişkili değişken gizlenir .

![Block&#45;scope name hiding](../cpp/media/vc38sf1.png "Block&#45;scope name hiding") <br/>
Block scope and name hiding

Şekilde gösterilen programın çıktısı:

```cpp
i = 0
i = 7
j = 9
i = 0
```

> [!NOTE]
> Argümanın `szWhat` işlevin kapsamında olduğu kabul edilir. Bu nedenle, işlevin en dış bloğunda bildirilmiş gibi işlem görür.

## Hiding class names

Aynı kapsamda bir işlev, nesne veya değişken ya da numaralandırıcı bildirerek sınıf adlarını gizleyebilirsiniz. Bununla birlikte, anahtar kelime tarafından önek eklendiğinde sınıf adına hala erişilebilir **`class`**.

```cpp
// hiding_class_names.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

// Declare class Account at global scope.
class Account
{
public:
    Account( double InitialBalance )
        { balance = InitialBalance; }
    double GetBalance()
        { return balance; }
private:
    double balance;
};

double Account = 15.37;            // Hides class name Account

int main()
{
    class Account Checking( Account ); // Qualifies Account as
                                       //  class name

    cout << "Opening account with a balance of: "
         << Checking.GetBalance() << "\n";
}
//Output: Opening account with a balance of: 15.37
```

> [!NOTE]
> Sınıf adının (`Account`) çağrıldığı herhangi bir yerde, onu global kapsamlı Hesap değişkeninden ayırt etmek için sınıf anahtar sözcüğü kullanılmalıdır. Bu kural, sınıf adı kapsam çözümleme operatörünün (::) sol tarafında yer aldığında uygulanmaz. Kapsam çözümleme operatörünün sol tarafındaki adlar her zaman sınıf adları olarak kabul edilir.

Aşağıdaki örnek `Account`,**`class`** anahtar kelimeyi kullanarak bir tür nesneye bir işaretçinin nasıl bildirileceğini gösterir :

```cpp
class Account *Checking = new class Account( Account );
```

`Account` Yukarıdaki açıklamada başlatıcısı (parantez içinde) küresel kapsamı vardır;**`double`** tipindedir .

> [!NOTE]
> The reuse of identifier names as shown in this example is considered poor programming style.

For information about declaration and initialization of class objects, see [Classes, Structures, and Unions](../cpp/classes-and-structs-cpp.md). For information about using the **`new`** and **`delete`** free-store operators, see [new and delete operators](new-and-delete-operators.md).

## Hiding names with global scope

Aynı adı blok kapsamında açıkça bildirerek, genel kapsamdaki adları gizleyebilirsiniz. Ancak, genel kapsam adlarına, kapsam çözümleme operatörü (`::`) kullanılarak erişilebilir .

```cpp
#include <iostream>

int i = 7;   // i has global scope, outside all blocks
using namespace std;

int main( int argc, char *argv[] ) {
   int i = 5;   // i has block scope, hides i at global scope
   cout << "Block-scoped i has the value: " << i << "\n";
   cout << "Global-scoped i has the value: " << ::i << "\n";
}
```

```Output
Block-scoped i has the value: 5
Global-scoped i has the value: 7
```

## See also

[Basic Concepts](../cpp/basic-concepts-cpp.md)
