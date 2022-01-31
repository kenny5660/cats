import numpy as np
data_x = list()
data_y = list()
with open('input.txt', 'r') as fin:
    N = int(fin.readline())
    for i in range(N):
        x, y = map(int, fin.readline().split())
        data_x.append(x)
        data_y.append(y)

data_x = np.array(data_x)
data_y = np.array(data_y)

sx_pows = np.array([0,0,0,0])
sy = 0
sxy = 0
sx2y = 0
for i in range(N):
  for k in range(4):
    sx_pows[k] =sx_pows[k] + (data_x[i] ** (k+1))
  sy = sy + data_y[i]
  sxy = sxy + data_x[i] * data_y[i]
  sx2y = sx2y + (data_x[i]**2) * data_y[i]

A = np.array(
  [
    [sx_pows[3], sx_pows[2], sx_pows[1]],
    [sx_pows[2], sx_pows[1], sx_pows[0]],
    [sx_pows[1], sx_pows[0], N]
  ]
)
B = np.array([sx2y,sxy,sy])
result =np.linalg.inv(A).dot(B)
#result = np.round(result,3)
with open('output.txt', 'w') as fout:
  print(result[0], result[1],result[2], file=fout)
