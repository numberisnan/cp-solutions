nb = int(input())

b = []


for i in range(nb):
    curbox = sorted([int(x) for x in input().split()])
    curbox.append(curbox[0]*curbox[1]*curbox[2])
    b.append(curbox[::-1])

b.sort()
#print(b)

ni = int(input())

for i in range(ni):
    found = False
    d = sorted([int(x) for x in input().split()])
    for box in b:
        if box[3] >= d[0] and box[2] >= d[1] and box[1] >= d[2]:
            found = True
            print(box[0])
            break
    if not found:
        print("Item does not fit.")