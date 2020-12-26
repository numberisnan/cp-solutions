#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n"
#define INF 5281

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    short d, n, clubs[32], dp[5281]; // store in dp the lest amount of strokes 
    cin >> d >> n;
    for (int i = 0; i < n; i++) {
        cin >> clubs[i];
    }

    //printarr(clubs);

    dp[0] = 0;
    for (int i = 1; i <= d; i++) {
        // Fill in dp[i]
        dp[i] = INF;
        for (int r = 0; r < n; r++) {
            if (i >= clubs[r] && dp[i] > dp[i-clubs[r]]+1) {
                dp[i] = dp[i-clubs[r]]+1;
            }
        }
    }

    if (dp[d] != INF) {
        cout << "Roberta wins in " << dp[d] << " strokes.";
    } else {
        cout << "Roberta acknowledges defeat.";
    }
    

    
    return 0;
}