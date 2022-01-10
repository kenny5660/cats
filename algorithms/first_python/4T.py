fin = open('input.txt', 'r')
n = int(fin.readline())

groups = dict()
for i in range(n):
    line = fin.readline().split()
    if not(line[0] in groups):
        groups[line[0]] = list()
    groups[line[0]].append(""+line[1]+" "+ line[2])

groups_key_sorted = sorted(groups.keys())
fout = open('output.txt','w')
for group in groups_key_sorted:
    print(group,file=fout)
    groups[group].sort()
    for student in groups[group]:
        print(student,file=fout)

fout.close()
fin.close()
