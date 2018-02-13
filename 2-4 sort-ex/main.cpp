//debug1 mergee函数中比较结构体的子数据，但并不是往temp里只赋值子数据，而是整个结构
//学习知识 归并排序
#include <iostream>
#include <algorithm>

using namespace std;
typedef struct _player{
    int id;
    long long int point;
    long long int ability;
}player;
void mergee(player a[],player winner[],player loser[],player temp[],int n){
    int i = 1;
    int j = 1;
    int k = 1;
    while(i <= n && j <= n){
        if(winner[i].point > loser[j].point || (winner[i].point == loser[j].point
                                               && winner[i].id < loser[j].id)) temp[k++] = winner[i++];
        else temp[k++] = loser[j++];
    }
    while(i <= n) temp[k++]= winner[i++];
    while(j <= n) temp[k++]= loser[j++];
    for (int l = 0; l < k; ++l) {
        a[l] = temp[l];
    }
};

bool cmp(player p1,player p2)
{
    return (p1.point  == p2.point ? p1.id < p2.id : p1.point > p2.point);
}
bool cmp2(player p1,player p2)
{
    return p1.ability > p2.ability;
}
int main() {
    freopen("in.txt","r",stdin);
    int n,r,q;
    cin >> n >> r >> q;
    player a[200002];
    player winner[100002];
    player loser[100002];
    player temp[200002];
    for (int i = 1; i <= 2*n; ++i) {
        cin >> a[i].point;
        a[i].id = i;
    }
    for (int i = 1; i <= 2*n; ++i) {
        cin >> a[i].ability;
    }
    sort(a+1,a+2*n+1,cmp);
    for (int i = 0; i < r; ++i) {
        int k = 1;
        for (int j = 1; j <= 2*n - 1; j = j+2) {
            if(a[j].ability > a[j+1].ability) {
                a[j].point++;
                winner[k] = a[j];
                loser[k++] = a[j+1];
            }
            else {
                a[j+1].point++;
                winner[k] = a[j+1];
                loser[k++] = a[j];
            }
        }
        mergee(a,winner,loser,temp,n);
    }
    cout << a[q].id;
    return 0;
}