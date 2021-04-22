m = input()
e = input()
e2 = input()
m2 = ""

ma = {}

for i in range(len(m)):
    ma[e[i]] = m[i]
for i in range(len(e2)):
    if e2[i] in ma:
        m2 += ma[e2[i]]
    else:
        m2 += "."

print(m2)