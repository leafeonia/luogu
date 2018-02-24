#include <iostream>
#include <vector>
using namespace std;
typedef struct _node{
    char ch;
    char l,r;
}node;
vector<node> tree;
char judge(string s){
    int zero =0;
    int one = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '0') zero = 1;
        else one = 1;
    }
    if(zero && one) return 'F';
    else if(zero && !one) return 'B';
    else return 'I';
}
char solve(string s){
    if(s.size() == 1){
        node a;
        a.ch = judge(s);
        a.l = '*';
        a.r = '*';
        tree.push_back(a);
        return a.ch;
    }
    node a;
    a.ch = judge(s);
    int mid = s.size()/2;
    a.l = solve(s.substr(0,mid));
    a.r = solve(s.substr(mid,s.size()));
    tree.push_back(a);
}
int main() {
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    solve(s);
    for (int i = 0; i < tree.size(); ++i) {
        cout << tree[i].ch;
    }
    return 0;
}