#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int l, w, t;

    cin >> l >> w >> t;

    cout << int (l / t) * int (w / t);

    return 0;
}