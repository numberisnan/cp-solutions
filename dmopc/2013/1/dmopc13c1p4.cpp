//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

// From https://dmoj.ca/tips/
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << (string)arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INFint 1000000
#define coord pair<int,int>

using namespace std;
bool walls[52][52];
int vis[52][52];

void clearVis() {
  loop(i, 51) {
    fill_n(vis[i], 51, -1);
  }
}

void clearWalls() {
  loop(i, 51) {
    fill_n(walls[i], 51, false);
  }
}

int bfs(coord bounds, coord start, coord find) {
    queue<coord> q;
    q.push(start);
    vis[start.first][start.second] = 0;

    while (!q.empty()) {
        coord curr = q.front();
        int r = curr.first, c = curr.second;
        q.pop();

        coord set[] = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};

        for (coord node : set) {
            if (vis[node.first][node.second] == -1 && node.first > 0 && node.second > 0 && node.first <= bounds.first && node.second <= bounds.second && !walls[node.first][node.second]) {
                if (node == find) {
                  return vis[curr.first][curr.second]+1;
                }
                q.push(node);
                vis[node.first][node.second] = vis[curr.first][curr.second]+1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int cases, r, c;
    string temp;
    coord start;
    coord end;
    cin >> cases;
    loop(cas, cases) {
      clearWalls();
      clearVis();

      cin >> c >> r;

      loop(i, r) {
        cin >> temp;
        loop(j, c) {
          if (temp[j] == 'X') {
            walls[i+1][j+1] = true;
          } else if (temp[j] == 'W') {
            end = {i+1, j+1};
          } else if (temp[j] == 'C') {
            start = {i+1, j+1};
          } else {
            walls[i+1][j+1] = false;
          }
        }
      }
      int dis = bfs({r, c}, start, end);
      cout << (dis < 60 && dis != -1 ? to_string(dis) : "#notworth"); nl;

    }

    return 0;
}
//endtemplate S