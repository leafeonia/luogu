#include <iostream>
using namespace std;
int n,k;
int ans = 0;
void dfs(int num,int tot,int depth){
    if(depth == k){
        if(tot == n) ans++;
        return;
    }
    for (int i = num; i <= n - tot; ++i) {
        dfs(i,tot+i,depth+1);
    }
}
int main() {
    freopen("in.txt","r",stdin);
    cin >> n >> k;
    dfs(1,0,0);
    cout << ans;
    return 0;
}