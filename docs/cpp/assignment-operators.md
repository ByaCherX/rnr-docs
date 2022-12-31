---
title: "Assignment operators"
description: "The C++ standard language assignment operators syntax and use."
ms.date: 07/24/2020
f1_keywords: ["=", "*=", "/=", "%=", "+=", "-=", "<<=", ">>=", "&=", "^=", "|="]
helpviewer_keywords: ["operators [C++], assignment", "assignment operators [C++], C++", "&= operator", "^= operator", "+= operator", ">>= operator", "|= operator", "operator>>=", "*= operator", "%= operator", "^= operator", "operator >>=", "= operator", "-= operator", "/= operator", "<<= operator"]
ms.assetid: b028cf35-2ff1-4f14-9027-fd53ebec8aa0
---
# Assignment operators

## Syntax

*expression* *assignment-operator* *expression*

*assignment-operator*: one of<br/>
&emsp;**`=`**&emsp;**`*=`**&emsp;**`/=`**&emsp;**`%=`**&emsp;**`+=`**&emsp;**`-=`**&emsp;**`<<=`**&emsp;**`>>=`**&emsp;**`&=`**&emsp;**`^=`**&emsp;**`|=`**

## Remarks

Atama operatörleri, sol işlenen tarafından belirtilen nesnede bir değer depolar. İki tür atama işlemi vardır:

- ikinci işlenenin değerinin birinci işlenen tarafından belirtilen nesnede saklandığı *simple assignment*.

- sonucu saklamadan önce bir aritmetik, kaydırma veya bit düzeyinde işlemin gerçekleştirildiği *compound assignment*

Operatör dışında aşağıdaki tabloda yer alan tüm atama operatörleri **`=`** bileşik atama operatörleridir.
### Assignment operators table

| Operator | Meaning |
|--|--|
| **`=`** | İkinci işlenenin değerini birinci işlenen tarafından belirtilen nesnede saklayın (basit atama). |
| **`*=`** | Birinci işlenenin değerini ikinci işlenenin değeriyle çarpın; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`/=`** | İlk işlenenin değerini ikinci işlenenin değerine bölün; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`%=`** | İkinci işlenenin değeriyle belirtilen birinci işlenenin modülünü alın; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`+=`** | İkinci işlenenin değerini birinci işlenenin değerine ekleyin; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`-=`** | 	İkinci işlenenin değerini birinci işlenenin değerinden çıkarın; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`<<=`** | Birinci işlenenin değerini, ikinci işlenenin değeri tarafından belirtilen bit sayısını sola kaydırın; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`>>=`** | Birinci işlenenin değerini, ikinci işlenenin değeri tarafından belirtilen bit sayısı kadar sağa kaydırın; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`&=`** | Birinci ve ikinci işlenenlerin bit düzeyinde AND'sini alın; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`^=`** | Birinci ve ikinci işlenenlerin bit düzeyinde özel VEYA'sını elde edin; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |
| **`|=`** | Birinci ve ikinci işlenenlerin bit düzeyinde kapsayıcı VEYA'sını elde edin; sonucu ilk işlenen tarafından belirtilen nesnede saklayın. |

### Operator keywords

Bileşik atama operatörlerinden üçünün anahtar kelime eşdeğerleri vardır. Onlar:

| Operator | Equivalent |
|--|--|
| **`&=`** | **`and_eq`** |
| **`|=`** | **`or_eq`** |
| **`^=`** | **`xor_eq`** |

C++, bu işleç anahtar sözcüklerini, bileşik atama işleçleri için alternatif yazımlar olarak belirtir. C'de, alternatif yazımlar \<iso646.h> başlığında makrolar olarak sağlanır. C++'da alternatif yazımlar anahtar sözcüklerdir; \<iso646.h> veya C++ eşdeğeri \<ciso646> kullanımı kullanımdan kaldırılmıştır. Microsoft C++' [`/permissive-`](../build/reference/permissive-standards-conformance.md) or [`/Za`](../build/reference/za-ze-disable-language-extensions.md) alternatif yazımı etkinleştirmek için veya derleyici seçeneği gereklidir.

## Example

```cpp
// expre_Assignment_Operators.cpp
// compile with: /EHsc
// Demonstrate assignment operators
#include <iostream>
using namespace std;
int main() {
   int a = 3, b = 6, c = 10, d = 0xAAAA, e = 0x5555;

   a += b;      // a is 9
   b %= a;      // b is 6
   c >>= 1;      // c is 5
   d |= e;      // Bitwise--d is 0xFFFF

   cout  << "a = 3, b = 6, c = 10, d = 0xAAAA, e = 0x5555" << endl
         << "a += b yields " << a << endl
         << "b %= a yields " << b << endl
         << "c >>= 1 yields " << c << endl
         << "d |= e yields " << hex << d << endl;
}
```

## Simple assignment

