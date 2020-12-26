
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

bool isValid(string n) {
    cout << "Checking: " << n; nl;
    int l = n.length();
    if (n == "") {
        return false;
    } else if (l == 1) {
        return n[0] == 'A';
    } else {
        if (n[0] == 'B') {
            // find matching s
            int b = 0, s = 0, i;
            loopfrom(1, i, l) {
                if (n[i] == 'B') {
                    b++;
                } else if (n[i] == 'S') {
                    s++;
                }

                if (s > b) {
                    break;
                }
            }

            if (i == l-1) {
                // matching s found, at the last character
                return isValid(n.substr(1, l-2));
            } else if (i == l) {
                return false;
            } else {
                // mathing s is not the last char, or there is no matching s
                //process n
                int ni = 1;
                while (n[ni] != 'N' && n[ni-1] != 'S' && ni < l) {
                    cout << ni << " " << n[ni] << n[ni-1]; nl;
                    ni++;
                }
                ni++;

                //cout << ni << " " << n[ni] << n[ni-1]; nl;

                if (ni == l) {
                    //no n found
                    return false;
                } else {
                    return isValid(n.substr(0, ni)) && isValid(n.substr(ni+1, l-ni-1));
                }

            }
        } else {
            //process n
            int ni = 0;
            while (n[ni] != 'N' && ni < l) {
                ni++;
            }

            if (ni == l || ni == 0) {
                //no n found
                return false;
            } else {
                return isValid(n.substr(0, ni)) && isValid(n.substr(ni+1, l-ni-1));
            }
        }



        /**

        if (j == l-1 && n[0] == 'B') {
            return isValid(n.substr(1, l-2));
        }

        if (i == l) {
            // no n
            if (n[0] == 'B' && n[l-1] == 'S') {
                return isValid(n.substr(1, l-2));
            } else {
                return false;
            }
        } else {
            //cout << "Checking: " << n.substr(0, i) << " " << n.substr(i+1, l-i-1); nl;
            return isValid(n.substr(0, i)) && isValid(n.substr(i+1, l-i-1));
        }
         **/
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string inp;
    cin >> inp;
    while (inp != "X") {
        cout << (isValid(inp) ? "YES" : "NO"); nl;
        cin >> inp;
    }

    return 0;
}
