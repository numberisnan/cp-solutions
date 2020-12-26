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
bool walls[22][22];
int vis[22][22];

void clearVis() {
  loop(i, 21) {
    fill_n(vis[i], 21, -1);
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

    int r, c, t, hl = 0;
    string temp;
    coord start;
    coord h[5];
    cin >> r >> c >> t;

    loop(i, r) {
      cin >> temp;
      loop(j, c) {
        if (temp[j] == 'X') {
          walls[i+1][j+1] = true;
        } else if (temp[j] == 'H') {
          h[hl] = {i+1, j+1};
          hl++;
        } else if (temp[j] == 'G') {
          start = {i+1, j+1};
        } else {
          walls[i+1][j+1] = false;
        }
      }
    }

    int mindis = INFint;
    int dis = 0, res = 0;
    coord bounds = {r, c};

    sort(h, h+t);
    do {
      //printarrn(h, t);
      clearVis();
      dis = 0;
      //cout << "searching " << (string)start << (string)h[0] << flush;
      res = bfs(bounds, start, h[0]);
      //cout << res; nl;
      dis += res;
      for (int i = 1; i < t; i++) {
        //cout << "searching " << (string)h[i-1] << (string)h[i];
        clearVis();
        //res = bfs(bounds, h[i-1], h[i]);
        dis += res;
        //cout << res; nl;
      }

      mindis = min(mindis, dis);
      //nl; cout << mindis; nl; nl;
    } while (next_permutation(h, h+t));

    cout << mindis;

    return 0;
}
//endtemplate S