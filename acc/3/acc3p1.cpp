//begintemplate S
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")


#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";

using namespace std;
int dp[1000001];
int arr[1000001];
bitset<1000001> enc; // 1-indexed

int main() {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL);
    
    int n, k, total = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (enc[arr[i]]) {
            // duplicate
            dp[i] = dp[i-1];
        } else {
            enc[arr[i]] = 1;
            if (i == 0) {
                dp[i] = 0;
            } else {
                set<int> found;
                int j;
                for (j = i; j > -1; j--) {
                    found.insert(arr[j]);
                    if ((int)found.size() >= k) {
                        //cout << "j: " << j << " i: " << i; nl;
                        break;
                    }
                }
                dp[i] = j + 1;
            }
        }

        total += dp[i];
    }
    
    //printarrn(dp, n);
    if (n == 1 && k == 1) {
        cout << 1;
        nl;
    } else {
        cout << total;
        nl;
    }
    

    return 0;
}
//endtemplate