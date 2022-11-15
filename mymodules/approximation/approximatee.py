import time

def approximateE(steps):
    start = time.time()
    assert steps % 2 == 0
    h = 1 / steps
    y = 1
    total4 = 0
    total2 = 0

    for i in range(1, steps // 2 - 1):
        y = y + h * y
        total4 += y
        y = y + h * y
        total2 += y
    y = y + h * y
    total4 += y
    y = y + h * y

    total4 *= 4
    total2 *= 2

    total = (total4 + total2 + y) * (h / 3)
    return total + 1, time.time() - start