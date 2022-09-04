
## HTML Formatting
Formatting elements were designed to display special types of text:

| Tag         | Description      |
|-------------|------------------|
|``<b>``      | Bold text        |
|``<strong>`` | Important text   |
|``<i>``      | Italic text      |
|``<em>``     | Vurgulanan metin |
|``<mark>``   | Marked text      |
|``<small>``  | Smaller text     |
|``<del>``    | Deleted text     |
|``<ins>``    | Inserted text    |
|``<sub>``    | Subscript text   |
|``<sup>``    | Superscript text |

## HTML Quotations
Biçimlendirme öğeleri, özel metin türlerini görüntülemek için tasarlanmıştır:

| Tag        | Description      |
|------------|------------------|
|``<b>``     | Kalın yazı       |
|``<strong>``| Önemli metin     |
|``<i>``     | İtalik metin     |
|``<em>``    | Vurgulanan metin |
|``<mark>``  | İşaretli metin   |
|``<small>`` | Daha küçük metin |
|``<del>``   | Silinen metin    |
|``<ins>``   | Eklenen metin    |
|``<sub>``   | Alt simge metni  |
|``<sup>``   | Üst simge metni  |

## HTML Comments
HTML yorumları tarayıcıda görüntülenmez, ancak HTML kaynak kodunuzu belgelemenize yardımcı olabilirler.

``<!-- Write your comments here -->``

## HTML Color
HTML renkleri, önceden tanımlanmış renk adlarıyla veya RGB, HEX, HSL, RGBA veya HSLA değerleriyle belirtilir.</br>
HTML'de, bir renk adı kullanılarak bir renk belirtilebilir:</br>
``Tomato`` | ``Orange`` | ``DodgerBlue`` | ``MediumSeaGreen`` | ``Gray`` | ``SlateBlue`` | ``Violet`` | ``LightGray``

### Text Color
HTML Metnin rengini ayarlayabilirsiniz:</br>
``<h1 style="color:Tomato;">Hello World</h1>``

### Color Values
HTML'de renkler RGB değerleri, HEX değerleri, HSL değerleri, RGBA değerleri ve HSLA değerleri kullanılarak da belirlenebilir.
Aşağıdaki üç ``<div>`` öğesinin arka plan rengi RGB, HEX ve HSL değerleriyle ayarlanır:

``rgb(255, 99, 71)``</br>
``#ff6347``</br>
``hsl(9, %100, %64)``

