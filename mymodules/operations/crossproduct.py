from norm import norm2

def crossProduct(v1, v2):
    assert len(v1) == 3
    assert len(v2) == 3

    return [v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]]
