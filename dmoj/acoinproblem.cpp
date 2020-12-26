#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF 10000000

using namespace std;

bool sortbyindex = false;
struct store {
    int i, c, l, res;
};

bool operator<(const store& lhs, const store& rhs)
{
    if (sortbyindex) {
        return lhs.i < rhs.i;
    } else {
        return (lhs.l == rhs.l ? lhs.c > rhs.c : lhs.l < rhs.l);
    }
}

int coins[2000];
vector<store> stores;
int dp[2][10001];

void advancedp() {
    copy_n(dp[1],10001, dp[0]);
    fill_n(dp[1], 10001, 0);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, v, c, l;
    cin >> n >> v;

    loop(i, n) {
        cin >> coins[i];
    }

    //printarrn(coins, n);

    loop(i, v) {
        cin >> c >> l;
        stores.push_back({i, c, l, -1});
    }

    sort(stores.begin(), stores.end());

    int pos = 0;
    vector<int> ls;
    fill_n(dp[0], 10001, INF);
    for (int lval = 1; lval < 2001; lval++) {
        ls.push_back(coins[lval-1]);
        if (stores[pos].l > lval) continue;
        //printarrn(ls, ls.size());
        // calc dp;
        //cout << stores[pos].c; nl;
        loopfrom(1, i, 10001) {
                int m = INF;
                for (auto c : ls) {
                    if (c <= i) {
                        m = min(m, dp[1][i-c]+1);
                    }
                }
                dp[1][i] = min(m, dp[0][i]);
        }

        //printarrn(dp[1], stores[pos].c+1); nl;

        while (stores[pos].l == lval) {
            if (dp[1][stores[pos].c] >= INF) {
                stores[pos].res = -1;
            } else {
                stores[pos].res = dp[1][stores[pos].c];
            }
            pos++;
        }

        ls.clear();
        advancedp();
    }

    sortbyindex = true;

    sort(stores.begin(), stores.end());

    for (store s : stores) {
        cout << s.res; nl;
    }

    return 0;
}