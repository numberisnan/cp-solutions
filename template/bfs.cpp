#include <queue>
#include <vector>

using namespace std;

//begintemplate BFS
int bfs(vector<vector<int>> adj, int start, int find) {
    int n = adj.size();
    queue<int> q;
    int vis[n];

    fill_n(vis, n, -1);
    q.push(start);
    vis[start] = 0;

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (int node : adj[c]) {
            if (!vis[node]) {
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
//endtemplate BFS
