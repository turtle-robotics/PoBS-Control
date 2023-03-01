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

int pos = 90;
 
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

  myservo.attach(12);


 

}
 
 
void loop() {
  
  // Get values for each channel
  ch1Value = readChannel(CH1, -100, 100, 0);
  ch2Value = readChannel(CH2, 0, 180, 90);
  ch3Value = readChannel(CH3, 0, 180, 90);
  ch4Value = readChannel(CH4, -100, 100, 0);
  ch5Value = readSwitch(CH5, false);
  ch6Value = readSwitch(CH6, false);
  
  // Print to Serial Monitor
//  Serial.print("Ch1: ");
//  Serial.print(ch1Value);
//  Serial.print(" | Ch2: ");
//  Serial.print(ch2Value);
//  Serial.print(" | Ch3: ");
//  Serial.print(ch3Value);
//  Serial.print(" | Ch4: ");
//  Serial.print(ch4Value);
//  
//  Serial.print(" | Ch5: ");
//  Serial.println(ch5Value);

//  if(ch5Value){
//    digitalWrite(2, HIGH);
//    
//  }else{
//    digitalWrite(2, LOW);
//  
//  }
//  
//  Serial.print(" | Ch6: ");
//  Serial.println(ch6Value);
//
//  if(ch6Value){
//    digitalWrite(2, HIGH);
//    
//  }else{
//    digitalWrite(2, LOW);
//    
//  }
//



//Serial.println(pos);


//if (ch2Value > pos){
//  pos += 1; //min(abs(ch2Value-pos),1);
//  pos = min(pos,175);
//  myservo.write(pos);
//}else if(ch2Value < pos){
//  pos -= 1; //min(abs(ch2Value-pos),1);
//  pos = max(pos,5);
//  myservo.write(pos);
//}else{
//  myservo.write(pos);
//}
//delay(20);



//if (!(abs(ch2Value-pos) == 0)){
//  pos += (ch2Value-pos)/abs(ch2Value-pos); 
//  //pos = max(min(pos,175),5);
//  myservo.write(pos);
//delay(20);
//}




    
    int s = 1;

    int i = 90;
    int top = 170;
    int bottom = 25;
    int width = 0;

if(ch2Value-pos > 0){
    bottom = pos;
    top = ch2Value;
for (i = bottom-10; i < top ; i += s){
   width = top-bottom;
    
    if(i <max(top-width/4,5) && i > max(bottom+width/4,5)){
      s = 4;
      }else{
      s = 1;
      }

    myservo.write(i);
    Serial.println(i);

    pos = i;
    delay(15);  
    }
    delay(15);
}else if((ch2Value-pos < 0)){
    bottom = ch2Value;
    top = pos;
for (i = top+10; i > bottom ; i -= s){
    if(i <max(top-width/4,5) && i > max(bottom+width/4,5)){
      s = 4;
      }else{
      s = 1;
      }


    myservo.write(i);
    Serial.println(i);

    pos = i;
    delay(15);  
    }
    delay(15); 

} else{
myservo.write(pos);
delay(15); 
}


//
//int h = 0;
//
//  for (pos = 1; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
//    
//    h = min(1, h++);
//    //Serial.print(abs(ch2Value));
//    //Serial.print("-");
//    Serial.println(pos);
//
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//    }
//    h = 0;
//  for (pos = 179; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
//    h = min(1, h++);
//    //Serial.print(abs(ch2Value));
//    //Serial.print("-");
//    Serial.println(pos);
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//    }


//ch3Value = readChannel(CH3, 0, 180, 100); 
//myservo.write(135);
//  
//  delay(0);

  
}
