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
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t, n, a;
    ll v;
    cin >> t;

    loop(tc, t) {
      cin >> n >> k;
      vector<pair<int, int>> arr;
      loop(i, n) {
        cin >> a;
        arr.push_back({a, a});
        
      }


    }
    
    return 0;
}
//endtemplate S