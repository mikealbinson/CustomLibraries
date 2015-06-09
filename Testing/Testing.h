/* Testing.h 
* written by Michael Albinson
*
*/


#ifndef _TESTING_H
#define _TESTING_H

#include "Arduino.h"

void success(String testName); //What to do if there is a successful test
void fail(String testName, int testType); //What to do if there is a failed test
const char* StringtoArray(String changeToCArray); 

void TestEqual (String testName, String one, String two); //Tests if two variables are equal
void TestEqual (String testName, const char* one, const char* two);
void TestEqual (String testName, String one, const char* two);
void TestEqual (String testName, int one, int two);
void TestEqual (String testName, char one, char two);
void TestEqual (String testName, byte one, byte two);
void TestEqual (String testName, bool one, bool two);

void TestNotEqual (String testName, String one, String two); //Tests to see if two things are not equal
void TestNotEqual (String testName, const char* one, const char* two);
void TestNotEqual (String testName, int one, int two);
void TestNotEqual (String testName, char one, char two);
void TestNotEqual (String testName, byte one, byte two);

void TestEmpty (String testName, int arg); //Tests to see if a variable is empty (i.e. = 0)
void TestEmpty (String testName, const char* arg);
void TestEmpty (String testName, String arg);
void TestEmpty (String testName, char arg);
void TestEmpty (String testName, byte arg);

void TestTrue (String testName, bool arg); //Tests to see if an arguement is true

#endif
