#include <bits/stdc++.h>
#include <vector>
#include <bitset>
#define loop(i, n) for(int i = 0; i < n; i++)
#define nl cout << "\n"

using namespace std;
bitset<5000001> r, c;

int main() {
    int m, n, k, temp;
    string cmmd;

    cin >> m >> n >> k;

    loop(i, k) {
        cin >> cmmd >> temp;
        if (cmmd == "R") {
            r[temp] = !r[temp];
        } else {
            c[temp] = !c[temp];
        }
    }

    cout << r.count()*(n-c.count()) + c.count()*(m-r.count()); nl;




}
