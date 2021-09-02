---
description: "Learn more about: C++ type system"
title: "C++ type system"
ms.date: "11/19/2019"
ms.topic: "conceptual"
ms.assetid: 553c0ed6-77c4-43e9-87b1-c903eec53e80
---
# C++ type system

*Type* kavramı C++'da çok önemlidir. Her değişken, işlev bağımsız değişkeni ve işlev dönüş değerinin derlenebilmesi için bir türü olmalıdır. Ayrıca, her ifadeye (değişmez değerler dahil), değerlendirilmeden önce derleyici tarafından örtük olarak bir tür verilir. Bazı tür örnekleri arasında **`int`** tamsayı değerleri **`double`** depolamak, kayan noktalı değerleri depolamak ( skaler veri türleri olarak da bilinir ) veya metni depolamak için Standart Kitaplık sınıfı [std::basic_string](../standart-library/basic-string-class.md) bulunur . Bir **`class`** veya **`struct`** tanımlayarak kendi türünüzü oluşturabilirsiniz. Tür, değişken (veya ifade sonucu) için ayrılacak bellek miktarını, bu değişkende saklanabilecek değer türlerini, bu değerlerin (bit desenleri olarak) nasıl yorumlandığını ve gerçekleştirilebilecek işlemleri belirtir. üstünde. Bu makale, C++ tipi sistemin ana özelliklerine resmi olmayan bir genel bakış içerir.

## Terminology

**Variable**: Adın tanımlandığı kodun kapsamı boyunca atıfta bulunduğu verilere erişmek için kullanılabilmesi için bir veri miktarının sembolik adı. C++'da değişken genellikle skaler veri türlerinin örneklerine atıfta bulunmak için kullanılırken, diğer türlerin örneklerine genellikle nesneler denir .

**Object**: Basitlik ve tutarlılık için, bu makale nesne terimini bir sınıf veya yapının herhangi bir örneğine atıfta bulunmak için kullanır ve genel anlamda kullanıldığında tüm türleri, hatta skaler değişkenleri içerir.

**POD type (düz eski veriler)**: C++'daki bu resmi olmayan veri türleri kategorisi, skaler (Temel türler bölümüne bakın) veya POD sınıfları olan türlere atıfta bulunur . Bir POD sınıfı, aynı zamanda POD olmayan statik veri üyelerine ve kullanıcı tanımlı oluşturuculara, kullanıcı tanımlı yıkıcılara veya kullanıcı tanımlı atama operatörlerine sahip değildir. Ayrıca, bir POD sınıfında sanal işlevler, temel sınıflar ve özel veya korumalı statik olmayan veri üyeleri yoktur. POD türleri genellikle, örneğin C dilinde yazılmış bir modülle (yalnızca POD türlerine sahip olan) harici veri alışverişi için kullanılır.

## Specifying variable and function types

C++ *kesin olarak* yazılan bir dildir ve ayrıca statik olarak yazılmıştır; her nesnenin bir türü vardır ve bu tür asla değişmez (statik veri nesneleriyle karıştırılmamalıdır). Kodunuzda bir değişken bildirdiğinizde, türünü açıkça belirtmeli ya **`auto`** derleyiciye, başlatıcıdan türü çıkarması talimatını vermek için anahtar sözcüğü kullanmalısınız . Kodunuzda bir işlev bildirdiğinizde, her bir bağımsız değişkenin türünü ve dönüş değerini veya **`void`** işlev tarafından herhangi bir değer döndürülmediğini belirtmeniz gerekir . Bunun istisnası, isteğe bağlı türlerin bağımsız değişkenlerine izin veren işlev şablonlarını kullanmanızdır.

Bir değişkeni ilk kez tanımladıktan sonra, türünü daha sonraki bir noktada değiştiremezsiniz. Ancak, değişkenin değerini veya bir işlevin dönüş değerini farklı türde başka bir değişkene kopyalayabilirsiniz. Bu tür işlemler, bazen gerekli olan ancak aynı zamanda potansiyel veri kaybı veya yanlışlığı kaynakları olan tür dönüştürmeleri olarak adlandırılır .

