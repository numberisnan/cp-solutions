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
typedef pair<float, float> point;

string to_string(point a) {
  return "x: " + to_string(a.first) + "\ny: " + to_string(a.second) + "\n";
}

class line {
  float m, b;
  point p1, p2;
  public:
    line(point pnt1, point pnt2) {
      p1 = pnt1;
      p2 = pnt2;
      if (pnt1.first - pnt2.first == 0) {
        m = 0;
      } else {
        m = (pnt1.second - pnt2.second)/(pnt1.first - pnt2.first);
      }
      b = pnt1.second - (m*pnt1.first);
    }

    point sect(line s) {
      if (m - s.m == 0) {
        return {0, 0};
      }
      float x = (s.b - b) / (m - s.m);
      return {x, m*(x) + b};
    }

    line perpbisect() {
      point pnt = {(p1.first + p2.first) / 2, (p1.second + p2.second) / 2};
      return *(new line(pnt, {pnt.first + (pnt.second / (1/m)), 0}));
    }

    string tostring() {
      return "m: " + to_string(m) + "\nb: " + to_string(b) + "\n";
    }
};

//unordered_set<float> xs;
pair<float, float> sheep[100];
vector<pair<float, float>> poi;

float dis(point a, point b) {
  return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    float x, y;
    cin >> n;

    loop(i, n) {
      cin >> x >> y;
      //cout << x << " " << y; nl;
      sheep[i] = {x, y};
    }
    /*
    line a({0,0},{6, 6});
    cout << a.tostring() << a.perpbisect().tostring();
    point b = a.sect(a.perpbisect());
    cout << b.first << " " << b.second;*/

    //xs.clear();
    line xaxis({0, 0}, {1, 0});
    point poivar;
    loop(i, n) {
      loop(j, n) {
        if (i == j) {
          continue;
        }
        poivar = xaxis.sect(line(sheep[i], sheep[j]).perpbisect());
        if (poivar.first >= 0 && poivar.second <= 1000) {
          poi.push_back(poivar);
        }
      }
    }

    float m;
    vector<int> mini;
    float res;

    unordered_set<int> output;
    for (auto p : poi) {
      m = INF(float);
      mini.clear();
      loop(i, n) {
        res = dis(p, sheep[i]);
        if (m == res) {
          mini.push_back(i);
        }
        if (m > res) {
          mini.clear();
          m = dis(p, sheep[i]);
          mini.push_back(i);
        }
      }
      //cout << "Entry from: " << to_string(p);
      for (auto i : mini) {
        output.insert(i);
        //cout << "closest: " << to_string(sheep[i]);
      }
    }

    for (auto i : output) {
      printf("The sheep at (%.2f, %.2f) might be eaten.\n", sheep[i].first, sheep[i].second);
      //cout << i; nl;
    }

    //cout << to_string(dis({0, 0}, {1, 1})); nl;
    //cout << n; nl;

    return 0;
}
//endtemplate S