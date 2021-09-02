---
description: "Learn more about: goto Statement (C++)"
title: "goto Statement (C++)"
ms.date: "11/04/2016"
f1_keywords: ["goto_cpp"]
helpviewer_keywords: ["goto keyword [C++]"]
ms.assetid: 724c5deb-2de1-42d8-8ef1-23589d9bf5ed
---
# goto Statement (C++)

**`goto`** İfadesi koşulsuz belirtilen tanımlayıcı tarafından etiketli açıklamaya kontrolünü aktarır.İfadesi koşulsuz belirtilen tanımlayıcı tarafından etiketli açıklamaya kontrolünü aktarır.

## Syntax

```
goto identifier;
```

## Remarks

tarafından belirtilen etiketli ifade `identifier`, geçerli işlevde olmalıdır. Tüm `identifier` adlar dahili bir ad alanının üyeleridir ve bu nedenle diğer tanımlayıcılarla etkileşime girmez.

Bir deyim etiketi yalnızca bir **`goto`** deyim için anlamlıdır ; aksi takdirde, ifade etiketleri yoksayılır. Etiketler yeniden bildirilemez.

Bir **`goto`** ifadenin, o konumdaki kapsamdaki herhangi bir değişkenin başlatılmasını atlayan bir konuma denetimi aktarmasına izin verilmez. Aşağıdaki örnek, C2362'yi yükseltir:

```cpp
int goto_fn(bool b)
{
    if (!b)
    {
        goto exit;  // C2362
    }
    else
    { /*...*/ }

    int error_code = 42;

exit:
    return error_code;
}
```

İyi programlama kullanmak tarzıdır **`break`**, **`continue`**, and **`return`** yerine ifadeleri **`goto`** her açıklamada mümkün. Ancak, **`break`** ifade bir döngünün yalnızca bir düzeyinden **`goto`** çıktığı için, derinlemesine iç içe geçmiş bir döngüden çıkmak için bir ifade kullanmanız gerekebilir .

Etiketler ve **`goto`** ifade hakkında daha fazla bilgi için bkz. [Labeled Statements](../cpp/labeled-statements.md).

## Example

Bu örnekte, bir **`goto`** ifade , kontrolü 3'e eşit `stop` olduğunda etiketlenen noktaya aktarır `i`.

```cpp
// goto_statement.cpp
#include <stdio.h>
int main()
{
    int i, j;

    for ( i = 0; i < 10; i++ )
    {
        printf_s( "Outer loop executing. i = %d\n", i );
        for ( j = 0; j < 2; j++ )
        {
            printf_s( " Inner loop executing. j = %d\n", j );
            if ( i == 3 )
                goto stop;
        }
    }

    // This message does not print:
    printf_s( "Loop exited. i = %d\n", i );

    stop:
    printf_s( "Jumped to stop. i = %d\n", i );
}
```

```Output
Outer loop executing. i = 0
Inner loop executing. j = 0
Inner loop executing. j = 1
Outer loop executing. i = 1
Inner loop executing. j = 0
Inner loop executing. j = 1
Outer loop executing. i = 2
Inner loop executing. j = 0
Inner loop executing. j = 1
Outer loop executing. i = 3
Inner loop executing. j = 0
Jumped to stop. i = 3
```

## See also

[Jump Statements](../cpp/jump-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)
