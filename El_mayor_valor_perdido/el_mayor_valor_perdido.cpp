/*
* Solucion aportada por el profesor de la FdI (UCM):
* Solution given by FdI's (UCM) professor:
*   ANTONIO ALEJANDRO SANCHEZ RUIZ-GRANADOS
*/
#include <iostream>
#include <vector>

using namespace std;

// v[a..b] is ordered, has at least 2 elements, and there is at least
// one value missing
int greatestMissingValue(const vector<int>& v, int a, int b) {
    int r;
    if (a + 1 == b) {
        // 2 elements and 1 missing
        r = v[b] - 1;
    }
    else {
        // more than 2 elements.
        // we know the missing value is on the right half if it does not contain
        // only consecutive numbers.
        // we need to make sure than the new vectors have at least 2 elements
        int m = (a + b) / 2;
        if (v[b] - v[m] > b - m)
            r = greatestMissingValue(v, m, b);
        else
            r = greatestMissingValue(v, a, m);
    }
    return r;
}

// Let be n = b-a+1 then
// T(n) = c0 if n == 2
// T(n) = T(n/2) + c if n > 2
// a = 1, b = 2, k = 0 -> a = b^k -> O(n^k * log n) = O(log n)

bool solve() {
    int n, q;
    cin >> n >> q;
    if (n == 0 && q == 0)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << greatestMissingValue(v, a, b) << endl;
    }
    return true;
}

int main() {
    while (solve());
}