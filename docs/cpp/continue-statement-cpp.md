---
description: "Learn more about: continue Statement (C++)"
title: "continue Statement (C++)"
ms.date: "11/04/2016"
f1_keywords: ["continue_cpp"]
helpviewer_keywords: ["continue keyword [C++]"]
ms.assetid: 3c94ee57-f732-4c1d-8537-d0ce5382bfd4
---
# continue Statement (C++)

Kontrolün, çevreleyen en küçük do, for veya while döngüsünün kontrol ifadesine aktarılmasını zorlar .

## Syntax

```
continue;
```

## Remarks

Geçerli yinelemede kalan deyimler yürütülmez. Döngünün bir sonraki yinelemesi şu şekilde belirlenir:

Bir **`do`** veya **`while`** döngüsünde, sonraki yineleme, **`do`** veya **`while`** ifadesinin kontrol eden ifadesini yeniden değerlendirerek başlar .

Bir **`for`** döngüde (sözdizimi kullanılarak `for( <init-expr> ; <cond-expr> ; <loop-expr> )`), `<loop-expr>` yan tümce yürütülür. Daha sonra `<cond-expr>` tümce yeniden değerlendirilir ve sonuca bağlı olarak döngü ya biter ya da başka bir yineleme gerçekleşir.

Aşağıdaki örnek, **`continue`** deyimin kod bölümlerini atlamak ve bir döngünün sonraki yinelemesine başlamak için nasıl kullanılabileceğini gösterir.

## Example

```cpp
// continue_statement.cpp
#include <stdio.h>
int main()
{
    int i = 0;
    do
    {
        i++;
        printf_s("before the continue\n");
        continue;
        printf("after the continue, should never print\n");
     } while (i < 3);

     printf_s("after the do loop\n");
}
```

```Output
before the continue
before the continue
before the continue
after the do loop
```

## See also

[Jump Statements](../cpp/jump-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)
