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