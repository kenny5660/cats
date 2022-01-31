from collections import Counter

def gini(y):
    freq = Counter(y).values()
    res = 0.0
    for f in freq:
        p = 1.0 * f / sum(freq)
        res += p * (1 - p)
    return res