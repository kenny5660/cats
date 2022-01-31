import tqdm
import random
import numpy as np


def mix(a, b, mutation_chance=0.1):
    c = np.where(np.random.randint(0, 2, a.shape[0]), a, b)
    if np.random.randint(2):
        return np.where(np.random.random(a.shape[0]) < mutation_chance, np.random.randint(1, 11, a.shape[0]), c)
    return c


def gen_alg(gen, m=1000):
    k = gen.shape[0]
    n = gen.shape[0] * 20
    best = np.zeros(genl.shape[1])
    pbar = tqdm.trange(m)

    time = np.zeros(n)
    buff = np.zeros(10)
    for _ in pbar:
        mixed = np.array(list(map(lambda x: mix(gen[x[0]], gen[x[1]]),
                                  zip(np.random.randint(0, gen.shape[0], n - gen.shape[0]),
                                      np.random.randint(0, gen.shape[0], n - gen.shape[0])))))
        gen = np.concatenate((gen, mixed), axis=0)

        time[:] = 0
        for i in range(len(gen)):
            buff[:] = 0
            for j in range(len(gen[i])):
                buff[gen[i][j] - 1] += coeff[gen[i][j] - 1][complexity[j] - 1] * timet[j]
            time[i] = buff.max()

        ind = np.argsort(time)
        best = gen[ind[0]]
        gen = gen[ind[:k]]
        score = 1e6 / time[ind[0]]
        pbar.set_description(str(score))

    return best


with open('input.txt', 'r') as fin:
    tasks = int(fin.readline())
    complexity = np.array(list(map(int, fin.readline().split())))
    timet = np.array(list(map(float, fin.readline().split())))
    workers = int(fin.readline())
    coeff = np.array([list(map(float, fin.readline().split())) for j in range(workers)])

genl = np.random.randint(1, 10, (5, tasks))

res = gen_alg(genl)
print(*res, file=open('output.txt', 'w'))