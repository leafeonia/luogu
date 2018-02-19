#include <iostream>
#include <algorithm>
int n,m;
int ans = 0;
int cnt = 1;
typedef struct _node{
    int fish;
    int leftup,rightup,leftdown,rightdown;
}node ;
node pond[2502][2502];
/*
int checkleftup(int i,int j){
    if(i == 0 || j == 0) {pond[i][j].leftup = 1; return cnt;}
    if(pond[i][j].fish == 0) return cnt;

}

int checkrightup(int i,int j){
    if(i == 0 || j == m-1) { pond[i][j].rightup = 1; return cnt;}
}
*/
int checkleftdown(int i,int j){
    while(i + cnt - 1 != n-1 && j - cnt + 1 != 0 && pond[i + cnt - 1][j - cnt + 1].fish == 1){
        if(!check(i,j,cnt,-1)) break;
        cnt++;
    }
    return cnt;
    //if(i == n-1 || j == 0 || pond[i][j].fish == 0) return cnt;
}

int checkrightdown(int i,int j){
    while(i + cnt - 1 != n-1 && j + cnt - 1 != 0 && pond[i + cnt - 1][j + cnt - 1].fish == 1){
        if(!check(i,j,cnt,1)) break;
        cnt++;
    }
    return cnt;
}

using namespace std;
int main() {
    freopen("in.txt","r",stdin);
    cin >> n >> m;
    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> pond[i][j].fish;
           // if(pond[i][j].fish) pond[i][j].leftdown = pond[i][j].rightdown = pond[i][j].leftup = pond[i][j].rightup = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(pond[i][j].fish == 1){
                /*
                if(pond[i][j].leftup == 0) {
                    cnt = 1;
                    temp = checkleftup(i, j);
                    ans = max(ans, temp);
                }
                if(pond[i][j].rightup == 0) {
                    cnt = 1;
                    temp = checkrightup(i, j);
                    ans = max(ans, temp);
                }*/
               // if(pond[i][j].leftdown == 0) {
                    cnt = 1;
                    temp = checkleftdown(i, j);
                    ans = max(ans, temp);
                //}
                //if(pond[i][j].rightdown == 0) {
                    cnt = 1;
                    temp = checkrightdown(i, j);
                    ans = max(ans, temp);
                //}
            }
        }
    }
    cout << ans;
    return 0;
}