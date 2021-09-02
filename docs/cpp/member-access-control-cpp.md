---
description: "Learn more about: Member Access Control (C++)"
title: "Member Access Control (C++)"
ms.date: "11/19/2018"
helpviewer_keywords: ["access control [C++]", "member access [C++]", "member-access control [C++]"]
ms.assetid: 2d596bca-56ad-4277-94e1-ce3db45fa14a
---
# Member Access Control (C++)

Erişim denetimleri, bir sınıfın [public](../cpp/public-cpp.md) arabirimini [private](../cpp/private-cpp.md) uygulama ayrıntılarından ve yalnızca türetilmiş sınıflar tarafından kullanılmak üzere [protected](../cpp/protected-cpp.md) üyelerden ayırmanıza olanak tanır. Erişim belirteci, bir sonraki erişim belirteci ile karşılaşılıncaya kadar kendisinden sonra bildirilen tüm üyeler için geçerlidir.

```cpp
class Point
{
public:
    Point( int, int ) // Declare public constructor.;
    Point();// Declare public default constructor.
    int &x( int ); // Declare public accessor.
    int &y( int ); // Declare public accessor.

private:                 // Declare private state variables.
    int _x;
    int _y;

protected:      // Declare protected function for derived classes only.
    Point ToWindowCoords();
};
```

Varsayılan erişim **`private`** bir sınıfta ve **`public`** bir yapı veya birleşimdedir. Bir sınıftaki erişim belirteçleri, herhangi bir sırada herhangi bir sayıda kullanılabilir. Sınıf türlerinin nesneleri için depolama tahsisi uygulamaya bağlıdır, ancak üyelere erişim belirteçleri arasında art arda daha yüksek bellek adresleri atanması garanti edilir.

## Member-Access Control

|Type of Access|Meaning|
|--------------------|-------------|
|[public](../cpp/public-cpp.md)|**`public`** Herhangi bir işlev tarafından kullanılabilecek şekilde bildirilen sınıf üyeleri .|
|[private](../cpp/private-cpp.md)|Olarak bildirilen sınıf üyeleri **`private`**, yalnızca sınıfın üye işlevleri ve arkadaşları (sınıflar veya işlevler) tarafından kullanılabilir.|
|[protected](../cpp/protected-cpp.md)|Bildirilen sınıf üyeleri **`protected`**, sınıfın üye işlevleri ve arkadaşları (sınıflar veya işlevler) tarafından kullanılabilir. Ek olarak, sınıftan türetilen sınıflar tarafından kullanılabilirler.|

Erişim denetimi, nesneleri kullanılmaları amaçlanmayan şekillerde kullanmanızı engellemeye yardımcı olur. Bu koruma, açık tür dönüştürmeleri (yayınlar) gerçekleştirildiğinde kaybolur.

> [!NOTE]
> Erişim denetimi tüm adlara eşit olarak uygulanabilir: üye işlevleri, üye verileri, iç içe sınıflar ve numaralandırıcılar.

## Access Control in Derived Classes

Türetilmiş bir sınıfta bir temel sınıfın hangi üyelerine erişilebilir olduğunu iki faktör kontrol eder; aynı faktörler, türetilmiş sınıftaki devralınan üyelere erişimi kontrol eder:

- Türetilmiş sınıfın **`public`** erişim belirtecini kullanarak temel sınıfı bildirip bildirmediği .

- Temel sınıfta üyeye erişimin ne olduğu.

Aşağıdaki tablo, bu faktörler arasındaki etkileşimi ve temel sınıf üye erişiminin nasıl belirleneceğini gösterir.

### Member Access in Base Class

