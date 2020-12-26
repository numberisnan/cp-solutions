#include <bits/stdc++.h>
#define msc (mikaseat[1])
#define msr (mikaseat[0])

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int r, c;
    cin >> r;
    cin >> c;
    

    bool isFullSeats[r][c];
    int surroundingPeople[r][c] = {};
    int handshakes[r][c];
    string currow;

    for (int i = 0; i < r; i++) {
        cin >> currow;
        for (int j = 0; j < c; j++) {
            isFullSeats[i][j] = currow[j] == 'o';
            if (isFullSeats[i][j]) { 
                bool top = i > 0;
                bool bottom = i < r - 1;
                bool left = j > 0;
                bool right = j < c - 1; 

                if (top) {
                    if (left) {
                        ++surroundingPeople[i-1][j-1];
                    }
                    ++surroundingPeople[i-1][j];
                    if (right) {
                        ++surroundingPeople[i-1][j+1];
                    }
                }

                if (bottom) {
                    if (left) {
                        ++surroundingPeople[i+1][j-1];
                    }
                    ++surroundingPeople[i+1][j];
                    if (right) {
                        ++surroundingPeople[i+1][j+1];
                    }
                }

                if (left) { ++surroundingPeople[i][j-1]; }
                if (right) { ++surroundingPeople[i][j+1]; }
            }
        }
    }

    int mikaseat[2] = {0, 0};
    int maxhandShakes = -1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (surroundingPeople[i][j] > maxhandShakes && !isFullSeats[i][j]) {
                mikaseat[0] = i;
                mikaseat[1] = j;
                maxhandShakes = surroundingPeople[i][j];
            }
        }
    }

    if (maxhandShakes >= 0) {
        isFullSeats[msr][msc] = true;
        // Mika sits down!
        // Update surroundingPeople
        bool top = msr > 0;
        bool bottom = msr < r - 1;
        bool left = msc > 0;
        bool right = msc < c - 1; 

        if (top) {
            if (left) {
                ++surroundingPeople[msr-1][msc-1];
            }
            ++surroundingPeople[msr-1][msc];
            if (right) {
                ++surroundingPeople[msr-1][msc+1];
            }
        }

        if (bottom) {
            if (left) {
                ++surroundingPeople[msr+1][msc-1];
            }
            ++surroundingPeople[msr+1][msc];
            if (right) {
                ++surroundingPeople[msr+1][msc+1];
            }
        }

        if (left) { ++surroundingPeople[msr][msc-1]; }
        if (right) { ++surroundingPeople[msr][msc+1]; }

    }

    //Count up those handshakes!
    int sum = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum += isFullSeats[i][j] ? surroundingPeople[i][j] : 0;
            //cout << isFullSeats[i][j] <<  "        ";
        }
    }

    cout << int (sum / 2);


    return 0;
}