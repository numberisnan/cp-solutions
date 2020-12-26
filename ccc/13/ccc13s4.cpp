#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    bool x = false; // switch t and f, use for extra cases

    int n, m, f, t;
    cin >> n >> m;
    vector<vector<int>> adjlist;
    adjlist.resize(n);

    for (int i = 0; i < m; i++) {
        cin >> t >> f;
        if (x) {
            swap(t, f);
        }
        adjlist[f-1].push_back(t-1); // Directed
    }

    int p, q;
    cin >> p >> q;
    p--;
    q--;
    
    // Bfs to find if q is in p
    queue<int> toSearch;
    bool visited[n]; 
    fill_n(visited, n, false); // Know that this works
    
    set<int> path;
    path.insert(p);

    toSearch.push(p);
    visited[p] = true;
    int s;
    bool qinp = false;

    while (toSearch.size() && !qinp) {
        s = toSearch.front();
        toSearch.pop();

        for (int node : adjlist[s]) {
            if (!visited[node]) {
                if (node == q) {
                    cout << (x ? "yes" : "no");
                    return 0;
                }

                toSearch.push(node);
                path.insert(node);
                visited[node] = true;
            }
        }
    }

    // bfs for p in q
    queue<int> toSearchb; 
    fill_n(visited, n, false); 

    toSearchb.push(q);
    visited[q] = true;
    bool pinq = false;

    while (toSearchb.size() && !pinq) {
        s = toSearchb.front();
        toSearchb.pop();

        for (int node : adjlist[s]) {
            if (!visited[node]) {
                if (node == p) {
                    cout << (x ? "no" : "yes");
                    return 0;
                }

                if (path.find(node) == path.end()) {
                    toSearchb.push(node);
                    visited[node] = true;
                }

                
            }
        }
    }
    
    cout << "unknown";
    return 0;
}