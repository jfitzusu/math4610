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

