import sys

a = list(sys.stdin.readline().split())
a = sorted(a,key=lambda x:x[1])
print(" ".join(map(str,a)))