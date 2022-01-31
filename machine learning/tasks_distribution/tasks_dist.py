import tqdm
import numpy as np

def mix(a, b, mutation_chance=0.01):
    c = np.where(np.random.randint(0, 2, a.shape[0]), a, b)
    if np.random.randint(2):
        return np.where(np.random.random(a.shape[0]) < mutation_chance, np.random.randint(1, workers+1, a.shape[0]), c)
    return c


def gen_alg(gen, m=1000, child_count = 20,mutation_chance_function=lambda x:0.1):
    
    k = gen.shape[0]
    n = gen.shape[0] * child_count
    best = np.zeros(gen.shape[1])
    pbar = tqdm.trange(m)
    time = np.zeros(n)
    buff = np.zeros(10)
    for i in pbar:
        #mutation_chance = max(mutation_start_chance-(((i**1.5)/m)),mutation_min_chance)
        mutation_chance = mutation_chance_function(i)
        mixed = np.array(list(map(lambda x: mix(gen[x[0]], gen[x[1]], mutation_chance),
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
        pbar.set_description(str(score)+" "+str(mutation_chance))

    return (best,score)


with open('input.txt', 'r') as fin:
    tasks = int(fin.readline())
    complexity = np.array(list(map(int, fin.readline().split())))
    timet = np.array(list(map(float, fin.readline().split())))
    workers = int(fin.readline())
    coeff = np.array([list(map(float, fin.readline().split())) for j in range(workers)])


started_gens = 15
generations = 600
child_count = 20
mutation_min_chance = 0.001
mutation_chance_function = lambda x: max(5/((x+1)**1),mutation_min_chance)

gen = np.random.randint(1, workers+1, (started_gens, tasks))
bests = list()
scores = list()
for i in range(30):
    if len(bests) > 0 :
        gen[0] = bests[np.argmax(scores)]
        res = gen_alg(gen,generations,child_count,mutation_chance_function)
    else:
        res = gen_alg(gen,generations,child_count,mutation_chance_function)
    bests.append(res[0])
    scores.append(res[1])
    mutation_chance_function = lambda x: max(3/((x+1)**1.2),mutation_min_chance)
    child_count = 15
print(*scores)
print(scores[np.argmax(scores)])
print(*bests[np.argmax(scores)], file=open('output-'+str(scores[np.argmax(scores)])+'.txt', 'w'))