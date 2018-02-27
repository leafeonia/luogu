#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int main() {
    freopen("in.txt","r",stdin);
    int m,n;
    cin >> m >> n;
    int room[52][52];
    int dp[52][52][52][52];
    memset(dp,0, sizeof(dp));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> room[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= m-1; ++k) {
                for (int l = j+1; l <= n; ++l) {
                    dp[i][j][k][l] = max(max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),dp[i][j-1][k-1][l]),dp[i][j-1][k][l-1])+room[i][j]+room[k][l];
                }
            }
        }
    }
    cout << dp[m][n-1][m-1][n];
    return 0;
}