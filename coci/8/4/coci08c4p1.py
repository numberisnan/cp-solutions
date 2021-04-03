def iterate(arr):
    for i in range(len(arr)-1):
        if arr[i] > arr[i+1]:
            [arr[i], arr[i+1]] = [arr[i+1], arr[i]]
            print(" ".join([str(x) for x in arr]))
    return arr


a = [int(x) for x in input().split()]

while a != sorted(a):
    a = iterate(a)
