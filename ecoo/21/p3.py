[n, m, k] = [int(x) for x in input().split()]

best = [[-1, -1]] * (n+1) # score, then prof

for i in range(k):
    [a,b,c] = [int(x) for x in input().split()]

    if best[b][0] < c:
        best[b] = [c, a]

print(best[1][1], end="")
for i in range(2, n+1):
    print(" " + str(best[i][1]), end="")
print()