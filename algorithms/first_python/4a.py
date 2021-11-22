import sys

n = int(input())
sum = 0
for i in range(n):
    sum += int(input())
    if sum >= 1000:
        break
print(sum)