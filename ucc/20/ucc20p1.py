n = int(input())
a = input()
b = input()

c = 0
for i in range(n):
    if a[i] == '0' and b[i] == '0':
        c += 1

print(c)