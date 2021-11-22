import sys
n,k = map(int,sys.stdin.readline().split())
a = list(map(int,sys.stdin.readline().split()))
keys = list(map(int,sys.stdin.readline().split()))
for i in range(k):
    a[keys[i]-1] +=1


print(" ".join(map(str,a)))