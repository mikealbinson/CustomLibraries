/*
* TicketflyBLE.h by Michael Albinson
* Based on the RBL nRF80001 library
*/

#include "TicketflyBLE.h"

BLE::BLE (){
}

void BLE::TflyBLESetup(){ 
  ble_set_name ("TFLY");
  ble_begin ();
  Serial.begin (57600);
}

void beaconSendData(){ 
  int carrier;
  char sendCharArray[14];
  if (Serial.available()){
    delay(5);
    while (Serial.available()){
      carrier = Serial.read();
      ble_write ( carrier );  
    }
  }
  ble_do_events();
}

String BLE::readIncoming(){ 
  int i=0;
  char stringBase[CHARS_TO_READ];
	for (int i=0; i<CHARS_TO_READ; i++){
    stringBase[i] = 1;
  }
  String finalString="";
  if (ble_available()){
    while (ble_available()){
      int carrier = ble_read();
      Serial.write (carrier);
      if (i<CHARS_TO_READ){
        stringBase [i] = carrier;
      }
      i++;
    }
    for (i=0;i<CHARS_TO_READ;i++){
      finalString = finalString + stringBase[i];
    }
    Serial.println("");
    Serial.println (finalString);
    return finalString;
  }
  ble_do_events();
}
