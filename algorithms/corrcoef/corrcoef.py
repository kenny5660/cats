import numpy as np
with open('input.txt', 'r') as fin:
  n,m = map(int,fin.readline().split())
  data = []
  for i in range(n):
    data.append(list(map(float, fin.readline().split())))
  data = np.array(data)
  corcoef = np.corrcoef(data)
with open('output.txt', 'w') as fout:
  for i in range(n):
    print(' '.join(map(str,corcoef[i])), file=fout)