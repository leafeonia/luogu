
#include <iostream>
#include <cctype>
using namespace std;


int main() {
    freopen("in.txt","r",stdin);
    int n;
    int x[] = {1,1,1,0,0,-1,-1,-1};
    int y[] = {1,0,-1,1,-1,1,0,-1};
    char ans[] = {'i','z','h','o','n','g'};
    char a[102][102];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[i][j] == 'y')
            {
                for (int k = 0; k < 8; ++k) {
                    int flag = 1;int xx,yy;
                    for (int l = 0; l < 6; ++l) {
                        xx += x[k];
                        yy += y[k];
                        if(xx < 0 || xx >= n || yy < 0 || yy >= n){
                            flag = 0;
                            break;
                        }
                        if(tolower(a[xx][yy]) != ans[l]){
                            flag = 0;break;
                        }
                    }
                    if(flag){
                        a[i][j] = 'Y';
                        for (int l = 1; l <= 6; ++l) {
                            a[i+l*x[k]][j+l*y[k]] = toupper(a[i+l*x[k]][j+l*y[k]]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(isupper(a[i][j])) cout << a[i][j];
            else cout << '*';
        }
        cout << endl;
    }
    return 0;
}