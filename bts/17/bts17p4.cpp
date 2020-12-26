//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

// From https://dmoj.ca/tips/
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n" << flush;
#define nl cout << "\n" << flush
#define ll long long
#define ull unsigned long long
#define INF(type) numeric_limits<type>::max()

using namespace std;
int puddles[100000];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    fill_n(puddles, 100000, INF(int));
    
    int n, m, j, p, t;
    cin >> n >> m >> j;

    loop(i, m) {
      cin >> p >> t;
      puddles[p] = t;
      //cout << p << " " << t; nl;
    }

    int currp = 0, mintime, mini, globalmaxtime = 0;

    //printarrn(puddles, n+1)

    while (currp <= n) {
      // find min possible tile to jump to
      mintime = INF(int);
      mini = -1;
      for (int i = currp + j; i > currp; i--) {
        //cout << i << " " << n; nl;
        if (i > n) {
          //cout << "hello";
          mini = n+1;
          mintime = 0;
          break;
        }

        if (puddles[i] < mintime) {
          mintime = puddles[i];
          mini = i;
        }
      }
      
      globalmaxtime = max(globalmaxtime, mintime);
      //cout << "Jump to tile " << mini; nl;
      if (mini == -1) {
        break;
      }
      currp = mini;
    }

    cout << (globalmaxtime == INF(int) ? -1 : globalmaxtime);

    return 0;
}
//endtemplate S