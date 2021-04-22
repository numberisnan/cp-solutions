
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

struct bully {
    int x, y, s;
};

vector<bully> u[1001], d[1001], l[1001], r[1001];
ll dp[1001][1001];

int manhat(int x, int y) {
    return x + y - 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, y, x, s;
    string dir;
    cin >> n >> m >> k;

    loop(i, k) {
        cin >> y >> x >> s >> dir;
        if (dir == "R") {
            r[y].push_back({x, y, s});
        } else if (dir == "L") {
            l[y].push_back({x, y, s});
        } else if (dir == "U") {
            u[x].push_back({x, y, s});
        } else { // d
            d[x].push_back({x, y, s});
        }
    }

    bool c;

    loop(i, 1001) {
        fill_n(dp[i], 1001, 0);
    }

    loopfrom(1, i, n+1) {
        loopfrom(1, j, m+1) {
            c = true;
            for (bully b : r[i]) {
                if (b.x+(b.s*(manhat(i,j)-1)) <= j) {
                    c = false;
                    break;
                }
            }

            for (bully b : l[i]) {
                //cout << b.x-(b.s*manhat(i,j)) << " " << j; nl;
                if (b.x-(b.s*(manhat(i,j)-1)) >= j) {
                    c = false;
                    break;
                }
            }

            for (bully b : u[j]) {
                if (b.y-(b.s*(manhat(i,j)-1)) >= i) {
                    c = false;
                    break;
                }
            }

            for (bully b : d[j]) {
                if (b.y+(b.s*(manhat(i,j)-1)) <= i) {
                    c = false;
                    break;
                }
            }

            if (c) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
            if (i == 1 && j == 1 && c) {
                dp[i][j] = 1;
            }
            //cout << i << " " << j << " : " << dp[i][j] << " " << c; nl;
            //cout << dp[i-1][j]; nl;
        }
    }

    cout << dp[n][m]; nl;

    return 0;
}
