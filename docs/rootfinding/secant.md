# Secant Root Finding Algorithm

**Routine Name:** secant

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from secant import secant
```

**Description/Purpose:** This routine will compute the root of a function given two initial starting values, using the secant approximation of the newton method. It will only work when the initial starting values are sufficiently close to the root. The function will return the approximate root, and whether or not it managed to converge. This routine should run faster than the newton routine when the derivative of the function is computationally complex. (Note: Honestly it will probably always run faster because the sympy expressions used for newton are extremley slow).

**Input:**
### *f:* 
  * Data Type: Lambda
  * Valid Input: Any Lambda with a Single Input Variable
  * Description: The Function to Search for a Root In, Represented Using Python's Built in Lambdas

### *x0:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. x0 d.n.e. x1
  * Description: The initial Guess for the Root. Must be Sufficiently Close to Guarantee Convergence.

### *x0:*
  * Data Type: Float
  * Valid Input: [float.min, float.max] s.t. x1 d.n.e. x0
  * Description: The initial Second Guess for the Root. Must be Sufficiently Close to Guarantee Convergence.   

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
  * Description: Verbose mode. If True, the function will return a log of all computed approximations and their error.

**Output:** 
### *Root:*
  * Data Type: Float?
  * Possible Values: [float.min, float.max]
  * Description: The Approximated Root of the Function, May or May Not be Accurate.

### *Converged:*
  * Data Type: Boolean
  * Possible Values: True/False
  * Description: Returns True if the Function Converged, False Otherwise. The Approximated Root is Only Accurate When True is Returned.

### *Log:*
  * Data Type: List[List[int, float, float]]
  * Possible Values: N/A
  * Description: Log of All Computed Approximations. Only Returns When Verbose Mode is Enabled. 

**Usage/Example:**

After Importing the Routine, You Can Call it In Your Code Like So:

```
f = lambda x: x * x - 1
root, converged = secant(f, 3, 3.1, 0.001)
print(root)
print(converged)
print(f(root))
```

Console Output:
```
2.0000000059950116
True
2.398004639303508e-08
```

**Implementation/Code:** The Following is the Code for secant()
```
def secant(f, x0, x1, tol, maxIter=1000, v=False):
    f0 = f(x0)
    f1 = f(x1)
    x2 = 0
    error = tol * 10
    resultsTable = []

    for i in range(maxIter):
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0)
        error = abs(x2 - x1)

        if v:
            resultsTable.append([i, x2, error])

        if error <= tol:
            break

        x0 = x1
        x1 = x2
        f0 = f1
        f1 = f(x1)

    if v:
        return x2, error <= tol, resultsTable

    return x2, error <= tol
```
**Last Modified:** September/2022