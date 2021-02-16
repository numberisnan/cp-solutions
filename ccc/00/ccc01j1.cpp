
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

string output[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    n *= 2;

    int sld = 2;
    int sl = 1;

    loop(i, n) {
        output[i] = "";
        loop(t, n) {
            output[i] += ' ';
        }
        loop(j, sl) {
            output[i][j] = '*';
            output[i][n-j-1] = '*';
        }
        sl += sld;
        if (sl >= n/2) {
            sld = -2;
        }

    }

    loop(i, n/2) {
        cout << output[i];
        if (i != n-1){
            nl;
        }
    }

    return 0;
}
