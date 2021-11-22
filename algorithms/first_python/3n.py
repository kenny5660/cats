import sys

with open('input.txt', 'r') as fin:
    n = fin.readline()
    file_names = fin.read().split()
fout = open('output.txt', 'w')
d = dict()
for name in file_names:
  new_name = name
  while new_name.lower() in d:
      d[new_name.lower()] += 1
      new_name = name+str(d[new_name.lower()])
  print(new_name,file=fout)
  d[new_name.lower()] = 0

    