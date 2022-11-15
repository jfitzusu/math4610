import numpy as np
def vectorAddition(v1, v2):
    assert len(v1) > 0
    assert len(v1) == len(v2)

    results = np.array(np.zeros(len(v1)))
    for i in range(len(v1)):
        results[i] = v1[i] + v2[i]

    return results
