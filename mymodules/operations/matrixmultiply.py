import numpy as np
from dotproduct import dotProduct
def matrixMultiply(m1, m2):
    assert len(m1) > 0
    assert len(m2) > 0
    assert len(m2[0]) > 0
    assert len(m1[0]) == len(m2)

    result = np.array(np.zeros((len(m1), len(m2[0]))))
    m1 = np.array(m1)
    m2 = np.array(m2)
    for i in range(len(m1)):
        for j in range(len(m2[0])):
            result[i][j] = dotProduct(m1[i], m2[:, j])

    return result
