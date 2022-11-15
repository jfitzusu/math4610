# Vector Norm Algorihms

**Routine Name:** normInf

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from norm import normInf
```

**Description/Purpose:** This function calculates the LInfinity norm of a vector. This norm is calcuated by taking the maginitude of the largest value in the vector

**Input:**
### *vector:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The vector to calculate the norm of

**Output:** 
### *LInf:*
  * Data Type: number
  * Possible Values: [0, number.max]
  * Description: The LInf norm of the vector

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
In this case, the Linfinity is 15, even though the only matching element in the vector is -15, which is the smallest value. This makes sense however, as we're taking the largest magnitude.

**Implementation/Code:** The Following is the Code for normInf()
```
def normInf(vector):
    assert len(vector) > 0
    lInf = 0
    for i in range(len(vector)):
        if abs(vector[i]) > lInf:
            lInf = abs(vector[i])

    return lInf
```
**Last Modified:** November/2022