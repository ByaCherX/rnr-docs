---
description: "Learn more about: Comments (C++)"
title: "Comments (C++)"
ms.date: "11/04/2016"
helpviewer_keywords: ["code comments, C++", "comments, documenting code", "comments, C++ code", "white space, C++ comments"]
ms.assetid: 6fcb906c-c264-4083-84bc-373800b2e514
---
# Comments (C++)

Yorum, derleyicinin yok saydığı ancak programcılar için yararlı olan metindir. Yorumlar normalde ileride başvurmak üzere koda açıklama eklemek için kullanılır. Derleyici bunları beyaz boşluk olarak değerlendirir. Belirli kod satırlarını devre dışı bırakmak için test sırasında yorumları kullanabilirsiniz; ancak ``#if``/ ``#endif`` önişlemci yönergeleri bunun için daha iyi çalışır çünkü yorumları içeren kodu çevreleyebilirsiniz ancak yorumları iç içe geçiremezsiniz.

Bir C++ yorumu aşağıdaki yollardan biriyle yazılır:

- ``/*`` Ardından (yeni hatları da dahil olmak üzere) herhangi bir karakter dizisi, ardından (çizgi, yıldız) karakterler, ``*/`` karakter. Bu sözdizimi ANSI C ile aynıdır.

- ``//`` (İki eğik çizgi) karakterleri, herhangi bir karakter dizisi içerir. Hemen önünde bir ters eğik çizgi olmayan yeni bir satır, bu yorum biçimini sonlandırır. Bu nedenle, genellikle "tek satırlık yorum" olarak adlandırılır.

Yorum karakterlerinin ( `/*`, `*/`, ve `//`) bir karakter sabiti, dize değişmezi veya yorum içinde özel bir anlamı yoktur. Bu nedenle, ilk sözdizimini kullanan yorumlar iç içe geçirilemez.

## See also

[Lexical Conventions](../cpp/lexical-conventions.md)
