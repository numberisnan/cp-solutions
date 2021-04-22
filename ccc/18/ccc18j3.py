d = [int(x) for x in input().split()]

for i in range(5):
    for j in range(5):
        if i > j:
            print(sum(d[j:i]), end=" " if j != 4 else "")
        else:
            print(sum(d[i:j]), end=" " if j != 4 else "")
    print()
