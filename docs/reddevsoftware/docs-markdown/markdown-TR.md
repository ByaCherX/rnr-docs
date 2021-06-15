<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<img src="../../media/index/markdown-mark-white.svg" alt="MarkdownLogo" class="center">
<h1 style="text-align: center">Markdown Language Documents <sub class="trlng">TR</sub> </h1>

## What is Markdown 
---
Markdown, düz metin metin belgelerine biçimlendirme öğeleri eklemek için kullanabileceğiniz hafif bir biçimlendirme dilidir. 2004 yılında John Gruber tarafından oluşturulan Markdown, şu anda dünyanın en popüler biçimlendirme dillerinden biridir.

### Why use Markdown
---
- Markdown her şey için kullanılabilir. İnsanlar bunu web siteleri, belgeler, notlar, kitaplar, sunumlar, e-posta mesajları ve teknik belgeler oluşturmak için kullanır.

- Markdown taşınabilir. Markdown formatlı metin içeren dosyalar hemen hemen her uygulama kullanılarak açılabilir. Şu anda kullanmakta olduğunuz Markdown uygulamasını beğenmediğinize karar verirseniz, Markdown dosyalarınızı başka bir Markdown uygulamasına aktarabilirsiniz. Bu, içeriğinizi özel bir dosya biçimine kilitleyen Microsoft Word gibi sözcük işleme uygulamalarının tam tersidir.

- Markdown, platformdan bağımsızdır. Herhangi bir işletim sistemini çalıştıran herhangi bir cihazda Markdown formatlı metin oluşturabilirsiniz.

- Markdown geleceğin kanıtıdır. Kullandığınız uygulama gelecekte bir noktada çalışmayı durdursa bile, bir metin düzenleme uygulaması kullanarak Markdown formatlı metninizi yine de okuyabileceksiniz. Bu, süresiz olarak korunması gereken kitaplar, üniversite tezleri ve diğer dönüm noktası belgeleri söz konusu olduğunda önemli bir husustur.

- Markdown her yerde. Reddit ve GitHub gibi web siteleri Markdown'ı destekler ve birçok masaüstü ve web tabanlı uygulama bunu destekler.

### How Does it Work?
---
Markdown uygulamaları , Markdown formatlı metni almak ve HTML formatına çıkarmak için Markdown işlemcisi (aynı zamanda “ayrıştırıcı” veya “uygulama” olarak da anılır) olarak adlandırılan bir şey kullanır . Bu noktada belgeniz bir web tarayıcısında görüntülenebilir veya bir stil sayfasıyla birleştirilebilir ve yazdırılabilir. Aşağıda bu işlemin görsel bir temsilini görebilirsiniz.

### What does Markdown do?
---
Markdown, not almanın, bir web sitesi için içerik oluşturmanın ve baskıya hazır belgeler üretmenin hızlı ve kolay bir yoludur.

Markdown sözdizimini öğrenmek uzun sürmez ve nasıl kullanılacağını öğrendikten sonra hemen her yerde Markdown kullanarak yazabilirsiniz. Çoğu kişi, web için içerik oluşturmak için Markdown'ı kullanır, ancak Markdown, e-posta mesajlarından alışveriş listelerine kadar her şeyi biçimlendirmek için iyidir.

### Support Markdown
---
daha fazla bilgi için ['markdown-support.md'](markdown-support.md) kısmına bakın.

<h1>Basic Syntax</h1>

---

> Neredeyse tüm Markdown uygulamaları, John Gruber'in orijinal tasarım belgesinde özetlenen temel sözdizimini destekler. Markdown işlemcileri arasında küçük farklılıklar ve tutarsızlıklar vardır - bunlar mümkün olan yerlerde satır içi olarak not edilir.

## Header
---
Başlık oluşturmak için #bir kelimenin veya tümcenin önüne sayı işaretleri ( ) ekleyin . Kullandığınız sayı işaretlerinin sayısı başlık seviyesine karşılık gelmelidir. Örneğin, bir başlık düzeyi üç ( `<h3>` ) oluşturmak için üç sayı işareti (örn., ### My Header) kullanın.

