import math
from rootfinding import fixedPointIteration, bisect

def problem1():
    # Original Function
    f = lambda x: x * math.e ** x

    # Fixed Point Alterations
    g1 = lambda x: x - f(x)
    g2 = lambda x: x + f(x)

    roots1 = []
    roots2 = []


    # Tests Initial Points from -5 to 5 for the First Fixed Point Alteration
    print("Approximating the Roots of f(x) = x * e ** x Using g(x) = x - f(x):")
    print("-------------------------------------------------------------------")
    for i in range(-5, 6):
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g1, i, 0.00000001)
        if converges:
            print(f"        SUCCESS. Result: {approximation}")
            roots1.append(approximation)
        else:
            print(f"        FAILED. Result: {approximation}")

    print("Roots Found:")
    print("------------")
    for root in roots1:
        print(f"x={root}")
    print("\n\n\n\n")


    # Tests Initial Points from -5 to 5 for the Second Fixed Point Alteration
    print("Approximating the Roots of f(x) = x * e ** x Using g(x) = x + f(x):")
    print("-------------------------------------------------------------------")

    for i in range(-5, 6):
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g2, i, 0.000000001)
        if converges:
            print(f"        SUCCESS. Result: {approximation}")
            roots2.append(approximation)
        else:
            print(f"        FAILED. Result: {approximation}")

    print("Roots Found:")
    print("------------")
    for root in roots2:
        print(f"x={root}")
    print("\n\n\n\n")


def problem3():
    # Original Function
    f = lambda x: 10.14 * math.e ** (x * x) * math.cos(math.pi / x)

    # Fixed Point Alteration
    g = lambda x: x - f(x)

    roots = []

    # Tests Initial Points from -3 to 7 for the Fixed Point Alteration
    print("Approximating the Roots of f(x) = 10.14 * e ** (x * x) * math.cos(pi / x) Using g(x) = x - f(x):")
    print("------------------------------------------------------------------------------------------------")
    for i in range(-3, 8):
        if i == 0:
            i += 0.000001
        print(f"    Using Initial Guess x0 = {i}")
        approximation, converges = fixedPointIteration(g, i, 0.00000001)
        if converges:
            print(f"        SUCCESS. Result: {approximation}")
            roots.append(approximation)
        else:
            print(f"        FAILED. Result: {approximation}")

    print("Roots Found:")
    print("------------")
    for root in roots:
        print(f"x={root}")
    print("\n\n\n\n")


if __name__ == "__main__":
    problem1()
    problem3()