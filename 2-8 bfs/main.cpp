//题解感悟：daanshuzuans也可以作为记录访问数组visited！每次访问后先把答案数组对应各记为1，然后在临时数组note里记录位置，最后执行完了把note里的格子在ans中全部置为cnt
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
int board[13][13];
int ans[13][13];
//int memo[1003][1003];
int note[100000][2];
int dire[5][4] = {{1,0},{-1,0},{0,1},{0,-1}};
typedef struct _point{
    int x;int y;
    _point(int x = 0,int y = 0):x(x),y(y){};
}point;
void bfs(int i,int j)
{
   //memset(memo,0,sizeof(memo));
    int cnt = 0;
    queue<point> q;
    point temp(i,j);
    point next;
    q.push(temp);
    cnt++;
    //memo[i][j] = 1;
    note[cnt][0] = i;
    note[cnt][1] = j;
    ans[i][j] = 1;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            next.x = temp.x + dire[k][0];
            next.y = temp.y + dire[k][1];
            if(next.x < 1 || next.x > n || next.y > n || next.y < 1 || board[temp.x][temp.y] + board[next.x][next.y] != 1 || ans[next.x][next.y] == 1) continue;
            //memo[next.x][next.y] = 1;
            cnt++;
            note[cnt][0] = next.x;
            note[cnt][1] = next.y;
            ans[next.x][next.y] = 1;
            q.push(next);
        }

    }
    for (int l = 1; l <= cnt; ++l) {
        ans[note[l][0]][note[l][1]] = cnt;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    memset(ans,-1,sizeof(ans));
    point pointlist[100003];
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> ch;
            board[i][j] = ch - '0';
        }
    }
    for (int k = 0; k < m; ++k) {
        cin >> pointlist[k].x >> pointlist[k].y;
    }
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(ans[i][j] == -1) bfs(i,j);
        }
    }*/
    for (int i = 0; i < m; ++i) {
        if(ans[pointlist[i].x][pointlist[i].y] != -1) cout <<  ans[pointlist[i].x][pointlist[i].y] << endl;
        else{
            bfs(pointlist[i].x,pointlist[i].y);
            cout << ans[pointlist[i].x][pointlist[i].y] << endl;
        }
    }
    return 0;
}