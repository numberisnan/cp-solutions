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

short freq[1000001];
vector<int> input;

set<int> getFactors(int n) {
  set<int> f;
  for (int i = 1; i <= sqrt(n); i++) {
    if (!(n % i)) {
      f.insert(i);
      f.insert(n / i);
    }
  }

  return f;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    fill_n(freq, 1000001, 0);

    int n, k, temp, total, maxv = 0;
    set<int> fs;

    cin >> n >> k;

    loop(i, n) {
      cin >> temp;
      freq[temp]++;
      input.push_back(temp);
      maxv = max(maxv, temp);
    }

    //cout << maxv; nl;
    
    for (auto t : input) {
      total = 0;
      if (t < k) {
        // pass
      } else if (t == k) {
        for (auto nu : input) {
          if (t % nu == k) {
            total++;
          }
        }
      } else { // t > k
        fs = getFactors(t-k);
        //cout << "Factors for " << t; nl;
        //printarr(fs); nl;
        for (auto f : fs) {
          if (t % f == k) {
            total += freq[f];
            if (t == f) {
              total--;
            }
          }
        }
      }

      cout << total << " ";
    }
    
    return 0;
}
//endtemplate S