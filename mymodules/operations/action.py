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
