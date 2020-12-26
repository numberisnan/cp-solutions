n = int(input())
for i in range(n):
    i = [int(i) for i in input().split()]
    print("16 BIT S/W ONLY" if i[0] * i[1] != i[2] else "POSSIBLE DOUBLE SIGMA")