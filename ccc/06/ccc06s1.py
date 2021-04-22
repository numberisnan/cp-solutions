a = input()
b = input()

def c(a,b):
    return a.upper() if a.isupper() or b.isupper() else a.lower()
def merge(a,b):
    poss = []
    for i in range(2):
        for j in range(2):
            if c(a[i],b[j]) not in poss:
                poss.append(c(a[i],b[j]))
    return poss

allposs = []
for i in range(0, 10, 2):
    allposs.append(merge(a[i:i+2], b[i:i+2]))
    #print(merge(a[i:i+2], b[i:i+2]))
n = int(input())

def main(inp):
    for j in range(5):
        if inp[j] not in allposs[j]:
            return "Not their baby!"

    return "Possible baby."


for i in range(n):
    print(main(input()))