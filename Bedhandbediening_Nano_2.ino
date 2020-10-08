//Keypad omzetter van enkel om naar relais kaart wissel contact. 8 channel
//aangepast voor de Arduino Nano   I/O omgewisseld van de Ralays
//10-11-2017 laatste aanpassing.
//IR learn toegevoegd & een buzzer aan/uit optie.
//I/O gecorrigeerd,3 seconden safe op AB toegevoegd.
//11-11-2017  Gewa inleer I/O en Binary gecorigeerd.
//12-11-2017  knop 5,6,7 buzzer gemaakt voor geen toepassing nog.
//20-7-2018   Programmeerbare relais uitgangen 1 t& m 8 (under construction).
//geupload als test voor github alleen 8-10-2020

#include <Keypad.h>
#include <EEPROM.h>


const byte ROWS = 3; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
  //  {'*','0','#'}
};

char keyassign[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
  //  {'*','0','#'}
};


byte rowPins[ROWS] = {1, 5, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3, 4, 7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


// byte ledPin = 13;  //onboard led   
const int buzzer = 13;            
 int relay1 = 14;   //output relay  1       (0
 int relay2 = 12;   //output relay  2       (6
 int relay3 = 11;   //output relay 3       (14  
 int relay4 = 10;   //output relay 4       (12
 int relay5 = 9;   //output relay 5       (11
 int relay6 = 8;   //output relay 6       (10
 int relay7 = 6;   //output relay  7       (9
 int relay8 = 0;   //output relay  8       (8
 

 int S0 = 15;   //output Bin mux
 int S1 = 16;   //output Bin mux
 int S2 = 17;   //output Bin mux
 int S3 = 18;   //output Bin mux
 int EnableMux = 19;   //Mux enable / disable


int address = 0;
int addresss = 1;
int addressss = 2;
int addresssss = 3;
int Radres4 =4;
int Radres5 =5;
int Radres6 =6;
int Radres7 =7;
int Radres8 =8;



byte value;
byte valuee;
byte valueee;
byte valueeee;

byte value3;
byte value4;
byte value5;
byte value6;
byte value7;
byte value8;


int count = 0; 
int relaisTel=0;

 

int addr = 0;
int addrr = 1;
int addrrr = 2;
int addrrrr = 3;

int Wadres3 =3;
int Wadres4 =4;
int Wadres5 =5;
int Wadres6 =6;
int Wadres7 =7;
int Wadres8 =8;



boolean blink = false;
boolean ledPin_state;
boolean Mux = false;
boolean Prog = false;



void setup(){
  //  Serial.begin(9600);
     keypad.setHoldTime(3000);                // Default is 1000mS 
     pinMode(buzzer, OUTPUT);               //Sets the digital pin to Buzzer output.
  //  pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay1, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay2, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay3, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay4, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay5, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay6, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay7, OUTPUT);              // Sets the digital pin as output.
    pinMode(relay8, OUTPUT);              // Sets the digital pin as output.
   
    pinMode(S0,OUTPUT);                   //Sets the digital pin as output.
    pinMode(S1,OUTPUT);                   //Sets the digital pin as output.
    pinMode(S2,OUTPUT);                   //Sets the digital pin as output.
    pinMode(S3,OUTPUT);                   //Sets the digital pin as output.
    pinMode(EnableMux,OUTPUT);               //Sets the digital pin as output.
   

      
   // digitalWrite(ledPin, LOW);           // Turn the LED on.
  //  ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    Mux = false;

   keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
        
  //  digitalWrite(ledPin, LOW); 
    digitalWrite(relay1, HIGH); 
    digitalWrite(relay2, HIGH); 
    digitalWrite(relay3, HIGH); 
    digitalWrite(relay4, HIGH); 
    digitalWrite(relay5, HIGH); 
    digitalWrite(relay6, HIGH); 
    digitalWrite(relay7, HIGH); 
    digitalWrite(relay8, HIGH); 


    digitalWrite(S0, HIGH);               // maak alle pinnen van de Mux hoog.
    digitalWrite(S1, HIGH);               // maak alle pinnen van de Mux hoog. 
    digitalWrite(S2, HIGH);               // maak alle pinnen van de Mux hoog.
    digitalWrite(S3, HIGH);               // maak alle pinnen van de Mux hoog.
    digitalWrite(EnableMux, HIGH);        //  Disable de mux.



         tone(buzzer, 1550); // Send 1KHz sound signal.
         delay(150);
         noTone(buzzer);     // Stop sound... 
         delay(150);
         tone(buzzer, 1550); // Send 1KHz sound signal.
         delay(150);      
         noTone(buzzer);     // Stop sound...  


   // Leest keypad bij opstarten ");
    delay(50);

    char key = keypad.getKey();



  if (key == '1') {  
         int val = 1;                                      //waarde naar EEprom voor geluid aan.
         tone(buzzer, 500); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 1500); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 2500); // Send 1KHz sound signal.
         delay(150);
         tone(buzzer, 3000); // Send 1KHz sound signal.
         delay(350);      
         noTone(buzzer);     // Stop sound...    
        EEPROM.write(addr, val);
        }

