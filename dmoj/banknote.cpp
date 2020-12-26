#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF 10000000



using namespace std;

int value[20001];
int cnt[20001];
int dp[20001]; // dp[x] is number of bills needed to make x
int indexmap[20001];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    int inp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        value[i] = inp;
        indexmap[inp] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> cnt[i];
    }
    cin >> k;

    int freq[k+1][n+1];

    dp[0] = 0;
    fill_n(freq[0], n, 0);
    pair<int, int> minCoin; // index and assumed value of dp[i] if that coin is selected
    
    for (int i = 1; i <= k; i++) { // For each value in dp
        dp[i] = INF;
        fill_n(freq[i], n, INF);
        minCoin = {INF, INF};
        for (int ci = 0; ci < n; ci++) {
            int c = value[ci];
            if (i-c >= 0 /* so i is not negative */) {
                /*if (i == k) {
                    cout << "minCoin " << minCoin.second << " " << dp[i-c]+1 << "   " << freq[i-c][ci] << " " << cnt[c];
                    nl; 
                }*/
                if (dp[i-c] != INF && minCoin.second > dp[i-c]+1 && freq[i-c][ci] < cnt[ci]) {
                    minCoin = pair<int,int>(c,dp[i-c]+1);
                }
            }
        }
        if (dp[i] > minCoin.second) {
            dp[i] = minCoin.second;
            copy_n(freq[i-minCoin.first], n, freq[i]);
            freq[i][indexmap[minCoin.first]]++;
        }
    }

    cout << dp[k];
    /*
    nl;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            cout << freq[i][j] << " ";
        }
        cout << ": " << dp[i];
        nl;
    }*/

    return 0;
}