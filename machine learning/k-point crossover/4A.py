import numpy as np
from typing import Tuple


def single_point_crossover(a, b, point):
    map = [i <= point for i in range(len(a))]
    return np.where(map, a, b), np.where(map, b, a)


def two_point_crossover(a, b, first, second):
    map = [(i <= first) | (i >= second) for i in range(len(a))]
    return np.where(map, a, b), np.where(map, b, a)


def k_point_crossover(a, b, points):
    points = [0, *points, a.shape[0]]
    seg = zip(points[::2], points[1::2])
    map = [False] * len(a)
    for el in seg:
        for i in range(el[0], el[1]+1):
            if (i < len(map)):
                map[i] = True
    return np.where(map, a, b), np.where(map, b, a)