//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INFint numeric_limits<int>::max()

using namespace std;
pair<int, int> arr[10000000];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, temp;
    cin >> n;

    loop(i, n) {
      cin >> temp;
      arr[i] = { temp % 10, 1000000 - temp};
    }

    sort(arr, arr+n);

    loop(i, n) {
      cout << 1000000 - arr[i].second << " ";
    }
    
    return 0;
}
//endtemplate S