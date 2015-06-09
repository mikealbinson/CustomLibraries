/*
* SDBeacon.cpp By Michael Albinson
* Based on the SdFat library
*
*/

#include "SDBeacon.h"

TicketflySDBeacon::TicketflySDBeacon(){
}

void TicketflySDBeacon::SDBeaconSetup (SdFat& SD) {
	Serial.begin (9600);
  Serial.print(F("Initializing SD card..."));
	pinMode(10, OUTPUT);
	
  if (!SD.begin(4)) {
    Serial.println(F("initialization failed!"));
    return;
  }
  Serial.println(F("initialization done."));

}

String TicketflySDBeacon::textFileSelect (){
	int i = 0;
	char stringBase [maxTitleSize];
	String fileTitle;
	if (Serial.available ())
	{
		while (Serial.available()){
			int carrier = Serial.read();
			stringBase[i] = carrier;
			i++;
		}
		for (i=0; i<maxTitleSize; i++){
			fileTitle = fileTitle + stringBase [i];
		}
		return fileTitle;
	}
}

bool TicketflySDBeacon::searchDatabaseForTicket(String TicketString, SdFat& SD){ 
		File myFile;
		const char* TicketNo = TicketString.c_str();
		myFile = SD.open("example.txt");  
		if (myFile) {
    	char buf[16];
    	myFile.read(buf, 16);
    	if (strncmp(buf, TicketNo, 14) == 0)
    	{
      	Serial.println(F("Match!"));
      	return true;
    	}
    	else {
				Serial.println (F("No Match"));
      	return false;
    	}
    myFile.close();
  }
	else {
	Serial.println(F("error opening file"));
  }
}

void TicketflySDBeacon::writeToSD (String writeThisString, String fileName, SdFat& SD) { 
	File myFile;
	const char* conversion = fileName.c_str();
	Serial.println (conversion);
	myFile = SD.open(conversion);
  if (myFile) {
    myFile.println(writeThisString);
    myFile.close();
  } 
	else {
    Serial.println(F("error opening example.txt"));
  }
}

void TicketflySDBeacon::simpleReadSD (String fileName, SdFat& SD){ 
	File myFile;
	const char* conversion = fileName.c_str();
	myFile = SD.open(conversion, FILE_READ);
	if (myFile) {
	  while (myFile.available()) {
	    Serial.write(myFile.read());
	  }
	  myFile.close();
	} 
	else 
	{
	    Serial.print(F("Error opening "));
			Serial.println (fileName);
	 }
}

void TicketflySDBeacon::fileRemove (String fileName, SdFat& SD) { 
	File myFile;
	const char* conversion = fileName.c_str();
  myFile = SD.open(conversion);
  SD.remove(conversion);
}

bool TicketflySDBeacon::ticketCompare (String searchFor, String compareToThis) {
  const char * conversion1 = searchFor.c_str();
  const char * conversion2 = compareToThis.c_str();
  if (strcmp (conversion1, conversion2) == 0) {
    return true;
  }
  else {
   return false;
  }
}

String TicketflySDBeacon::TicketInfoParser (String TicketString, int typeReturn){ 
  String TicketNumberRetrieve = "", TicketNameRetrieve = "", TicketTypeRetrieve = "";
  int lengthString, commaIndex1, commaIndex2;
  TicketString.replace(" ", "");
  lengthString = TicketString.length();
  commaIndex1 = TicketString.indexOf(',');
  commaIndex2 = TicketString.indexOf(',', commaIndex1+1);
    switch (typeReturn){
      case 1:
        TicketNumberRetrieve = TicketString.substring (0, commaIndex1);
        return TicketNumberRetrieve;
        break;
      case 2:
        TicketNameRetrieve = TicketString.substring (commaIndex1+1, commaIndex2);
        return TicketNameRetrieve;
        break;
      case 3:
        TicketTypeRetrieve = TicketString.substring (commaIndex2+1, lengthString);
        return TicketTypeRetrieve;
        break;
      default:
        return "empty";
        Serial.println (F("this is not an acceptable input"));
        break;
    }
}

String TicketflySDBeacon:: parseTextLines (String TicketRecieved, int receiveType, SdFat& SD, TicketflySDBeacon& SDB) {
  char line[50]; //max 50 char/line 
	int lineIndex = 0;
  int n;
  String carrier;
  SdFile file("example.txt", O_READ);
  if (!file.isOpen()) Serial.println(F("ERROR")); //Check 
  while ((n = file.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
      line[n - 1] = 0;
      /* uncomment for debugging
      Serial.print (lineIndex);
      Serial.print (": ");
      Serial.println(line);
      Serial.println (TicketInfoParser (line, 1));
      */
      lineIndex++;
      carrier = TicketInfoParser (line, 1);
      if (SDB.ticketCompare(TicketRecieved, carrier)){
        Serial.println ("Match");
        return TicketInfoParser (line, receiveType);
      }
    } 
    else {
      Serial.println (F("Line too long"));
    }
  }
}
