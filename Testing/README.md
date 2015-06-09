#Testing

A quick testing library I threw together to test my "mocks" library pretty straightforward, so the function description section will not go over every input type. Just note that for the equal and notEqual tests, the variable types MUST MATCH because otherwise my tests will not work. The only exceptions are in the testEqual section, where you may compare a String with a c-string.

No additional libraries are necesary for this library (Yay!).

##Function Descriptions
| Function Name   | Description                                         | Input Arguments (if any)                                                                                            | Output Arguments (if any) | Other Important Info |
|-----------------|-----------------------------------------------------|---------------------------------------------------------------------------------------------------------------------|---------------------------|----------------------|
| TestEqual();    | Tests if two variables are equal.                   | String testName: the name of the test.  TYPE one, two: two variables of the same type                                | Serial output.            | N/A                  |
| TestNotEqual(); | Tests if two variables are not equal.               | String testName: the name of the test.  TYPE one, two: two variables of the same type                                | Serial output.            | N/A                  |
| TestEmpty();    | Tests if a variable is empty (i.e. = 0 or similar). | String testName: the name of the test.  TYPE arg: any variable that is within the definition of the tests           | Serial output.            | N/A                  |
| TestTrue();     | Tests if the argument is true.                      | String testName: the name of the test.   bool arg: a variable, object. or function that evaluates to true or false. | Serial output.            | N/A                     |

####Notes
1. Tests will be added over time
