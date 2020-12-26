
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C, s;
    string inp;
    ll total = 0;
    cin >> R >> C >> s;
    int cc[C], cr[R];
    fill_n(cc, C, 0);
    fill_n(cr, R, 0);

    if (s > R) {
        s = R;
    }

    if (s > C) {
        s = min(s, C);
    }

    loop(i, R-s+1) {
        loop(a, s) {
            if (i+a < R) {
                cr[i + a]++;
                //cout << i+a; nl;
            }
        }
    }

    //printarrn(cr, R);
    loop(i, C-s+1) {
        loop(a, s) {
            if (i+a < C) {
                cc[i + a]++;
                //cout << i+a; nl;
            }
        }
    }

    loop(r, R) {
        cin >> inp;
        loop(c, C) {
            //cout << min(min(s, r+1), R-r) << " " << min(min(s, c+1), C-c); nl;
            if (inp[c] == 'X') {
                total += cc[c] * cr[r];
                //cout << cc[c] * cr[r]; nl;
            }
        }
    }

    cout << total/((R-s+1)*(C-s+1)); nl;

    return 0;
}
