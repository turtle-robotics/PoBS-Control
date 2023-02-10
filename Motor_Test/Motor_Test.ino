#include <Servo.h>

Servo ESC;

int Speed;

 
void setup(){
  // Set up serial monitor
  ESC.attach(10,1000,2000);
}
 


void loop() {
Speed = analogRead(A0);
Speed = map(Speed, 0, 1023, 0, 180);
ESC.write(Speed);
}
