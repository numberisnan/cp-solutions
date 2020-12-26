#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string in, out;

    getline(cin, in);

    for (int i = 0; i < (int)in.length(); i++) {
        out += in[i];
        if (i > 1 && isupper(in[i]) && in[i-1] == ' ') {
            out.insert(out.end() - 2, '.');
        }
    }

    std::cout << out << '.';
    
    return 0;
}
