/*
Author: Peter Barrett
Date: 1/4/14
License: MIT
*/

#include <RFduinoBLE.h>
#include "Timer.h"

int led = 4; //blue
int led2 = 3; //green
int led3 = 2; //red
int trig = 5;
int echo = 6;
Timer t;

float duration = 0, distance = 0; 
boolean initial;
void setup()
{
  //set up ultrasonic sensor
  Serial.begin (9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  initial = true;
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
   t.update();
 // RFduinoBLE.sendFloat(5);
  // to send one char
 
  // to send multiple chars
  // RFduinBLE.send(&data, len);
  
  
  
  if(initial){
    initial = false;
    t.every(1000, sendDistance);
  }
  
  //RFduinoBLE.sendFloat(5);
  //RFduinoBLE.sendInt(5);
}

void sendDistance(){

  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
   RFduinoBLE.sendFloat(distance); 
}

void RFduinoBLE_onAdvertisement(bool start)
{
  
}

void RFduinoBLE_onConnect()
{
  int i = 0;
  while(i++ < 3){
    digitalWrite(led3, HIGH);
    delay(100);  
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
  }
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
