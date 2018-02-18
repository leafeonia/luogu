#include <iostream>
#include <string.h>
#define mmax 28
#define Nmax 30005
using namespace std;
int main() {
    int price[mmax],impo[mmax],result[Nmax];
    memset(result,0, sizeof(result));
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> price[i] >> impo[i];
    }
    for (int j = 1; j <= m; ++j) {
        for (int k = n; k >= price[j]; --k) {
            result[k] = max(result[k],result[k-price[j]]+price[j]*impo[j]);
        }
    }
    cout << result[n] << endl;
    return 0;
}