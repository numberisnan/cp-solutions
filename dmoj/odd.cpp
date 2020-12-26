//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define INFint numeric_limits<int>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, temp, r = 0;
    cin >> n;

    loop(i, n) {
      cin >> temp;
      r ^= temp;
    }

    cout << r << "\n";
    
    return 0;
}
//endtemplate S