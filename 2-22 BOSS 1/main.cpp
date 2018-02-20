
#include <iostream>
#include <cstring>
typedef struct _node{
    bool fish;
    short right,left,down,leftdown,rightdown;
}node ;
node pond[2202][2202];
using namespace std;
int main() {
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false); //!!!加了这个就过了！运行时间缩短一半！
    memset(pond,0,sizeof(pond));
    int n,m;
    short ans = 0;
    cin >> n >> m;
    short cnt,temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> pond[i][j].fish;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = m-1; j >= 0; --j) {
            if(pond[i][j].fish == 1){
                cnt = 1;
                while(1){
                    if(i + cnt > n-1) break;
                    if(pond[i+cnt][j].fish == 1)break;
                    cnt++;
                }
                pond[i][j].down = cnt;
                cnt = 1;
                while(1){
                    if(j - cnt < 0) break;
                    if(pond[i][j-cnt].fish == 1)break;
                    cnt++;
                }
                pond[i][j].left = cnt;
                cnt = 1;
                while(1){
                    if(j+cnt > m-1) break;
                    if(pond[i][j+cnt].fish == 1)break;
                    cnt++;
                }
                pond[i][j].right = cnt;
                cnt = 1;
                while(1){
                    if(i + cnt > n-1 || j - cnt < 0) break;
                    if(pond[i+cnt][j-cnt].fish == 0)break;
                    if(pond[i+cnt][j-cnt].leftdown) {cnt+=pond[i+cnt][j-cnt].leftdown;break;}
                    cnt++;
                }
                pond[i][j].leftdown = cnt;
                cnt = 1;
                while(1){
                    if(i + cnt > n-1 || j + cnt  > m-1) break;
                    if(pond[i+cnt][j+cnt].fish == 0)break;
                    if(pond[i+cnt][j+cnt].rightdown) {cnt+=pond[i+cnt][j+cnt].rightdown;break;}
                    cnt++;
                }
                pond[i][j].rightdown = cnt;
                if(pond[i][j].down <= ans) continue;//短路，down <= ans时ans值不可能被更新
                temp = min(pond[i][j].down,pond[i][j].left);
                temp = min(temp,pond[i][j].leftdown);
                for (int k = 1; k < temp; ++k) {
                    while(pond[i+k][j-k].left < temp - k || pond[i+k][j-k].down < temp - k) temp--;
                    if(temp <= ans) break;
                }
                ans = max(temp,ans);
                temp = min(pond[i][j].down,pond[i][j].rightdown);
                temp = min(temp,pond[i][j].right);
                for (int k = 1; k < temp; ++k) {
                    if(pond[i+k][j+k].left < temp - k || pond[i+k][j+k].down < temp - k) temp--;
                    if(temp <= ans)break;
                }
                ans = max(temp,ans);
            }
        }
    }
    cout << ans;
    return 0;
}