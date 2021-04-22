n = int(input())

l = []
for i in range(n):
    l.append(input().split())

s = input()
f = ""

while len(s):
    for i in range(n):
        if s.startswith(l[i][1]):
            s = s[len(l[i][1]):]
            f += l[i][0]

print(f)