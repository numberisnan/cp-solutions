//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define INFint numeric_limits<int>::max()

using namespace std;
//int arr[1000000];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, d, inv, hops = INFint;
    cin >> n >> d;
    d = abs(d);

    loop(i, n) {
      cin >> inv;
      if (!(d % inv)) {
        hops = min(hops, d / inv);
      }
    }

    if (hops == INFint) {
      cout << "This is not the best time for a trip.";
    } else {
      cout << hops;
    }

    
    return 0;
}
//endtemplate S