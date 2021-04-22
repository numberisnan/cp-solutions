n = int(input())

s = []
v = []
o = []
final = []

for i in range(n):
    sn = int(input())
    vn = int(input())
    on = int(input())

    s.clear()
    v.clear()
    o.clear()
    final.clear()

    for j in range(sn):
        s.append(input())
    for j in range(vn):
        v.append(input())
    for j in range(on):
        o.append(input())

    for j in range(sn):
        for k in range(vn):
            for l in range(on):
                final.append(s[j] + " " + v[k] + " " + o[l] + ".")

    #final = sorted(final)

    for j in range(len(final)):
        print(final[j])
    if i != n-1:
        print("")