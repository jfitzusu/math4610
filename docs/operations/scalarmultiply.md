# Vector and Scalar Multiplication Algorithm

**Routine Name:** scalarMultiply

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from scalarmultiply import scalarMultiply
```

**Description/Purpose:** This function will multiply a vector by a scalar. The result of this is a vector which points in the same direction, who's magnitude is now larger by a factor of the scalar. 

**Input:**
### *vector:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The vector to scale

### *scalar:*
  * Data Type: number
  * Valid Input: [number.min, number.max]
  * Description: The number to scale the vector by

**Output:** 
### *v:*
  * Data Type: number[]
  * Possible Values: [number.min, number.max]
  * Description: The vector results from scaling vectory by scalar

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testScalarMultiply():
    print("Testing Vector Scale")
    print("-----------------------")
    VECTOR_1 = [56, 12, 33, 0, 4, 2.32323, -12, 8]
    FACTOR = 2
    result = scalarMultiply(FACTOR, VECTOR_1)
    printableResult = [result[i] for i in range(len(result))]
    print(f"    Original Vector: {VECTOR_1}")
    print(f"    Vector After Scaling by {FACTOR}: {printableResult}")
    VECTOR_1 = [98, -2, 18]
    FACTOR = 5
    result = scalarMultiply(FACTOR, VECTOR_1)
    printableResult = [result[i] for i in range(len(result))]
    print(f"    Original Vector: {VECTOR_1}")
    print(f"    Vector After Scaling by {FACTOR}: {printableResult}")
    print("\n\n\n")
```

Console Output:
```
Testing Vector Scale
-----------------------
    Original Vector: [56, 12, 33, 0, 4, 2.32323, -12, 8]
    Vector After Scaling by 2: [112.0, 24.0, 66.0, 0.0, 8.0, 4.64646, -24.0, 16.0]
    Original Vector: [98, -2, 18]
    Vector After Scaling by 5: [490.0, -10.0, 90.0]
```
As you can see, each element of our original vectors have been multiplied by the value of the scalars. This means that the magnitude of our vectors has increased, but their directions remain unchanged.  

**Implementation/Code:** The Following is the Code for scalarMultiply()
```
import numpy as np
def scalarMultiply(scalar, vector):
    assert len(vector) > 0
    result = np.array(np.zeros(len(vector)))
    for i in range(len(vector)):
        result[i] = vector[i] * scalar
    return result
```
**Last Modified:** November/2022