digits = [int(d) for d in input()]



l = len(digits)
toi = 0
possible = True
if l == 1:
    print("0")
elif l == 2:
    s = digits[1] * 10 + digits[0]
    c = digits[0] * 10 + digits[1]
    if s > c:
        print(s)
    else:
        print(0)
else:
    while digits[l-toi-1] <= digits[l-toi-2]:
        if toi + 2 == l:
            possible = False
            break
        toi += 1
    
    if possible:
        insert = digits[l-toi-2]

        toSort = digits[l-toi-1:l]

        sted = digits[:l-toi-2]

        #print("toi: " + str(toi+1))
        #print("insert: " + str(insert))
        #print("toSort: " + str(toSort))
        #print("sted: " + str(sted))
        #print(possible)

        # find smallest toSort larger than insert

        remove = 1000000000
        removei = -1

        for i in range(len(toSort)): 
            if toSort[i] > insert and toSort[i] < remove: 
                remove = toSort[i]
                removei = i



        toSort[removei], insert = insert, toSort[removei]

        print(*sted, insert, *sorted(toSort), sep="")
    else:
        print(0)