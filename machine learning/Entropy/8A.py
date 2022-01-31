from collections import Counter
from math import log

def entropy(y): 
    freq = Counter(y).values()
    res = 0
    for f in freq:
        p = 1.0 * f / sum(freq)
        res -= p * log(p)
    return res