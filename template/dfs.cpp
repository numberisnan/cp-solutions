#include <bits/stdc++.h>
#include <vector>

using namespace std;

//begintemplate DFS
void dfs(vector<vector<int>> &adj, int start, int find, bool &found, bool vis[]) {
    vis[start] = true;

    //cout << "\n" << start + 1 << "\nadj: ";

    for (int node : adj[start]) {
        //cout << node + 1;
        if (node == find) {
            found = true;
        } else if (!vis[node]) {
            dfs(adj, node, find, found, vis);
        }
    }
}
//endtemplate DFS