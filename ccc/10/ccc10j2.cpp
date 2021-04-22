
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

int total(int a, int b, int s) {
    int ta = 0;
    int sa = s;
    while (sa > 0) {
        ta += a;
        sa -= a;
        if (sa < 0) {
            ta -= 0-sa;
            break;
        }
        ta -= b;
        sa -= b;
        if (sa < 0) {
            ta += 0-sa;
            break;
        }
    }

    return ta;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d,s;

    cin >> a >> b >> c >> d >> s;

    int ta = total(a,b,s);
    int tc = total(c,d,s);

    //cout << ta; nl;
    //cout << tc; nl;

    if (tc == ta) {
        cout << "Tied"; nl;
    } else if (tc < ta) {
        cout << "Nikky"; nl;
    } else {
        cout << "Byron"; nl;
    }

    return 0;
}
