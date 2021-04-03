a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

a.sort()
b.sort()

def main():
    for i in range(3):
        if a[i] > b[i]:
            print("N")
            return

    print("Y")

main()

