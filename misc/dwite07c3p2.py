for case in range(5):
    ip = input()
    inc = False
    inc2 = False
    ins = False
    inss = False

    s = ""
    i = 0
    while len(ip):
        if ip.find("'") == 0:
            end = ip[1:].find("'")+1
            s += " " + ip[1:end]
            ip = ip[end+1:]
        elif ip.find('"') == 0:
            end = ip[1:].find('"')+1
            s += " " + ip[1:end]
            ip = ip[end+1:]
            #print(ip)
        elif ip.find('/*') == 0:
            end = ip[1:].find('*/')+1
            s += " " + ip[2:end]
            ip = ip[end+2:]
        elif ip.find('//') == 0:
            s += " " + ip[2:]
            break
        else:
            ip = ip[1:]

    print(s.strip())
