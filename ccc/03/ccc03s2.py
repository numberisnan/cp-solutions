import re

n = int(input())

for i in range(n):
    final = []
    for j in range(4):
        inp = input().lower()
        finalword = inp.split()[-1]
        if len(re.findall("[aeiou]", finalword)):
            finalsyl = re.findall("[^aeiou]*([aeiou][^aeiou]*)", finalword)[-1]
        else:
            finalsyl = finalword
        final.append(finalsyl)

    #print(final)
    if final[0] == final[1] and final[1] == final[2] and final[2] == final[3]:
        print("perfect")
    elif final[0] == final[1] and final[2] == final[3]:
        print("even")
    elif final[0] == final[2] and final[1] == final[3]:
        print("cross")
    elif final[0] == final[3] and final[2] == final[1]:
        print("shell")
    else:
        print("free")