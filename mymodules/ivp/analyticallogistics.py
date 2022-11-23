import math

'''
Function Which Analytically the Logistics Equation
a: The Growth Constant
b: The Limiting Constant
p0: Initial Value of the System at t=0
P: Maximum Value to Approximate
n: Number of Steps to Approximate
Returns: Two Arrays, One of Input Values and One of Output Values for the Exact Logistics Equation
Notes: Uses Sympy Expressions, Which Slows Down Performance Quite a Bit
'''


def analyticalLogistics(a, b, p0, P, n=100):
    h = P / n
    c = p0 / (-b * p0 + a)

    inputs = [0]
    outputs = [p0]

    t = 0
    p = p0
    for i in range(n):
        t += h
        inputs.append(t)
        p = (a * c * math.e ** (a * t)) / (1 + b * c * math.e ** (a * t))
        outputs.append(p)

    return inputs, outputs
