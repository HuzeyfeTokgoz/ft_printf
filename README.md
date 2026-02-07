*This project has been created as part of the 42 curriculum by hutokgoz.*

# ft_printf

## 🗣️ Açıklama (Description)

**ft_printf**, standart C kütüphanesindeki `printf` fonksiyonunun özel bir uygulamasıdır. Bu projenin amacı, C dilindeki **değişken sayıda argüman alan fonksiyonların (variadic functions)** çalışma mantığını derinlemesine anlamak ve formatlı çıktı verme işlemini kendi kütüphanemizle yeniden oluşturmaktır.

Bu proje sayesinde, fonksiyonların stack (yığın) belleğini nasıl kullandığını, argümanlara erişim için `va_list` yapısının nasıl yönetildiğini ve modüler bir kod tabanının nasıl yapılandırılacağını öğrendim. Sonuç olarak ortaya çıkan `libftprintf.a` kütüphanesi, orijinal `printf` fonksiyonunun belirli format belirleyicileri için davranışını birebir taklit eder.

## ⚙️ Teknik Tercihler: Algoritma ve Veri Yapıları

### Veri Yapısı: `va_list` ve Stack Yönetimi
Projenin temelinde `<stdarg.h>` kütüphanesinden gelen `va_list` yapısı kullanılmıştır.

* **Neden `va_list`?**

    Yüksek seviyeli dillerin aksine C, fonksiyon argümanlarını bellekteki **Stack (Yığın)** bölgesine ardışık olarak yerleştirir. `va_list`, bu bellek bloğu üzerinde gezinen bir işaretçi (cursor) görevi görür.
* **Nasıl Çalışır?**

    `va_start` ile imleci ilk argümana konumlandırdım. `va_arg` makrosu kullanılarak, imlecin istenen veri tipinin boyutu kadar (örneğin bir `int` için 4 byte) ileri atlamasını sağladım. Bu yöntem, Stack'i tıpkı bir bağlı liste (linked list) gibi, ancak pointerlar yerine bitişik bellek blokları üzerinden okumamı sağladı.

### Algoritma: Dispatcher (Yönlendirici) ve Recursion (Öz Yineleme)
`ft_printf` mimarisi, bir ayrıştırma döngüsü ve bir yönlendirme mekanizmasına dayanır.

1.  **Parsing Loop (Ayrıştırma Döngüsü):** 
Ana fonksiyon, format stringini karakter karakter işler.

2.  **Dispatcher:** Bir `%` işareti görüldüğünde, kontrol `print_format` fonksiyonuna geçer. Bu fonksiyon, gelen belirleyiciyi (`c`, `s`, `d` vb.) analiz eder ve ilgili yardımcı fonksiyonu çağırır.

3.  **Sayı Tabanı Dönüşümü için Recursion:**
    Sayıların (Tamsayı, Unsigned, Hexadecimal ve Pointer) basılması için **recursive** bir algoritma kullandım.

## 📋 Desteklenen Formatlar

Uygulamam aşağıdaki standart format belirleyicilerini desteklemektedir:

| Belirleyici | Açıklama |
| :--- | :--- |
| `%c` | Tek bir karakter basar. |
| `%s` | Bir string (karakter dizisi) basar. |
| `%p` | `void *` pointer argümanını hexadecimal formatta basar. |
| `%d` | 10'luk tabanda işaretli bir tamsayı basar. |
| `%i` | 10'luk tabanda bir tamsayı basar. |
| `%u` | 10'luk tabanda işaretsiz (unsigned) bir tamsayı basar. |
| `%x` | Sayıyı hexadecimal (16'lık) tabanda **küçük harflerle** basar. |
| `%X` | Sayıyı hexadecimal (16'lık) tabanda **büyük harflerle** basar. |
| `%%` | Yüzde işaretini basar. |

## 🚀 Talimatlar (Instructions)

### 1. Derleme (Compilation)
Kütüphaneyi oluşturmak için proje dizininde şu komutu çalıştırın:

`make`

Bu işlem **libftprintf.a** dosyasını oluşturacaktır. 
#### Makefile kuralları:

`make clean`: Nesne (.o) dosyalarını temizler.

`make fclean`: Nesne dosyalarını ve kütüphane dosyasını temizler.

`make re`: Her şeyi temizler ve sıfırdan derler.

### 2. Kullanım (Usage)
ft_printf'i kendi projenizde kullanmak için başlık dosyasını ekleyin ve derleme sırasında kütüphaneyi bağlayın.

#### Derleme Komutu:

```bash
gcc main.c libftprintf.a -o programim
./programim
```

## 📚 Kaynaklar ve AI Kullanımı

### Referanslar
* The C Programming Language (Kernighan & Ritchie): Standart kütüphane davranışlarını anlamak için.

* Linux Man Sayfaları: man printf (3) ve man stdarg (3).

* Standart C Kütüphanesi Kaynak Kodları: Uç durumlar (edge cases) için glibc implementasyonu incelendi.

### AI (Yapay Zeka) Kullanımı Açıklaması
Bu projenin geliştirilmesi sırasında Yapay Zeka araçlarından destekleyici bir eğitim aracı olarak faydalanılmıştır. Özellikle:

* Kavramsal Anlama: Stack bellek yapısının ve va_list'in bellekte pointerlara kıyasla nasıl hareket ettiğinin görselleştirilmesi ve teorik olarak anlaşılması.

* Hata Ayıklama (Debugging): %s ve %p formatlarında NULL gelmesi gibi kritik hataların tespiti ve güvenli kod yazımı (Crash almadan (null) yazdırma gibi).

*Not:* Tüm kod implementasyonu, mantık kurgusu ve nihai kararlar tarafımdan yapılmıştır.