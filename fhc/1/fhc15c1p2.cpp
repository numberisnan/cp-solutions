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

struct ch {
  char val;
  bool unique;
  vector<ch> next;

  ch* find(char n) {
    loop(i, next.size()) {
      if (next[i].val == n) {
        return &next[i];
      }
    }
    return NULL;
  }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int c;
    cin >> c;

    loop(i, c) {
      int n;
      string temp;
      ch* curr;
      ch* next;
      cin >> n;

      ch start = {' ', true, {}};
      
      loop(i, n) {
        cin >> temp;
        curr = &start;
        loop(id, temp.length()) {
          if (curr->next.size() > 1) {
            
          }
          next = curr->find(temp[id]);
          if (next != NULL) {
            curr = next;
          } else {
            curr->next.push_back({temp[id], true, {}});
            curr = &(curr->next[0]);
          }
        }
      }
    }
    
    return 0;
}
//endtemplate S