Basit atama operatörü (**`=`**), ikinci işlenenin değerinin birinci işlenen tarafından belirtilen nesnede saklanmasına neden olur. Her iki nesne de aritmetik türdeyse, sağdaki işlenen, değeri kaydetmeden önce soldaki türe dönüştürülür.

Nesneleri **`const`** ve **`volatile`** türleri, yalnızca **`volatile`** olan veya olmayan **`const`** veya olmayan türlerin l değerlerine atanabilir **`volatile`**.

Sınıf türündeki (**`struct`**, **`union`**, and **`class`** types) nesnelere atama , adlı bir işlev tarafından gerçekleştirilir `operator=`. Bu operatör işlevinin varsayılan davranışı, bit düzeyinde kopyalama gerçekleştirmektir; ancak bu davranış aşırı yüklenmiş operatörler kullanılarak değiştirilebilir. Daha fazla bilgi için, bkz. [Operator overloading](../cpp/operator-overloading.md). Sınıf türlerinde ayrıca *kopya atama* ve taşıma atama operatörleri olabilir. Daha fazla bilgi için bkz. [Copy constructors and copy assignment operators](copy-constructors-and-copy-assignment-operators-cpp.md) ve [Move constructors and move assignment operators](move-constructors-and-move-assignment-operators-cpp.md).

Belirli bir temel sınıftan kesin olarak türetilmiş herhangi bir sınıfın nesnesi, temel sınıfın bir nesnesine atanabilir. Bunun tersi doğru değildir, çünkü türetilmiş sınıftan temel sınıfa örtük bir dönüşüm vardır, ancak temel sınıftan türetilmiş sınıfa değil. Örneğin:

```cpp
// expre_SimpleAssignment.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
class ABase
{
public:
    ABase() { cout << "constructing ABase\n"; }
};

class ADerived : public ABase
{
public:
    ADerived() { cout << "constructing ADerived\n"; }
};

int main()
{
    ABase aBase;
    ADerived aDerived;

    aBase = aDerived; // OK
    aDerived = aBase; // C2679
}
```

Referans tiplerine atamalar, sanki referansın işaret ettiği nesneye atama yapılıyormuş gibi davranır.

Sınıf türü nesneler için atama, başlatmadan farklıdır. Atama ve başlatmanın ne kadar farklı olabileceğini göstermek için kodu göz önünde bulundurun.

```cpp
UserType1 A;
UserType2 B = A;
```

Önceki kod bir başlatıcıyı gösterir; `UserType2` tür bir argüman aldığı için yapıcıyı çağırır `UserType1`. verilen kod

```cpp
UserType1 A;
UserType2 B;

B = A;
```

the assignment statement

```cpp
B = A;
```

aşağıdaki etkilerden birine sahip olabilir:

- İşlevini çağırın `operator=` için UserType2sağlanan `operator=` bir sağlanır `UserType1` argüman.

- `UserType1::operator UserType2` Böyle bir işlev varsa , açık dönüştürme işlevini çağırın .

- `UserType2::UserType2` Böyle bir kurucu varsa, bir `UserType1` argüman alan ve sonucu kopyalayan bir kurucu çağırın .

## Compound assignment

Bileşik atama operatörleri, [Assignment operators table](#assignment-operators-table)'da gösterilir. Bu operatörler bir şekilde sahip *e1* *op* = *e2* , *e1* olmayan bir olup **`const`**, değiştirilebilir l-value ve *e2* olup:

aritmetik bir tür

bir işaretçi, *op* ise **`+`** or **`-`**

The *e1* *op* = *e2* olarak bir şekilde davranır *e1* *e1* *op* *e2*, ancak *e1* sadece bir kere elde edildi.=

Numaralandırılmış bir türe bileşik atama, bir hata mesajı oluşturur. Sol işlenen işaretçi türündeyse, sağ işlenen işaretçi türünde veya 0 olarak değerlendirilen sabit bir ifade olmalıdır. Sol işlenen bir integral türünde olduğunda, sağ işlenen bir işaretçi türünden olmamalıdır. işaretçi türü.

## Result of assignment operators

Atama operatörleri, atamadan sonra sol işlenen tarafından belirtilen nesnenin değerini döndürür. Ortaya çıkan tür, sol işlenenin türüdür. Atama ifadesinin sonucu her zaman bir l değeridir. Bu operatörler sağdan sola ilişkilendirilebilirliğe sahiptir. Sol işlenen, değiştirilebilir bir l değeri olmalıdır.

ANSI C'de atama ifadesinin sonucu bir l değeri değildir. Bu, C'de yasal C++ ifadesine `(a += b) += c` izin verilmediği anlamına gelir .

## See also

[Expressions with binary operators](../cpp/expressions-with-binary-operators.md)<br/>
[C++ built-in operators, precedence, and associativity](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[C assignment operators](../c-language/c-assignment-operators.md)
