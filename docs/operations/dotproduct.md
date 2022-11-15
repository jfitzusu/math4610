# Dot Product Algorithm

**Routine Name:** dotProduct

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from dotProduct import dotProduct
```

**Description/Purpose:** This function calculates the dot product of two vectors. This is done by peicewise multiplying elements of the vectors, and adding it to a cummulative sum. This means that both vectors must have the same size, and that our result will be squashed down to a single value. 

**Input:**
### *v1:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The first vector to take the dot product of

  ### *v2:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The second vector to take the dot product of

**Output:** 
### *dotProduct:*
  * Data Type: number
  * Possible Values: [number.min, number.max]
  * Description: The dot product of v1 and v2

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testDotProduct():
    print("Testing Dot Product:")
    print("--------------------")
    VECTOR_1 = [8, -8, 15, 12]
    VECTOR_2 = [0, 1, 2, 0.5]
    product = dotProduct(VECTOR_1, VECTOR_2)
    expectedDotProduct = 28
    print(f"    Vector 1: {VECTOR_1}")
    print(f"    Vector 2: {VECTOR_2}")
    print(f"    Dot Product: {product}")
    print(f"    Expected Dot Product: {expectedDotProduct}")
    print("\n\n\n")
```

Console Output:
```
Testing Dot Product:
--------------------
    Vector 1: [8, -8, 15, 12]
    Vector 2: [0, 1, 2, 0.5]
    Dot Product: 28.0
    Expected Dot Product: 28
```
As we can see, each elment in each vector contributes to the dot product.

**Implementation/Code:** The Following is the Code for dotProduct()
```
def dotProduct(v1, v2):
    assert len(v1) > 0
    assert len(v1) == len(v2)

    result = 0
    for i in range(len(v1)):
        result += v1[i] * v2[i]

    return result
```
**Last Modified:** November/2022