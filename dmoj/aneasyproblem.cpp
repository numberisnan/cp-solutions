//begintemplate S
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";
#define INF 10e9;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, maxl = 1, lim = 50;
    bool flag;

    cin >> n;

    if (n > lim) {
      int temp, total = 0;
      vector<stack<int>> buckets;
      //buckets.push_back(tempStack);

      loop(i, n) {
          cin >> temp;
          flag = false;
          for (int j = 0; j < (int)(buckets.size()); j++) {
              //cout << buckets[j].top();
              if (temp & buckets[j].top()) {
                  buckets[j].push(temp);
                  flag = true;
              }
          }

          if (!flag) {
              // new bucket
              stack<int> newStack;
              newStack.push(temp);
              buckets.push_back(newStack);
          }
      }

      loop(i, (int)(buckets.size())) {
          total = max(total, (int)(buckets[i].size()));
          /*
          cout << "bucket: " << i << "\n";
          while (buckets[i].size()) {
              cout << buckets[i].top() << " ";
              buckets[i].pop();
          }
          nl;*/
      }

      cout << total;
    } else {
      int arr[n], dp[n];

      loop(i, n) {
        cin >> arr[i];
        if (!i) {
          dp[i] = 1;
          continue;
        }
        dp[i] = 1;
        for (int j = i-1; j >= 0; j--) {
          if (arr[j] & arr[i]) {
            dp[i] = max(dp[i], dp[j]+1);
          }
        }

        maxl = max(maxl, dp[i]);
      }

      cout << maxl;
    }
    //nl;
    //printarrn(dp, n);
    
    return 0;
}
//endtemplate S