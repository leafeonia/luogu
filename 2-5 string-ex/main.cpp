//WA 1的宽度不是1，而是跟其他数字一样……
#include <iostream>
#include <string>
#define leftup screen[1+j][currentline] = '|';
#define leftdown screen[k+2+j] [currentline]= '|';
#define rightup screen[1+j] [currentline+k+1]= '|';
#define rightdown screen[k+2+j] [currentline+k+1]= '|';
#define up screen[0][currentline+1+j] = '-';
#define mid screen[k + 1][currentline+1+j] = '-';
#define down screen[2*k + 2][currentline+1+j] = '-';
using namespace std;
int main() {
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k;
    cin >> k;
    char screen[65][8000];
    for (int i = 0; i < 2*k + 3; ++i) {
        for (int j = 0; j < 8000; ++j) {
            screen[i][j] = ' ';
        }
    }
    string num;
    cin >> num;
    int currentline = 0;
    for (int i = 0; i < num.length(); ++i) {
        switch (num[i])
        {
            case ('0'):
                for (int j = 0; j < k; ++j) {
                    up;down;rightdown;rightup;leftdown;leftup;
                }
                currentline += (k+3);
                break;
            case ('1'):
                for (int j = 0; j < k; ++j) {
                    rightup;rightdown;
                }
                currentline += (k+3);
                break;
            case('2'):
                for (int j = 0; j < k; ++j) { up;mid;down;rightup;leftdown }
                currentline += (k+3);
                break;
            case('3'):
                for (int j = 0; j < k; ++j) { up;mid;down;rightup;rightdown}
                currentline += (k+3);
                break;
            case('4'):
                for (int j = 0; j < k; ++j) { mid;leftup;rightup;rightdown}
                currentline += (k+3);
                break;
            case('5'):
                for (int j = 0; j < k; ++j) { up;mid;down;leftup;rightdown}
                currentline += (k+3);
                break;
            case('6'):
                for (int j = 0; j < k; ++j) { up;mid;down;leftup;leftdown;rightdown}
                currentline += (k+3);
                break;
            case('7'):
                for (int j = 0; j < k; ++j) { up;rightup;rightdown}
                currentline += (k+3);
                break;
            case('8'):
                for (int j = 0; j < k; ++j) { up;mid; down;leftup;leftdown;rightup;rightdown}
                currentline += (k+3);
                break;
            case('9'):
                for (int j = 0; j < k; ++j) { up;mid;down;leftup;rightup;rightdown;}
                currentline += (k+3);
                break;
        }
    }
    for (int i = 0; i < 2*k + 3; ++i) {
        for (int j = 0; j < currentline; ++j) {
            cout << screen[i][j];
        }
        cout << endl;
    }
    return 0;
}