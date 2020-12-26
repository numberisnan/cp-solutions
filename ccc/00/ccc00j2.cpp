
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

int nthDigit(int n, int d) {
    return int(n/pow(10, d))%10;
}

bool isRotatable(int n) {
    int ndigits;
    loop(i, 16) {
        if (pow(10, i) > n) {
            ndigits = n;
            break;
        }
    }

    int r, l;
    loop(i, ndigits/2) {
        r = nthDigit(n, i);
        l = nthDigit(n, ndigits-i-1);
        if ((r == 6 && l == 9) || (r == 9 && l == 6) || (r == 1 && l == 1) || (r == 0 && l == 0) || (r == 8 && l == 8)) {

        } else {
            cout << l << r; nl;
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int from, to;
    cin >> from >>  to;

    int count = 0;
    loopfrom(from, i, to+1) {
        if (isRotatable(i)) {
            count++;
            //cout << i; nl;
        }
    }

    cout << count; nl;

    return 0;
}
