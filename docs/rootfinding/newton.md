# Newton Root Finding Algorithm

**Routine Name:** newton

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from newton import newton
```

**Description/Purpose:** This routine will compute the root of a function given an initial starting value. It will only work when the initial starting value of is sufficiently close to the root, and the derivative of the function evaluated at the initial value is not 0. The function will return the approximate root, and whether or not it managed to converge. This routine should not be used when the derivative of the function is computationally complex.  

**Input:**
### *f:* 
  * Data Type: Sympy Expression
  * Valid Input: Any Expression Whose Derivative Does Not Evaluate to Zero at x0, and Is Defined Only in Terms of Sympy.symbols('x')
  * Description: The Function to Search for a Root In, Represented Using Sympy's Symbolic Expressions. 

### *x0:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. f'(x0) d.n.e 0
  * Description: The initial Guess for the Root. Must be Sufficiently Close to Guarantee Convergence. Should Not Represent an Area Where the Derivative of f Evaluates to 0.
  * Notes: Sufficiently Large Values of x Will Cause Sympy to Run Extremely Slow, Nothing I Can Do About This. 

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
  * Description: Verbose mode. If True, the function will log itermediate results to the console.

**Output:** 
### *Root:*
  * Data Type: Float?
  * Possible Values: [float.min, float.max]
  * Description: The Approximated Root of the Function, May or May Not be Accurate.

### *Converged:*
  * Data Type: Boolean
  * Possible Values: True/False
  * Description: Returns True if the Function Converged, False Otherwise. The Approximated Root is Only Accurate When True is Returned.

### *Console:*
  * If the verbose flag is toggled, intermediate results will be printed to the console for debugging purposes.

**Usage/Example:**

After Importing the Routine, You Can Call it In Your Code Like So:

```
x = sympy.symbols('x')
f = x * x - 1
root, converged = newton(f, 3, 0.001)
print(root)
print(converged)
print(f.subs(x, root))
```

Console Output:
```
4294967297/4294967295
True
9.313225746154785e-10
```
As we can see, our function fount a root at approximatley 1, and, when our original expression was evaluated at this point, it yeilds approximatley zero. The Results are not exact, because, as mentioned before, this is an approximation. 

**Implementation/Code:** The Following is the Code for newton()
```
import sympy

'''
Approximates the Root of a Function Using the Newton Method
f: The Function in Question. MUST BE A SYMPY EXPRESSION
x0: Initial Guess
tol: Maximum Permissible Error
maxIter: Maximum Iterations to Test Before Giving Up
-v: Verbose Mode, Tracks/Returns Intermittent Results
Returns: The Approximate Root, Convergence Status

NOTES: f'(x0) Cannot Equal 0
NOTES: FUNCTION MUST BE A SYMPY EXPRESSION
'''
def newton(f, x0, tol, maxIter=1000, v=False):
    x1 = 0
    x = sympy.symbols('x')
    derF = sympy.diff(f, x)
    error = 10 * tol
    for i in range(maxIter):
        derivative = derF.subs(x, x0)

        if derivative == 0:
            raise Exception("ERROR: Encountered Invalid Derivative {0}")

        x1 = x0 - f.subs(x, x0) / derivative
        error = abs(x1 - x0)
        if v:
            print(f'Iteration={i}. xApprox={x1}. Error={error}')

        if error <= tol:
            break

        x0 = x1

    return x1, error <= tol
```
**Last Modified:** November/2022