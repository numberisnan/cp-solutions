inp = input()
while inp != "quit!":
    if len(inp) >= 4 and inp[-2:] == "or" and inp[-3] not in "aeiouy":
        print(inp[:-1] + "ur")
    else:
        print(inp)
    inp = input()