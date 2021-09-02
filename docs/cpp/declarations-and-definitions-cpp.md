---
description: "Learn more about: Declarations and definitions (C++)"
title: "Declarations and definitions (C++)"
ms.date: "12/12/2019"
ms.assetid: 678f1424-e12f-45e0-a957-8169e5fef6cb
---
# Declarations and definitions (C++)

Bir C++ programı değişkenler, işlevler, türler ve ad alanları gibi çeşitli varlıklardan oluşur. Bu varlıkların her biri, kullanılmadan önce bildirilmelidir . Bir bildirim, türü ve diğer özellikleri hakkında bilgilerle birlikte varlık için benzersiz bir ad belirtir. C++'da bir ismin bildirildiği nokta, derleyici tarafından görünür hale geldiği noktadır. Derleme biriminde daha sonraki bir noktada bildirilen bir işleve veya sınıfa başvuramazsınız. Değişkenler, kullanıldıkları noktadan önce mümkün olduğunca yakın bildirilmelidir.

Aşağıdaki örnek, bazı bildirimleri gösterir:

```cpp
#include <string>

void f(); // forward declaration

int main()
{
    const double pi = 3.14; //OK
    int i = f(2); //OK. f is forward-declared
    `std::string` str; // OK `std::string` is declared in <string> header
    C obj; // error! C not yet declared.
    j = 0; // error! No type specified.
    auto k = 0; // OK. type inferred as int by compiler.
}

int f(int i)
{
    return i + 42;
}

namespace N {
   class C{/*...*/};
}
```

line 5. satırda `main` işlev bildirilir. 7. satırda, **`const`** adlı bir değişken `pi` bildirilir ve başlatılır. 8. satırda, bir tamsayı `i` bildirilir ve işlev tarafından üretilen değerle başlatılır `f`. Ad `f`, 3. satırdaki ileri bildirim nedeniyle derleyici tarafından görülebilir .

line 9. satırda `obj`, tip adında bir değişken `C` bildirildi. Ancak, bu bildirim bir hataya neden olur, çünkü `C`programda daha sonra bildirilmez ve ileriye dönük olarak bildirilmez. Hatayı düzeltmek için, ya bütün taşıyabilirsiniz tanımını ait `C` öncesinde `main` veya başka bunun için bir ileriye deklarasyon ekleyin. Bu davranış, işlevlerin ve sınıfların bir kaynak dosyadaki bildirim noktalarından önce kullanılabildiği C# gibi diğer dillerden farklıdır.

line 10. satırda `str`, type adında bir değişken `std::string` bildirildi. 1. satırda kaynak dosyayla birleştirilen [header file](header-files-cpp.md) `std::string` tanıtıldığı için ad görünür . Sınıfın bildirildiği ad alanıdır.string `std` `string`

line 11. satırda, ad `j` bildirilmediği için bir hata oluştu. Bir bildirim, javaScript gibi diğer dillerden farklı olarak bir tür sağlamalıdır. 12. satırda **`auto`**, derleyiciye `k`, başlatıldığı değere dayalı olarak türünü çıkarmasını söyleyen anahtar kelime kullanılır. Bu durumda derleyici **`int`** türü seçer .

## Declaration scope

Bir bildirimin tanıttığı ad , bildirimin gerçekleştiği kapsamda geçerlidir . Önceki örnekte, mainişlevin içinde bildirilen değişkenler *yerel değişkenlerdir*. `i` `main` dışında, *global kapsamda* başka bir değişken tanımlayabilirsiniz ve bu tamamen ayrı bir varlık olacaktır. Ancak, bu tür ad tekrarı, programcının kafa karışıklığına ve hatalarına yol açabilir ve bundan kaçınılmalıdır. 21. satırda sınıf `C`, ad alanı kapsamında bildirilir `N`. Ad alanlarının kullanımı, ad çakışmalarını önlemeye yardımcı olur . Çoğu C++ Standart Kitaplığı adları, `std` ad alanı. Bildirimleri ile etkileşim nasıl kapsam kuralları hakkında daha fazla bilgi için bkz [Scope](../cpp/scope-visual-cpp.md).

