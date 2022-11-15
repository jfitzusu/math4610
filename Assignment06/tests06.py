import math
import sys
sys.path.append('../mymodules/operations')
sys.path.append('../mymodules/approximation')

from vectoraddition import vectorAddition
from vectorsubtraction import vectorSubtraction
from scalarmultiply import scalarMultiply
from norm import norm1, norm2, normInf
from dotproduct import dotProduct
from crossproduct import crossProduct
from tripleproduct import tripleProduct
from action import action
from matrixaddition import matrixAddition
from matrixsubtraction import matrixSubtraction
from matrixmultiply import matrixMultiply

from approximatee import approximateE


def testVectorAddition():
    print("Testing Vector Addition:")
    print("------------------------")
    VECTOR_1 = [56, 12, 33, 0, 4, 2.32323, -12, 8]
    VECTOR_2 = [0.001, 232, 1 / 12, 12, 32, 23, 23, 12]
    results = vectorAddition(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUM: {printableResults}")
    VECTOR_1 = [98, -2, 18]
    VECTOR_2 = [0, -2, 1 / 18]
    results = vectorAddition(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUM: {printableResults}")
    print("\n\n\n")

def testVectorSubtraction():
    print("Testing Vector Subtraction:")
    print("---------------------------")
    VECTOR_1 = [56, 12, 33, 0, 4, 2.32323, -12, 8]
    VECTOR_2 = [0.001, 232, 1 / 12, 12, 32, 23, 23, 12]
    results = vectorSubtraction(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUB: {printableResults}")
    VECTOR_1 = [98, -2, 18]
    VECTOR_2 = [0, -2, 1 / 18]
    results = vectorSubtraction(VECTOR_1, VECTOR_2)
    printableResults = [results[i] for i in range(len(results))]
    print(f"    Vector 1: {VECTOR_1}\n    Vector 2: {VECTOR_2}\n    SUB: {printableResults}")
    print("\n\n\n")

def testVectorAddAndSub():
    print("Validating Vector Addition/Subtraction")
    print("--------------------------------------")
    VECTOR_1 = [56, 12, 33, 0, 4, 2.32323, -12, 8]
    VECTOR_2 = [0.001, 232, 1 / 12, 12, 32, 23, 23, 12]
    add = vectorAddition(VECTOR_1, VECTOR_2)
    sub = vectorSubtraction(add, VECTOR_2)
    printableSub = [sub[i] for i in range(len(sub))]
    print(f"    Original Vector: {VECTOR_1}")
    print(f"    Vector After Add/Sub: {printableSub}")
    equal = True
    for i in range(len(VECTOR_1)):
        error = abs(VECTOR_1[i] - printableSub[i])
        if error > 0.0001:
            equal = False
    print(f"    Equal? {'Yes' if equal else 'No'}")
    print("\n\n\n")

def testScalarMultiply():
    print("Testing Vector Scale")
    print("-----------------------")
    VECTOR_1 = [56, 12, 33, 0, 4, 2.32323, -12, 8]
    FACTOR = 2
    result = scalarMultiply(FACTOR, VECTOR_1)
    printableResult = [result[i] for i in range(len(result))]
    print(f"    Original Vector: {VECTOR_1}")
    print(f"    Vector After Scaling by {FACTOR}: {printableResult}")
    VECTOR_1 = [98, -2, 18]
    FACTOR = 5
    result = scalarMultiply(FACTOR, VECTOR_1)
    printableResult = [result[i] for i in range(len(result))]
    print(f"    Original Vector: {VECTOR_1}")
    print(f"    Vector After Scaling by {FACTOR}: {printableResult}")
    print("\n\n\n")

def testNorm():
    print("Testing Vector Norm:")
    print("--------------------")
    VECTOR = [5, 7, 12, -12, -15, 2]
    expectedL1 = 53
    expectedL2 = math.sqrt(591)
    expectedLInf = 15
    l1 = norm1(VECTOR)
    l2 = norm2(VECTOR)
    lInf = normInf(VECTOR)
    print(f"    Original Vector: {VECTOR}")
    print(f"    Calculated L1: {l1}")
    print(f"    Expected L1: {expectedL1}")
    print(f"    Calculated L2: {l2}")
    print(f"    Expected L2: {expectedL2}")
    print(f"    Calculated LInf: {lInf}")
    print(f"    Expected LInf: {expectedLInf}")
    print("\n\n\n")

def testDotProduct():
    print("Testing Dot Product:")
    print("--------------------")
    VECTOR_1 = [8, -8, 15, 12]
    VECTOR_2 = [0, 1, 2, 0.5]
    product = dotProduct(VECTOR_1, VECTOR_2)
    expectedDotProduct = 28
    print(f"    Vector 1: {VECTOR_1}")
    print(f"    Vector 2: {VECTOR_2}")
    print(f"    Dot Product: {product}")
    print(f"    Expected Dot Product: {expectedDotProduct}")
    print("\n\n\n")

def testCrossProduct():
    print("Testing Cross Product:")
    print("----------------------")
    v1 = [89, 23, -23]
    v2 = [123, 0, 18]
    cross = crossProduct(v1, v2)
    expectedCross = [414, -4431, -2829]
    print(f"    Vector 1: {v1}")
    print(f"    Vector 2: {v2}")
    print(f"    Cross Product: {cross}")
    print(f"    Expected Cross Product: {expectedCross}")
    print("\n\n\n")

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


def testAction():
    print("Testing Matrix Action on Vector:")
    print("--------------------------------")
    m = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    v = [0, 1, 2, 3]
    result = action(m, v)
    expectedResult = [14, 38, 62, 86]
    printableResult = [result[i] for i in range(len(result))]
    print(f"    Matrix: {m}")
    print(f"    Vector: {v}")
    print(f"    Action M on V: {printableResult}")
    print(f"    Expected Action: {expectedResult}")
    print("\n\n\n")

def testMatrixAdd():
    print("Testing Matrix Addition:")
    print("------------------------")
    m1 = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    m2 = [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    add = matrixAddition(m1, m2)
    printableAdd = [[add[i][j] for j in range(len(add[i]))] for i in range(len(add))]
    print(f"    Matrix 1: {m1}")
    print(f"    Matrix 2: {m2}")
    print(f"    Sum: {printableAdd}")
    print("\n\n\n")

def testMatrixSub():
    print("Testing Matrix Subtraction:")
    print("---------------------------")
    m1 = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    m2 = [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    add = matrixSubtraction(m1, m2)
    printableAdd = [[add[i][j] for j in range(len(add[i]))] for i in range(len(add))]
    print(f"    Matrix 1: {m1}")
    print(f"    Matrix 2: {m2}")
    print(f"    Sub: {printableAdd}")
    print("\n\n\n")

def testMatrixMultiply():
    print("Testing Matrix Multiply:")
    print("------------------------")
    m1 = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
    m2 = [[15, 14, 13, 12], [11, 10, 9, 8], [7, 6, 5, 4], [3, 2, 1, 0]]
    multiply = matrixMultiply(m1, m2)
    expectedMultiply = [[34, 28, 22, 16], [178, 156, 134, 112], [322, 284, 246, 208], [466, 412, 358, 304]]
    printableMultiply = [[multiply[i][j] for j in range(len(multiply[i]))] for i in range(len(multiply))]
    print(f"    Matrix 1: {m1}")
    print(f"    Matrix 2: {m2}")
    print(f"    Product: {printableMultiply}")
    print(f"    Expected Product: {expectedMultiply}")
    print("\n\n\n")

def testE():
    print("Testing E Approximations:")
    print("-------------------------")
    print(f"    Reference Value: {math.e}")
    i = 10
    while i <= 1000000:
        result = approximateE(i)
        print(f"    {i} Iterations: {result[0]} ({result[1]} Seconds)")
        i *= 10

if __name__ == "__main__":
    # testVectorAddition()
    # testVectorSubtraction()
    # testVectorAddAndSub()
    # testScalarMultiply()
    # testNorm()
    # testDotProduct()
    # testCrossProduct()
    # testTripleProduct()
    # testAction()
    # testMatrixAdd()
    # testMatrixSub()
    # testMatrixMultiply()
    testE()