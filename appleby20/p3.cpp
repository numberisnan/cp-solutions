
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

int prefix[10001][116];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, T;

    cin >> s >> T;
    string pre, str;

    cin >> pre >> str;

    loop(i, 10001) {
        loop(j, 116) {
            prefix[i][j] = -1;
        }
    }

    loopfrom(1, i, s) {
        if (prefix[0][(int)pre[i]] == -1) {
            prefix[0][(int)pre[i]] = i;
        }
    }

    printarrn(prefix[0], 116); nl;

    loopfrom(1, i, s) {
        loop(n, 116) {
            prefix[i][n] = prefix[i-1][n];
        }
        /*if (prefix[i][(int)pre[i]] == i) {
            int j = i+1;
            while (pre[j] != pre[i] && j < s) {
                j++;
            }

            if (j == s-1 && pre[j] != pre[i]) {
                prefix[i][(int)pre[i]] = -1;
            } else {
                prefix[i][(int)pre[i]] = j;
            }
        }*/
        printarrn(prefix[i], 116); nl;
    }

    return 0;
}
