#mocks

This library is designed to test the functionalities of the RBL BLE library, the SdFat library and the U8g library without the need of physical hardware to interface with. This library, thus, stands as a kind of basis to test on without the access to the hardware if you just have an arduino.

Note that not all of the methods from the original libraries have been implemented, just the ones I felt I needed as I tested my own functions. The rest could hypothetically come with time, so this will be gradually updated as I find I need new functionalities out of this library. 

##### This library will only require the Testing library from this repository (at some point soon)

##Function Descriptions
The biggest problem with this library is that it combines a large numbers of functions that reside within their own mock object class. So it will be difficult to outline their functionality briefly here. HOWEVER, I can offer a general rule of thumb that the functions I have provided will act as closely to the real objects as I could make them, and that almost every time a function has a boolean return it will just return true for the sake of testing. That said heres a more or less exhaustive list of the PUBLIC functions. You shouldn't really need to worry about the private ones unless you are trying to mod this library.

This library assumes some knowledge of the actual libraries that these mock objects are based off of and what those interior functions are supposed to do.

#### MockFile Class
| Function Name | Description             | Input Arguments (if any)                                      | Output Arguments (if any) |
|---------------|-------------------------|---------------------------------------------------------------|---------------------------|
| MockFile();   | MockFile constructor    | N/A                                                           | N/A                       |
| read();       | Mock read function      | (Optionally) a const char array                               | True                      |
| close();      | Mock close function     | N/A                                                           | True                      |
| println();    | Mock println function   | String stringToPrint: the string you want printed to the file | True                      |
| available();  | Mock available function | N/A                                                           | True                      |

#### MockSdFat Class
| Function Name | Description                           | Input Arguments (if any)                                                                                                                                                                                                                                                                                                             | Output Arguments (if any) |
|---------------|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------|
| MockSdFat();  | Constructor for the MockSdFat class.  | N/A                                                                                                                                                                                                                                                                                                                                  | N/A                       |
| open();       | Mock open file function               | String file: the name of the file you want to open.  (optional): const uint_8 function: function represents one of the preset literal constants from the SdFat library. Since this function always returns true, this part only is important if you're creating a function that includes such a literal constant in its read() call. | True                      |
| begin();      | Mock begin function                   | int i: an integer. In the actual read function, corresponds to the pin you are using for SS with the SPI bus for the SD card.                                                                                                                                                                                                        | True                      |
| remove();     | Mock remove function                  | String file: the file you want to remove                                                                                                                                                                                                                                                                                                                                     | True                      |
| available();  | Mock available function               | N/A                                                                                                                                                                                                                                                                                                                                  | True                      |

#### MockSDBeacon Class
| Function Name              | Description                           | Input Arguments (if any)                                                                                                                                                                                                      | Output Arguments (if any)                          |
|----------------------------|---------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------|
| MockSDBeacon();               | Constructor for the MockSDBeacon class.  | N/A                                                                                                                                                                                                                           | N/A                                                |
| SDBeaconSetup();           | Mock setup function                   | MockSdFat& SD: a mock SdFat object to target                                                                                                                                                                                  | N/A                                                |
| searchDatabaseForTicket(); | Mock search function                  | String TicketString: The string you want to search for in the database. MockSdFat& SD: a mock SdFat object to target  MockFile& File: a mock File object to target                                                            | Returns True if the ticket if found, false if not. |
| writeToSD();               | Mock write function                   | String writeThisString: The string you want to write to the file.  String fileName: The name of the file you want to write to.   MockSdFat& SD: a mock SdFat object to target.  MockFile& File: a mock File object to target. | N/A                                                |
| simpleReadSD();            | Mock read function                    |  String fileName: The name of the file you want to read. MockSdFat& SD: a mock SdFatobject to target  MockFile& File: a mock File object to target                                                                            | N/A                                                |
| fileRemove();              | Mock remove function                  |  String fileName: the name of the file you want to remove. MockSdFat& SD: a mock SdFatobject to target  MockFile& File: a mock File object to target                                                                          | N/A                                                |
*Based heavily on the MockFile class, the MockSdFat class and on my SDBeacon function set.

#### MockOLED Class
| Function Name        | Description                          | Input Arguments (if any)                                                                                | Output Arguments (if any) |
|----------------------|--------------------------------------|---------------------------------------------------------------------------------------------------------|---------------------------|
| MockOLED();          | Constructor for the MockOLED class.  | N/A                                                                                                     | N/A                       |
| MockPrintToOLED();   | A mock print function                | String printThis: the string to print                                                                   | True                      |
| setColorIndexMock(); | A mock index setting function        | int type: The kind of color index to use, represented in the actual U8g library as a literal constant   | True                      |
| drawSetupMock();     | A mock drawSetup function            | MockOLED& obj: the OLED object you want to print to.                                                    | True                      |
| drawGeneralMock();   | A mock drawGeneral function          | String stringToPrint: The string you want printed. MockOLED& obj: the OLED object you want to print to. | True                      |

#### MockBLE Class
| Function Name         | Description                         | Input Arguments (if any)                                                                                        | Output Arguments (if any)                  |
|-----------------------|-------------------------------------|-----------------------------------------------------------------------------------------------------------------|--------------------------------------------|
| MockBLE();            | Constructor for the MockBLE class.  | N/A                                                                                                             | N/A                                        |
| TflyBLESetup();       | The mock BLE setup function         | N/A                                                                                                             | N/A                                        |
| clearParsingSetups(); | The mock BLE clear function         | String stringToClear: a string variable you want emptied. char charArrayToClear: A char array you want cleared. | N/A                                        |
| beaconSendData();     | The mock BLE send function          | N/A                                                                                                             | N/A                                        |
| readIncoming();       | The mock BLE read function          | N/A                                                                                                             | String of what was (mock) read off the BLE |

####Also includes MockTesting.ino, an example to demonstrate the virtual nature of the library
