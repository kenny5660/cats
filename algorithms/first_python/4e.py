import sys
str_words = sys.stdin.readline().split()
a = int(input()) -1
if a >= len(str_words):
    print(str_words[-1])
else:
    print(str_words[a])