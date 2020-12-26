#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL);

    int n, c;
    cin >> n;
    int sum = 0;
    while (n--) {
        cin >> c;
        sum += c;
    }

    cout << sum;
    
    return 0;
}