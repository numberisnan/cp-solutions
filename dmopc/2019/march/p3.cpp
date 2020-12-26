#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m, l, r, sum;
    
    string numb;
    
    cin >> n >> m;
    
    vector<int> sums;
    bool number[n];
    cin >> numb;

    for (int i = 0; i < n; i++) {
        number[i] = (numb[i] == '1');
    }

    while (m--) {
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            number[i-1] = true;
        }
        /*
        for (bool v : number) {
            cout << v;
        }

        cout << "\n";
        */
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += number[i] ? pow(2, (float)n-i-1) : 0;
        }

        sum %= 1000000007;
        if (sum) {
            sums.push_back(sum);
        }
    }

    for (int v : sums) {
        cout << v << "\n";
    }
    
    return 0;
}