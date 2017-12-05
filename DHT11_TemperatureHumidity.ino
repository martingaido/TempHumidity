/*
   Sense ambient temperature and humidity,
   display data on serial monitor.
  
   Author: Martin Gaido
   https://github.com/martingaido
   
   Parts required:
  
   - Arduino UNO Board
   - DHT11 Sensor
   - Cables
  
   Conn Diagram
  
   DHT11 (GND)  -> ARDUINO UNO (GND)
   DHT11 (VCC)  -> ARDUINO UNO (5V)
   DHT11 (DATA) -> ARDUINO UNO (D7)

   This example code is part of the public domain.
*/

#include "dht.h"

dht DHT;

#define DHT11_PIN 7
int temp_tmp;
int hume_tmp;

void setup(){
  
  Serial.begin(9600);

}

void loop()
{
  
  int chk = DHT.read11(DHT11_PIN);

  /*
  // Print temperature -> serial monitor
  Serial.print("Temperature: ");
  Serial.print(DHT.temperature);
  Serial.println("C");

  // Print humidity -> serial monitor
  Serial.print("Humidity:    ");
  Serial.print(DHT.humidity);
  Serial.println("%");
  */

  // Print temperature on serial monitor
  // only if a variation is detected.
  
  if(temp_tmp != DHT.temperature){
      
      Serial.print("Temperature: ");
      Serial.print(DHT.temperature);
      Serial.println("ºC");
      temp_tmp = DHT.temperature;
      
  }

  // Print humidity on serial monitor
  // only if a variation is detected.
  
  if(hume_tmp != DHT.humidity){

      Serial.print("Humidity:    ");
      Serial.print(DHT.humidity);
      Serial.println("%");
      hume_tmp = DHT.humidity;
    
  }

  // Repeat the operation every second
  delay(1000);
}

