#include <Wire.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22); // SDA = GPIO21, SCL = GPIO22

    if (!lox.begin()) {
        Serial.println("Gagal mendeteksi VL53L0X. Cek koneksi!");
        while (1);
    }
    Serial.println("VL53L0X Terdeteksi!");
}

void loop() {
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);

    if (measure.RangeStatus != 4) { // Status 4 = tidak valid
        Serial.print("Jarak: ");
        Serial.print(measure.RangeMilliMeter);
        Serial.println(" mm");
    } else {
        Serial.println("Out of range");
    }
    delay(500);
}