## Definitions

İşlevler, sınıflar, numaralandırmalar ve sabit değişkenler dahil olmak üzere bazı varlıklar, bildirilmeye ek olarak tanımlanmalıdır. Bir tanım varlık programda daha sonra kullanıldığında makinenin kodu oluşturmak için gereken bilgileri tüm derleyici sağlar. Önceki örnekte, 3. satır, işlev için bir bildirim içerir, `f` ancak işlevin tanımı , 15'ten 18'e kadar olan satırlarda sağlanır. 21. satırda, sınıf `C` hem bildirilmiş hem de tanımlanmıştır (tanımlandığı gibi sınıf hiçbir şey yapmasa da) . Bir sabit değişken, bildirildiği aynı ifadede tanımlanmalıdır, başka bir deyişle bir değer atanmalıdır. Yerleşik bir tür bildirimi, örneğin **`int`** otomatik olarak bir tanımdır çünkü derleyici buna ne kadar yer ayıracağını bilir.

Aşağıdaki örnek, aynı zamanda tanım olan bildirimleri gösterir:

```cpp
// Declare and define int variables i and j.
int i;
int j = 10;

// Declare enumeration suits.
enum suits { Spades = 1, Clubs, Hearts, Diamonds };

// Declare class CheckBox.
class CheckBox : public Control
{
public:
    Boolean IsChecked();
    virtual int     ChangeState() = 0;
};
```

Here are some declarations that are not definitions:

```cpp
extern int i;
char *strchr( const char *Str, const char Target );
```

## Typedefs and using statements

C++'ın eski sürümlerinde, [`typedef`](aliases-and-typedefs-cpp.md) anahtar sözcük, başka bir ad için takma ad (*alias*) olan yeni bir ad bildirmek için kullanılır . Örneğin, tür `std::string` için başka bir addır `std::basic_string<char>`. Programcıların neden gerçek adı değil de typedef adını kullandığı açık olmalıdır. Modern C++'da [`using`](aliases-and-typedefs-cpp.md) anahtar kelime yerine anahtar kelime tercih edilir **`typedef`**, ancak fikir aynıdır: önceden bildirilmiş ve tanımlanmış bir varlık için yeni bir ad bildirilir.

## Static class members

Statik sınıf veri üyeleri, sınıfın tüm nesneleri tarafından paylaşılan ayrık değişkenler olduğundan, sınıf tanımının dışında tanımlanmalı ve başlatılmalıdır. (Daha fazla bilgi için, bkz. [Classes](../cpp/classes-and-structs-cpp.md).)

## extern declarations

Bir C++ programı birden fazla derleme birimi içerebilir. Ayrı bir [compilation unit](header-files-cpp.md)'de tanımlanmış bir varlık bildirmek için [`extern`](extern-cpp.md) anahtar sözcüğü kullanın. Beyannamedeki bilgiler derleyici için yeterlidir, ancak varlığın tanımı bağlama adımında bulunamazsa, bağlayıcı hata verecektir.

## In this section

[Storage classes](storage-classes-cpp.md)<br/>
[`const`](const-cpp.md)<br/>
[`constexpr`](constexpr-cpp.md)<br/>
[`extern`](extern-cpp.md)<br/>
[Initializers](initializers.md)<br/>
[Aliases and typedefs](aliases-and-typedefs-cpp.md)<br/>
[`using` declaration](using-declaration.md)<br/>
[`volatile`](volatile-cpp.md)<br/>
[`decltype`](decltype-cpp.md)<br/>
[Attributes in C++](attributes.md)<br/>

## See also

[Basic Concepts](../cpp/basic-concepts-cpp.md)<br/>
