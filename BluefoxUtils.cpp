/*
  
  BluefoxUtils.h - Library for utilising the sigfox capabilities of 
  the bluefox development board by Net Sensors Ltd
  Created by Doug Mahy, January 6, 2018.
  Released into the public domain.
  
*/


#include "Arduino.h"
#include "BluefoxUtils.h"

#define LED_BUILTIN 0

BluefoxUtils::BluefoxUtils(){
		
		
}

void BluefoxUtils::wait(long delaytime){
    long delayMillis = millis();
    while (millis() < (delayMillis + delaytime)) {}   
}

void BluefoxUtils::printDebug(String key){


     
  //check length of key and value is less than 30 charachters if more then truncate else pad with charachters.
  
  int keylength = 30;
  
  if (key.length() > keylength){
    key.remove(keylength);
  }
  else{
     for (int i = key.length(); i < keylength; i++){
          key.concat(" ");  
     } 
  }
  key.concat(": "); 
  Serial.print(key);
    #ifdef DEBUG_LOG
      logString.concat(key);
    #endif 
 
  
 
}

void BluefoxUtils::printDebug(String key,String val){
  
      printDebug(key);
      printDebugValue(val);
 
}

void BluefoxUtils::printDebugValue(String val){
  
     Serial.println(val);
    #ifdef DEBUG_LOG
     logString.concat(val);
     logString.concat("\n");
    #endif 
      
  
  
}

void BluefoxUtils::flash(long flashOnMillis, long flashOffMillis, int repeat){


  for (int i=0;i<repeat;i++){
    
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    wait(flashOnMillis); 
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW  
    wait(flashOffMillis);
  
  }

 
 
}

