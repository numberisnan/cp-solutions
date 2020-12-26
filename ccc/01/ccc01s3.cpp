
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

// From https://dmoj.ca/tips/
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INF(type) numeric_limits<type>::max()

using namespace std;

void dfs(vector<vector<int>> &adj, int start, int find, bool &found, bool vis[]) {
    vis[start] = true;

    //cout << "\n" << start << "\nadj: ";

    for (int node : adj[start]) {
        //cout << node << " ";
        if (node == find) {
            found = true;
        } else if (!vis[node] && !found) {
            dfs(adj, node, find, found, vis);
        }
    }
}

bool isConnected(vector<pair<int, int>> &edges) {
    bool vis[91];
    fill_n(vis, 91, false);
    //construct adj
    vector<vector<int>> adj;
    adj.resize(91);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    bool found = false;
    dfs(adj, 65, 66, found, vis);

    return found;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a, b;
    int c = 0;
    vector<pair<int, int>> edges;

    while (a != '*' && b != '*') {
        cin >> a >> b;
        edges.push_back({(int)a, (int)b});
        //cout << (int)a; nl;
    }

    edges.erase(edges.begin()+edges.size());

    loop(i, edges.size()) {
        pair<int,int> edge = edges[i];
        edges.erase(edges.begin()+i);

        // check if a and b are connected
        if (!isConnected(edges)) {
            cout << (char)edge.first << (char)edge.second; nl;
            c++;
        }

        edges.insert(edges.begin(), edge);
    }

    cout << "There are " << c << " disconnecting roads.";nl;
    return 0;
}
