/* 
* Part 1
* Authors: Jeff Schulthies, Vick Rekhi, Austin Moon 
*/

/* Digital Pins. */
#define blue_pin 6
#define green_pin 10
#define red_pin 11

/* Potentiometer Pin. */
#define pot_pin 0

/* Potentiometer Value */
int pot_val = 0;


void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  Serial.begin(9600);
}


void loop() {    
  int sensorValue = analogRead(pot_pin);
  pot_val = analogRead(pot_pin);
  //Serial.println(sensorValue);
  //Test Value
  //Serial.println(pot_val);

  //Color and range value mapping
  temperatureConversion(pot_val);
  
  // Red
   if(950 <= pot_val){
    setRed();
   }
   
  // Orange
   else if(700 <= pot_val){
    setOrange();
   }
   
   // Yellow
   else if(400 <= pot_val){
    setYellow();
   }
   
   // Green   
   else if(300 <= pot_val){
    setGreen();
   }
   
   // Blue
   else if(pot_val <= 200){
    setBlue();
   }
}

void setRed() {
  analogWrite(red_pin, 255);
  analogWrite(green_pin, 0);
  analogWrite(blue_pin, 0);
} 

void setOrange() {
  analogWrite(red_pin, 255);
  analogWrite(green_pin, 80);
  analogWrite(blue_pin, 0);
}

void setYellow() {
  analogWrite(red_pin, 255);
  analogWrite(green_pin, 255);
  analogWrite(blue_pin, 0);
}

void setGreen() {
  analogWrite(red_pin, 0);
  analogWrite(green_pin, 255);
  analogWrite(blue_pin, 0);
}

void setBlue() {
  analogWrite(red_pin, 0);
  analogWrite(green_pin, 0);
  analogWrite(blue_pin, 255);
}

// Potentiomater input 0 - 1023
// Converts that value to mV 
double potentiometerToVoltage(int pot_value) {
  double voltage;
  return voltage = ((double)pot_value * 5 /1023) * 1000;
}

// Converts voltage in mV to Temperature
void temperatureConversion(int pot_value) {
  double temperature;
  double voltage;

  voltage = potentiometerToVoltage(pot_value);
  
  if (voltage > 750) {
    temperature = 25 + ((voltage - 750) / 10);
  } else if (voltage == 750) {
    temperature = 25;
  } else if(voltage < 750){
    temperature = 25 + ((voltage - 750) / 10);
  }
  
  Serial.print("Temperature: ");
  Serial.println(temperature);
} 

