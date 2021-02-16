def reduce(s):
    if len(s) == 1:
        return int(s)
    su = 0
    for i in range(len(s)):
        su += int(s[i])
    return reduce(str(su))

n = int(input())

for i in range(n):
    num = input()
    print(reduce(num))