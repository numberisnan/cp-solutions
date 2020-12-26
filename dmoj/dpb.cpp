
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

int dp[100001];
int b[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;

    loop(i, n) {
        cin >> b[i];
    }

    //cout << b[0]; nl;

    fill_n(dp, 100001, 0);

    dp[0] = 0;
    dp[1] = abs(b[0] - b[1]);
    int m;

    //cout << b[0]; nl;

    loopfrom(2, i, n) {
        m = INF(int);
        int count = 0;
        for (int k = i-1; k >= 0; k--) {
            if (count >= K) {
                break;
            }
            m = min(m, abs(b[i] - b[k]) + dp[k]);
            //cout << k << " " << i << " : ";
            count++;
        } //nl;

        dp[i] = m;
    }

    //printarrn(dp, n); nl;
    cout << dp[n-1]; nl;

    return 0;
}
