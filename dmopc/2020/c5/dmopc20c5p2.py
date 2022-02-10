import fractions
from math import floor, ceil

[n, m] = [int(x) for x in input().split()]
sq = ""
total = 0
bottom = 0

for i in range(m):
    temp = (n*(i+1))/m
    top = ceil(temp)
    for j in range(bottom, top):
        sq += str(j+1) + " " + str(i+1) + "\n"
        total += 1

    bottom = top-1 if temp != int(temp) else top

print(total)
print(sq[:-1])
