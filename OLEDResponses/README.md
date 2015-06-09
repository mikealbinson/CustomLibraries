# OLEDResponses Library
### A library heavily based on the U8g graphics library.


##In order to use, you must:
1. Have the U8gMod library included from this repository
2. Have a Adafruit SSD1306 or similar -- this may be changed if necesary, but the library is designed for this type of display

## Function Documentation 

| Function Name        | Description                                                                                                                      | Input Arguments (if any)                                                                                                                          | Output Arguments (if any) | Other Important Info                                                                  |
|----------------------|----------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------|---------------------------------------------------------------------------------------|
| OLED();              | Constructor for the OLED class. Establishes the mode, color index and type of display.                                           | N/A                                                                                                                                               | N/A                       | As a constructor, must be called similarly to  OLED object; before the setup function |
| drawSetup();         |  Prints the phrase "Setting up" to the display for three seconds                                                                 | N/A                                                                                                                                               | N/A                       | N/A                                                                                   |
| drawTicketflyLogo(); | Draws a bitmap image of the Ticketfly Logo to the screen for 10 seconds                                                          | N/A                                                                                                                                               | N/A                       | N/A                                                                                   |
| drawGeneral();       | Prints a string to the display for either three seconds, or an amount of time in seconds designated by the user in delayThisLine | stringToPrint: the string you want to print (suggested to be < 10 chars long)  delayThisLong: The amount of time in seconds to display the string | N/A                       | N/A                                                                                   |

##Customization
--------------------
I don't personally support any customization of display in this library, it could be done by copying the desired display from any of the U8gLib examples into the private section where the SSD1306 is designated and also into the OLED constructor, but like I said, this is designed for the SSD1306, so no promises on any customizations. 
