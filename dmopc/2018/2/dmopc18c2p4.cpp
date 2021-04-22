
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

int d[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll temp = 0, n, m;
    cin >> n >> m;

    loop(i,n) {
        cin >> d[i];
        temp += d[i];
    }

    if (temp < m) {
        cout << "-1"; nl;
        return 0;
    }

    int p1 = -1, p2 = 0;
    ll sum = 0;
    int si = 1000000;

    while (p1 < n) {
        //cout << "sum: " << sum; nl;
        if (sum < m) { // too small
            p1++;
            sum += d[p1];
        } else { // includes sum == m
            if (si > p1-p2) {
                si = p1-p2;
                //cout << p1 << " " << p2; nl;
            }
            sum -= d[p2];
            p2++;
        }
    }

    cout << si + 1; nl;

    return 0;
}
