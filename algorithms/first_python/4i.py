import sys

p = int(input())
a = list(map(int,sys.stdin.readline().split()))
n,m = list(map(int,sys.stdin.readline().split()))
b = list()
for i in range(n):
    b.append(a[i*m:i*m+m])

for i in range(n):
    print(" ".join(map(str,b[i])))