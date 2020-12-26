
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

    string l;
    char d;

    vector<string> landm;
    string dir = "";
    int j = 0;

    while (l != "SCHOOL") {
        cin >> d >> l;
        landm.push_back(l);
        dir = dir + d;
        j++;
    }

    for (int i = 0; i < j; i++) {
        if (dir[i] == 'L') {
            dir[i] = 'R';
        } else {
            dir[i] = 'L';
        }
    }

    reverse(dir.begin(), dir.end());
    landm.pop_back();
    reverse(landm.begin(), landm.end());
    landm.push_back("HOME");

    //cout << landm.size() << " " << j << flush;

    for (int i = 0; i < j-1; i++) {
        cout << "Turn " << (dir[i] == 'L' ? "LEFT" : "RIGHT") << " onto " << landm[i] << " street."; nl;
    }

    cout << "Turn " << (dir[j-1] == 'L' ? "LEFT" : "RIGHT") << " into your HOME."; nl;

    return 0;
}
