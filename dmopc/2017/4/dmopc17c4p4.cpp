
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

int g[1000001]; // the guarding sched
int first[1000001]; // first[i] is the first day bank i is guarded
int r[1000001]; // final robbing sched
unordered_set<int> guarded; // set of guarded banks

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill_n(first, 1000001, -1);
    fill_n(r, 1000001, 0);

    int n;
    cin >> n;

    loop(i, n) {
        cin >> g[i];
        if (first[g[i]] == -1) {
            first[g[i]] = i;
        }
        guarded.insert(g[i]);
    }

    if (guarded.size() == 1) { // Only 1 bank is guarded
        cout << "-1"; nl;
        return 0;
    }

    int temp;
    auto bank = guarded.begin();
    loop(i, (int)guarded.size()) { // Followed the editorial, except chose the bank after instead of before cause interators
        temp = *bank;
        advance(bank, 1);
        if (bank == guarded.end()) {
            bank = guarded.begin();
        }
        r[first[temp]] = *bank;
    }

    int next = 1;
    while (first[next] != -1 && next < 1000001) { // Fill in the rest
        next++;
    }
    loop(i, n) {
        if (r[i]) {
            continue;
        }
        r[i] = next;
        next++;
        while (first[next] != -1 && next < 1000001) {
            next++;
        }
    }

    printarrn(r, n); // Print
    return 0;
}
