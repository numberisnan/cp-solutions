
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>


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

    int temp, tests, n, currtrain;
    stack<int> branch, line;

    cin >> tests;

    loop(i, tests) {
        while(branch.size()) {
            branch.pop();
        }

        while(line.size()){
            line.pop();
        }

        cin >> n;

        currtrain = 1;
        loop(i, n) {
            cin >> temp;
            line.push(temp);
        }

        branch.push(0);

        while (line.size()) {
            if (line.top() == currtrain) {
                //cout << "Line to lake"; nl;
                line.pop();
                currtrain++;
            } else if (branch.top() == currtrain) {
                //cout << "Branch to Lake"; nl;
                branch.pop();
                currtrain++;
            }
            else {
                //cout << "Line to Branch"; nl;
                branch.push(line.top());
                line.pop();
            }
        }

        while (currtrain == branch.top()) {
            branch.pop();
            currtrain++;
            //cout << "Branch to Lake"; nl;
        }

        cout << (currtrain == n+1 ? "Y" : "N"); nl;
        //cout << currtrain; nl;

    }

    return 0;
}
