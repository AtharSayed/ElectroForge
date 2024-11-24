// Code By Athar Sayed 
#include <Servo.h>. // Includes the Servo library
#include <Wire.h>   // Includes the OLED's Libraries 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
int sensor = 13;  // Digital pin D7
int led = 15 ; // Digital pin D8

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Defines Trig and Echo pins of the Ultrasonic Sensor
const int trigPin = 12; // D6 pin
const int echoPin = 14; // D5 pin 

// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(2); // Defines on which pin is the servo motor attached D4
  
  pinMode(sensor, INPUT);   // declare sensor as input 
  pinMode(led, OUTPUT); // Led is declared as Output

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);

  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);             
  display.println(" PBL Project!");
  display.display();
  delay(2000);
  display.clearDisplay(); 
  
}
void loop() {
  Pir();
  display.clearDisplay();
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(20);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(20);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(" degree ,Distance:  "); 
  Serial.print(distance);
  Serial.println(" cm");
  }
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

 void Pir(void)
{
 long state = digitalRead(sensor);
    if(state == HIGH) {    
   display.setTextSize(1);
   display.setCursor(0,20);
   display.print(" MOTION ");
   display.setCursor(2,34);
   display.print(" DETECTED.! ");
   display.display();
   digitalWrite(led, HIGH);
   delay(2000);
  }
  
  else
  {
    display.setTextSize(1);
    display.setCursor(0,20);
    display.print("NO MOTION ");
    display.display();
     digitalWrite(led, LOW);
  }
}
