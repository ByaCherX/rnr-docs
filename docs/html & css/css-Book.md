
<h1 style="text-align:center">CSS Book <i class="bi bi-book"></i></h1>
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../lib/html&css_book.css">

## CSS Syntax
Bir CSS kuralı, bir seçici ve bir bildirim bloğundan oluşur. Seçici, stil vermek istediğiniz HTML öğesini işaret eder. Bildirim bloğu, noktalı virgülle ayrılmış bir veya daha fazla bildirim içerir. Her bildirim, iki nokta üst üste ile ayrılmış bir CSS özellik adı ve bir değer içerir. Birden çok CSS bildirimi noktalı virgülle ayrılır ve bildirim blokları küme parantezleriyle çevrilidir.

## CSS Selector
CSS seçicileri, stil vermek istediğiniz HTML öğelerini "bulmak" (veya seçmek) için kullanılır.</br>
CSS seçicilerini beş kategoriye ayırabiliriz:
* Basit seçiciler (ad, kimlik, sınıfa göre öğeleri seçin)
* Birleştirici seçiciler (aralarındaki belirli bir ilişkiye göre öğeleri seçin)
* Sözde sınıf seçiciler (belirli bir duruma göre öğeleri seçin)
* Sözde öğe seçiciler (bir öğenin bir bölümünü seçin ve stil verin)
* Nitelik seçiciler (bir nitelik veya nitelik değerine göre öğeleri seçin)

