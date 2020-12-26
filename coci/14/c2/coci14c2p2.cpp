//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define INFint numeric_limits<int>::max()

using namespace std;
//int arr[1000000];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    unordered_set<string> count;

    int n;
    string name;
    cin >> n;

    loop(i, 2*n - 1) {
      cin >> name;
      if (count.find(name) == count.end()) {
        count.insert(name);
      } else {
        count.erase(name);
      }
    }

    cout << *count.begin();
    
    return 0;
}
//endtemplate S