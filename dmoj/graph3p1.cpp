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

struct edge {
    int from, to;
};

bitset<30001> offices;
unordered_set<int> graph[30001];
int depth[30001];
vector<edge> edges;

void bfs() {
    queue<int> q;
    depth[0] = 0;

    q.push(0);
    int curr;
    while (!q.empty()) {
        curr = q.front();
        q.pop();

        for (int n : graph[curr]) {
            if (depth[n] == -1) {
                depth[n] = depth[curr] + 1;
                q.push(n);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_n(depth, 30001, -1);

    int n, m, from, to, k, office;
    cin >> n >> m;
    loop(i, m) {
        cin >> from >> to;
        edges.push_back({from, to});
    }

    cin >> k;
    loop(i, k) {
        cin >> office;
        offices[office] = 1;
    }

    for (edge e : edges) {
        if (offices[e.from]) {
            e.from = 0;
        }
        if (offices[e.to]) {
            e.to = 0;
        }

        graph[e.to].insert(e.from);
        graph[e.from].insert(e.to);
    }

    bfs();

    cout << *max_element(depth, depth+n+1); nl;

    return 0;
}
