
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


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

bitset<3001> adj[3001];
vector<int> graph[3001];

vector<int> smallerTri(vector<int> a, vector<int> b) {
    loop(i, 3) {
        if (a[i] > b[i]) {
            return b;
        } else if (b[i] > a[i]) {
            return a;
        }
    }

    return a; // defualt case
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, from, to;
    cin >> n >> m;

    loop(i, m) {
        cin >> from >> to;
        adj[from][to] = 1;
        adj[to][from] = 1;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    loopfrom(1, i, n+1) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> tri;
    bool flag = false;

    // try to find any triangles
    loopfrom(1, i, n+1) {
        for (int v1 : graph[i]) {
            for (int v2 : graph[i]) {
                if (adj[v1][v2]) {
                    tri = {i, v1, v2};
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << 3; nl;
            printarrn(tri, 3);
            return 0;
        }
    }

    vector<int> e1, e2 = {};
    // check for 4

    //get e1
    int i = 1;
    while (!graph[i].size()) i++;
    e1 = {i, graph[i][0]};

    // get e2
    i++;
    if (i == e1[1]) {
        i++;
    }
    while (i <= n) {
        flag = false;
        for (int next : graph[i]) {
            if (next != e1[0] && next != e1[1]) {
                flag = true;
                e2 = {i, next};
                break;
            }
        }
        if (flag) {
            break;
        }
        i++;
        if (i == e1[1]) {
            i++;
        }
    }
    if (e2.empty()) {
        cout << -1; nl;
        return 0;
    }

    tri = {e1[0], e1[1], e2[0], e2[1]};
    sort(tri.begin(), tri.end());

    cout << 4; nl;
    printarrn(tri, 4);

    return 0;
}
