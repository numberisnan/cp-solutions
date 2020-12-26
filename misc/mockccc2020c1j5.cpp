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
#define INF(type) numeric_limits<type>::max()


using namespace std;
//int arr[1000000];

bool isPrime(ll n) {
  if (n == 0 || n == 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (!(n % i)) {
      return false;
    }
  }
  return true;
}

int digits(ll n) {
  if (n < 10) {
    return 1;
  }
  return digits(n / 10) + 1;
}

ll nextPrime(int d, ll n) {
  ll next = max(n, (ll)(pow(10, d-1)));
  while (!isPrime(next)) {
    next++;
  }

  return next;

}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll d, nval, n, f, s, res = INF(ll);
    cin >> d >> nval;
    n = max(digits(nval), (int)d*2);
    //cout << n; nl;

    for (ll i = d; i <= n - d; i++) { // i is the first digit of the second prime
      if (isPrime(nval / (ll)pow(10, n-i))) {
        f = nval / (ll)pow(10, n-i);
        s = nextPrime(n - i, nval % (ll)pow(10, n-i));
      } else {
        f = nextPrime(i, nval / (ll)pow(10, n-i));
        s = nextPrime(n - i, 0);
      }
      //cout << nval / (int)pow(10, n-i) << " , " << nval % (int)pow(10, n-i); nl;
      //cout << "ac :" << f << " , " << s; nl;
      res = min(res, (f * (ll)pow(10, digits(s))) + s);
    }

    cout << res; nl;
    //cout << nthdigitfromleft(12435, 2);
    //cout << nextPrime(4); nl;
    //printPrimes();
    
    return 0;
}
//endtemplate S