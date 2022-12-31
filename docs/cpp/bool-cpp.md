---
description: "Learn more about: bool (C++)"
title: "bool (C++)"
ms.date: "11/04/2016"
f1_keywords: ["bool_cpp", "__BOOL_DEFINED"]
helpviewer_keywords: ["bool keyword [C++]", "__BOOL_DEFINED macro"]
ms.assetid: 9abed3f2-d21c-4eb4-97c5-716342e613d8
---
# bool (C++)

Bu anahtar kelime yerleşik bir türdür. Bu türdeki bir değişken değerlere sahip olabilir true ve false. Koşullu ifadeler type **`bool`** değerine sahiptir ve bu nedenle type değerlerine sahiptir **`bool`**. Örneğin, `i != 0` şimdi **`true`** veya **`false`** değerine bağlı olarak i.

**Visual Studio 2017 version 15.3 and later** ( [/std:c++17](../build/reference/std-specify-language-standard-version.md) ile kullanılabilir ): Bir sonek veya önek artırma veya azaltma operatörünün işleneni türünde olmayabilir **`bool`**. Bir değişken verilen Diğer bir deyişle, `b` Çeşidi **`bool`**, bu ifadeler artık izin verilir:

```cpp
    b++;
    ++b;
    b--;
    --b;
```

The values **`true`** and **`false`** have the following relationship:

```cpp
!false == true
!true == false
```

In the following statement:

```cpp
if (condexpr1) statement1;
```

Eğer `condexpr1` bir **`true`**, `statement1` her zaman çalıştırılır; eğer `condexpr1` olduğunu **`false`**, `statement1` asla çalıştırılmaz.

Bir **`++`** tür değişkenine bir sonek veya önek operatörü uygulandığında **`bool`**, değişken olarak ayarlanır **`true`**.

**Visual Studio 2017 version 15.3 and later**: `operator++` 3for **`bool`** dilden kaldırıldı ve artık desteklenmiyor.

Sonek veya önek **`--`** operatörü bu tür bir değişkene uygulanamaz.

**`bool`** Varsayılan ayrılmaz promosyonlar yazın katılır. Tipte bir r-value **`bool`** tipi bir r-value dönüştürülebilir **`int`** ile, **`false`** sıfır olmak ve **`true`** biri olmuştur. Farklı bir tür **`bool`** olarak aşırı yük çözünürlüğüne katılır.

## See also

[Keywords](../cpp/keywords-cpp.md)<br/>
[Built-in types](../cpp/fundamental-types-cpp.md)
