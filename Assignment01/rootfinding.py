import math

'''
Approximates the Root of a Function Using the Bisection Method
f: The Function in Question
a: Start of the Interval Containing at Least One Root
b: End of the Interval Containing at Least One Root
tol: Maximum Permissible Error
-v: Verbose Mode, Tracks/Returns Intermittent Results
Returns: The Approximate Root, Intermittent Results if Toggled
NOTES: f(a) and f(b) Must be On Opposite Sides of the x Axis
'''
def bisect(f, a, b, tol, v=False):
    if f(a) * f(b) >= 0:
        raise Exception("ERROR: f(a) and f(b) Must be On Opposite Sides of the x Axis")

    iterations = math.ceil(math.log2((b - a) / tol))
    fa = f(a)
    fb = f(b)
    if v:
        resultsTable = []

    for i in range(iterations):
        c = (a + b) / 2
        fc = f(c)

        if v:
            resultsTable.append([i + 1, c, math.fabs(b - c)])

        if fa * fc < 0:
            fb = fc
            b = c
        elif fb * fc <0 :
            fa = fc
            a = c
        elif fc == 0:
            break
        else:
            raise Exception("ERROR: f(a) and f(b) Must be On Opposite Sides of the x Axis")

    if v:
        return c, resultsTable

    return c


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
    if v:
        resultsTable = []

    try:
        for i in range(maxIterations):
            x1 = g(x0)
            error = math.fabs(x1 - x0)
            if v:
                resultsTable.append([i, x1, error])

            if error <= tol:
                break
            x0 = x1

    except(OverflowError):
        return math.inf, False

    if v:
        return x1,  error <= tol, resultsTable

    return x1, error <= tol
