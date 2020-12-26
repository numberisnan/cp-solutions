//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF numeric_limits<ll>::max();

using namespace std;
vector<ll> pos[2000000002];
//ll arr[1000000];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n, a, m = 0;

    cin >> n;
    loop(i, n) {
      cin >> a;
      a += 1000000000;
      pos[a].push_back(i);
      //arr[i] = a;

      m = max(m, a);
    }

    ll i = 0;
    ll j = m;
    ll besti, bestj, res, minn = INF;
    while (i < j) {
      if (!pos[i].size()) {
        i++;
        continue;
      }

      if (!pos[j].size()) {
        j--;
        continue;
      }

      res = j - i;

      if (res < minn || (res == minn && (10e7*i) + j < (10e7*besti) + bestj)) {
        minn = res;
        besti = *min_element(pos[i].begin(), pos[i].end());
        bestj = *min_element(pos[j].begin(), pos[j].end());
      }

      if (res > 0) {
        j--;
      } else {
        i++;
      }
    }

    cout << minn << "\n" << besti << " " << bestj;

    
    return 0;
}
//endtemplate S