
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

// From https://dmoj.ca/tips/
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INF(type) numeric_limits<type>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<bool> s;
    int n, temp;
    string ex;
    bool exp;

    cin >> n;

    loop(i,n) {
        cin >> temp;
        if (temp == 1) {
            cin >> ex;
            exp = (ex == "true" ? true : false);
            if (s.find(exp) == s.end()) {
                cout << "true";
            } else {
                cout << "false";
            }
            s.insert(exp);
        } else if (temp == 2) {
            cin >> ex;
            exp = (ex == "true" ? true : false);
            if (s.find(exp) == s.end()) {
                cout << "false";
            } else {
                cout << "true";
            }
            s.erase(exp);
        } else if (temp == 3) {
            cin >> ex;
            exp = (ex == "true" ? true : false);
            int i = 0;
            int ans = -1;
            auto it = s.begin();
            while (it != s.end()) {
                if (*it == exp) {
                    ans = i;
                    break;
                }
                it++;
                i++;
            }

            cout << ans;
        } else {
            for (auto b : s) {
                cout << (b ? "true" : "false") << " ";
            }
        }

        nl;
    }

    return 0;
}
