---
description: "Overview Windows C++ programming"
title: "Windows C++ programming"
ms.custom: "index-page"
ms.date: "19/06/2021"
helpviewer_keywords: ["C++, windows, C++ Programming"]
---
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

<h1 style="text-align:center;">Windows C++ Programming <i class="bi bi-code-slash"></i></h1>

C++ ile oluşturabileceğiniz birkaç geniş Windows uygulaması kategorisi vardır. Her birinin kendi programlama modeli ve Windows'a özgü kitaplıklar kümesi vardır, ancak C++ standart kitaplığı ve üçüncü taraf C++ kitaplıkları bunların herhangi birinde kullanılabilir.

Bu bölümde, Windows programları oluşturmak için Visual Studio ve MFC/ATL sarmalayıcı kitaplıklarının nasıl kullanılacağı anlatılmaktadır. Windows platformunun kendisiyle ilgili belgeler için [Windows belgelerine](https://docs.microsoft.com/en-us/windows/) bakın.

## Command line (console) applications
C++ konsol uygulamaları, bir konsol penceresindeki komut satırından çalıştırılır ve yalnızca metin çıktısını görüntüleyebilir. Daha fazla bilgi için bkz . C++'da konsol hesap makinesi oluşturma.

## Native desktop client applications
Bir yerel masaüstü istemci uygulaması bir C veya C ++ orijinal yerli kullanan uygulama pencereli olan Windows C API'leri veya Bileşen Nesne Modeli (COM) API'leri işletim sistemine erişmek için. Bu API'lerin kendileri çoğunlukla C dilinde yazılmıştır. Yerel bir masaüstü uygulaması oluşturmanın birden fazla yolu vardır: İşletim sistemi olaylarını işleyen C tarzı bir mesaj döngüsü kullanarak doğrudan Win32 API'lerini kullanarak programlayabilirsiniz. Veya Microsoft Foundation Classes kullanarak programlayabilirsiniz.(MFC), Win32'yi saran hafif nesne yönelimli bir C++ kitaplığı. Her iki yaklaşım da Evrensel Windows Platformu (UWP) ile karşılaştırıldığında "modern" olarak kabul edilmez, ancak her ikisi de hala tam olarak desteklenmektedir ve bugün dünyada çalışan milyonlarca kod satırına sahiptir. Bir pencerede çalışan bir Win32 uygulaması, geliştiricinin bir Windows yordam işlevi içinde Windows iletileriyle açık bir şekilde çalışmasını gerektirir. Adına rağmen, bir Win32 uygulaması 32 bit (x86) veya 64 bit (x64) ikili dosya olarak derlenebilir. Visual Studio IDE'de x86 ve Win32 terimleri eşanlamlıdır.

Geleneksel Windows C++ programlamaya başlamak için bkz . Win32 ve C++ ile Başlarken . Win32 hakkında biraz bilgi sahibi olduktan sonra, MFC Masaüstü Uygulamaları hakkında bilgi edinmek daha kolay olacaktır . Gelişmiş grafikler kullanan geleneksel bir C++ masaüstü uygulaması örneği için, bkz. Hilo: Windows için C++ Uygulamaları Geliştirme .

## C++ or .NET?
Genel olarak, C#'da .NET programlama daha az karmaşıktır, daha az hataya açıktır ve Win32 veya MFC'den daha modern nesne yönelimli API'ye sahiptir. Çoğu durumda, performansı fazlasıyla yeterli. .NET, zengin grafikler için Windows Presentation Foundation'a (WPF) sahiptir ve hem Win32'yi hem de modern Windows Runtime API'sini kullanabilirsiniz. Genel bir kural olarak, aşağıdaki durumlarda masaüstü uygulamaları için C++ kullanmanızı öneririz:

- bellek kullanımı üzerinde hassas kontrol
- güç tüketiminde en yüksek ekonomi
- genel bilgi işlem için GPU kullanımı
- DirectX'e erişim
- standart C++ kitaplıklarının yoğun kullanımı

C++'ın gücünü ve verimliliğini .NET programlama ile birleştirmek de mümkündür. C#'ta bir kullanıcı arabirimi oluşturabilir ve uygulamanın yerel C++ kitaplıklarını kullanmasını sağlamak için C++/CLI kullanabilirsiniz. Daha fazla bilgi için, bkz . C++/CLI ile .NET Programlama .

## COM Components
Bileşen Nesne Modeli (COM) farklı dillerde yazılmış programları birbirleriyle iletişim kurmasını sağlayan bir özelliktir. Birçok Windows bileşeni, COM nesneleri olarak uygulanır ve nesne oluşturma, arabirim keşfi ve nesne yok etme için standart COM kurallarını takip eder. C++ masaüstü uygulamalarından COM nesnelerini kullanmak nispeten basittir, ancak kendi COM nesnenizi yazmak daha ileri düzeydedir. Active Template Library (ATL) makro ve yardımcı işlevlerini basitleştirmek COM geliştirme öngörmektedir. Daha fazla bilgi için bkz. ATL COM masaüstü bileşenleri .

## Universal Windows Platform apps
Evrensel Windows Platformu (UWP), modern Windows API'sidir. UWP uygulamaları herhangi bir Windows 10 cihazında çalışır, kullanıcı arabirimi için XAML kullanır ve tamamen dokunmatik özelliklidir. UWP hakkında daha fazla bilgi için bkz. Evrensel Windows Platformu (UWP) uygulaması nedir? ve Windows Evrensel Uygulamaları Kılavuzu .

UWP için orijinal C++ desteği (1) C++/CX, sözdizimi uzantılarına sahip bir C++ lehçesi veya (2) standart C++ ve COM'a dayalı Windows Çalışma Zamanı Kitaplığı'ndan (WRL) oluşuyordu. Hem C++/CX hem de WRL hala desteklenmektedir. Yeni projeler için, tamamen standart C++ tabanlı ve daha hızlı performans sağlayan C++/WinRT'yi öneriyoruz .

## Desktop Bridge
Windows 10'da, mevcut masaüstü uygulamanızı veya COM nesnenizi bir UWP uygulaması olarak paketleyebilir ve modern Windows API kümesinden dokunma veya çağrı API'leri gibi UWP özellikleri ekleyebilirsiniz. Ayrıca Visual Studio'daki bir masaüstü çözümüne bir UWP uygulaması ekleyebilir ve bunları tek bir pakette paketleyebilir ve aralarında iletişim kurmak için Windows API'lerini kullanabilirsiniz.

Visual Studio 2017 sürüm 15.4 ve sonraki sürümleri, mevcut masaüstü uygulamanızı paketleme işini büyük ölçüde basitleştirmek için bir Windows Uygulama Paketi Projesi oluşturmanıza olanak tanır. Masaüstü uygulamanızın kullanabileceği kayıt defteri çağrıları veya API'ler için birkaç kısıtlama geçerlidir. Ancak çoğu durumda, bir uygulama paketinde çalışırken benzer işlevsellik elde etmek için alternatif kod yolları oluşturabilirsiniz. Daha fazla bilgi için bkz. Masaüstü Köprüsü .

## Games
DirectX oyunları PC veya Xbox'ta çalışabilir. Daha fazla bilgi için bkz. DirectX Graphics and Gaming .

## SQL Server database client
SQL Server veritabanlarına yerel koddan erişmek için ODBC veya OLE DB kullanın. Daha fazla bilgi için bkz. SQL Server Native Client .

## Windows device drivers
Sürücüler, donanım aygıtlarındaki verileri uygulamalar ve diğer işletim sistemi bileşenleri için erişilebilir hale getiren düşük düzeyli bileşenlerdir. Daha fazla bilgi için bkz. Windows Sürücü Seti (WDK) .

## Windows services
Windows hizmeti , çok az veya hiç kullanıcı etkileşimi olmadan arka planda çalışabilen bir programdır. Bu programlara UNIX sistemlerinde arka plan programı denir . Daha fazla bilgi için bkz. Hizmetler .

## SDKs, libraries, and header files
Visual Studio, C Çalışma Zamanı Kitaplığı (CRT), C++ Standart Kitaplığı ve Microsoft'a özgü diğer kitaplıkları içerir. Bu kitaplıklar için başlık dosyalarını içeren içerme klasörlerinin çoğu, Visual Studio yükleme dizininde \VC\ klasörü altında bulunur. Windows ve CRT başlık dosyaları, Windows SDK yükleme klasöründe bulunur.

vcpkg paket yöneticisi, Windows için yüzlerce üçüncü taraf açık kaynak kitaplığını kolayca yüklemenize olanak tanır. Daha fazla bilgi için bkz. vcpkg .

Microsoft kitaplıkları şunları içerir:

- Microsoft Foundation Classes (MFC): Düğmeler, liste kutuları, ağaç görünümleri ve diğer denetimleri içeren zengin kullanıcı arabirimlerine sahip geleneksel Windows programları, özellikle kurumsal uygulamalar oluşturmak için nesne yönelimli bir çerçeve. Daha fazla bilgi için bkz. MFC Masaüstü Uygulamaları .

- Etkin Şablon Kitaplığı (ATL): COM bileşenleri oluşturmak için güçlü bir yardımcı kitaplık. Daha fazla bilgi için bkz. ATL COM Masaüstü Bileşenleri .

- C++ AMP (C++ Accelerated Massive Parallelism): GPU üzerinde yüksek performanslı genel hesaplamalı çalışmayı sağlayan bir kitaplık. Daha fazla bilgi için bkz. C++ AMP (C++ Accelerated Massive Parallelism) .

- Eşzamanlılık Çalışma Zamanı: Çok çekirdekli ve çok çekirdekli aygıtlar için paralel ve eşzamansız programlama çalışmalarını basitleştiren bir kitaplık. Daha fazla bilgi için bkz. Eşzamanlılık Çalışma Zamanı .

Birçok Windows programlama senaryosu, Windows işletim sistemi bileşenlerine erişim sağlayan başlık dosyalarını içeren Windows SDK'sını da gerektirir. Varsayılan olarak Visual Studio, Windows SDK'yı Evrensel Windows uygulamalarının geliştirilmesine olanak tanıyan C++ Masaüstü iş yükünün bir bileşeni olarak yükler. UWP uygulamaları geliştirmek için Windows SDK'nın Windows 10 sürümüne ihtiyacınız vardır. Bilgi için bkz. Windows 10 SDK . (Windows'un önceki sürümleri için Windows SDK'ları hakkında daha fazla bilgi için Windows SDK arşivine bakın ).

Program Files (x86)\Windows Kits , yüklediğiniz tüm Windows SDK sürümleri için varsayılan konumdur.

Xbox ve Azure gibi diğer platformların, yüklemeniz gerekebilecek kendi SDK'ları vardır. Daha fazla bilgi için DirectX Geliştirici Merkezi ve Azure Geliştirici Merkezi'ne bakın.

## Development Tools
Visual Studio, yerel kod için güçlü bir hata ayıklayıcı, statik analiz araçları, grafik hata ayıklama araçları, tam özellikli bir kod düzenleyici, birim testleri için destek ve diğer birçok araç ve yardımcı program içerir. Daha fazla bilgi için, bkz Visual Studio ile geliştirme işlemine başlayın ve bakış Visual Studio C ++ geliştirme .

## C++ Programming Overview Tree
---

* [Walkthrough: Creating a Standard C++ Program](walkthrough-creating-a-standard-cpp-program-cpp.md)
* [Walkthrough: Creating Windows Desktop Applications (C++)](walkthrough-creating-windows-desktop-applications-cpp.md)
* [Windows Desktop Wizard](windows-desktop-wizard.md)
* [Active Template Library (ATL)](../cpp/atl/atl-com-desktop-components.md)
* [Microsoft Foundation Classes (MFC)](../cpp/mfc/mfc-desktop-applications.md)
* [ATL and MFC Shared Classes](../atl-mfc-shared/atl-mfc-shared-classes.md)
* [Data Access](../data/data-access-in-cpp.md)
* [Text and Strings](../text/text-and-strings-in-visual-cpp.md)
* [Resources for Creating a Game Using DirectX](resources-for-creating-a-game-using-directx.md)
* [How to: Use the Windows 10 SDK in a Windows Desktop Application](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)
* [Working with Resource Files](working-with-resource-files.md)
* [Resources for Creating a Game Using DirectX (C++)](resources-for-creating-a-game-using-directx.md)
* [How to: Use the Windows 10 SDK in a Windows Desktop Application](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)
* [Deploying Native Desktop Applications](deploying-native-desktop-applications-visual-cpp.md)</br>
More About <https://docs.microsoft.com/en-us/cpp/windows/desktop-applications-visual-cpp?view=msvc-160>
