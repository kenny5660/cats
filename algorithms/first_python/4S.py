def Join (array,separator):
    ans_str = ""
    for i in range(len(array)-1):
        ans_str += array[i]+separator
    return ans_str + array[-1]