import math

[m, n, k] = [int(x) for x in input().split()]
h = [int(x) for x in input().split()]

h = sorted(h, reverse=True)

ncols = math.ceil(k/m)
front = h[:ncols]
#print(front)

h = h[ncols:]
count = 0
for i in range(ncols):
    sec = h[:m-1]
    h = h[m-1:]
    #print(sec)
    for j in range(len(sec)):
        count += front[i] - sec[j]
        count += j+1
        #print(front[i] - sec[j] + i+1)

print(count)