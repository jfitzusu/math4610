import math
from rootfinding import fixedPointIteration, bisect

def problem1():
    f = lambda x: x * math.e ** x

    g1 = lambda x: x - f(x)
    g2 = lambda x: x + f(x)


    print("Approximating the Roots of f(x) = x * e ** x Using g(x) = x - f(x):")

    for i in range(-5, 6):
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g1, i, 0.00000001)
        if converges:
            print(f"        Convergence SUCCESS. Result: {approximation}")
        else:
            print("        Convergence FAILED")

    print("Approximating the Roots of f(x) = x * e ** x Using g(x) = x + f(x):")

    for i in range(-5, 6):
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g2, i, 0.000000001)
        if converges:
            print(f"        Convergence SUCCESS. Result: {approximation}")
        else:
            print(f"        Convergence FAILED. Result: {approximation}")


def problem3():
    f = lambda x: 10.14 * math.e ** (x * x) * math.cos(math.pi / x)

    g = lambda x: x - f(x)

    print("Approximating the Roots of f(x) = 10.14 * e ** (x * x) * math.cos(pi / x) Using g(x) = x - f(x):")
    for i in range(-3, 8):
        if i == 0:
            i += 0.000001
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g, i, 0.00000001)
        if converges:
            print(f"        Convergence SUCCESS. Result: {approximation}")
        else:
            print("        Convergence FAILED")


if __name__ == "__main__":
    problem1()
    problem3()