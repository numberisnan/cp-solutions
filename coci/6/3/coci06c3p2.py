count = 0

def manhat(a,b,c,d):
    return abs(a-c) + abs(b-d)

for i in range(4):
    inp = input()
    for j in range(4):
        if inp[j] == ".":
            continue
        number = ord(inp[j])-65
        coords = [number//4, number%4]
        count += manhat(i,j,*coords)

print(count)