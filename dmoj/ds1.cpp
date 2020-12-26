#include <bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define ll long long
#define nl cout << "\n";

using namespace std;

template <typename T>
class BIT {
    private:
    T *BITarray;
    int size;
    public:
    BIT(T array[], int s) {
        size = s;
        BITarray = (T*)calloc(sizeof(T), size+1);
        assert(BITarray);
        
        fill_n(BITarray, size, 0);
        for (int i = 0; i < size; i++) {
            updateBIT(i, array[i]);
        }
    }
    ~BIT() {
        free(BITarray);
        BITarray = NULL;
    }
    void updateBIT(int in, int v) {
        in++;
        while (in <= size) {
            BITarray[in] += v;
            in += in & (-in);
        }
    }
    void display(int n) {
        loop(i, n) {
            cout << *(BITarray + i) << " ";
        }
        cout << "\n";
    }
    T queryFromStart(int i) { //Inclusive
        i++;
        T sum = 0;
        while (i > 0) {
            sum += BITarray[i];
            i -= i & (-i);
        }
        return sum;
    }   
    T query(int l, int r) { //Inclusive
        return queryFromStart(r) - queryFromStart(l-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n, m, currnum;
    cin >> n >> m;
    ll arr[n];
    ll freq[100001];
    fill_n(freq, 100001, 0);
    fill_n(arr, n, 0);
    loop(i, n) {
        cin >> currnum;
        arr[i] = currnum;
        freq[currnum-1]++;
    }
    

    BIT<ll> tree(arr, n);
    BIT<ll> freqtree(freq, 100001);

    string currop;
    ll f, s;
    loop(i, m) {
        cin >> currop;
        if (currop == "C") {
            cin >> f >> s;
            f--;
            tree.updateBIT(f, s - arr[f]);
            //freqtree.display(5);
            freqtree.updateBIT(arr[f]-1, -1); //decrement old
            freqtree.updateBIT(s-1, 1); //increment new
            //freqtree.display(5);
            freq[arr[f]-1]--;
            //cout << s-1 << "==s-1\n";
            freq[s-1]++;
            arr[f] = s;
            //printarr(arr)
            //printarrn(freq, 9);
        } else if (currop == "S") {
            cin >> f >> s;
            cout << tree.query(f-1, s-1) << "\n";
        } else {
            // Q
            cin >> f;
            cout << freqtree.queryFromStart(f-1) << "\n";
        }
    }

    return 0;
}

/*
Test
5 5
1 2 3 4 5
Q 2
S 1 3
C 2 5
Q 2
S 1 3
*/