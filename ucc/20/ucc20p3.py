import re

h = int(input())
nt = int(input())
t = [int(x) for x in input().split()]

ntr = int(input())
tr = input()

gap = max([len(x)-2 for x in re.findall(r'(?=(1[^1]*1))', tr)])

bt = 0

for i in range(nt):
    if gap >= t[i] > bt:
        bt = t[i]

print(h//bt + 1 if h%bt else h//bt)