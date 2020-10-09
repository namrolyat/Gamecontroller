/* Gameboy with buttons to USB Keyboard presses */
// used for Arduino Leonardo  29-9-2020

// Include the Bounce2 library found here (replaces Bounce.h):
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>
#include <Keyboard.h>


//The number of push buttons used on the gameboy

const int analogInPin1 = A0;   //measure on input 1 I/O
const int analogInPin2 = A1;   //measure on input USB from PC
const int analogInPin3 = A2; 
const int analogInPin4 = A3; 
const int analogInPin5 = A4; 
const int analogInPin6 = A5; 
 
int sensorValue1 = 0;
int sensorValue2 = 0;
int outputValue = 0;   


const int NUM_OF_BUTTONS = 7;
const int DEBOUNCE_TIME = 10;   //button debounce time

// The Teensy LC input pins used
//const uint8_t BUTTON_PINS[NUM_OF_BUTTONS] = {0, 1, 2, 3, 4, 5, 6};  //Teensy
//The Arduino input pins used
  const uint8_t BUTTON_PINS[NUM_OF_BUTTONS] = {3, 4, 5, 6, 7, 8, 9};  // Arduino

Bounce *buttons = new Bounce[NUM_OF_BUTTONS];

// Array with keycodes
// const int KEY_CODES[NUM_OF_BUTTONS] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7};
const int KEY_CODES[NUM_OF_BUTTONS] = {49,50,51,52,53,54,55};




void setup() {

     Serial.begin(115200);

  
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
   pinMode(0, INPUT_PULLUP);
  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    //setup the bounce instance for the current button
    buttons[i].attach( BUTTON_PINS[i] , INPUT_PULLUP  );
    buttons[i].interval(25);           // interval in ms
    
  }
}

void loop() {

       sensorValue1 = analogRead(analogInPin1); 
       sensorValue2 = analogRead(analogInPin2); 
         
                  
     // map it to the range of the analog out:
     // outputValue = map(sensorValue, 0, 1023, 0, 255);
     // Serial.print("Button Value 1= ");
     // Serial.println(outputValue*0.005);
     // Serial.println(sensorValue*0.0015);
     
       //Serial.println(sensorValue2);             // Print as Raw data 0 to 1024 usb port
        Serial.print(sensorValue2*0.004888759);  // Print as Voltage  usb port
        Serial.print(",");
        
      // Serial.println(sensorValue1);             // Print as Raw data 0 to 1024 input 1
        Serial.println(sensorValue1*0.004888759);  // Print as Voltage input 1 
         
        
      //if (sensorValue1 < 1000)
     // {
      //  Serial.println(sensorValue1);
     // }
     // else if ((sensorValue1 > 1000))
      //{
       //  Serial.println(sensorValue1);
     // }
      
      
     
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  for (int i = 0; i < NUM_OF_BUTTONS; i++)
  {
    buttons[i].update();
  }

  // Check each button for "falling" edge.
  // Upon change, create corresponding keypress.
  // Upon rising edge, create corresponding keyboard release.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  for (int i = 0; i < NUM_OF_BUTTONS; i++)
  {
	   if ( buttons[i].fell() )
	  {
		   Keyboard.press(KEY_CODES[i]);
       
    }
    else if ( buttons[i].rose() )
    {
		  Keyboard.release(KEY_CODES[i]);
	  }


   
  }  //(for(int i=1; i<=NUM_BUTTONS; i++))
}  // (loop)
