def parse(arr):
    if len(arr) == 1:
        return float(arr[0])
    else:
        op = arr[-1]
        dis = 0
        sep = -2
        while dis >= 0:
            if arr[sep].isdigit(): # might want to check for float
                dis -= 1
            else:
                dis += 1
            sep -= 1

        if op == "+":
            return parse(arr[:sep+1]) + parse(arr[sep+1:-1])
        elif op == "-":
            return parse(arr[:sep+1]) - parse(arr[sep+1:-1])
        elif op == "*":
            return parse(arr[:sep+1]) * parse(arr[sep+1:-1])
        elif op == "/":
            return parse(arr[:sep+1]) / parse(arr[sep+1:-1])
        elif op == "%":
            return parse(arr[:sep+1]) % parse(arr[sep+1:-1])
        elif op == "^":
            return parse(arr[:sep+1]) ** parse(arr[sep+1:-1])



print(parse(input().split()))