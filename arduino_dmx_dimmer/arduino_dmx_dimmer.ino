#include <DMXSerial.h>

#define STARTADDR 15
#define OUT1 4
#define OUT2 5
#define OUT3 6

void setup () {
  //Serial.begin(115200);
  DMXSerial.init(DMXReceiver);
  
  // set some default values
  DMXSerial.write(STARTADDR,0);
  DMXSerial.write(STARTADDR+1, 0);
  DMXSerial.write(STARTADDR+2, 0);
  
  // enable pwm outputs
  pinMode(OUT1,   OUTPUT); // sets the digital pin as output
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3,  OUTPUT);
  pinMode(13,OUTPUT);
}


void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {
    digitalWrite(13,HIGH);
    // read recent DMX values and set pwm levels 
    analogWrite(OUT1,   DMXSerial.read(STARTADDR));
    analogWrite(OUT2, DMXSerial.read(STARTADDR+1));
    analogWrite(OUT3,  DMXSerial.read(STARTADDR+2));

  } else {
    // turn off.
    digitalWrite(13,LOW);
    analogWrite(OUT1,   0);
    analogWrite(OUT2, 0);
    analogWrite(OUT3,  0);
  }
}

