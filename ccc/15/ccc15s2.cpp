//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define INFint numeric_limits<int>::max()

using namespace std;
int arr[1000001]; // 1 indexed

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int j, a, size, n, total = 0;
    char s;
    cin >> j >> a;

    loop(i, j) {
      cin >> s;
      if (s == 'S') {
        size = 1;
      } else if (s == 'M') {
        size = 2;
      } else {
        size = 3;
      }

      arr[i+1] = size;
    }

    loop(i, a) {
      cin >> s >> n;
      if (s == 'S') {
        size = 1;
      } else if (s == 'M') {
        size = 2;
      } else {
        size = 3;
      }

      if (arr[n] >= size) {
        total++;
        arr[n] = 0;
      }
    }

    cout << total;

    
    return 0;
}
//endtemplate S