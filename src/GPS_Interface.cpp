#include <Arduino.h>
#include "TinyGPS++.h"
#include "SoftwareSerial.h"


SoftwareSerial ss(22, 21);
union POS {double lat; double lng;}; //position union

class GroveGPS{
    private:
    POS latest_pos;
    TinyGPSPlus gps;
    public:
    
    GroveGPS(){
        latest_pos.lat = 0;
        latest_pos.lng = 0;
        gps = TinyGPSPlus();
    }

    POS get_pos(){

        latest_pos.lat = gps.location.lat();
        latest_pos.lng = gps.location.lng();
        return latest_pos;
    }

    double get_lat(){
        return latest_pos.lat;
    }

    double get_lng(){
        return latest_pos.lng;
    }

    void update_pos(){
        Serial.begin(9600);
        while (ss.available() > 0){
            gps.encode(ss.read());
            latest_pos.lat = gps.location.lat();
            latest_pos.lng = gps.location.lng();
            //TODO: remove serial stuff
            Serial.printf("Lat: %f, Lng: %f\n", latest_pos.lat, latest_pos.lng);
        }
    }
};