---

---




### Main Fonksiyonu

Program icrasının bir sonraki satırda başlayacağını gösteren tek satırlık yorumdur.
```cpp
int main()
```
Her C++ programının bir parçasıdır. Main'den sonraki parantezler, main'in fonksiyon olarak adlandırılan program yapılandırma bloğu olduğunu gösterir. C++ programları tipik olarak bir ya da daha fazla fonksiyon ve sınıf içerir. C++ programları, programda tanımlanan ilk fonksiyon olmasa bile main fonksiyonundan çalışmaya başlar. Main'in solundaki int anahtar kelimesi bu fonksiyonun tamsayı bir değer döndüreceğini belirtir. Anahtar kelimeler C++ tarafından özel bir kullanım için ayrılmış kelimelerdir. Tüm C++ anahtar kelimelerinin listesi Şekil 4.3'te görülebilir. Bir Fonksiyonlarımızı oluştururken göreceğiz. Şimdilik her programınızda main fonksiyonun soluna int anahtarı kelimesini ekleyin.

### Çıktı İfadesi
```cpp
std::cout <<  "Welcome to C++\n";       //mesajı göster
```
Çift tırnak içersindeki karakterlerin yazılması işleminin gerçekleştirilmesini bilgisayara bildirir. Çift tırnak içersindeki Çift tırnak içersindeki karakterler ve tırnak işaretleri karakter dizini ya da katar olarak adlandırılır. Bu dokümanda, çift tırnak içersindeki karakterler karakter dizini olarak ifade edilmektedir. ! Karakter dizeleri içersindeki boşluk karakteri derleyici tarafından göz ardı edilmez.

std::cout << komutu, "welcome to C++\n" ve noktalı virgül ( ; ) içeren 8. satırın tümü ifade olarak adlandırılır. Birçok C++ ifadesi, ifade sonlandırıcı olarak bilinen noktalı virgül ile sona erer (bazı istisnai durumları yakında göreceksiniz.)
#include gibi ön-işlem komutları noktalı virgül ile bitmez. Tipik olarak C++'da girdi ve çıktı, karakterler ile gerçekleştirilir. Bundan dolayı, bir önceki ifade gerçekleştirilirken, Welcome to C++!\n karakter dizini, ekrana bağlı olan std::cout standart çıktı akış nesnesine gönderilir.

### Std name space

Cout'dan önceki std:: ifadesi, önişlemci komutu olan #include<iostream> ile programa dahill ettiğimiz fonksiyonlar için gereklidir. Std::cout gösterimi, std isim uzayına ait bir komut (örneğin burada cout) kullandığımızı belirtir. Unit 1 de gördüğümüz cin (standart girdi komutu) ve cerr (standart hata koşulu) komutları da std isim uzayına aittirler. İsim uzayları Diğer Konular isimli 23. Ünite'de derinlemesine incelenecek ileri seviye bir konudur. Şimdilik, gördüğümüz her cout, cin ve cerr komutunun önüne std:: koymamız gerek.

### Akış Ekleme Operatörü ve Kaçış Dizileri

Çıktı ifadesindeki << operatörü akış ekleme operatörü olarak isimlendirilir. Bu program çalışırken operatörün sağındaki değer çıktı akışına eklenir. Operatör, verinin gittiği yeri işaret eder. Normalde çift tırnak arasındaki karakter dizisini içersinde bulunan tüm karkter dizisi içersinde bulunan tüm karakterler görüldüğü şekilde yazılır. Fakat \n karakterleri ekrana yazılmaz Ters eğik çizgi (\) kaçış karakteri olarak adlandırılır. Bu, "özel" bir karakterin çıktı olacağını gösterir. Karakter dizisini içersinde ters eğik çizgiyle karşılaşıldığında bir sornaki karakter ile birleşerek bir kaçış dizisi oluştururlar. \n kaçış dizisi yeni satır mana
Sına gelir ve ekranda imlecin yeni satırın başına gelmesini sağlar. Bazı genel kaçış dizileri Şekil 2.2'de listelenmiştir.

