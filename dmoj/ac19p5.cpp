
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

int maxdis[1500][1500];
int val[1500][1500];
vector<pair<int, int>> graph[1500][1500];

int fill(int r, int c) {
    if (maxdis[r][c]) {
        return maxdis[r][c];
    }
    int m = 0;
    for (auto next : graph[r][c]) {
        m = max(m, fill(next.first, next.second) + 1);
    }

    maxdis[r][c] = m;
    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    loop(r, n) {
        loop(c, n) {
            cin >> val[r][c];
        }
    }

    pair<int, int> moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    loop(r, n) {
        loop(c, n) {
            for (auto move : moves) {
                if (r+move.first >= 0 && r+move.first < n && c+move.second >= 0 && c+move.second < n && val[r+move.first][c+move.second] > val[r][c]) {
                    graph[r][c].push_back({r+move.first, c+move.second});
                }
            }
        }
    }

    int m = 0;
    loop(r, n) {
        loop(c, n) {
            m = max(m, fill(r, c));
        }
    }

    cout << m; nl;



    return 0;
}
