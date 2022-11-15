import math
'''
Approximates the Root of a Function Using Fixed Point Iteration
g: The Modified Fixed Point Version of the Function
x0: Initial Guess for the Root
tol: Maximum Permissible Error
maxIterations: Maximum Steps to Try Before Giving Up
v: Verbose Mode, Tracks/Returns Intermittent Results
Returns: Approximation of Root, True/False if Iteration Converged, Intermittent Results if Toggled
'''
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