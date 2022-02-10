
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>


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
queue<pair<int, int>> sq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, top, bottom;
    ll total = 0;
    float a;
    cin >> n >> m;
    a = (float)n/m;

    loop(i, m) {
        bottom = floor((float)a*i);
        top = ceil(a*(float)(i+1));
        //cout << top << " " << bottom; nl;
        loopfrom(bottom, j, top) {
            sq.push({i, j});
            total++;
        }
    }

    cout << total; nl;
    while (sq.size()) {
        cout << sq.front().second+1 << " " << sq.front().first+1; nl;
        sq.pop();
    }



    return 0;
}
