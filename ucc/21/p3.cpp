#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define nl cout << "\n";

using namespace std;

int pizza[10000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r, q, a, b;
    cin >> n >> l >> r >> q;

    loop(i, q) {
        cin >> a >> b;
        pizza[a]++;
        pizza[b+1]--;
    }

    int curr = 0;
    long long s = 0;
    loopfrom(1, i, l) {
        curr += pizza[i];
        //cout << curr; nl;
    }
    loopfrom(l, i, r+1) {
        curr += pizza[i];
        //cout << curr; nl;
        s += curr;
    }

    cout << s; nl;
    loopfrom(1, i, n+1) {
        //cout << pizza[i]; nl;
    }

    return 0;
}
