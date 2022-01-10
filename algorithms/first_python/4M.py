a = list(map(int, input().split()))
print(" ".join(map(str,(a[:2])))+" "+"".join(str(e)+" " for e in a[-3:1:-1])+" ".join(map(str,(a[-2:]))))