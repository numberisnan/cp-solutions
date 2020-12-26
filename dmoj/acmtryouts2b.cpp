
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
ll lane[1002];
ll l;

void clear() {
    fill_n(lane, 1002, 0);
}

int binsearch(int s) {
    int le = 0;
    int r = l;
    int mid;

    while (le <= r) {
        mid = int((le+r)/2);
        if (lane[mid] > s) {
            r = mid - 1;
        } else if (lane[mid] < s) {
            le = mid + 1;
        } else {
            return mid;
        }
    }

    return min(le, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    loop(tc, cases) {
        clear();

        ll n;
        cin >> l >> n;

        ll c, r, d, toadd;
        loop(i, n) {
            cin >> c >> r >> d;
            toadd = 0;
            loopfrom(max(c-r, (ll)1), i, min(c+r+1, l+1)) {
                toadd += d;
                lane[i] += toadd;
            }
            loopfrom(min(c+r+1, l+1), i, l+1) {
                lane[i] += toadd;
            }
        }

        lane[l+1] = INF(ll);

        //printarrn(lane, l+1);

        ll m, h, res;
        cin >> m;
        //cout << l; nl;
        //cout << lane[l]; nl;
        loop(i, m) {
            cin >> h;
            //cout << h; nl;
            res = binsearch(h);
            while (lane[res] < h) {
                res++;
            }
            if (res == l+1) {
                cout << "Bloon leakage"; nl;
            } else {
                cout << res; nl;
            }

        }
    }

    return 0;
}
