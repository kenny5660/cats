import sys


a = list(map(int,sys.stdin.readline().split()))
n = len(a)
b = list()
for i in range(n):
    if i == n -1 or a[i+1] != 0:
        b.append(a[i])


print(" ".join(map(str,b)))