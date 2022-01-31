import numpy as np


def sus(fitness, n, start):
    step = fitness.sum() / n
    keep = []
    pointers = [start + i*step for i in range(n)]
    sum = 0
    I = -1
    for P in pointers:
        while sum < P:
            I += 1
            sum += fitness[I]
        keep.append(I)
    return keep

fitness = np.array([10, 4, 3, 2, 1])
print(*fitness[sus(fitness, 3, 6)])