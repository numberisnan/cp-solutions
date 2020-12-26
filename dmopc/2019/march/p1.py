from decimal import Decimal

slopes = []
yints = []
for _ in range(2):
    points = [Decimal(x) for x in input().split()]
    if (points[0] == points[2]):
        slopes.append(None)
        yints.append(points[0])
    else:
        slope = (points[1] - points[3]) / (points[0] - points[2])
        slopes.append(slope)
        yint = points[1] - (slope * points[0])
        yints.append(yint)

if (slopes[0] == slopes[1]):
    if (yints[0] == yints[1]):
        print("coincident")
    else:
        print("parallel")
else:
    # find intersection
    if None in slopes:
        if (slopes[0] == None): # line 1 is verical
            print("%.6f %.6f" % (yints[0], (slopes[1] * yints[0]) + yints[1]))
        else:
            print("%.6f %.6f" % (yints[1], (slopes[0] * yints[1]) + yints[0]))
    else:
        x = (yints[0] - yints[1]) / (slopes[1] - slopes[0])
        y = (slopes[0] * x) + yints[0]
        print("%.6f %.6f" % (x, y))