| Markdown               | HTML                       | Rendered Output          |
|------------------------|----------------------------|--------------------------|
| # Heading level 1      | `<h1>Heading level 1</h1>` | <h1>Heading level 1</h1> |
| ## Heading level 2     | `<h2>Heading level 2</h2>` | <h2>Heading level 2</h2> |
| ### Heading level 3    | `<h3>Heading level 3</h3>` | <h3>Heading level 3</h3> |
| #### Heading level 4   | `<h4>Heading level 4</h4>` | <h4>Heading level 4</h4> |
| ##### Heading level 5  | `<h5>Heading level 5</h5>` | <h5>Heading level 5</h5> |
| ###### Heading level 6 | `<h6>Heading level 6</h6>` | <h6>Heading level 6</h6> |

## Alternate Syntax
---
Alternatif olarak, metnin altındaki satıra, ==başlık seviyesi 1 için herhangi bir sayıda karakter veya başlık seviyesi 2 için herhangi bir sayıda karakter ekleyin .

| Markdown                               | HTML                       | Rendered Output          |
|----------------------------------------|----------------------------|--------------------------|
| Heading level 1</br> ==========        | `<h1>Heading level 1</h1>` | <h1>Heading level 1</h1> |
| Heading level 2</br> ----------------- | `<h2>Heading level 2</h2>` | <h2>Heading level 2</h2> |

## Paragraphs
---
Paragraf oluşturmak için bir veya daha fazla metin satırını ayırmak için boş bir satır kullanın.

| Markdown | HTML |
|----------|------|
|I really like using Markdown.</br></br>I think I'll use it to format all of my documents from now on.|	`<p>I really like using Markdown.</p>`</br></br>`<p>I think I'll use it to format all of my documents from now on.</p>`|

## Line Breaks
---
Satır sonu (`<br>`) oluşturmak için satırı iki veya daha fazla boşlukla sonlandırın ve ardından return yazın.

| Markdown | HTML |
|----------|------|
|This is the first line.</br>And this is the second line.|`<p>This is the first line.<br>`</br>`And this is the second line.</p>`|

## Bold text
---
Metni kalınlaştırmak için, bir kelimenin veya ifadenin önüne ve arkasına iki yıldız veya alt çizgi ekleyin. Vurgu için bir kelimenin ortasını kalın yapmak için harflerin etrafına boşluk bırakmadan iki yıldız ekleyin.

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|I just love `**bold text**`. | `I just love <strong>bold text</strong>.` | I just love **bold text.**|
|I just love `__bold text__`. | `I just love <strong>bold text</strong>.` | I just love __bold text.__|
|Love`**is**`bold | `Love<strong>is</strong>bold` | Love**is**bold|

## Italic
---
Metni italik yapmak için, bir kelimenin veya tümcenin önüne ve arkasına bir yıldız işareti veya alt çizgi ekleyin. Vurgu için bir kelimenin ortasını italik yapmak için harflerin etrafına boşluk bırakmadan bir yıldız işareti ekleyin.

|Markdown | Html |Rendered Output  |
|---------|------|-----------------|
|Italicized text is the `*cat's meow*`. |Italicized text is the `<em>cat's meow</em>`.|Italicized text is the *cat’s meow*.|
|Italicized text is the `_cat's meow_`. |Italicized text is the `<em>cat's meow</em>`.|Italicized text is the *cat’s meow*.|
|A`*cat*`meow |A`<em>cat</em>`meow|A*cat*meow|
 
## Bold and Italic
---
Metni kalın ve italik olarak aynı anda vurgulamak için, bir kelimenin veya tümcenin önüne ve arkasına üç yıldız veya alt çizgi ekleyin. Vurgu için bir kelimenin ortasını kalın ve italik hale getirmek için harflerin etrafına boşluk bırakmadan üç yıldız işareti ekleyin.

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|This text is `***really important***`. | `This text is <strong><em>really important</em></strong>`. | This text is ***really important***.|

## Blockquotes
---
Blok alıntı oluşturmak `>` için paragrafın önüne bir alıntı ekleyin .

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|> Hello world | `<blockquote>Hello world</blockquote>` | <blockquote>Hello world</blockquote> |
|> Hello</br>></br>> world | `<blockquote> <p>Hello</p><p>world</p> </blockquote>` | <blockquote><p>Hello</p><p>world</p></blockquote> |
|> Hello</br>>> world | `<blockquote> <p>Hello</p><blockquote>world</blockquote> </blockquote>` | <blockquote><p>Hello</p><blockquote>world</blockquote></blockquote> |
|> #### Header</br>> - hello</br>> *world | `<blockquote>`</br>`<h4><p>Header</p></h4> <ul><li>text1</li> <li>text2</li></ul>`</br>`</blockquote>` | <blockquote><h4><p>Header</p></h4><ul><li>text1</li><li>text2</li></ul></blockquote> |

## Lists
---
| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|1. first item</br>2. second item</br>---1. Indented item</br>3. third item | `<ol>`</br>`<li>First item</li><li>Second item</li>`</br>`<ol><li>Indented item</li></ol></li>`</br>`<li>Third item</li>`</br>`</ol>` | <ol><li>First item</li><li>Second item</li><ol><li>Indented item</li></ol></li><li>third item</li></ol> |
|1. first item</br>1. seond item</br>1. third item | `<ol>`</br>`<li>First item</li><li>Second item</li><li>Third item</li>`</br>`</ol>` | <ol><li>First item</li><li>Second item</li><li>Third item</li></ol> |
|- First item</br>* Second item</br>+ Third item</br> ///- Indented item| `<ul>`</br>`<li>First item</li><li>Second item</li><li>Third item`</br>`<ul><li>Indented item</li></ul></li>`</br>`</ul>` | <ul><li>First item</li><li>Second item</li><li>Third item<ul><li>Indented item</li></ul></li></ul> |

## Code Blocks
---

Bir kelimeyi veya tümceyi kod olarak belirtmek için, onu ters tikler ( `) içine alın.

