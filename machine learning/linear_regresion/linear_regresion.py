import numpy as np
def fit_linear_regression(X, y):
    XX=np.dot(X.T,X)
    Xm=np.linalg.inv(XX)
    X1=np.dot(Xm,X.T)
    result = np.dot(X1,y)
    return result

