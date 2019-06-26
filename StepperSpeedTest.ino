/*
This code lets you run and test your stepper motors using arduino with any of the standard motor driver like A4988/TB6600/DRV8825 etc.
Simply reduce the value of x i.e delay between pulses to increase speed of the motor.
*/
/*
This code will hep you find the speed limit of your motor + driver combination. Fiddle with the value of x and current potentiometer to go for higer speed and smoother motion.
Conclusion: Use higher voltage source 24V or more and x<10 for superfast speeds. 
*/


void setup() {                
  pinMode(2, OUTPUT); // This pin is used for step pulses     
  pinMode(4, OUTPUT); // This pin is used for direction CW or CCW
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  

}
void loop() {
  for( int x =100, j=0; j<35000; j++)  // Very less value of x can not work somtimes as the motor will not gain momentum in such less time and will miss step.
  {
  
  for(int i=0; i<1000; i++)
   {
    digitalWrite(2, HIGH);
    delayMicroseconds(x);          
    digitalWrite(2, LOW); 
   delayMicroseconds(x/5);            // use this to adjust the duty cycle of PWM signal
   // if (x<6) x=x-5;                 // Only when you want accleration 
   //else if (x>15) x=x+5;          // Only when you want decelaration
 
  }
 if(x>=50) x--;                 //  lower limit can be used to speed up the motor. Does it one value at a time which slowly acclerates the motors instead of giving jerks or stopping.
 
   
  
  }
}
