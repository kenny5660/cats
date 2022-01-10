import sys
import math
a = list(map(float,sys.stdin.readline().split()))

sum = 0
for k in a:
    sum += k*k

print(math.sqrt(sum))