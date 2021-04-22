
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>


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

vector<int> graph[1001];
int dis[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, from, to, n, a, b;

    cin >> l >> from >> to >> n;

    loop(i, n) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    queue<int> q;
    q.push(from);
    dis[from] = 0;

    bool vis[1001];
    fill_n(vis, 1001, false);
    int curr;

    while (q.size()) {
        curr = q.front();
        q.pop();
        for (int node : graph[curr]) {
            if (!vis[node]) {
                q.push(node);
                dis[node] = dis[curr] + 1;
                vis[node] = true;
            }
        }
    }

    cout << dis[to]; nl;



    return 0;
}
