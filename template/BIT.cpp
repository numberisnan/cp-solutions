#include <bits/stdc++.h>

using namespace std;

//begintemplate BIT
#define loop(i, n) for(int i = 0; i < n; i++)
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
//endtemplate BIT

int main() {
    int c[] = {1, 5, 6, 2, 8, 33, 66, 2, 4, 64, 2};
    BIT<int> a(c, 11);
    cout << a.query(2, 4);
    return 0;
}