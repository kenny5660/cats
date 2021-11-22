import sys
a = list(map(int,sys.stdin.read().split()))
n = len(a)
min_el = a[0]
max_el = a[0]
for i in range(n):
    if min_el > a[i]:
        min_el = a[i]
    if max_el < a[i]:
        max_el = a[i]
for i in range(n):
    if a[i] == max_el:
        a[i] = min_el

print(" ".join(map(str,a)))