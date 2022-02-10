s = input()

def iscons(s):
    return s in "AEIOUY"

f = s[0]
for i in range(1, len(s)):
    if iscons(s[i]) == iscons(s[i-1]):
        f += " " + s[i]
    else:
        f += s[i]

print(f)