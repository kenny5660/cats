import numpy as np
with open('input.txt', 'r') as fin:
  n,k = map(int,fin.readline().split())
  data = np.array(list(map(float, fin.readline().split())))

unique, counts = np.unique(data, return_counts=True)

freq_table  = np.asarray((unique, counts))

with open('output.txt', 'w') as fout:
  print(np.sum( ((freq_table[0]-np.mean(data))**k)*(freq_table[1]/np.full(len(freq_table[1]), n)) ), file=fout)