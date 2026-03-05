# RSA Encryption Demo (C++)

## 📌 Deskripsi Proyek

Program ini merupakan implementasi sederhana dari **algoritma kriptografi RSA (Rivest–Shamir–Adleman)** yang dibuat **dari awal (from scratch)** menggunakan bahasa **C++** tanpa menggunakan library kriptografi eksternal.

Program ini mendemonstrasikan proses dasar RSA yaitu:

* **Key Generation** (pembangkitan kunci publik dan privat)
* **Enkripsi pesan**
* **Dekripsi pesan**

Program menerima **plaintext berupa teks**, kemudian:

1. Mengubah setiap karakter menjadi **kode ASCII**
2. Mengenkripsi ASCII menggunakan **public key**
3. Menghasilkan **ciphertext**
4. Mendekripsi ciphertext menggunakan **private key**
5. Mengembalikan pesan ke bentuk **plaintext**

Program ini dibuat sebagai **demo untuk tugas mata kuliah Kriptografi**.

---

# 🔐 Tentang Algoritma RSA

RSA adalah algoritma **kriptografi asimetris** yang menggunakan dua kunci:

* **Public Key (e, n)** → digunakan untuk enkripsi
* **Private Key (d, n)** → digunakan untuk dekripsi

Keamanan RSA didasarkan pada kesulitan memfaktorkan bilangan besar hasil perkalian dua bilangan prima.

---

# ⚙️ Cara Kerja Program

## 1. Key Generation

Program memilih dua bilangan prima:

```
p = 17
q = 11
```

Kemudian menghitung:

```
n = p × q
ɸ(n) = (p − 1)(q − 1)
```

Selanjutnya program mencari nilai:

* **e** → relatif prima dengan φ(n)
* **d** → modular inverse dari e

Sehingga diperoleh:

```
Public Key  = (e, n)
Private Key = (d, n)
```

---

## 2. Proses Enkripsi

Setiap karakter plaintext diubah menjadi **ASCII**.

Contoh:

```
H = 72
E = 69
L = 76
```

Kemudian dienkripsi menggunakan rumus RSA:

```
C = M^e mod n
```

Dimana:

* M = plaintext (ASCII)
* C = ciphertext

---

## 3. Proses Dekripsi

Ciphertext kemudian dikembalikan menjadi plaintext menggunakan rumus:

```
M = C^d mod n
```

Hasilnya kemudian dikonversi kembali menjadi karakter.

---

# 📂 Struktur Program

Program terdiri dari beberapa fungsi utama:

### `gcd()`

Digunakan untuk mencari **Greatest Common Divisor (GCD)** antara dua bilangan.

### `modInverse()`

Digunakan untuk mencari **modular inverse** yang diperlukan untuk menghitung private key.

### `rsa()`

Digunakan untuk menghitung operasi perpangkatan dengan modulo:

```
base^exp mod mod
```

Fungsi ini digunakan dalam proses **enkripsi dan dekripsi RSA**.

---

# ▶️ Cara Menjalankan Program

## 1. Clone repository

```
git clone https://github.com/Lyc-n/rsa-from-scratch.git
```

Masuk ke folder project:

```
cd rsa-from-scratch
```

---

## 2. Compile program

Menggunakan **g++ compiler**

```
g++ main.cpp -o rsa
```

---

## 3. Jalankan program

```
./rsa
```

Pada Windows:

```
rsa.exe
```

---

# 💻 Contoh Output Program

Input:

```
Masukkan plaintext: HELLO
```

Output:

```
Public Key (e,n): (3,187)
Private Key (d,n): (107,187)

ASCII tiap karakter:
H -> 72
E -> 69
L -> 76
L -> 76
O -> 79

Ciphertext:
18387989811

Hasil Dekripsi:
HELLO
```

---

# 📚 Referensi

1. https://tekkom.upi.edu/2023/02/rsa-cryptography-algorithm/
2. https://www.splunk.com/en_us/blog/learn/rsa-algorithm-cryptography.html

---

# 👨‍🎓 Informasi Tugas

Mata Kuliah: Keamanan Data dan Informasi
Topik: Analisis Komprehesif Kriptografi dalam Konteks Confidentiality
Jenis Implementasi: Coding Demo

Program ini dibuat untuk menunjukkan secara sederhana bagaimana **algoritma RSA bekerja dari proses pembangkitan kunci hingga enkripsi dan dekripsi pesan**.
