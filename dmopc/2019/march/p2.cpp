#include <bits/stdc++.h>
#include <vector>
#include <utility> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int a, b, total = 0, minisums, minisuml;
    
    cin >> a >> b;

    int nums[b];
    for (int i = 1; i <= b; i++) {
        nums[i-1] = i;
    }

    //factor b
    vector<pair<int, int>> factors;
    for (int i = 2; i <= pow(a, 0.5); i++) {
        if (!(a%i)) {
            factors.emplace_back(max(i, a / i), min(a / i, i));
        }
    }

    /*
    for (auto f : factors) {
        cout << f.first << " " << f.second << "\n";
    }
    */

    for (auto fac : factors) {
        minisuml = 0;
        minisums = 0;
        for (int i = 0; i < b; i++) {
            while (!(nums[i] % fac.first)) {
                nums[i] /= fac.first;
                minisuml++;
            }
            while (!(nums[i] % fac.second)) {
                nums[i] /= fac.second;
                minisums++;
            }  
        }
        total += min(minisuml, minisums); 
    }

    cout << total;
    
    return 0;
}