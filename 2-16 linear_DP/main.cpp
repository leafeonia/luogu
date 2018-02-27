
#include <iostream>
#include <algorithm>
#include <cstring>

typedef struct _task{
    int start,last;
}task;
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int n,k;
    cin >> n >> k;
    task list[10002];
    int work[10002]; //work[i]:第i分钟有没有工作开始？
    int dp[20002];
    memset(work,0, sizeof(work));
    memset(dp,0, sizeof(dp));
    for (int i = 0; i < k; ++i) {
        cin >> list[i].start >> list[i].last;
        work[list[i].start]++;
    }
    for (int j = n; j >= 1; --j) {
        if(!work[j])dp[j] = dp[j+1] + 1;
        else{
            for (int i = 0; i < k; ++i) {
                if(list[i].start == j) dp[j] = max(dp[j],dp[j+list[i].last]);
            }
        }
    }
    cout << dp[1];
    return 0;
}
