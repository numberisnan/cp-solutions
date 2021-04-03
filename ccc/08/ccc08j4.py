inp = ""


def reverse(s):
    #print(s)
    s = str(s)
    if len(s) == 1:
        return s
    else:
        cutoff = 1
        dis = 0
        while dis >= 0:
            if s[cutoff].isdigit():
                dis -= 1
            else:
                dis += 1
            cutoff += 1
        return reverse(s[1:cutoff]) + reverse(s[cutoff:]) + s[0]


while True:
    inp = input()
    if inp == "0":
        break
    res = reverse(inp.replace(" ", ""))
    res = " ".join(list(res))
    print(res)

