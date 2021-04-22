def shift(c, s):
    n = ord(c)-65
    nn = n + s
    nn %= 26
    return chr(nn + 65)


k = int(input())


def f(p):
    return 3*p + k


m = input()
d = []

for i in range(len(m)):
    d.append(shift(m[i], -f(i+1)))

print("".join(d))