def dotProduct(v1, v2):
    assert len(v1) > 0
    assert len(v1) == len(v2)

    result = 0
    for i in range(len(v1)):
        result += v1[i] * v2[i]

    return result