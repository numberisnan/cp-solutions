c = int(input())
for case in range(c):
  n = int(input())
  li = [int(s) for s in input().split()]
  #print(li)
  l = li.index(1)
  r = l
  curr = 1
  flag = True
  while curr < n:
    if li[(r+1) % n] == curr+1 or li[(r+1) % n] == curr-1:
      r += 1
    elif li[l-1] == curr+1 or li[l-1] == curr-1:
      l -= 1
    else:
      flag = False
      break
    curr += 1
    
  print("Case #" + str(case+1) + ": " + ("yes" if flag else "no"))
