import math

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
