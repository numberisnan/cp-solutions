//begintemplate S
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define INFint numeric_limits<int>::max()

using namespace std;
int arr[1000][1000];

int bfs(vector<vector<int>> &adj, int start, int find) {
    if (arr[start][find]) {
      return arr[start][find];
    }
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
            if (vis[node] == -1) {
                if (node == find) {
                  arr[start][find] = vis[c]+1;
                  return vis[c]+1;
                }
                q.push(node);
                vis[node] = vis[c]+1;
            }
        }
    }
    arr[start][find] = -1;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<vector<int>> adj;

    int n, m, t, from, to, q, qfrom, qto, res;
    cin >> n >> m >> t;

    adj.resize(n);

    loop(i, m) {
      cin >> from >> to;
      adj[from-1].push_back(to-1);
    }

    cin >> q;

    loop(i, q) {
      cin >> qfrom >> qto;
      res = bfs(adj, qfrom-1, qto-1);
      if (res != -1) {
        cout << res * t << "\n";
      } else {
        cout << "Not enough hallways!\n";
      }
    }

    return 0;
}
//endtemplate S