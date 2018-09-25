/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
#include "CapacitiveSensor.h"
//#include <SPI.h>
//#include <SD.h> //include the SD library

//byte inByte;
//bool sdInitSuccess = false; //card init status

#include "zegacore.h"

CapacitiveSensor   button1 = CapacitiveSensor(10,2);        // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor   button2 = CapacitiveSensor(10,3);        // 10 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil
CapacitiveSensor   button3 = CapacitiveSensor(10,5);        // 10 megohm resistor between pins 4 & 8, pin 8 is sensor pin, add wire, foil
// 1 -x-x
// 3 -x-x
// 2 -x-x


//File file;
//File prime;

dataEntity motor;

unsigned int motormode = 0;


void setup()                    
{
   motor.init();
   //pinMode(chipSelect, OUTPUT);
   
   //LED 3 bits (6,7,8)
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   
   button1.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
  
}

/*
unsigned int countingViability(dataEntity DE0){
  unsigned int score = 0;
  prime =SD.open("primes.txt", FILE_READ);
  if (prime){
      char caract;
      while ((caract = file.read()) != -1){
        
      }
  }

  return score;
}
// non en fait je vais simplement faire un test de primarilite heuristique
*/


//test heuristique pour les nombres premiers
int heuristicPrime(int x){
  //(2**(x-1)%x)%2
  return (2^(x-1)%x)%2;
}

void loop()                    
{
    int maxcapa = 15;
    long start = millis();
    long total1 =  button1.capacitiveSensor(30);
    long total2 =  button2.capacitiveSensor(30);
    long total3 =  button3.capacitiveSensor(30);

    if (total2 > maxcapa){
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    }
    if (total3 > maxcapa){
      Serial.println("test");
    }

    if (total1 > maxcapa){
      motormode = 3;
    }
    
    int Cok = 0;
    if (motormode == 3){
      //file =SD.open("data.txt", FILE_WRITE);
      //Serial.print(file);
        for (double i1 = 0.733; i1 < 5; i1=i1+0.01){
          digitalWrite(6, LOW);
          for (double i2 = 0.267; i2 < 5; i2=i2+0.01){
            digitalWrite(7, LOW);
            for (double i3 = 0; i3 < 5; i3=i3+0.01){
              digitalWrite(8, LOW);
              motor.set_delta1(i1);
              motor.set_delta2(i2);
              motor.set_delta3(i3);
              //digitalWrite(LED_BUILTIN, LOW);
              Cok = 0;
              total3 =  button3.capacitiveSensor(30);
              if (total3 > maxcapa) {
                //file.close();
                //digitalWrite(LED_BUILTIN, HIGH);
                asm volatile (" jmp 0");
              }
              for (int a1=0; a1<100; a1++){
                  motor.calculus(a1);
                  if ( heuristicPrime( round( motor.get_y() ) ) == 1 ){
                    Cok++;
                  }
              }
              if ( Cok > 0 ) {
                Serial.print(motor.get_delta1());
                Serial.print(",");
                Serial.print(motor.get_delta2());
                Serial.print(",");
                Serial.print(motor.get_delta3());
                Serial.print(",");
                Serial.print(Cok);
                Serial.print("\n");
              }
              
              
              digitalWrite(8, HIGH);
            }
           digitalWrite(7, HIGH); 
          }
         digitalWrite(6, HIGH);
        }
        motormode=0;
      //file.close();
    }

    
    
    
    //Serial.println(total1);                  // print sensor output 1
    //Serial.println(total2);                  // print sensor output 2
    //Serial.println(total3);                // print sensor output 3
 
    //Serial.println("=====");
    
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(8, HIGH);
    delay(300);// arbitrary delay to limit data to serial port 
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
}
