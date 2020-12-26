//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <vector.h>

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
const int psize = 10000001;
vector<int> primes = {2};
short p[psize];

void popPrimes() {
  fill_n(p, psize, 0);
  for (int i = 2; i < psize; i++) {
    if (!p[i]) {
      for (int j = i; j < psize; j += i) {
        p[j]++;
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    popPrimes();

    //printarrn(p, 10);

    int c, a, b, k, count;
    cin >> c;
    loop(casen, c) {
      cin >> a >> b >> k;
      count = 0;
      loopfrom(a, i, b+1) {
        if (p[i] == k) {
          count++;
        }
      }

      cout << "Case #" << casen+1 << ": " << count; nl;
    }

    return 0;
}
//endtemplate S