
#include <iostream>
#include <cstring>
int n,m;
int record = -1;
int currentmax = 0;//每次dfs一个点，记录该点的最长滑道距离
int mountain[103][103];
int ans[103][103];
int plain[103][103];//预处理，记录洼地坐标
int dire[5][3] = {{1,0},{-1,0},{0,1},{0,-1}};
bool valid(int i,int j){
    int flag = 0;
    for (int k = 0; k < 4; ++k) {
        int next_x = i + dire[k][0];
        int next_y = j + dire[k][1];
        if(next_x < 1 || next_x > n || next_y < 1 || next_y > m ) continue;
        if(mountain[next_x][next_y] >= mountain[i][j]) continue;
        flag = 1;
        break;
    }
    return flag;
}
using namespace std;
void dfs(int i,int j,int le){
    if(plain[i][j] == 1){
        if(le > record) record = le;
        if(le > currentmax) currentmax = le;
        return;
    }
    if(ans[i][j]){
        le += (ans[i][j] - 1);
        if(le > record) record = le;
        if(le > currentmax) currentmax = le;
        return;
    }
    int updated_i,updated_j;
    for (int k = 0; k < 4; ++k) {
        updated_i = i + dire[k][0];
        updated_j = j + dire[k][1];
        if(updated_i < 1 || updated_i > n || updated_j < 1 || updated_j > m ) continue;
        if( mountain[updated_i][updated_j] >= mountain[i][j]) continue;
        le++;
        dfs(updated_i,updated_j,le);
        le--;
    }

}
int main() {
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(plain,0, sizeof(plain));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mountain[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(!valid(i,j)) plain[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            currentmax = 0;
            dfs(i,j,1);
            ans[i][j] = currentmax;
        }
    }
    cout << record;
    //test TLE
    /*for (int i = 0; i < 100; ++i) {
        if(i % 2 == 0){
            for (int j = 0; j < 100; ++j) {
                cout << i*100 + j + 1 << ' ';
            }
            cout << '\r' << '\n';
        }
        else
        {
            for (int j = 99; j >= 0; --j) {
                cout << i*100 + j + 1 << ' ';
            }
            cout << '\r' << '\n';
        }
    }*/
    return 0;
}