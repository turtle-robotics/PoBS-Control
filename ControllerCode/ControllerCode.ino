//Arduino FS-I6X Demo
 // fsi6x-arduino-uno.ino
  //Read output ports from FS-IA6B receiver module
//  Display values on Serial Monitor
  
 // Channel functions by Ricardo Paiva - https://gist.github.com/werneckpaiva/
  
//  DroneBot Workshop 2021
//  https://dronebotworkshop.com

#include <Servo.h>

 
// Define Input Connections
#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9
#define CH5 8
#define CH6 11
 
// Integers to represent values from sticks and pots
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value; 
int ch5Value;
 
// Boolean to represent switch value
bool ch6Value;
 
// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
 
// Read the switch channel and return a boolean value
bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}



Servo myservo;

 
void setup(){
  // Set up serial monitor
  Serial.begin(115200);
  
  // Set all pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
  pinMode(CH5, INPUT);
  pinMode(CH6, INPUT);
  pinMode(2, OUTPUT);

  myservo.attach(10);

}
 
 
void loop() {
/*  
  // Get values for each channel
  ch1Value = readChannel(CH1, -100, 100, 0);
  ch2Value = readChannel(CH2, -100, 100, 0);
  ch3Value = readChannel(CH3, 0, 180, 100);
  ch4Value = readChannel(CH4, -100, 100, 0);
  ch5Value = readSwitch(CH5, false);
  ch6Value = readSwitch(CH6, false);
  
  // Print to Serial Monitor
  Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print(" | Ch2: ");
  Serial.print(ch2Value);
  Serial.print(" | Ch3: ");
  Serial.print(ch3Value);
  Serial.print(" | Ch4: ");
  Serial.print(ch4Value);
  
  Serial.print(" | Ch5: ");
  Serial.println(ch5Value);

  if(ch5Value){
    digitalWrite(2, HIGH);
    
  }else{
    digitalWrite(2, LOW);
  
  }
  
  Serial.print(" | Ch6: ");
  Serial.println(ch6Value);

  if(ch6Value){
    digitalWrite(2, HIGH);
    
  }else{
    digitalWrite(2, LOW);
    
  }

*/ 
ch3Value = readChannel(CH3, 0, 180, 100); 
myservo.write(ch3Value);
  
  delay(0);

  
}
