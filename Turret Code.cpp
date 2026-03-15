#include <Servo.h>

// Inisialisasi servo
Servo servo1;
Servo servo2;

// Pin untuk sensor ultrasonik
const int trigPin = 10;
const int echoPin = 11;

int angle1 = 0;  // Sudut servo1
int distance = 0; // Jarak yang terbaca
bool isObjectDetected = false; // Status deteksi objek
unsigned long lastDetectionTime = 5000; // Waktu terakhir objek terdeteksi
const unsigned long delayTime = 1000; // Delay 1 detik

// Fungsi untuk menghitung jarak
int getDistance() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Untuk ultrasonik
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Menghitung jarak dalam cm
  return distance;
}

void setup() {
  // Hubungkan servo ke pin yang sesuai
  servo1.attach(9); 
  servo2.attach(8);
  
  // Set pin untuk sensor ultrasonik
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set pin LED indikator
  pinMode(13, OUTPUT);
  
  // Posisi awal servo2
  servo2.write(110); 
  
  // Memulai komunikasi serial
  Serial.begin(9600);
}

void loop() {
  // Loop pertama untuk scanning sudut servo1 dari 35° ke 165°
  for (angle1 = 35; angle1 <= 165; angle1 += 2) {
    servo1.write(angle1); // Gerakkan servo1
    delay(50);
    
    distance = getDistance(); // Mengambil jarak
    Serial.print("Distance: ");
    Serial.println(distance); // Cetak jarak ke serial monitor
    
    if (distance <= 20) { // Jika objek terdeteksi dalam jarak maksimal 20 cm
      isObjectDetected = true;
      lastDetectionTime = millis(); // Simpan waktu deteksi
      delay(1000);
      digitalWrite(13, LOW); // LED mati ketika objek terdeteksi
      delay(200);
      servo2.write(45); // Gerakkan servo2 ke 45°
      delay(500);
      servo2.write(110); // Kembali ke posisi 110°
      delay(500);
    }
  }
  
  // Loop kedua untuk scanning servo1 dari 165° kembali ke 35°
  for (angle1 = 165; angle1 >= 35; angle1 -= 2) {
    servo1.write(angle1); // Gerakkan servo1
    delay(50);
    
    distance = getDistance(); // Mengambil jarak
    Serial.print("Distance: ");
    Serial.println(distance); // Cetak jarak ke serial monitor
    
    if (distance <= 20) { // Jika objek terdeteksi dalam jarak maksimal 20 cm
      isObjectDetected = true;
      lastDetectionTime = millis(); // Simpan waktu deteksi
      delay(1000);
      digitalWrite(13, LOW); // LED mati ketika objek terdeteksi
      delay(200);
      servo2.write(45); // Gerakkan servo2 ke 45°
      delay(500);
      servo2.write(110); // Kembali ke posisi 110°
      delay(500);
    }
  }
}
