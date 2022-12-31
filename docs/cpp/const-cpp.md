---
description: "Learn more about: const (C++)"
title: "const (C++)"
ms.date: "11/04/2016"
f1_keywords: ["const_cpp"]
helpviewer_keywords: ["const keyword [C++]"]
ms.assetid: b21c0271-1ad0-40a0-b21c-5e812bba0318
---
# const (C++)

Bir veri bildirimini değiştirirken, **`const`** anahtar sözcük, nesnenin veya değişkenin değiştirilemez olduğunu belirtir.

## Syntax

```
const declaration ;
member-function const ;
```

## const values

**`const`** Anahtar kelime belirtir bir değişkenin değeri sabittir ve onu değiştirmesini programcı önlemek için derleyici söyler.

```cpp
// constant_values1.cpp
int main() {
   const int i = 5;
   i = 10;   // C3892
   i++;   // C2105
}
```

C++'da, sabit değerleri tanımlamak **`const`** için [#define](../preprocessor/hash-define-directive-c-cpp.md) önişlemci yönergesi yerine anahtar sözcüğü kullanabilirsiniz . ile tanımlanan değerler **`const`** tip kontrolüne tabidir ve sabit ifadeler yerine kullanılabilir. C++'da, bir **`const`** değişkene sahip bir dizinin boyutunu aşağıdaki gibi belirleyebilirsiniz:

```cpp
// constant_values2.cpp
// compile with: /c
const int maxarray = 255;
char store_char[maxarray];  // allowed in C++; not allowed in C
```

C'de, sabit değerler varsayılan olarak harici bağlantıya göredir, böylece yalnızca kaynak dosyalarda görünebilirler. C++'da, sabit değerler varsayılan olarak dahili bağlantıya geçer ve bu da onların başlık dosyalarında görünmelerine olanak tanır.

**`const`** Anahtar kelime de işaretçi beyanlarında kullanılabilir.

```cpp
// constant_values3.cpp
int main() {
   char *mybuf = 0, *yourbuf;
   char *const aptr = mybuf;
   *aptr = 'a';   // OK
   aptr = yourbuf;   // C3892
}
```

Olarak bildirilen bir değişkene **`const`** işaretçi, yalnızca olarak da bildirilen bir işaretçiye atanabilir **`const`**.

```cpp
// constant_values4.cpp
#include <stdio.h>
int main() {
   const char *mybuf = "test";
   char *yourbuf = "test2";
   printf_s("%s\n", mybuf);

   const char *bptr = mybuf;   // Pointer to constant data
   printf_s("%s\n", bptr);

   // *bptr = 'a';   // Error
}
```

İşlevin bir işaretçiden geçen bir parametreyi değiştirmesini önlemek için, verileri işlev parametreleri olarak sabit tutmak için işaretçiler kullanabilirsiniz.

olarak bildirilen nesneler **`const`** için yalnızca sabit üye işlevlerini çağırabilirsiniz. Bu, sabit nesnenin asla değiştirilmemesini sağlar.

```cpp
birthday.getMonth();    // Okay
birthday.setMonth( 4 ); // Error
```

Sabit olmayan bir nesne için sabit veya sabit olmayan üye işlevleri çağırabilirsiniz. **`const`** Anahtar sözcüğü kullanarak bir üye işlevini de aşırı yükleyebilirsiniz ; bu, sabit ve sabit olmayan nesneler için işlevin farklı bir sürümünün çağrılmasını sağlar.

**`const`** Anahtar kelimeyle yapıcıları veya yıkıcıları bildiremezsiniz .

## const member functions

**`const`** Anahtar sözcükle bir üye işlevi bildirmek, işlevin çağrıldığı nesneyi değiştirmeyen "salt okunur" bir işlev olduğunu belirtir. Bir sabit üye işlevi, statik olmayan herhangi bir veri üyesini değiştiremez veya sabit olmayan herhangi bir üye işlevini çağıramaz. Sabit bir üye işlevi bildirmek için, **`const`** anahtar sözcüğü bağımsız değişken listesinin kapanış parantezinden sonra yerleştirin. **`const`** Anahtar kelime beyanı ve tanımı hem de gereklidir.

```cpp
// constant_member_function.cpp
class Date
{
public:
   Date( int mn, int dy, int yr );
   int getMonth() const;     // A read-only function
   void setMonth( int mn );   // A write function; can't be const
private:
   int month;
};

int Date::getMonth() const
{
   return month;        // Doesn't modify anything
}
void Date::setMonth( int mn )
{
   month = mn;          // Modifies data member
}
int main()
{
   Date MyDate( 7, 4, 1998 );
   const Date BirthDate( 1, 18, 1953 );
   MyDate.setMonth( 4 );    // Okay
   BirthDate.getMonth();    // Okay
   BirthDate.setMonth( 4 ); // C2662 Error
}
```

## C and C++ const differences

Bir değişkeni **`const`** C kaynak kod dosyasında olduğu gibi bildirdiğinizde , bunu şu şekilde yaparsınız:

```cpp
const int i = 2;
```

Daha sonra bu değişkeni başka bir modülde aşağıdaki gibi kullanabilirsiniz:

```cpp
extern const int i;
```

Ancak aynı davranışı C++'da elde etmek için **`const`** değişkeninizi şu şekilde bildirmelisiniz :

```cpp
extern const int i = 2;
```

**`extern`** Bir C kaynak kodu dosyasında kullanmak üzere bir C++ kaynak kodu dosyasında bir değişken bildirmek istiyorsanız , şunu kullanın:

```cpp
extern "C" const int x=10;
```

C++ derleyicisi tarafından ad yönetimini önlemek için.

## Remarks

Bir üye işlevin parametre listesini takip ederken, **`const`** anahtar sözcük, işlevin çağrıldığı nesneyi değiştirmediğini belirtir.

hakkında daha fazla bilgi **`const`** için aşağıdaki konulara bakın:

- [const and volatile Pointers](../cpp/const-and-volatile-pointers.md)

- [Type Qualifiers (C Language Reference)](../c-language/type-qualifiers.md)

- [volatile](../cpp/volatile-cpp.md)

- [#define](../preprocessor/hash-define-directive-c-cpp.md)

## See also

[Keywords](../cpp/keywords-cpp.md)
