---
title: "switch statement (C++)"
description: "Reference to the Standard C++ switch statement in Microsoft Visual Studio C++."
ms.date: "04/25/2020"
f1_keywords: ["default_cpp", "switch_cpp", "case_cpp"]
helpviewer_keywords: ["switch keyword [C++]", "case keyword [C++], in switch statements", "default keyword [C++]"]
no-loc: [switch, case, default, break, while, opt]
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
---
# `switch` statement (C++)

Allows selection among multiple sections of code, depending on the value of an integral expression.

## Syntax

> *`selection-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; **`switch`**&nbsp;**`(`**&nbsp;*`init-statement`*<sub>opt</sub><sup>C++17</sup>&nbsp;*`condition`*&nbsp;**`)`**&nbsp;*`statement`*

> *`init-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; *`expression-statement`*\
> &nbsp;&nbsp;&nbsp;&nbsp; *`simple-declaration`*

> *`condition`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; *`expression`*\
> &nbsp;&nbsp;&nbsp;&nbsp; *`attribute-specifier-seq`*<sub>opt</sub>&nbsp;*`decl-specifier-seq`*&nbsp;*`declarator`*&nbsp;*`brace-or-equal-initializer`*

> *`labeled-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; **`case`**&nbsp;*`constant-expression`*&nbsp;**`:`**&nbsp;*`statement`*\
> &nbsp;&nbsp;&nbsp;&nbsp; **`default`**&nbsp;**`:`**&nbsp;*`statement`*

## Remarks

Bir **`switch`** deyim *`labeled-statement`*, değerine bağlı olarak, kontrolün deyim gövdesindeki birine aktarılmasına neden olur *`condition`*.

*`condition`* Tamamlayıcı tip veya entegre tip açık bir dönüşüm vardır, bir sınıf tipi olmalıdır. Entegre promosyon, Standart dönüşümlerde açıklandığı gibi gerçekleşir .

Bildirim **`switch`** gövdesi, bir dizi **`case`**etiketten ve isteğe bağlı bir **`default`** etiketten oluşur. A *`labeled-statement`*, bu etiketlerden ve takip eden ifadelerden biridir. Etiketli ifadeler sözdizimsel gereklilikler değildir, ancak **`switch`** ifade onlarsız anlamsızdır. İfadelerdeki iki *`constant-expression`* değer **`case`** aynı değeri değerlendiremez. **`default`** Etiket sadece bir kez görünebilir. **`default`** İfadesi sıklıkla sonunda yerleştirilir, ancak herhangi bir yerde geçebilir **`switch`** deyim vücuda. A **`case`** veya **`default`** etiketi yalnızca bir **`switch`** ifadenin içinde görünebilir .

*`constant-expression`* Her **`case`** bir etiket ile aynı tipte olan bir sabit değere dönüştürülür *`condition`*. Daha sonra, *`condition`* eşitlik için ile karşılaştırılır . Kontrol, değeriyle eşleşen değerden sonraki ilk ifadeye geçer . Ortaya çıkan davranış aşağıdaki tabloda gösterilmektedir.**`case`** *`constant-expression`* *`condition`* 

### `switch` statement behavior

| Durum | Action |
|--|--|
| Dönüştürülen değer, yükseltilmiş denetim ifadesinin değeriyle eşleşir. | Kontrol, bu etiketi takip eden ifadeye aktarılır. |
| Sabitlerin hiçbiri **`case`** etiketlerdeki sabitlerle eşleşmez ; bir **`default`** etiket mevcuttur. | Control is transferred to the **`default`** label. |
| Sabitlerin hiçbiri **`case`** etiketlerdeki sabitlerle eşleşmez ; Hiçbir **`default`** etiket mevcuttur. | Kontrol, ekstreden sonra ekstreye aktarılır **`switch`**. |

Eşleşen bir ifade bulunursa, yürütme daha sonra **`case`** veya **`default`** etiketler aracılığıyla devam edebilir. [`break`](../cpp/break-statement-cpp.md) İfadesi sonrası yapılan açıklamaya yürütme ve transfer kontrolünü durdurmak için kullanılır **`switch`** açıklamada. İfade olmadan **`break`** , eşleşen **`case`** etiketten sonuna kadar olan her ifade, **`switch`**, dahil olmak üzere **`default`** yürütülür. Örneğin:

```cpp
// switch_statement1.cpp
#include <stdio.h>