|private|protected|Public|
|-------------|---------------|------------|
|Türetme erişiminden bağımsız olarak her zaman erişilemez|Özel türetme kullanıyorsanız türetilmiş sınıfta özel|Özel türetme kullanıyorsanız türetilmiş sınıfta özel|
||Korumalı türetme kullanıyorsanız türetilmiş sınıfta korunur|Korumalı türetme kullanıyorsanız türetilmiş sınıfta korunur|
||Genel türetme kullanıyorsanız türetilmiş sınıfta korunur|Genel türetme kullanıyorsanız, türetilmiş sınıfta genel|

Aşağıdaki örnek bunu göstermektedir:

```cpp
// access_specifiers_for_base_classes.cpp
class BaseClass
{
public:
    int PublicFunc(); // Declare a public member.
protected:
    int ProtectedFunc(); // Declare a protected member.
private:
    int PrivateFunc(); // Declare a private member.
};

// Declare two classes derived from BaseClass.
class DerivedClass1 : public BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
        PrivateFunc(); // function is inaccessible
    }
};

class DerivedClass2 : private BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
        PrivateFunc(); // function is inaccessible
    }
};

int main()
{
    DerivedClass1 derived_class1;
    DerivedClass2 derived_class2;
    derived_class1.PublicFunc();
    derived_class2.PublicFunc(); // function is inaccessible
}
```

içinde `DerivedClass1`, üye işlevi `PublicFunc` bir genel üyedir ve bir genel temel sınıf `ProtectedFunc` olduğu için korumalı bir üyedir `BaseClass`. `PrivateFunc` için `BaseClass` özeldir ve türetilmiş sınıflara erişilemez.

Olarak `DerivedClass2`, fonksiyonlar `PublicFunc` ve `ProtectedFunc` çünkü özel üyelerini kabul edilir `BaseClass` özel taban sınıftır. Yine, `PrivateFunc` özel olan BaseClassve herhangi bir türetilmiş sınıflara erişilemez.

Temel sınıf erişim belirteci olmadan türetilmiş bir sınıf bildirebilirsiniz. Böyle bir durumda, türetilmiş sınıf bildirimi **`class`** anahtar kelimeyi kullanıyorsa türetme özel olarak kabul edilir . Türetilmiş sınıf bildirimi **`struct`** anahtar kelimeyi kullanıyorsa türetme genel kabul edilir . Örneğin, aşağıdaki kod:

```cpp
class Derived : Base
...
```

is equivalent to:

```cpp
class Derived : private Base
...
```

Similarly, the following code:

```cpp
struct Derived : Base
...
```

is equivalent to:

```cpp
struct Derived : public Base
...
```

Özel erişime sahip olarak bildirilen üyelerin **`friend`**, temel sınıftaki bildirim kullanılarak bu işlevler veya sınıflar bildirilmedikçe, işlevler veya türetilmiş sınıflar tarafından erişilebilir olmadığına dikkat edin.

Bir **`union`** türün temel sınıfı olamaz.

> [!NOTE]
> Özel bir temel sınıf **`private`** belirtirken, türetilmiş sınıfın kullanıcılarının üye erişimini anlaması için anahtar sözcüğü açıkça kullanmanız önerilir .

## Access control and static members

olarak bir temel sınıf belirttiğinizde **`private`**, yalnızca statik olmayan üyeleri etkiler. Genel statik üyelere, türetilmiş sınıflarda hala erişilebilir. Ancak, işaretçiler, referanslar veya nesneler kullanarak temel sınıfın üyelerine erişmek, erişim denetiminin yeniden uygulandığı bir dönüştürme gerektirebilir. Aşağıdaki örneği göz önünde bulundurun:

```cpp
// access_control.cpp
class Base
{
public:
    int Print();             // Nonstatic member.
    static int CountOf();    // Static member.
};

// Derived1 declares Base as a private base class.
class Derived1 : private Base
{
};
// Derived2 declares Derived1 as a public base class.
class Derived2 : public Derived1
{
    int ShowCount();    // Nonstatic member.
};
// Define ShowCount function for Derived2.
int Derived2::ShowCount()
{
   // Call static member function CountOf explicitly.
    int cCount = Base::CountOf();     // OK.

   // Call static member function CountOf using pointer.
    cCount = this->CountOf();  // C2247. Conversion of
                               //  Derived2 * to Base * not
                               //  permitted.
    return cCount;
}
```

