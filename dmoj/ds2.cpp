
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


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

int un = 0;

struct edge {
    int from, to, len;
};

int g[100001];
int r[100001];

int find(int i) {
    if (g[i] == i) {
        return i;
    } else {
        int res = find(g[i]);
        g[i] = res;
        return res;
    }
}

bool unite(int a, int b) {
    int ha = find(a);
    int hb = find(b);

    if (hb == ha) return false;
    if (r[ha] > r[hb]) {
        g[hb] = ha;
    } else if (r[ha] < r[hb]) {
        g[ha] = hb;
    } else {
        g[hb] = ha;
        r[ha]++;
    }

    un++;
    return true;
}

int n;
vector<int> tree;

bool connected() {
    return un == n-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, u, v;
    cin >> n >> m;

    loop(i, n) {
        g[i] = i;
        r[i] = 0;
    }

    loop(i, m) {
        if (connected()) {
            break;
        }
        cin >> u >> v;
        if (unite(u, v)) {
            tree.push_back(i+1);
        }
    }

    if (connected()) {
        for (int e : tree) {
            cout << e; nl;
        }
    } else {
        cout << "Disconnected Graph"; nl;
    }




    

    return 0;
}
