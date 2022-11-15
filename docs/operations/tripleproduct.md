# Triple Product Algorithm

**Routine Name:** tripleProduct

**Author:** Jacob Fitzgerald

**Language:** Python. This function can be used by including the import statment in your Python header:
```
from tripleproduct import tripleproduct
```

**Description/Purpose:** This function calculates the scalar triple product of three vectors. The scalar triple product is defined as the dot product of one of the vectors and the cross product of the other two. Luckily, due to the properties of these operations, the order in which this is done does not matter. As this code uses the crossProduct routine, which accpets only three dimensional vectors, this code also only accepts three dimensional vectors. The result of the cross product means that our results get squashed into a singular value. 

**Input:**
### *v1:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The first vector to take the triple product of

### *v2:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The second vector to take the triple product of

### *v3:* 
  * Data Type: number[]
  * Valid Input: Any subscriptable object composed of numbers
  * Description: The third vector to take the triple product of


**Output:** 
### *product:*
  * Data Type: number
  * Possible Values: [number.min, number.max]
  * Description: The triple product of v1, v2, and v3

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
def testTripleProduct():
    print("Testing Triple Product:")
    print("-----------------------")
    v1 = [89, 23, -23]
    v2 = [123, 0, 18]
    v3 = [323, 1, 0]
    trip = tripleProduct(v1, v2, v3)
    expectedTrip = 129291
    print(f"    Vector 1: {v1}")
    print(f"    Vector 2: {v2}")
    print(f"    Vector 3: {v3}")
    print(f"    Triple Product: {trip}")
    print(f"    Expected Triple Product: {expectedTrip}")
    print("\n\n\n")
```

Console Output:
```
Testing Triple Product:
-----------------------
    Vector 1: [89, 23, -23]
    Vector 2: [123, 0, 18]
    Vector 3: [323, 1, 0]
    Triple Product: 129291
    Expected Triple Product: 129291
```
As we can see, the tripple product is very large. This is due to the large increase in magnitude from the cross product element, as well as the dot product element. 

**Implementation/Code:** The Following is the Code for tripleProduct()
```
from dotproduct import  dotProduct
from crossproduct import crossProduct
def tripleProduct(v1, v2, v3):
    assert len(v1) == 3
    assert len(v2) == 3
    assert len(v3) == 3

    return dotProduct(crossProduct(v1, v2), v3)
```
**Last Modified:** November/2022