### CSS Selector
- Element Selector ( p {} )
- Id Selector ( #id {} )
- Class Selector ( .class {} ) & ( p.class {} )
- Universal Selector ( * {} )
- Grouping Selector ( h1,h2,p {} )

## CSS Commet

```css
/* This is a single-line comment */
```
### CSS Commet & HTML Commet
```html
<style>
p {
  color: red;  /* Set text color to red */ 
}
</style>
<!-- These paragraphs will on html page -->
```

## CSS Background
### Background Color
``background-color`` Nitelik bir elemanın arka plan rengini belirler.
```css
body {background-color: lightblue;}
```
### Background Image
background-imageNitelik bir elemanın arka plan olarak kullanmak üzere bir görüntü belirtir.
```css
body {background-image: url("paper.gif");}
```
### Background Repat
Varsayılan olarak, ``background-image`` özellik bir görüntüyü hem yatay hem de dikey olarak tekrarlar.
```css
background-repeat: repeat-x;
```

## CSS Border
``border-style`` Ekran sınırlarını belirtir.</br>
Aşağıdaki değerlere izin verilir:
* **dotted** - Noktalı bir kenarlık tanımlar
* **dashed** - Kesikli bir kenarlık tanımlar
* **solid** - Katı bir sınır tanımlar
* **double** - Çift kenarlık tanımlar
* **groove** - 3B oluklu bir kenarlık tanımlar. Etki, kenarlık rengi değerine bağlıdır
* **ridge** - 3B çıkıntılı kenarlık tanımlar. Etki, kenarlık rengi değerine bağlıdır
* **inset** - Bir 3B iç kenarlık tanımlar. Etki, kenarlık rengi değerine bağlıdır
* **outset** - Bir 3B başlangıç ​​sınırı tanımlar. Etki, kenarlık rengi değerine bağlıdır
* **none** - Sınır tanımlamaz
* **hidden** - Gizli bir sınır tanımlar

## CSS Margin
CSS ``margin`` özellikleri, tanımlanmış sınırların dışında, öğelerin etrafında boşluk oluşturmak için kullanılır.</br>
CSS, bir öğenin her bir tarafı için kenar boşluğunu belirtmek için özelliklere sahiptir:
* margin-top
* margin-right
* margin-bottom
* margin-left

Tüm kenar boşluğu özellikleri aşağıdaki değerlere sahip olabilir:</br>
* auto - tarayıcı marjı hesaplar
* length - px, pt, cm, vb. cinsinden bir kenar boşluğu belirtir.
* % - içeren öğenin genişliğinin %'si olarak bir kenar boşluğu belirtir
* inherit - kenar boşluğunun üst öğeden devralınması gerektiğini belirtir

## CSS Padding
CSS ``padding`` özellikleri, herhangi bir tanımlanmış sınırların içinde bir öğenin içeriğinin etrafında boşluk oluşturmak için kullanılır.

CSS, bir öğenin her bir tarafı için dolguyu belirtmek için özelliklere sahiptir:
* padding-top
* padding-right
* padding-bottom
* padding-left

## CSS Height
CSS ``height`` ve ``width`` özellikler, bir öğenin yüksekliğini ve genişliğini ayarlamak için kullanılır.

``height`` Ve ``width`` özellikleri aşağıdaki değerlere sahip olabilir:

* **auto** - Bu varsayılandır. Tarayıcı yüksekliği ve genişliği hesaplar
* **length** - Yüksekliği/genişliği px, cm vb. cinsinden tanımlar.
* **%** - İçerdiği bloğun yüksekliğini/genişliğini yüzde olarak tanımlar
* **initial** - Yüksekliği/genişliği varsayılan değerine ayarlar
* **inherit** - Yükseklik/genişlik, ana değerinden devralınır

## CSS Box Model /lts!
CSS'de tasarım ve yerleşimden bahsederken "kutu modeli" terimi kullanılır.

CSS kutu modeli aslında her HTML öğesinin etrafını saran bir kutudur. Şunlardan oluşur: kenar boşlukları, kenarlıklar, dolgu ve gerçek içerik. Aşağıdaki resim kutu modelini göstermektedir:

* Content - Metin ve resimlerin göründüğü kutunun içeriği
* Padding - İçeriğin etrafındaki alanı temizler. dolgu şeffaftır
* Border - Dolgu ve içeriği çevreleyen bir kenarlık
* Margin - Sınırın dışındaki bir alanı temizler. Kenar boşluğu şeffaf

## CSS Outline
``outline-style`` Property anahat stilini belirtir ve aşağıdaki değerlerden birine sahip olabilir:

CSS, aşağıdaki anahat özelliklerine sahiptir:
* ``outline-style``
* ``outline-color``
* ``outline-width``
* ``outline-offset``
* ``outline``

### CSS Outline Style
``outline-style`` Property anahat stilini belirtir ve aşağıdaki değerlerden birine sahip olabilir:
* **dotted** - Noktalı bir anahat tanımlar
* **dashed** - Kesikli bir anahat tanımlar
* **solid** - Sağlam bir anahat tanımlar
* **double** - Çift anahat tanımlar
* **groove** - 3B oluklu bir anahat tanımlar
* **ridge** - 3B çıkıntılı bir anahat tanımlar
* **inset** - Bir 3B ek anahat tanımlar
* **outset** - Bir 3B başlangıç ​​taslağı tanımlar
* **none** - Anahat tanımlamaz
* **hidden** - Gizli bir anahat tanımlar

## CSS Text
### Text Color 
color Property metnin rengini ayarlamak için kullanılır. Renk şu şekilde belirtilir:
* bir renk adı - "red" gibi
* bir HEX değeri - "#ff0000" gibi
* bir RGB değeri - "rgb(255,0,0)" gibi
```css
h2 {color:red;}
```

### Text Aligment
text-alignTesisinde metnin yatay hizalama ayarlamak için kullanılır. Bir metin sola veya sağa hizalanmış, ortalanmış veya iki yana yaslanmış olabilir.
```css
h2 {text-align: $element;}
```

### Text Decoration
``text-decoration`` Property metinden seti veya kaldır süslemeleri için kullanılır.
```css
p {text-decoration: overline;}
```

### Text Transform
``text-transform`` Property Büyük harfle ve bir metinde küçük harfleri belirtmek için kullanılır.
```css
p.uppercase {text-transform: uppercase;}
```

### Text Spacing /lts!
``text-indent`` Tesiste metnin ilk satırının girinti belirtmek için kullanılır:

## CSS Font
CSS'de beş genel yazı tipi ailesi vardır:

* **Serif** yazı tiplerinde her harfin kenarlarında küçük bir çizgi bulunur. Bir formalite ve zarafet duygusu yaratırlar.
* **Sans-serif** yazı tiplerinde temiz çizgiler vardır (küçük vuruşlar eklenmez). Modern ve minimalist bir görünüm yaratırlar.
* **Monospace** yazı tipleri - burada tüm harfler aynı sabit genişliğe sahiptir. Mekanik bir görünüm yaratırlar. 
* **Cursive** yazı insan el yazısı taklit.
* **Fantasy** yazı tipleri dekoratif/eğlenceli yazı tipleridir.

| Generic Font Family | Examples of Font Names |
|---------------------|------------------------|
| Serif               | <l style="font-family:'Times New Roman'">Times New Roman</l></br><l style="font-family:'Georgia'">Georgia</l></br><l style="font-family:'Garamond'">Garamond</l>|
| Sans-serif          | <l style="font-family:'Arial'">Arial</l></br><l style="font-family:'Verdana'">Verdana</l></br><l style="font-family:'Helvetica'">Helvetica</l> |
| Monospace           | <l style="font-family:Courier New">Courier New</l></br><l style="font-family:Lucida Console">Lucida Console</l></br><l style="font-family:Monaco">Monaco</l> |
| Cursive             | <l style="font-family:Brush Script MT">Brush Script MT</l></br><l style="font-family:Lucida Handwriting">Lucida Handwriting</l> |
| Fantasy             | <l style="font-family:Copperplate,fantasy">Copperplate</l></br><l style="font-family:Papyrus,fantasy">Papyrus</l> |

> [!IMPORTANT]
> ``font-family`` tarayıcılar / işletim sistemleri arasındaki maksimum uyumluluğu sağlamak için, "fallback" sistemi olarak birçok yazı adlarını tutmak gerekir. İstediğiniz yazı tipiyle başlayın ve genel bir aile (Generic Font Family) ile bitirin. Yazı tipi adları virgülle ayrılmalıdır.

### Font Styles
``font-style`` Property çoğunlukla italik metnini belirtmek için kullanılır.

Bu özelliğin üç değeri vardır:
* Normal - Metin normal olarak gösterilir (normal text)
* Italic - Metin italik olarak gösterilir (*italic text*)
* Oblique - Metin "eğik" (eğik italiğe çok benzer, ancak daha az desteklenir) ()

``font-weight`` Property yazı tipinin ağırlığını belirtir:
* Normal - normal yazı tipi (Normal text)
* Bold - Kalın yazı tipi (**Bold text**)

``font-variant`` Bir metin küçük kapaklar görüntülenmesi gereken olup olmadığını özellik belirtir yazı tipi.
* normal- normal yazı tipidir. (normal text)
* small-caps - Küçük harfli bir yazı tipinde, tüm küçük harfler büyük harflere dönüştürülür. (<span style="font-variant:small-caps">small-caps text</span>)

### Font Size
``font-size`` Property metnin boyutunu ayarlar.</br>

Web tasarımında metin boyutunu yönetebilmek önemlidir. Ancak, paragrafların başlıklar veya başlıkların paragraflar gibi görünmesi için yazı tipi boyutu ayarlamalarını kullanmamalısınız.

Her zaman başlıklar için ``<h1> - <h6>`` ve paragraflar için ``<p>`` gibi uygun HTML etiketlerini kullanın.

### Font Google
HTML'de standart yazı tiplerinden herhangi birini kullanmak istemiyorsanız Google Yazı Tiplerini kullanabilirsiniz. Google Yazı Tiplerini kullanmak ücretsizdir ve aralarından seçim yapabileceğiniz 1000'den fazla yazı tipi vardır.
```css
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=*FontFamily*">
```

## CSS Icon
Simgeler, bir simge kitaplığı kullanılarak HTML sayfanıza kolayca eklenebilir. CSS Icon Bootstrap iconu kullanmaktadır.
```html
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
```
> [!TIP]
> Bootstrap CSS için en iyi icon kütüphanesidir ve default olarak rds-docs belgelerine eklenir. Daha fazla bilgi için: https://icons.getbootstrap.com/

## CSS Link
Bağlantılar herhangi bir CSS özelliği ile biçimlendirilebilir (örn. color, font-family, background, vb.). Ek olarak, bağlantıların hangi durumda olduklarına bağlı olarak farklı şekilde biçimlendirilebilir .

Dört bağlantı durumu şunlardır:
* ``a:link`` - normal, ziyaret edilmemiş bir bağlantı
* ``a:visited`` - kullanıcının ziyaret ettiği bir bağlantı
* ``a:hover`` - kullanıcı fareyi üzerine getirdiğinde bir bağlantı
* ``a:active`` - tıklandığı anda bir bağlantı

### Link Other Property
* ``text-declaration:`` &none; &underline;

## CSS List
HTML'de iki ana liste türü vardır:
* sırasız listeler (``<ul>``) - liste öğeleri madde işaretleri ile işaretlenmiştir.
* sıralı listeler (``<ol>``) - liste öğeleri sayılar veya harflerle işaretlenmiştir.

CSS listesi özellikleri şunları yapmanızı sağlar:
* Sıralı listeler için farklı liste öğesi işaretçileri ayarlayın
* Sırasız listeler için farklı liste öğesi işaretçileri ayarlayın
* Liste öğesi işaretçisi olarak bir resim ayarlayın
* Listelere ve liste öğelerine arka plan renkleri ekleyin

## CSS Table
Bir HTML tablosunun görünümü CSS ile büyük ölçüde geliştirilebilir

- CSS'de tablo kenarlıkları belirtmek için ``border`` özelliği kullanın.
- ``border-collapse`` Sınırlar tek sınıra içine çökme gerekip gerekmediğini belirtir.

## CSS Display
``display`` Property düzenini kontrol etmek için en önemli CSS özelliktir.
* none - herhangi bir şey yapmaz yani görüntü vermez
* inline - &??
* block - &??

## CSS Layout
``position`` Özelliği, bir element için kullanılan yerleştirme yöntemi türünü belirtir.

Beş farklı konum değeri vardır:
* ``static``
* ``relative``
* ``fixed``
* ``absolute``
* ``sticky``

### Position: Static
HTML öğeleri varsayılan olarak statik olarak konumlandırılır. Statik konumlu elemanlar top, bottom, left ve right özelliklerden etkilenmez.

Bir eleman position: static; herhangi bir özel şekilde konumlandırılmamıştır; her zaman sayfanın normal akışına göre konumlandırılır:
```css
div.static { 
  position: static; 
  border: 3px solid #73AD21; }
```

### Position: Relative
``position: relative;`` İle bir eleman, normal konumuna göre konumlandırılır.

Göreceli olarak konumlandırılmış bir elemanın top, right, alt ve left özelliklerinin ayarlanması, normal konumundan uzağa ayarlanmasına neden olacaktır. Diğer içerik, öğenin bıraktığı boşluğa sığacak şekilde ayarlanmayacaktır.

```css
div.relative {}
```

### Position: Fixed
Bir öğe ``position: fixed;`` görünüm alanına göre konumlandırılır, yani sayfa kaydırılsa bile her zaman aynı yerde kalır. Öğeyi konumlandırmak için üst, sağ, alt ve sol özellikler kullanılır. Sabit bir öğe, normalde bulunduğu yerde sayfada bir boşluk bırakmaz.

Sayfanın sağ alt köşesindeki sabit öğeye dikkat edin. İşte kullanılan CSS:
```css
div.fixed {}
```

### Position: Absolute
``position: absolute;`` ile bir öğe , en yakın konumlandırılmış ataya göre konumlandırılır.

Yine de; mutlak konumlandırılmış bir öğenin konumlandırılmış ataları yoksa, belge gövdesini kullanır ve sayfa kaydırma ile birlikte hareket eder.

Not: Mutlak konumlandırılmış öğeler normal akıştan çıkarılır ve öğelerle örtüşebilir.
```css
div.absolute
```

### Position: Sticky
``position: sticky;`` ile bir öğe, kullanıcının kaydırma konumuna göre konumlandırılır.

Yapışkan bir öğe, kaydırma konumuna bağlı olarak ``relative`` ve ``fixed`` arasında geçiş yapar.  Görünüm alanında belirli bir offset konumu karşılanana kadar göreli olarak konumlandırılır - ardından yerine "yapışır" (position:fixed gibi).

## CSS Overflow
``overflow`` özelliği, bir alana sığmayacak kadar büyük olan içeriğe ne olacağını kontrol eder.

overflowÖzellik şu değerlere sahiptir:
* ``visible``- Varsayılan. Taşma kırpılmaz. İçerik, öğenin kutusunun dışında işleniyor
* ``hidden`` - Taşma kırpılır ve içeriğin geri kalanı görünmez olur
* ``scroll`` - Taşma kırpılır ve içeriğin geri kalanını görmek için bir kaydırma çubuğu eklenir
* ``auto``- Benzer scroll, ancak yalnızca gerektiğinde kaydırma çubukları ekler

### Overflow: Visible
Varsayılan olarak, taşma şeklindedir visible, yani kırpılmaz ve öğe kutusunun dışında işlenir.

### Overflow: Hidden
``hidden`` değeri, taşma kırpılır ve içeriğin geri kalanı gizlenir.

### Overflow: Scrool
Değer olarak ``scroll`` ayarlandığında, taşma kırpılır ve kutunun içinde gezinmek için bir kaydırma çubuğu eklenir. Bunun hem yatay hem de dikey olarak bir kaydırma çubuğu ekleyeceğini unutmayın (ihtiyacınız olmasa bile)

### Overflow: Auto
``auto`` Değer benzer ``scroll``, ancak yalnızca gerektiğinde kaydırma çubukları ekler.

## CSS Float
CSS ``float`` özelliği, bir öğenin nasıl yüzeceğini belirtir.</br>
CSS ``clear`` özelliği, temizlenen öğenin yanında ve hangi tarafta hangi öğelerin yüzebileceğini belirtir.

``float`` Özelliği konumlandırılması ve örneğin içeriği bir kap metinlerin sol görüntü şamandıra izin biçimlendirmek için kullanılır.

``float`` Property aşağıdaki değerlerden birine sahip olabilir:
* ``left`` - Öğe, bulunduğu kabın solunda yüzer
* ``right`` - Öğe, bulunduğu kabın sağında yüzer
* ``none``- Öğe havada durmaz (metinde geçtiği yerde görüntülenecektir). Bu varsayılan
* ``inherit`` - Öğe, ebeveyninin kayan nokta değerini devralır

### Clear Property
``clear`` Property aşağıdaki değerlerden birine sahip olabilir:
* ``none``- Öğe, sol veya sağ kayan öğelerin altına itilmez. Bu varsayılan
* ``left`` - Öğe, soldaki kayan öğelerin altına itilir
* ``right`` - Öğe, sağa kayan öğelerin altına itilir
* ``both`` - Öğe, hem sol hem de sağ kayan öğelerin altına itilir
* ``inherit`` - Öğe, net değeri ebeveyninden miras alır

## CSS Pseudo-class
Bir öğenin özel bir durumunu tanımlamak için bir sözde sınıf kullanılır.

Örneğin, aşağıdakiler için kullanılabilir:
- Bir kullanıcı fareyle üzerine geldiğinde bir öğeye stil verin
- Ziyaret edilen ve ziyaret edilmeyen bağlantıları farklı şekilde stillendirin
- Odaklandığında bir öğeye stil verin

```css
div {background-color: red;}
div:hover {background-color: blue;} /*Fare ile üzerinize geldiğinizde arka plan rengi mavi olur*/
```

## CSS Nav
Kullanımı kolay navigasyona sahip olmak, herhangi bir web sitesi için önemlidir. CSS ile sıkıcı HTML menülerini güzel görünümlü gezinme çubuklarına dönüştürebilirsiniz.

Bir gezinme çubuğu, temel olarak standart HTML'ye ihtiyaç duyar.

Gezinme çubuğu temel olarak bir bağlantı listesidir, bu nedenle ``<ul>`` ve ``<li>`` öğelerini kullanmak son derece mantıklıdır:
```html
<ul>
  <li><a href=""></a></li>
  ...
</ul>
```

## CSS Attr Selectors
Belirli niteliklere veya nitelik değerlerine sahip HTML öğelerine stil vermek mümkündür.

``[attribute]`` Seçici belirli bir özelliği olan unsurları seçmek için kullanılır.

Aşağıdaki örnek, bir hedef özniteliği olan tüm ``<a>`` öğelerini seçer:
```css
a[target] {background-color: red;}
```

### Attr Selector list
* a [ `&`attiribute="`&`value" ]
* a [ `&`attribute~="`&`value" ]
* a [ `&`attribute|="`&`value" ]
* a [ `&`attribute^="`&`value" ]
* a [ `&`attribute$="`&`value" ]
* a [ `&`attribute*="`&`value" ]

## CSS Form
### Styling Input Field
* ``input[type=text]`` - sadece metin alanlarını seçecek
* ``input[type=password]`` - sadece şifre alanlarını seçecek
* ``input[type=number]`` - sadece sayı alanlarını seçecek

## CSS Website Layout
Bir web sitesi genellikle üstbilgilere, menülere, içeriğe ve altbilgiye bölünür:

:::image type="content" source="../media/website_layout.png" alt-text="website_layout":::


## CSS Unit
CSS, bir uzunluğu ifade etmek için birkaç farklı birime sahiptir. Mutlak uzunluk birimleri sabittir ve bunlardan herhangi birinde ifade edilen bir uzunluk tam olarak bu boyutta görünecektir. Ekran boyutları çok farklı olduğundan, mutlak uzunluk birimlerinin ekranda kullanılması önerilmez. Ancak, çıktı ortamı biliniyorsa, örneğin baskı düzeni için kullanılabilirler.

### Absolute Lengths
| Unit | Description                  |
|------|------------------------------|
| cm   | centimeters                  |
| mm   | millimeters                  |
| in   | inches (1in = 96px = 2.54cm) |
| px * | pixels (1px = 1/96th of 1in) |
| pt   | points (1pt = 1/72 of 1in)   |
| pc   | picas (1pc = 12 pt)          |

### Relative Lengths
| unit | description                  |
|------|------------------------------|
| em   | Relative to the font-size of the element (2em means 2 times the size of the current font) |
| ex   | Relative to the x-height of the current font (rarely used) |
| ch   | Relative to width of the "0" (zero)                        |
| rem  | Relative to font-size of the root element                  |
| vw   | Relative to 1% of the width of the viewport*               |
| vh   | Relative to 1% of the height of the viewport*              |
| vmin | Relative to 1% of viewport's* smaller dimension            |
| vmax | Relative to 1% of viewport's* larger dimension             |
| %    | Relative to the parent element                             |

## CSS Important
CSS'deki ``!important`` kural, bir özelliğe/değere normalden daha fazla önem vermek için kullanılır.

Aslında, ``!important`` kuralı kullanırsanız , o öğedeki o belirli özellik için önceki TÜM stil kurallarını geçersiz kılar!

> [!IMPORTANT]
> Bir kuralı geçersiz kılmanın tek yolu ``!important`` kullanmaktır., kaynak kodunda aynı (veya daha yüksek) özgüllüğe sahip bir bildirime başka bir kural eklemektir - ve işte sorun burada başlıyor! Bu, CSS kodunu kafa karıştırıcı hale getirir ve özellikle büyük bir style sayfanız varsa hata ayıklamak zor olacaktır!

<h1 style="text-align:center">CSS Advanced</h1>








