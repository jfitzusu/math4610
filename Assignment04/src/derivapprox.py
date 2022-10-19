"""
Function Which Uses the Limit Definition of the Derivative to Approximate the Value of the Second Derivative of a Function
f: Function to Approximate For
x0: Point to Approximate At
h: Initial Increment
Returns: Approximate Value of Second Derivative
"""
def approxSecondDerivative(f, x0, h):
    return (f(x0 + h) - 2 * f(x0) + f(x0 - h)) / (h * h)