#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a,int b);
int main()
{
    freopen("in.txt","r",stdin);
    int row,column,k,l,dd;
    cin >> row >> column >> k >> l >> dd;
    int talkingrow[1002] = {0};//记录每行之上设立走道可以拆散多少对
    int talkingcolumn[1002] = {0};
    int a,b,c,d;
    for (int i = 0; i < dd; ++i) {
        cin >> a >> b >> c >> d;
        if(a == c && (d - b == 1 || b - d == 1) ) talkingcolumn[min(b,d)]++;
        else if(b == d && (c - a == 1 || a == c+1)) talkingrow[min(a,c)]++;
    }
    int aa[1002],bb[1002];
    for (int i = 0; i < k; ++i) {
        int maxn = -1;
        int p = 0;
        for (int j = 1; j <= row; ++j) {
            if (talkingrow[j] > maxn)
            {
                p = j;
                maxn = talkingrow[j];
            }
        }
        talkingrow[p] = 0;
        aa[i] = p;
    }
    sort(aa,aa+k,compare);
    for (int m = 0; m < k; ++m) {
        cout << aa[m] << " ";
    }
    cout << endl;
    for (int i = 0; i < l; ++i) {
        int maxn = -1;
        int p = 0;
        for (int j = 1; j <= column; ++j) {
            if (talkingcolumn[j] > maxn)
            {
                p = j;
                maxn = talkingcolumn[j];
            }
        }
        talkingcolumn[p] = 0;
        bb[i] = p;
    }
    sort(bb,bb+l,compare);
    for (int m = 0; m < l; ++m) {
        cout << bb[m] << " ";
    }
    cout << endl;

}
bool compare(int a,int b)
{
    return a < b;
}
