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
  read_inputs(); 
  delay(4000); 
  // put your main code here, to run repeatedly:
}

void read_inputs(){
   while(serial_connection.available()){
   if(gps.encode(serial_connection.read())){
     String msg = serial_connection.readStringUntil('\r');
     Serial.println(msg);
     Serial.println("LAT=");Serial.println(gps.location.lat(),6);
     Serial.println("LONG=");Serial.println(gps.location.lng(),6);
     Serial.println("ALT=");Serial.println(gps.altitude.meters(),6);
   }

  }
}
// put function definitions here:return x + y;
double read_altitude(){
 while(serial_connection.available()){
  if(gps.encode(serial_connection.read())){
    return gps.altitude.meters(); 
  }
 } 
}
