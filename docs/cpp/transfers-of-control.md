---
description: "Learn more about: Transfers of Control"
title: "Transfers of Control"
ms.date: "11/04/2016"
helpviewer_keywords: ["control flow, branching", "control flow, transferring control"]
ms.assetid: aa51e7f2-060f-4106-b0fe-331f04357423
---
# Transfers of Control

Bir başlatıcıyı geçen bir programı belirtmek için **`goto`** ifadeyi veya bir **`case`** ifadedeki etiketi kullanabilirsiniz **`switch`**. Başlatıcıyı içeren bildirim, jump ifadesinin gerçekleştiği blok tarafından çevrelenen bir blokta olmadığı sürece, bu tür kodlar geçersizdir.

Aşağıdaki örnek total, ch, ve nesnelerini bildiren ve başlatan bir döngüyü gösterir i. **`goto`** Denetimi bir başlatıcıdan sonra aktaran hatalı bir ifade de vardır .

```cpp
// transfers_of_control.cpp
// compile with: /W1
// Read input until a nonnumeric character is entered.
int main()
{
   char MyArray[5] = {'2','2','a','c'};
   int i = 0;
   while( 1 )
   {
      int total = 0;

      char ch = MyArray[i++];

      if ( ch >= '0' && ch <= '9' )
      {
         goto Label1;

         int i = ch - '0';
      Label1:
         total += i;   // C4700: transfers past initialization of i.
      } // i would be destroyed here if  goto error were not present
   else
      // Break statement transfers control out of loop,
      //  destroying total and ch.
      break;
   }
}
```

Önceki örnekte, **`goto`** deyim, kontrolün başlatılmasından sonraki denetimi aktarmaya çalışır `i`. Ancak, `i` beyan edilmiş ancak başlatılmamışsa, transfer yasal olacaktır.

Nesneleri `total` ve `ch` olarak hizmet blok ilan açıklamada ait **`while`** blok kullanılarak çıkıldığı zaman tablosunda, imha edilir **`break`** deyimi.
