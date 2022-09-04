<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<h1 style="text-align:center">Pro Git Book</h1>

Bu bölüm Git'i kullanmaya başlama hakkında olacak. Sürüm kontrol araçları hakkında bazı arka planlar açıklayarak başlayacağız, ardından Git'in sisteminizde nasıl çalıştırılacağına ve son olarak çalışmaya başlamak için nasıl kurulacağına geçeceğiz. Bu bölümün sonunda Git'in neden buralarda olduğunu, neden kullanmanız gerektiğini anlamalı ve bunu yapmak için hazır olmalısınız.

## About Version Control
“Sürüm kontrolü” nedir ve neden önemsemelisiniz? Sürüm kontrolü, belirli sürümleri daha sonra geri çağırabilmeniz için bir dosyada veya dosya kümesinde zaman içinde yapılan değişiklikleri kaydeden bir sistemdir. Bu kitaptaki örnekler için, sürüm kontrollü dosyalar olarak yazılım kaynak kodunu kullanacaksınız, ancak gerçekte bunu bir bilgisayardaki hemen hemen her tür dosyayla yapabilirsiniz.

Bir grafik veya web tasarımcısıysanız ve bir görüntünün veya düzenin her sürümünü (ki bunu kesinlikle istersiniz) saklamak istiyorsanız, Sürüm Kontrol Sistemi (VCS) kullanmak çok akıllıca bir şeydir. Seçilen dosyaları önceki bir duruma geri döndürmenize, tüm projeyi önceki bir duruma döndürmenize, zaman içindeki değişiklikleri karşılaştırmanıza, soruna neden olabilecek bir şeyi en son kimin değiştirdiğini, kimin bir sorunu ne zaman ortaya çıkardığını ve daha fazlasını görmenizi sağlar. Bir VCS kullanmak, aynı zamanda, genel olarak, işleri batırırsanız veya dosyaları kaybederseniz, kolayca kurtarabileceğiniz anlamına gelir. Ayrıca, tüm bunları çok az bir ek yük için alırsınız.

### Local Version Control Systems
Birçok kişinin tercih ettiği sürüm kontrol yöntemi, dosyaları başka bir dizine kopyalamaktır (akıllıysa, belki zaman damgalı bir dizine). Bu yaklaşım çok basittir çünkü çok basittir, ancak aynı zamanda inanılmaz derecede hataya açıktır. Hangi dizinde olduğunuzu unutmak ve yanlışlıkla yanlış dosyaya yazmak veya istemediğiniz dosyaları kopyalamak kolaydır.

Bu sorunla başa çıkmak için, programcılar uzun zaman önce, dosyalardaki tüm değişiklikleri revizyon kontrolü altında tutan basit bir veritabanına sahip yerel VCS'ler geliştirdiler.

:::image type="content" source="../media/git-local-version.png" alt-text="git-local":::

En popüler VCS araçlarından biri, bugün hala birçok bilgisayarla dağıtılan RCS adlı bir sistemdi. RCS, yama setlerini (yani dosyalar arasındaki farkları) diskte özel bir biçimde tutarak çalışır; daha sonra tüm yamaları ekleyerek herhangi bir zamanda herhangi bir dosyanın nasıl göründüğünü yeniden oluşturabilir.

