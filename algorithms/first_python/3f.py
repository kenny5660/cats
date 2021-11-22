import sys

n,k = map(int,sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
k = k % n
a = a[k:] + a[:k]
a= map(str,a)
print(" ".join(a))