
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
#define print(a) cout << a; nl;

using namespace std;

int graph[751];
bool g[751][751];

struct node {
    int x, y;
};

node blds[751];

struct edge {
    int from, to;
};

vector<edge> cables;

bool operator<(const edge& lhs, const edge& rhs)
{
    return lhs.from < rhs.from;
}

priority_queue<pair<double, edge>> edges;

int n;
double distance(node a, node b) {
    return pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
}

int find(int i) {
    if (graph[i] == i) {
        return i;
    } else {
        int res = find(graph[i]);
        graph[i] = res;
        return res;
    }
}

void unite(int a, int b) {
    int ha = find(a);
    int hb = find(b);

    graph[hb] = ha;
    //cout << "adasdas";
}

bool connected() {
    if (n == 1) {
        return true;
    }
    int g = find(1);
    loopfrom(2, i, n+1) {
        if (find(i) != g) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, e, from, to;

    cin >> n;

    loop(i, n) {
        cin >> x >> y;
        blds[i+1] = {x, y};
        graph[i+1] = i+1;
    }

    cin >> e;

    loop(i, e) {
        cin >> from >> to;
        edges.push({0, {from, to}});
        g[from][to] = true;
        g[to][from] = true;
    }

    loopfrom(1, i, n+1) {
        loopfrom(1, j, n+1) {
            if (i != j && !g[i][j] && !g[j][i]) {
                edges.push({-distance(blds[i], blds[j]), {i, j}});
                //cout << i << " " << j; nl;
                g[i][j] = true;
                g[j][i] = true;
            }
        }
    }

    //printarrn(graph, n+1); nl;

    bool flag = (n == 1);
    double total = 0;
    while (!flag) {
        auto e = edges.top();
        //cout << e.first; nl;
        //cout << e.second.from << " " << e.second.to; nl; nl;
        edges.pop();
        //printarrn(graph, n+1); nl;
        if (find(e.second.from) != find(e.second.to)) {
            unite(e.second.from, e.second.to);
            total += -e.first;
            //cout << -e.first; nl;
            //cout << e.second.from << " " << e.second.to; nl; nl;
            if (e.first) {
                cables.push_back(e.second);
            }
            flag = connected();
        }
    }

    //printarrn(graph, n+1); nl;

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << total; nl;
    loop(i, (int)cables.size()) {
        cout << cables[i].from << " " << cables[i].to; nl;
    }
    //printarrn(graph, n+1); nl;

    return 0;
}
