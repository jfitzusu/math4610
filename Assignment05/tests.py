import math

from implicitlogistics import implicitLogistics
from analyticallogistics import analyticalLogistics
from expliciteulerlogistic import explicitEulerLogistic
from trapezoid import trapezoid
from simpson import simpson
import matplotlib.pyplot as plt
from scipy import stats

def testImplicitLogistics(a, b, p0, P):
    print(f"    Testing the Implicit Euler Method on the Logistics Equation With a={a} b={b} p0={p0}")
    x, y = implicitLogistics(a, b, p0, P, 1000)
    print(f"       End Value: {y[-1]:.10f}")
    plt.plot(x, y)
    plt.title(f"Logistics Curve Approximation for alpha={a} beta={b} p0={p0} (Implicit)")
    plt.xlabel("Time")
    plt.ylabel("Population")
    plt.show()

def testAnalyticLogistics(a, b, p0, P):
    print(f"    Testing the Analytical Method on the Logistics Equation With a={a} b={b} p0={p0}")
    x, y = analyticalLogistics(a, b, p0, P, 1000)
    print(f"       End Value: {y[-1]:.10f}")
    plt.plot(x, y)
    plt.title(f"Logistics Curve EXACT for alpha={a} beta={b} p0={p0}")
    plt.xlabel("Time")
    plt.ylabel("Population")
    plt.show()

def compareLogistics(a, b, p0, P):
    print(f"    Comparing Logistics Equation Methods With a={a} b={b} p0={p0}")
    x0, y0 = explicitEulerLogistic(a, b, p0, P, 1000)
    print(f"       End Value Explicit: {y0[-1]:.10f}")
    x1, y1 = implicitLogistics(a, b, p0, P, 1000)
    print(f"       End Value Implicit: {y1[-1]:.10f}")
    x2, y2 = analyticalLogistics(a, b, p0, P, 1000)
    print(f"       End Value Analytical: {y2[-1]:.10f}")

    plt.plot(x0, y0, color='r', label="Explicit Euler Method")
    plt.plot(x1, y1, color='g', label="Implicit Euler Method")
    plt.plot(x2, y2, color='b', label="Analytical Method")
    plt.title(f"Comparison of Logistics Equation Methods with alpha={a} beta={b} p0={p0}")
    plt.xlabel("Time")
    plt.ylabel("Population")
    plt.legend()
    plt.show()

def testTrapezoid(f, fString, a, b, n):
    print(f"    Testing Trapezoidal Approximation of f(x)={fString} from a={a} to b={b} with {n} Subintervals")
    res = trapezoid(f, a, b, n)
    print(f"        Result: {res}")

def testSimpsons(f, fString, a, b, n):
    steps = 4
    H = []
    E = []
    ref = simpson(f, a, b, 2 ** n * 4)
    for i in range(n):
        H.append((b - a) / steps)
        print(f"    Testing Trapezoidal Approximation of f(x)={fString} from a={a} to b={b} with {steps} Subintervals")
        res = simpson(f, a, b, steps)
        E.append(math.fabs(res - ref))
        print(f"        Result: {res}")
        steps *= 2


    hLog = [math.log(h) for h in H]
    eLog = [math.log(e) for e in E]
    plt.plot(hLog, eLog)
    plt.title(f"Convergence Study of f(x)={fString} Over Varying Step Sizes")
    plt.xlabel("Step Size (log)")
    plt.ylabel("Error (log)")
    plt.show()

    slope1, intercept1, _, _, _ = stats.linregress(hLog, eLog)
    print(f"    Equation For Error Using Scipy Linear Regression: E = {math.exp(intercept1):0.4f} * h ^ {slope1:.4f}")


if __name__ == "__main__":
    # print("Testing Implicit Euler Method")
    # print("-----------------------------")
    # testImplicitLogistics(0.2, 0.0005, 10.0, 100)
    # testImplicitLogistics(0.01, 0.0005, 10.0, 500)
    # testImplicitLogistics(2.0, 0.0005, 10.0, 10)

    # print("Testing Analytical Method")
    # print("-----------------------------")
    # testAnalyticLogistics(0.2, 0.0005, 10.0, 100)
    # testAnalyticLogistics(0.01, 0.0005, 10.0, 500)
    # testAnalyticLogistics(2.0, 0.0005, 10.0, 10)


    # print("Comparing Methods")
    # print("-----------------")
    # compareLogistics(0.2, 0.0005, 10.0, 100)
    # compareLogistics(0.01, 0.0005, 10.0, 500)
    # compareLogistics(2.0, 0.0005, 10.0, 10)


    # print("Testing Trapezoidal Approximation")
    # print("_________________________________")
    # f = lambda x: math.e ** (-(x * x))
    # fString = "e ^ (- x ^ 2)"
    # testTrapezoid(f, fString, 0, math.pi / 4, 2)
    # testTrapezoid(f, fString, 0, math.pi / 4, 4)
    # testTrapezoid(f, fString, 0, math.pi / 4, 8)
    # testTrapezoid(f, fString, 0, math.pi / 4, 16)


    print("Testing Simpson's Approximation")
    print("-------------------------------")
    f = lambda x: math.e ** (-(x * x))
    fString = "e ^ (- x ^ 2)"
    testSimpsons(f, fString, 0, math.pi / 4, 8)
