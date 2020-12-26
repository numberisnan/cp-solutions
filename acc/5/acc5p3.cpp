#include <bits/stdc++.h>
#define ll long long

using namespace std;
int s[100000];

int main() {
    int n, k, temp1, temp2; 
    ll psum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        psum += temp1;
        s[i] = temp1 - temp2;
    }
    
    sort(s, s+n);
    reverse(s, s+n);
    ll ssum = 0;
    for (int i = 0; i < k; i++) {
        ssum += s[i];
    }
    
    cout << psum - ssum << "\n";
    
    return 0;
}