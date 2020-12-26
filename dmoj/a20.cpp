//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF 10e9;

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL);

    ll n;
    cin >> n;
    string snum;
    ll num;
    vector<pair<ll,ll>> res;
    
    loop(i, n) {
        pair<ll, ll> temp;
        cin >> snum;
        num = stol(snum, 0, 16);
        if (num & (1<<20)) {
            // 20th bit true
            temp.first = num;
            temp.second = num & ~(1<<20);
        } else {
            temp.first = num;
            temp.second = -1;
        }
        
        res.push_back(temp);
    }
    
    loop(i, n) {
      auto r = res[i];
      if (r.second != -1) {
        printf("%08X %08X\n", (unsigned int)r.second, (unsigned int)r.first);
      } else {
        printf("%08X\n", (unsigned int)r.first);
      }
    }

    
    return 0;
}
//endtemplate S