POD türünde bir değişken tanımladığınızda, onu başlatmanızı, yani ona bir başlangıç değeri vermenizi şiddetle tavsiye ederiz. Bir değişkeni başlatana kadar, daha önce o bellek konumunda olan bitlerden oluşan bir "çöp" değerine sahiptir. Bu, özellikle sizin için başlatma işlemlerini gerçekleştiren başka bir dilden geliyorsanız, C++'ın hatırlanması gereken önemli bir yönüdür. POD olmayan sınıf türünde bir değişken bildirirken, yapıcı başlatmayı işler.

Aşağıdaki örnek, her biri için bazı açıklamalar içeren bazı basit değişken bildirimlerini göstermektedir. Örnek ayrıca, derleyicinin, değişken üzerinde sonraki belirli işlemlere izin vermek veya vermemek için tür bilgilerini nasıl kullandığını da gösterir.

```cpp
int result = 0;              // Declare and initialize an integer.
double coefficient = 10.8;   // Declare and initialize a floating
                             // point value.
auto name = "Lady G.";       // Declare a variable and let compiler
                             // deduce the type.
auto address;                // error. Compiler cannot deduce a type
                             // without an intializing value.
age = 12;                    // error. Variable declaration must
                             // specify a type or use auto!
result = "Kenny G.";         // error. Can’t assign text to an int.
string result = "zero";      // error. Can’t redefine a variable with
                             // new type.
int maxValue;                // Not recommended! maxValue contains
                             // garbage bits until it is initialized.
```

## Fundamental (built-in) types

Bazı dillerden farklı olarak, C++, diğer tüm türlerin türetildiği evrensel bir temel türe sahip değildir. Dil, yerleşik türler olarak da bilinen birçok temel türü içerir . Bu, sırasıyla **`int`**, **`double`**, **`long`**, **`bool`**, artı **`char`** ve **`wchar_t`** ASCII ve UNICODE karakterleri için ve türleri gibi sayısal türleri içerir . En tamamlayıcı temel tipleri (dışında **`bool`**, **`double`**, **`wchar_t`** ve ilgili türleri), tüm sahip değişken saklayabildiği değerleri aralığını değiştirmek versiyonları. Örneğin, 32 bitlik işaretli bir tamsayı depolayan bir **`int`**, -2.147.483.648 ile 2.147.483.647 arasında bir değeri temsil edebilir. **`unsigned int`** int32 bit olarak da saklanan , 0 ile 4,294,967,295 arasında bir değer saklayabilir. Her durumda olası değerlerin toplam sayısı aynıdır; sadece aralık farklıdır.

Temel türler, üzerlerinde hangi işlemleri yapabileceğinizi ve bunların diğer temel türlere nasıl dönüştürülebileceğini yöneten yerleşik kurallara sahip olan derleyici tarafından tanınır. Yerleşik türlerin tam listesi ve bunların boyutu ve sayısal sınırları için bkz. [Built-in types](../cpp/fundamental-types-cpp.md)

Aşağıdaki çizim, Microsoft C++ uygulamasındaki yerleşik türlerin göreli boyutlarını gösterir:

