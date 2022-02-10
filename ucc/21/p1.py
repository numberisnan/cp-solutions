s = input()

d = s.split("25")

n = 0
for seg in d:
    for char in seg:
        if char not in "46":
            n += 1


print(n)