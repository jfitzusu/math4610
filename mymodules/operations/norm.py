import math


def norm1(vector):
    assert len(vector) > 0
    l1 = 0
    for i in range(len(vector)):
        l1 += abs(vector[i])

    return l1

def norm2(vector):
    assert len(vector) > 0
    l2 = 0
    for i in range(len(vector)):
        l2 += vector[i] * vector[i]
    l2 = math.sqrt(l2)

    return l2

def normInf(vector):
    assert len(vector) > 0
    lInf = 0
    for i in range(len(vector)):
        if abs(vector[i]) > lInf:
            lInf = abs(vector[i])

    return lInf