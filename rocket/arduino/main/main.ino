#include "Wire.h"

#include "I2Cdev.h"
#include "MPU6050.h"

#include <SD.h>

MPU6050 carsicker;


#define LED_PIN 13
bool blinkState = false;
int16_t ax, ay, az;
int16_t gx, gy, gz;

const int csPin = 10;
const int airDigitalPin = 9;
const int airAnalogPin = 0;
bool sd_ok;
bool mpu_ok;


void testSD() {
  sd_ok = SD.begin(csPin);
  //  一般情况下仅仅测试是会返回true, 但是不注释掉写入等操作的代码就出问题了
  Serial.println(sd_ok ? "SD testing success" : "SD crashed!");
}

void testMPU() {
  Serial.println("init MPU...");
  carsicker.initialize();
  Serial.println("connect MPU...");
  mpu_ok = carsicker.testConnection();
  Serial.println(mpu_ok ? "mpu testing success" : "mpu crashed!");
}

void setup() {
  Wire.begin();
  // put your setup code here, to run once:
  Serial.begin(9600);
  testSD();
  testMPU();
}

void loop() {
  // put your main code here, to run repeatedly:
  int air_analog = readAirQuality();
  
  Serial.println("Air Quality: " + air_analog);
  carsicker.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial.print("a/g:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);
  delay(250);
  
}

int readAirQuality() {
  int air_analog = analogRead(airAnalogPin);
  return air_analog;
}


//  Serial.println("loading SD");
//  bool sd_ok;
//  sd_ok = false;
//  while (!sd_ok) {
//    sd_ok = testSD();
////    delay(1000);
//  };
//  Serial.println("sd ok..?");
//  File Log;
//  
//  Log = SD.open("log.txt", FILE_WRITE);
//
//  if (Log) {
//    Serial.print("log file has already exists.");
//  } else {
//    Serial.print("log file doesn't exist but has been created.");
//  }
//  Log.println("22/3/22 23:40 test...");
//  Log.close();
//  Log = SD.open("log.txt", FILE_WRITE);
//  Serial.println(Log.read());
//  Log.close();
