//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF numeric_limits<int>::max();

using namespace std;
pair<int,int> arr[1000000];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, a;
    cin >> n;

    loop(i, n) {
      cin >> a;
      arr[i] = {a, i};
    }

    sort(arr, arr+n);

    int i = 0;
    int j = n - 1;
    int res, m = INF;
    pair<pair<int,int>,pair<int,int>> matches;

    while (i < j) {
      res = abs(arr[j].first + arr[i].first);
      if (res < m || (res == m && (arr[j].second < matches.second.second || arr[i].second < matches.first.second))) {
        if (m == res) {
          //cout << ": " << i << " " << j;
        }
        m = res;
        matches = {arr[i], arr[j]};
      }

      if (res >= 0) {
        // move left pointer
        j--;
      } else {
        i++;
      }
    }

    cout << m << "\n" << min(matches.first.second,matches.second.second)  + 1 << " " << max(matches.first.second,matches.second.second) + 1;
    //nl; cout <<  << " " << arr[matches.second];

    
    return 0;
}
//endtemplate S