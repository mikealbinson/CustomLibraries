#TicketflyBLE
To use this library you will need to download and include:
1. the RBL_LibCLONE library
2. boards.h
3. SPI.h //no need to download this, it is in arduino's default library, just include it in your sketch

You will also need an RBL nRF8001 bluetooth low energy shield for arduino. 

##Function Descriptions
| Function Name     | Description                                                                                                                                                                                                                            | Input Arguments (if any)                                                     | Output Arguments (if any) | Other Important Info                                                                                                         |
|-------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------|---------------------------|------------------------------------------------------------------------------------------------------------------------------|
| BLE();            | Constructor for the BLE class.                                                                                                                                                                                                         | N/A                                                                          | N/A                       | As a constructor, must be called similarly to  "BLE objectName;" before the setup function. See example if you are confused. |
| TflyBLESetup();   |  Sets up the BLE for advertising. Use only in the setup loop or else the BLE will drop its connection to your device every time the loop function runs. Only works if you include beaconSendData(), readIncoming() or BLE_do_events(). | N/A                                                                          | N/A                       | N/A                                                                                                                          |
| beaconSendData(); | Tells the beacon to send the data inputted through the serial monitor or as indicated in the function call.                                                                                                                            | String, either through the serial monitor or indicated in the function call (as ticketToSend). | N/A                       | N/A                                                                                                                          |
| readIncoming();   | Reads incoming data to the BLE and outputs that information as a string.                                                                                                                                                               | N/A                                                                          | N/A                       | N/A                                                                                                                          |

===================================
####Notes:
1. This library is intended for use with the nRF8001 shield only. I have no idea if this will work with anything else and make no promises.
2. This library is brief and will continue to be expanded upon over time.
