import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  
class Oracle:
    '''Provides an interface for evaluating a function and its derivative at arbitrary point'''
    
    def value(self, x: np.ndarray) -> float:
        return x[0]**2 + x[1]**2+ x[1]*2+1
        
    def gradient(self, x: np.ndarray) -> np.ndarray:
        return np.array([2*x[0],2*x[1]+2])




import numpy as np
class GDM:
    eta: float
    alpha: float
    def __init__(self, *, alpha: float = 0.9, eta: float = 0.1):
        self.alpha  = alpha
        self.eta = eta

    def optimize(self, oracle, x0: np.ndarray, *,
                 max_iter: int = 100, eps: float = 1e-5) -> np.ndarray:
        cur_x = x0
        cur_p = np.zeros(x0.shape)
        previous=x0
        for i in range(max_iter):
            grad = oracle.gradient(cur_x)
            cur_p = self.alpha* cur_p + self.eta*grad
            cur_x = previous - cur_p
            grad = oracle.gradient(cur_x)
            if np.linalg.norm(grad) < eps:
                break
            previous = cur_x 
        return cur_x

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
x = y = np.arange(-3.0, 3.0, 0.05)
X, Y = np.meshgrid(x, y)
oracle = Oracle()
zs = np.array(oracle.value((np.ravel(X),np.ravel(Y))))
Z = zs.reshape(X.shape)

ax.plot_surface(X, Y, Z)

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

gdm = GDM()
x_optimum = gdm.optimize(oracle,np.array([2,2]),max_iter=5000)
ax.scatter(x_optimum[0],x_optimum[1],oracle.value(x_optimum),c="red")

plt.show()