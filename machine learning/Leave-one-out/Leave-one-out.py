import numpy as np 

def loo_score(predict, X, y, k):
    sum = 0
    for i in range(X.shape[0]):
        lern_X = np.delete(X, i, axis=0)
        lern_y = np.delete(y, i, axis=0)
        test_X = X[i, :]
        sum += predict(lern_X, lern_y, test_X, k) == y[i]
    return sum