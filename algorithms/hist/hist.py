import numpy as np
with open('input.txt', 'r') as fin:
  n = int(fin.readline())
  data = np.array(list(map(float, fin.readline().split())))

k = int(1 + np.floor(np.log2(n)))
with open('output.txt', 'w') as fout:
  print(' '.join(map(str,np.histogram(data,bins=k)[0])), file=fout)