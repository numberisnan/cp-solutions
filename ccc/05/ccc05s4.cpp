#pragma GCC optimize("Ofast")

#include <unordered_set>
#include <vector>
#include <iostream>
#include <map>
#include <stack>

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

    int cases;
    stack<string> enc;
    vector<string> inp;

    cin >> cases;
    loop(cn, cases) {
        while (!enc.empty()) {
            enc.pop();
        }
        inp.clear();

        string name;
        int n;

        cin >> n;
        loop(i, n) {
            cin >> name;
            inp.push_back(name);
        }

        int old = (int)inp.size();
        string prev = inp[n-1];
        int maxdepth = 0;
        enc.push("dfdsfdsfa");

        loop(i, n) {
            if (inp[i] != enc.top()) {
                enc.push(prev);
                prev = inp[i];
            } else {
                // prev is a leaf
                maxdepth = max(maxdepth, (int)enc.size()-1);
                prev = enc.top();
                enc.pop();
            }
        }

        cout << (old*10) - (maxdepth*20); nl;
        //cout << old << " " << maxdepth; nl;
    }

    return 0;
}
