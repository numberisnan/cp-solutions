
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
#define NINF(type) numeric_limits<type>::min()

using namespace std;

int arr[500001];

ll minchanges(int* arr, int n, bool reverse) {
    if (*arr == INF(int)) {
        return 0;
    }

    if (n == 1) {
        return 0;
    }
    int maxi;
    int* me;
    ll total = 0;
    vector<pair<int, int>> v;
    //printarrn(arr, n);

    loop(i, n-1) {
        v.push_back({arr[i],-(n-i)});
    }

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second; nl;
    } nl;

    while(n > 0) {
        while (-v[0].second > n) {
            v.erase(v.begin());
        }
        me = arr+(n+v[0].second);
        cout << "me: " << *me << " " << v[0].second; nl;

        //cout << *me; nl;
        for (int* p = arr; p < me; p++) {
            total += *me - *p;
        }

        n -= (n+v[0].second) + 1;
        arr = me+1;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m = NINF(int), mi;
    cin >> n;

    loop(i, n) {
        cin >> arr[i];
        if (arr[i] > m) {
            m = arr[i];
            mi = i;
        }
    }

    arr[n] = INF(int);

    int* down = arr+mi+1;
    reverse(arr, arr+mi);

    ll totalchanges = minchanges(down, n-mi-1, true);
    totalchanges += minchanges(arr, mi, false);

    cout << totalchanges; nl;


    return 0;
}
