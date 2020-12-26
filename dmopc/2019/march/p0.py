sides = [int(x) for x in input().split()]

sides.sort()

print("yes" if sides[0] + sides[1] > sides[2] else "no")