
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

    return 0;
}
