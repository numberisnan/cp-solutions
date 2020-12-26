//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INFint numeric_limits<int>::max()

using namespace std;
//int arr[1000000];

struct node {
  unordered_set<int> in, out;
};

node arr[10002];
unordered_set<int> nq;

void dfs(int n) {
  cout << "Searching: " << n << " in size : " << arr[n].in.size(); nl;
  if (arr[n].in.size()) {
    return;
  }
  nq.erase(n);
  if (!arr[n].out.size()) {
    return;
  }
  for (int a : arr[n].out) {
    arr[n].out.erase(a);
    arr[a].in.erase(n); // remove edge
    dfs(a);
  }

  cout << "Ending: " << n; nl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, e, from, to;

    cin >> n >> e;

    for(int i = 1; i <= n; i++) {
      nq.insert(i);
    }

    loop(i, e) {
      cin >> from >> to;
      arr[from].out.insert(to);
      arr[to].in.insert(from);
    }

    loopfrom(1, i, n+1) {
      cout << "Node: " << i; nl;
      cout << "In: ";
      auto p = arr[i].in.begin();
      while (p != arr[i].in.end()) {
        cout << *p << " ";
        p++;
      }
      nl;
      cout << "Out: ";
      p = arr[i].out.begin();
      while (p != arr[i].out.end()) {
        cout << *p << " ";
        p++;
      }
      nl;
    }
    nl;
    
    for(int i = 1; i <= n; i++) { //all nodes
      dfs(i); nl;
    }

    cout << (nq.size() ? "N" : "Y"); nl;
    
    return 0;
}
//endtemplate S