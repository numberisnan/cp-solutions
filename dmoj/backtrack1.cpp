//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INFint numeric_limits<int>::max()

using namespace std;
ll arr[100];

ll pal(int n) {
  if (n == 1) {
    return 1;
  }

  if (arr[n]) {
    return arr[n];
  }
  ll total = 1;
  for (int i = 1; i <= floor(n / 2); i++) {
    total += pal(n - (2*i));
  }


  arr[n] = total;
  return total;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    fill_n(arr, 100, 0);

    int n;
    cin >> n;
    cout << pal(n);


    return 0;
}
//endtemplate S