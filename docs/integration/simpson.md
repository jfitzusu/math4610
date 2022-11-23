# Simpson's Rule Algorithm

**Routine Name:** simpson

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from simpson import simpson
```

**Description/Purpose:** This function approximates the definite integral of a function using simpson's rule. Simpson's rule approximates an integral by fitting an imaginary curve to it, in practice, this is done by using weighted values for the start, end and midpoint evaluations. In this case, the composite version of the rule is used, meaning that only n + 1 function evaluations are actually needed, even though it converges realtive to h^4. This makes it an extremley efficient algorithm, that can also perfectly represent the integration of polynomials up through x^3.

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
    slope1, intercept1, _, _, _ = stats.linregress(hLog, eLog)
    print(f"    Equation For Error Using Scipy Linear Regression: E = {math.exp(intercept1):0.4f} * h ^ {slope1:.4f}")

print("Testing Simpson's Approximation")
print("-------------------------------")
f = lambda x: math.e ** (-(x * x))
fString = "e ^ (- x ^ 2)"
testSimpsons(f, fString, 0, math.pi / 4, 8)
```

In this code we set up a simple simple lamba function (e ^ (-x^2)) to test our funciton with. We then call it with decreasing step sizes, and keep track of the approximate error. We also print the results to the console. This allows us to come up with an equation that shows us just how fast our solution will converge, which we calculate using linear regression. 

Console Output:
```
Testing Simpson's Approximation
-------------------------------
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 4 Subintervals
        Result: 0.6499055993840337
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 8 Subintervals
        Result: 0.6498818839235538
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 16 Subintervals
        Result: 0.6498804267988076
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 32 Subintervals
        Result: 0.6498803361175071
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 64 Subintervals
        Result: 0.6498803304559893
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 128 Subintervals
        Result: 0.6498803301022391
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 256 Subintervals
        Result: 0.6498803300801318
    Testing Trapezoidal Approximation of f(x)=e ^ (- x ^ 2) from a=0 to b=0.7853981633974483 with 512 Subintervals
        Result: 0.6498803300787487
    Equation For Error Using Scipy Linear Regression: E = 0.0173 * h ^ 4.0107
```

As we can see, our result converges extremley fast, much faster than the trapezoidal rule, and for a very similar amount of work, making this an excellent function.  

**Implementation/Code:** The Following is the Code for simpson()
```
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
```
**Last Modified:** November/2022