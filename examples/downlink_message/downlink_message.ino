/*
  
  sigfox.h - Library example utilising the sigfox capabilities of 
  the bluefox development board by Net Sensors Ltd
  Created by Doug Mahy, January 6, 2018.
  Released into the public domain.
  
*/

//#define MY_DEBUG
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "Sigfox.h"

//create an instance of the Sigfox library/class
Sigfox sigfox;

void setup() {

  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
  
  Serial.begin(115200); Serial.println(); Serial.println("Starting ....");  //start up the serial port so you can see what is happening
 
  sigfox.begin();   // initialise instance of sigfox class modem 

  // modem starts powered down to save power until it is needed so needs to be reset/turned on before use.  
  // The if else clause can be used to check the success of the reset as reset returns true for success and false for fail
  
  if (sigfox.reset()){
    Serial.print("Reset     : ");Serial.println("success");
  }
  else{
    Serial.print("Reset     : ");Serial.println("fail");
  }  
  
  // gets the pac code a function parameter can be used to set the timeout in number of milliseconds
  // return type is String containing pac code or "timeout" if pac code cannot be retrieved.
  Serial.print("PAC code  : ");Serial.println(sigfox.getPacCode());

  // as above but for the device id
  Serial.print  ("Device Id : ");Serial.println(sigfox.getDeviceId(2000));

  // string we are going to send, hex chars only allowed must be even number no "half" bytes allowed
  String hexString = "F00DDEADBEEFC0FFEE";

  // function to send hex string no return value as device is sent to sleep and left to transmit on its own
  Serial.print("Sending   : "); Serial.println(hexString);

  Serial.print("Result    : ");Serial.println(sigfox.downlinkHexString(hexString));
  
  // example commented out below where we can send a byte array instead of a string   
  //byte message[] = {0x01, 0x69, 0x07, 0xB2, 0xA2, 0x4A, 0xBC, 0x16, 0xA2, 0xE5, 0xC0, 0x04};
  //sigfox.sendByteArray(message);

}

void loop() {
  // put your main code here, to run repeatedly:
}