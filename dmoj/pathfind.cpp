//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INFint numeric_limits<int>::max()

using namespace std;
vector<unordered_set<int>> blocks;
vector<unordered_set<int>> vis;
//int arr[1000000];

struct coord {
  int r, c;
};

bool dfs(coord bounds, coord start) {
  //blocks[start.r].insert(start.c);
  //cout << "Searching: " << start.r << " " << start.c; nl;

  if (start.r == bounds.r || start.c == 1) {
    return true;
  }
  bool found = false;

  int r = start.r, c = start.c;
  coord s[] = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}, {r+1, c+1}, {r+1, c-1}, {r-1, c+1}, {r-1, c-1}};
  for (auto next : s) {
    if (vis[next.r].find(next.c) == vis[next.r].end() && next.r > 0 && next.c > 0 && next.r <= bounds.r && next.c <= bounds.c && blocks[next.r].find(next.c) != blocks[next.r].end()) {
      vis[next.r].insert(next.c);
      if (dfs(bounds, {next.r, next.c})) {
        found = true;
        break;
      }
    }
  }

  return found;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, k, c, r;
    cin >> n >> m >> k;

    blocks.resize(m+1);
    vis.resize(m+1);

    loop(i, k) {
      cin >> c >> r;
      blocks[r].insert(c);
    }
    
    bool res = false;
    for (auto start : blocks[1]) {
      //cout << "Start: " << start; nl;
      res |= dfs({n, m}, {1, start});
    }

    if (!res) {
      for (int i = 1; i <= m; i++) {
        //cout << "Start: " << start; nl;
        if (blocks[i].find(n) != blocks[i].end()) {
          res |= dfs({n, m}, {i, n});
        }
      }
    }

    cout << (!res ? "YES" : "NO");

    return 0;
}
//endtemplate S
