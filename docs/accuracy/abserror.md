# Absolute Error Algorithm

**Routine Name:** absError

**Author:** Jacob Fitzgerald

**Language:** C. This function can be used by including the include statment in your C file:
```
#include "abserror.c"
```

Your code can then be compiled using gcc with library linking to produce an executable:
```
gcc -o my_exe my_code.c -lm
```
It can be used as part of a shared library for convience, but that goes beyond the scope of this document.

**Description/Purpose:** Given a value, u, and it's approximation, v, this function will calculate the absoulte error of the approximation. This is done by taking the absoulte value of the difference of the two inputs. 

**Input:**
### *u:* 
  * Data Type: double
  * Valid Input: [double.min, double.max]
  * Description: The true value

  ### *v:* 
  * Data Type: double
  * Valid Input: [double.min, double.max]
  * Description: The measured approximation

**Output:** 
### *absError:*
  * Data Type: double
  * Possible Values: [0, double.max]
  * Description: The absolute error of the approximation

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
printf("Absolute Error of %f to %f: %f \n", 10.1, 10.0, absError(10.0, 10.1)
```

This example cacluates the absolute error between the measured value, 10.1, and the actual value, 10.0. 

Console Output:
```
Absolute Error of 10.100000 to 10.000000: 0.100000
```

**Implementation/Code:** The Following is the Code for crossProduct()
```
double absError(double u, double v) {
        return fabs(v - u);
    }
```
**Last Modified:** November/2022