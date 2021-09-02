---
description: "Learn more about: nullptr"
title: "nullptr"
ms.date: 07/22/2020
f1_keywords: ["nullptr_cpp"]
helpviewer_keywords: ["nullptr keyword [C++]"]
ms.assetid: e9d80ea6-2506-4eb5-b47b-2349df085832
---
# nullptr

**`nullptr`** Anahtar tipi bir boş gösterici sabit belirten `std::nullptr_t` herhangi bir ham işaretçi türü dönüştürülebilen. Anahtar kelimeyi **`nullptr`** herhangi bir başlık eklemeden kullanabilmenize rağmen , kodunuz type kullanıyorsa, `std::nullptr_t` bunu başlık ekleyerek tanımlamanız gerekir `<cstddef>`.

> [!NOTE]
> **`nullptr`** Anahtar kelime de yönetilen kod uygulamaları için C++/CLI tanımlanan ve ISO Standardı C++ anahtar kelime ile değiştirilebilir değildir. [`/clr`](../build/reference/clr-common-language-runtime-compilation.md) Kodunuz, yönetilen kodu hedefleyen derleyici seçeneği kullanılarak derlenebiliyorsa `__nullptr`, derleyicinin yerel C++ yorumunu kullandığını garanti etmeniz gereken herhangi bir kod satırında kullanın. Daha fazla bilgi için bkz. [`nullptr` (C++/CLI and C++/CX)](../extensions/nullptr-cpp-component-extensions.md).

## Remarks

Avoid using `NULL` or zero (`0`) as a null pointer constant; **`nullptr`** is less vulnerable to misuse and works better in most situations.  For example, given `func(std::pair<const char *, double>)`, then calling `func(std::make_pair(NULL, 3.14))` causes a compiler error.  The macro `NULL` expands to `0`, so that the call `std::make_pair(0, 3.14)` returns `std::pair<int, double>`, which isn't convertible to the `std::pair<const char *, double>` parameter type in `func`.  Calling `func(std::make_pair(nullptr, 3.14))` successfully compiles because `std::make_pair(nullptr, 3.14)` returns `std::pair<std::nullptr_t, double>`, which is convertible to `std::pair<const char *, double>`.

## See also

[Keywords](../cpp/keywords-cpp.md)<br/>
[`nullptr` (C++/CLI and C++/CX)](../extensions/nullptr-cpp-component-extensions.md)
