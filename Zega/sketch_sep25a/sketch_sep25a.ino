
#define PROGRAM "1704X15H"
#define LOOPS_TO_SAVE_DATA 1  // Loops to save data to SD card [1-60 recommended]

#include <SD.h>
#include <SPI.h>
int chipSelect = 10;           // Set chipSelect = 4;
File mySensors;
int z = 0;                       // Variable to save data to SDcard
int loops = 0;                 // Counting loops for test purposes

void setup(void) {
  Serial.begin(9600);
  pinMode(10, OUTPUT);  // Reserve pin 10 as an OUTPUT (SDcard)
  SD.begin(chipSelect);   // Initialize SDcard with chipSelect on pin 4
}

void loop(void) {
  mySensors = SD.open("data.txt", FILE_WRITE);
  if ((mySensors && z == 0) || (mySensors && z >= LOOPS_TO_SAVE_DATA)) {
    Serial.print("Sensor data successfully saved! Loops: ");
    Serial.println(loops);
    mySensors.print(PROGRAM);
    mySensors.print(",");
    mySensors.println(loops);
    // [All data...]
    mySensors.close();
    z = 1;
  } else if ((mySensors && z >= 1) && (z < LOOPS_TO_SAVE_DATA)) {
    Serial.print("Sensor data will be saved each ");
    Serial.print(LOOPS_TO_SAVE_DATA);
    Serial.print(F(" loops. Current loop: "));
    Serial.println(z);
    z++;
  } else if (z > LOOPS_TO_SAVE_DATA) {
    Serial.print("Sensor data is NOT saved as it should!");
    z++;
  } else {
    Serial.print("Sensor data is NOT saved!");
    z++;
  }
  loops++;
  delay(1000);
}
