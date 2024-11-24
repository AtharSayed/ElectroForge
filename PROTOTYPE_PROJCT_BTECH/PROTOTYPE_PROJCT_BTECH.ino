// Prototype code for B.Tech project 

#include<Servo.h>
// OLED LIBRARIES 
#include <Wire.h>   // Includes the OLED's Libraries 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h> 

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Initializing 1 servo  
Servo servo1;


// INITIALIZING  VIB SENSR  X 1
   int vib_pin1 = 8; // digital pinout  D8 pin
    

void setup() {
  // put your setup code here, to run once:
  
  // SERVO MOTOR X 1
   servo1.attach(22);  // D4 digital pin 
   
   // DECLARING VIBRATION SENSOR AS INPUT 
  pinMode(vib_pin1,INPUT);

  Serial.begin(9600); // Setting the baud rate at 9600 b/s

  //OLED FUNCTIONS 

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
  display.println("B.TECH PRJCT!");
  display.setCursor(2,34);
  display.println("PROTOTYPE");
  display.setCursor(0,28);
  display.println("GRP-G4"); 
  display.display();
  delay(2000);
  display.clearDisplay(); 

  
}

void loop() {
  // put your main code here, to run repeatedly:
   long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 4000){  
     servo1.write(15);
     delay(5000);
     servo1.write(150);
     delay(100);
 
  }

}

long TP_init(){
  delay(10);
  long measurement=pulseIn (vib_pin1, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
