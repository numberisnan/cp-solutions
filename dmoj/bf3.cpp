//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define INFint numeric_limits<int>::max()

using namespace std;
int arr[1000000];

bool isPrime(ll n) {
  if (n == 1) {
    return false;
  }
  for (int i = 2; i < sqrt(n); i++) {
    if (!(n % i)) {
      return false;
    }
  }

  return true;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin >> n;

    while (!isPrime(n)) {
      n++;
    }

    cout << n;
    nl;
    

    
    return 0;
}
//endtemplate S