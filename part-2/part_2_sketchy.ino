/* 
* Part 2
* Authors: Jeff Schulthies, Vick Rekhi, Austin Moon 
*/

/* Digital Pins. */
#define blue_pin 6
#define green_pin 10
#define red_pin 11

/* Potentiometer Pins. */
#define red_pot_pin 0
#define green_pot_pin 1
#define blue_pot_pin 2

/* Pin Values */
int red_pot_value;
int green_pot_value;
int blue_pot_value;
  
void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  red_pot_value = (analogRead(red_pot_pin) / 4);
  green_pot_value = (analogRead(green_pot_pin) / 4);
  blue_pot_value = (analogRead(blue_pot_pin) / 4);

  setAnalog();

  /* Test Print Statements. */
  
  //Serial.println("test");
  //Serial.print("Red Value: ");
  //Serial.println(red_pot_value);
  
  //Serial.print("Green Value: ");
  //Serial.println(green_pot_value);
  
  //Serial.print("Blue Value88: ");
  //Serial.println(blue_pot_value);

}

/*
 * Updates pin
 */
void setAnalog() {
  analogWrite(red_pin, red_pot_value);
  analogWrite(green_pin, green_pot_value);
  analogWrite(blue_pin, blue_pot_value);
} 
