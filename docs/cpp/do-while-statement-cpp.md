---
description: "Learn more about: do-while Statement (C++)"
title: "do-while Statement (C++)"
ms.date: "11/04/2016"
f1_keywords: ["do_cpp"]
helpviewer_keywords: ["do keyword [C++], do-while", "do-while keyword [C++]", "do keyword [C++]", "while keyword [C++], do-while"]
ms.assetid: e01e6f7c-7da1-4591-87f9-c26ff848e7b0
---
# do-while Statement (C++)

Belirtilen sonlandırma koşulu ( *expression* ) sıfır olarak değerlendirilene kadar bir deyimi tekrar tekrar yürütür.

## Syntax

```
do
   statement
while ( expression ) ;
```

## Remarks

Sonlandırma koşulunun testi, döngünün her yürütülmesinden sonra yapılır; bu nedenle, bir **do-while** döngüsü, sonlandırma ifadesinin değerine bağlı olarak bir veya daha fazla kez yürütülür. **do-while** bir zaman ifadesi de kesebilirler [break](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md), yada [return](../cpp/return-statement-cpp.md) ifadesi deyimi bünyesinde yürütülür.

İfade aritmetik veya işaretçi türü olmalıdır. Yürütme şu şekilde ilerler:

- İfade gövdesi yürütülür.

- Daha sonra ifade (*expression*) değerlendirilir. Eğer ifade yanlıştır, **do-while** deyimi sonlandığı ve kontrol programının bir sonraki ifadeye geçer. Eğer ekspresyon (sıfır olmayan) doğru, işlem adım 1'ile başlayan, tekrar edilir.

## Example

The following sample demonstrates the **do-while** statement:

```cpp
// do_while_statement.cpp
#include <stdio.h>
int main()
{
    int i = 0;
    do
    {
        printf_s("\n%d",i++);
    } while (i < 3);
}
```

## See also

[Iteration Statements](../cpp/iteration-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)<br/>
[while Statement (C++)](../cpp/while-statement-cpp.md)<br/>
[for Statement (C++)](../cpp/for-statement-cpp.md)<br/>
[Range-based for Statement (C++)](../cpp/range-based-for-statement-cpp.md)
