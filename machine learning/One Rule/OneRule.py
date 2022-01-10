from io import StringIO
input_text="""10 4
Outlook Temperature Humidity Windy
overcast hot high FALSE 1
sunny mild high FALSE 0
overcast mild high TRUE 1
rainy mild normal FALSE 1
overcast hot normal FALSE 1
rainy mild high FALSE 1
rainy cool normal FALSE 1
rainy mild high TRUE 0
sunny hot high FALSE 0
sunny hot high TRUE 0
4
rainy cool normal TRUE
sunny cool normal FALSE
overcast cool normal TRUE
sunny mild normal TRUE
"""
sys.stdin = StringIO(input_text)

import sys 
n,k = map(int,sys.stdin.readline().split())
colums = sys.stdin.readline().split()

df_lern = list()
df_test = list()
for i in range(n):
    df_lern.append(sys.stdin.readline().split())
m = int(sys.stdin.readline())
for i in range(m):
    df_test.append(sys.stdin.readline().split())

real_answ = k

best_predictor = dict()
best_predictor_column = ""
best_predictor_erros = n
for column in range(k):
    freq_table = dict()
    predictor = dict()
    errors = 0
    for row in range(n):
        if not(df_lern[row][column] in freq_table):
            freq_table[df_lern[row][column]] = {"0":0,"1":0}
        freq_table[df_lern[row][column]][df_lern[row][real_answ]] +=1
    for key in freq_table.keys():
        if freq_table[key]["1"] >= freq_table[key]["0"]:
            predictor[key] = "1"
        else:
            predictor[key] = "0"
    for row in range(n):
        if predictor[df_lern[row][column]] != df_lern[row][real_answ]:
            errors +=1
    if errors < best_predictor_erros:
        best_predictor_erros = errors
        best_predictor = predictor
        best_predictor_column = column
for row in range(m):
    print(best_predictor[df_test[row][best_predictor_column]])