if (key == '2') {  
         int val = 0;                                         //waarde naar EEprom voor geluid uit.
         tone(buzzer, 3000); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 2500); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 1500); // Send 1KHz sound signal.
         delay(150);
         tone(buzzer, 500); // Send 1KHz sound signal.
         delay(500);      
         noTone(buzzer);     // Stop sound...    
        EEPROM.write(addr, val);
        }

 if (key == '3') {  
         int val = 1;                                      //waarde naar EEprom voor 3 seconden veilighied relay  aanzetten.
         tone(buzzer, 500); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 1500); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 2500); // Send 1KHz sound signal.
         delay(150);
         tone(buzzer, 3000); // Send 1KHz sound signal.
         delay(350);      
         noTone(buzzer);     // Stop sound...    
        EEPROM.write(addrr, val);
        }

 if (key == '4') {  
         int val = 0;                                      //waarde naar EEprom voor 3 seconden veilighied relay  uitzetten.
         tone(buzzer, 3000); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 2500); // Send 1KHz sound signal.  
         delay(150);  
         tone(buzzer, 1500); // Send 1KHz sound signal.
         delay(150);
         tone(buzzer, 500); // Send 1KHz sound signal.
         delay(350);      
         noTone(buzzer);     // Stop sound...    
        EEPROM.write(addrr, val);
        }

 if (key == '5') {  
        // int val = 1;                                      //reset alle relais weer naar de volgorde 1 t& m 8 oplopend.
         tone(buzzer, 2200); // Send 1KHz sound signal.  
         delay(750);  
         noTone(buzzer);     // Stop sound... 
         delay(250);
         tone(buzzer, 2200); // Send 1KHz sound signal.  
         delay(750);
         noTone(buzzer);     // Stop sound...    
         delay(250);
         tone(buzzer, 2200); // Send 1KHz sound signal.  
         delay(750);      
         noTone(buzzer);     // Stop sound...    
        
         EEPROM.write(addrrr, 1);  // reset relais 1 weer naar basis 1 
         EEPROM.write(addrrrr, 2);  // reset relais 2 weer naar basis 2  
        }
 
 if (key == '6') {  
        // int val = 1;                                      //Om nog te gebuiken als optie in de toekomst.
         tone(buzzer, 400); // Send 1KHz sound signal.  
         delay(200);  
         tone(buzzer, 200); // Send 1KHz sound signal.  
         delay(500);      
         noTone(buzzer);     // Stop sound...    
      //  EEPROM.write(addrr, val);
        }

 if (key == '7') {  
                                            //Om in de programmeermode te komen voor de ralais uitgangen in te stellen 1 t&m 8.
        tone(buzzer, 440); // Send 1KHz sound signal.  
         delay(120);  
         tone(buzzer, 880); // Send 1KHz sound signal.  
         delay(120);  
         tone(buzzer, 1320); // Send 1KHz sound signal.
         delay(120);
         tone(buzzer, 1760); // Send 1KHz sound signal.
         delay(120);
         tone(buzzer, 2200); // Send 1KHz sound signal.  
         delay(120);     
         noTone(buzzer);     // Stop sound...  

     RelaisRedisign:
         char key = keypad.getKey();                 //lees keypad  
         Prog = true;
      goto RelaisRedisign;      
     
        }
 
 

      if (key == '8') {                                        //om IRlearn mode te komen.

         tone(buzzer, 500); // Send 1KHz sound signal.  
         delay(120);  
         tone(buzzer, 800); // Send 1KHz sound signal.  
         delay(120);  
         tone(buzzer, 1000); // Send 1KHz sound signal.
         delay(120);
         tone(buzzer, 1250); // Send 1KHz sound signal.
         delay(120);
         tone(buzzer, 1500); // Send 1KHz sound signal.  
         delay(120);     
         noTone(buzzer);     // Stop sound...  
          
      IRlearn:
         char key = keypad.getKey();                 //lees keypad  
         //   digitalWrite(ledPin,!digitalRead(ledPin));  //onboardled 50mms. 
         digitalWrite(EnableMux,LOW);                 //Zet de mux aan. 
         Mux = true;
      goto IRlearn;
       
        }
      

    
}


