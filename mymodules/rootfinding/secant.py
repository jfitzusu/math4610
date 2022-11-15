import math

'''
Approximates the Root of a Function Using the Secant Method
f: The Function in Question, a Lambda
x0: Initial Guess
x1: Second Initial Guess
tol: Maximum Permissible Error
maxIter: Maximum Iterations to Test Before Giving Up
-v: Verbose Mode, Tracks/Returns Intermittent Results
Returns: The Approximate Root, Convergence Status, Intermittent Results if Toggled
'''
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