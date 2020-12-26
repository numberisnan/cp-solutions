//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

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
    deque<int> stack, res;
    int n, temp;
    bool flag;
    
    cin >> cases;

    loop(c, cases) {
      cin >> n;
      stack.clear();
      res.clear();

      loop(i, n) {
        cin >> temp;
        stack.push_back(temp);
      }

      res.push_back(stack.front());
      stack.pop_front();

      flag = true;

      while (stack.size()) {
        if (stack.back() == res.front() - 1) {
          res.push_front(stack.back());
          stack.pop_back();
        } else if (stack.back() == res.back() + 1) {
          res.push_back(stack.back());
          stack.pop_back();
        } else if (stack.front() == res.front() - 1) {
          res.push_front(stack.front());
          stack.pop_front();
        } else if (stack.front() == res.back() + 1) {
          res.push_back(stack.front());
          stack.pop_front();
        } else {
          flag = false;
          break;
        }
      }

      cout << "Case #" << c+1 << ": " << (flag ? "yes" : "no"); nl;
    }

    return 0;
}
//endtemplate S