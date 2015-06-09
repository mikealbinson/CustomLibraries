/*
* SDBeacon.h By Michael Albinson
* Based on the SdFat library
*
*/


#ifndef SDBeacon_h
#define SDBeacon_h

#include "Arduino.h"
#include <SdFatMod.h> //THIS FILE REQUIRES A MODIFIED VERSION OF <SdFat.h>
#include <SPI.h>

#define maxTitleSize 16

class TicketflySDBeacon{

	
public:
	TicketflySDBeacon(); //TicketflySDBeacon object constructor

	void SDBeaconSetup(SdFat& SD); //go here to change files that are being searched for each type--ONLY USE IN THE SETUP LOOP

	String textFileSelect (); //Takes in input from the serial monitor and outputs a String that can be used in the following functions to declare
							  //the file(s) you would like to use. It is suggested that this be implemented in the setup function.

	bool searchDatabaseForTicket(String TicketString, SdFat& SD); //One method to search for a ticket in your SD database, returns true
																  //if the ticket is found

	void writeToSD(String writeThisString, String fileName, SdFat& SD); //Writes a string to the file indicated by "fileName". 

	void simpleReadSD (String fileName, SdFat& SD); //Reads the entirety of the file indicated by "fileName"

	void fileRemove (String fileName, SdFat& SD); //removes the fiel indicated by "fileName" --NOTE: this file cannot be recovered after it is removed

	bool ticketCompare (String searchFor, String compareToThis); //A method for parseTextLines that compares twp tickets and returns true
																 //if they are the same

	String TicketInfoParser (String TicketString, int typeReturn); //a method for parseTextLines that pulls reads a file line by line
																   //to a string. Returns the string of either the number, name or type
																   //of ticket (must be separated by commas in the file)

	String parseTextLines (String TicketRecieved, int receiveType, SdFat& SD, TicketflySDBeacon& SDB); //combines the above two functions to
																									   //compare the "TicketReceived"
																									   //string to the document to check 
																									   //if it exists on the SD file

};

#endif

