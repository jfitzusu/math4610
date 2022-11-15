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
