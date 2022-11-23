# Double Accuracy Algorithm

**Routine Name:**  accuracyDouble

**Author:** Jacob Fitzgerald

**Language:** C. This function can be used by including the include statment in your C file:
```
#include "accuracydouble.c"
```

Your code can then be compiled using gcc with library linking to produce an executable:
```
gcc -o my_exe my_code.c -lm
```
It can be used as part of a shared library for convience, but that goes beyond the scope of this document.

**Description/Purpose:** This code calculates the accuracy of a *double* datatype on the system it's run on. This is accomplished by adding increasingly smaller values to a constant, and testing for a difference. Once no differnece is detectable, the accuracy limit of a double has been reached.

**Input:**
### *maxLoops:* 
  * Data Type: int
  * Valid Input: [0, int.max]
  * Description: Loops to attempt before giving up

**Output:** 
### *accuracy:*
  * Data Type: int
  * Possible Values: [-1, double.max]
  * Description: The number of bits dedicated to the mantissa of a *double* data type. -1 indicates a failure on the algorithms part (likely due to a limiting maxLoop value)

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
printf("Accuracy of a Double: %i \n", accuracyDouble(500));
```

This example runs the function with an extrmley high maximum loop value, almost gaurenteeing we get an answer back. 

Console Output:
```
Accuracy of a Double: 53
```

In this case, our system uses the usual standard, with 53 bits used to represent a *double* datatypes mantissa.

**Implementation/Code:** The Following is the Code for crossProduct()
```
int accuracydouble(int maxLoops) {
        float one = 1.0f;
        float modifier = 1.0f;

        for (int i=0; i < maxLoops; i++) {
            if (one - (one + modifier) == 0) {
                return i;
            }
            modifier /= 2.0f;
        }

        return -1;
    }
```
**Last Modified:** November/2022