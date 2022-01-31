from collections import Counter
from math import log
import numpy as np


def entropy(y):
    freq = Counter(y).values()
    res = 0
    for f in freq:
        p = 1.0 * f / sum(freq)
        res -= p * log(p)
    return res


def var(y):
    return np.var(y)


def gini(y):
    freq = Counter(y).values()
    res = 0.0
    for f in freq:
        p = 1.0 * f / sum(freq)
        res += p * (1 - p)
    return res


def tree_split(X, y, criterion):
    functionSwitch = {
        'var': var,
        'gini': gini,
        'entropy': entropy
    }

    func = functionSwitch[criterion]
    split = (-1, -1)
    min = 1e9
    n = X.shape[0]
    for i in range(X.shape[1]):
        for j in range(X.shape[0]):
            leftBorder = y[X[:, i] <= X[j, i]]
            rightBorder = y[X[:, i] > X[j, i]]
            s = (leftBorder.shape[0] * 1.0 / n) * func(leftBorder) + \
                (rightBorder.shape[0] * 1.0 / n) * func(rightBorder)
            if s < min:
                min, split = s, (i, j)
    return split