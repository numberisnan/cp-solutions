newmap = [int(x) for x in input().split()]
word = input()

def lettertokey(s):
    buttons = ["", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    for i in range(len(buttons)):
        if s in buttons[i]:
            return [str(newmap.index(i+1)+1) * (ord(s) - ord(buttons[i][0]) + 1), str(newmap.index(i+1)+1)]


res = ""
lastkey = 0

for i in range(len(word)):
    orig = lettertokey(word[i])
    if orig[1] == lastkey:
        res += "#" + orig[0]
    else:
        res += orig[0]
    lastkey = orig[1]

print(res)


