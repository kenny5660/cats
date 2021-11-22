str_p = input()

str_p = str_p.replace(" ","")
str_p = str_p.lower()
if str_p == str_p[::-1]:
    print("True")
else:
    print("False")