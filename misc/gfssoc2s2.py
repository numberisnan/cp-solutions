[n,t] = [int(x) for x in input().split()]

m = []

for i in range(n):
    temp = input().split()
    m.append([temp[0], int(temp[1])])

s = []

for i in range(n):
    for j in range(n):
        if i == j: continue
        for k in range(n):
            if k == i or k == j: continue
            if m[i][1]+m[j][1]+m[k][1] <= t:
                p = " ".join(sorted([m[i][0],m[k][0],m[j][0]]))
                if p not in s:
                    s.append(p)

s.sort()

for i in range(len(s)):
    print(s[i])