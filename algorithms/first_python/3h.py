import sys

a = list(map(int, sys.stdin.readline().split()))

a.sort()
cnt = 0
n = len(a)
for i in range(n):
     if (i == 0 or a[i] > a[i-1]):
            cnt+=1

print(cnt)