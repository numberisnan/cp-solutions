import re
for case in range(5):
    ip = input().strip()
    i = 1
    while ip[:len(ip)-i] != ip[i:] and i < len(ip):
        i += 1
    #print(i)
    print(ip + ip[len(ip)-i:])
