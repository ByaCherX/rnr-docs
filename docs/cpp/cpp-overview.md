---
title: "C++ Overview Programming"
description: "It provides an overview of C++ and what topics it is."
ms.custom: "alt-page"
ms.date: "08/07/2021"
helpviewer_keywords: ["cpp overview programming", "cpp-overview, cpp-programming-overview"]
ms.assetid: 03f9efff-bb95-45ef-9157-0a3fac809ccf
---
<style>h2orange{color:#e68a00}h4blue{color:#3399ff}</style>

<h1 style="text-align:center">Overview C++</h1>

**C++ Standart Kütüphanesi** olan string C++, iki tür karakter dizini sunar -string sınıf nesleri (3. Ünitede) ve C karakter dizinleri C karakter dizinlerinin güvenlik problemlerinin büyük bölümünü ortadan kaldırmak ve daha sağlam programlar yapmak için C karakter dizinlerini birçoğu C++ string sınıfının örnekleri ile yer değiştirdik Sanayideki karşılaşacağınız eski kodlar ile çalışmaya sizi hazırlamak için, ilerleyen bölümlerde C karakter dizinlerini tartışmaya devam edeceğiz. Yeni geliştirmelerde string nesnelerini değerlendirmelisiniz

<h2><h2orange>UML™  (Unified Modelling Language™)<h2orange></h2>

UML (Birleşmiş Modelleme Dili), nesneye dayalı sistemleri modellemek için kullanılan endüstriyel standartlarda bir grafik dilidir. UML'e ilk ünitelerde giriş yapıyoruz.

• İstisna işleme. dökümanın başlarında temel istisna işlemeyi inceliyoruz Eğitmenler, 17. Ünite olan İstisna İşleme: Derin Bir Bakış isimli üniteden daha detaylı müfredat edinebilirler.

• İsteğe bağlı şablon veri yapıları. Veri yapıları için zengin. Çok ünitede işlenen bir içerik sunuyoruz -bağımlılık ç,zelgesinde Veri Yapıları mödülüne bakın.

• Üç adet programlama paradigması. Yapısal programlama, nesneye dayalı programlama ve genel programlamayı tartışıyoruz.

---

C++ günümze en popüler yazılım geliştirme dillerinde birisidir. Bu doküman Uluslararası Standart Organizasyonu (ISO) ve Uluslararası Elektroteknik Komisyonu (IEC) tarafından standartlaştırılmıştır. C++ 11 sürümüne giriş yapmaktadır.

---

<h2><h2orange>Moore Yasası<h2orange></h2>

Moore Yasası, Intel şirketinin kurucularından Gordon Moore'un 19 Nisan 1965 yılında Electronics Magazine dergisinde yayınlanan makalesi ile teknoloji tarihine kendi adıyla geçen yasa.

Her 18 ayda bir tümleşik devre üzerine yerleştirilebilecek bileşen sayısının iki katına çıkacacağını, bunun bilgisayarların işlem kapasitelerinde büyük artışlar yaratacağını, üretim maliyetlerinin ise aynı kalacağını, hatta düşme eğilimi göstereceğini öngören deneysel (ampirik) gözlem.

1965 yılında, "mikroişlemciler içindeki transistör sayısı her yıl iki katına çıkacaktır" diyen Moore, daha sonraları 1975 yılında bu öngörüsünü güncellemiş ve her iki yılda bir iki katına çıkacak şekilde düzeltmiştir. Moore "18 ayda bir" ifadesinin de kendisi tarafından söylenmediği konusunda da ısrar etmiştir. Kendisi tarafından hiçbir zaman yasa olarak tanımlanmayan ifadesi, Kalifornia Teknoloji Üniversitesi profesörü ve yüksek ölçekli indirgeme konusunun öncülerinden biri olan Carver Mead tarafından bu şekilde adlandırılmıştır.

Sözün ilk söylendiği 1965 yılından bu yana bu yasa çoğunlukla geçerli olmuştur. Yasa temel olarak bir tümleşik devrenin fiziki boyutunun devreyi oluşturan transistör sayısının karesiyle değiştiği anlamına gelir. Örneğin tümleşik devre bünyesindeki transistör sayısı iki katına çıkarsa devrenin boyutu dört katına çıkar.

Optik litografi yöntemi ile üretilen tümleşik devrelerde günümüzde silisyum yongalar üzerinde 65 nanometre (1 nanometre = 10−9m) boyutuna kadar büyüklüklerde, yani yaklaşık olarak 600 silisyum atomu boyutunda yapılar oluşturulabilmektedir. Kullanılan morötesi ışık dalga boylarının, atom fiziksel boyutlarının sınırlılığı ve küçük yapıların yüksek frekanslarda çalıştırılmasında ortaya çıkan çalışma düzensizlikleri, yeni bir tümleşik devre teknolojisi geliştirilemez ise Moore yasasının kısa bir süre içerisinde geçerliliğini yitireceğini göstermektedir.

<h2><h2orange>Bilgisayar Organizasyonu<h2orange></h2>

|||
|-----|-----|
|Giriş Birimi|	Giriş birimi giriş cihazlarından aldığı bilgileri (veri ve bilgisayar programcıları) işleyecek diğer bir birime bırakır. Bilgisayarlara çoğu bilgi klavye, dokunmatik ekran veya fare gibi cihazlarr üzerinden gelmektedirler. Diğer veri girişi türleri ses komutları, tarama görüntüleri ve barkodlar, ikincil diskler (sabit disk, DVD sürücüleri, USB flash sürücüleri) web kameraları ve internettir.|
|Çıkış Birimi|	Bu birimin görevi bilgisayarın işlediği verileri alıp kullanıcısının erişebileceği çıkış cihazlarına yerleştirmektedir. Günümüzde bilgisayarlardan çıkan veriler ekran üzerinde görüntülenebilir. Kağıda yazılabilir.|
|Hafıza Birimi| 	Hafıza birimi giriş biriminden gelen verileri saklandığı ve sahip olduğu verilere hızlı erişim imkanı tanıyan düşük kapasiteli "depo" birimidir. İşlenmesi istenen verinin hızlı bir şekilde erişilmesine imkan verir.|
|Aritmetik ve Mantıksal Birim (ALU)|	Bu birimin görevi toplama, çıkarma çarpma ve bölme gibi hesaplamaları gerçekleştirmektedir. Ayrıca hafıza birimindeki iki verinin eşit olup olmadağına karar verme gibi mantıksal karalarda bu birimde verilmektedir. ALU genelde CPU'nun bir parçası olarak geliştirilmektedir.|
|Merkezi İşlem Birimi (CPU)	|Bu yönetici birimi diğer birimlerin opersayonlarını koordine etmekle görevlidir. CPU, giriş birimine verilen ne zaman hafıza birimine yükleneceğini ALU biriminde hafıza birimindeki verilerin ne zaman çıkış yapıp işleneceğine karar verir.|
|İkincil Saklama Birimi|Bu birim uzun ömürlü ve yüksek kapasiteli depo birimidir. Diğer birimler tarafından aktif olarak kullanılmayan verilerin ve programların, ihtiyaç duyulana kadar saklanması için ikincil saklanma birimine yerleştirilirler.|

<h2><h2orange>Makine Dilleri, Sembolik Diller ve Yüksek Seviyeli Diller<h2orange></h2>

Programcılar farklı programlama dillerini kullanarak komutlarını yazabilirler. Kimi diller bilgisayar tarafından direk anlaşılırken kimilerinin çeviriciye ihtiyacı vardır. 

<h4><h4blue>Makine Dilleri<h4blue></h4>
Her bilgisayar sadece kendi donanım mimarisi tarafından tanımlanmış olan makine dilini (Makine kodu olarak da adlandırılır) anlayabilir. Makine dilleri genelde sayılardan oluşmaktadır. (0 ve 1'ler) Bu tip dillerin insanlar tarafından kullanılması oldukça zordur.

<h4><h4blue>Sembolik Diller<h4blue></h4>
Makine dillerinde programlamak, programcılar için oldukça zor ve yavaştır. Bunun yerine her bir operasyonu temsil etmek için İngilizce kısaltmalar kullanılmaya başlanmıştır. Bu kısaltmalar sembolik dillerin temelini oluşturmuştur. Assembler adı verilen çevirici programlar sembolik dilde yazılan programları makine dillerine çevirmek için geliştirilmiştir. Sembolik diller insanlar için daha anlaşılır olsalar da, makine diline çevirilne kadar bilgisayarlar için anlamsızdır.

<h4><h4blue>Yüksek Seviyeli Diller<h4blue></h4>
Programlama sürecini daha da hızlandıracak ve bir ifade ile önemli görevleri gerçekleştirebilecek yüksek seviyeli programlama dilleri geliştrimiştir. C++, Java, C# ve Visual Basic gibi yüksek seviyeli dillerde yazılan komutlar her gün kullanılan İngilizceye ve yapılan hesaplamalar sıkça kullanılan matematiksel ifadelere benzemektedir. Derleyici adı verilen programlar yüksek seviyeli dillerde yazılan programları makine diline çevirmektedir.
Yüksek seviyeli dilde yazılmış bir programı makine diline çevirme işlemi bilgisayarın oldukça fazla zamanı alabilir. Yorumlayıcı programlar yüksek seviyeli programları direk çalıştırabilmek için geliştirilmiştir. Bu sayede derleme işlemine ihtiyaç duyulmamaktadır. Fakat bu programlar derlenmiş programlardan daha yavaş çalışmaktadır. JavaScript ve PHP gibi popüler script diller yorumlayıcılar tarafından işletilmektedir.

<h2><h2orange>Programming Languages<h2orange></h2>

|Language|Explain|
|---|---|
|**Fortran**|Fortran (FORmula TRANslator) IBM tarafından 1950'li yıllarda kompleks matematiksel hesaplamaların kullanıldığı bilimsel ve mühendislik uygulamaları geliştirmek için tasarlanmıştır. Hala bir çok programcı tarafından kullanılmaktadır. Ve son sürümü nesneye dayalı programlamayı desteklemektedir. |
|**COBOL**|COBOL (Common Business Oriented Leanguage) 1950'li yılların sonunda bilgisayar üreticileri, ABD hükümeti ve sanayi bilgisayar kullanıcıları tarafından Grace Hopper'ın geliştirdiği bir dil temel alınarak geliştirilmiştir.|
|**Pascal**|1960'lı yıllarda yapılan bir araştırma yapısal programlama ile sonuçlanmıştır. Yapısal programlama, önceki tekniklere göre daha açık, kolay test edilip değiştirilebilen programlar yazılmasına imkan sağlayan bir programlama tekniğidir.|
|**Basic**|Basic, öğrencileri programlama teknikleri hakkında bilgilerndirmek için Dartmouth Kolejinde 1960'lı yıllarda geliştirmiştir.|
|**C**|C programlama dili Bell laboratuvarlarında Dennis Ritchie tarafından 1972 yılında geliştirildi. Başlangıçta bütün çevrelerce UNIX işletim sisteminin geliştirme dili olarak tanınmıştır. Günümüzde genel amaçlı işletim sistemlerinin büyük bir bölümü C ve C++ programlama dilleri ile yazılmaktadır.|
|**Java**|Sun Microsystem, 1991 yılında James Gosling tarafından yürütülen şirket içi bir projeyi başlatmıştır. Proje sonucunda C++ dili temel alınarak geliştirilen nesneye yönelik bir programlama dili olan Java ortaya çıkmıştır. Java programlama dilinin temel amacı çok farklı bilgisayar sistemlerinde ve bilgisayar ile kontrol edilen cihazlarda çalışabilecek programlar yazabilmektir. Java ayrıca Android tabanlı akıllı telefon ve tabletler için uygulama geliştirmek için kullanılmaktadır.|
|**Visual Basic**|Microsoft tarafından Windows işletim sistemine uygulama yazmayı basitleştirmek için 1990'lı yılların başında geliştirilmiştir. Son sürümü nesneye yönelik programlama desteklemektedir.|
|**C#**|C# programlama dili C++ ve java dillerini temel alarak internet ve web'i bir bilgisayar uygulamasında birleştirmek için Microsoft tarafından geliştirilmiştir. Nesneye yönelik programlamayı desteklemektedir.|
|**PHP**|PHP, bir kullanıcı ve programcı komitesi tarafından desteklenen açık kaynaklı nesneye yönelimli "betikleyici" bir dildir. Wikipedia ve Facebook gibi bir çok web sitesi tarafından kullanılmaktadır. PHP platformdan bağımsız çalışabilmektedir. UNIX, Linux, Mac ve Windows işletim sistemleri için gerçekleştirimi bulanmaktadır. PHP, MySQL gibi birçok veri tabanını da desteklemektedir.|
|**Phyton**|1991 yılında piyasaya sürülen Phyton nesneye yönemli bir betik dilidir. Amsterdam'daki Matematik ve Bilgisayar bilimleri için Ulusal araştırma ensitüsünde Guido ban Rossum tarafından geliştirilmiştir.Phyton bir sistem programlama dili olan Modula-3'ü örnek almıştır. Phyton sınıf ve programlama ara yüzleri kullanılarak genişletilebilmektedir.|
|**JavaScript**|JavaScript günümüzde en çok kullanılan betik dilidir. Temel amacı web sayfalarına programlanabilirlik eklemektedir. Örneğin kullanıcı etkileşimi ve animasyon. Bütün büyük web tarayıcıları tarafından desteklenmektedir.|

<h2><h2orange>Software Development Terms<h2orange></h2>

| Temrs | Explain |
|-------|----------|
| **Ajax** |Ajax Web 2.0 yazılım teknolojisinin en önemli parçalarından birisidir. Ajax internet uygulamalarının masaüstü uygulaması gibi davranmasını sağlamaktadır. Web uygulamalarında verinin internet üzerinde gedip geldiği düşünüldüğünde zor bir görev üstlendiği açıktır.|
| **Çevik yazılım geliştirme** |Çevik yazılım geliştirme, önceki yöntemlere göre daha az kaynak kullanıp daha hızlı yazılım üretmeyi amaçlayan bir yöntemler bütünüdür. Daha fazla bilgi için Agile Alliance (www.agilealliance.org)|
| **Yeniden Düzenleme** |Yeniden düzenleme, var olan programların doğruluğunu ve fonksiyonelliklerini bozmadan daha basit ve açık hale getirmektedir. Çevik yazılım geliştirme teknikleri ile sıkça kullanılmaktadır. Bir çok IDE programı içersinde yeniden düzenleme aracı barındırmaktadır. |
| **Tasarım Desenleri** |Tasarım desenleri esnek ve kontrol edilebilir neseneye dayalı yazlımların geliştirmesi için sıkça kullanılan mimarilerdir. Tasarım desenlerindeki temel amaç tekrar eden problemlere iyi sonuç verdiği bilinen tasarımları uygulayarak daha kaliteli yazılımları daha az zaman ve para harcarayak geliştirmektedir.|
| **LAMP** |LAMP kısaltması programcıların web uygulaması geliştirmesi için kullandıkları açık kaynaklı bazı teknolojilerin baş harflerinin birleştirilmesi ile oluşturulmuştur. Linux, Apache, MySQL ve PHP isimlerinin baş harfleri alınarak kısaltma oluşturulmuştur. MySQL açık kaynaklı veri tabanı yönetim sistemidir. PHP ise sunucu taraflı çalışan en mehşur açık kaynaklı internet betimleme dilidir.|
| **Bir Servis olarak Yazılım (SaaS)** |Yazılım genelde bir ürün olarak düşünülmektedir. Eğer bir uygulamayı çalıştırmak istiyorsunuz öncelikle yazılımı üretici firmadan satın almanız ve bilgisayarınıza kurmanız gerekir. Yazılımların yeni sürümleri çıktığından ihtiyaca göre yazlımın güncellenmesi gerekir. On binlerce sistemin bulunduğu organizasyonlarda bu işlemler oldukça güçlük çıkarmaktadır. Bir servis olarak yazılım ile programlar internet üzerinden erişilebilen sunucularda çalışırlar. Sunucudaki programlar güncellendiğinde dünya etrafındaki bütün kullanıcılar güncellenmis uygulamayı kullanabilecektir. Yerel kuruluma ihtiyaç yoktur. Servislere tarayıcılar aracılığıyla erişebilirsiniz Tarayıcıların taşınabilirliği oldukça yüksektir. Bu sayede bir çok farklı makinede aynı uygulamayı çalıştırabilirsiniz.|
| **Bir Servis olarak Platform (PaaS)** |Bir servis olarak Platform, bulut işlemin diğer bir yeteneğidir. Uygulama geliştirme veya çalıştırma platformlarını bir web servisi şeklinde kullanıcıların hizmetine sunmaktadır. Bu sayede kullanıc gerekli araçları bilgisayarına kurmadan kullanabilmektedir. Popüler PaaS servisleri Google App Engine, Amazon EC2 ve Bungee Labs.|
| **Software Development Kit (SDK)** |Yazılım Geliştirme Takımı, programcıların uygulamayı kullanabilmeleri için verileri doküman ve araçları kapsamaktadır.|

<h2><h2orange>Software Versions and Software Technologies<h2orange></h2>

| Version | Explain |
|---------|---------|
| **Alfa** |Hata geliştirmekte olan bir yazılım ürünün ilk sürümüne alfa sürümünü adı verilir. Alfa sürümlerinin hata oranı oldukça yüksektir. Ayrıca program tamlanmamıştır ve dengesizdir. Genelde çok az sayıdaki geliştiriciye sadece yeni özellikleri test etmeleri için verilmektedir.
| **Beta** |Beta sürümünü programın içersindeki çoğu hata giderilip program tamamlanma aşamasına oldukça yakın piyasaya sürülmektedir. Genelde çok büyük bir geliştirici kitlesine verilmektedir. Beta yazlımlar daha kararlıdır fakat hala değişime açıktır.
| **Exit in Candidate** |Çıkış Adayları genelde bütün özellikleri tamalanmış ve hatalardan arındırılmış sürümlerdir. Toplum tarafından kullanılmaya ve detaylı teste hazırdırlar. Toplum tarafından kullanılmaya ve detaylı teste hazırdırlar. Yazlım farklı sistemlerde farklı kısıtlar içersinde çalıştırılmaktadır. Bu sırada bulunan hatalar düzeltilir. Ve son sürüm piyasaya çıkartılır. Yazılım firmaları ürünleri için genelde güncellemeler paylaşırlar.
| **Beta in Progress** |Bu yaklaşımla geliştirilen yazlımların bir sürüm numarası yoktur. (örneğin Google search veya Gmail) Bulut üzerine yerleştirilmiş yazlım sürekli olarak geliştirilmektedir. Kullanıcılar ise devamlı son sürümü kullanmaktadır.

</br1>








