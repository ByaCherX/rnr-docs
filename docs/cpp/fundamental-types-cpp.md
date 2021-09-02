---
description: "Learn more about: Built-in types (C++)"
title: "Built-in types  (C++)"
ms.date: 07/22/2020
f1_keywords: ["__int128_cpp", "__wchar_t_cpp", "char_cpp", "char8_t_cpp", "char16_t_cpp", "char32_t_cpp", "double_cpp", "float_cpp", "int_cpp", "long_cpp", "long_double_cpp", "short_cpp", "signed_cpp", "unsigned_cpp", "unsigned_int_cpp", "wchar_t_cpp"]
helpviewer_keywords: ["specifiers [C++], type", "float keyword [C++]", "char keyword [C++]", "__wchar_t keyword [C++]", "signed types [C++], summary of data types", "Integer data type [C++], C++ data types", "arithmetic operations [C++], types", "int data type", "unsigned types [C++], summary of data types", "short data type [C++]", "double data type [C++], summary of types", "long long keyword [C++]", "long double keyword [C++]", "unsigned types [C++]", "signed types [C++]", "void keyword [C++]", "storage [C++], basic type", "integral types, C++", "wchar_t keyword [C++]", "floating-point numbers [C++], C++ data types", "long keyword [C++]", "type specifiers [C++]", "integral types", "long keyword [C++]", "storing types [C++]", "data types [C++], void"]
ms.assetid: 58b0106a-0406-4b74-a430-7cbd315c0f89
---
# Built-in types (C++)

Yerleşik türler (*fundamental types* olarak da adlandırılır) C++ dil standardı tarafından belirtilir ve derleyicide yerleşiktir. Yerleşik türler hiçbir başlık dosyasında tanımlanmamıştır. Yerleşik türler üç ana kategoriye ayrılır: *integral*, *floating-point* ve *void*. Integral türleri tam sayıları temsil eder. Floating-point türleri, kesirli parçalara sahip olabilecek değerleri belirtebilir. Çoğu yerleşik tür, derleyici tarafından farklı türler olarak değerlendirilir. Ancak, bazı türler eşanlamlıdır veya derleyici tarafından eşdeğer türler olarak değerlendirilir.

## Void type

[`void`](void-cpp.md) Tip değerlerin boş kümesini tanımlamaktadır. Hiçbir tür değişken **`void`** belirtilemez. **`void`** Tip hiçbir değer döndürmek işlevi bildirmek için veya türsüz veya keyfi olarak yazılan veriler genel olarak açıklanmaktadır ilan etmek öncelikle kullanılır. Herhangi bir ifade açıkça dönüştürülebilir veya type'a dönüştürülebilir **`void`**. Ancak, bu tür ifadeler aşağıdaki kullanımlarla sınırlıdır:

- Bir ifade ifadesi. ( Daha fazla bilgi için, bkz. [Expressions](expressions-cpp.md) )

- Virgül operatörünün sol işleneni. ( Daha fazla bilgi için bkz. [Comma Operator](comma-operator.md) )

- Koşul operatörünün (`? :`) ikinci veya üçüncü işleneni. ( Daha fazla bilgi için bkz. [Expressions with the Conditional Operator](conditional-operator-q.md) )

## std::nullptr_t

Anahtar sözcük **`nullptr`**, `std::nullptr_t` herhangi bir ham işaretçi türüne dönüştürülebilen , türünde bir boş işaretçi sabitidir . Daha fazla bilgi için bkz [`nullptr`](nullptr.md).

## Boolean type

[`bool`](bool-cpp.md) Tip değerlere sahip olabilir [`true`](true-cpp.md) ve [`false`](false-cpp.md). Türün boyutu **`bool`** uygulamaya özeldir. Microsoft'a özgü uygulama ayrıntıları için [Sizes of built-in types](#sizes-of-built-in-types) bakın.

## Character types
> Düzeltme Gerekli

**`char`** Türü etkin bir temel uygulama karakter kümesinin üyeleri kodlayan bir karakter gösterimi türüdür. Çeşidi C ++ derleyici davranır değişkenler **`char`**, **`signed char`** ve **`unsigned char`** farklı türde olan.

**Microsoft-specific**: Derleme seçeneği kullanılmadığı sürece, tür değişkenleri varsayılan olarak türden türe **`char`** yükseltilir. Bu durumda, tür olarak kabul edilirler ve işaret uzantısı olmadan terfi ettirilirler.int **`signed char`** [`/J`](../build/reference/j-default-char-type-is-unsigned.md) **`unsigned char`** **`int`**

Bir tür değişkeni, **`wchar_t`** geniş karakterli veya çok baytlı bir karakter türüdür. **`L`** Geniş karakter türünü belirtmek için bir karakterden veya dize değişmez değerinden önceki öneki kullanın.

**Microsoft-specific**: Varsayılan olarak, **`wchar_t`** yerel bir türdür, ancak için typedef [`/Zc:wchar_t-`](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) yapmak **`wchar_t`** için kullanabilirsiniz **`unsigned short`**. **`__wchar_t`** Tip yerli bir Microsoft özgü eşanlamlısıdır wchar_ttürü.

**`char8_t`** Tipi UTF-8 karakter gösterimi için kullanılır. İle aynı temsile sahiptir **`unsigned char`**, ancak derleyici tarafından ayrı bir tür olarak kabul edilir. **`char8_t`** Tip 20 C ++ yenidir. **Microsoft-specific**: kullanımı derleyici seçeneğini **`char8_t`** gerektirir [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md).

**`char16_t`** Tipi UTF-16 karakter gösterimi için kullanılır. Herhangi bir UTF-16 kod birimini temsil edecek kadar büyük olmalıdır. Derleyici tarafından ayrı bir tür olarak kabul edilir.

