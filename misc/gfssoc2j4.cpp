
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

int arr[500001];

int qe(int a, int b) {
    if (a > b) {
        swap(a,b);
    }

    if (!a) {
        return arr[b];
    } else {
        return arr[b] - arr[a-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    loop(i, n) {
        cin >> arr[i];
        if (i) {
            arr[i] += arr[i-1];
        }
    }

    int a, b;

    //printarrn(arr, n);

    loop(i, q) {
        cin >> a >> b;
        cout << arr[n-1] - qe(a-1,b-1); nl;
    }

    //cout << qe(1,3); nl;

    return 0;
}
