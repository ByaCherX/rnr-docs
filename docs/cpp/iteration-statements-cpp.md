---
description: "Learn more about: Iteration Statements (C++)"
title: "Iteration Statements (C++)"
ms.date: "11/04/2016"
helpviewer_keywords: ["iteration statements", "loop structures, iteration statements"]
ms.assetid: bf6d75f7-ead2-426a-9c47-33847f59b8c7
---
# Iteration Statements (C++)

Yineleme ifadeleri, bazı döngü sonlandırma kriterlerine tabi olarak, ifadelerin (veya bileşik ifadelerin) sıfır veya daha fazla kez yürütülmesine neden olur. Bu deyimler bileşik deyimler olduğunda, [break](../cpp/break-statement-cpp.md) deyimi veya [continue](../cpp/continue-statement-cpp.md) deyimiyle karşılaşılmadıkça, sırayla yürütülürler .

C++ dört yineleme ifadesi sağlar (Bu ifadeler *Selection statements* bölümünde birleştirilmiştir.) [Selection statements](../cpp/selection-statements-cpp.md) Bunların her biri, sonlandırma ifadesi sıfır (yanlış) olarak değerlendirilene veya bir **`break`** ifadeyle döngü sonlandırmaya zorlanana kadar yinelenir . Aşağıdaki tablo bu ifadeleri ve eylemlerini özetlemektedir; her biri aşağıdaki bölümlerde ayrıntılı olarak tartışılmaktadır.

### Iteration Statements

|Statement|Evaluated At|Initialization|Increment|
|---------------|------------------|--------------------|---------------|
|**`while`**|Top of loop|No|No|
|**`do`**|Bottom of loop|No|No|
|**`for`**|Top of loop|Yes|Yes|
|**range-based for**|Top of loop|Yes|Yes|

Bir yineleme ifadesinin ifade kısmı bir bildirim olamaz. Ancak, bir bildirim içeren bileşik bir ifade olabilir.

## See also

[Overview of C++ Statements](../cpp/overview-of-cpp-statements.md)