Önceki kod olarak, erişim kontrol için bir işaretçi dönüşümü engeller `Derived2` için bir işaretçi `Base`. **`this`** İşaretçi dolaylı tiptedir `Derived2 *`. İşlevi seçmek için `CountOf` type'a **`this`** dönüştürülmelidir `Base *`. Baseiçin özel bir dolaylı temel sınıf olduğundan böyle bir dönüştürmeye izin verilmez `Derived2`. Özel bir temel sınıf türüne dönüştürme, yalnızca doğrudan türetilmiş sınıflara yönelik işaretçiler için kabul edilebilir. Bu nedenle, tür işaretçileri türe `Derived1 *` dönüştürülebilir `Base *`.

`CountOf` İşlevi seçmek için bir işaretçi, başvuru veya nesne kullanmadan açıkça çağırmanın dönüştürme anlamına gelmediğini unutmayın. Bu nedenle, aramaya izin verilir.

Türetilmiş bir sınıfın üyeleri ve arkadaşları, bir `T` işaretçiyi `T` bir işaretçiye, özel bir doğrudan temel sınıfa dönüştürebilir `T`.

## Access to virtual functions

 [virtual](../cpp/virtual-cpp.md) işlevlere uygulanan erişim denetimi , işlev çağrısını yapmak için kullanılan türe göre belirlenir. İşlevin geçersiz kılınan bildirimleri, belirli bir tür için erişim denetimini etkilemez. Örneğin:

```cpp
// access_to_virtual_functions.cpp
class VFuncBase
{
public:
    virtual int GetState() { return _state; }
protected:
    int _state;
};

class VFuncDerived : public VFuncBase
{
private:
    int GetState() { return _state; }
};

int main()
{
   VFuncDerived vfd;             // Object of derived type.
   VFuncBase *pvfb = &vfd;       // Pointer to base type.
   VFuncDerived *pvfd = &vfd;    // Pointer to derived type.
   int State;

   State = pvfb->GetState();     // GetState is public.
   State = pvfd->GetState();     // C2248 error expected; GetState is private;
}
```

Önceki örnekte, çağrılar yazmak için `GetState` bir işaretçi kullanarak sanal işlevi `VFuncBase` çağırmak `VFuncDerived::GetState`, `GetState` genel olarak kabul edilir. Ancak, yazmak `GetState` için işaretçi kullanarak çağırmak , sınıfta private olarak bildirildiğinden `VFuncDerived` erişim denetimi ihlalidir .`GetStateVFuncDerived` 

> [!CAUTION]
> Sanal işlev `GetState`, temel sınıfa bir işaretçi kullanılarak çağrılabilir `VFuncBase`. Bu, çağrılan işlevin o işlevin temel sınıf versiyonu olduğu anlamına gelmez.

## Access control with multiple inheritance

Sanal temel sınıfları içeren çoklu kalıtımlı kafeslerde, belirli bir isme birden fazla yoldan ulaşılabilir. Bu farklı yollar boyunca farklı erişim denetimi uygulanabileceğinden, derleyici en fazla erişim sağlayan yolu seçer. Aşağıdaki şekle bakın.

![Access along paths of an inheritance graph](../cpp/media/vc38v91.gif "Access along paths of an inheritance graph") <br/>
Access along paths of an inheritance graph

Şekilde, class içinde bildirilen bir isme `VBase` her zaman class üzerinden ulaşılır `RightPath`. Doğru yol, çünkü daha erişilebilir `RightPath` beyan `VBase` oysa bir kamu temel sınıf olarak `LeftPath` beyan `VBase` özel olarak.

## See also

[C++ Language Reference](../cpp/cpp-language-reference.md)
