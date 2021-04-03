#include <bits/stdc++.h>
#include <vector>
#include <bitset>
#define loop(i, n) for(int i = 0; i < n; i++)
#define nl cout << "\n"
#define ll long long

using namespace std;
int n, p[200000], w[200000], d[200000];
ll trypos(int pos) {
    ll t = 0;
    loop(i, n) {
        if (p[i] == pos) {
            t += 0;
        } else if (p[i] < pos) {
            t += (pos - p[i] - d[i])*w[i];
        } else {
            t += (p[i] - pos - d[i])*w[i];
        }
    }

    return t;
}


int main() {

    cin >> n;

    double s = 0;
    double weight = 0;
    double final;

    loop(i,n) {
        cin >> p[i] >> w[i] >> d[i];
        s += (double)p[i]/w[i];
        weight += 1/(double)w[i];
    }

    final = s / weight;
    ll besttime = 100000000;
    int bestpos = 0, res;
    int thresh = 5000;

    for (int i = final-thresh; i < final + thresh; i++) {
        res = trypos(i);
        if (res < besttime) {
            besttime = res;
            bestpos = i;
        }
    }

    cout << besttime << " " << bestpos; nl;



    return 0;
}