**`char32_t`** Tipi UTF-32 karakter gösterimi için kullanılır. Herhangi bir UTF-32 kod birimini temsil edecek kadar büyük olmalıdır. Derleyici tarafından ayrı bir tür olarak kabul edilir.

## Floating-point types

Kayan nokta türleri, çok çeşitli büyüklüklerde kesirli değerlerin yaklaşıklığını sağlamak için bir IEEE-754 gösterimi kullanır. Aşağıdaki tabloda, C++'daki kayan nokta türleri ve kayan nokta türü boyutlarındaki karşılaştırmalı kısıtlamalar listelenmektedir. Bu kısıtlamalar, C++ standardı tarafından zorunlu kılınmıştır ve Microsoft uygulamasından bağımsızdır. Yerleşik kayan nokta türlerinin mutlak boyutu standartta belirtilmemiştir.

| Type | Contents |
|--|--|
| **`float`** | Type **`float`**, C++'daki en küçük kayan nokta türüdür. |
| **`double`** | Tür **`double`**, türe eşit veya daha büyük **`float`**, ancak türün boyutuna eşit veya daha kısa olan bir kayan nokta türüdür **`long double`**. |
| **`long double`** | Type **`long double`**, type 'dan büyük veya eşit olan bir kayan nokta türüdür **`double`**. |

**Microsoft-specific**: Temsil **`long double`** eve **`double`** aynıdır. Ancak **`long double`** ve **`double`** derleyici tarafından farklı türler olarak kabul edilir. Microsoft C++ derleyicisi, 4 ve 8 baytlık IEEE-754 kayan nokta temsillerini kullanır. Daha fazla bilgi için bkz. [IEEE floating-point representation](../build/ieee-floating-point-representation.md).

## Integer types

**`int`** Tipi, varsayılan temel tamsayı türüdür. Uygulamaya özel bir aralıktaki tüm sayıları temsil edebilir.

Bir imzalı tamsayı temsil pozitif ve negatif değerler hem tutabilir biridir. Varsayılan olarak veya signeddeğiştirici anahtar sözcüğü mevcut olduğunda kullanılır . unsignedDeğiştirici anahtar kelime belirtir bir imzasız sadece negatif olmayan değerler tutabilir gösterimi.

Boyut değiştirici, kullanılan tamsayı gösteriminin bit cinsinden genişliğini belirtir. Dil short, long, ve long longdeğiştiricileri destekler . Bir shorttür en az 16 bit genişliğinde olmalıdır. Bir longtür en az 32 bit genişliğinde olmalıdır. Bir long longtür en az 64 bit genişliğinde olmalıdır. Standart, integral türleri arasında bir boyut ilişkisi belirtir:

`1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)`

Bir uygulama, her tür için hem minimum boyut gereksinimlerini hem de boyut ilişkisini sağlamalıdır. Ancak, gerçek boyutlar uygulamalar arasında değişebilir ve değişebilir. Microsoft'a özgü uygulama ayrıntıları için Yerleşik türlerin boyutlarına bakın .

**`int`** Anahtar sözcük ihmal edilebilir **`signed`**, **`unsigned`** veya boyuta tadil belirtilmektedir. Değiştiriciler ve **`int`** varsa tür, herhangi bir sırada görünebilir. Örneğin, **`short unsigned`** ve **`unsigned int short`** aynı türe bakın.

### Integer type synonyms

Aşağıdaki tür grupları derleyici tarafından eş anlamlı olarak kabul edilir:

- **`short`**, **`short int`**, **`signed short`**, **`signed short int`**

- **`unsigned short`**, **`unsigned short int`**

- **`int`**, **`signed`**, **`signed int`**

- **`unsigned`**, **`unsigned int`**

- **`long`**, **`long int`**, **`signed long`**, **`signed long int`**

- **`unsigned long`**, **`unsigned long int`**

- **`long long`**, **`long long int`**, **`signed long long`**, **`signed long long int`**

- **`unsigned long long`**, **`unsigned long long int`**

**Microsoft-specific** türleri tam sayı belirli bir genişliği vardır **`__int8`**, **`__int16`**, **`__int32`** ve **`__int64`** türleri. Bu türler **`signed`** ve **`unsigned`** değiştiricileri kullanabilir . **`__int8`** Veri türü türü ile eş anlamlıdır **`char`**, **`__int16`** türü ile eş anlamlıdır **`short`**, **`__int32`** türü ile eşanlamlıdır **`char`** ve **`__int64`** türü ile eş anlamlıdır **`long long`**.

## Sizes of built-in types

Çoğu yerleşik tür, uygulama tanımlı boyutlara sahiptir. Aşağıdaki tablo, Microsoft C++'daki yerleşik türler için gereken depolama miktarını listeler. Özellikle **`long`** 64 bit işletim sistemlerinde bile 4 bayttır.

| Type | Size |
|--|--|
| **`bool`**, **`char`**, **`char8_t`**, **`unsigned char`**, **`signed char`**, **`__int8`** | 1 byte |
| **`char16_t`**, **`__int16`**, **`short`**, **`unsigned short`**, **`wchar_t`**, **`__wchar_t`** | 2 bytes |
| **`char32_t`**, **`float`**, **`__int32`**, **`int`**, **`unsigned int`**, **`long`**, **`unsigned long`** | 4 bytes |
| **`double`**, **`__int64`**, **`long double`**, **`long long`**, **`unsigned long long`** | 8 bytes |

See [Data type ranges](data-type-ranges.md) for a summary of the range of values of each type.

For more information about type conversion, see [Standard conversions](standard-conversions.md).

## See also

[Data type ranges](data-type-ranges.md)
