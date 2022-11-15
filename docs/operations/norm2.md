# Vector Norm Algorihms

**Routine Name:** norm2

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from norm import norm2
```

**Description/Purpose:** This function calculates the L2 norm of a vector. This norm is calculated by summing the squares of each element, and then taking the square root. It is comenly refered to as the magnitude of the vector. 

**Input:**
### *vector:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The vector to calculate the norm of

**Output:** 
### *L2:*
  * Data Type: number
  * Possible Values: [0, number.max]
  * Description: The L2 norm of the vector

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testNorm():
    print("Testing Vector Norm:")
    print("--------------------")
    VECTOR = [5, 7, 12, -12, -15, 2]
    expectedL1 = 53
    expectedL2 = math.sqrt(591)
    expectedLInf = 15
    l1 = norm1(VECTOR)
    l2 = norm2(VECTOR)
    lInf = normInf(VECTOR)
    print(f"    Original Vector: {VECTOR}")
    print(f"    Calculated L1: {l1}")
    print(f"    Expected L1: {expectedL1}")
    print(f"    Calculated L2: {l2}")
    print(f"    Expected L2: {expectedL2}")
    print(f"    Calculated LInf: {lInf}")
    print(f"    Expected LInf: {expectedLInf}")
    print("\n\n\n")
```

Console Output:
```
Testing Vector Norm:
--------------------
    Original Vector: [5, 7, 12, -12, -15, 2]
    Calculated L1: 53
    Expected L1: 53
    Calculated L2: 24.310491562286437
    Expected L2: 24.310491562286437
    Calculated LInf: 15
    Expected LInf: 15
```
As you can see, the L2 norm is much less than the L1 norm. This is usually the case due to the squaring and square root taking nature of the evaluation.

**Implementation/Code:** The Following is the Code for norm2()
```
def norm2(vector):
    assert len(vector) > 0
    l2 = 0
    for i in range(len(vector)):
        l2 += vector[i] * vector[i]
    l2 = math.sqrt(l2)

    return l2
```
**Last Modified:** November/2022