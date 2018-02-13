
#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    char c[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        s[i] = c[(s[i]-'a') + n % 26];
    }
    for (int i = 0; i < s.length(); ++i) {
        cout << s[i];
    }
    return 0;
}
