//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

// From https://dmoj.ca/tips/
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INF(type) numeric_limits<type>::max()

using namespace std;
int factarr[1000002];
const int MOD = 10000007;

int fact(int n) {
  if (n == 1) {
    return 1;
  }
  if (!factarr[n]) {
    int res = (fact(n-1) * n) % MOD;
    factarr[n] = res;
    return res;
  } else {
    return factarr[n];
  }
}

int goodpaths(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 2;
  } else {
    return (((n-1)*(n-2))/2) % MOD;
  }
}

int allpaths(int n) {
  int sum = 0;
  for (int i = 2; i <= n; i++) {
    sum += fact(i);
    sum %= MOD;
  }

  return sum;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    fill_n(factarr, 1000002, 0);

    int n, temp;
    cin >> n;
    loop(i, n) {
      cin >> temp;
      cout << allpaths(temp);nl;
      cout << goodpaths(temp);nl;
      cout << allpaths(temp) - goodpaths(temp); nl; nl;
    }
    
    return 0;
}
//endtemplate S