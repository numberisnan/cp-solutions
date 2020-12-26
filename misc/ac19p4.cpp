//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define INFint numeric_limits<int>::max()

using namespace std;
vector<int> ind[20001]; // sorted by x value
vector<pair<int, int>> arr;

int makeRect(int a, int b, int c) {
  /* a     b
     
     c
  */

  if (arr[a].first == arr[b].first && arr[a].second == arr[c].second && find(ind[arr[b].first].begin(), ind[arr[b].first].end(), arr[c].second) != ind[arr[b].first].end()) {
    int x = abs(arr[b].first - arr[a].first);
    int y = abs(arr[a].second - arr[c].second);

    return x * y;
  }

  return -1;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, x, y;
    int m = -1;
    cin >> n;

    loop(i, n) {
      cin >> x >> y;
      arr.push_back({x, y});
      ind[x].push_back(y);
    }

    loop(p1, n) {
      loop(p2, n) {
        if (p1 == p2) {
          continue;
        }
        loop(p3, n) {
          m = max(m, makeRect(p1, p2, p3));
        }
      }
    }

    cout << m;

    
    return 0;
}
//endtemplate S