"""
Function to Apply Linear Regression to a Set of Points
X: Array of X Values (Input)
Y: Array of Y Values (Output) (Must Match x in Size)
returns: a and b, the Approximate Coefficients of the Equation y = ax + b
"""


def linearFit(X, Y):
    assert len(X) == len(Y);
    n = len(X)

    # A Matrix After Transposition Step
    a11 = n
    a12 = sum(X)
    a21 = a12
    a22 = sum([xi * xi for xi in X])

    # B Matrix After Transposition Step
    b1 = sum(Y)
    b2 = sum([X[i] * Y[i] for i in range(n)])

    # Determinant of Modified A Matrix
    detA = a11 * a22 - a12 * a21

    # Results After Elimination Step
    b = (a22 * b1 - a12 * b2) / detA
    a = (-a21 * b1 + a11 * b2) / detA

    return a, b
