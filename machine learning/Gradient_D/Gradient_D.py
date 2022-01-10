import numpy as np
class GradientOptimizer:
    def __init__(self, oracle, x0):
        self.oracle = oracle
        self.x0 = x0

    def optimize(self, iterations, eps, alpha):
        previous=self.x0
        for i in range(iterations):
            grad = self.oracle.get_grad(np.array(previous))
            current = previous - np.dot(alpha,grad)
            if sum(abs(previous-current)) <= eps:
                return current
            previous = current
        return current