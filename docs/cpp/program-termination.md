---
title: "C++ program termination"
description: "Learn about the standard ways to exit a C++-language program."
ms.date: 12/07/2020
helpviewer_keywords: ["terminating execution", "quitting applications", "exiting applications", "programs [C++], terminating"]
---
# C++ program termination

C++'da bir programdan şu yollarla çıkabilirsiniz:

- Call the [`exit`](../cpp/c-language/c-runtime-library/reference/exit-exit-exit.md) function.
- Call the [`abort`](../cpp/c-language/c-runtime-library/reference/abort.md) function.
- Execute a [`return`](return-statement-cpp.md) statement from `main`.

## `exit` function

[`exit`](../c-runtime-library/reference/exit-exit-exit.md) \<Stdlib.h> beyan fonksiyonu, bir C ++ programı sonlandırır. Argüman olarak sağlanan değer `exit`, programın dönüş kodu veya çıkış kodu olarak işletim sistemine döndürülür. Kural olarak, sıfır dönüş kodu, programın başarıyla tamamlandığı anlamına gelir. Programınızın başarısını veya başarısızlığını belirtmek için \<stdlib.h> içinde de tanımlanan `EXIT_FAILURE` ve sabitlerini kullanabilirsiniz `EXIT_SUCCESS`.

İşlevden bir returnifade yayınlamak , mainişlevi exitbağımsız değişkeni olarak dönüş değeriyle çağırmaya eşdeğerdir .

## `abort` function

[`abort`](../c-runtime-library/reference/abort.md) Ayrıca standardında ilan fonksiyon, dosyayı <stdlib.h>, bir C ++ programı sonlandırır sayılabilir. Arasındaki fark `exit` ve `abort` olmasıdır `exit` C ++ çalışma zamanı sonlandırma işleme yeri (küresel nesne yıkıcılar denilen olsun) almaya izin verir ama `abort` hemen programı sonlandırır. `abort` Fonksiyon global durağan nesneler normal imha işlemi atlar. Ayrıca, [`atexit`](../c-runtime-library/reference/atexit.md) işlev kullanılarak belirtilen tüm özel işlemleri atlar.

## `atexit` function

atexitProgram sonlandırılmadan önce yürütülecek eylemleri belirtmek için işlevi kullanın.  [`atexit`](../c-runtime-library/reference/atexit.md) Çıkış işleme işlevinin yürütülmesinden önce, çağrıdan önce başlatılan hiçbir global statik nesne yok edilmez.

## `return` statement in `main`

[`return`](return-statement-cpp.md) from deyimi yayınlamak `main`, işlevi çağırmakla işlevsel olarak eşdeğerdir `exit`. Aşağıdaki örneği göz önünde bulundurun:

```cpp
// return_statement.cpp
#include <stdlib.h>
int main()
{
    exit( 3 );
    return 3;
}
```

`exit` Ve **`return`** bir önceki örnekte olduğu tablolar işlevsel olarak aynıdır. Normalde, C++, **`void`** bir değer döndürmekten başka dönüş türlerine sahip işlevleri gerektirir. `main` Fonksiyon bir istisnadır; bir **`return`** açıklama yapmadan bitebilir. Bu durumda, çağırma işlemine uygulamaya özel bir değer döndürür. **`return`** İfadende dönüş değeri belirlemenizi sağlar `main`.

## Destruction of static objects

`exit`' den bir **`return`** deyimi çağırdığınızda veya yürüttüğünüzde `main`, statik nesneler, başlatılmalarının tersi sırayla (`atexit` varsa , çağrıdan sonra) yok edilir. Aşağıdaki örnek, bu tür başlatma ve temizlemenin nasıl çalıştığını gösterir.

### Example

Aşağıdaki örnekte, statik nesneler `sd1` ve `sd2` öğeleri, girişten önce oluşturulur ve başlatılır `main`. Bu program returndeyimi kullanarak sonlandırıldıktan sonra önce `sd2` yok edilir ve ardından `sd1`. `ShowData` Sınıfın yıkıcısı , bu statik nesnelerle ilişkili dosyaları kapatır.

```cpp
// using_exit_or_return1.cpp
#include <stdio.h>
class ShowData {
public:
   // Constructor opens a file.
   ShowData( const char *szDev ) {
   errno_t err;
      err = fopen_s(&OutputDev, szDev, "w" );
   }

   // Destructor closes the file.
   ~ShowData() { fclose( OutputDev ); }

   // Disp function shows a string on the output device.
   void Disp( char *szData ) {
      fputs( szData, OutputDev );
   }
private:
   FILE *OutputDev;
};

//  Define a static object of type ShowData. The output device
//   selected is "CON" -- the standard output device.
ShowData sd1 = "CON";

//  Define another static object of type ShowData. The output
//   is directed to a file called "HELLO.DAT"
ShowData sd2 = "hello.dat";

int main() {
   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}
```

Bu kodu yazmanın başka bir yolu, `ShowData` nesneleri blok kapsamıyla bildirmek ve kapsam dışına çıktıklarında yok edilmelerine izin vermektir:

```cpp
int main() {
   ShowData sd1( "CON" ), sd2( "hello.dat" );

   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}
```

## See also

[`main` function and command-line arguments](main-function-command-line-args.md)
