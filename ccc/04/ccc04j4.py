import re

k = [ord(x)-65 for x in input()]
m = [ord(x)-65 for x in re.sub("[!-/:-@[-`{-~ ]", "",input())]

for i in range(len(m)):
    m[i] += k[i%len(k)]
    m[i] %= 26
    m[i] = chr(m[i]+65)

print("".join(m))

