#include <bits/stdc++.h>

using namespace std;
#define nl cout << "\n"

int main() {
    int n, ma, temp, m = 1000000, ind = -1;
    
    cin >> n >> ma;
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < ma; j++) {
            cin >> temp;
            //cout << temp; nl;
            if (temp == 1 || temp == 10) {
                count++;
            }
        }

        //cout << i << " : " << count; nl;
        
        if (count < m) {
            ind = i + 1;
            m = count;
        }
    }
    
    cout << ind;
}