#include <bits/stdc++.h>
#include <vector>
#define loop(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main() {
    int curr, next, n, temp;
    cin >> n;
    vector<long> h, w;
    long long s = 0;

    loop(i, n+1) {
        cin >> temp;
        h.push_back(temp);
    }

    loop(i, n) {
        cin >> temp;
        w.push_back(temp);
    }

    for (int i = 1; i < n+1; i++) {
        s += (h[i]+h[i-1])*w[i-1];
    }

    if (s % 2) {
        cout << s/2 << ".5\n";
    } else {
        cout << s/2 << "\n";
    }


    return 0;
}

