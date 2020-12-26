
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
vector<ll> den;
bitset<1000000001> need;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, c, d, total = 0, newcoins = 0;
    bool ne = false;

    cin >> n >> k;

    loop(i, n) {
        cin >> c >> d;
        if (!d) {
            need[c] = 1;
            ne = true;
        }
        den.push_back(c);
    }

    den.push_back(k);
    n++;

    loop(i, n-1) {
        if (!need[den[i]]) continue;
        if (total + den[i] >= den[i+1]) continue;
        total += den[i];
        newcoins++;
    }

    if (ne) {
        cout << newcoins << "\n" << k-total; nl;
    } else {
        cout << "0\n" << k-1;
    }




    return 0;
}