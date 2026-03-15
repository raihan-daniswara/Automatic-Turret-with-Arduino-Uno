# Automatic Turret with Arduino Uno

## Project Overview

**Automatic Turret with Arduino Uno** adalah proyek sistem turret otomatis berbasis mikrokontroler **Arduino Uno** yang dirancang untuk mendeteksi objek di sekitarnya dan merespons secara otomatis.

Sistem ini menggunakan **sensor ultrasonik** untuk mendeteksi jarak objek dan **dua motor servo** untuk menggerakkan turret. Servo pertama berfungsi sebagai **scanner horizontal** yang memindai area di sekitarnya, sedangkan servo kedua berfungsi sebagai **mekanisme aksi** ketika objek terdeteksi.

Ketika sensor mendeteksi objek dalam jarak tertentu, sistem akan:
* menghentikan proses scanning sementara
* menyalakan indikator
* menggerakkan servo aksi
* kemudian kembali ke posisi awal dan melanjutkan proses scanning

Proyek ini bertujuan untuk mempelajari konsep **robotika, sensor jarak, kontrol servo, serta sistem deteksi otomatis menggunakan mikrokontroler**.

---

## Tujuan Project

* Mempelajari penggunaan **sensor ultrasonik untuk deteksi jarak**
* Mengimplementasikan **kontrol motor servo menggunakan Arduino**
* Membuat sistem **automatic scanning dan detection**
* Mengembangkan proyek **robotika sederhana berbasis mikrokontroler**
* Memahami integrasi antara **sensor, aktuator, dan logika program**

---

## Fitur Utama

### Sistem Scanning Otomatis
* Servo utama melakukan scanning dari **35° hingga 165°**
* Sistem memindai area secara bolak-balik
* Digunakan untuk mencari objek di sekitar turret

### Deteksi Objek
* Menggunakan **sensor ultrasonik HC-SR04**
* Menghitung jarak objek dalam satuan **centimeter**
* Objek akan terdeteksi jika berada dalam jarak **≤ 20 cm**

### Sistem Respon Turret
* Ketika objek terdeteksi:
  * scanning berhenti sementara
  * LED indikator berubah
  * servo aksi bergerak

### Mekanisme Servo Aksi
* Servo kedua bergerak dari **110° ke 45°**
* Setelah aksi selesai, servo kembali ke posisi awal
* Sistem kemudian melanjutkan scanning

### Monitoring Serial
* Data jarak objek dikirim ke **Serial Monitor**
* Memudahkan debugging dan monitoring sistem

---

## Teknologi yang Digunakan

### Hardware

* Arduino Uno
* Ultrasonic Sensor **HC-SR04**
* Servo Motor (2x)
* LED Indicator
* Jumper Wires
* Breadboard
* Frame Turret

### Software
* Bahasa pemrograman **C/C++ (Arduino)**

### Tools 
* Arduino IDE

---

## Cara Kerja Sistem

1. Arduino menggerakkan **servo scanning** untuk memindai area.
2. Sensor ultrasonik mengukur jarak objek di depan turret.
3. Jika objek berada dalam jarak **≤ 20 cm**:
   * sistem menandai objek terdeteksi
   * LED indikator berubah
   * servo aksi bergerak
4. Setelah aksi selesai, turret kembali melakukan scanning.

---

## Struktur Program

Program utama terdiri dari beberapa bagian:

* **Inisialisasi Servo**
* **Pembacaan Sensor Ultrasonik**
* **Logika Scanning Turret**
* **Deteksi Objek**
* **Respon Servo Aksi**
* **Output Serial Monitor**

Fungsi utama yang digunakan:

* `getDistance()` → Menghitung jarak menggunakan sensor ultrasonik
* `setup()` → Inisialisasi servo, sensor, dan komunikasi serial
* `loop()` → Menjalankan proses scanning dan deteksi objek
