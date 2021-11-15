def mod_sum(a, b, p):
 if (a < (p - b)):
  return a + b;
 else:
  return b - (p - a);

def mod_mul(a,b,p):
 k = a
 c = 0
 while (b != 0):
   if (b % 2 == 1):
    c = mod_sum(c, k,p);
   b = b // 2;
   k = mod_sum(k, k, p);
 return c;

with open('input.txt', 'r') as fin:
  p,n = map(int, fin.readline().split())
  pol = map(int, fin.read().split()) 
pol = list(pol)
n +=1;
if (n > 1):

 last= 1
 cur = pol[0]
 pol[1] = mod_mul(p - pol[1], pol[0], p)
 for i in range(2,n):
  cur = pol[0]
  for j in range(1,i):
   last = cur;
   cur =  pol[j];
   pol[j] = mod_sum(cur,mod_mul(p-pol[i], last, p), p);
  pol[i] = mod_mul(p - pol[i], cur, p);

with open('output.txt', 'w') as fout:
  print(" ".join(map(str,pol[::-1])), file=fout)