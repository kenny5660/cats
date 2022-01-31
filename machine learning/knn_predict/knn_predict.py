import numpy as np 
from collections import Counter

def knn_predict_simple(X, y, x, k):
    k = min(X.shape[0], k)
    knn = [y[i] for i in np.argsort(np.linalg.norm(X - x, axis=1))[:k]]
    return Counter(knn).items()
