/*
* OLEDResponses.h by Michael Albinson
* Based heavily upon the U8g graphics library
* Brief function descriptions are provided below, but more detailed 
*/

#ifndef OLEDResponses_h
#define OLEDResponses_h

#include <U8gLibClone.h> //a simplified version of the U8g library to ease RAM usage
#include "Arduino.h" //required for all libraries

class OLED{
  private: 
  	U8GLIB_SSD1306_128X32 *u8g; //from the U8glib, used to initialize the SSDD1306 OLED.
  								//Others moy be substituted or added from any of the U8g example .ino files
	
  public:
  	OLED(); 
	//constructor for the OLED object.

	void drawTicketflyLogo (); 
	//draws a bitmap image of the Ticketfly logo and displays it until the next drawxxx() call

	void drawSetup();
	//prints the words "setting up" to the screen to indicate that the OLED is working

  	void drawGeneral(String stringToPrint);
  	//prints the desired text to the OLED--Note that after about 10 chars the words will run off the screen

  	void drawGeneral(String stringToPrint, int delayThisLong);
  	//prints the desired text to the OLED for a specified amount of time in seconds. See above. 

};

#endif // OLEDResponses_h
