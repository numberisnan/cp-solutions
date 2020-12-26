
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

ll pre[1000000];
ll* ptr = pre;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, inp, offset = 0;
    cin >> n >> d;

    cin >> pre[0];

    loopfrom(1, i, n) {
        cin >> inp;
        pre[i] = pre[i-1] + inp;
    }

    loop(i, d) {
        cin >> inp;
        //cout << inp; nl;
        if (ptr[inp-1] - offset >= ptr[n-1] - ptr[inp-1]) {
            //cout << "snap left"; nl;
            cout << ptr[inp-1] - offset; nl;
            offset += ptr[inp-1] - offset;
            ptr += inp;
            n -= inp;
            //cout << "Adding " << ptr[inp-1] << " to offset"; nl;
        } else {
            //cout << "snap right"; nl;
            cout << ptr[n-1] - ptr[inp-1]; nl;
            n = inp;
        }

        /*for (int i = 0; i < n; i++) {
            cout << ptr[i] << " ";
        } nl;*/
    }

    return 0;
}
