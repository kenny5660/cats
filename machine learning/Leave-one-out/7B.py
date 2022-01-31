import numpy as np 

def loo_score(predict, X, y, k):
    ans = 0
    for i in range(X.shape[0]):
        ans += predict(np.delete(X, i, axis=0), np.delete(y, i, axis=0), X[i, :], k) == y[i]
    return ans