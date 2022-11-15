# Matrix Addition Algorithm

**Routine Name:** matrixAddition()

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from matrixaddition import matrixAddition
```

**Description/Purpose:** This function will add two matrices together. This is accomplished via pairwise addition of their compenents. This requires the two matrices be of the same size, and results in a matrix of the same size as well. 

**Input:**
### *m1:* 
  * Data Type: number[][]
  * Valid Input: Any 2d subscriptable object composed of numbers
  * Description: The first matrix to add

### *m2:* 
  * Data Type: number[][]
  * Valid Input: Any 2d subscriptable object composed of numbers
  * Description: The second matrix to add


**Output:** 
### *m3:*
  * Data Type: number[][]
  * Possible Values: [number.min, number.max]
  * Description: The result of adding m1 to m2

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testMatrixAdd():
    print("Testing Matrix Addition:")
    print("------------------------")
    m1 = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    m2 = [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    add = matrixAddition(m1, m2)
    printableAdd = [[add[i][j] for j in range(len(add[i]))] for i in range(len(add))]
    print(f"    Matrix 1: {m1}")
    print(f"    Matrix 2: {m2}")
    print(f"    Sum: {printableAdd}")
    print("\n\n\n")
```

Console Output:
```
Testing Matrix Addition:
------------------------
    Matrix 1: [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    Matrix 2: [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    Sum: [[15.0, 15.0, 15.0, 15.0], [15.0, 15.0, 15.0, 15.0], [15.0, 15.0, 15.0, 15.0], [15.0, 15.0, 15.0, 15.0]]
```
In this case, we made it so each matching component of our matrices would sum to the same value. This serves to illustrate how the values are added together.

**Implementation/Code:** The Following is the Code for matrixAddition()
```
import numpy as np


def matrixAddition(m1, m2):
    assert len(m1) > 0
    assert len(m1[0]) > 0
    assert len(m1) == len(m2)
    assert len(m1[0]) == len(m2[0])

    result = np.array(np.zeros((len(m1), len(m1[0]))))
    for i in range(len(m1)):
        for j in range(len(m1[i])):
            result[i][j] = m1[i][j] + m2[i][j]

    return result

```
**Last Modified:** November/2022