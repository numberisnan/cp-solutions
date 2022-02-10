import math

s = int(input())
interv = int(input())
msg = int(input())

v = math.ceil((msg-s)/interv)

if v > 3:
    print("Who knows...")
elif v == 0:
    print(interv+s)
else:
    print((interv*v)+s)