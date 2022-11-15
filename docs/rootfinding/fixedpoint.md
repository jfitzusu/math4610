# Fixed Point Iteration Root Finding Algorithm

**Routine Name:** fixedPointIteration

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from fixedpoint import fixedPointIteration
```

**Description/Purpose:** This routine will approximate the root of a function using fixed point iteration. This means that, instead of the function you want to find a root for, it must be provided with the fixed point equation that you have constructed. It uses an initial guess in order to approximate the root, and will only be gaurenteed to converge when the derrivative of your fixed point equation is between -1 and 1 (non-inclusive) at the root.

**Input:**
### *g:* 
  * Data Type: Lambda
  * Valid Input: Any Lambda with a Single Input Variable
  * Description: The Fixed Point Iteration Equation Search for a Root With, Reperesented Using a Lambda

### *x0:*
  * Data Type: Float
  * Valid Input: [float.min, float.max]
  * Description: The initial Guess for the Root.

### *tol:*
  * Data Type: Float
  * Valid Input: (0, float.max]
  * Description: The Maximum Permissible Absolute Error (Estimated) for the Root Approximation.

### *maxIter:*
  * Data Type: int
  * Valid Input: [1, int.max]
  * Default: 1000
  * Description: The Maximum Number of Approximations to Compute Before Assuming the Function Will Not Converge

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

### *Converged:*
  * Data Type: Bool
  * Possible Values: True/False
  * Description: Whether or Not the Function Converged

### *Console*
  * If the Verbose Flag is Toggled, the Function Will Print Intermediate Results to the Console for Debugging Purposes.


**Usage/Example:**

After Importing the Routine, You Can Call it In Your Code Like So:

```
def problem1():
    # Original Function
    f = lambda x: x * math.e ** -x

    # Fixed Point Alterations
    g1 = lambda x: x - f(x)
    g2 = lambda x: x + f(x)

    roots1 = []
    roots2 = []


    # Tests Initial Points from -5 to 5 for the First Fixed Point Alteration
    print("Approximating the Roots of f(x) = x * e ** x Using g(x) = x - f(x):")
    print("-------------------------------------------------------------------")
    for i in range(-5, 6):
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g1, i, 0.00000001)
        if converges:
            print(f"        SUCCESS. Result: {approximation}")
            roots1.append(approximation)
        else:
            print(f"        FAILED. Result: {approximation}")

    print("Roots Found:")
    print("------------")
    for root in roots1:
        print(f"x={root}")
    print("\n\n\n\n")
```

Console Output:
```
Approximating the Roots of f(x) = x * e ** x Using g(x) = x - f(x):
-------------------------------------------------------------------
    Using Initial Guess x0 = -5
        SUCCESS. Result: 737.0657955128829
    Using Initial Guess x0 = -4
        SUCCESS. Result: 214.39260013257692
    Using Initial Guess x0 = -3
        SUCCESS. Result: 57.256610769563
    Using Initial Guess x0 = -2
        FAILED. Result: 12.774536617781685
    Using Initial Guess x0 = -1
        SUCCESS. Result: 2.465190328815662e-32
    Using Initial Guess x0 = 0
        SUCCESS. Result: 0.0
    Using Initial Guess x0 = 1
        SUCCESS. Result: 8.909872570538368e-19
    Using Initial Guess x0 = 2
        SUCCESS. Result: 9.860761315262648e-32
    Using Initial Guess x0 = 3
        SUCCESS. Result: 1.8755956882534777e-26
    Using Initial Guess x0 = 4
        SUCCESS. Result: 1.1768542528449143e-25
    Using Initial Guess x0 = 5
        SUCCESS. Result: 9.50419618610275e-27
Roots Found:
------------
x=737.0657955128829
x=214.39260013257692
x=57.256610769563
x=2.465190328815662e-32
x=0.0
x=8.909872570538368e-19
x=9.860761315262648e-32
x=1.8755956882534777e-26
x=1.1768542528449143e-25
x=9.50419618610275e-27
```
As we can see, the function can return multiple different roots when only one exists. This is due to the fact that we're mearly calculating an approximation, which means that any value sufficiently close to our root will also qualify as a root. Additionally, values that are very close to the x-axis, in this case very large values, will give a false alarm, as they are arbitrarily close to roots themselves. 

**Implementation/Code:** The Following is the Code for fixedPointIteration()
```
import math

def fixedPointIteration(g, x0, tol, maxIterations=100, v=False):
    x1 = x0
    error = 10 * tol

    try:
        for i in range(maxIterations):
            x1 = g(x0)
            error = math.fabs(x1 - x0)

            if v:
                print(f"iteration: {i}. xApprox: {x1:.4E}. error: {error:.4E}.")

            if error <= tol:
                break
            x0 = x1

    except(OverflowError):
        return math.inf, False

    return x1, error <= tol
```
**Last Modified:** November/2022