other example

        <html>
          <head>
            <title>Test</title>
          </head>


| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
| At the command prompt, type \`nano.\` | At the command prompt, type `<code>nano</code>.` | At the command prompt, type `nano.` |

## Images
---
örnekteki gibi fotoğraf ekleyebilirsiniz `![markdown svg logo](../../media/index/markdown-mark.svg)`
sonuç şunun gibi olacaktır;<img src="../../media/index/markdown-mark.svg" style="width: 90px;">

## Links
---
Bir bağlantı oluşturmak için, bağlantı metnini parantez içine alın (örn. [github]) ve ardından hemen URL'yi parantez içinde (örn (https://github.com). ) takip edin.

| Markdown | HTML | Rendered Output |
|----------|------|-----------------|
|`[github](https://github.com)`|`<a href="https://github.com">github</a>`|[github](https://github.com)|
|`[github](https://github.com "this is github link")`|`<a href="https://github.com">github</a>`|[github](https://github.com "this is github link")|
|`<https://github.com>`| - |<https://github.com>|
|`**[github link](https://github.com)**`| - |**[github link](https://github.com)**|
| [![image](/assets/images/shiprock.jpg "text")](link) | - | - |

## Escaping Chracters
Aksi takdirde bir Markdown belgesindeki metni biçimlendirmek için kullanılacak değişmez bir karakteri görüntülemek için karakterin önüne bir ters eğik çizgi (`\`) ekleyin.

| Character | Name                                           |
|-----------|------------------------------------------------|
| \         | backslash                                      |
| `         | backtick (see also escaping backticks in code) |
| *         | asterisk                                       |
| _         | underscore                                     |
| { }       | curly braces                                   |
| [ ]       | brackets                                       |
| < >       | angle brackets                                 |
| ( )       | parentheses                                    |
| #         | pound sign                                     |
| +         | plus sign                                      |
| -         | minus sign (hyphen)                            |
| .         | dot                                            |
| !         | exclamation mark                               |
|\|         | pipe (see also escaping pipe in tables)        |





<!--
<h1 style="text-align:center">Compatibility recommendations</h1>

### Header Practices
İşaretleme uygulamaları, sayı işaretleri ( #) ve başlık adı arasındaki eksik boşluğun nasıl ele alınacağı konusunda anlaşamaz . Uyumluluk için, numara işaretleri ile başlık adı arasına her zaman bir boşluk koyun.

| ✅ Do this         | ❌ Don't do this |
|--------------------|-------------------|
| # Here's a Heading | #Here's a Heading |

### Italic Practices
Markdown applications don’t agree on how to handle underscores in the middle of a word. For compatibility, use asterisks to italicize the middle of a word for emphasis.

| ✅ Do this  | ❌ Don't do this |
|------------- |-------------------|
| A`*cat*`meow | A`_cat_`meow    |

### Link Practices
Markdown uygulamaları, bir URL'nin ortasındaki boşlukların nasıl ele alınacağı konusunda hemfikir değildir. Uyumluluk için, boşlukları URL ile kodlamayı deneyin %20.

| ✅ Do this | ❌ Don't do this |
|------------ |------------------|
| `[link](https://www.example.com/my%20great%20page)` | `[link](https://www.example.com/my great page)`|
-->
