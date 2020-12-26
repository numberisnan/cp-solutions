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
//int arr[1000000];
ull y, t;
double p;

ull getEstForN(int p, ull y, ull t) {
  double P = ((double)p/100) + 1;
  double psum = 0;

  for (ull i = 1; i <= y; i++) {
    psum += pow(P, i);
  }

  return t / psum;
}

ull getAcc(int p, ull y, ull n) {
  double P = ((double)p/100) + 1;
  ull total = 0;
  for (ull i = 1; i <= y; i++) {
    total += n;
    total *= P;
  }

  return total;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  ull y, t;
  int p;
  cin >> p >> y >> t;

  ull n = getEstForN(p, y, t);

  cout << "init " << n; nl;

  ull res = getAcc(p, y, n);

  while (res < t) {
    cout << res;nl;
    n++;
    res = getAcc(p, y, n);
  }
  cout << n; nl;
  
  return 0;
}
//endtemplate S