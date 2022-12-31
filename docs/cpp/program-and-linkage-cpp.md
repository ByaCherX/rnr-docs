---
description: "Learn more about: Translation units and linkage"
title: "Translation units and linkage (C++)"
ms.date: "12/11/2019"
ms.assetid: a6493ba0-24e2-4c89-956e-9da1dea660cb
---
# Translation units and linkage

Bir C++ programında, örneğin bir değişken veya işlev adı gibi bir sembol , kapsamı içinde herhangi bir sayıda bildirilebilir, ancak yalnızca bir kez tanımlanabilir. Bu kural "Tek Tanımlı Kural"dır (ODR). Bir bildirim , programa bir isim ekler (veya yeniden sunar). Bir *definition*, bir adı tanıtır. Ad bir değişkeni temsil ediyorsa, bir tanım onu açıkça başlatır. Bir fonksiyon tanımı , imza ve fonksiyon gövdesinden oluşur. Sınıf tanımı, sınıf adının ardından tüm sınıf üyelerini listeleyen bir bloktan oluşur. (Üye işlevlerinin gövdeleri isteğe bağlı olarak başka bir dosyada ayrı olarak tanımlanabilir.)

Aşağıdaki örnek, bazı bildirimleri gösterir:

```cpp
int i;
int f(int x);
class C;
```

Aşağıdaki örnek bazı tanımları göstermektedir:

```cpp
int i{42};
int f(int x){ return x * i; }
class C {
public:
   void DoSomething();
};
```

Bir program bir veya daha fazla çeviri biriminden oluşur . Bir çeviri birimi, bir uygulama dosyasından ve doğrudan veya dolaylı olarak içerdiği tüm başlıklardan oluşur. Uygulama dosyaları genellikle *cpp* veya *cxx* dosya uzantısına sahiptir . Başlık dosyaları genellikle h veya hpp uzantısına sahiptir . Her çeviri birimi derleyici tarafından bağımsız olarak derlenir. Derleme tamamlandıktan sonra, bağlayıcı derlenmiş çeviri birimlerini tek bir *program*'da birleştirir . ODR kuralının ihlali, genellikle bağlayıcı hataları olarak görünür. Bağlayıcı hataları, aynı adın farklı çeviri birimlerinde iki farklı tanımı olduğunda ortaya çıkar.

Genel olarak, bir değişkeni birden çok dosyada görünür kılmanın en iyi yolu, onu bir başlık dosyasına koymaktır. Ardından , bildirim gerektiren her *cpp* dosyasına bir #include yönergesi ekleyin . Başlık içeriğinin etrafına içerme korumaları ekleyerek , bildirdiği adların yalnızca bir kez tanımlanmasını sağlarsınız.

C++20'de [modules](modules-cpp.md), başlık dosyalarına geliştirilmiş bir alternatif olarak sunulur.

Bazı durumlarda, bir *cpp* dosyasında global bir değişken veya sınıf bildirmek gerekli olabilir. Bu gibi durumlarda, derleyiciye ve bağlayıcıya adın ne tür bir bağlantısı olduğunu söylemenin bir yoluna ihtiyacınız vardır. Bağlantı türü, nesnenin adının yalnızca bir dosyaya mı yoksa tüm dosyalara mı uygulanacağını belirtir. Bağlantı kavramı yalnızca genel adlar için geçerlidir. Bağlantı kavramı, bir kapsam içinde bildirilen adlara uygulanmaz. Kapsam, işlev veya sınıf tanımlarında olduğu gibi bir küme parantez ile belirtilir.

## External vs. internal linkage

Bir *free function* küresel veya ad alanı kapsamda tanımlanan bir fonksiyondur. Const olmayan global değişkenler ve serbest işlevler varsayılan olarak harici bağlantıya sahiptir ; bunlar programdaki herhangi bir çeviri biriminden görülebilir. Bu nedenle, başka hiçbir global nesne bu ada sahip olamaz. *internal linkage* veya *no linkage* bir sembol, yalnızca bildirildiği çeviri birimi içinde görünür. Bir ismin dahili bağlantısı varsa, aynı isim başka bir çeviri biriminde de bulunabilir. Sınıf tanımları veya işlev gövdeleri içinde bildirilen değişkenlerin bağlantısı yoktur.

Genel bir adı, açıkça bildirerek dahili bağlantıya sahip olmaya zorlayabilirsiniz **`static`**. Bu, görünürlüğünü bildirildiği aynı çeviri birimiyle sınırlar. Bu bağlamda, **`static`** yerel değişkenlere uygulandığından farklı bir şey ifade eder.

Aşağıdaki nesneler varsayılan olarak dahili bağlantıya sahiptir:

- const objects
- constexpr objects
- typedefs
- ad alanı (namespace) kapsamındaki static object

Bir const nesnesine harici bağlantı vermek için, onu olarak bildirin **`extern`** ve ona bir değer atayın:

```cpp
extern const int value = 42;
```

See [extern](extern-cpp.md) for more information.

## See also

[Basic Concepts](../cpp/basic-concepts-cpp.md)
