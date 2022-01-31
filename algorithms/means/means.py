import numpy as np
with open('input.txt', 'r') as fin:
  n = int(fin.readline())
  data = []
  for i in range(n):
    data.append(list(map(float, fin.readline().split())))
  data = np.array(data).T
  mean = np.sum(data[0]*data[1])/ np.sum(data[1])
  harmonic = np.sum(data[1])/ (np.sum(1.0/data[0]*data[1]))
  geom = np.exp(np.sum(np.log(data[0])*data[1])/ np.sum(data[1]))
with open('output.txt', 'w') as fout:
  print(' '.join(map(str,[mean,harmonic,geom])), file=fout)