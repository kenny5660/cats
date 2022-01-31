from collections import Counter
from math import log
import numpy as np

def gini(y): 
    class_freq = list(Counter(y).values())
    res = 0.0
    N = np.sum(class_freq)
    for f in class_freq:
        p = 1.0 * f / N
        res += p * (1 - p)
    return res

print(gini([3, 2, 4, 4, 2, 0, 1, 3, 0, 1]))