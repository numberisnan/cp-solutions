import re

exp = re.compile(r"([aeiou])p\1")

inp = input()

print(exp.sub(r"\1", inp))