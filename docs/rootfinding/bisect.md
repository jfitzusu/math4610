# Bisection Root Finding Algorithm

**Routine Name:** fixedPointIteration

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from bisect import bisect
```

**Description/Purpose:** This routine will approximate the root of a function using bisection. Given a range which is known to contain a root, it will systematically narrows down the range using function evaluations in order to approximate the root to within a specific accuracy. This means the function must be continous over the interval, in order to avoid any issues with breaks. This method is especially robust compared to other root finding methods, having some of the easiest to satisfy initial conditions, but it is usually fairly slow. 

**Input:**
### *f:* 
  * Data Type: Lambda
  * Valid Input: Any Lambda with a Single Input Variable
  * Description: The Function to Search for a Root in, Reperesented Using a Lambda

### *a:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. a < b
  * Description: The Left Bound of an Interval Containing a Root

### *b:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. b > a
  * Description: The Right Bound of an Interval Containing a Root


### *tol:*
  * Data Type: Float
  * Valid Input: (0, float.max]
  * Description: The Maximum Permissible Absolute Error (Estimated) for the Root Approximation.

### *v:*
  * Data Type: boolean
  * Valid Input: True/False
  * Default: False
  * Description: Verbose mode. If True, the function will print intermediate results to the console.

**Output:** 
### *Root:*
  * Data Type: Float?
  * Possible Values: [float.min, float.max]
  * Description: The Approximated Root of the Function, May or May Not be Accurate.

### *Console*
  * If the Verbose Flag is Toggled, the Function Will Print Intermediate Results to the Console for Debugging Purposes.


**Usage/Example:**

After Importing the Routine, You Can Call it In Your Code Like So:

```
f = lambda x: x ** 2 - 1
root = bisect(f, 0, 3, 0.0001, True)
print(root)
```

Console Output:
```
iteration: 0. xApprox: 1.5000E+00. error: 1.5000E+00
iteration: 1. xApprox: 7.5000E-01. error: 7.5000E-01
iteration: 2. xApprox: 1.1250E+00. error: 3.7500E-01
iteration: 3. xApprox: 9.3750E-01. error: 1.8750E-01
iteration: 4. xApprox: 1.0312E+00. error: 9.3750E-02
iteration: 5. xApprox: 9.8438E-01. error: 4.6875E-02
iteration: 6. xApprox: 1.0078E+00. error: 2.3438E-02
iteration: 7. xApprox: 9.9609E-01. error: 1.1719E-02
iteration: 8. xApprox: 1.0020E+00. error: 5.8594E-03
iteration: 9. xApprox: 9.9902E-01. error: 2.9297E-03
iteration: 10. xApprox: 1.0005E+00. error: 1.4648E-03
iteration: 11. xApprox: 9.9976E-01. error: 7.3242E-04
iteration: 12. xApprox: 1.0001E+00. error: 3.6621E-04
iteration: 13. xApprox: 9.9994E-01. error: 1.8311E-04
iteration: 14. xApprox: 1.0000E+00. error: 9.1553E-05
1.000030517578125
```
As we can see, our function kept iterating untill within the desired error, giving us a fairly accurate approximation of the root. 

**Implementation/Code:** The Following is the Code for bisect()
```
import math

def bisect(f, a, b, tol, v=False):
    if f(a) * f(b) >= 0:
        raise Exception("ERROR: f(a) and f(b) Must be On Opposite Sides of the x Axis")

    iterations = math.ceil(math.log2((b - a) / tol))
    fa = f(a)
    fb = f(b)
    c = (a + b) / 2

    for i in range(iterations):
        c = (a + b) / 2
        fc = f(c)

        if v:
            print(f"iteration: {i}. xApprox: {c:.4E}. error: {math.fabs(b - c):.4E}")

        if fa * fc < 0:
            fb = fc
            b = c
        elif fb * fc <0:
            fa = fc
            a = c
        elif fc == 0:
            break
        else:
            raise Exception("ERROR: f(a) and f(b) Must be On Opposite Sides of the x Axis")

    return c
```
**Last Modified:** November/2022