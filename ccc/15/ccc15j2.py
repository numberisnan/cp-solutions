import re

i = input()

h = len(re.findall(r':-\)', i))
s = len(re.findall(r':-\(', i))

if h == s:
    if h == 0:
        print("none")
    else:
        print("unsure")
elif h > s:
    print("happy")
else:
    print("sad")