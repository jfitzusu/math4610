# Hybrid Newton Root Finding Algorithm

**Routine Name:** hybridNewton

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from hybridnewton import hybridNewton
```

**Description/Purpose:** This routine will compute the root of a function given an initial starting value. The function will return the approximate root, and whether or not it managed to converge. This routine should not be used when the derivative of the function is computationally complex. This function combines both the newton method, and the bisection method for a more robust problem solving approach. This means that, instead of an initial guess, an interval containing a root must be provided. If the newton method fails, bisection will be used to reduce the interval and try again. This allows for much faster convergance than just using the bisection method, without the hastle of approximating guesses that comes with the newton method.    

**Input:**
### *f:* 
  * Data Type: Sympy Expression
  * Valid Input: Any Expression Whose Derivative Does Not Evaluate to Zero at x0, and Is Defined Only in Terms of Sympy.symbols('x')
  * Description: The Function to Search for a Root In, Represented Using Sympy's Symbolic Expressions. 

### *a:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. a < b
  * Description: The Left Bound of the Region Containing a Root
### *b*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. b > a
  * Description: The Right Bound of the Region Containing a Root

### *tol:*
  * Data Type: Float
  * Valid Input: (0, float.max]
  * Description: The Maximum Permissible Absolute Error (Estimated) for the Root Approximation.

### *maxIter:*
  * Data Type: int
  * Valid Input: [1, int.max]
  * Default: 1000
  * Description: The Maximum Number of Approximations to Compute with the Newton Method Before Assuming the Function Will Not Converge

### *maxTries:*
  * Data Type: int
  * Valid Input: [1, int.max]
  * Default: 10
  * Description: The Maximum Number of Times to Reduce the Interval with Bisection before Giving Up

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
def testHybridNewton():
    print("TESTING HYBRID NEWTON METHOD")
    print("----------------------------")
    x = sympy.symbols('x')
    expr = 10.14 * math.e ** (x * x) * sympy.cos(math.pi / x)
    sol = hybridNewton(expr, -3, 7, 0.001)
    print(f"The Approximate Root of 10.14 * e ^ (x ^ 2) * cos(PI/x) Within Range [-3, 7] is {sol[0]}")
    print(f"CONVERGED: {sol[1]}.")
    print()
```

Console Output:
```
TESTING HYBRID NEWTON METHOD
----------------------------
The Approximate Root of 10.14 * e ^ (x ^ 2) * cos(PI/x) Within Range [-3, 7] is 2.00000000664768
CONVERGED: True.
```

**Implementation/Code:** The Following is the Code for hybridNewton()
```
import sympy

'''
Approximates the Root of a Function Using the Newton Method, Falling Back to Bisection if It Doesn't Converge
f: The Function in Question. MUST BE A SYMPY EXPRESSION
a: Lower Boundary
b: Upper Boundary
tol: Maximum Permissible Error
maxIter: Maximum Iterations to Test Before Giving Up
maxTries: Maximum Times to Reduce the Problem With Bisection Before Giving Up
strictInterval: Boolean, Dictates Whether Convergence Must Happen Within the Interval

Returns: The Approximate Root, Convergence Status

NOTES: f'(b) Cannot Equal 0
NOTES: FUNCTION MUST BE A SYMPY EXPRESSION
'''


def hybridNewton(f, a, b, tol, maxiter=1000, maxTries=10, strictInterval=False):
    error = 10 * tol
    x = sympy.symbols('x')
    derF = sympy.diff(f, x)

    for i in range(maxTries):

        # Setup for Newton Method
        x0 = b
        x1 = 0
        for j in range(maxiter):
            derivative = derF.subs(x, x0)

            if derivative == 0:
                raise Exception("ERROR: Encountered Invalid Derivative {0}")

            x1 = x0 - f.subs(x, x0) / derivative

            error = abs(x1 - x0)

            if error <= tol:
                break

            x0 = x1

        # Returns Root if Convergence Happened
        if strictInterval:
            if error < tol and a < x1 < b:
                return x1, True
        elif error < tol:
            return x1, True

        # Reduces Interval With Bisection if Convergence Failed
        fa = f.subs(x, a)
        fb = f.subs(x, b)

        for j in range(4):
            c = 0.5 * (a + b)
            fc = f.subs(x, c)

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

        if abs(b - a) < tol:
            return b, True

    return b, False

```
**Last Modified:** November/2022