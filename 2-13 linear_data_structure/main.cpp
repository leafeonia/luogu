//debug 重复删除时要直接跳过，否则访问已删除的野指针
//debug 每次更新时更新四个关系，不是三个
#include <iostream>
using namespace std;
typedef struct _node{
    int id;
    _node *prev, *next;
}node;
int main() {
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    node* a[100002];
    int n,m,num,lr;
    cin >> n;
    node* head = new node;
    a[1] = head;
    a[1]->id = 1;
    a[1]->prev = a[1];
    a[1]->next = a[1];
    for (int i = 2; i <= n; ++i) {
        node* cur = new node;
        a[i]  = cur;
        a[i]->id = i;
        cin >> num >> lr;
        if(lr) {
            a[i]->prev = a[num];
            a[i]->next = a[num]->next;
            a[num]->next = a[i];
            a[i]->next->prev = a[i];
        }
        else{
            if(a[num] == head) head = a[i];
            a[i]->next = a[num];
            a[i]->prev = a[num]->prev;
            a[num]->prev = a[i];
            a[i]->prev->next = a[i];//画个图感受
        }
    }
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> num;
        if(!a[num]) continue;
        a[num]->prev->next = a[num]->next;
        a[num]->next->prev = a[num]->prev;
        delete a[num];
        a[num] = NULL;
    }
    node* temp = head;
    do{
        cout << temp->id << " ";
        temp = temp->next;
    }while(temp->id != head->id);
    return 0;
}