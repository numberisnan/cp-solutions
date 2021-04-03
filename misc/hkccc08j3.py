n = int(input())

phonebook = {}
counts = {}

for i in range(n):
    [name, number] = input().split()
    phonebook[number] = name

d = int(input())

for i in range(d):
    number = int(input())
    if number in counts:
        counts[number] += 1
    else:
        counts[number] = 1

mostCalled = 0
number = 1000000000

for key in counts:
    if counts[key] > mostCalled or (counts[key] == mostCalled and int(key) < number):
        mostCalled = counts[key]
        number = int(key)

print(phonebook[str(number)])