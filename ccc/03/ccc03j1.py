t = int(input())
s = int(input())
h = int(input())

for i in range(t):
    print(("*" + s * " ") * 2 + "*")

print("*" * (2*(1+s)+1))

for i in range(h):
    print(" " * ((2*(1+s)+1)//2) + "*")