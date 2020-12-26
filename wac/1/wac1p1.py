import math
from decimal import getcontext, Decimal, ROUND_CEILING
getcontext().prec = 30 # 100 if necessary

ans = []

for _ in range(int(input())):
    ans.append((Decimal(0.5) + Decimal(Decimal(0.25) + Decimal(2) * Decimal(input())).sqrt()).to_integral_exact(rounding=ROUND_CEILING))

for n in ans:
    print(n)