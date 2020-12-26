//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF 10e9;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n[6][6];
    char c;

    loop(i, 6) {
      loop(j, 6) {
        loop(k, 6) {
          c = getchar();
          if (c == 'R') {
            n[i][j] |= (1<<k);
          } else {
            n[i][j] &= ~(1<<k);
          }
        }
      }
    }

    loop(i, 6) {
      loop(j, 6) {
        loop(k, 6) {
          
        }
      }
    }

    
    return 0;
}
//endtemplate S