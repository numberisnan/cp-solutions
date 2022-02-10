#include <bits/stdc++.h>
#include <vector>
#include <queue>

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define nl cout << "\n";

using namespace std;

int fib[500001];
vector<int> adj[500001];
int vis[500001];

int f(int i) {
    if (i==1) return 2;
    else if (i==2) return 3;
    return (i%50)+((fib[i-1]+fib[i-2])%2021);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    fib[1] = 1;
    fib[2] = 1;
    loopfrom(1, i, n) {
        if (i >= 3) {
            fib[i] = (fib[i-1]+fib[i-2])%2021;
        }
        adj[i].push_back(i-1);
        if (i != n) {
            adj[i].push_back(i+1);
        }
        if (i-f(i) >= 1) {
            adj[i].push_back(i-f(i));
        }
        if (i+f(i) <= n) {
            adj[i].push_back(i+f(i));
        }
    }

    queue<int> q;
    fill_n(vis, n+1, -1);

    q.push(1);
    vis[1] = 0;
    int c;

    while(q.size()) {
        c = q.front();
        q.pop();

        for (int node : adj[c]) {
            if (vis[node] == -1) {
                //cout << node; nl;
                vis[node] = vis[c]+1;
                q.push(node);
                if (node == n) {
                    cout << vis[node]; nl;
                    return 0;
                }
            }
        }
    }


    return 0;
}

