[calls,minutes] = list(map(lambda n:int(n), input().split()))
ppc = list(map(lambda n:int(n), input().split()))
ppc.sort()
quality = 0
if calls > 100:
    ci = -1
    for _ in range(minutes):
        if ci < -1 and ppc[ci] < ppc[ci+1]:
            ci += 1
        elif ci > -calls and ppc[ci-1] > ppc[ci]:
            ci -= 1
        quality+=ppc[ci]
        if ppc[ci] > 0:
            ppc[ci]-=1
else:
    for _ in range(minutes):
        quality+=ppc[-1]
        if ppc[-1] > 0:
            ppc[-1]-=1
        # resort ppc
        for i in range(1, len(ppc) + 1):
            if ppc[-1] < ppc[-i]:
                ppc.insert(-i-1,ppc.pop())
                break
print(quality)