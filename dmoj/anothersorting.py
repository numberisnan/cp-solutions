class n:
    unitsort = True
    def __init__(self, n):
        self.n = n
        self.u = n % 10
    def __lt__(self, other):
        if n.unitsort:
            return self.u < other.u
        else:
            return self.n < other.n
    def __gt__(self, other):
        if n.unitsort:
            return self.u > other.u
        else:
            return self.n > other.n
    def __str__(self):
        return str(self.n)

l = int(input())
v = [n(int(s)) for s in input().split()]

v.sort()

final = [[] for i in range(10)]

n.unitsort = False

for k in v:
    final[k.u].append(k)

for i in range(len(final)):
    final[i] = list(reversed(sorted(final[i])))
    for j in range(len(final[i])):
        print(str(final[i][j]), end=" ")


