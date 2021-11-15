with open('input.txt', 'r') as fin:
    str1 = fin.readline()
str_out = ""
if str1[0].isupper():
    str_out += str1[0].lower()
    for i in range(1,len(str1)):
        if str1[i].isupper():
            str_out += "_"
        str_out += str1[i].lower()
else:
    split_str = str1.split("_")
    split_str = map(lambda x: x.title(),split_str)
    str_out = "".join(split_str)

with open('output.txt', 'w') as fout:
    print(str_out,file=fout)