### Centralized Version Control Systems
İnsanların karşılaştığı bir sonraki büyük sorun, diğer sistemlerdeki geliştiricilerle işbirliği yapmaları gerektiğidir. Bu sorunla başa çıkmak için Merkezi Sürüm Kontrol Sistemleri (CVCCS'ler) geliştirilmiştir. Bu sistemler (CVS, Subversion ve Perforce gibi), tüm sürümlü dosyaları içeren tek bir sunucuya ve bu merkezi yerden dosyaları teslim alan birkaç istemciye sahiptir. Uzun yıllar boyunca bu, sürüm kontrolü için standart olmuştur.

:::image type="content" source="../media/git-centralized-vcs-server.png" alt-text="git-centralized":::

Bu kurulum, özellikle yerel VCS'lere göre birçok avantaj sunar. Örneğin, projedeki diğer herkesin ne yaptığını herkes bir dereceye kadar bilir. Yöneticiler, kimin ne yapabileceği konusunda hassas bir denetime sahiptir ve bir CVCS'yi yönetmek, her istemcide yerel veritabanlarıyla uğraşmaktan çok daha kolaydır.

Bununla birlikte, bu kurulumun bazı ciddi dezavantajları da vardır. En belirgin olanı, merkezi sunucunun temsil ettiği tek başarısızlık noktasıdır. Bu sunucu bir saatliğine çökerse, o saat boyunca hiç kimse işbirliği yapamaz veya üzerinde çalıştıkları herhangi bir şeye sürümlü değişiklikleri kaydedemez. Merkezi veritabanının bulunduğu sabit disk bozulursa ve uygun yedeklemeler tutulmadıysa, kesinlikle her şeyi kaybedersiniz - insanların yerel makinelerinde sahip oldukları tek anlık görüntüler dışında projenin tüm geçmişi. Yerel VCS'ler de aynı sorundan muzdariptir - projenin tüm geçmişi tek bir yerde olduğunda, her şeyi kaybetme riskiyle karşı karşıya kalırsınız.

### Dağıtılmış Versiyon Kontrol Sistemleri
Dağıtılmış Sürüm Kontrol Sistemleri (DVCS'ler) burada devreye girer. Bir DVCS'de (Git, Mercurial, Bazaar veya Darcs gibi), istemciler yalnızca dosyaların en son anlık görüntüsünü kontrol etmez; bunun yerine, tam geçmişi de dahil olmak üzere depoyu tamamen yansıtırlar. Bu nedenle, herhangi bir sunucu ölürse ve bu sistemler bu sunucu aracılığıyla işbirliği yapıyorsa, istemci havuzlarından herhangi biri onu geri yüklemek için sunucuya geri kopyalanabilir. Her klon, tüm verilerin gerçekten tam bir yedeğidir.

:::image type="content" source="../media/git-distributed.png" alt-text="git-distributed":::

Ayrıca, bu sistemlerin birçoğu, birlikte çalışabilecekleri birkaç uzak havuza sahip olmakla oldukça iyi başa çıkıyor, böylece aynı proje içinde farklı insan gruplarıyla farklı şekillerde aynı anda işbirliği yapabilirsiniz. Bu, hiyerarşik modeller gibi merkezi sistemlerde mümkün olmayan çeşitli iş akışı türlerini ayarlamanıza olanak tanır.

## What is Git ?
Peki, kısaca Git nedir? Bu, özümsenmesi gereken önemli bir bölümdür, çünkü Git'in ne olduğunu ve nasıl çalıştığının temellerini anlarsanız, Git'i etkili bir şekilde kullanmak muhtemelen sizin için çok daha kolay olacaktır. Git'i öğrenirken, CVS, Subversion veya Perforce gibi diğer VCS'ler hakkında bilebileceğiniz şeylerden zihninizi temizlemeye çalışın - bunu yapmak, aracı kullanırken ince kafa karışıklığından kaçınmanıza yardımcı olacaktır. Git'in kullanıcı arayüzü bu diğer VCS'lere oldukça benzer olsa da, Git bilgileri çok farklı bir şekilde saklar ve düşünür ve bu farklılıkları anlamak, onu kullanırken kafanızın karışmasını önlemenize yardımcı olur.

### Git Has Integrity
Git'teki her şey, saklanmadan önce sağlama toplamıdır ve daha sonra bu sağlama toplamı tarafından başvurulur. Bu, Git'in haberi olmadan herhangi bir dosya veya dizinin içeriğini değiştirmenin imkansız olduğu anlamına gelir. Bu işlevsellik Git'te en düşük seviyelerde yerleşiktir ve felsefesinin ayrılmaz bir parçasıdır. Git tarafından algılanmadan aktarım sırasında bilgileri kaybedemez veya dosya bozulması elde edemezsiniz.

Git'in bu sağlama toplamı için kullandığı mekanizmaya SHA-1 karma adı verilir. Bu, onaltılık karakterlerden (0–9 ve a–f) oluşan ve Git'teki bir dosya veya dizin yapısının içeriğine göre hesaplanan 40 karakterlik bir dizedir. Bir SHA-1 karması şuna benzer:

``24b9da6552252987aa493b52f8696cd6d3b00373``

Git'te bu hash değerlerini çok fazla kullandığı için her yerde göreceksiniz. Aslında Git, veritabanındaki her şeyi dosya adına göre değil, içeriğinin karma değerine göre depolar.

## Getting a Git Repository

### Initializing a Repository in an Existing Directory
Halihazırda sürüm kontrolü altında olmayan bir proje dizininiz varsa ve onu Git ile kontrol etmeye başlamak istiyorsanız, önce o projenin dizinine gitmeniz gerekir. Bunu hiç yapmadıysanız, çalıştırdığınız sisteme bağlı olarak biraz farklı görünür</br>
``$ cd C:/Users/user/my_project``

Bu, .gitgerekli tüm depo dosyalarınızı içeren bir Git deposu iskeleti adında yeni bir alt dizin oluşturur. Bu noktada, projenizdeki hiçbir şey henüz izlenmedi. Yeni oluşturduğunuz dizinde tam olarak hangi dosyaların bulunduğu hakkında daha fazla bilgi için Git Internals'a bakın .git.

Mevcut dosyaların sürüm kontrolüne başlamak istiyorsanız (boş bir dizinin aksine), muhtemelen bu dosyaları izlemeye başlamalı ve bir ilk taahhütte bulunmalısınız. Bunu, git addizlemek istediğiniz dosyaları belirten birkaç komutla ve ardından bir git commit:

``$ git add *.c``</br>
``$ git add LICENSE``</br>
``$ git commit -m 'Initial project version'``

### Cloning an Existing Repository
Mevcut bir Git deposunun bir kopyasını almak istiyorsanız - örneğin katkıda bulunmak istediğiniz bir proje - ihtiyacınız olan komut ``git clone``. Subversion gibi diğer VCS'lere aşina iseniz, komutun "checkout" değil "clone" olduğunu fark edeceksiniz. Bu önemli bir ayrımdır — sadece çalışan bir kopya almak yerine Git, sunucunun sahip olduğu neredeyse tüm verilerin tam bir kopyasını alır. Proje geçmişi için her dosyanın her sürümü, çalıştırdığınızda varsayılan olarak aşağı çekilir ``git clone`` Aslında, sunucu diskiniz bozulursa, sunucuyu klonlandığı zamanki durumuna geri ayarlamak için herhangi bir istemcideki klonların neredeyse herhangi birini kullanabilirsiniz (bazı sunucu tarafı kancalarını ve benzeri şeyleri kaybedebilirsiniz, ancak tüm sürümlendirilmiş veriler orada olacaktır.

Git'in kullanabileceğiniz bir dizi farklı aktarım protokolü vardır. örnek https://protokolü kullanır , ancak SSH aktarım protokolünü kullanan git://veya öğesini de görebilirsiniz user@server:path/to/repo.git. Git'i bir Sunucuya almak , sunucunun Git deponuza erişmek için ayarlayabileceği tüm mevcut seçenekleri ve her birinin artılarını ve eksilerini tanıtacaktır.

### Checking the Status of Your Files
Hangi dosyaların hangi durumda olduğunu belirlemek için kullandığınız ana araç git statuskomuttur. Bu komutu doğrudan bir klondan sonra çalıştırırsanız, şöyle bir şey görmelisiniz:</br>
``$ git status``

### Committing Your Changes
Artık hazırlama alanınız istediğiniz gibi ayarlandığına göre, değişikliklerinizi gerçekleştirebilirsiniz. Hala sahnelenmemiş olan herhangi bir şeyin - oluşturduğunuz veya değiştirdiğiniz ve git addonları düzenlediğinizden beri çalıştırmadığınız herhangi bir dosyanın - bu işleme girmeyeceğini unutmayın. Diskinizde değiştirilmiş dosyalar olarak kalacaklar. Bu durumda, diyelim ki en son koştuğunuzda git status, her şeyin sahnelendiğini gördünüz, bu yüzden değişikliklerinizi yapmaya hazırsınız. Taahhüt etmenin en basit yolu şunu yazmaktır git commit:</br>
``$ git commit``

> [!TIP]
Alternatif olarak, aşağıdaki gibi commit bir ``-m`` bayraktan sonra belirterek taahhüt mesajınızı komutla satır içi olarak yazabilirsiniz:</br>
> ``$ git commit -m "Story 182: fix benchmarks for speed"``

## Viewing the Commit History

Birkaç taahhüt oluşturduktan sonra veya mevcut bir taahhüt geçmişine sahip bir depoyu klonladıysanız, muhtemelen ne olduğunu görmek için geriye bakmak isteyeceksiniz. Bunu yapmak için en temel ve güçlü araç git ``log`` komuttur.

bir dizi özetleme seçeneği de kullanabilirsiniz git log. Örneğin, her bir taahhüt için bazı kısaltılmış istatistikler görmek istiyorsanız, şu --statseçeneği kullanabilirsiniz :</br>
``$ git log --stat``

Başka bir gerçekten yararlı seçenek --pretty. Bu seçenek, günlük çıktısını varsayılandan farklı biçimlere değiştirir. Kullanmanız için önceden oluşturulmuş birkaç seçenek değeri mevcuttur. onelineBu seçenek için değer her sen kaydedilmesini bir sürü bakıyorsanız yararlıdır tek bir satır üzerinde taahhüt yazdırır. Ek olarak short, full, ve fullerdeğerleri çıktıyı kabaca aynı biçimde ancak sırasıyla daha az veya daha fazla bilgi ile gösterir:

En ilginç seçenek değeri, formatkendi günlük çıktı biçiminizi belirlemenize olanak sağlayan 'dir. Bu, özellikle makine ayrıştırması için çıktı oluştururken kullanışlıdır - biçimi açıkça belirttiğiniz için Git'teki güncellemelerle değişmeyeceğini bilirsiniz:</br>
``$ git log --pretty=format:"%h - %an, %ar : %s"``

| Belirleyici | Çıktı Açıklaması                          |
|-------------|-------------------------------------------|
| %h   | Kısaltılmış taahhüt karması                      |
| %T   | ağaç karması                                     |
| %t   | Kısaltılmış ağaç karması                         |
| %P   | Üst karmalar                                     |
| %p   | Kısaltılmış ana karmalar                         |
| %an  | Yazar adı                                        |
| %ae  | Yazar e-postası                                  |
| %ad  | Yazar tarihi (format --date=seçeneğine uygundur) |
| %ar  | Yazar tarihi, akraba                             |
| %cn  | üye adı                                          |
| %ce  | Üye e-postası                                    |
| %cd  | üye tarihi                                       |
| %cr  | Üye tarihi, göreceli                             |
| %s   | konu                                             |

| Seçenek         | Açıklama                           |
|-----------------|------------------------------------|
| --stat          | Her bir taahhütte değiştirilen dosyalar için istatistikleri göster.|
| --shortstat     | --stat komutundan yalnızca değiştirilen/eklemeler/silmeler satırını görüntüleyin.|
| --name-only     | Taahhüt bilgisinden sonra değiştirilen dosyaların listesini göster.|
| --name-status   | Eklenen/değiştirilen/silinen bilgilerden etkilenen dosyaların listesini de gösterin.|
| --abbrev-commit | SHA-1 sağlama toplamının 40 karakterinin tümü yerine yalnızca ilk birkaç karakterini gösterin.|
| --relative-date | Tarihi tam tarih biçimini kullanmak yerine göreli bir biçimde (örneğin, "2 hafta önce") görüntüleyin.|
| --graph         | Dalın bir ASCII grafiğini görüntüleyin ve günlük çıktısının yanında birleştirme geçmişini görüntüleyin.|
| --pretty        | Taahhütleri alternatif bir biçimde göster. Seçenek değerleri tek satır, kısa, tam, daha dolgun ve biçim (kendi biçiminizi belirlediğiniz) içerir.|
| --oneline       | --pretty=oneline --abbrev-commitBirlikte kullanılan kısaltma.|

<h1 style="text-align:center">Git Branching</h1>

## Branches in a Nutshell

Bir taahhütte bulunduğunuzda Git, hazırladığınız içeriğin anlık görüntüsüne yönelik bir işaretçi içeren bir taahhüt nesnesi depolar. Bu nesne ayrıca yazarın adını ve e-posta adresini, yazdığınız mesajı ve doğrudan bu taahhütten önce gelen taahhüt veya taahhütlere işaret edenleri (ebeveyn veya ebeveynleri) içerir: ilk taahhüt için sıfır ebeveyn, normal bir taahhüt için bir ebeveyn ve iki veya daha fazla dalın birleştirilmesinden kaynaklanan bir taahhüt için birden çok üst öğe.

Git'teki bir dal, bu taahhütlerden birine yönelik hafif, hareketli bir işaretçidir. Git'teki varsayılan dal adı master. Taahhüt mastervermeye başladığınızda, yaptığınız son taahhüdü gösteren bir dal verilir . Her taahhütte bulunduğunuzda, masterdal işaretçisi otomatik olarak ilerler.

:::image type="content" source="../media/git-branch-and-history.png" alt-text=".":::

### Creating a New Branch
Yeni bir şube oluşturduğunuzda ne olur? Bunu yapmak, hareket etmeniz için yeni bir işaretçi oluşturur. Diyelim ki adında yeni bir dal oluşturmak istiyorsunuz testing. Bunu şu git branchkomutla yaparsınız :</br>
``$ git branch testing``

Git şu anda hangi şubede olduğunuzu nasıl biliyor? ``HEAD`` adlı özel bir işaretçi tutar . Bunun, HEADSubversion veya CVS gibi alışık olabileceğiniz diğer VCS'lerdeki konseptten çok farklı olduğunu unutmayın . Git'te bu, şu anda bulunduğunuz yerel şubeye yönelik bir işaretçidir. Bu durumda, hala açıksınız master. git branchKomut sadece oluşturulan yeni bir şube - o şubeye geçmek vermedi.

### Şube Değiştirme
Mevcut bir şubeye geçmek için git checkoutkomutu çalıştırın. Yeni testingşubeye geçelim:</br>
``$ git checkout testing``
Bu ``HEAD``, testingşubeye işaret etmek için hareket eder.

## Basic Branching and Merging

### Basic Branching
lk olarak, projeniz üzerinde çalıştığınızı ve masterdalda zaten birkaç taahhüdünüz olduğunu varsayalım .

:::image type="content" source="../media/git-basic-branching-1.png" alt-text=".":::

Yeni bir dal oluşturmak ve aynı anda ona geçmek için git ``checkout`` komutu şu ``-b`` anahtarla çalıştırabilirsiniz:</br>
``$ git checkout -b iss53``

Testlerinizi çalıştırabilir, düzeltmenin istediğiniz gibi olduğundan emin olabilir ve son olarak üretime dağıtmak için ``hotfix`` şubeyi tekrar şubenizle birleştirebilirsiniz. Bunu şu git mergekomutla yaparsınız:</br>
``$ git checkout master`` ///
``$ git merge hotfix``

:::image type="content" source="../media/git-basic-branching-5.png" alt-text=".":::

## Branch Management

Artık bazı şubeleri oluşturduğunuza, birleştirdiğinize ve sildiğinize göre, şubeleri her zaman kullanmaya başladığınızda işinize yarayacak bazı şube yönetimi araçlarına bakalım.

``git branch`` Komutù sadece oluşturmak ve silme dalları daha fazlasını yapar. Argüman olmadan çalıştırırsanız, mevcut şubelerinizin basit bir listesini alırsınız.
Her daldaki son taahhüdü görmek için şunu çalıştırabilirsiniz ``git branch -v``

## Branching Workflows

### Long-Running Branches
Birçok Git geliştiricisinin, masterdallarında yalnızca tamamen kararlı olan koda sahip olmak gibi bu yaklaşımı benimseyen bir iş akışı vardır.
Muhtemelen yalnızca yayınlanmış veya yayınlanacak kod. Adlandırılmış **develop** veya **next** kararlılığı test etmek için çalıştıkları veya kullandıkları başka bir paralel dalları vardır.

Mutlaka her zaman kararlı değildir, ancak kararlı bir duruma geldiğinde, master şubesinde birleştirilir.

**develop** veya **master** dal. Buradaki fikir, şubelerinizin çeşitli istikrar seviyelerinde olmasıdır; daha kararlı bir seviyeye ulaştıklarında, üstlerindeki dalda birleşirler. Yine, birden fazla uzun soluklu şubeye sahip olmak gerekli değildir, ancak özellikle çok büyük veya karmaşık projelerle uğraşırken genellikle yararlıdır.


## Remote Branches
Uzak referanslar, şubeler, etiketler vb. dahil olmak üzere uzak havuzlarınızdaki referanslardır (işaretçiler). Açıkça ``git remote show`` yazarak uzak dallar için uzak referansların tam listesini ve daha fazla bilgiyi alabilirsiniz. Bununla birlikte, daha yaygın bir yol, uzaktan izleme dallarından yararlanmaktır.

Uzaktan izleme dalları, uzak dalların durumuna referanslardır. Bunlar, taşıyamayacağınız yerel referanslardır; Git, herhangi bir ağ iletişimi yaptığınızda, uzak havuzun durumunu doğru bir şekilde temsil etmelerini sağlamak için bunları sizin için taşır. Uzak depolarınızdaki şubelerin onlara en son bağlandığınızda nerede olduğunu size hatırlatmak için bunları yer imleri olarak düşünün.

Uzaktan izleme şube adları biçimini alır ``<remote>/<branch>``. Örneğin, uzaktan kumandanızdaki **master** şubenin, **origin** onunla en son iletişim kurduğunuz andan itibaren nasıl göründüğünü görmek isterseniz, **origin/master** şubeyi kontrol edersiniz . Bir iş ortağıyla bir sorun üzerinde çalışıyorsanız ve onlar bir **iss53** şube açtıysa, kendi yerel **iss53** şubeniz olabilir, ancak sunucudaki şube uzaktan izleme şubesi tarafından temsil edilir **origin/iss53**.

Daha fazla bilgi için: <https://git-scm.com/book/en/v2/Git-Branching-Remote-Branches>

## Rebasing
Git'te, değişiklikleri bir daldan diğerine entegre etmenin iki ana yolu vardır: **merge** ve **rebase**. Bu bölümde, yeniden temellendirmenin ne olduğunu, nasıl yapıldığını, neden oldukça şaşırtıcı bir araç olduğunu ve hangi durumlarda kullanmak istemeyeceğinizi öğreneceksiniz.

### The Basic Rebase
:::image type="content" source="../media/git-basic-rebase-1.png" alt-text=".":::
Dalları entegre etmenin en kolay yolu, daha önce de bahsettiğimiz gibi **merge** komuttur. En son iki dal anlık görüntüsü ( *C3* ve *C4*) ile ikisinin en son ortak atası (*C2*) arasında üç yönlü bir birleştirme gerçekleştirerek yeni bir anlık görüntü (ve kesinleştirme) oluşturur.
:::image type="content" source="../media/git-basic-rebase-2.png" alt-text=".":::

<h1 style="text-align:center">Distributed Git Workflows</h1>

Artık tüm geliştiricilerin kodlarını paylaşmaları için bir odak noktası olarak ayarlanmış uzak bir Git deposuna sahip olduğunuza ve yerel bir iş akışındaki temel Git komutlarına aşina olduğunuza göre, dağıtılmış iş akışlarından bazılarının nasıl kullanılacağına bakacaksınız. Git'in size sağladığı

Bu bölümde, dağıtılmış bir ortamda katkıda bulunan ve entegratör olarak Git ile nasıl çalışacağınızı göreceksiniz. Yani, bir projeye başarılı bir şekilde kod eklemeyi ve bunu siz ve proje yürütücüsü için mümkün olduğunca kolaylaştırmayı ve ayrıca katkıda bulunan birkaç geliştiriciyle bir projeyi nasıl başarılı bir şekilde sürdüreceğinizi öğreneceksiniz.

## Distributed Workflows

Merkezi Sürüm Kontrol Sistemlerinin (CVCS'ler) aksine, Git'in dağıtık yapısı, geliştiricilerin projelerde nasıl işbirliği yaptığı konusunda çok daha esnek olmanızı sağlar. Merkezi sistemlerde her geliştirici, merkezi bir hub ile aşağı yukarı eşit olarak çalışan bir düğümdür. Ancak Git'te her geliştirici potansiyel olarak hem bir düğüm hem de bir merkezdir; yani, her geliştirici hem diğer havuzlara kod katkıda bulunabilir hem de başkalarının çalışmalarını temel alabilecekleri ve katkıda bulunabilecekleri bir genel havuz sağlayabilir. Bu, projeniz ve/veya ekibiniz için çok çeşitli iş akışı olanakları sunar, bu nedenle bu esneklikten yararlanan birkaç ortak paradigmayı ele alacağız. Her tasarımın güçlü ve olası zayıf yönlerini gözden geçireceğiz; kullanmak için tek bir tane seçebilir veya her birinin özelliklerini karıştırıp eşleştirebilirsiniz.

<h1 style="text-align:center">Git Tools</h1>

### Short SHA-1
Git, SHA-1 karmasının ilk birkaç karakterini sağlarsanız, bu kısmi karma en az dört karakter uzunluğunda ve açık olduğu sürece hangi taahhütten bahsettiğinizi anlayacak kadar akıllıdır; yani, nesne veritabanındaki başka hiçbir nesne, aynı önekle başlayan bir karmaya sahip olamaz.

Örneğin, belirli bir işlevi eklediğinizi bildiğiniz belirli bir taahhüdü incelemek için, önce ``git log`` taahhüdü bulmak için komutu çalıştırabilirsiniz.

Bu durumda, 1c002dd…​ hash'i ile başlayan taahhütle bilgi almak için ``git show 1c002dd`` yazın.

### RefLog Shortnames
Git'in siz uzaktayken arka planda yaptığı şeylerden biri, bir "reflog" tutmaktır - son birkaç aydır **HEAD** ve şube referanslarınızın nerede olduğunun bir günlüğünü almak için ```git reflog`` yazın.

``git log`` çıktı gibi biçimlendirilmiş **reflog** bilgilerini görmek için şunu çalıştırabilirsiniz ``git log -g``.

### Stashing Your Work
Saklamayı göstermek için projenize girecek ve birkaç dosya üzerinde çalışmaya başlayacak ve muhtemelen değişikliklerden birini gerçekleştireceksiniz. 
Şimdi dalları değiştirmek istiyorsunuz, ancak henüz üzerinde çalıştığınız şeyi taahhüt etmek istemiyorsunuz, bu yüzden değişiklikleri saklarsınız. Yığınınıza yeni bir zula itmek için şunu çalıştırın ``git stash`` veya ``git stash push``.

<h1 style="text-align:center">More About proGit</h1>

**Link: [proGitBook](https://git-scm.com/book/en/v2) > https://git-scm.com/book/en/v2**





