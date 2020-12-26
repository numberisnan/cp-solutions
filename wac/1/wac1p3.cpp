#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &adj, int start, int &l, bool *vis) {
    vis[start] = true;

    //cout << "\n" << start + 1 << "\nadj: ";

    for (int node : adj[start]) {
        //cout << node + 1;
        if (!vis[node]) {
            l++; 
            dfs(adj, node, l, vis);
        }
    }
}

void findLeaves(vector<vector<int>> &adj, int start, int depth, vector<vector<int>> &leaves, bool vis[]) {
    vis[start] = true;

    //cout << "\n" << start + 1 << "\nadj: ";

    if (adj[start].empty()) {
        leaves[depth].push_back(start);
    } else {
        for (int node : adj[start]) {
            //cout << node + 1;
            if (!vis[node]) {
                findLeaves(adj, node, depth+1, leaves, vis);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<int>> adj;
    vector<vector<int>> radj;

    adj.resize(n);
    radj.resize(n);
    
    int input;
    for (int i = 1; i < n; i++) {
        cin >> input;
        adj[i].push_back(input-1);
        radj[input-1].push_back(i);
    }

    bool vis[n];
    fill_n(vis, n, false);
    bool rvis[n];
    fill_n(rvis, n, false);

    int l;
    vector<vector<int>> leaves;
    leaves.resize(100000);

    leaves.shrink_to_fit();

    findLeaves(radj, 0, 0, leaves, rvis);
    /*
    for (int i = 0; i < leaves.size(); i++) {
        cout << "DEPTH: " << i << " ";
        for (int leaf : leaves[i]) {
            cout << leaf << " ";
        }

        cout << "\n";
    }
    */

    vector<int> ans;
    vector<int> sortedLeaves;

    for (int i = leaves.size(); i >= 0; i--) {
        for (auto leaf : leaves[i]) {
            sortedLeaves.push_back(leaf);
        }
    }
    /*
    for (int leaf : sortedLeaves) {
        cout << "\n" << leaf; 
    }
    */
    

    for (int i = 0; i < min(m,k); i++) {
        if (i >= sortedLeaves.size()) {
            ans.push_back(0);
        } else {
            l = 1;
            dfs(adj, sortedLeaves.at(i), l, vis);
            ans.push_back(l);  
        }
        
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    if (m >= k) {
        for (int i = 0; i < m - k; i++) {
            ans.push_back(ans[i%n]);
        }
    } else {
        ans.resize(m);
    }

    cout << ans[0];
    ans.erase(ans.begin());

    for (int a : ans) {
        cout << " " << a;
    }

    cout << "\n";

    return 0;
}

/*
11 1 10
1 2 3 4 5 6 7 8 9 10

*/