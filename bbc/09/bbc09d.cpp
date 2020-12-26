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
ull arr[100000], rev[100000];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, temp;
    ull m = 0;
    cin >> n;

    loop(i, n) {
      cin >> temp;
      arr[i] = temp;
    }

    sort(arr, arr+n);

    copy(arr, arr+n, rev);

    reverse(rev, rev+n);

    loop(i, n) {
      m += (arr[i] * rev[i]);
      m %= 10007;
    }

    cout << m << "\n";

        
    return 0;
}
//endtemplate S