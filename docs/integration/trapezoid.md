# Trapezoidal Rule Algorithm

**Routine Name:** trapezoid

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from trapezoid import trapezoid
```

**Description/Purpose:** This function approximates the definite integral of a function using the trapezoidal rule. The trapezoidal rule simply approximates an interval by using the start and end values to calculate the area of an imaginary trapezoid. In this case, the composite trapezoidal rule is used, meaning that only n + 1 function evaluations are actually needed, even though it converges realtive to h^2. This makes it an fairly efficient algorithm, that can also perfectly represent the integration of linear functions.

**Input:**
### *f:* 
  * Data Type: Lambda (float) => float
  * Valid Input: Any valid python lamba which takes and returns a single argument
  * Description: The function to approximate the definite integral of

### *a:* 
  * Data Type: float
  * Valid Input: [float.min, float.max] s.t. a < b
  * Description: The left hand side of the interval

### *b:* 
  * Data Type: float
  * Valid Input: [float.min, float.max] s.t. b > a
  * Description: The right hand side of the interval

### *n:* 
  * Data Type: int
  * Valid Input: (0, int.max]
  * Default Value: 100
  * Description: The number of subtinervals to use


**Output:** 
### *solution*
  * Data Type: float
  * Possible Values: [float.min, float.max]
  * Description: The approximate value of the integral of f from a to b

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testTrapezoid(f, fString, a, b, n):
    print(f"    Testing Trapezoidal Approximation of f(x)={fString} from a={a} to b={b} with {n} Subintervals")
    res = trapezoid(f, a, b, n)
    print(f"        Result: {res}")

print("Testing Trapezoidal Approximation")
print("_________________________________")
f = lambda x: math.e ** (-(x * x))
fString = "e ^ (- x ^ 2)"
testTrapezoid(f, fString, 0, math.pi / 4, 2)
testTrapezoid(f, fString, 0, math.pi / 4, 4)
testTrapezoid(f, fString, 0, math.pi / 4, 8)
testTrapezoid(f, fString, 0, math.pi / 4, 16)
```

This code calls our trapezoidal integration function on a simple function (e ^ -x^2) from 0 to pi/4 with an increasing number of subintervals.

Console Output:
```
Testing Trapezoidal Approximation
_________________________________
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 2 Subintervals
        Result: 0.6388862805734845
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 4 Subintervals
        Result: 0.6471507696813964
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 8 Subintervals
        Result: 0.6491991053630145
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 16 Subintervals
        Result: 0.6497100964398593
```

As we can see, our result converges relativley quickly. 

**Implementation/Code:** The Following is the Code for trapezoid()
```
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
```
**Last Modified:** November/2022