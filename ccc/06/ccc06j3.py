inp = input()

bu = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
def keyTime(a):
    for i in range(len(bu)):
        if a in bu[i]:
            return bu[i].index(a)+1

def sameKey(a,b):
    for i in range(len(bu)):
        if a in bu[i] and b in bu[i]:
            return True

    return False


while inp != "halt":
    count = 0
    for i in range(len(inp)-1):
        count += keyTime(inp[i])
        if sameKey(inp[i], inp[i+1]):
            count += 2

    print(count + keyTime(inp[-1]))
    inp = input()