import math
import sys
sys.path.append('../../mymodules/derivation')
sys.path.append('../../mymodules/fitting')
sys.path.append('../../mymodules/ivp')

from derivapprox import approxSecondDerivative
from linearfit import linearFit
from scipy import stats
import matplotlib.pyplot as plt
from expliciteulerlogistic import explicitEulerLogistic


def testSecondDerivative():
    testFunction = lambda x: ((x - math.pi / 2) * math.tan(x) ** 2) / (x * x + 65)

    print("Testing Function:  ((x - PI / 2) * tan(x) ** 2) / (x * x + 65) at x0 = PI / 4")
    for i in range(7):
        h = 1 / (2 ** i)
        print(f"    With Step Size {h:.4f}: ", end='')
        print(f"{approxSecondDerivative(testFunction, math.pi / 4, h): .10f}")
    print("\n\n")


def testLinearRegression():
    print("Approximating Linear fit For ((x - PI / 2) * tan(x) ** 2) / (x * x + 65) at x0 = PI / 4")
    testFunction = lambda x: ((x - math.pi / 2) * math.tan(x) ** 2) / (x * x + 65)

    X = [1 / (2 ** i) for i in range(9)]
    Y = [approxSecondDerivative(testFunction, math.pi / 4, xi) for xi in X]

    print("    Error Analysis")
    E = Y[:-1]
    for i in range(len(Y) - 1):
        E[i] = abs(Y[-1] - Y[i])
        print(f"        Error With Step Size {X[i]:.4f}: {E[i]:.10f}")

    logX = [math.log(x) for x in X[:-1]]
    logE = [math.log(e) for e in E]

    # SciPy's Built in Linear Regression Function
    slope1, intercept1, _, _, _ = stats.linregress(logX, logE)

    # My Linear Regression Function
    a, b = linearFit(logX, logE)

    print(f"    Equation Using Scipy Linear Regression: E = {math.exp(intercept1):0.4f} * h ^ {slope1:.4f}")
    print(f"    Equation Using My Linear Regression: E = {math.exp(b):0.4f} * h ^ {a:.4f}")
    print("\n\n")

    # Graph of Error
    plt.plot(X[:-1], E)
    plt.title("Absolute Error vs StepSize")
    plt.xlabel("Step Size (h)")
    plt.ylabel("Approximate Absolute Error (E)")
    plt.yscale('log')
    plt.xscale('log')
    plt.show()

def testLogistic(a, b, p0, end):
    print(f"Approximating Logistics Equation alpha={a} beta={b} p0={p0}")
    x, y = explicitEulerLogistic(a, b, p0, end, 1000)
    print(f"   End Value: {y[-1]:.10f}")
    plt.plot(x, y)
    plt.title(f"Logistics Curve Approximation for alpha={a} beta={b} p0={p0}")
    plt.xlabel("Time")
    plt.ylabel("Population")
    plt.show()




if __name__ == "__main__":
    testSecondDerivative()
    testLinearRegression()
    testLogistic(0.2, 0.0005, 10.0, 60)
    testLogistic(0.01, 0.0005, 10.0, 600)
    testLogistic(2.0, 0.0005, 10.0, 8)
