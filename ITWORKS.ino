#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <TinyGPSPlus.h>


SoftwareSerial serial_connection(10,11);
// put function declarations here:
int myFunction(int, int);
TinyGPSPlus gps; 

void setup() {
 Serial.begin(9600); 
 serial_connection.begin(9600);
 }

void loop() {
  while(serial_connection.available()){
   if(gps.encode(serial_connection.read())){
     String msg = serial_connection.readStringUntil('\r');
     Serial.println(msg);
     Serial.println("LAT=");Serial.println(gps.location.lat(),6);
     Serial.println("LONG=");Serial.println(gps.location.lng(),6);
     delay(4000);

   }

  }
  
  
  // put your main code here, to run repeatedly:
}

// put function definitions here:eturn x + y;
