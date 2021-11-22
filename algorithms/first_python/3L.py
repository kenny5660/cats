import sys
with open('input.txt', 'r') as fin:
    n = int(fin.readline())
    a = list(map(int,fin.read().split()))

cnt = [0 for i in range(10)]
for i in range(n):
  cnt[a[i]] += 1

with open('output.txt', 'w') as fout:
    print(" ".join(map(str,cnt[1:])),end="",file=fout)
    print(" "+str(cnt[0]),file=fout)

