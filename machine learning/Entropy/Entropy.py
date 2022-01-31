from collections import Counter
from math import log
import numpy as np

def entropy(y): 
    class_freq = list(Counter(y).values())
    res = 0
    N = np.sum(class_freq)
    for f in class_freq:
        p = 1.0 * f / N
        res -= p * np.log(p)
    return res


entropy(np.array([1,1,1,1,1,1,2,2,2,3,3,4,4,4]))