int main() {
   const char *buffer = "Any character stream";
   int uppercase_A, lowercase_a, other;
   char c;
   uppercase_A = lowercase_a = other = 0;

   while ( c = *buffer++ )   // Walks buffer until NULL
   {
      switch ( c )
      {
         case 'A':
            uppercase_A++;
            break;
         case 'a':
            lowercase_a++;
            break;
         default:
            other++;
      }
   }
   printf_s( "\nUppercase A: %d\nLowercase a: %d\nTotal: %d\n",
      uppercase_A, lowercase_a, (uppercase_A + lowercase_a + other) );
}
```

In the above example, `uppercase_A` is incremented if `c` is an uppercase `'A'`. The **`break`** statement after `uppercase_A++` terminates execution of the **`switch`** statement body and control passes to the **`while`** loop. Without the **`break`** statement, execution would "fall through" to the next labeled statement, so that `lowercase_a` and `other` would also be incremented. A similar purpose is served by the **`break`** statement for `case 'a'`. If `c` is a lowercase `'a'`, `lowercase_a` is incremented and the **`break`** statement terminates the **`switch`** statement body. If `c` isn't an `'a'` or `'A'`, the **`default`** statement is executed. 

**Visual Studio 2017 and later:** ve sonrası: ( [/std:c++17](../build/reference/std-specify-language-standard-version.md) ile kullanılabilir ) `[[fallthrough]]` Öznitelik, C++17 standardında belirtilir. Bir **`switch`** açıklamada kullanabilirsiniz . Derleyiciye veya kodu okuyan herhangi birine, düşme davranışının kasıtlı olduğuna dair bir ipucu. Microsoft C++ derleyicisi şu anda hata davranışı konusunda uyarmadığından, bu özniteliğin derleyici davranışı üzerinde hiçbir etkisi yoktur. Örnekte, öznitelik, sonlandırılmamış etiketli ifade içindeki boş bir ifadeye uygulanır. Başka bir deyişle, noktalı virgül gereklidir.

```cpp
int main()
{
    int n = 5;
    switch (n)
    {

    case 1:
        a();
        break;
    case 2:
        b();
        d();
        [[fallthrough]]; // I meant to do this!
    case 3:
        c();
        break;
    default:
        d();
        break;
    }

    return 0;
}
```

**Visual Studio 2017 version 15.3 and later** ( [/std:c++17](../build/reference/std-specify-language-standard-version.md) ile kullanılabilir ). Bir **`switch`** ifadenin *`init-statement`* noktalı virgülle biten bir yan tümcesi olabilir . Kapsamı **`switch`** ifadenin bloğuyla sınırlı olan bir değişkeni tanıtır ve başlatır :

```cpp
    switch (Gadget gadget(args); auto s = gadget.get_status())
    {
    case status::good:
        gadget.zip();
        break;
    case status::bad:
        throw BadGadget();
    };
```

Bir **`switch`** ifadenin iç bloğu, erişilebilir oldukları , yani tüm olası yürütme yolları tarafından atlanmadıkları sürece başlatıcılara sahip tanımlar içerebilir . Bu bildirimler kullanılarak tanıtılan adların yerel kapsamı vardır. Örneğin:

```cpp
// switch_statement2.cpp
// C2360 expected
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    switch( tolower( *argv[1] ) )
    {
        // Error. Unreachable declaration.
        char szChEntered[] = "Character entered was: ";

    case 'a' :
        {
        // Declaration of szChEntered OK. Local scope.
        char szChEntered[] = "Character entered was: ";
        cout << szChEntered << "a\n";
        }
        break;

    case 'b' :
        // Value of szChEntered undefined.
        cout << szChEntered << "b\n";
        break;

    default:
        // Value of szChEntered undefined.
        cout << szChEntered << "neither a nor b\n";
        break;
    }
}
```

Bir **`switch`** deyim yuvalanabilir. İç içe yerleştirildiğinde **`case`** veya **`default`** etiketleri, **`switch`** onları çevreleyen en yakın ifadeyle ilişkilendirilir .

### Microsoft-specific behavior

Microsoft C++ doesn't limit the number of **`case`** values in a **`switch`** statement. The number is limited only by the available memory.

## See also

[Selection Statements](../cpp/selection-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)
