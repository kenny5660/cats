str = input()
if str.count(",") > 0:
    print("сложное", end = ' ')
if str.count("?") > 0 and str.count("!") > 0:
    print("вопросительно-восклицательное")
elif str.count("?") > 0 and str.count("!") == 0:
    print("вопросительное")
elif str.count("?") == 0 and str.count("!") > 0:
    print("восклицательное")
else:
    print("повествовательное")