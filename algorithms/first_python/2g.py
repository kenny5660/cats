with open('input.txt', 'r') as fin:
  hour_t,minute_t,hour_d,minute_d  = map(int, fin.read().split())

minute_out = (minute_t + minute_d)%60
hour_out = (hour_t + hour_d + ((minute_t + minute_d)//60))%24
with open('output.txt', 'w') as fout:
    print("%s %s"%(hour_out,minute_out), file=fout)