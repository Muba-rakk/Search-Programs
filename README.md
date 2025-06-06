# 🔍 PaperFinder: Intelligent Search Engine for Academic Papers

Selamat datang di **PaperFinder**!  
Proyek ini adalah implementasi sederhana namun powerful untuk pencarian data paper akademik berbasis **C++** yang dirancang khusus sebagai bagian dari tugas mata kuliah di Universitas Sultan Ageng Tirtayasa.

## 📚 Deskripsi

PaperFinder adalah program berbasis CLI (Command Line Interface) yang mampu melakukan **pencarian data paper akademik** dari file CSV menggunakan dua metode pencarian populer:

- **Linear Search** — cocok untuk dataset kecil atau pencarian cepat tanpa pengurutan.
- **Binary Search** — ideal untuk pencarian efisien setelah pengurutan data berdasarkan kriteria tertentu.

### 🔧 Fitur Utama

- 🔎 Pencarian berdasarkan:
  - **Judul**
  - **Tahun Terbit**
  - **Nama Penulis**

- 🧠 Memilih metode pencarian sesuai kebutuhan:
  - Metode linear (brute force)
  - Metode biner (lebih optimal setelah sorting)

- 📁 Membaca dan memfilter data dari file `data.csv` dengan validasi kolom yang ketat.

- 🖨️ Menampilkan hasil dengan format yang rapi dan mudah dibaca.

## 🗂️ Struktur Data

Data disimpan dalam bentuk struct `Paper` yang berisi:

```cpp
struct Paper {
    string judul;
    string sumber;
    string penulis;
    int tahun;
    string link;
};
```

## 💡 Catatan
- Pastikan file CSV memiliki format kolom yang konsisten.
- Binary Search akan menyortir data terlebih dahulu sebelum melakukan pencarian.

## ✨ Penutup
PaperFinder adalah bukti bahwa bahkan program sederhana dapat memberikan manfaat besar jika dibangun dengan fokus pada tujuan.
Semoga bermanfaat dan bisa jadi inspirasi dalam membangun sistem pencarian data yang lebih kompleks di masa depan!
