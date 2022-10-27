import math

'''
Approximates the Root of a Function Using the Bisection Method
f: The Function in Question
a: Start of the Interval Containing at Least One Root
b: End of the Interval Containing at Least One Root
tol: Maximum Permissible Error
-v: Verbose Mode, Prints Debug Info
Returns: The Approximate Root
NOTES: f(a) and f(b) Must be On Opposite Sides of the x Axis
'''
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


'''
Approximates the Root of a Function Using the Secant Method, Falling Back to Bisection if It Doesn't Converge
f: The Function in Question, a Lambda
a: Lower Boundary
b: Upper Boundary
tol: Maximum Permissible Error
maxIter: Maximum Iterations to Test Before Giving Up
maxTries: Maximum Times to Reduce the Problem With Bisection Before Giving Up
strictInterval: Boolean, Dictates Whether Convergence Must Happen Within the Interval

Returns: The Approximate Root, Convergence Status
'''


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
