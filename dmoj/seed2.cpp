//begintemplate S
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define INFint numeric_limits<int>::max()

using namespace std;
//int arr[1000000];

int main() {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL);

    bool flag = false;
    string temp;
    ll l = 1;
    ll r = 2000000000;
    ll pos = (l+r)/2;
    cout << pos << "\n" << flush;
    while (!flag) {
      cin >> temp;
      if (!temp.compare("SINKS")) {
        l = pos;
      } else if (!temp.compare("OK")) {
        flag = true;
      } else {
        r = pos;
      }

      pos = (l+r)/2;
      cout << pos << "\n" << flush;
    }

    
    return 0;
}
//endtemplate S