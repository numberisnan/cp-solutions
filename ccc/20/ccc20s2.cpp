#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <utility>
#pragma GCC optimize("Ofast")

using namespace std;

vector<pair<int, int>> findall(vector<vector<int>> &arr, int n) {
    vector<pair<int, int>> ans;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j] == n) {
                arr[i][j] == 0;
                ans.push_back(make_pair(i, j));
            }
        }
    }

    return ans;
}

void buildadj(vector<vector<int>> &vals, vector<vector<int>> &nodenums, int r, int c, bool &found, bool &con, bool vis[]) {
    vis[nodenums[r][c]] = true;

    if (!con) {
        return;
    }
    //cout << r + 1 << " " << c+1 << "\n";

    vector<pair<int, int>> searchResults = findall(vals, (r+1) * (c+1));
    for (auto coord : searchResults) {
        if (!nodenums[coord.first][coord.second]) {
            found = true;
            con = false;
            return;
        }
    }

    for (auto coord : searchResults) {
        //cout << "Seach r: " << coord.first + 1 << " " << coord.second + 1 << " " << nodenums[coord.first][coord.second] << " " << vis[nodenums[coord.first][coord.second]] << "\n";
        if (!vis[nodenums[coord.first][coord.second]]) {
            //cout << "here";
            buildadj(vals, nodenums, coord.first, coord.second, found, con, vis);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m;

    cin >> n;
    cin >> m;
    vector<vector<int>> vals;
    vals.resize(n);
    vector<vector<int>> nodenums;
    nodenums.resize(n);
    int currnum, nodenumcount = 0;

    for (int i = 0; i < n; i++) {
        //cout << i << "i " << n << "n ";
        for (int j = 0; j < m; j++) {
            //cout << j << "j " << m << "m ";
            cin >> currnum;
            vals[i].push_back(currnum);
            //cout << nodenums.size() << " " << nodenumcount << " ";
            nodenums[i].push_back(nodenumcount);
            nodenumcount++;
        }
    }

    bool a = false;
    bool c = true;
    bool vis[n * m];
    fill_n(vis, n * m, false);

    buildadj(vals, nodenums, n-1, m-1, a, c, vis);

    cout << (a ? "yes" : "no");

    return 0;
}