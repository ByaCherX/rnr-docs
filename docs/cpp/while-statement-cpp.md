---
description: "Learn more about: while Statement (C++)"
title: "while Statement (C++)"
ms.date: "11/04/2016"
f1_keywords: ["while_cpp"]
helpviewer_keywords: ["while keyword [C++]", "while keyword [C++], syntax"]
ms.assetid: 358dbe76-5e5e-4af5-b575-c2293c636899
---
# while Statement (C++)

Executes *statement* repeatedly until *expression* evaluates to zero.

## Syntax

```
while ( expression )
   statement
```

## Remarks

İfade testi , döngünün her yürütülmesinden önce gerçekleşir; bu nedenle, bir **`while`** döngü sıfır veya daha fazla kez yürütülür. ifade bir integral türünde, bir işaretçi türünde veya bir integral veya işaretçi türüne açık bir dönüşüme sahip bir sınıf türünde olmalıdır.

Bir **`while`** döngü, ifade gövdesi içinde bir `break`, `goto` veya `return` çalıştırıldığında da sonlandırılabilir. Döngüden çıkmadan geçerli yinelemeyi sonlandırmak için devam et seçeneğini kullanın **`while`**. **`continue`** kontrolü **`while`** döngünün bir sonraki yinelemesine geçirir .

Aşağıdaki kod **`while`**, bir dizeden sondaki alt çizgileri kırpmak için bir döngü kullanır:

```cpp
// while_statement.cpp

#include <string.h>
#include <stdio.h>
char *trim( char *szSource )
{
    char *pszEOS = 0;

    //  Set pointer to character before terminating NULL
    pszEOS = szSource + strlen( szSource ) - 1;

    //  iterate backwards until non '_' is found
    while( (pszEOS >= szSource) && (*pszEOS == '_') )
        *pszEOS-- = '\0';

    return szSource;
}
int main()
{
    char szbuf[] = "12345_____";

    printf_s("\nBefore trim: %s", szbuf);
    printf_s("\nAfter trim: %s\n", trim(szbuf));
}
```

Sonlandırma koşulu, döngünün en üstünde değerlendirilir. Sonda alt çizgi yoksa, döngü hiçbir zaman yürütülmez.

## See also

[Iteration Statements](../cpp/iteration-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)<br/>
[do-while Statement (C++)](../cpp/do-while-statement-cpp.md)<br/>
[for Statement (C++)](../cpp/for-statement-cpp.md)<br/>
[Range-based for Statement (C++)](../cpp/range-based-for-statement-cpp.md)
