#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int time[102],value[102],result[1002];
    memset(time,0, sizeof(time));
    memset(value,0, sizeof(value));
    memset(result,0, sizeof(result));
    int t,m;
    cin >> t >> m;
    for (int k = 1; k <= m; ++k) {
        cin >> time[k] >> value[k];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = t;j >= time[i];j--) {
            result[j] = max(result[j],result[j-time[i]]+value[i]);
        }
    }
    cout << result[t] << endl;
    return 0;
}