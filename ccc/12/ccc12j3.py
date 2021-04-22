k = int(input())
org = ["*x*", " xx", "* *"]
for i in range(3):
    s = ""
    for j in range(3):
        s += org[i][j] * k
    for j in range(k):
        print(s)