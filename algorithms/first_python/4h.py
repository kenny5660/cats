import sys

n = int(input())
a = list()
b = list()
for i in range(n):
    a.append(list(map(int,sys.stdin.readline().split())))
    b.append([0]*n)
for i in range(n):
    for k in range(n):
        b[k][i] = a [i][k]
for i in range(n):
    print(" ".join(map(str,b[i])))