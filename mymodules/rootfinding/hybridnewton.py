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
