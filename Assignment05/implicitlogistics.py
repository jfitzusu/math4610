from newton import newton
import sympy

x = sympy.symbols('x')

'''
Function Which Implements the Implicit Euler Method to Approximate the Logistics Equation
a: The Growth Constant
b: The Limiting Constant
p0: Initial Value of the System at t=0
P: Maximum Value to Approximate
n: Number of Steps to Approximate
Returns: Two Arrays, One of Input Values and One of Output Values for the Approximated Logistics Equation
Notes: Uses Sympy Expressions, Which Slows Down Performance Quite a Bit
'''


def implicitLogistics(a, b, p0, P, n=100):
    h = P / n

    inputs = [0]
    outputs = [p0]

    t = 0
    p = p0
    for i in range(n):
        t += h
        inputs.append(t)
        implicitExpr = x - h * (a * x - b * x * x) - outputs[-1]
        p, converged = newton(implicitExpr, outputs[-1], 0.00001)
        outputs.append(p)

    return inputs, outputs
