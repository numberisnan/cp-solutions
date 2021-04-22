n = int(input())

mcount = 1000000

for i in range(n):
    m = [int(x) for x in input().split()]
    mcount = min(mcount, sum(m[1:]))

print(mcount)