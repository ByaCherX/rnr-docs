---
title: "if-else statement (C++)"
description: "Use if-else, if-else with initializer, and if-constexpr statements to control conditional branching."
ms.date: 10/02/2020
f1_keywords: ["else_cpp", "if_cpp"]
helpviewer_keywords: ["if keyword [C++]", "else keyword [C++]"]
ms.assetid: f8c45cde-6bce-42ae-81db-426b3dbd4caa
---
# if-else statement (C++)

Bir if-else ifadesi koşullu dallanmayı kontrol eder. içindeki ifadeler, *`if-branch`* yalnızca *`condition`* sıfırdan farklı bir değer (veya **`true`**) olarak değerlendirilirse yürütülür . Değeri *`condition`* sıfır değilse, aşağıdaki ifade yürütülür ve isteğe bağlı ifadeyi izleyen ifade **`else`** atlanır. Aksi takdirde, aşağıdaki deyim Atlanan alır ve bir varsa **`else`** aşağıdaki komutla elseçalıştırılmaktadır.

*`condition`* expressions that evaluate to non-zero are:

- **`true`**
- boş olmayan bir işaretçi (pointer)
- sıfır olmayan herhangi bir aritmetik değer veya
- aritmetik, boole veya işaretçi türüne açık bir dönüştürmeyi tanımlayan bir sınıf türü. (Dönüşümler hakkında bilgi için bkz.  [Standard Conversions](../cpp/standard-conversions.md).)

## Syntax

*`init-statement`*:\
&emsp; *`expression-statement`*\
&emsp; *`simple-declaration`*

*`condition`*:\
&emsp; *`expression`*\
&emsp; *`attribute-specifier-seq`*<sub>*opt*</sub> *`decl-specifier-seq`* *`declarator`* *`brace-or-equal-initializer`*

*`statement`*:\
&emsp; *`expression-statement`*\
&emsp; *`compound-statement`*

*`expression-statement`*:\
&emsp; *`expression`*<sub>*opt*</sub> **`;`**

*`compound-statement`*:\
&emsp; **`{`** *`statement-seq`*<sub>*opt*</sub> **`}`**

*`statement-seq`*:\
&emsp; *`statement`*\
&emsp; *`statement-seq`* *`statement`*

*`if-branch`*:\
&emsp; *`statement`*

*`else-branch`*:\
&emsp; *`statement`*

*`selection-statement`*:\
&emsp; **`if`** **`constexpr`**<sub>*opt*</sub><sup>17</sup> **`(`** *`init-statement`*<sub>*opt*</sub><sup>17</sup> *`condition`* **`)`** *`if-branch`*\
&emsp; **`if`** **`constexpr`**<sub>*opt*</sub><sup>17</sup> **`(`** *`init-statement`*<sub>*opt*</sub><sup>17</sup> *`condition`* **`)`** *`if-branch`* **`else`** *`else-branch`*

<sup>17</sup> This optional element is available starting in C++17.

## if-else statements

Bir yapı dışında herhangi bir değere sahip olabilen **`if`** ifadenin tüm formlarında, *`condition`* tüm yan etkileri de dahil olmak üzere değerlendirilir. **`if`** Yürütülen *`if-branch`* or *`else-branch`* bir[`break`](../cpp/break-statement-cpp.md), [`continue`](../cpp/continue-statement-cpp.md), veya içermediği sürece kontrol, deyimden programdaki bir sonraki deyime geçer [`goto`](../cpp/goto-statement-cpp.md).

**`else`** Bir fıkrasının `if...else` deyimi en yakın önceki ile ilişkili **`if`** karşılık gelen yok aynı kapsamda açıklamada **`else`** deyimi.

### Example

This sample code shows several **`if`** statements in use, both with and without **`else`**:

```cpp
// if_else_statement.cpp
#include <iostream>

using namespace std;

class C
{
    public:
    void do_something(){}
};
void init(C){}
bool is_true() { return true; }
int x = 10;

int main()
{
    if (is_true())
    {
        cout << "b is true!\n";  // executed
    }
    else
    {
        cout << "b is false!\n";
    }

    // no else statement
    if (x == 10)
    {
        x = 0;
    }

    C* c;
    init(c);
    if (c)
    {
        c->do_something();
    }
    else
    {
        cout << "c is null!\n";
    }
}
```

## <a name="if_with_init"></a> if statement with an initializer

C++17'den başlayarak, **`if`** bir *`init-statement`* ifade, adlandırılmış bir değişkeni bildiren ve başlatan bir ifade de içerebilir. Değişkene yalnızca if-ifadesi kapsamında ihtiyaç duyulduğunda if-ifadesinin bu formunu kullanın. **Microsoft-specific**: Bu form, Visual Studio 2017 sürüm 15.3'ten itibaren kullanılabilir ve en azından [`/std:c++17`](../build/reference/std-specify-language-standard-version.md) derleyici seçeneği gerektirir.

### Example

```cpp
#include <iostream>
#include <mutex>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<int, string> m;
mutex mx;
bool shared_flag; // guarded by mx
void unsafe_operation() {}

int main()
{

    if (auto it = m.find(10); it != m.end())
    {
        cout << it->second;
        return 0;
    }

    if (char buf[10]; fgets(buf, 10, stdin))
    {
        m[0] += buf;
    }

    if (lock_guard<mutex> lock(mx); shared_flag)
    {
        unsafe_operation();
        shared_flag = false;
    }

    string s{ "if" };
    if (auto keywords = { "if", "for", "while" }; any_of(keywords.begin(), keywords.end(), [&s](const char* kw) { return s == kw; }))
    {
        cout << "Error! Token must not be a keyword\n";
    }
}
```

## <a name="if_constexpr"> if constexpr statements

C++17'den başlayarak, **`if constexpr`** birden çok işlev aşırı yüklemesine başvurmak zorunda kalmadan derleme zamanı dallandırma kararları vermek için işlev şablonlarında bir ifade kullanabilirsiniz . **Microsoft-specific**: Bu form, Visual Studio 2017 sürüm 15.3'ten itibaren kullanılabilir ve en azından [`/std:c++17`](../build/reference/std-specify-language-standard-version.md) derleyici seçeneği gerektirir.

### Example

Bu örnek, parametre paketini açmayı işleyen tek bir işlevi nasıl yazabileceğinizi gösterir. Sıfır parametreli aşırı yük gerekmez:

```cpp
template <class T, class... Rest>
void f(T&& t, Rest&&... r)
{
    // handle t
    do_something(t);

    // handle r conditionally
    if constexpr (sizeof...(r))
    {
        f(r...);
    }
    else
    {
        g(r...);
    }
}
```

## See also

[Selection Statements](../cpp/selection-statements-cpp.md)\
[Keywords](../cpp/keywords-cpp.md)\
[`switch` Statement (C++)](../cpp/switch-statement-cpp.md)
