# Cross Product Algorithm

**Routine Name:** crossProduct

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from crossproduct import crossProduct
```

**Description/Purpose:** This function calculates the cross product of two vectors. The result is an entirley new vector, which should have a different direction and magnitude. This process is fairly complicated, so, in order to simplify it, our function only accepts three dimensional vectors. This means we can use a simplified base case, and ignore a bunch of messy matrix operations. 

**Input:**
### *v1:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The first vector to take the cross product of

  ### *v2:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The second vector to take the cross product of

**Output:** 
### *crossProduct:*
  * Data Type: number
  * Possible Values: [number.min, number.max]
  * Description: The cross product of v1 and v2

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testCrossProduct():
    print("Testing Cross Product:")
    print("----------------------")
    v1 = [89, 23, -23]
    v2 = [123, 0, 18]
    cross = crossProduct(v1, v2)
    expectedCross = [414, -4431, -2829]
    print(f"    Vector 1: {v1}")
    print(f"    Vector 2: {v2}")
    print(f"    Cross Product: {cross}")
    print(f"    Expected Cross Product: {expectedCross}")
    print("\n\n\n")
```

Console Output:
```
Testing Cross Product:
----------------------
    Vector 1: [89, 23, -23]
    Vector 2: [123, 0, 18]
    Cross Product: [414, -4431, -2829]
    Expected Cross Product: [414, -4431, -2829]
```
In this case, the resultant vector is much larger in magnitude than either of our starting vectors. 

**Implementation/Code:** The Following is the Code for crossProduct()
```
def crossProduct(v1, v2):
    assert len(v1) == 3
    assert len(v2) == 3

    return [v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]]

```
**Last Modified:** November/2022