
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
int dp[3001][3001];
string a, b;

string trace(int i, int j) {
    if (!i || !j) {
        return "";
    }
    if (b[i] == a[j]) {
        return b[i] + trace(i-1, j-1);
    }
    if (dp[j-1][i] >= dp[j][i-1]) {
        return trace(i, j-1);
    } else {
        return trace(i-1, j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int la = a.length(), lb = b.length(); //rows are a, columns are b

    loopfrom(1, i, lb) {
        loopfrom(1, j, la) {
            if (b[i] == a[j]) {
                dp[j][i] = dp[j-1][i-1]+1;
            } else {
                if (dp[j-1][i] >= dp[j][i-1]) {
                    dp[j][i] = dp[j-1][i];
                } else {
                    dp[j][i] = dp[j][i-1];
                }
            }
        }
    }

    // trace the LCS


    string ans = trace(lb-1, la-1);
    reverse(ans.begin(), ans.end());
    cout << ans;nl;

    return 0;
}
