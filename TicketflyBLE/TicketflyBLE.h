/*
* TicketflyBLE.h by Michael Albinson
* Based on the RBL nRF80001 library
* NOTE: If you don't include one of the body (loop) functions (either beaconSendData or readIncoming), you MUST add ble_do_events() to the body of your 
* loop function, otherwise the BLE will not initialize (although it will not do anything without either of these functions... So if you
* do not plan to use them you may want to consider not using this library)
*/

#ifndef TICKETFLYBLE_H_
#define TICKETFLYBLE_H_


#include "Arduino.h"
#include <SPI.h>
#include <boards.h>
#include <RBL_LibCLONE.h>

#define CHARS_TO_READ 14 //Set number of char to read from the BLE (max of 16)

class BLE {
public:
	BLE();  //Constructor for the BLE object
	void TflyBLESetup (); //Initializes the BLE--use only in the setup loop
	void beaconSendData(); //Tells the BLE beacon to send data typed into the serial monitor
	String readIncoming(); //tells the BLE beacon to receive data sent from the RBL BLE app-->returns it as a string
};

#endif
