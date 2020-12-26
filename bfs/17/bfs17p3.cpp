//begintemplate S
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
//#define coord pair<int, int>

using namespace std;

struct coord {
  int first, second, range, n;
};

ostream& operator << (ostream &os, const coord &s) {
    return (os << "x: " << s.first << " y: " << s.second << " range: " << s.range << "\n");
}

bool coordeq(coord a, coord b) {
  return a.first = b.first && a.second == b.second;
}

int dis(coord a, coord b) {
  return ceil(sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2)));
}

vector<coord> t1, t2;
int vis[3001];

int bfs(vector<coord> &g, int nodes, coord start, coord find) {
    if (coordeq(start, find)) {
      return 0;
    }
    
    fill_n(vis, nodes, INF(int));
    queue<coord> q;
    q.push(start);
    vis[start.n] = 0;

    while (!q.empty()) {
        coord curr = q.front();
        q.pop();

        loop(i, nodes) {
            if (coordeq(g[i],curr)) {
              continue;
            }
            if (vis[i] == INF(int) && dis(curr, g[i]) <= curr.range) {
              //cout << curr << " can pass to " << "\n" << g[i]; nl;
              if (coordeq(g[i], find)) {
                return vis[curr.n]+1;
              }
              q.push(g[i]);
              vis[g[i].n] = vis[curr.n]+1;
            }
        }
    }
    return INF(int);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t1l, t2l, range, x, y;
    coord b1, b2, s1 = {0, 0, 0, -1}, s2 = {0, 0, 0, -1};

    cin >> t1l >> t2l;

    loop(i, t1l) {
      cin >> x >> y >> range;
      t1.push_back({x, y, range, i});
      if (range == 9001) {
        b1 = {x, y, range, i};
      }
      if (s1.second < y) {
        s1 = {x, y, range, i};
      }
    }

    loop(i, t2l) {
      cin >> x >> y >> range;
      t2.push_back({x, y, range, i});
      if (range == 9001) {
        b2 = {x, y, range, i};
      }
      if (s2.second < y) {
        s2 = {x, y, range, i};
      }
    }

    int res1 = bfs(t1, t1l, s1, b1);
    int res2 = bfs(t2, t2l, s2, b2);

    if (res1 == res2) {
      cout << "SUDDEN DEATH"; nl;
    } else if (res1 < res2) {
      cout << "We are the champions!"; nl;
    } else {
      cout << ":'("; nl;
    }

    //printarrn(t1, t1l);
    //printarr(t2);
    //cout << dis(s2, t2[3]);
    
    return 0;
}
//endtemplate S