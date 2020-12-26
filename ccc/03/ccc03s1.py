p = 1
while True:
    if p == 100:
        print("You Win!")
        break 
    roll = int(input())
    if not roll:
        print("You Quit!")
        break
    p += roll
    if p > 100:
        p -= roll
    if p == 54:
        p = 19
    elif p == 90:
        p = 48
    elif p == 99:
        p = 77
    elif p == 9:
        p = 34
    elif p == 40:
        p = 64
    elif p == 67:
        p = 86
    print("You are now on square " + str(p))
    
