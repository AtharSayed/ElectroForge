// VIBRATION CREATION SYSTEM (B.TECH PROJECT )
// CODE BY ATHAR SAYED

int motorPin =  ; //Pin to which the motor is connected with arduino
int potmeter_pin =  ; // Pin to which potentiometer is connected (Analog Pin)
int val = 0 ;


void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);   // Vibration motor  declared as output   
  

}

void loop() {
  // put your main code here, to run repeatedly:
     val = analogRead(potmeter_pin);   
     val =  map(val,0,1023,0,255);
     analogWrite(potmeter_pin,val);


}
