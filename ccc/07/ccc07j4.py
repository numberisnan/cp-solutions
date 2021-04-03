a = input().replace(" ", "")
b = input().replace(" ", "")

ca = {}
cb = {}

for i in range(len(a)):
    if a[i] in ca:
        ca[a[i]] += 1
    else:
        ca[a[i]] = 1

for i in range(len(b)):
    if b[i] in cb:
        cb[b[i]] += 1
    else:
        cb[b[i]] = 1

print("Is an anagram." if len(ca.items() & cb.items()) == len(ca) else "Is not an anagram.")