| Kaçış dizisi | Tanım                                                           |
|--------------|-----------------------------------------------------------------|
| \n   | Yeni satır. İmleci bir sornaki satırın başına götürür.                  |
| \t   | Yatay sekme İmleci bir sornaki sekmeye kaydırır.                        |
| \r   | Satır başı. İmleci yeni satıra geçirmeyip, aynı satırın başına götürür. |
| \a   | Alarm. Sistem zil sesinin çıkmasını sağlar.                             |
| \\\\ | Ters eğik çizgi karakterinin yazılmasını sağlar.                        |
| \'   | Tek tırnak. Tek tırnak karakterinin yazılmasını sağlar.                 |
| \''  | Çift tırnak. Çift tırnak karakterinin yazılmasını sağlar.               |

### Return ifadesi
```cpp
return 0;  // programın başarıyla sonlandığını belirtir.
```
Fonksiyondan çıkmak için kullanılan ifadelerden biridir. return ifadesi, burada görüldüğü şekilde main fonksiyonunun sonunda kullanıldığında, 0 değeri programın başarıyla sonlandırıldığı gösterir. 11. satırdaki sağ küme parantezi ( } ) main fonksiyonunun bittiğini gösterir. C++ standartlarına göre, eğer program return ifadesine rastlamadan main fonksiyonunun sonuna gelirse, aynı sonunda return 0 varmış gibi programın başarıyla sonlandığını varsayar. Bu nedenle, sonraki programlarımızda main fonksiyonlarının sonunda return ifadesini kullanmayacağız.

### Değişken Bildirimleri
```cpp
    int number1 = 0;     // toplanacak ilk tamsayı (ilk değer olarak 0 verilmiştir.)
    int number2 = 0;     // toplanacak ikinci tamsayı (ilk değer olarak 0 verilmiştir.)
    int sum = 0;         // number1 ve number2'nin toplamı (ilk değer olarak 0 verilmiştir.)
```
Bildirimlerdir. Number1, number2 ve sum tanımlayıcıları değişken isimleridir. Değişken, bir değerin program tarafından kullanılması için depolanabileceği bilgisayar hafızasındaki yerdir. Bu bildirimler, number1, number2 ve sum değişkinlerinin veri tipinin (türünün) tamsayı manasına gelen int olduğunda belirtir. Örneğin 7,-10,0, 31914 vb. Bu bildirimler değişkenlerin ilk değerlerini 0 olarak da belirlenmiştir.

Her değişken, program içersinde kullanılmadan önce bir isim ve veri tipi ile birlikte bildirilmelidir. Aynı tipteki birkaç değişken tek bir bildirim ile tanımlanabileceği gibi çoklu bildirim ile de tanımlanabilir. Her üç değişkeni virgül ile ayrılmış liste kullanarak tek bir bildirim ile aşağıdaki şekilde tanımlayabiliriz:
```cpp
    int number1 = 0 , number2 = 0 , sum = 0;
```
Bu şekilde program daha az okunabilir olur ve her değişkenin amacını tanımlayan yorumları görmenizi engeller.

### Aritmetik

Çoğu program aritmetik hesaplamaları gerçekleştirmektedir. Aşağıdaki tabloda C++ aritmektik operatörlerini özetlemektedir. Cebirde kullanılmayan çeşitli özel sembollerin kullanımına dikkat edelim. Yıldız işareti (*) çarpma işlemini ifade eder, yüzde işareti (%) mod alma operatörüdür. Aritmetik operatörler iki adet işlenen alan ikili operatörlerdir. Örneğin number1 + number2 ifadesi, + ikili operatörünü ve number1 ve number2 isimli iki adet işleneni içerir.

Pay ve paydanın tamsayı olduğu tamsayı bölme işlemi tamsayı olan bir bölüm verir; örneğin 7/4 ifadesi sonuç olarak 1, ve 17/5 ifadesi de sonuç olarak 3 üretir. Tamsayı bölme işlemindeki ondalık kısımlar ihmal edilir.

| İşlem   | C++ aritmetik operatörü | Cebirsel ifade  | C++ ifadesi |
|---------|-------------------------|-----------------|-------------|
| Toplama | +                       | f + 7           | f + 7       |
| Çıkarma | -                       | p - c           | p - c       |
| Çarpma  | *                       | bm ya da b .  m | b * m       |
| Bölme   | /                       | x/y  ya da x/y  | x/y         |
| Mod     | %                       | r mod s         | r % s       |















