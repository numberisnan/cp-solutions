import re

for i in range(5):
    inp = input()
    print(len(re.findall('\w{4,}', inp)))