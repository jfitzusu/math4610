# Matrix Multiplcation Algorithm

**Routine Name:** matrixmultiply()

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from matrixmultiply import matrixMultiply
```

**Description/Purpose:** This function will multiply two matrices together. This is done such that the i, j th element of the resulting matrix is the dot product of the ith row of the first matrix, and the jth column of the second. This means that the columns of the second matrix must match the rows in the first, and that the result will be a square matrix of this value. 

**Input:**
### *m1:* 
  * Data Type: number[][]
  * Valid Input: Any 2d subscriptable object composed of numbers
  * Description: The first matrix to multiply by

### *m2:* 
  * Data Type: number[][]
  * Valid Input: Any 2d subscriptable object composed of numbers
  * Description: The second matrix to multiply into


**Output:** 
### *m3:*
  * Data Type: number[][]
  * Possible Values: [number.min, number.max]
  * Description: The result of multiplying m1 and m2

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
import numpy as np
from dotproduct import dotProduct
def matrixMultiply(m1, m2):
    assert len(m1) > 0
    assert len(m2) > 0
    assert len(m2[0]) > 0
    assert len(m1) == len(m2[0])

    result = np.array(np.zeros((len(m1), len(m1))))
    m1 = np.array(m1)
    m2 = np.array(m2)
    for i in range(len(m1)):
        for j in range(len(m1)):
            result[i][j] = dotProduct(m1[i], m2[:, j])

    return result

```

Console Output:
```
Testing Matrix Multiply:
------------------------
    Matrix 1: [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    Matrix 2: [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    Product: [[34.0, 28.0, 22.0, 16.0], [178.0, 156.0, 134.0, 112.0], [322.0, 284.0, 246.0, 208.0], [466.0, 412.0, 358.0, 304.0]]
    Expected Product: [[34, 28, 22, 16], [178, 156, 134, 112], [322, 284, 246, 208], [466, 412, 358, 304]]
```
As we can see, the result of multiplying these two matrices is a square matrix, although, since our inputs were square as well, this is hardly a suprise.

**Implementation/Code:** The Following is the Code for matrixMultiply()
```
import numpy as np
from dotproduct import dotProduct
def matrixMultiply(m1, m2):
    assert len(m1) > 0
    assert len(m2) > 0
    assert len(m2[0]) > 0
    assert len(m1) == len(m2[0])

    result = np.array(np.zeros((len(m1), len(m1))))
    m1 = np.array(m1)
    m2 = np.array(m2)
    for i in range(len(m1)):
        for j in range(len(m1)):
            result[i][j] = dotProduct(m1[i], m2[:, j])

    return result

```
**Last Modified:** November/2022