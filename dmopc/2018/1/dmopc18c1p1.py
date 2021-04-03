input()
s = [int(x) for x in input().split()]

if 0 in s:
    finalzero = len(s)-s[::-1].index(0)-1

    if finalzero == len(s)-1:
        el = max(s)
    else:
        el = s[finalzero+1]

    s = [(x if x else el) for x in s]

#print(s)
print("YES" if s == sorted(s) else "NO")