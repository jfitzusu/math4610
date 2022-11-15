import numpy as np
def scalarMultiply(scalar, vector):
    assert len(vector) > 0
    result = np.array(np.zeros(len(vector)))
    for i in range(len(vector)):
        result[i] = vector[i] * scalar
    return result