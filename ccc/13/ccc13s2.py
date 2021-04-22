w = int(input())

n = int(input())

t = []
for i in range(n):
    t.append(int(input()))

i = -4
s = 0
while s <= w and i+4 < len(t):
    #print(s)
    if i >= 0:
        s -= t[i]
    s += t[4+i]
    i += 1
if i+3 != 99999:
    print(i+3)
else:
    print(n)