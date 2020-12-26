#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

// From https://dmoj.ca/tips/
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n"
#define ll long long
#define ull unsigned long long
#define INF(type) numeric_limits<type>::max()

using namespace std;

//begintemplate BFS
int bfs(unordered_set<int> adj[], int start, int find) {
    //cout << "Node " << start << " is connected to: ";
    int n = 50;
    queue<int> q;
    int vis[n];

    fill_n(vis, n, -1);
    q.push(start);
    vis[start] = 0;

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (int node : adj[c]) {
            if (vis[node] == -1) {
                if (node == find) {
                    return vis[c]+1;
                }
                q.push(node);
                vis[node] = vis[c]+1;
            }
        }
    }

    return -1;
}

unordered_set<int> adj[51] = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c = ' ';
    int a, b;

    while (c != 'q') {
        cin >> c;
        if (c == 'i') {
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        } else if (c == 'd') {
            cin >> a >> b;
            adj[b].erase(a);
            adj[a].erase(b);
        } else if (c == 'n') {
            cin >> a;
            cout << adj[a].size(); nl;
        } else if (c == 'f') {
            cin >> a;
            unordered_set<int> res;
            int friends = adj[a].size();
            for (int f : adj[a]) {
                res.insert(f);
                for (int f2 : adj[f]) {
                    res.insert(f2);
                }
            }
            cout << res.size() - friends - 1; nl;
        } else if (c == 's') {
            cin >> a >> b;
            int r = bfs(adj, a, b);
            if (r == -1) {
                cout << "Not connected"; nl;
            } else {
                cout << r; nl;
            }
        }
    }

    return 0;
}
