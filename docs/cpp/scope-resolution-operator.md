---
title: "Scope resolution operator: `::`"
description: "Learn how the scope resolution operator `::` works in Standard C++."
ms.date: 12/06/2020
f1_keywords: ["::"]
helpviewer_keywords: ["scope, scope resolution operator", "operators [C++], scope resolution", "scope resolution operator", ":: operator"]
---
# Scope resolution operator: `::`

Kapsam çözümleme operatörü **`::`**, farklı kapsamlarda kullanılan tanımlayıcıları belirlemek ve belirsizliğini gidermek için kullanılır. Kapsam hakkında daha fazla bilgi için bkz. [Scope](../cpp/scope-visual-cpp.md).

## Syntax

> *`qualified-id`*:\
> &emsp;*`nested-name-specifier`* **`template`**<sub>opt</sub> *`unqualified-id`*

> *`nested-name-specifier`*:\
> &emsp;**`::`**\
> &emsp;*`type-name`* **`::`**\
> &emsp;*`namespace-name`* **`::`**\
> &emsp;*`decltype-specifier`* **`::`**\
> &emsp;*`nested-name-specifier`* *`identifier`* **`::`**\
> &emsp;*`nested-name-specifier`* **`template`**<sub>opt</sub> *`simple-template-id`* **`::`**

> *`unqualified-id`*:\
> &emsp;*`identifier`*\
> &emsp;*`operator-function-id`*\
> &emsp;*`conversion-function-id`*\
> &emsp;*`literal-operator-id`*\
> &emsp;**`~`** *`type-name`*\
> &emsp;**`~`** *`decltype-specifier`*\
> &emsp;*`template-id`*

## Remarks

`identifier` Bir değişken, bir fonksiyon ya da bir numaralandırma bir değer olabilir.

## Use `::` for classes and namespaces

Aşağıdaki örnek, kapsam çözümleme operatörünün ad alanları ve sınıflarla nasıl kullanıldığını gösterir:

```cpp
namespace NamespaceA{
    int x;
    class ClassA {
    public:
        int x;
    };
}

int main() {

    // A namespace name used to disambiguate
    NamespaceA::x = 1;

    // A class name used to disambiguate
    NamespaceA::ClassA a1;
    a1.x = 2;
}
```

Kapsam niteleyicisi olmayan bir kapsam çözümleme işleci, genel ad alanına başvurur.

```cpp
namespace NamespaceA{
    int x;
}

int x;

int main() {
    int x;

    // the x in main()
    x = 0;
    // The x in the global namespace
    ::x = 1;

    // The x in the A namespace
    NamespaceA::x = 2;
}
```

Kapsam çözümleme operatörünü, bir üyeyi **`namespace`** tanımlamak veya üyenin ad alanını bir **`using`** yönergede aday gösteren bir ad alanını belirlemek için kullanabilirsiniz . Aşağıdaki örnekte, kullanabilirsiniz `NamespaceC` hak kazanmak için `ClassB` bile olsa, `ClassB` ad ilan edildi `NamespaceB`, çünkü `NamespaceB` içinde aday `NamespaceC` bir tarafından **`using`** yönerge.

```cpp
namespace NamespaceB {
    class ClassB {
    public:
        int x;
    };
}

namespace NamespaceC{
    using namespace NamespaceB;
}

int main() {
    NamespaceB::ClassB b_b;
    NamespaceC::ClassB c_b;

    b_b.x = 3;
    c_b.x = 4;
}
```

Kapsam çözümleme operatörlerinin zincirlerini kullanabilirsiniz. Aşağıdaki örnekte, `NamespaceD::NamespaceD1` iç içe ad alanını `NamespaceD1` ve `NamespaceE::ClassE::ClassE1` iç içe geçmiş sınıfı tanımlar `ClassE1`.

```cpp
namespace NamespaceD{
    namespace NamespaceD1{
        int x;
    }
}

namespace NamespaceE{
    class ClassE{
    public:
        class ClassE1{
        public:
            int x;
        };
    };
}

int main() {
    NamespaceD:: NamespaceD1::x = 6;
    NamespaceE::ClassE::ClassE1 e1;
    e1.x = 7  ;
}
```

## Use `::` for static members

Statik sınıf üyelerini çağırmak için kapsam çözümleme operatörünü kullanmalısınız.

```cpp
class ClassG {
public:
    static int get_x() { return x;}
    static int x;
};

int ClassG::x = 6;

int main() {

    int gx1 = ClassG::x;
    int gx2 = ClassG::get_x();
}
```

## Use `::` for scoped enumerations

Kapsamlı çözümleme operatörü, aşağıdaki örnekte olduğu gibi, kapsamlı bir numaralandırma [Enumeration declarations](../cpp/enumerations-cpp.md) bildirimlerinin değerleriyle de kullanılır :

```cpp
enum class EnumA{
    First,
    Second,
    Third
};

int main() {
    EnumA enum_value = EnumA::First;
}
```

## See also

[C++ built-in operators, precedence, and associativity](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Namespaces](../cpp/namespaces-cpp.md)
