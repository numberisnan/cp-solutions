from sys import stdin 

input = stdin.readline

[n, m, k] = [int(x) for x in input().split()]

g = [[] for i in range(n)]

for _ in range(m):
    s = [int(x) for x in input().split()]
    g[s[0]-1].append(s[1]-1)
    g[s[1]-1].append(s[0]-1)

if m == k:
    print(max(0, n - 1 - m))
elif not k:
    visited = [False] * n
    parts = 0
    for i in range(len(g)):
        if visited[i]: # already counted
            continue

        queue = []
        queue.append(i)
        visited[i] = True

        while len(queue): # bfs the node to visit connected nodes
            s = queue.pop(0)

            for n in g[s]:
                if not visited[n]:
                    queue.append(n)
                    visited[n] = True
        # new island
        parts += 1
    print(parts - 1)
else:
    visited = [False] * n
    parts = 0
    extraedges = 0
    for i in range(len(g)):
        if visited[i]: # already counted
            continue

        queue = []
        queue.append(i)
        visited[i] = True
        edges = 0
        nodes = 1

        while len(queue): # bfs the node to visit connected nodes
            s = queue.pop(0)

            for n in g[s]:
                edges += 1
                if not visited[n]:
                    queue.append(n)
                    visited[n] = True
                    nodes += 1
        # new island
        parts += 1
        extraedges += (edges // 2) - nodes + 1
    print(max(0, parts - 1 - min(extraedges, k)))

