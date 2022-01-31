from ctypes import pointer
import numpy as np

def sus(fitness: np.ndarray, n: int, start: float) -> list:
    step = fitness.sum() / n
    result = []    
    sum = 0
    index = -1
    for i in range(n):
        p = start + step * i
        while sum < p:
            index += 1
            sum += fitness[index]
        result.append(index)
    return result


fitness = np.array([10, 4, 3, 2, 1])
print(*fitness[sus(fitness, 3, 6)])