import sys

n = int(input())
a = list()
for i in range(2):
    a.append(list(map(int, sys.stdin.readline().split())))

b = a[0]

for i in range(2-1):
    for k in range(n):
        b[k] = b[k]+ a[i+1][k]
b= map(str,b)
print(" ".join(b))