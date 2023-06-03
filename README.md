# LELE IOT

Project ini membuat sebuah pakan otomatis dengan menggunnakka AI serta berbasi Web dimana pakan akan keluar otomatis ketika pakan waktunya sudah tepat sama seperti yang di setting di web

## Features
Memberikan pakan secara otomatis ketika waktu yang sudah ditentukan di web
* Pakan akan tidak akan keluar jika suhu dan ph tidak norma untuk ikan makan
* Berat keluar pakan bisa ditetukan melalui web
* Bisa di akses jarak jauh karena menggunakkan web

## Tech
Project Iot ini menggunkkan tekknologi :
 * ESP32 CAM
 * Arduino IDE
 * NTP SERVER
 * PHP,HTML, CSSS
 
## Struktur
```
Proyek_iot
│   README.md
│
├───API
│   │   apiKasihPakan.php
│   │   apiMonitoring.php
│   │   connect.php
│   │   leleiot.sql
│   │
│   └───yang tidak jadi pake
│           apiKondisiAir.php
│           apiKondisiPakan.php
│
├───dc_digital
│       dc_digital.ino
│
├───motordc
│       motordc.ino
│
├───PH
│   ├───kalibrasi
│   │       kalibrasi.ino
│   │
│   ├───ph-sensor-ph-4502c
│   │       ph-sensor-ph-4502c.ino
│   │
│   ├───ph_fix
│   │       ph_fix.ino
│   │
│   └───sensor_ph
│           sensor_ph.ino
│
├───pinProyekIOT
│       pin.txt
│
├───Poryek_IOT
│       LCD_ULRTASONIK.ino
│       Poryek_IOT.ino
│       Post_Monitoring.ino
│       Sensor_PH.ino
│       Sensor_Suhu.ino
│       Servo_MotorDC.ino
│
├───servo
│   │   servo.ino
│   │
│   └───servo2
│           servo2.ino
│
├───suhu
│       suhu.ino
│
└───Waktu_dan_servo
        Waktu_dan_servo.ino



```
## Instalation

## Credits
*[Ramdan](https://www.linkedin.com/in/onlyramdan/)


