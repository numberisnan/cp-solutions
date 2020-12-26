//begintemplate S
#pragma GCC optimize("O2")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define INFint numeric_limits<int>::max()

using namespace std;

int add(int a, int b) {
  return (a + b) % (1000000007);
}

int powers[500000] = {1};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, l, r, ans = 0;
    string temp;
    set<int> s;

    cin >> n >> m;
    for(int i = 1; i < n; i++) {
      powers[i] = add(powers[i-1], powers[i-1]);
    }

    reverse(powers, powers + n);
    cin >> temp;
    loop(i, n) {
      if (temp[i] == '1') {
        ans = add(ans, powers[i]);
      } else {
        s.insert(i);
      }
    }

    auto v = s.begin();
    auto p = v;

    loop(i, m) {
      cin >> l >> r;
      l--;
      r--;
      v = s.begin();
      while (*v < l && v != s.end()) {
        v++;
      }

      while (*v <= r && v != s.end()) {
        ans = add(ans, powers[*v]);
        p = v;
        v++;
        s.erase(p);
      }

      cout << ans << "\n";
    }


    
    return 0;
}
//endtemplate S