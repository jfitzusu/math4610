import math
from rootfinding import fixedPointIteration, bisect

from sympy import *

def problem1():
    x = Symbol('x')

    f = x * math.e ** x

    g1 = x - f
    g2 = x + f

    print("Approximating the Roots of f(x) = x * e ** x Using g(x) = x - f(x):")

    for i in range(-5, 5):
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g1, i, 0.00000001)
        if converges:
            print(f"        Convergence SUCCESS. Result: {approximation}")
        else:
            print("        Convergence FAILED")

    print("Approximating the Roots of f(x) = x * e ** x Using g(x) = x + f(x):")

    for i in range(-5, 5):
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g2, i, 0.000000001)
        if converges:
            print(f"        Convergence SUCCESS. Result: {approximation}")
        else:
            print(f"        Convergence FAILED. Result: {approximation}")

if __name__ == "__main__":
    problem1()