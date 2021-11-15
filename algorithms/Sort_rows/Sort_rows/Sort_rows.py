cast_types = { 'd':lambda x: float(x), 'i':lambda x: -int(x), 'u':lambda x: abs(int(x)),'c':lambda x: -ord(x[0]),'s':lambda x: x.rstrip("\n")}
inFile = open('input.txt', 'r')
n,m = map(int, inFile.readline().split())
types = inFile.readline().split()
priority = list(map(int, inFile.readline().split()))
priority_s = sorted(range(len(priority)), key=lambda x: priority[x],reverse=True)
data = [list([cast_types[types[i]](inFile.readline()) for i in range(m)]) for j in range(n)]
with open('output.txt', 'w') as fout:
  print('\n'.join(map(str,sorted(range(len(data)),key = lambda x: [data[x][prior] for prior in priority_s]))), file=fout)
inFile.close()

b = [1,2,3,4,5,6,7,8]

a = (b[i] for i in range (5))

def arifm():
    a = 0
    while True:
        a+=yield a 
       #yield(a)
        

gen = arifm()
print(next(gen))
for i in range(5):
    print (gen.send(5))
for i in range(5):
    print (gen.send(10))

