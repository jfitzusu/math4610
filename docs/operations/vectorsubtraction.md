# Vector Subtraction Algorithm

**Routine Name:** vectorSubtraction

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from vectorsubtraction import vectorSubtraction
```

**Description/Purpose:** This function is meant to subtract one vector from the other. Both vectors must be of the same size, and the result will be a vector also of the same size. In this case, the result will be calculated by pairwise subtracting the elements of the second vector from the first. 

**Input:**
### *v1:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The vector to subtract from

### *v2:*
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The vector to subtract

**Output:** 
### *v3:*
  * Data Type: number[]
  * Possible Values: [number.min, number.max]
  * Description: The vector that results in subtracting v2 from v1

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testVectorSubtraction():
    print("Testing Vector Subtraction:")
    print("---------------------------")
    VECTOR_1 = [56, 12, 33, 0, 4, 2.32323, -12, 8]
    VECTOR_2 = [0.001, 232, 1 / 12, 12, 32, 23, 23, 12]
    results = vectorSubtraction(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUB: {printableResults}")
    VECTOR_1 = [98, -2, 18]
    VECTOR_2 = [0, -2, 1 / 18]
    results = vectorSubtraction(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUB: {printableResults}")
    print("\n\n\n")
```

Console Output:
```
Testing Vector Subtraction:
---------------------------
    Vector 1: [56, 12, 33, 0, 4, 2.32323, -12, 8]
    Vector 2: [0.001, 232, 0.08333333333333333, 12, 32, 23, 23, 12]
    SUB: [55.999, -220.0, 32.916666666666664, -12.0, -28.0, -20.67677, -35.0, -4.0]
    Vector 1: [98, -2, 18]
    Vector 2: [0, -2, 0.05555555555555555]
    SUB: [98.0, 0.0, 17.944444444444443]
```
As you can see, this results in a pairwise subtracting each element of the second vector from the first. Any data elements that implement __sub__ between themselves should technically work, as there's no type validaiton, but it's not recomended to use non numerics. 

**Implementation/Code:** The Following is the Code for vectorSubtraction()
```
import numpy as np

def vectorSubtraction(v1, v2):
    assert len(v1) > 0
    assert len(v1) == len(v2)

    results = np.array(np.zeros(len(v1)))
    for i in range(len(v1)):
        results[i] = v1[i] - v2[i]

    return results
```
**Last Modified:** November/2022