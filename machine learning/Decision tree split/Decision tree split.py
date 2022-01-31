from collections import Counter
from math import log
import numpy as np

def var(y):
    return np.var(y)

def entropy(y): 
    class_freq = list(Counter(y).values())
    res = 0
    N = np.sum(class_freq)
    for f in class_freq:
        p = 1.0 * f / N
        res -= p * np.log(p)
    return res


def gini(y): 
    class_freq = list(Counter(y).values())
    res = 0.0
    N = np.sum(class_freq)
    for f in class_freq:
        p = 1.0 * f / N
        res += p * (1 - p)
    return res

def tree_split(X, y, criterion):
    functionCriterionMap = {
        'var': var,
        'gini': gini,
        'entropy': entropy
    }

    func = functionCriterionMap[criterion]
    split = (-1, -1)
    min = 1e10
    n = X.shape[0]
    for i in range(X.shape[1]):
        for j in range(X.shape[0]):
            leftBorder = y[X[:, i] <= X[j, i]]
            rightBorder = y[X[:, i] > X[j, i]]
            s = (leftBorder.shape[0] * 1.0 / n) * func(leftBorder) + (rightBorder.shape[0] * 1.0 / n) * func(rightBorder)
            if s < min:
                min  = s
                split = (i, j)
    return split