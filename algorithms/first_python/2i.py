with open('input.txt', 'r') as fin:
  a,b,t  = map(int, fin.read().split())

end = t % (a*2 + b*2)
with open('output.txt', 'w') as fout:
    if end >= 0 and end < a:
      print("S", file=fout)
    elif end >= a and end < a+b:
      print("E", file=fout)
    elif end >= a+b and end < a+b+a:
      print("N", file=fout)
    elif end >= a+b+a and end < a+b+a+b:
      print("W", file=fout)