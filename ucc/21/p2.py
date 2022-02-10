n = int(input())

inp = [int(x) for x in input().split()]
inp.append(1)

m = 0
beg = -1
for i in range(n+1):
    if inp[i]%2:
        m = max(m, sum(inp[beg+1:i]))
        #print(beg, i, sum(inp[beg+1:i]))
        beg = i

print(m)