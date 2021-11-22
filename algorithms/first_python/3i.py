import sys

a = sys.stdin.readline()

cnt = 1
n = len(a)
for i in range(n):
     if (a[i] in (" ")):
            cnt+=1
     if (a[i] in (",",".","!","?")):
            cnt-=1

print(cnt)