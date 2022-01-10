
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
class Adam:
    eta: float
    beta1: float
    beta2: float
    epsilon: float

    def __init__(self, *, eta: float = 0.1, beta1: float = 0.9, beta2: float = 0.999, epsilon: float = 1e-8):
        self.epsilon  = epsilon
        self.eta = eta
        self.beta1 = beta1
        self.beta2 = beta2

    def optimize(self, oracle, x0: np.ndarray, *,
                 max_iter: int = 100, eps: float = 1e-5) -> np.ndarray:
        cur_x = x0
        G = np.zeros(x0.shape)
        M = np.zeros(x0.shape)
        M_ = np.zeros(x0.shape)
        G_ = np.zeros(x0.shape)
        for i in range(max_iter):
            grad = oracle.gradient(cur_x)
            if np.linalg.norm(grad) < eps:
                break

            M = self.beta1*M +(1-self.beta1)*grad
            G = self.beta2*G +(1-self.beta2)*(grad**2)
            
            M_ = M/(1-self.beta1**(i+1))
            G_ = G/(1-self.beta2**(i+1))
            cur_x = cur_x - self.eta*M_/(np.sqrt(G_)+self.epsilon)
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

gdm = Adam()
x_optimum = gdm.optimize(oracle,np.array([2,2]),max_iter=5000)
ax.scatter(x_optimum[0],x_optimum[1],oracle.value(x_optimum),c="red")

plt.show()