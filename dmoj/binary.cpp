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

string format(string s) {
  int size = s.length();
  int m = size % 4;
  if (m == 0) {
    m = 4;
  }
  loop(i, 4-m) {
    s = '0' + s;
  }

  size = s.size();
  string res = "";
  // add in the spaces
  loop(i, size) {
    if (!(i % 4)) {
      res += ' ';
    }
    res += s[i];
  }

  return res;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, cu;
    string c;
    cin >> n;

    loop(_, n) {
      cin >> cu;
      c = bitset<32>(cu).to_string();

      while (c[0] == '0') {
        c.erase(0,1);
      }

      if (c.length() == 0) {
        c = "0";
      }

      cout << format(c); nl;

    }
    
    return 0;
}
//endtemplate S