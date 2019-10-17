/*
 * Generated with JETTTT by Dckuino.js project !
 * Total time : 157.3sec (2m37.3s)
 */

#include "Keyboard.h"
int RXLED = 17;  // The RX LED has a defined Arduino pin
int windows = 0;
void blinkDelay(unsigned long j){
  TXLED0;
  j=j/1000;
  for(int i=1 ; i<j ; i++){
    if(i%10==0){
      for(int i=1 ; i<=5 ; i++){
      digitalWrite(RXLED, LOW);   // set the RX LED ON
      delay(100);              // wait for a second
      digitalWrite(RXLED, HIGH);    // set the RX LED OFF
      delay(100);    
	  Serial.write('Y');
      }
    }
    else{  
    digitalWrite(RXLED, LOW);   // set the RX LED ON
    delay(500);              // wait for a second
    digitalWrite(RXLED, HIGH);    // set the RX LED OFF
    delay(500);    
	Serial.write('Y');
    }
  }
  for(int i=1 ; i<=5 ; i++){
    
  digitalWrite(RXLED, LOW);   // set the RX LED ON
  TXLED0;
  delay(100);              // wait for a second
  
  digitalWrite(RXLED, HIGH);    // set the RX LED OFF
  TXLED1;
  delay(100);    
  }
  TXLED1;
}


void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void waitWindows() {
  while(windows == 0){
    if (Serial.available()) {
        char serialListener = Serial.read();
        if (serialListener == 'Y') {
            windows = 1;
        }
        else {}
        }
    }
   blinkDelay(1000);
 }



/* Init function */
void setup()
{
  Serial.begin(9600);
  // Begining the Keyboard stream
	waitWindows();

	blinkDelay(10000);
	Keyboard.begin();
  
  // Wait  for boot windows
  
  

  // --> Minimize all windows
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.press('d');
  delay(500);
  Keyboard.releaseAll();
  delay(1000);
  // --> Open cmd
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.press('r');
  delay(500);
  Keyboard.releaseAll();

  blinkDelay(1000);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);

  blinkDelay(1000);

  
  
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.press('d');
  delay(500);
  Keyboard.releaseAll();
  delay(1000);
  
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();
  delay(500);
  
  
  
  
  // --> Start program BMS
  Keyboard.print("Start \"\" \"%USERPROFILE%\\Google Drive\\Narada2\\bin\\BMS.exe\"");

  typeKey(KEY_RETURN);
  //wait program open
  blinkDelay(70000);
  
//  typeKey(KEY_RETURN);//no com port (OK)

  Keyboard.press(KEY_LEFT_CTRL);
  delay(500);
  Keyboard.press('g');
  delay(500);
  Keyboard.releaseAll();

  blinkDelay(1000);
  typeKey(KEY_TAB);
  blinkDelay(1000);
  typeKey(KEY_TAB);
  blinkDelay(1000);
  typeKey(KEY_RETURN);
  blinkDelay(1000);
  
//  typeKey(KEY_RETURN);//no com port (OK)

  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();
  
  delay(500);
  
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();

  
  blinkDelay(30000);

  typeKey(KEY_TAB);

  blinkDelay(1000);
  
  typeKey(KEY_RETURN);

  blinkDelay(1000);

//  typeKey(KEY_RETURN);//no com port (OK)
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.releaseAll();
  delay(50);
  Keyboard.press('n');
  Keyboard.releaseAll();

  blinkDelay(10000);
  Keyboard.press(KEY_ESC);
  delay(50);
  Keyboard.releaseAll();
  blinkDelay(1000);
  typeKey(KEY_TAB);
  blinkDelay(1000);

  typeKey(KEY_TAB);
  blinkDelay(1000);
  
  Keyboard.press('d');
  Keyboard.releaseAll();

  blinkDelay(3000);
  
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();
  
  blinkDelay(5000);
  
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();
  
//  Keyboard.press(KEY_LEFT_GUI);
//  Keyboard.releaseAll();
//  delay(1000);
//  Keyboard.press(KEY_LEFT_GUI);
//  Keyboard.releaseAll();
  
  blinkDelay(1000);
  
  for (int i=0;i<=7;i++){delay(100); typeKey(KEY_TAB);}

  delay(1000);

  typeKey(KEY_DELETE);

  Keyboard.print("1");

  blinkDelay(1000);
  
  typeKey(KEY_TAB);

  blinkDelay(5000);

  while(1==1){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('e');
  Keyboard.releaseAll();
  blinkDelay(30000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  blinkDelay(270000);
  }
  // Ending stream
  Keyboard.end();
}

void loop() {}
