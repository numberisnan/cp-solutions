
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

int d[100];
int ans[100];
set<int> remain;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    bool possible;

    loop(cas, 5) {
        remain.clear();
        possible = true;

        cin >> n;
        loop(i, n) {
            cin >> d[i];
            remain.insert(i+1);
        }

        loop(i, n) {
            if (d[i] >= remain.size()) {
                possible = false;
                break;
            }
            auto card = remain.rbegin();
            advance(card, d[i]);
            ans[i] = *card;
            remain.erase(*card);
        }

        if (possible) {
            printarrn(ans, n);
        } else {
            cout << "IMPOSSIBLE"; nl;
        }
    }

    return 0;
}
