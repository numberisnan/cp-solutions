
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <map>
#include <tuple>

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
map<int, int> inc;


void chInc(int key, int i) {
    auto f = inc.find(key);
    if (f == inc.end()) {
        //no such key
        inc.insert({key, i});
    } else {
        f->second += i;
    }
}

void prange(int s, int e, int in) {
    chInc(s, in);
    chInc(e+1, -in);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, s, a, b, spook;

    cin >> n >> l >> s;

    loop(i, n) {
        cin >> a >> b >> spook;
        //cout << a << b << spook; nl;
        prange(a, b, spook);
    }
    prange(1, l, 0);

    ll currsp =  0, candy = inc.begin()->first-1;

    for (auto it = inc.begin(); it != inc.end(); it++) {
        if (it->first == l+1) {
            break;
        }
        currsp += it->second;
        auto next = it; advance(next, 1);
        if (currsp < s) {
            candy += next->first - it->first;
            //cout << (next->first - it->first) << "     " << it->first << "     " << next->first; nl;
        }
    }

    cout << candy; nl;

    return 0;
}
