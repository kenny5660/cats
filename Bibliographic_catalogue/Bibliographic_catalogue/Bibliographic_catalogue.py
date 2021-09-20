import collections
inFile = open('input.txt', 'r')
n = int(inFile.readline()) 
athors = collections.OrderedDict()
books = collections.OrderedDict()
id = 0
for i in range(n):
    data = inFile.readline().rstrip("\n").lower().split()
    if not(data[0] in athors):
        athors[data[0]] = id
        id += 1
    if data[1] in books:
        books[data[1]].add(athors[data[0]])
    else:
         books[data[1]] = {athors[data[0]]}
id = 0
groops = collections.OrderedDict()
for book in books:
    if not(frozenset(books[book]) in groops):
        groops[frozenset(books[book])] = id
        id+=1

with open('output.txt', 'w') as fout:
  print(len(athors), file=fout)
  print('\n'.join(key for key in athors)+'\n', file=fout)
  print(len(groops), file=fout)
  print('\n'.join(str(len(key))+' '+(' '.join(str(setkey) for setkey in key)) for key in groops)+'\n', file=fout)
  print(len(books), file=fout)
  print('\n'.join(key+' '+str(groops[frozenset(books[key])]) for key in books), file=fout)
inFile.close()
