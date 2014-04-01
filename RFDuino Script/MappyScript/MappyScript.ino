/*
The sketch is an empty template for Bluetooth Low Energy 4.
Simply remove what you dont need, and fill in the rest.
*/

#include <RFduinoBLE.h>

#define trig 2
#define echo 3

float duration, distance; 

void setup()
{
  //set up ultrasonic sensor
  Serial.begin (9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  RFduinoBLE.deviceName = "Mappy";
  RFduinoBLE.advertisementData = "data";
  RFduinoBLE.advertisementInterval = MILLISECONDS(300);
  RFduinoBLE.txPowerLevel = -20;  // (-20dbM to +4 dBm)

  // start the BLE stack
  RFduinoBLE.begin();
}

void loop()
{
  // switch to lower power mode
  RFduino_ULPDelay(INFINITE);  
  
  // to send one char
  // RFduinoBLE.send((char)temp);

  // to send multiple chars
  // RFduinBLE.send(&data, len);
  
  digitalWrite(trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration/58.2;
  RFduinoBLE.sendFloat(distance);
  
}

void RFduinoBLE_onAdvertisement(bool start)
{
  
}

void RFduinoBLE_onConnect()
{
  
}

void RFduinoBLE_onDisconnect()
{
}

// returns the dBm signal strength indicated by the receiver after connection (-0dBm to -127dBm)
void RFduinoBLE_onRSSI(int rssi)
{
}

void RFduinoBLE_onReceive(char *data, int len)
{
}
