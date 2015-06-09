#ifndef MOCKS_H_
#define MOCKS_H_

#include "arduino.h"
#include <U8gLibClone.h>
#include <Testing.h>
#include <SPI.h>
#include <boards.h>
#include <RBL_LibCLONE.h>

#define CHARS_TO_READ 14

void testingScenario ();
void endOfScenario ();

class MockFile{
public:
	MockFile(); //Constructor for the mockFile class
	bool read(); //a read function that evuates to true
	const char* read (const char* interest, int that); // a secondary read function that evaluates to true
	bool close(); //a close function mock up that evaluates to true
	String println(String lineToPrint); //a println mock function that returns the string printed
	bool available(); //a mock available function that evaluates to true
	
private:
	String readerString = "HelloYouThere";
};

class MockSdFat {
 public:
	MockSdFat(); //Constructor for the MockSdFat class
	bool open(String file); //a mock open function that evaluates to true
	bool open(String file, const uint8_t function); //a secondary mock open function that evaluates to true
	bool begin(int i);//a mock begin function that evaluates to true
	bool remove (String file);//a mock remove function that evaluates to true
	bool available(); //a mock available function that evaluates to true

};

class MockSDBeacon{
public:
	  MockSDBeacon(); //Constructor for the MockSDBeacon class
		void SDBeaconSetup (MockSdFat& SD); //a mock setup function that includes a test to demonstrate if the file opens or not
		bool searchDatabaseForTicket(String TicketString, MockSdFat& SD,  MockFile& myFile); //a mock search function that evaluates to true
		void writeToSD (String writeThisString, String fileName, MockSdFat& SD, MockFile& myFile); //a mock write function that includes a test to demonstrate if the file is written to or not
		void simpleReadSD (String fileName, MockSdFat& SD, MockFile& myFile);//a mock read function that includes a test to demonstrate if the file is read or not
		void fileRemove (String fileName, MockSdFat& SD, MockFile& myFile);//a mock remove function that includes a test to demonstrate if the file is removed or not
};

class MockOLED{
	private:
	U8GLIB_SSD1306_128X32MOCK *MOCKu8g; //constructor for the MOCKu8g object
	bool exists; //used internally
		
	
  public:
		int MockPrintToOLED (String printThis); // a mock print function for the OLED
		int setColorIndexMock(int type); // a mock setIndex function for the OLED
  	MockOLED(); //Constructor for the MockOLED class
		void drawSetupMock(MockOLED &obj); //a mock setup function for the OLED
  	const char* drawGeneralMock(String stringToPrint, MockOLED &obj); // a mock general draw function for the OLED
};

class MockBLE {
public:
	MockBLE(); //Constructor for the MockBLE class
	void TflyBLESetup ();//a mock setup function for the BLE
	void clearParsingSetups(String stringToClear, char charArrayToClear[]);
	void beaconSendData();//a mock send function for the BLE
	String readIncoming();//a mock receive function for the BLE
	
private:
	int ble_available = true; //let's assume we're costantly connected
	char MockBLE_Read(int &i); // an interior read method that allows for simulated reading
	const char* MockBLE_write (int carrier, int &i); // an interior method for simulated writing
	
};


#endif
