import numpy as np
from typing import Tuple


def single_point_crossover(a, b, point):
    is_cross = [i <= point for i in range(len(a))]
    return np.where(is_cross, a, b), np.where(is_cross, b, a)


def two_point_crossover(a, b, first, second):
    is_cross = [(i <= first) or (i >= second) for i in range(len(a))]
    return np.where(is_cross, a, b), np.where(is_cross, b, a)


def k_point_crossover(a, b, points):
    points = [0, *points, a.shape[0]]
    segs = list(zip(points[::2], points[1::2]))
    is_cross = [False for i in range(len(a))]
    for seg in segs:
        for i in range(seg[0], seg[1]+1):
            if (i < len(a)):
                is_cross[i] = True
    return np.where(is_cross, a, b), np.where(is_cross, b, a)


a = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
b = np.array([9, 8, 7, 6, 5, 4, 3, 2, 1, 0])
prep = lambda x: ' '.join(map(str, x))
print(*map(prep, single_point_crossover(a, b, 4)), '', sep='\n')
print(*map(prep, two_point_crossover(a, b, 2, 7)), '', sep='\n')
print(*map(prep, k_point_crossover(a, b, np.array([1, 5, 8]))), '', sep='\n')
            