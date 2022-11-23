# Approximate Second Derivative Algorithm

**Routine Name:** approxSecondDerivative

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from derivapprox import  approxSecondDerivative
```

**Description/Purpose:** This function approximates the second derivative of a function at a given point, using a given step size. This is done using a two sided approximation, where points to the right and left are used to appoximate the value. This means it should converge much faster than a one sided approximation as the step size decreases. 

**Input:**
### *f:* 
  * Data Type: Lambda (float) => float
  * Valid Input: Any python lambda which takes only one value, and returns one value
  * Description: The function to approximate the second derivative for

### *x0:* 
  * Data Type: float
  * Valid Input: [float.min, float.max] s.t. f''(x) is defined
  * Description: The location to calculate the second derivative at

### *h:* 
  * Data Type: float
  * Valid Input: (0, float.max]
  * Description: The step size to use for the approximation


**Output:** 
### *Second Derivative:*
  * Data Type: float
  * Possible Values: [float.min, float.max]
  * Description: The approximate value of the second derivative of f at x0

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testSecondDerivative():
    testFunction = lambda x: ((x - math.pi / 2) * math.tan(x) ** 2) / (x * x + 65)

    print("Testing Function:  ((x - PI / 2) * tan(x) ** 2) / (x * x + 65) at x0 = PI / 4")
    for i in range(7):
        h = 1 / (2 ** i)
        print(f"    With Step Size {h:.4f}: ", end='')
        print(f"{approxSecondDerivative(testFunction, math.pi / 4, h): .10f}")
    print("\n\n")
```

This code sets up a lambda, in this case a relatively complex geometric equation, for which to approximate the second of. It then calls our function with decreasing step sizes, so that the convergence of the result can be seen. 

Console Output:
```
Testing Function:  ((x - PI / 2) * tan(x) ** 2) / (x * x + 65) at x0 = PI / 4
    With Step Size 1.0000:  0.0888843331
    With Step Size 0.5000: -0.1099994234
    With Step Size 0.2500: -0.0747243947
    With Step Size 0.1250: -0.0693044446
    With Step Size 0.0625: -0.0680767520
    With Step Size 0.0312: -0.0677769924
    With Step Size 0.0156: -0.0677024890
```
As we can see, this funciton converges realtivley fast, with increases in step size massivley decreasing our error. 

**Implementation/Code:** The Following is the Code for approxSecondDerivative()
```
def approxSecondDerivative(f, x0, h):
    return (f(x0 + h) - 2 * f(x0) + f(x0 - h)) / (h * h)
```
**Last Modified:** November/2022