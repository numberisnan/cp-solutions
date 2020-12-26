s = input()


def isvalid(w):
    w = w.replace("B", " ( 4 + ")
    w = w.replace("S", " / 4 ) ")
    w = w.replace("A", " 1 ")
    w = w.replace("N", " + ")
    #print(w)
    if w == "":
        return False
    try:
        eval(w)
    except:
        return False
    return True


while s != "X":
    print("YES" if isvalid(s) else "NO")
    s = input()