import re
import datetime

n = int(input())
t = ""
a = []

for i in range(n):
    s = input()
    t += s
t += " "

res = re.findall("[\W\a]\d\d\d\d-\d\d-\d\d\W", t)
for st in res:
    a.append(st)

for st in a:
    st = re.findall("\d\d\d\d-\d\d-\d\d", st)[0]
    sp = st.split("-")
    y = int(sp[0])
    m = int(sp[1])
    d = int(sp[2])
    try:
        datetime.date(year=y, month=m, day=d)
        correct = True
    except:
        correct = False

    if correct:
        print(st)
