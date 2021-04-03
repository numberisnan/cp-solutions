fr = int(input())
to = int(input())

pairs = [[1,1],[6,9],[9,6],[8,8],[0,0]]

def isRotatable(n):
    st = str(n)
    for i in range(len(st)):
        if not ([int(st[i]), int(st[-(i+1)])] in pairs):
            return False

    return True

count = 0
for i in range(fr, to+1):
    if isRotatable(i):
        count += 1
        #print(i)

print(count)