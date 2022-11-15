# Hybrid Secant Root Finding Algorithm

**Routine Name:** hybridSecant

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from hybridsecant import hybridSecant
```

**Description/Purpose:** This routine will compute the root of a function given an initial range. It starts by attempting to use the secant method to test for convergence. If the function fails to converge, it will reduce the interval using the bisection method. After this, it will try the secant method once again on the reduced interval, repeating this process untill a timeout value is reached, or the function converges. The function will return the approximate root, and whether or not it managed to converge. This routine should be used when you do not have a good initial guess for the root of the function.   

**Input:**
### *f:* 
  * Data Type: Lambda
  * Valid Input: Any Lambda with a Single Input Variable
  * Description: The Function to Search for a Root In, Represented Using Python's Built in Lambdas

### *a:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. a < b
  * Description: The Minimum Value of the Range to Search for a Root In.

### *b:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. b > a
  * Description: The Maximum Value of the Range to Search for a Root In. 

### *tol:*
  * Data Type: Float
  * Valid Input: (0, float.max]
  * Description: The Maximum Permissible Absolute Error (Estimated) for the Root Approximation.

### *maxIter:*
  * Data Type: int
  * Valid Input: [1, int.max]
  * Default: 1000
  * Description: The Maximum Number of Approximations to Compute Using the Secant Method Before Assuming the Function Will Not Converge

### *maxTries:*
  * Data Type: int
  * Valid Input: [1, int.max]
  * Default: 10
    * Description: The Number of Times to Reduce the Interval Before Assuming There is No Valid Root Within the Range

### *strictInterval:*
  * Data Type: Boolean
  * Valid Input: True/False
  * Default: False
  * Description: When set to True, prevents the routine from returning roots outside the given interval. If left at the default value, it's possible the routine may return a value outside of the given interval. 


**Output:** 
### *Root:*
  * Data Type: Float?
  * Possible Values: [float.min, float.max]
  * Description: The Approximated Root of the Function, May or May Not be Accurate.

### *Converged:*
  * Data Type: Boolean
  * Possible Values: True/False
  * Description: Returns True if the Function Converged, False Otherwise. The Approximated Root is Only Accurate When True is Returned.

**Usage/Example:**

After Importing the Routine, You Can Call it In Your Code Like So:

```
f = lambda x: x * x * x
root, converged = hybridSecant(f, -10, 10, 0.001)
print(root)
print(converged)
print(f(root))
```

Console Output:
```
0.0034733644940187674
True
4.190357548550342e-08
```

**Implementation/Code:** The Following is the Code for secant()
```
def hybridSecant(f, a, b, tol, maxiter=1000, maxTries=10, strictInterval=False):
    error = 10 * tol

    for i in range(maxTries):

        # Setup for Secant Method
        x0 = b
        x1 = 10 * tol + x0
        x2 = 0

        f0 = f(x0)
        f1 = f(x1)
        for j in range(maxiter):

            x2 = x1 - f1 * (x1 - x0) / (f1 - f0)

            error = abs(x2 - x1)

            if error <= tol:
                break

            x0 = x1
            x1 = x2
            f0 = f1
            f1 = f(x1)

        # Returns Result if Convergence Happened
        if strictInterval:
            if error < tol and a < x1 < b:
                return x1, True
        elif error < tol:
            return x1, True

        # Reduces Interval Using Bisection if Failed to Converge
        fa = f(a)
        fb = f(b)

        for j in range(4):
            c = 0.5 * (a + b)
            fc = f(c)

            if fa * fc < 0:
                fb = fc
                b = c
            elif fb * fc < 0:
                fa = fc
                a = c
            elif fc == 0:
                return c, True
            else:
                return c, False

        # Returns Result if Bisection Managed to Converge, Otherwise Loops Back to Secant Method
        if abs(b - a) < tol:
            return b, True

    return b, False
```
**Last Modified:** September/2022