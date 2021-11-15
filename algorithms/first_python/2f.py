with open('input.txt', 'r') as fin:
  a,b  = map(int, fin.read().split())

d = a+b-1

with open('output.txt', 'w') as fout:
    if (a%2 == 0 and b%2 == 0) or (a%2 != 0 and b%2 != 0) or d%4!=0:
      print(0, file=fout)
    else:
      print(d, file=fout)