import sys
#with open('d.in', 'r') as fin:
#       a = fin.readline()
a = sys.stdin.readline()
a = a.strip(("\n"))
a = a.strip((" "))
marks = (",",".","!","?")
marks_spc = (" ",",",".","!","?")
marks_spc_tir = (",",".","!","?","-"," ")
cnt = 0
state = 0
n = len(a)
for i in range(0,n):
     if not(a[i] in marks_spc_tir) and state == 0:
       cnt+=1
       state = 1
     elif a[i] in marks_spc or (a[i] == '-' and (i == n-1 or a[i+1] in marks_spc_tir)):
       state = 0
print(cnt)
#with open('d.out', 'w') as fout:
#       print(cnt,file=fout)