# Action of Matrix on Vector Algorithm

**Routine Name:** action

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from action import action
```

**Description/Purpose:** This function calculates the action of a matrix on a vector. This is done by taking the dot product of every row in the matrix with the vector. The result is a vector of the same size, but usually of different magintude and direction. 

**Input:**
### *m:* 
  * Data Type: number[][]
  * Valid Input: Any 2d subscriptable object composed of numbers
  * Description: The matrix to apply to the vector

### *v:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The vector to apply the matrix to


**Output:** 
### *action:*
  * Data Type: number[]
  * Possible Values: [number.min, number.max]
  * Description: The action of m on v

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testAction():
    print("Testing Matrix Action on Vector:")
    print("--------------------------------")
    m = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    v = [0, 1, 2, 3]
    result = action(m, v)
    expectedResult = [14, 38, 62, 86]
    printableResult = [result[i] for i in range(len(result))]
    print(f"    Matrix: {m}")
    print(f"    Vector: {v}")
    print(f"    Action M on V: {printableResult}")
    print(f"    Expected Action: {expectedResult}")
    print("\n\n\n")
```

Console Output:
```
Testing Matrix Action on Vector:
--------------------------------
    Matrix: [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    Vector: [0, 1, 2, 3]
    Action M on V: [14.0, 38.0, 62.0, 86.0]
    Expected Action: [14, 38, 62, 86]
```
As we can see, the resulting vector is of the same size, but wildly different direction and magnitude.

**Implementation/Code:** The Following is the Code for action()
```
import numpy as np
from dotproduct import dotProduct
def action(m, v):
    assert len(m) > 0
    assert len(v) > 0
    assert len(m[0]) == len(v)

    result = np.array(np.zeros(len(v)))
    for i in range(len(m)):
        result[i] = dotProduct(m[i], v)

    return result
```
**Last Modified:** November/2022