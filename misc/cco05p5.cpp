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

    int n, l, r, prevP = 1, rdis, ldis, toAdd;
    ll total = 0;

    cin >> n;

    loop(i, n) {
      cin >> l >> r;
      rdis = r - prevP;
      ldis = prevP - l;
      if (prevP <= r && prevP >= l) {
          toAdd= (rdis > ldis ? (ldis * 2) + rdis : (rdis * 2) + ldis);
          prevP = (rdis > ldis ? r : l);
      }
      else if (ldis < rdis) {
        // r is closer
        toAdd = rdis;
        //cout << abs(prevP - r) << " :";
        //nl;
        prevP = r;
      } else {
        // l 
        toAdd = ldis;
        //cout << abs(prevP - l) << " :";
        //nl;
        prevP = l;
      }
      total += toAdd + 1;
      //cout << toAdd << " : " << total; nl;
    }

    total--;

    // get to n, n
    total += n - prevP;

    cout << total;
    
    return 0;
}
//endtemplate S