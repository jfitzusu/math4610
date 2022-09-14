import math

import sympy

'''
Sympy Expressions are Used to Represent and Evaluate Functions
'''

'''
Approximates the Root of a Function Using the Bisection Method
f: A Sympy Expression Representing a Function
a: Start of the Interval Containing at Least One Root
b: End of the Interval Containing at Least One Root
tol: Maximum Permissable Error
NOTES: f(a) and f(b) Must be On Opposite Sides of the x Axis
'''


def bisect(f, a, b, tol):
    if f.subs(a) * f.subs(b) >= 0:
        raise Exception("ERROR: f(a) and f(b) Must be On Opposite Sides of the x Axis")

    iterations = math.ceil(math.log2((b - a) / tol))
    fa = f.subs(a)
    fb = f.subs(b)

    for i in range(iterations):
        c = a + b / 2
        fc = f.subs(c)

        if fa * fc < 0:
            fb = fc
            b = c
        elif fb * fc < 0:
            fa = fc
            a = b
        elif fc == 0:
            break
        else:
            raise Exception("ERROR: f(a) and f(b) Must be On Opposite Sides of the x Axis")

        return c

def fixedPointIteration(f, x0, tol, maxIterations=100):
    