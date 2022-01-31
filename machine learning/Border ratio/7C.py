import numpy as np


def GetShortDist(dists, indicies):
    ind = np.argmin(dists)
    return dists[ind], indicies[ind]


def GetDists(x, y, coordsByValue):
    dists = {}
    for value, coords in coordsByValue.items():
        dists[value] = GetShortDist(np.linalg.norm(
            coords[0] - x, axis=-1), coords[1]) if y != value else -1
    return dists


def get_border_value(point, value, dist):
    m, ind = float('inf'), None
    for l, data in point.items():
        if l == value:
            continue

        if data[0] < m:
            m, ind = data
    return dist[ind][value][0] / m


n, m = [int(el) for el in input().split()]
data = []
for i in range(n):
    data.append([float(el) for el in input().split()])
data = np.array(data)

x = data[..., :-1]
y = data[..., -1].astype(int)

inds = np.arange(n)
coordsByValue = {value: (x[y == value], inds[y == value])
                 for value in np.unique(y)}

dists = [GetDists(x[i], y[i], coordsByValue) for i in range(len(x))]

for i in range(len(y)):
    m = float('inf')
    ind = 0
    for value, distData in dists[i].items():
        if value == y[i]:
            continue
        if distData[0] < m:
            m, ind = distData
    print(dists[ind][y[i]][0] / m, end=' ')
