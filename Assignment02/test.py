import sympy
import math
from newton import newton
from secant import secant
from hybridnewton import hybridNewton
from hybridsecant import hybridSecant

def testNewton():
    print("TESTING NEWTON METHOD")
    print("---------------------")
    x = sympy.symbols('x')
    expr = x * math.e ** -x

    for i in range(-3, 4):
        sol = newton(expr, i + 0.2, 0.001)
        print(f"The Approximate Root of x * e ^ -x Using {i + 0.2} as an Initial Guess is {sol[0]}")
        print(f"CONVERGED: {sol[1]}.")
    print()

def testSecant():
    print("TESTING SECANT METHOD")
    print("---------------------")
    f = lambda x: x * math.e ** -x

    for i in range(-3, 4):
        sol = secant(f, i - 0.2, i, 0.001)
        print(f"The Approximate Root of x * e ^ - x Using {i - 0.2} and {i} as Initial Values is {sol[0]}")
        print(f"CONVERGED: {sol[1]}")
    print()


def testHybridNewton():
    print("TESTING HYBRID NEWTON METHOD")
    print("----------------------------")
    x = sympy.symbols('x')
    expr = 10.14 * math.e ** (x * x) * sympy.cos(math.pi / x)
    sol = hybridNewton(expr, -3, 7, 0.001)
    print(f"The Approximate Root of 10.14 * e ^ (x ^ 2) * cos(PI/x) Within Range [-3, 7] is {sol[0]}")
    print(f"CONVERGED: {sol[1]}.")
    print()

def allRootsHybridNewton(strict):
    print("TESTING ALL ROOTS FOR THE HYBRID NEWTON METHOD")
    print("----------------------------------------------")
    x = sympy.symbols('x')
    expr = 10.14 * math.e ** (x * x) * sympy.cos(math.pi / x)
    intervals = [(-3, -1), (-1, -0.5), (-0.5, -0.3), (-0.3, 0.2), (0.2, 0.25), (0.25, 0.35), (0.35, 0.5), (0.5, 0.7), (0.7, 7)]
    for interval in intervals:
        sol = hybridNewton(expr, interval[0], interval[1], 0.001, strictInterval=strict)
        print(f"The Approximate Root of 10.14 * e ^ (x ^ 2) * cos(PI/x) Within Range [{interval[0]}, {interval[1]}] is {sol[0]}")
        print(f"CONVERGED: {sol[1]}.")
    print()

def testHybridSecant():
    print("TESTING HYBRID SECANT METHOD")
    print("----------------------------")
    expr = lambda x: 10.14 * math.e ** (x * x) * math.cos(math.pi / x)
    sol = hybridSecant(expr, -3, 7, 0.001)
    print(f"The Approximate Root of 10.14 * e ^ (x ^ 2) * cos(PI/x) Within Range [-3, 7] is {sol[0]}")
    print(f"CONVERGED: {sol[1]}.")
    print()

def allRootsHybridSecant(strict):
    print("TESTING ALL ROOTS FOR HYBRID SECANT METHOD")
    print("------------------------------------------")
    expr = lambda x: 10.14 * math.e ** (x * x) * math.cos(math.pi / x)
    intervals = [(-3, -1), (-1, -0.5), (-0.5, -0.3), (-0.3, 0.2), (0.2, 0.25), (0.25, 0.35), (0.35, 0.5), (0.5, 0.7), (0.7, 7)]
    for interval in intervals:
        sol = hybridSecant(expr, interval[0], interval[1], 0.001, strictInterval=strict)
        print(f"The Approximate Root of 10.14 * e ^ (x ^ 2) * cos(PI/x) Within Range [{interval[0]}, {interval[1]}] is {sol[0]}")
        print(f"CONVERGED: {sol[1]}.")
    print()


if __name__ == "__main__":
    testNewton()
    testSecant()
    testHybridNewton()
    allRootsHybridNewton(False)
    allRootsHybridNewton(True)
    testHybridSecant()
    allRootsHybridNewton(True)
    allRootsHybridSecant(True)