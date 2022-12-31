---
title: "for statement (C++)"
description: "Reference to the Standard C++ for statement in Microsoft Visual Studio C++."
f1_keywords: ["for_cpp"]
ms.date: 07/31/2020
helpviewer_keywords: ["for keyword [C++]"]
ms.assetid: 6c7d01b3-c4c1-4c6a-aa58-e2d198f33d4a
---
# `for` statement (C++)

Koşul yanlış olana kadar bir ifadeyi tekrar tekrar yürütür. Aralık tabanlı **`for`** deyim hakkında bilgi için bkz. Aralık tabanlı fordeyim (C++) .

## Syntax

> **`for (`** *`init-expression`* **`;`** *`cond-expression`* **`;`** *`loop-expression`* **`)`**\
> &emsp;*`statement`*

## Remarks

**`for`** Belirtilen sayıda yürütmesi gereken döngüler oluşturmak için ifadeyi kullanın .

**`for`** Aşağıdaki tabloda gösterildiği gibi, açıklamada, üç isteğe bağlı bölümden oluşmaktadır.

### for loop elements

| Syntax name | When executed | Description |
|--|--|--|
| *`init-expression`* | Başka element önce **`for`** açıklamada, *`init-expression`* yalnızca bir kez yürütülür. Kontrol daha sonra 'a geçer *`cond-expression`*. | Genellikle döngü indekslerini başlatmak için kullanılır. İfadeler veya bildirimler içerebilir. |
| *`cond-expression`* | *`statement`* İlk yineleme de dahil olmak üzere her yinelemenin yürütülmesinden önce *`statement`* yalnızca *`cond-expression`* true (sıfırdan farklı) olarak değerlendirilirse yürütülür. | Bir integral türünü veya bir integral türüne açık bir dönüşümü olan bir sınıf türünü değerlendiren bir ifade. Normalde döngü sonlandırma kriterlerini test etmek için kullanılır. |
| *`loop-expression`* | Her yinelemenin sonunda *`statement`*. Sonra *`loop-expression`* yürütülür, *`cond-expression`* değerlendirilir. | Normalde döngü indekslerini artırmak için kullanılır. |

Aşağıdaki örnekler, **`for`** ifadeyi kullanmanın farklı yollarını gösterir .

```cpp
#include <iostream>
using namespace std;

int main() {
    // The counter variable can be declared in the init-expression.
    for (int i = 0; i < 2; i++ ){
       cout << i;
    }
    // Output: 01
    // The counter variable can be declared outside the for loop.
    int i;
    for (i = 0; i < 2; i++){
        cout << i;
    }
    // Output: 01
    // These for loops are the equivalent of a while loop.
    i = 0;
    while (i < 2){
        cout << i++;
    }
    // Output: 01
}
```

*`init-expression`* ve *`loop-expression`* virgülle ayrılmış birden çok ifade içerebilir. Örneğin:

```cpp
#include <iostream>
using namespace std;

int main(){
    int i, j;
    for ( i = 5, j = 10 ; i + j < 20; i++, j++ ) {
        cout << "i + j = " << (i + j) << '\n';
    }
}
    // Output:
    i + j = 15
    i + j = 17
    i + j = 19
```

*`loop-expression`* artırılabilir, azaltılabilir veya başka şekillerde değiştirilebilir.

```cpp
#include <iostream>
using namespace std;

int main(){
for (int i = 10; i > 0; i--) {
        cout << i << ' ';
    }
    // Output: 10 9 8 7 6 5 4 3 2 1
    for (int i = 10; i < 20; i = i+2) {
        cout << i << ' ';
    }
    // Output: 10 12 14 16 18
```

Bir **`for`** döngü, içinde bir [`break`](../cpp/break-statement-cpp.md), [`return`](../cpp/return-statement-cpp.md), veya [`goto`](../cpp/goto-statement-cpp.md) ( **`for`** döngünün dışındaki etiketli bir ifadeye ) *`statement`* yürütüldüğünde sona erer . Döngüdeki bir [`continue`](../cpp/continue-statement-cpp.md) ifade **`for`** yalnızca geçerli yinelemeyi sonlandırır.

Eğer *`cond-expression`* atlanırsa, bu kabul edilir **`true`** ve **`for`** döngü bir olmadan sona olmaz **`break`**, **`return`**, or **`goto`** içinde *`statement`*.

İfadenin üç alanı **`for`** normalde başlatma, sonlandırma için test etme ve artırma için kullanılsa da, bunlar bu kullanımlarla sınırlı değildir. Örneğin, aşağıdaki kod 0'dan 4'e kadar olan sayıları yazdırır. Bu durumda, *`statement`* null deyimidir:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int i;
    for( i = 0; i < 5; cout << i << '\n', i++){
        ;
    }
}
```

## `for` loops and the C++ Standard

C++ standardı, bir **`for`** döngüde bildirilen bir değişkenin, **`for`** döngü sona erdikten sonra kapsam dışına çıkacağını söyler. Örneğin:

```cpp
for (int i = 0 ; i < 5 ; i++) {
   // do something
}
// i is now out of scope under /Za or /Zc:forScope
```

Varsayılan olarak, [/Ze](../build/reference/za-ze-disable-language-extensions.md) altında , bir **`for`**döngüde bildirilen bir değişken, **`for`**döngünün kapsamı sona erene kadar kapsamda kalır .

[/Zc:forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md), for döngülerinde bildirilen değişkenlerin standart davranışını belirtmeye gerek kalmadan etkinleştirir /Za.

Aşağıdaki şekilde **`for`** değişkenleri yeniden bildirmek için döngünün kapsam farklarını kullanmak da mümkündür `/Ze`:

```cpp
// for_statement5.cpp
int main(){
   int i = 0;   // hidden by var with same name declared in for loop
   for ( int i = 0 ; i < 3; i++ ) {}

   for ( int i = 0 ; i < 3; i++ ) {}
}
```

Bu davranış, bir **`for`** döngüde bildirilen değişkenlerin **`for`** döngü tamamlandıktan sonra kapsam dışına çıkmasını gerektiren bir döngüde bildirilen bir değişkenin standart davranışını daha yakından taklit eder . Bir **`for`** döngüde bir değişken bildirildiğinde , derleyici onu dahili olarak **`for`** döngünün çevreleyen kapsamındaki yerel bir değişkene yükseltir. Zaten aynı ada sahip yerel bir değişken olsa bile terfi ettirilir.

## See also

[Iteration statements](../cpp/iteration-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)<br/>
[while statement (C++)](../cpp/while-statement-cpp.md)<br/>
[do-while statement (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Range-based for statement (C++)](../cpp/range-based-for-statement-cpp.md)
