//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll unsigned long long
#define ull unsigned long long
#define INFint numeric_limits<int>::max()

using namespace std;
//int arr[1000000];
int vis[10000000];

int bfs(ll start, ll find) {
    if (start == find) {
      return 0;
    }
    queue<ll> q;
    ll n = 10000000;

    fill_n(vis, n, -1);
    q.push(start);
    vis[start] = 0;

    while (!q.empty()) {
        ll c = q.front();
        q.pop();

        vector<ll> set = {c-(ll)1, c-(ll)3};
        if (3*c < n) {
          set.push_back(3*c);
        }

        if (!(c&1)) { //even
          set.push_back(c/2);
        }
        for (ll node : set) {
            if (vis[node] == -1) {
                if (node == find) {
                  return vis[c]+1;
                }
                q.push(node);
                vis[node] = vis[c]+1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n, m;

    cin >> n >> m;
    int res = bfs(n, m);
    if (res == -1) {
      cout << n << " " << m;
    } else {
      cout << res;
    }


    
    return 0;
}
//endtemplate S