void loop(){
    char key = keypad.getKey();

    if (key) {
          value = EEPROM.read(address);
          valuee = EEPROM.read(addresss);
          
          valueee = EEPROM.read(addressss);
          valueeee = EEPROM.read(addresssss);
           
          if (value==1){
           // Serial.println(key);
           tone(buzzer, 2000); // voor een toon van 2 khz bij het indrukken van een toets.
           delay(50);  
           noTone(buzzer);     // Stop sound. 
          } 
        }



        
    
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        
        if (key == '1'){
            if (Mux==0){
              if (Prog==1){
                // digitalWrite(relay8, LOW);
                
                  count++;
                      if (count==1){
                         digitalWrite(relay1, LOW); 
                         int val=1;
                         EEPROM.write(addrrr, val);
                      }
                      if (count==2){
                         digitalWrite(relay2, LOW); 
                         int val=2;
                         EEPROM.write(addrrr, val);
                      }     
                      if (count==3){
                         digitalWrite(relay3, LOW);
                         int val=3;
                         EEPROM.write(addrrr, val); 
                      }
                      if (count==4){
                         digitalWrite(relay4, LOW); 
                         int val=4;
                         EEPROM.write(addrrr, val);
                      }    
                       if (count==5){
                         digitalWrite(relay5, LOW); 
                         int val=5;
                         EEPROM.write(addrrr, val);
                      }
                      if (count==6){
                         digitalWrite(relay6, LOW); 
                         int val=6;
                         EEPROM.write(addrrr, val);
                      }     
                      if (count==7){
                         digitalWrite(relay7, LOW);
                         int val=7;
                         EEPROM.write(addrrr, val); 
                      }
                      if (count==8){
                         digitalWrite(relay8, LOW);
                         int val=8;
                         EEPROM.write(addrrr, val); 
                         count=0;
                      }    
              }
               else

              if (valueee==1){
                 digitalWrite(relay1, LOW);
               }
               if (valueee==2){
                digitalWrite(relay2, LOW); 
               }
                if (valueee==3){
                 digitalWrite(relay3, LOW);
               }
               if (valueee==4){
                digitalWrite(relay4, LOW);
               }
                if (valueee==5){
                 digitalWrite(relay5, LOW);
               }
               if (valueee==6){
                digitalWrite(relay6, LOW); 
               }
                if (valueee==7){
                 digitalWrite(relay7, LOW);
               }
               if (valueee==8){
                digitalWrite(relay8, LOW);
               }           


               
             //   digitalWrite(relay1, LOW);    //in standaard mode doet hij relais 1 schakelen.
                
            }
        else
        { 
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.       
          digitalWrite(S0, HIGH);     //mux binary code  1   kanaal 1.
          digitalWrite(S1, HIGH);     //mux binary code  1
          digitalWrite(S2, HIGH);     //mux binary code  1    
          digitalWrite(S3, LOW);      //mux binary code  0
        }                       
        }



    
        if (key == '2'){ 
           if (Mux == false){ 
               if (Prog==1){
                // digitalWrite(relay8, LOW);
                
                  count++;
                      if (count==1){
                         digitalWrite(relay1, LOW); 
                         int val=1;
                         EEPROM.write(addrrrr, val);
                      }
                      if (count==2){
                         digitalWrite(relay2, LOW); 
                         int val=2;
                         EEPROM.write(addrrrr, val);
                      }     
                      if (count==3){
                         digitalWrite(relay3, LOW);
                         int val=3;
                         EEPROM.write(addrrrr, val); 
                      }
                      if (count==4){
                         digitalWrite(relay4, LOW); 
                         int val=4;
                         EEPROM.write(addrrrr, val);
                      }    
                       if (count==5){
                         digitalWrite(relay5, LOW); 
                         int val=5;
                         EEPROM.write(addrrrr, val);
                      }
                      if (count==6){
                         digitalWrite(relay6, LOW); 
                         int val=6;
                         EEPROM.write(addrrrr, val);
                      }     
                      if (count==7){
                         digitalWrite(relay7, LOW);
                         int val=7;
                         EEPROM.write(addrrrr, val); 
                      }
                      if (count==8){
                         digitalWrite(relay8, LOW);
                         int val=8;
                         EEPROM.write(addrrrr, val); 
                         count=0;
                      }    
              }
               else

              if (valueeee==1){
                 digitalWrite(relay1, LOW);
               }
               if (valueeee==2){
                digitalWrite(relay2, LOW); 
               }
                if (valueee==3){
                 digitalWrite(relay3, LOW);
               }
               if (valueeee==4){
                digitalWrite(relay4, LOW);
               }
                if (valueeee==5){
                 digitalWrite(relay5, LOW);
               }
               if (valueeee==6){
                digitalWrite(relay6, LOW); 
               }
                if (valueeee==7){
                 digitalWrite(relay7, LOW);
               }
               if (valueeee==8){
                digitalWrite(relay8, LOW);
               }           
               
             //   digitalWrite(relay2, LOW);    //in standaard mode doet hij relais 1 schakelen.
                
            }  
            
           else
           {  
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.        
          digitalWrite(S0, LOW);      //mux binary code  0   knaal 2.
          digitalWrite(S1, HIGH);     //mux binary code  1
          digitalWrite(S2, HIGH);      //mux binary code 1
          digitalWrite(S3, LOW);      //mux binary code  0
         
        }   
        }
        

        if (key == '3'){ 
            if (Mux == false){ 
                 if (Prog==1){
                // digitalWrite(relay8, LOW);
                
                  count++;
                      if (count==1){
                         digitalWrite(relay1, LOW); 
                         int val=1;
                         EEPROM.write(Wadres3, val);
                      }
                      if (count==2){
                         digitalWrite(relay2, LOW); 
                         int val=2;
                         EEPROM.write(Wadres3, val);
                      }     
                      if (count==3){
                         digitalWrite(relay3, LOW);
                         int val=3;
                         EEPROM.write(Wadres3, val); 
                      }
                      if (count==4){
                         digitalWrite(relay4, LOW); 
                         int val=4;
                         EEPROM.write(Wadres3, val);
                      }    
                       if (count==5){
                         digitalWrite(relay5, LOW); 
                         int val=5;
                         EEPROM.write(Wadres3, val);
                      }
                      if (count==6){
                         digitalWrite(relay6, LOW); 
                         int val=6;
                         EEPROM.write(Wadres3, val);
                      }     
                      if (count==7){
                         digitalWrite(relay7, LOW);
                         int val=7;
                         EEPROM.write(Wadres3, val); 
                      }
                      if (count==8){
                         digitalWrite(relay8, LOW);
                         int val=8;
                         EEPROM.write(Wadres3, val); 
                         count=0;
                      }    
              }
               else

              if (value3==1){
                 digitalWrite(relay1, LOW);
               }
               if (value3==2){
                digitalWrite(relay2, LOW); 
               }
                if (value3==3){
                 digitalWrite(relay3, LOW);
               }
               if (value3==4){
                digitalWrite(relay4, LOW);
               }
                if (value3==5){
                 digitalWrite(relay5, LOW);
               }
               if (value3==6){
                digitalWrite(relay6, LOW); 
               }
                if (value3==7){
                 digitalWrite(relay7, LOW);
               }
               if (value3==8){
                digitalWrite(relay8, LOW);
               }                     
            }               
     
         // digitalWrite(relay3, LOW); 
          else
          {   
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.    
          digitalWrite(S0, HIGH);    //mux binary code  1  kanaal 3.
          digitalWrite(S1, LOW);     //mux binary code  0
          digitalWrite(S2, HIGH);    //mux binary code  1
          digitalWrite(S3, LOW);     //mux binary code  0
          
         }
        }

        
        if (key == '4'){ 
             if (Mux == false){   
    //      digitalWrite(ledPin, HIGH); 
          digitalWrite(relay4, LOW);
         }
        else
         {
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.  
          digitalWrite(S0, LOW);      //mux binary code  0  kanaal 4.
          digitalWrite(S1, LOW);      //mux binary code  0
          digitalWrite(S2, HIGH);     //mux binary code  1
          digitalWrite(S3, LOW);      //mux binary code  0      
         
        } 
        }

         
         if (key == '5'){ 
              if (Mux == false){   
      //    digitalWrite(ledPin, HIGH); 
          digitalWrite(relay5, LOW); 
         }
         else
         {
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.  
          digitalWrite(S0, HIGH);     //mux binary code  1  kanaal 5.
          digitalWrite(S1, HIGH);     //mux binary code  1
          digitalWrite(S2, LOW);      //mux binary code  0
          digitalWrite(S3, LOW);      //mux binary code  0   
          
        }
        }

        
        if (key == '6'){ 
           if (Mux == false){   
     //     digitalWrite(ledPin, HIGH); 
          digitalWrite(relay6, LOW);   
          }
          else
          {
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.  
          digitalWrite(S0, LOW);      //mux binary code  0  kanaal 6.
          digitalWrite(S1, HIGH);      //mux binary code 1
          digitalWrite(S2, LOW);      //mux binary code  0
          digitalWrite(S3, LOW);      //mux binary code  0   
          
        }   
        }


        if (key == '7'){ 
           if (Mux == false){   
      //    digitalWrite(ledPin, HIGH); 
          digitalWrite(relay7, LOW); 
         }
         else
         {
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.  
          digitalWrite(S0, HIGH);      //mux binary code  1  kanaal 7.
          digitalWrite(S1, LOW);       //mux binary code  0
          digitalWrite(S2, LOW);       //mux binary code  0
          digitalWrite(S3, LOW);       //mux binary code  0   
          
        }
        }
        
        if (key == '8'){ 
           if (Mux == false){   
      //    digitalWrite(ledPin, HIGH); 
          digitalWrite(relay8, LOW);
         }
         else
         {
          tone(buzzer, 850); // Send 1KHz sound signal.  
          delay(75);  
          noTone(buzzer);     // Stop sound.  
          digitalWrite(S0, LOW);      //mux binary code  0  kanaal 8.
          digitalWrite(S1, LOW);      //mux binary code  0
          digitalWrite(S2, LOW);      //mux binary code  0
          digitalWrite(S3, LOW);      //mux binary code  0        
        }
        }
        
          
        break;

       

    case RELEASED:
     if (key == '1') {    
         //  blink = false;
        //   digitalWrite(ledPin, LOW); 
            digitalWrite(relay1, HIGH); 
            digitalWrite(relay2, HIGH);
            digitalWrite(relay3, HIGH);
            digitalWrite(relay4, HIGH);
            digitalWrite(relay5, HIGH);
            digitalWrite(relay6, HIGH);
            digitalWrite(relay7, HIGH);
            digitalWrite(relay8, HIGH);  
           
            digitalWrite(S0, HIGH);     //mux binary code   1 
            digitalWrite(S1, HIGH);      //mux binary code  1
            digitalWrite(S2, HIGH);      //mux binary code  1    
            digitalWrite(S3, HIGH);      //mux binary code  1
          if (Prog==1){
            digitalWrite(relay1, HIGH);
            digitalWrite(relay2, HIGH);
            digitalWrite(relay3, HIGH);
            digitalWrite(relay4, HIGH);
            digitalWrite(relay5, HIGH);
            digitalWrite(relay6, HIGH);
            digitalWrite(relay7, HIGH);
            digitalWrite(relay8, HIGH);
            }
        }
        
     if (key == '2') { 
       //   digitalWrite(ledPin, LOW);
            digitalWrite(relay1, HIGH); 
            digitalWrite(relay2, HIGH);
            digitalWrite(relay3, HIGH);
            digitalWrite(relay4, HIGH);
            digitalWrite(relay5, HIGH);
            digitalWrite(relay6, HIGH);
            digitalWrite(relay7, HIGH);
            digitalWrite(relay8, HIGH);  
          
            digitalWrite(S0, HIGH);     //mux binary code   1 
            digitalWrite(S1, HIGH);      //mux binary code  1
            digitalWrite(S2, HIGH);      //mux binary code  1    
            digitalWrite(S3, HIGH);      //mux binary code  1

        if (Prog==1){
            digitalWrite(relay1, HIGH);
            digitalWrite(relay2, HIGH);
            digitalWrite(relay3, HIGH);
            digitalWrite(relay4, HIGH);
            digitalWrite(relay5, HIGH);
            digitalWrite(relay6, HIGH);
            digitalWrite(relay7, HIGH);
            digitalWrite(relay8, HIGH);
            }
        
            
        }

   if (key == '3') {    
      //     digitalWrite(ledPin, LOW); 
           digitalWrite(relay3, HIGH); 
           digitalWrite(S0, HIGH);     //mux binary code   1
           digitalWrite(S1, HIGH);      //mux binary code  1
           digitalWrite(S2, HIGH);      //mux binary code  1   
           digitalWrite(S3, HIGH);      //mux binary code  1
         
        }
        if (key == '4') { 
       //   digitalWrite(ledPin, LOW);
          digitalWrite(relay4, HIGH);  
           digitalWrite(S0, HIGH);     //mux binary code   1 
           digitalWrite(S1, HIGH);      //mux binary code  1
           digitalWrite(S2, HIGH);      //mux binary code  1    
           digitalWrite(S3, HIGH);      //mux binary code  1
        }

         if (key == '5') {    
      //     digitalWrite(ledPin, LOW); 
           digitalWrite(relay5, HIGH); 
           digitalWrite(S0, HIGH);     //mux binary code   1 
           digitalWrite(S1, HIGH);      //mux binary code  1
           digitalWrite(S2, HIGH);      //mux binary code  1    
           digitalWrite(S3, HIGH);      //mux binary code  1
           
        }
        if (key == '6') { 
     //     digitalWrite(ledPin, LOW);
          digitalWrite(relay6, HIGH); 
           digitalWrite(S0, HIGH);     //mux binary code   1 
           digitalWrite(S1, HIGH);      //mux binary code  1
           digitalWrite(S2, HIGH);      //mux binary code  1    
           digitalWrite(S3, HIGH);      //mux binary code  1 
        }

        if (key == '7') {    
      //     digitalWrite(ledPin, LOW); 
           digitalWrite(relay7, HIGH); 
           digitalWrite(S0, HIGH);     //mux binary code   1 
           digitalWrite(S1, HIGH);      //mux binary code  1
           digitalWrite(S2, HIGH);      //mux binary code  1    
           digitalWrite(S3, HIGH);      //mux binary code  1
        }
        if (key == '8') { 
//          digitalWrite(ledPin, LOW);
          digitalWrite(relay8, HIGH); 
           digitalWrite(S0, HIGH);     //mux binary code   1 
           digitalWrite(S1, HIGH);      //mux binary code  1
           digitalWrite(S2, HIGH);      //mux binary code  1    
           digitalWrite(S3, HIGH);      //mux binary code  1 
        }
        
        break;

    case HOLD:
        if (key && valuee==1) {               // na 3 seconden valt altijd het relay af.
          
             digitalWrite(relay1, HIGH); 
             digitalWrite(relay2, HIGH); 
             digitalWrite(relay3, HIGH); 
             digitalWrite(relay4, HIGH); 
             digitalWrite(relay5, HIGH); 
             digitalWrite(relay6, HIGH); 
             digitalWrite(relay7, HIGH); 
             digitalWrite(relay8, HIGH); 
      
       }
        break;
             
    }
}
