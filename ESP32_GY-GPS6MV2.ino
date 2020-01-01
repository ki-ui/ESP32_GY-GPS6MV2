#include <TinyGPS++.h>

TinyGPSPlus gps;
HardwareSerial serial(2); // use UART2 : gpsRX->17pin gpsTX->16pin

void setup() {
  Serial.begin(115200);
  serial.begin(9600);
}

void loop() {
  if (serial.available()) {
    gps.encode(serial.read());
    if (gps.location.isUpdated()) {
      Serial.println("LAT : " + String(gps.location.lat(), 10));
      Serial.println("LNG : " + String(gps.location.lng(), 10));
    }
  }
}
