import sys

a = sys.stdin.read().split()
n = len(a)
for i in range(n):
  if i % 2 == 0:
    if i == n-1 or i == n-2:
       print(a[i])
    else:
      print(a[i]+", ",end="")
     
    
  
for i in range(n):
  if i % 2 != 0:
    if i == n-1 or i == n-2:
       print(a[i])
    else:
      print(a[i]+", ",end="")
    