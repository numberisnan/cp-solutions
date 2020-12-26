#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int s, f;
    string ss, sf;

    getline(cin, ss);
    getline(cin, sf);

    s = stoi(ss);
    f = stoi(sf);

    int count = 0;

    for (int i = 1; i <= 32; ++i) {
        int r = pow(i, 6);
        if (r <= f && r >= s) {
            count++;
        }
    }

    cout << count;
}