/*
 * PIR sensor tester
 * 
 *  The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 10
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 */
 
 #include <LiquidCrystal.h>
 // initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 10, 4, 5, 6, 7);
 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ExploreEmbedded!"); 
  
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      lcd.clear();
       lcd.setCursor(0, 1);
  // print when motion detected
  lcd.print("Motion detected!");
     
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of

       lcd.clear();
       lcd.setCursor(0, 1);
  // print the when motion not detected:
  lcd.print("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}


