import math

'''
Approximates an Integral Using the Composite Simpsons Rule
f: Function to Integrate
a: Start of Interval
b: End of Interval
n: Number of Subintervals to Approximate With
'''
def simpson(f, a, b, n=100):
    h = (b - a) / n
    sum2 = 0
    sum4 = 0
    x = a
    for i in range(math.floor(n // 2) - 1):
        x += h
        sum4 += f(x)
        x += h
        sum2 += f(x)

    sum4 += f(x + h)
    sum2 *= 2
    sum4 *= 4

    sol = (sum2 + sum4 + f(a) + f(b)) * (h / 3)
    return sol

