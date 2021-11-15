import sys
n = input()
a = sys.stdin.read().split("\n")
a = list(map(lambda x: x.lower(), a))
print(a.count("boletus edulis"))