
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

ll dp[1000001];
ll arr[1000001];

int deal2(int a, int b) {
    return max(a,b) + (min(a,b)*0.75);
}

int deal3(int a, int b, int c) {
    int m = min(a,min(b,c));
    return (a+b+c-m) + (m*0.5);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    loop(i, n){
        cin >> arr[i];
    }

    dp[0] = arr[0];
    dp[1] = deal2(arr[0], arr[1]);

    int d2, d3, d;

    loopfrom(2, i, n) {
        d = arr[i] + dp[i-1];
        d2 = deal2(arr[i-1], arr[i]) + dp[i-2];
        if (i >= 3) {
            d3 = deal3(arr[i], arr[i-1], arr[i-2]) + dp[i-3];
        } else {
            d3 = deal3(arr[i], arr[i-1], arr[i-2]);
        }
        //cout << "Vals:" << d << " " << d2 << " " << d3; nl;
        dp[i] = min(d2, min(d3, d));
    }

    cout << dp[n-1]; nl;
    //printarrn(dp, n);
    //printarrn(arr, n);

    //cout << deal3(40, 1000, 1000); nl;



    return 0;
}
