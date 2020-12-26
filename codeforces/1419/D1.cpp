
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <queue>

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
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    cin >> n;

    loop(i, n) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    queue<int> fir, sec;

    loop(i, n) {
        if (i < (n/2)) {
            fir.push(v[i]);
        } else {
            sec.push(v[i]);
        }
    }

    if (n <= 2) {
        cout << 0; nl;
    } else if (n % 2 == 0) {
        cout << fir.size() - 1; nl;
    } else {
        cout << fir.size(); nl;
    }


    while (!fir.empty()) {
        cout << sec.front() << " " << fir.front() << " ";
        sec.pop();
        fir.pop();
    }
    if (sec.size()) {
        cout << sec.front(); nl;
    } else {
        nl;
    }

    return 0;
}
