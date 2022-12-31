---
description: "Learn more about: break Statement (C++)"
title: "break Statement (C++)"
ms.date: "11/04/2016"
f1_keywords: ["break_cpp"]
helpviewer_keywords: ["break keyword [C++]"]
ms.assetid: 63739928-8985-4b05-93ce-016322e6da3d
---
# break Statement (C++)

**`break`** Göründüğü yakın parça döngü veya koşullu tablosunu uçları yürütülmesi. Kontrol, varsa deyimin sonunu takip eden deyime geçer.

## Syntax

```
break;
```

## Remarks

**`break`** Deyim koşullu kullanılır anahtar deyimler switch, do, for ve while döngü ifadeleri içindir.

Bir **`switch`** ifadede, **`break`** ifade, programın bir sonraki ifadeyi ifadenin dışında yürütmesine neden olur **`switch`**. Bir **`break`** deyim olmadan , eşleşen **`case`** etiketten **`switch`** deyimin sonuna kadar tüm deyimler, **`default`** yan tümce de dahil olmak üzere yürütülür.

Döngülerde, **`break`** ifade, en yakın çevreleyen do, for, veya whileifadesinin yürütülmesini sona erdirir . Kontrol, varsa, sona eren ifadeyi takip eden ifadeye geçer.

İç içe ifadeler içinde, **`break`** ifade yalnızca onu hemen çevreleyen **`do`**, **`for`**, **`switch`**, veya **`while`** ifadesini sona erdirir . Daha derin iç içe geçmiş yapılardan denetimi aktarmak için bir **`return`** or **`goto`** deyimi kullanabilirsiniz .

## Example

Aşağıdaki kod, **`break`** ifadenin bir **`for`** döngüde nasıl kullanılacağını gösterir.

```cpp
#include <iostream>
using namespace std;

int main()
{
    // An example of a standard for loop
    for (int i = 1; i < 10; i++)
    {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
    }

    // An example of a range-based for loop
int nums []{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i : nums) {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
    }
}
```

```Output
In each case:
1
2
3
```

The following code shows how to use **`break`** in a **`while`** loop and a **`do`** loop.

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (i < 10) {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
        i++;
    }

    i = 0;
    do {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
        i++;
    } while (i < 10);
}
```

```Output
In each case:
0123
```

Aşağıdaki kod, **`break`** bir switch ifadesinde nasıl kullanılacağını gösterir. **`break`** Her vakayı ayrı ayrı ele almak istiyorsanız her durumda kullanmalısınız; kullanmazsanız **`break`**, kod yürütme sonraki duruma geçer.

```cpp
#include <iostream>
using namespace std;

enum Suit{ Diamonds, Hearts, Clubs, Spades };

int main() {

    Suit hand;
    . . .
    // Assume that some enum value is set for hand
    // In this example, each case is handled separately
    switch (hand)
    {
    case Diamonds:
        cout << "got Diamonds \n";
        break;
    case Hearts:
        cout << "got Hearts \n";
        break;
    case Clubs:
        cout << "got Clubs \n";
        break;
    case Spades:
        cout << "got Spades \n";
        break;
    default:
          cout << "didn't get card \n";
    }
    // In this example, Diamonds and Hearts are handled one way, and
    // Clubs, Spades, and the default value are handled another way
    switch (hand)
    {
    case Diamonds:
    case Hearts:
        cout << "got a red card \n";
        break;
    case Clubs:
    case Spades:
    default:
        cout << "didn't get a red card \n";
    }
}
```

## See also

[Jump Statements](../cpp/jump-statements-cpp.md)<br/>
[Keywords](../cpp/keywords-cpp.md)<br/>
[continue Statement](../cpp/continue-statement-cpp.md)
