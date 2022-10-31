'''
Approximates an Integral Using the Composite Trapezoidal Rule
f: Function to Integrate
a: Start of Interval
b: End of Interval
n: Number of Subintervals to Approximate With
'''
def trapezoid(f, a, b, n=100):
    h = (b - a) / n

    sol = 0
    x = a
    for i in range(n - 1):
        x += h
        sol += f(x)

    sol += (f(a) + f(b)) / 2
    sol *= h
    return sol

