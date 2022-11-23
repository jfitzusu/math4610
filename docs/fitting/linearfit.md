# Linear Data Fitting Algorithm

**Routine Name:** linearFit

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from linearfit import linearFit
```

**Description/Purpose:** This function performs a linear data fitting on a set of inputs and outputs. These inputs and outputs must be matched in a 1 to 1 fasion. This is accomplished by setting up the inputs and outputs as a system of equations using matrixes, and using the transpose of the input matrix to simplify and solve for the most accurate coefficients. 

**Input:**
### *X:* 
  * Data Type: float[]
  * Valid Input: [float.min, float.max][n] s.t. n=m
  * Description: An array of input values

### *Y:* 
  * Data Type: float[]
  * Valid Input: [float.min, float.max][m] s.t. m=n
  * Description: An array of output values


**Output:** 
### *a, b:*
  * Data Type: float, float
  * Possible Values: [float.min, float.max], [float,min, float.max]
  * Description: The coeffecients for the equation y = ax + b that lead to the minimal amount of error for our input and output values

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testLinearRegression():
    print("Approximating Linear fit For ((x - PI / 2) * tan(x) ** 2) / (x * x + 65) at x0 = PI / 4")
    testFunction = lambda x: ((x - math.pi / 2) * math.tan(x) ** 2) / (x * x + 65)

    X = [1 / (2 ** i) for i in range(9)]
    Y = [approxSecondDerivative(testFunction, math.pi / 4, xi) for xi in X]

    print("    Error Analysis")
    E = Y[:-1]
    for i in range(len(Y) - 1):
        E[i] = abs(Y[-1] - Y[i])
        print(f"        Error With Step Size {X[i]:.4f}: {E[i]:.10f}")

    logX = [math.log(x) for x in X[:-1]]
    logE = [math.log(e) for e in E]

    # SciPy's Built in Linear Regression Function
    slope1, intercept1, _, _, _ = stats.linregress(logX, logE)

    # My Linear Regression Function
    a, b = linearFit(logX, logE)

    print(f"    Equation Using Scipy Linear Regression: E = {math.exp(intercept1):0.4f} * h ^ {slope1:.4f}")
    print(f"    Equation Using My Linear Regression: E = {math.exp(b):0.4f} * h ^ {a:.4f}")
    print("\n\n")
```

This code sets up an initial lambda function to test our function with. It creates a set of step size values, then uses the second derivative approximation function discused in the derivative module to create a sequence of approximations. It then prints the error of the results, and takes the log of both the step size and the error values. It then performes linear regression on the results using both our function, and scipy's equivelant (for testing) to approximate the relationship between step size and error.  

Console Output:
```
Approximating Linear fit For ((x - PI / 2) * tan(x) ** 2) / (x * x + 65) at x0 = PI / 4
    Error Analysis
        Error With Step Size 1.0000: 0.1565635754
        Error With Step Size 0.5000: 0.0423201811
        Error With Step Size 0.2500: 0.0070451524
        Error With Step Size 0.1250: 0.0016252022
        Error With Step Size 0.0625: 0.0003975097
        Error With Step Size 0.0312: 0.0000977500
        Error With Step Size 0.0156: 0.0000232467
        Error With Step Size 0.0078: 0.0000046480
    Equation Using Scipy Linear Regression: E = 0.1568 * h ^ 2.1426
    Equation Using My Linear Regression: E = 0.1568 * h ^ 2.1426
```
In this case, we can see that our function produces essentially identical results to scipy's built in function, which means it most likely is accurate. We can also see that our deriviative approximation, discussed in the derivative module, converges fairly quickly. 

**Implementation/Code:** The Following is the Code for linearFit()
```
def linearFit(X, Y):
    assert len(X) == len(Y);
    n = len(X)

    # A Matrix After Transposition Step
    a11 = n
    a12 = sum(X)
    a21 = a12
    a22 = sum([xi * xi for xi in X])

    # B Matrix After Transposition Step
    b1 = sum(Y)
    b2 = sum([X[i] * Y[i] for i in range(n)])

    # Determinant of Modified A Matrix
    detA = a11 * a22 - a12 * a21

    # Results After Elimination Step
    b = (a22 * b1 - a12 * b2) / detA
    a = (-a21 * b1 + a11 * b2) / detA

    return a, b
```
**Last Modified:** November/2022