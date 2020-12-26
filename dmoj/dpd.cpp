//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

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

//ll dp[101][100001];
ll dp[2][100001];
ll v[100], w[100], n, maxw;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n >> maxw;

    loop(i, n) {
        cin >> w[i] >> v[i];
    }

    fill_n(dp[0], 0, 100001);

    loopfrom(1, N, n+1) {
        dp[1][0] = 0;
        loopfrom(1, W, maxw+1) {
            if (w[N-1] > W) {
                dp[1][W] = dp[0][W];
            } else {
                dp[1][W] = max(dp[0][W], v[N-1] + dp[0][W - w[N-1]]);
            }

            //cout << dp[N][W] << " ";
        }
        //nl;

        copy_n(dp[1], 100001, dp[0]);

    }

    cout << dp[1][maxw];nl;
    
    return 0;
}
//endtemplate S