//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF 10e9;
int vals[200000];

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, x, f;
    ll cost = 0; 
    cin >> n;
    loop(i, n) {
      cin >> vals[i];
    }
    cin >> x >> f;
    loop(i, n) {
      cost += f * floor(vals[i]/(f + x));
      if (vals[i] % (f + x) > x) {
        cost += f;
      }
    }

    cout << cost;

    //nl; printarrn(vals, n);
    return 0;
}
//endtemplate S