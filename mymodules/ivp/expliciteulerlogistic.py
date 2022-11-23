"""
Implements the Explicit Euler Method to Approximate Logistic Curves
a: Alpha, the Growth Constant
b: Beta, the Limiting Constant
p0: Initial Starting Value at t=0
P: The Maximum Value to Approximate
n: Number of Steps to Approximate
Returns: 2 Arrays of Points, One Representing Time Values, the Other Representing P Values
"""


def explicitEulerLogistic(a, b, p0, P, n=100):
    h = P / n
    deriv = lambda x: a * x - b * x * x

    inputs = [0]
    outputs = [p0]

    t = 0
    p = p0
    for i in range(n):
        t += h
        inputs.append(t)
        p = p + h * deriv(p)
        outputs.append(p)

    return inputs, outputs
