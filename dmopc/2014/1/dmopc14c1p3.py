n = int(input())
gradesum = 0
averages = []
for i in range(n):
    gradesum += int(input())
for i in range(int(input())):
    gradesum += int(input())
    n += 1
    averages.append(gradesum/n)
for n in averages:
    print("%.3f" % n)