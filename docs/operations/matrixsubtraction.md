# Matrix Subtraction Algorithm

**Routine Name:** matrixSubtraction()

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from matrixsubtraction import matrixSubtraction
```

**Description/Purpose:** This function will subtract one matrix from another. This is done by peicewise subtraction of the elements. This means that both matrices must be of the same size, and that the result will also be of the same size.

**Input:**
### *m1:* 
  * Data Type: number[][]
  * Valid Input: Any 2d subscriptable object composed of numbers
  * Description: The first matrix to subtract from

### *m2:* 
  * Data Type: number[][]
  * Valid Input: Any 2d subscriptable object composed of numbers
  * Description: The second matrix to subtract


**Output:** 
### *m3:*
  * Data Type: number[][]
  * Possible Values: [number.min, number.max]
  * Description: The result of subtracting m2 from m1

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testMatrixSub():
    print("Testing Matrix Subtraction:")
    print("---------------------------")
    m1 = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    m2 = [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    add = matrixSubtraction(m1, m2)
    printableAdd = [[add[i][j] for j in range(len(add[i]))] for i in range(len(add))]
    print(f"    Matrix 1: {m1}")
    print(f"    Matrix 2: {m2}")
    print(f"    Sub: {printableAdd}")
    print("\n\n\n")
```

Console Output:
```
Testing Matrix Subtraction:
---------------------------
    Matrix 1: [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    Matrix 2: [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    Sub: [[-15.0, -13.0, -11.0, -9.0], [-7.0, -5.0, -3.0, -1.0], [1.0, 3.0, 5.0, 7.0], [9.0, 11.0, 13.0, 15.0]]
```
Each compoment from the second matrix is subtracted from the same component in the first. As the elements of our first matrix are decreasing, and the second increasing, this leads to the observed pattern in the result, where subsequent elements are two greater than the last.

**Implementation/Code:** The Following is the Code for matrixSubtraction()
```
import numpy as np


def matrixSubtraction(m1, m2):
    assert len(m1) > 0
    assert len(m1[0]) > 0
    assert len(m1) == len(m2)
    assert len(m1[0]) == len(m2[0])

    result = np.array(np.zeros((len(m1), len(m1[0]))))
    for i in range(len(m1)):
        for j in range(len(m1[i])):
            result[i][j] = m1[i][j] - m2[i][j]

    return result

```
**Last Modified:** November/2022