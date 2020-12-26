//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF 10e9;

using namespace std;
bitset<361> angles, dp;
vector<int> selected;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k, a, s;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a;
        angles[a] = 1;
        // add all possible agles from that angle
        int currangle = (2*a) % 360;
        while (currangle != a) {
            angles[currangle] = 1;
            currangle = (currangle + a) % 360;
        }
    }

    loop(i, k) {
        cin >> s;
        selected.push_back(s);
    }

    for (int i = 1; i < *max_element(selected.begin(), selected.end()); i++) { // for each in dp
        loop(v, 361) {
            if (angles[v] && v <= i) {
                if (v <= i) {
                    angles[i] = angles[i-v];
                }
            }
        }
    }
    
    loop(i, k) {
      cout << (angles[selected[i]] ? "YES" : "NO") << "\n";
    }


    return 0;
}
//endtemplate S