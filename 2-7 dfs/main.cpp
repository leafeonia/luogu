//debug （1）忘记一个词最多用两次的条件造成无限循环 （2）for的处理 （3）长度要减去重叠部分的 （4）flag2循环部分，一个词用三次不会递归进入下一次搜索，但最大值已经更新了，增加判断条件usage[j <= 1
#include <iostream>
#include <string>
using namespace std;
int ans = 0;
int n;
int flag = 0;//用于处理一开始输入单字母的特殊情形，此时单字母必须包含于其他词，但别的情况下包含是不允许的
string wordlist[22];
int usage[22] = {0};
void dfs(string currentword,int length)
{
    for (int i = 1; i <= currentword.length(); ++i) {
        if(i == currentword.length() && flag) return;
        if(i == currentword.length() && !flag) flag = 1;
        for (int j = 0; j < n; ++j) { //遍历所有词
            int flag2 = 1;
            for (int k = 0; k < i && k < wordlist[j].length(); ++k) {  //从相接长度为1开始查起直到相接长度达到两词长度的较小值，满足条件就继续搜索
                if(wordlist[j][k] != currentword[currentword.length() - i + k]) {flag2 = 0;break;}
            }
            if(flag2) {
                if (length + wordlist[j].length() - i > ans && usage[j] <= 1) ans = length + wordlist[j].length()-i;
                usage[j]++;
                if(usage[j] <= 2) dfs(wordlist[j], length + wordlist[j].length()-i);
                usage[j]--;
            }
        }
    }
}
int main() {
    freopen("in.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> wordlist[i];
    }
    string openalphabet;
    cin >>openalphabet;
    dfs(openalphabet,1);
    cout << ans;
    return 0;
}