![Size in bytes of built&#45;in types](../cpp/media/built-intypesizes.png "Size in bytes of built&#45;in types")

Aşağıdaki tablo, Microsoft C++ uygulamasında en sık kullanılan temel türleri ve bunların boyutlarını listeler:

| Type | Size | Comment |
|--|--|--|
| **`int`** | 4 bytes | İntegral değerler için varsayılan seçim. |
| **`double`** | 8 bytes | Kayan nokta değerleri için varsayılan seçim. |
| **`bool`** | 1 byte | Doğru veya yanlış olabilen değerleri temsil eder. |
| **`char`** | 1 byte | Asla UNICODE'a dönüştürülmesi gerekmeyecek olan eski C tarzı dizelerdeki veya std::string nesnelerindeki ASCII karakterleri için kullanın. |
| **`wchar_t`** | 2 bytes | UNICODE biçiminde kodlanabilen "geniş" karakter değerlerini temsil eder (Windows'ta UTF-16, diğer işletim sistemleri farklılık gösterebilir). Bu, tür dizelerinde kullanılan karakter türüdür `std::wstring`. |
| **`unsigned char`** | 1 byte | C++ yerleşik bayt türüne sahip değildir. `unsigned char` Bir bayt değerini temsil etmek için kullanın . |
| **`unsigned int`** | 4 bytes | Bit bayrakları için varsayılan seçim. |
| **`long long`** | 8 bytes | Çok büyük tamsayı değerlerini temsil eder. |

Diğer C++ uygulamaları, belirli sayısal türler için farklı boyutlar kullanabilir. C++ standardının gerektirdiği boyutlar ve boyut ilişkileri hakkında daha fazla bilgi için bkz. [Built-in types](fundamental-types-cpp.md).

## The void type

**`void`** Tip özel bir türüdür; türünde bir değişken bildiremezsiniz **`void`**, ancak bazen ham (yazılmamış) bellek ayırırken gerekli olan bir tür `void *`(işaretçiye **`void`**) değişkeni bildirebilirsiniz . Bununla birlikte, işaretçiler **`void`** tür açısından güvenli değildir ve genellikle modern C++'da kullanımları kesinlikle önerilmez. Bir işlev bildiriminde, bir **`void`** dönüş değeri, işlevin bir değer döndürmediği anlamına gelir; bu yaygın ve kabul edilebilir bir kullanımdır.**`void`**. C dili void, örneğin parametre listesinde bildirilecek sıfır parametreye sahip işlevlere ihtiyaç duysa da `fou(void)`, bu uygulama modern C++'da önerilmez ve bildirilmelidir `fou(void)`. Daha fazla bilgi için, bkz. [Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md).

## const type qualifier

Herhangi bir yerleşik veya kullanıcı tanımlı tür, const anahtar sözcüğüyle nitelenebilir. Ek olarak, üye işlevler **`const`**-nitelikli ve hatta - **`const`** aşırı yüklenmiş olabilir. Bir **`const`** türün değeri , başlatıldıktan sonra değiştirilemez.

```cpp

const double PI = 3.1415;
PI = .75 //Error. Cannot modify const variable.
```

**`const`** Niteleyici fonksiyonu yaygın olarak kullanılmaktadır ve değişken tanımlama ve "sabit doğruluğu" C ++ önemli bir kavramdır; esasen **`const`** derleme zamanında değerlerin istenmeden değiştirilmediğini garanti etmek için kullanmak anlamına gelir . Daha fazla bilgi için bkz [`const`](../cpp/const-cpp.md).

Bir **`const`** tür, const olmayan sürümünden farklıdır; örneğin, **`const int`** dan farklı bir türdür **`int`**. C++ **`const_cast`** operatörünü, bir değişkenden const-ness'i kaldırmanız gereken nadir durumlarda kullanabilirsiniz . Daha fazla bilgi için, bkz. [Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md).

## String types

Kesin konuşmak gerekirse, C++ dilinde yerleşik bir dize türü yoktur; **`char`** ve **`wchar_t`** tek karakterleri depolayın - bir dizeye yaklaşmak için bu türlerden bir dizi bildirmelisiniz '\0', dizi öğesine son geçerli karakterden bir sonraki sonlandırıcı bir boş değer (örneğin, ASCII `'\0'`) ekleyerek ( C stili dize olarak da adlandırılır ). C tarzı dizeler, yazılması için çok daha fazla kod veya harici dize yardımcı program kitaplığı işlevlerinin kullanılmasını gerektiriyordu. Ancak modern C++'da Standart Kitaplık türleri `std::string` (8 bitlik **`char`** karakter dizileri için) veya `std::wstring` (16 bit için) vardır.wchar_t-type karakter dizileri). Bu C++ Standart Kitaplık kapsayıcıları, herhangi bir uyumlu C++ oluşturma ortamında bulunan standart kitaplıkların parçası oldukları için yerel dize türleri olarak düşünülebilir. `#include <string>` Bu türleri programınızda kullanılabilir hale getirmek için yönergeyi kullanın. (MFC veya ATL kullanıyorsanız, `CString` sınıf da mevcuttur, ancak C++ standardının bir parçası değildir.) Boş sonlandırılmış karakter dizilerinin (daha önce bahsedilen C stili dizeler) kullanımı modern C++'da kesinlikle önerilmez.

## User-defined types

Bir tanımladığınızda **`class`**, **`struct`**, **`union`**, ya **`enum`** da temel bir tip sanki o yapı Kodunuzun geri kalanında kullanılır. Bellekte bilinen bir boyutu vardır ve derleme zamanı denetimi için ve çalışma zamanında programınızın ömrü boyunca nasıl kullanılacağına ilişkin belirli kurallar ona uygulanır. Temel yerleşik türler ile kullanıcı tanımlı türler arasındaki temel farklar şunlardır:



- Derleyici, kullanıcı tanımlı bir tür hakkında yerleşik bilgiye sahip değildir. Derleme işlemi sırasında tanımla ilk karşılaştığında türü öğrenir.

- Uygun operatörleri sınıf üyeleri veya üye olmayan işlevler olarak tanımlayarak (aşırı yükleme yoluyla) türünüz üzerinde hangi işlemlerin gerçekleştirilebileceğini ve diğer türlere nasıl dönüştürülebileceğini belirtirsiniz. Daha fazla bilgi için, bkz. [Function Overloading](function-overloading.md)

## Pointer types

C dilinin en eski sürümlerine dayanan C++, özel bildiriciyi **`*`** (yıldız) kullanarak bir işaretçi türünde bir değişken bildirmenize izin vermeye devam eder . İşaretçi türü, gerçek veri değerinin depolandığı konumun adresini bellekte saklar. Modern C++'da bunlara ham işaretçiler denir ve kodunuzda özel operatörler **`*`** (yıldız(asterisk)) veya ->(büyüktür ile tire ) aracılığıyla erişilir . Buna *dereferencing* denirve hangisini kullanacağınız, bir işaretçiyi bir skalere mi yoksa bir nesnedeki bir üyeye işaretçiye mi başvuru yaptığınıza bağlıdır. İşaretçi türleriyle çalışmak, uzun zamandır C ve C++ program geliştirmenin en zorlu ve kafa karıştırıcı yönlerinden biri olmuştur. İstersen Bu bölüm yardım kullanımı ham işaretçilere bazı gerçekleri ve uygulamalar özetlenmektedir, ama modern C ++ içinde artık nedeniyle evrimi için, hiç nesne sahipliği için ham işaretçileri kullanmak için gerekli (veya önerilir) bulunuyor [smart pointer](../cpp/smart-pointers-modern-cpp.md) daha tartışılan ( Bu bölümün sonunda). Nesneleri gözlemlemek için ham işaretçiler kullanmak yine de yararlı ve güvenlidir, ancak bunları nesne sahipliği için kullanmanız gerekiyorsa, bunları sahip oldukları nesnelerin nasıl oluşturulduğunu ve yok edildiğini dikkatle ve çok dikkatli bir şekilde göz önünde bulundurarak yapmalısınız.

Bilmeniz gereken ilk şey, bir ham işaretçi değişkeni bildirmek, yalnızca işaretçinin referansı kaldırıldığında başvuracağı bellek konumunun bir adresini depolamak için gereken belleği tahsis edecektir. Veri değerinin kendisi için bellek tahsisi ( *backing store* olarak da adlandırılır ) henüz tahsis edilmemiştir. Başka bir deyişle, ham bir işaretçi değişkeni bildirerek, gerçek bir veri değişkeni değil, bir bellek adres değişkeni yaratmış olursunuz. Bir destek deposu için geçerli bir adres içerdiğinden emin olmadan önce bir işaretçi değişkeninin referansını kaldırmak, programınızda tanımsız davranışa (genellikle önemli bir hata) neden olur. Aşağıdaki örnek, bu tür bir hatayı göstermektedir:

```cpp
int* pNumber;       // Declare a pointer-to-int variable.
*pNumber = 10;      // error. Although this may compile, it is
                    // a serious error. We are dereferencing an
                    // uninitialized pointer variable with no
                    // allocated memory to point to.
```

Örnek, gerçek tamsayı verilerini depolamak için ayrılmış herhangi bir belleğe veya kendisine atanmış geçerli bir bellek adresine sahip olmayan bir işaretçi türünün başvurusunu kaldırır. Aşağıdaki kod bu hataları düzeltir:

```cpp
    int number = 10;          // Declare and initialize a local integer
                              // variable for data backing store.
    int* pNumber = &number;   // Declare and initialize a local integer
                              // pointer variable to a valid memory
                              // address to that backing store.
...
    *pNumber = 41;            // Dereference and store a new value in
                              // the memory pointed to by
                              // pNumber, the integer variable called
                              // "number". Note "number" was changed, not
                              // "pNumber".
```

Düzeltilmiş kod örneği, `pNumber` işaret eden yedekleme deposunu oluşturmak için yerel yığın belleği kullanır . Basitlik için temel bir tür kullanıyoruz. Pratikte, işaretçiler için yedekleme deposu, çoğunlukla, bir anahtar sözcük ifadesi (C stili programlamada, eski C çalışma zamanı kitaplığı ) kullanılarak yığın (veya *free store* ) adı verilen bir bellek alanına dinamik olarak tahsis edilen kullanıcı tanımlı türlerdir. fonksiyonu kullanılmıştır). Bir kez tahsis edildikten sonra, bu değişkenler, özellikle bir sınıf tanımına dayanıyorlarsa, genellikle nesneler olarak adlandırılır. Tahsis edilen bellek, karşılık gelen bir ifadeyle (veya tahsis etmek için işlevi kullandıysanız , C çalışma zamanı işleviyle ) silinmelidir.

Ancak, özellikle karmaşık kodlarda, dinamik olarak tahsis edilmiş bir nesneyi silmeyi unutmak kolaydır, bu da bellek sızıntısı adı verilen bir kaynak hatasına neden olur . Bu nedenle, modern C++'da ham işaretçilerin kullanılması kesinlikle önerilmez. Ham bir işaretçiyi bir [smart pointer](../cpp/smart-pointers-modern-cpp.md) sarmak neredeyse her zaman daha iyidir; bu, yıkıcısı çağrıldığında (kod akıllı işaretçi için kapsam dışına çıktığında) belleği otomatik olarak serbest bırakır; akıllı işaretçiler kullanarak, C++ programlarınızdaki bütün bir hata sınıfını neredeyse ortadan kaldırırsınız. Aşağıdaki örnekte, `MyClass` genel yöntemi olan kullanıcı tanımlı bir tür olduğunu varsayın `DoSomeWork();`

```cpp
void someFunction() {
    unique_ptr<MyClass> pMc(new MyClass);
    pMc->DoSomeWork();
}
  // No memory leak. Out-of-scope automatically calls the destructor
  // for the unique_ptr, freeing the resource.
```

For more information about smart pointers, see [Smart Pointers](../cpp/smart-pointers-modern-cpp.md).

For more information about pointer conversions, see [Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md).

For more information about pointers in general, see [Pointers](../cpp/pointers-cpp.md).

## Windows data types

C ve C++ için klasik Win32 programlamasında, çoğu işlev, parametre türlerini ve dönüş değerlerini belirtmek için Windows'a özgü typedef'leri ve `#define` makroları ( 'de tanımlanmıştır `windef.h`) kullanır. Bu Windows veri türleri çoğunlukla C/C++ yerleşik türlerine verilen özel adlardır (takma adlar). Bu tür tanımlarının ve önişlemci tanımlarının tam listesi için  . `HRESULT` ve gibi bu tip LCIDtanımlarından bazıları kullanışlı ve açıklayıcıdır. Diğerleri, örneğin `INT`, özel bir anlamı yoktur ve yalnızca temel C++ türleri için takma adlardır. Diğer Windows veri türleri, C programlama ve 16 bit işlemci günlerinden kalan adlara sahiptir ve modern donanım veya işletim sistemlerinde hiçbir amacı veya anlamı yoktur. Windows Çalışma Zamanı Kitaplığı ile ilişkili, Windows Çalışma Zamanı temel veri türleri olarak listelenen özel veri türleri de vardır . Modern C++'da genel kılavuz, Windows türü değerin nasıl yorumlanacağı hakkında ek bir anlam ifade etmediği sürece, temel C++ türlerini tercih etmektir.

## More information

For more information about the C++ type system, see the following topics.

[Value Types](../cpp/value-types-modern-cpp.md)\
Describes *value types* along with issues relating to their use.

[Type Conversions and Type Safety](../cpp/type-conversions-and-type-safety-modern-cpp.md)\
Describes common type conversion issues and shows how to avoid them.

## See also

[Welcome back to C++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[C++ Language Reference](../cpp/cpp-language-reference.md)<br/>
[C++ Standard Library](../standard-library/cpp-standard-library-reference.md)
