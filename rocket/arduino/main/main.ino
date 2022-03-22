#include <SD.h>


const int csPin = 10;
const int airDigitalPin = 9;
const int airAnalogPin = 0;


bool testSD() {
  bool sd_ok;
  sd_ok = SD.begin(csPin);
  if (!sd_ok) {
    Serial.println("Error: load SD crashed");
    return false;
  } else { 
    Serial.println("Load SD OK"); 
    return true;
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
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
}

void loop() {
  // put your main code here, to run repeatedly:
  int air_analog = analogRead(airAnalogPin);
  
  Serial.println(air_analog);
  delay(250);
}

// official demo code
//void printDirectory(File dir, int numTabs) {
//  while (true) {
//    File entry =  dir.openNextFile();
//    if (! entry) {
//      break;
//    }
//    for (uint8_t i = 0; i < numTabs; i++) {
//      Serial.print('\t');
//    }
//    Serial.print(entry.name());
//    if (entry.isDirectory()) {
//      Serial.println("/");
//      printDirectory(entry, numTabs + 1);
//    } else {
//      Serial.print("\t\t");
//      Serial.println(entry.size(), DEC);
//    }
//    entry.close();
//  }
//}
