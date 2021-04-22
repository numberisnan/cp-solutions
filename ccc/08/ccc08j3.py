def ttc(c): # r c
    if 65 <= ord(c) <= 90:
        n = ord(c)-65
        return [n//6, n%6]
    elif c == " ":
        return [4, 2]
    elif c == "-":
        return [4, 3]
    elif c == ".":
        return [4, 4]
    else:
        return [4, 5]


def manhat(a,b):
    return abs(a[0]-b[0]) + abs(a[1]-b[1])


inp = input() + "/"
c = [0,0]
count = 0

for i in range(len(inp)):
    nextc = ttc(inp[i])
    count += manhat(c, nextc)
    #print(manhat(c, nextc))
    c = nextc

print(count)
#print()

