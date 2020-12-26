
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
bool e[201][401];
struct pos {
    int x, y;
    int getx() {
        return (x - 200);
    }
    int gety() {
        return -y;
    }
    bool move(char d, int m) {
        if (d == 'd') {
            for (int i = y+1; i <= y + m; i++) {
                if (e[i][x]) {
                    y += m;
                    return false;
                }
                e[i][x] = true;
            }
            y += m;
            //cout << y;nl;
        } else if (d == 'u') {
            for (int i = y-1; i >= y - m; i--) {
                if (e[i][x]) {
                    y = y-m;
                    return false;
                }
                e[i][x] = true;
            }
            y = y-m;
        } else if (d == 'l') {
            for (int i = x-1; i >= x - m; i--) {
                if (e[y][i]) {
                    x = x - m;
                    return false;
                }
                e[y][i] = true;
            }
            x = x - m;
        } else {
            for (int i = x+1; i <= x + m; i++) {
                if (e[y][i]) {
                    x = x + m;
                    return false;
                }
                e[y][i] = true;
            }
            x = x + m;
            //cout << x;nl;
        }

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pos p = {200, 1};

    vector<pair<char, int>> moves = {{'d', 2}, {'r', 3}, {'d', 2}, {'r', 2}, {'u', 2}, {'r', 2}, {'d', 4}, {'l', 8}, {'u', 2}};

    for (auto mo : moves) {
        p.move(mo.first, mo.second);
    }

    char d;
    int m;
    cin >> d >> m;
    while (d != 'q') {
        if (!p.move(d, m)) {
            cout << p.getx() << " " << p.gety() << " DANGER";nl;
            break;
        } else {
            cout << p.getx() << " " << p.gety() << " safe";nl;
        }
        cin >> d >> m;
    }

    for (auto row : e) {
        //printarrn(row, 401)
    }

    return 0;
}
