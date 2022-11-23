# E Approximation Algorithm

**Routine Name:** approximateE

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from approximatee import approximateE
```

**Description/Purpose:** This function approximates the value of e using a given number of steps. This is done by using an IVP, in which we know the starting value of the function is 1, and the derivative is equal to the value. The explicit euler method is used, and, as such, the code must be performed in serial. Additionally, we integrate our approximation of the function using simpson's rule, to result in a value that should equal e. This last step doesn't actually seem to give us any accuracy improvments though. 

**Input:**
### *steps:* 
  * Data Type: intt
  * Valid Input: (0, int.max)
  * Description: The number of steps to use in the approximation


**Output:** 
### *e:*
  * Data Type: float
  * Possible Values: A small range around e
  * Description: The approximate value of e

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testE():
    print("Testing E Approximations:")
    print("-------------------------")
    print(f"    Reference Value: {math.e}")
    i = 10
    while i <= 1000000:
        result = approximateE(i)
        print(f"    {i} Iterations: {result[0]} ({result[1]} Seconds)")
        i *= 10
```

This code tests our function with a varying number of steps, and reports the results.  

Console Output:
```
Testing E Approximations:
-------------------------
    Reference Value: 2.718281828459045
    10 Iterations: 2.166527307 (0.0 Seconds)
    100 Iterations: 2.6564288754049237 (0.0 Seconds)
    1000 Iterations: 2.7120204975143265 (0.0 Seconds)
    10000 Iterations: 2.7176549245277357 (0.0009992122650146484 Seconds)
    100000 Iterations: 2.7182191303469354 (0.006003141403198242 Seconds)
    1000000 Iterations: 2.71827555857059 (0.05995655059814453 Seconds)
```
As we can see, the function converges relativley quickly, but not as fast as it should given that we use the simpson's method. This is because our error is bound by the much wonkier euler approximation. 

**Implementation/Code:** The Following is the Code for approximateE()
```
def approximateE(steps):
    start = time.time()
    assert steps % 2 == 0
    h = 1 / steps
    y = 1
    total4 = 0
    total2 = 0

    for i in range(1, steps // 2 - 1):
        y = y + h * y
        total4 += y
        y = y + h * y
        total2 += y
    y = y + h * y
    total4 += y
    y = y + h * y

    total4 *= 4
    total2 *= 2

    total = (total4 + total2 + y) * (h / 3)
    return total + 1, time.time() - start
```
**Last Modified:** November/2022