
#ifndef Lighter_Adafruit_GPS_H
#define Lighter_Adafruit_GPS_H
 #include "Arduino.h"
 #include <SoftwareSerial.h>

// how long to wait when we're looking for a response
#define MAXWAITSENTENCE 5
#include "SoftwareSerial.h"
// AVR ok
// ARDUINO >= 100

class Lighter_Adafruit_GPS {
 public:
  void begin(uint16_t baud); 


  Lighter_Adafruit_GPS(SoftwareSerial *ser); // Constructor when using SoftwareSerial

  //Lighter_Adafruit_GPS(HardwareSerial *ser); // Constructor when using HardwareSerial

  char *lastNMEA(void);
  boolean newNMEAreceived();
  void common_init(void);

  void sendCommand(const char *);
  
  //void pause(boolean b);

  boolean parseNMEA(char *response);
  uint8_t parseHex(char c);

  char read(void);
  boolean parse(char *);
  void interruptReads(boolean r);



  uint8_t hour, minute, seconds, year, month, day;
  uint16_t milliseconds;
  // Floating point latitude and longitude value in degrees.
  float latitude, longitude;
  int32_t latitude_fixed, longitude_fixed;
  float latitudeDegrees, longitudeDegrees;
  float geoidheight, altitude;
  float speed, angle, magvariation, HDOP;
  char lat, lon, mag;
  boolean fix;
  uint8_t fixquality, satellites;

  //boolean waitForSentence(const char *wait, uint8_t max = MAXWAITSENTENCE);
 
 private:

  uint8_t parseResponse(char *response);
  SoftwareSerial *gpsSwSerial;
};


#endif
