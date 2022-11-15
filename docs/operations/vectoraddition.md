# Vector Addition Algorithm

**Routine Name:** vectorAddition

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from vectoraddition import vectorAddition
```

**Description/Purpose:** This function will compute the sum of two vectors. It does this by adding the elements pairwise. The vectors must be of the same size, and the result of this operation will be a new vector, also of the same size.  

**Input:**
### *v1:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The first vector to add

### *v2:*
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The second vector to add


**Output:** 
### *v3:*
  * Data Type: number[]
  * Possible Values: [number.min, number.max]
  * Description: The vector that results in adding v2 to v1

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testVectorAddition():
    print("Testing Vector Addition:")
    print("------------------------")
    VECTOR_1 = [56, 12, 33, 0, 4, 2.32323, -12, 8]
    VECTOR_2 = [0.001, 232, 1 / 12, 12, 32, 23, 23, 12]
    results = vectorAddition(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUM: {printableResults}")
    VECTOR_1 = [98, -2, 18]
    VECTOR_2 = [0, -2, 1 / 18]
    results = vectorAddition(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUM: {printableResults}")
    print("\n\n\n")
```

Console Output:
```
Testing Vector Addition:
------------------------
    Vector 1: [56, 12, 33, 0, 4, 2.32323, -12, 8]
    Vector 2: [0.001, 232, 0.08333333333333333, 12, 32, 23, 23, 12]
    SUM: [56.001, 244.0, 33.083333333333336, 12.0, 36.0, 25.32323, 11.0, 20.0]
    Vector 1: [98, -2, 18]
    Vector 2: [0, -2, 0.05555555555555555]
    SUM: [98.0, -4.0, 18.055555555555557]
```
As you can see, this results in a pairwise adding of each vector element. It should work for any Python numerical type. There's actually no real type validation, so as long as both elements have __add__ implemented between them, it should give a result, though maybe not the one you want. 

**Implementation/Code:** The Following is the Code for vectorAddition()
```
import numpy as np
def vectorAddition(v1, v2):
    assert len(v1) > 0
    assert len(v1) == len(v2)

    results = np.array(np.zeros(len(v1)))
    for i in range(len(v1)):
        results[i] = v1[i] + v2[i]

    return results

```
**Last Modified:** November/2022