#include <bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    bitset<1000000> count;
    int n, a, b, temp, pairs = 0;

    cin >> n >> a >> b;
    loop(i, a) {
        cin >> temp;
        count[temp] = 1;
    }
    loop(i, b) {
        cin >> temp;
        if (count[temp]) {
            pairs++;
        }
    }

    cout << (n - pairs);
    

    return 0;
}
