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

*Based heavily on the MockFile class and on my SDBeacon function set.

#### MockSDBeacon Class

#### MockOLED Class

#### MockBLE Class
