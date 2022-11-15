from dotproduct import  dotProduct
from crossproduct import crossProduct
def tripleProduct(v1, v2, v3):
    assert len(v1) == 3
    assert len(v2) == 3
    assert len(v3) == 3

    return dotProduct(crossProduct(v1, v2), v3)
