
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

int dp[1000][1000];
short arr[1000];
int res;

int state(int l, int r) {
    if (dp[l][r]) {
        return dp[l][r];
    }
    if (l == r) {
        return arr[r];
    }
    res = max(arr[r] - state(l, r-1), arr[l] - state(l+1, r));
    dp[l][r] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;
    cin >> n;

    loop(i,n) {
        cin >> arr[i];
        sum += arr[i];
    }

    int minus = state(0, n-1);

    cout << (minus + sum)/2; nl;

    return 0;
}
