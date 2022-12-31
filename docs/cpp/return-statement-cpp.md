---
description: "Learn more about: return Statement (C++)"
title: "return Statement (C++)"
ms.date: "11/04/2016"
f1_keywords: ["return_cpp"]
helpviewer_keywords: ["return keyword [C++], syntax", "return keyword [C++]"]
ms.assetid: a498903a-056a-4df0-a6cf-72f633a62210
---
# return Statement (C++)

Bir işlevin yürütülmesini sonlandırır ve kontrolü çağıran işleve (veya işlevi işlevden kontrol aktarırsanız işletim sistemine) döndürür `main`. Yürütme, çağrının hemen ardından çağrı işlevinde devam eder.

## Syntax

```
return [expression];
```

## Remarks

`expression` Bir başlatma gerçekleştirilen sanki maddesi, mevcut ise, fonksiyon bir beyanda belirtilen türüne dönüştürülür. İfade returntüründen işlev türüne dönüştürme, geçici nesneler oluşturabilir. Geçicilerin nasıl ve ne zaman oluşturulduğu hakkında daha fazla bilgi için bkz. Geçici Nesneler .

Yan `expression` tümcenin değeri, çağıran işleve döndürülür. İfade atlanırsa, işlevin dönüş değeri tanımsızdır. Yapıcılar ve yıkıcılar ve türdeki işlevler, **`void`** ifadede bir ifade belirtemez **`return`**. Diğer tüm türlerdeki işlevler, ifadede bir ifade belirtmelidir **`return`**.

Kontrol akışı, fonksiyon tanımını içeren bloktan çıktığında, sonuç, **`return`** ifadesi olmayan bir ifadenin yürütülmüş olmasıyla aynıdır. Bu, bir değer döndürdüğü bildirilen işlevler için geçersizdir.

Bir fonksiyon herhangi bir sayıda **`return`** ifadeye sahip olabilir .

Aşağıdaki örnek **`return`**, iki tamsayıdan en büyüğünü elde etmek için bir ifade içeren bir ifade kullanır .

## Example

```cpp
// return_statement2.cpp
#include <stdio.h>

int max ( int a, int b )
{
   return ( a > b ? a : b );
}

int main()
{
    int nOne = 5;
    int nTwo = 7;

    printf_s("\n%d is bigger\n", max( nOne, nTwo ));
}
```

## See also

[Jump Statements](../cpp/jump-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)