> [!TIP]
> Learn more about Color Values</br> [RGB](https://www.w3schools.com/html/html_colors_rgb.asp), [HEX](https://www.w3schools.com/html/html_colors_hex.asp) ve [HSL](https://www.w3schools.com/html/html_colors_hsl.asp) hakkında daha fazla bilgi edineceksiniz.

## HTML CSS
Basamaklı Stil Sayfaları (CSS), bir web sayfasının düzenini biçimlendirmek için kullanılır.

CSS ile rengi, yazı tipini, metnin boyutunu, öğeler arasındaki boşluğu, öğelerin nasıl konumlandırıldığını ve düzenlendiğini, hangi arka plan resimlerinin veya arka plan renklerinin kullanılacağını, farklı cihazlar ve ekran boyutları için farklı ekranları ve daha fazla!

### Using CSS
CSS, HTML belgelerine 3 şekilde eklenebilir:

* Inline - styleHTML öğelerinin içindeki özniteliği kullanarak
* Internal - bölümdeki bir ``<style>`` öğeyi kullanarak ``<head>``
* External - ``<link>`` harici bir CSS dosyasına bağlanmak için bir öğe kullanarak

CSS eklemenin en yaygın yolu, stilleri harici CSS dosyalarında tutmaktır. Bununla birlikte, bu öğreticide satır içi ve dahili stilleri kullanacağız, çünkü bunu göstermek daha kolay ve kendiniz denemeniz daha kolay.

#### Inline CSS
Tek bir HTML öğesine benzersiz bir stil uygulamak için satır içi CSS kullanılır.</br>
Satır içi CSS ``style``, bir HTML öğesinin özniteliğini kullanır.

#### Internal CSS
Tek bir HTML sayfası için bir stil tanımlamak için dahili bir CSS kullanılır.</br>
Bir ``<head>`` HTML sayfasının bölümünde, bir ``<style>`` öğe içinde dahili bir CSS tanımlanır.

```html
<style>
body {background-color: powderblue;}
h1   {color: blue;}
p    {color: red;}
</style>
```

#### External CSS
Birçok HTML sayfasının stilini tanımlamak için harici bir stil sayfası kullanılır.

Harici bir stil sayfası kullanmak için ``<head>``, her HTML sayfasının bölümüne bir bağlantı ekleyin:

```html
<head>
  <link rel="stylesheet" href="styles.css">
</head>
```

## HTML Links
### HTML Links - Hyperlinks
HTML bağlantıları köprülerdir. Bir bağlantıya tıklayıp başka bir belgeye atlayabilirsiniz. Fareyi bir bağlantının üzerine getirdiğinizde, fare oku küçük bir ele dönüşecektir.

HTML ``<a>`` etiketi bir köprüyü tanımlar. Aşağıdaki sözdizimine sahiptir:</br>
``<a href="url">link text</a>``

### HTML Links - The target Attribute
Varsayılan olarak, bağlantılı sayfa mevcut tarayıcı penceresinde görüntülenecektir. Bunu değiştirmek için bağlantı için başka bir hedef belirtmelisiniz.

``target`` Nitelik belirtir nerede bağlantılı belgeyi açmak için.

``target`` Özniteliği şu değerlerden birine sahip olabilir:

* ``_self`` - Varsayılan. Belgeyi, tıklandığı pencerede/sekmede açar
* ``_blank`` - Belgeyi yeni bir pencerede veya sekmede açar
* ``_parent`` - Belgeyi ana çerçevede açar
* ``_top`` - Belgeyi pencerenin tam gövdesinde açar

### HTML Links - Use an Image as a Link
Bir görseli bağlantı olarak kullanmak için ``<img>`` etiketi etiketin içine koymanız ``<a>`` yeterlidir:

```html
<a href="default.asp">
<img src="smiley.gif" alt="HTML tutorial" style="width:42px;height:42px;">
</a>
```

### Link to an Email Address
Kullanıcının e-posta programını açan bir bağlantı oluşturmak ``mailto:`` için ``href`` özelliğin içinde kullanın (yeni bir e-posta göndermelerine izin vermek için):</br>
``<a href="mailto:someone@example.com">Send email</a>``

### Button as a Link
Bir HTML düğmesini bağlantı olarak kullanmak için biraz JavaScript kodu eklemeniz gerekir. JavaScript, bir düğme tıklaması gibi belirli olaylarda ne olacağını belirtmenize olanak tanır:</br>
``<button onclick="document.location='default.asp'">HTML Tutorial</button>``

### Link Titles
``title`` Öznitelik, öğe hakkında ek bilgileri belirtir. Bilgi, çoğunlukla fare öğenin üzerine geldiğinde bir araç ipucu metni olarak gösterilir.</br>
``<a href="https://www.w3schools.com/html/" title="Go to W3Schools HTML section">Visit our HTML Tutorial</a>``

### Create a Bookmark in HTML
Bir web sayfası çok uzunsa yer imleri yararlı olabilir. Bir yer imi oluşturmak için - önce yer imini oluşturun, ardından ona bir bağlantı ekleyin. Bağlantı tıklandığında, sayfa aşağı veya yukarı kaydırılarak yer iminin bulunduğu konuma gelir.

İlk olarak, idbir yer imi oluşturmak için özniteliği kullanın:</br>
``<h2 id="C4">Chapter 4</h2>``

Ardından, aynı sayfadan yer işaretine ("4. Bölüme Atla") bir bağlantı ekleyin:</br>
``<a href="#C4">Jump to Chapter 4</a>``

Ayrıca başka bir sayfadaki bir yer işaretine bağlantı ekleyebilirsiniz:</br>
``<a href="html_demo.html#C4">Jump to Chapter 4</a>``

## HTML Images
Görüntüler, bir web sayfasının tasarımını ve görünümünü iyileştirebilir.
``<img src="pic_trulli.jpg" alt="Italian Trulli">``

HTML ``<img>`` etiketi, bir web sayfasına bir resim gömmek için kullanılır. Görüntüler teknik olarak bir web sayfasına eklenmez; resimler web sayfalarına bağlıdır. ``<img>`` Etiketi başvurulan resim için bir tutma alanı yaratır.

``<img>`` Etiketi yalnızca niteliklerini içerir ve bir kapanış etiketi yok, boş.

``<img>`` Etiketi, iki niteliği taşımaktadır:

* src - Resmin yolunu belirtir
* alt - Resim için alternatif bir metin belirtir

``<img src="url" alt="alternatetext">``

### Images on Another Server/Website
Başka bir sunucudaki bir resme işaret etmek için srcöznitelikte mutlak (tam) bir URL belirtmelisiniz:</br>
``<img src="https://www.w3schools.com/images/w3schools_green.jpg" alt="W3Schools.com">``

| Abbreviation | File Format                  | File Extension                  |
|----------|----------------------------------|---------------------------------|
|APNG | Animated Portable Network Graphics    |.apng                            |
|GIF  | Graphics Interchange Format	          |.gif                             |
|ICO  | Microsoft Icon                        |.ico, .cur                       |
|JPEG | Joint Photographic Expert Group image |.jpg, .jpeg, .jfif, .pjpeg, .pjp |
|PNG  | Portable Network Graphics             |.png                             |
|SVG  | Scalable Vector Graphics              |.svg                             |

## HTML Table
HTML tabloları, web geliştiricilerinin verileri satırlar ve sütunlar halinde düzenlemesine olanak tanır.</br>
``<table>`` Etiket HTML tablosu tanımlar.

Her tablo satırı bir ``<tr>`` etiketle tanımlanır. Her tablo başlığı bir ``<th>`` etiketle tanımlanır. Her tablo verisi/hücresi bir ``<td>`` etiketle tanımlanır.

Varsayılan olarak, ``<th>`` öğelerdeki metin kalın ve ortalanmıştır.

Varsayılan olarak, ``<td>`` öğelerdeki metin normaldir ve sola hizalıdır.

```html
<table style="width:100%">
  <tr>
    <th>Firstname</th>
    <th>Lastname</th>
    <th>Age</th>
  </tr>
  <tr>
    <td>Jill</td>
    <td>Smith</td>
    <td>50</td>
  </tr>
  <tr>
    <td>Eve</td>
    <td>Jackson</td>
    <td>94</td>
  </tr>
</table>
```

## HTML List
HTML listeleri, web geliştiricilerinin bir dizi ilgili öğeyi listelerde gruplandırmasına olanak tanır.

### Unordered HTML List
Sırasız bir liste ``<ul>`` etiketi ile başlar. Her liste öğesi ``<li>`` etiketiyle başlar.

Liste öğeleri varsayılan olarak madde işaretleri (küçük siyah daireler) ile işaretlenecektir:

```html
<ul>
  <li>Coffee</li>
  <li>Tea</li>
  <li>Milk</li>
</ul>
```

### Ordered HTML List
Sıralı bir liste ``<ol>`` etiketi ile başlar . Her liste öğesi ``<li>`` etiketiyle başlar .

Liste öğeleri varsayılan olarak sayılarla işaretlenecektir:

```html
<ol>
  <li>Coffee</li>
  <li>Tea</li>
  <li>Milk</li>
</ol>
```

### HTML Description Lists
HTML ayrıca açıklama listelerini de destekler.

Açıklama listesi, her terimin açıklamasıyla birlikte terimlerin bir listesidir.

``<dl>`` Etiket, açıklama listesi tanımlar ``<dt>`` etiket terimi (ad) tanımlar ve ``<dd>`` etiket her dönem açıklanmaktadır:

```html
<dl>
  <dt>Coffee</dt>
  <dd>- black hot drink</dd>
  <dt>Milk</dt>
  <dd>- white cold drink</dd>
</dl>
```

## HTML Block & Inline
### Block-level Elements
Her HTML öğesinin, ne tür bir öğe olduğuna bağlı olarak varsayılan bir görüntüleme değeri vardır.

- Blok düzeyinde bir öğe her zaman yeni bir satırda başlar.
- Blok düzeyinde bir öğe her zaman mevcut olan tam genişliği kaplar (mümkün olduğunca sola ve sağa doğru uzanır).
- Blok düzeyinde bir öğenin bir üst ve bir alt kenar boşluğu vardır, oysa bir satır içi öğede yoktur.
``<div>Hello World</div>``

### Inline Elements
Satır içi öğe yeni bir satırda başlamaz.</br>
Bir satır içi öğe yalnızca gerektiği kadar genişlik kaplar.

## HTML Classes
HTML classniteliği, bir HTML öğesi için bir sınıf belirtmek için kullanılır.

Birden çok HTML öğesi aynı sınıfı paylaşabilir.

### Using The class Attribute
``class`` Nitelik genellikle stil sayfasında bir sınıf adına noktasına kullanılır. Belirli sınıf adına sahip öğelere erişmek ve bunları değiştirmek için bir JavaScript tarafından da kullanılabilir.

### The Syntax For Class
Sınıf oluşturmak için; bir nokta (.) karakteri ve ardından bir sınıf adı yazın. Ardından, küme parantezleri {} içinde CSS özelliklerini tanımlayın:

HTML öğeleri birden fazla sınıfa ait olabilir.</br>
Birden çok sınıf tanımlamak için sınıf adlarını bir boşlukla ayırın, örneğin ``<div class="city main">`` Öğe, belirtilen tüm sınıflara göre şekillendirilecektir.

## HTML Id
HTML idözelliği, bir HTML öğesi için benzersiz bir kimlik belirtmek için kullanılır.

Bir HTML belgesinde aynı kimliğe sahip birden fazla öğeniz olamaz.

id sözdizimi şöyledir: bir hash karakteri (#) ve ardından bir id adı yazın. Ardından, küme parantezleri {} içinde CSS özelliklerini tanımlayın.

### HTML Bookmarks with ID and Links
HTML yer imleri, okuyucuların bir web sayfasının belirli bölümlerine atlamasına izin vermek için kullanılır. Bir yer imi kullanmak için önce onu oluşturmanız ve ardından ona bir bağlantı eklemeniz gerekir. Ardından, bağlantıya tıklandığında sayfa, yer iminin bulunduğu konuma kaydırılır.
1. ``<h2 id="C4">Chapter 4</h2>``
1. ``<a href="#C4">Jump to Chapter 4</a>``
1. ``<a href="html_demo.html#C4">Jump to Chapter 4</a>``

## HTML iframes
HTML ``<iframe>`` etiketi bir satır içi çerçeve belirtir.

Geçerli HTML belgesine başka bir belge gömmek için bir satır içi çerçeve kullanılır.

```html
<iframe src="url" title="description"></iframe>
```

### The HTML < noscript > Tag
HTML ``<noscript>`` etiketi, tarayıcılarında komut dosyalarını devre dışı bırakmış veya komut dosyalarını desteklemeyen bir tarayıcıya sahip kullanıcılara görüntülenecek alternatif bir içerik tanımlar.

## HTML File Paths
Dosya yolu, bir web sitesinin klasör yapısındaki bir dosyanın konumunu tanımlar.</br>
* Mutlak dosya yolu, bir dosyanın tam URL'sidir:
``<img src="https://www.w3schools.com/images/picture.jpg" alt="Mountain">``

* Göreli bir dosya yolu, geçerli sayfaya göre bir dosyaya işaret eder.
``<img src="/images/picture.jpg" alt="Mountain">``

## HTML Head
HTML ``<head>`` elemanı, aşağıdaki elemanları için bir kap: ``<title>, <style>, <meta>, <link>, <script>, and <base>``
``<head>`` Eleman meta verileri (veri hakkında veri) için bir kap olup arasına yerleştirilir ``<html>`` etiket ve ``<body>`` etiket.

HTML meta verileri, HTML belgesi hakkındaki verilerdir. Meta veriler görüntülenmiyor. Meta veriler genellikle belge başlığını, karakter setini, stilleri, komut dosyalarını ve diğer meta bilgileri tanımlar.

### HTML < title > Element
``<title>`` Öğe, belgenin başlık tanımlar. Başlık salt metin olmalıdır ve tarayıcının başlık çubuğunda veya sayfa sekmesinde gösterilir.

Bir sayfa başlığının içeriği, arama motoru optimizasyonu (SEO) için çok önemlidir! Sayfa başlığı, arama sonuçlarında sayfaları listelerken sıraya karar vermek için arama motoru algoritmaları tarafından kullanılır.

### HTML < style > Element
``<style>`` Eleman tek bir HTML sayfası için stil bilgileri tanımlamak için kullanılır.

### HTML < link > Element
``<link>`` Eleman akım belge ve harici kaynak arasındaki ilişkiyi tanımlar. Etiket en sık dış stil sayfaları için bağlantıyı için kullanılır.

### HTML < meta > Element
``<meta>`` Eleman tipik karakter kümesi, sayfa açıklama, anahtar kelimeler, belgenin yazarı ve görünüm ayarları belirtmek için kullanılır.

Meta veriler sayfada görüntülenmez, ancak tarayıcılar (içeriğin nasıl görüntüleneceği veya sayfanın nasıl yeniden yükleneceği), arama motorları (anahtar kelimeler) ve diğer web hizmetleri tarafından kullanılır.

Kullanılan karakter setini tanımlayın:
```html
<meta charset="UTF-8">
```
Arama motorları için anahtar kelimeleri tanımlayın:
```html
<meta name="keywords" content="HTML, CSS, JavaScript">
```
Web sayfanızın bir açıklamasını tanımlayın:
```html
<meta name="description" content="Free Web tutorials">
```
Bir sayfanın yazarını tanımlayın:
```html
<meta name="author" content="John Doe">
```
Belgeyi her 30 saniyede bir yenileyin:
```html
<meta http-equiv="refresh" content="30">
```
Web sitenizin tüm cihazlarda iyi görünmesini sağlamak için görünüm alanını ayarlama:
```html
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

### Setting The Viewport
Görünüm alanı, kullanıcının bir web sayfasının görünür alanıdır. Cihaza göre değişir - cep telefonunda bilgisayar ekranından daha küçük olacaktır.

``<meta>`` Tüm web sayfalarınıza aşağıdaki öğeyi eklemelisiniz:

```html
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

## HTML Layout
HTML, bir web sayfasının farklı bölümlerini tanımlayan birkaç anlamsal öğeye sahiptir:

HTML5 Semantik Öğeleri	
* ``<header>`` - Bir belge veya bölüm için bir başlık tanımlar
* ``<nav>`` - Bir dizi gezinme bağlantısı tanımlar
* ``<section>`` - Belgedeki bir bölümü tanımlar
* ``<article>`` - Bağımsız, kendi kendine yeten bir içerik tanımlar
* ``<aside>`` - İçeriği içerikten ayrı olarak tanımlar (kenar çubuğu gibi)
* ``<footer>`` - Bir belge veya bölüm için bir alt bilgi tanımlar
* ``<details>`` - Kullanıcının isteğe bağlı olarak açıp kapatabileceği ek ayrıntıları tanımlar
* ``<summary>`` - ``<details>`` Öğe için bir başlık tanımlar

### CSS Float Layout
CSS ``float`` özelliğini kullanarak tüm web mizanpajlarını yapmak yaygındır. Float'ı öğrenmesi kolaydır - sadece ``float`` ve clearözelliklerinin nasıl çalıştığını hatırlamanız gerekir. Dezavantajları: Floating Elements, esnekliğe zarar verebilecek belge akışına bağlıdır. [CSS Float ve Clear](https://www.w3schools.com/css/css_float.asp) bölümümüzde float hakkında daha fazla bilgi edinin.

## HTML Responsive
Duyarlı Web Tasarımı, bir web sitesini tüm cihazlarda (masaüstü, tablet ve telefon) iyi görünmesi için otomatik olarak yeniden boyutlandırmak, gizlemek, küçültmek veya büyütmek için HTML ve CSS kullanmakla ilgilidir:

## HTML ComputerCode
HTML, kullanıcı girdisini ve bilgisayar kodunu tanımlamak için çeşitli öğeler içerir.

```html
<code>
x = 5; y = 6;
z = x + y;
</code>
```

### HTML < samp > For Program Output
HTML ``<samp>`` öğesi, bir bilgisayar programından örnek çıktıyı tanımlamak için kullanılır. İçindeki içerik, tarayıcının varsayılan monospace yazı tipinde görüntülenir.
```html
<p>Message from my computer:</p>
<p><samp>File not found.<br>Press F1 to continue</samp></p>
```

## HTML Semantic Elements

### Semantik Öğeler Nelerdir?
Anlamsal bir öğe, anlamını hem tarayıcı hem de geliştirici için açık bir şekilde tanımlar.</br>
Anlamsal olmayan öğelere örnekler: ``<div>`` ve ``<span>`` - İçeriği hakkında hiçbir şey söylemez.</br>
Anlamsal öğe örnekleri: ``<form>``, ``<table>``, ve ``<article>`` - İçeriğini açıkça tanımlar.</br>
Birçok web sitesi, gezinmeyi, üstbilgiyi ve altbilgiyi belirtmek için ``<div id="nav">``, ``<div class="header">``, ``<div id="footer">`` gibi HTML kodu içerir.</br>
HTML'de bir web sayfasının farklı bölümlerini tanımlamak için kullanılabilecek bazı anlamsal öğeler vardır:  

### Html < section > Element
``<section>`` Eleman, bir belgenin bir bölüm tanımlar.

### HTML < article > Element
``<article>`` Eleman bağımsız, kendi kendine yeten içeriği belirtir.</br>
Bir makale kendi başına anlamlı olmalı ve web sitesinin geri kalanından bağımsız olarak dağıtılabilir olmalıdır.</br>
Bir ``<article>`` elemanın nerede kullanılabileceğine dair örnekler:
* Forum gönderisi
* Blog yazısı
* Gazete makalesi

### HTML < header > Element
``<header>`` Eleman giriş içerik veya seyir bağlantılar kümesi için bir kabı ifade etmektedir.

Bir ``<header>`` öğe tipik olarak şunları içerir:
* Bir veya daha fazla başlık öğesi (``<h1> - <h6>``)
* Logo veya simge
* Yazarlık bilgileri

### HTML < footer > Element
``<footer>`` Öğesi bir belgenin veya bölümün altbilgi tanımlar.

Bir ``<footer>`` öğe tipik olarak şunları içerir:

* yazarlık bilgileri
* telif hakkı bilgisi
* iletişim bilgileri
* site haritası
* en iyi bağlantılara geri dön
* İlgili belgeler

### HTML < nav > Element
``<nav>`` Eleman navigasyon bir dizi bağlantı tanımlar.

### HTML < aside > Element
``<aside>`` Eleman (bir kenar çubuğu gibi) yerleştirilir içerikten ayrılan bir içeriğini tanımlar.

``<aside>`` İçerik dolaylı çevredeki içeriği ile ilgili olmalıdır.

### HTML < figure > and < figcaption > Elements
``<figure>``Vb resim, şekil, fotoğraf, kod girişler gibi etiketin belirtir müstakil içerik,</br>
``<figcaption>`` Etiketi için bir başlık tanımlar ``<figure>`` elemanı. ``<figcaption>`` Eleman ilk olarak veya bir son çocuğu olarak yerleştirilebilir ``<figure>`` elemanı.</br>
``<img>`` Eleman gerçek görüntü / şekle tanımlar. </br>

## HTML Entities
Bazı karakterler HTML'de ayrılmıştır. Metninizde küçüktür (<) veya büyüktür (>) işaretlerini kullanırsanız, tarayıcı bunları etiketlerle karıştırabilir. Karakter varlıkları, HTML'de ayrılmış karakterleri görüntülemek için kullanılır. Bir karakter varlığı şöyle görünür:

```html
&entity_name;
OR

&#entity_number;
```

## HTML Symbol Entities
HTML varlıkları önceki bölümde açıklanmıştır. Birçok matematiksel, teknik ve para birimi simgesi normal bir klavyede bulunmaz. Bir HTML sayfasına bu tür semboller eklemek için, sembol için varlık adını veya varlık numarasını (ondalık veya onaltılık referans) kullanabilirsiniz.

Bir varlık adı, bir ondalık sayı ve bir onaltılık değer ile euro işaretini (€) görüntüleyin:
```html
<p>I will display &euro;</p>
<p>I will display &#8364;</p>
<p>I will display &#x20AC;</p>
```

| Char | Number   | Entity       | Description          |
|------|----------|--------------|----------------------|
| ∂ | ``&#8706;`` | ``&part;``   | PARTIAL DIFFERENTIAL |
| ∃ | ``&#8707;`` | ``&exist;``  | THERE EXISTS         |
| ∅ | ``&#8709;`` | ``&empty;``  | EMPTY SETS           |
| ∇ | ``&#8711;`` | ``&nabla;``  | NABLA                |
| ∈ | ``&#8712;`` | ``&isin;``   | ELEMENT OF           |
| ∉ | ``&#8713;`` | ``&notin;``  | NOT AN ELEMENT OF    |
| ∋ | ``&#8715;`` | ``&ni;``     | CONTAINS AS MEMBER   |
| ∏ | ``&#8719;`` | ``&prod;``   | N-ARY PRODUCT        |
| ∑ | ``&#8721;`` | ``&sum;``    | N-ARY SUMMATION      |
| © | ``&#169;``  | ``&copy;``   | COPYRIGHT SIGN       |
| € | ``&#8364;`` | ``&euro;``   | EURO SIGN            |
| ™ | ``&#8482;`` | ``&trade;``  | TRADEMARK            |
| ← | ``&#8592;`` | ``&larr;``   | LEFTWARDS ARROW      |
| ↑ | ``&#8593;`` | ``&uarr;``   | UPWARDS ARROW        |
| → | ``&#8594;`` | ``&rarr;``   | RIGHTWARDS ARROW     |
| ↓ | ``&#8595;`` | ``&darr;``   | DOWNWARDS ARROW      |
| ♠ | ``&#9824;`` | ``&spades;`` | BLACK SPADE SUIT     |
| ♣ | ``&#9827;`` | ``&clubs;``  | BLACK CLUB SUIT      |
| ♥ | ``&#9829;`` | ``&hearts;`` | BLACK HEART SUIT     |
| ♦ | ``&#9830;`` | ``&diams;``  | BLACK DIAMOND SUIT   |

## HTML Emojis
Emojiler UTF-8 karakter setindeki karakterlerdir: 😄 😍</br>
Emojiler resimlere veya simgelere benziyor, ancak değiller, UTF-8 (Unicode) karakter kümesinden harflerdir (karakterler).

## HTML Chartset
Bir HTML sayfasını doğru bir şekilde görüntülemek için, bir web tarayıcısının hangi karakter setini kullanacağını bilmesi gerekir.

### From ASCII to UTF-8
- ASCII, ilk karakter kodlama standardıydı. ASCII, internette kullanılabilecek 128 farklı karakter tanımladı: sayılar (0-9), İngilizce harfler (AZ) ve ! $ + - ( ) @ < > .
- ISO-8859-1, HTML 4 için varsayılan karakter setiydi. Bu karakter seti 256 farklı karakter kodunu destekledi. HTML 4 ayrıca UTF-8'i de destekledi.
- ANSI (Windows-1252), orijinal Windows karakter setiydi. ANSI, ANSI'nin 32 fazladan karaktere sahip olması dışında, ISO-8859-1 ile aynıdır.
- HTML5 spesifikasyonu, web geliştiricilerini dünyadaki neredeyse tüm karakterleri ve sembolleri kapsayan UTF-8 karakter setini kullanmaya teşvik eder!

## HTML URL Encode
Web tarayıcıları, bir URL kullanarak web sunucularından sayfa ister. Web'deki bir belgeyi (veya diğer verileri) adreslemek için Tekdüzen Kaynak Konum Belirleyici (URL) kullanılır.

`https://www.w3schools.com/html/default.asp` gibi bir web adresi şu sözdizimi kurallarına uyar:
```html
scheme://prefix.domain:port/path/filename
```
#### Explanation
* **scheme** - İnternet hizmetinin türünü tanımlar (en yaygın olanı http veya https'dir )
* **prefix** - bir etki alanı önekini tanımlar (http için varsayılan, www'dir )
* **domain** - İnternet etki alanı adını tanımlar (w3schools.com gibi)
* **port** - ana bilgisayardaki bağlantı noktası numarasını tanımlar (http için varsayılan değer 80'dir )
* **path** - sunucuda bir yol tanımlar (Eğer atlanırsa: sitenin kök dizini)
* **filename** - bir belgenin veya kaynağın adını tanımlar

---

## HTML Forms
Kullanıcı girdisini toplamak için bir HTML formu kullanılır. Kullanıcı girişi genellikle işlenmek üzere bir sunucuya gönderilir.

### The < form > Element
HTML ``<form>`` öğesi, kullanıcı girişi için bir HTML formu oluşturmak için kullanılır:
```html
<form>
.
form elements
.
</form>
```

### The < input > Element
HTML ``<input>`` öğesi en çok kullanılan form öğesidir.</br>
Bir ``<input>`` öğe, type özniteliğe bağlı olarak birçok şekilde görüntülenebilir .

### The < label > Element
``<label>`` Yukarıdaki örnekte elemanın kullanımına dikkat edin. ``<label>`` Etiketi birçok form öğeleri için bir etiket tanımlar.

### The < select > Element
``<select>`` Öğesi bir açılır listeyi tanımlar:
```html
<label for="cars">Choose a car:</label>
<select id="cars" name="cars">
  <option value="volvo">Volvo</option>
  <option value="saab">Saab</option>
  <option value="fiat">Fiat</option>
  <option value="audi">Audi</option>
</select>
```
### The HTML < form > Element
HTML ``<form>`` öğesi, aşağıdaki form öğelerinden bir veya daha fazlasını içerebilir:
* ``<input>``
* ``<label>``
* ``<select>``
* ``<textarea>``
* ``<button>``
* ``<fieldset>``
* ``<legend>``
* ``<datalist>``
* ``<output>``
* ``<option>``
* ``<optgroup>``

### The < textarea > Element
``<textarea>`` Eleman, bir çok hatlı bir giriş alanı (bir metin alanı) tanımlar:

```html
<textarea name="message" rows="10" cols="30">
The cat was playing in the garden.
</textarea>
```

### HTML Input Types
HTML'de kullanabileceğiniz farklı giriş türleri şunlardır:
* ``<input type="button">``
* ``<input type="checkbox">``
* ``<input type="color">``
* ``<input type="date">``
* ``<input type="datetime-local">``
* ``<input type="email">``
* ``<input type="file">``
* ``<input type="hidden">``
* ``<input type="image">``
* ``<input type="month">``
* ``<input type="number">``
* ``<input type="password">``
* ``<input type="radio">``
* ``<input type="range">``
* ``<input type="reset">``
* ``<input type="search">``
* ``<input type="submit">``
* ``<input type="tel">``
* ``<input type="text">``
* ``<input type="time">``
* ``<input type="url">``
* ``<input type="week">``

> [!NOTE]
> More About İnput Types https://www.w3schools.com/html/html_form_input_types.asp and also https://www.w3schools.com/html/html_form_attributes.asp

---

## HTML Canvas
HTML ``<canvas>`` öğesi, bir web sayfasında grafik çizmek için kullanılır.

Soldaki grafik ile oluşturulur ``<canvas>``. Dört öğe gösterir: kırmızı bir dikdörtgen, bir degrade dikdörtgen, çok renkli bir dikdörtgen ve çok renkli bir metin.

### HTML Canvas Nedir ?
HTML ``<canvas>`` öğesi, JavaScript aracılığıyla anında grafik çizmek için kullanılır. ``<canvas>`` Eleman grafikler için sadece bir kaptır. Grafikleri gerçekten çizmek için JavaScript kullanmalısınız.

Canvas, yollar, kutular, daireler, metin çizmek ve resim eklemek için çeşitli yöntemlere sahiptir. Canvas, bir HTML sayfasındaki dikdörtgen bir alandır. Varsayılan olarak, bir tuvalin kenarlığı ve içeriği yoktur.

İşaretleme şöyle görünür:
```html
<canvas id="myCanvas" width="200" height="100"></canvas>
```

## HTML SVG Graphics
SVG, vektör tabanlı grafikleri XML biçiminde tanımlar.

SVG nedir?
* SVG, Ölçeklenebilir Vektör Grafikleri anlamına gelir
* SVG, Web için grafikleri tanımlamak için kullanılır
* SVG, bir W3C önerisidir

### The HTML < svg > Element
HTML ``<svg>`` öğesi, SVG grafikleri için bir kapsayıcıdır.</br>
SVG'nin yollar, kutular, daireler, metin ve grafik görüntüleri çizmek için çeşitli yöntemleri vardır.

#### SVG ve Canvas Arasındaki Farklar
SVG, XML'de 2D grafikleri tanımlamak için kullanılan bir dildir.</br>
Canvas, anında (bir JavaScript ile) 2D grafikler çizer.</br>
SVG, XML tabanlıdır; bu, her öğenin SVG DOM içinde mevcut olduğu anlamına gelir. Bir öğe için JavaScript olay işleyicileri ekleyebilirsiniz.</br>
SVG'de çizilen her şekil bir nesne olarak hatırlanır. Bir SVG nesnesinin öznitelikleri değiştirilirse, tarayıcı şekli otomatik olarak yeniden oluşturabilir.</br>
Canvas, piksel piksel işlenir. Tuvalde, grafik çizildikten sonra tarayıcı tarafından unutulur. Konumunun değiştirilmesi gerekiyorsa, grafiğin kapsadığı nesneler de dahil olmak üzere tüm sahnenin yeniden çizilmesi gerekir.</br>

---

## HTML Web Storage Api
### HTML Web Depolama Nedir?
Web depolama ile web uygulamaları, verileri kullanıcının tarayıcısında yerel olarak depolayabilir.

HTML5'ten önce, uygulama verilerinin her sunucu isteğine dahil olan çerezlerde saklanması gerekiyordu. Web depolaması daha güvenlidir ve büyük miktarda veri web sitesi performansını etkilemeden yerel olarak depolanabilir.

Çerezlerin aksine, depolama limiti çok daha büyüktür (en az 5MB) ve bilgiler asla sunucuya aktarılmaz.

Web depolama, kaynak başınadır (etki alanı ve protokol başına). Tek bir kaynaktan tüm sayfalar aynı verileri depolayabilir ve bunlara erişebilir.

### HTML Web Storage Objects
HTML web depolama, istemcide veri depolamak için iki nesne sağlar:

* window.localStorage - son kullanma tarihi olmayan verileri depolar
* window.sessionStorage - bir oturum için veri depolar (tarayıcı sekmesi kapatıldığında veriler kaybolur)

Web depolamayı kullanmadan önce localStorage ve sessionStorage için tarayıcı desteğini kontrol edin:
```js
if (typeof(Storage) !== "undefined") {
  // Code for localStorage/sessionStorage.
} else {
  // Sorry! No Web Storage support..
}
```


> [!TIP]
> More About HTML Documents https://www.w3schools.com/html/default.asp

<h3>------------------------------------------------ End line ------------------------------------------------</h3>









