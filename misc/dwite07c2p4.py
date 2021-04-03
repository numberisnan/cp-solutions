def check(inp):
    stack = []

    for j in range(len(inp)):
        if inp[j] in ['{','[','(']:
            stack.append(inp[j])
        elif inp[j] in [')','}',']']:
            if not len(stack):
                return "not balanced"
            char = stack.pop()
            if (inp[j] == '}' and char != '{') or (inp[j] == ']' and char != '[') or (inp[j] == ')' and char != '('):
                return "not balanced"

    return "balanced"

for i in range(5):
    inp = input()

    print(check(inp))


