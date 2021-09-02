---
description: "Learn more about: Header files (C++)"
title: "Header files (C++)"
ms.date: "12/11/2019"
helpviewer_keywords: ["header files [C++]"]
---
# Header files (C++)

Değişkenler, işlevler, sınıflar vb. gibi program öğelerinin adları, kullanılmadan önce bildirilmelidir. Örneğin, `x = 42` önce 'x' bildirmeden yazamazsınız.

```cpp
int x; // declaration
x = 42; // use x
```

Bildirim, derleyiciye öğenin bir **`int`**, a **`double`**, a **function**, a **`class`** veya başka bir şey olup olmadığını söyler . Ayrıca, her ad, kullanıldığı her .cpp dosyasında (doğrudan veya dolaylı olarak) bildirilmelidir. Bir programı derlerken, her .cpp dosyası bağımsız olarak bir derleme biriminde derlenir. Derleyici, diğer derleme birimlerinde hangi adların bildirildiğini bilmiyor. Bu, bir sınıf, işlev veya genel değişken tanımlarsanız, onu kullanan her ek .cpp dosyasında o şeyin bir bildirimini sağlamanız gerektiği anlamına gelir. Bu şeyin her bildirimi tüm dosyalarda tam olarak aynı olmalıdır. Bağlayıcı tüm derleme birimlerini tek bir programda birleştirmeye çalıştığında, hafif bir tutarsızlık hatalara veya istenmeyen davranışlara neden olur.

Hata olasılığını en aza indirmek için C++, bildirimleri içermek için *header files* kullanma kuralını benimsemiştir . Bildirimleri bir başlık dosyasında yaparsınız, ardından her .cpp dosyasında veya bu bildirimi gerektiren diğer başlık dosyasında #include yönergesini kullanırsınız. #include yönergesi, derlemeden önce başlık dosyasının bir kopyasını doğrudan .cpp dosyasına ekler.

> [!NOTE]
> Visual Studio 2019'da, C++20 modülleri özelliği, başlık dosyalarının bir iyileştirmesi ve nihai olarak değiştirilmesi olarak sunulmuştur. Daha fazla bilgi için bkz. [Overview of modules in C++](modules-cpp.md).

## Example

Aşağıdaki örnek, bir sınıf bildirmenin ve ardından onu farklı bir kaynak dosyada kullanmanın yaygın bir yolunu gösterir. Başlık dosyasıyla başlayacağız, `my_class.h`. Bir sınıf tanımı içerir, ancak tanımın eksik olduğuna dikkat edin; üye işlevi `do_something` tanımlı değil:

```cpp
// my_class.h
namespace N
{
    class my_class
    {
    public:
        void do_something();
    };

}
```

Ardından, bir uygulama dosyası oluşturun (genellikle .cpp veya benzeri bir uzantıya sahip). my_class.cpp dosyasını arayacağız ve üye bildirimi için bir tanım sağlayacağız. `#include` Bu noktada my_class bildiriminin .cpp dosyasına eklenmesi için "my_class.h" dosyasına bir yönerge ekliyoruz ve .cpp dosyasına `<iostream>` çekmeyi dahil ediyoruz `std::cout`. Kaynak dosyayla aynı dizindeki başlık dosyaları için tırnak işaretleri kullanıldığını ve standart kitaplık başlıkları için açılı ayraçların kullanıldığını unutmayın. Ayrıca, birçok standart kitaplık başlığında .h veya başka bir dosya uzantısı yoktur.

Uygulama dosyasında, **`using`** "my_class" veya "cout" kelimelerinin her sözünü "N::" veya "std::" ile nitelemek zorunda kalmamak için isteğe bağlı olarak bir ifade kullanabiliriz. **`using`** Başlık dosyalarınıza ifadeler koymayın!

```cpp
// my_class.cpp
#include "my_class.h" // header in local directory
#include <iostream> // header in standard library

using namespace N;
using namespace std;

void my_class::do_something()
{
    cout << "Doing something!" << endl;
}
```

Artık `my_class` başka bir .cpp dosyasında kullanabiliriz. Derleyicinin bildirimi çekmesi için başlık dosyasını #include ediyoruz. Derleyicinin bilmesi gereken tek şey, my_class öğesinin, adlı genel üye işlevine sahip bir sınıf olmasıdır `do_something()`.

```cpp
// my_program.cpp
#include "my_class.h"

using namespace N;

int main()
{
    my_class mc;
    mc.do_something();
    return 0;
}
```

Derleyici her .cpp dosyasını .obj dosyalarına derlemeyi bitirdikten sonra, .obj dosyalarını bağlayıcıya iletir. Bağlayıcı nesne dosyalarını birleştirdiğinde, my_class için tam olarak bir tanım bulur; my_class.cpp için üretilen .obj dosyasındadır ve derleme başarılı olur.

## Include guards

Tipik olarak, başlık dosyalarında birden çok kez tek bir .cpp dosyasına eklenmemelerini sağlamak için bir içerme koruması veya `#pragma once` yönergesi bulunur.

```cpp
// my_class.h
#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H

namespace N
{
    class my_class
    {
    public:
        void do_something();
    };
}

#endif /* MY_CLASS_H */
```

## What to put in a header file

Bir başlık dosyası potansiyel olarak birden çok dosya tarafından içerilebileceğinden, aynı ada sahip birden çok tanım üretebilecek tanımları içeremez. Aşağıdakilere izin verilmez veya çok kötü uygulama olarak kabul edilir:

- ad alanında (namespace) veya genel kapsamda (global scope) yerleşik tür tanımlarında
- satır içi olmayan işlev tanımları (non-inline function)
- const olmayan değişken tanımları (non-const variable)
- toplu tanımlar (aggregate definitions)
- adsız ad alanları (unnamed namespaces)
- direktifleri kullanmak

Kullanımı **`using`** yönergesi mutlaka hataya neden olmaz, ancak can potansiyel bir sorun nedeni doğrudan ya da dolaylı olarak bu başlık içerdiğini her .cpp dosyasında kapsam içine ad getiriyor çünkü.

## Sample header file

Aşağıdaki örnek, bir başlık dosyasında izin verilen çeşitli türde bildirimleri ve tanımları gösterir:
```cpp
// sample.h
#pragma once
#include <vector> // #include directive
#include <string>

namespace N  // namespace declaration
{
    inline namespace P
    {
        //...
    }

    enum class colors : short { red, blue, purple, azure };

    const double PI = 3.14;  // const and constexpr definitions
    constexpr int MeaningOfLife{ 42 };
    constexpr int get_meaning()
    {
        static_assert(MeaningOfLife == 42, "unexpected!"); // static_assert
        return MeaningOfLife;
    }
    using vstr = std::vector<int>;  // type alias
    extern double d; // extern variable

#define LOG   // macro definition

#ifdef LOG   // conditional compilation directive
    void print_to_log();
#endif

    class my_class   // regular class definition,
    {                // but no non-inline function definitions

        friend class other_class;
    public:
        void do_something();   // definition in my_class.cpp
        inline void put_value(int i) { vals.push_back(i); } // inline OK

    private:
        vstr vals;
        int i;
    };

    struct RGB
    {
        short r{ 0 };  // member initialization
        short g{ 0 };
        short b{ 0 };
    };

    template <typename T>  // template definition
    class value_store
    {
    public:
        value_store<T>() = default;
        void write_value(T val)
        {
            //... function definition OK in template
        }
    private:
        std::vector<T> vals;
    };

    template <typename T>  // template declaration
    class value_widget;
}
```
