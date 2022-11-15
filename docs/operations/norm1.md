# Vector Norm Algorihms

**Routine Name:** norm1

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from norm import norm1
```

**Description/Purpose:** This function calculates the L1 norm of a vector. This norm is calculated by summing the magnitude of each element. The result is a singular value.  

**Input:**
### *vector:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The vector to calculate the norm of

**Output:** 
### *L1:*
  * Data Type: number
  * Possible Values: [0, number.max]
  * Description: The L1 norm of the vector

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
As you can see, the L1 norm is much different than other norm evaluations. 

**Implementation/Code:** The Following is the Code for scalarMultiply()
```
def norm1(vector):
    assert len(vector) > 0
    l1 = 0
    for i in range(len(vector)):
        l1 += abs(vector[i])

    return l1
```
**Last Modified:** November/2022