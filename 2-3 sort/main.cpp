//DEBUG : 数组下标0 1    降序要用 >
//学习知识 高精度入门 string比较大小
#include<bits/stdc++.h>
using namespace std;
struct BigInteger{
    static const int BASE=100000000;
    static const int WIDTH=8;
    vector<int> v;

    BigInteger(long long num = 0){ *this = num;}
    BigInteger operator = (long long num){
        v.clear();
        do{
            v.push_back(num % BASE);
            num /= BASE;
        }while (num > 0);
        return *this;
    }
    BigInteger operator = (const string& s){
        v.clear();
        int x;
        int start;
        int end;
        int i;
        int blocks;
        blocks=(s.length()-1)/WIDTH+1;
        for(i=0;i<blocks;i++){
            end=s.length()-i*WIDTH;
            start=max(0,end-WIDTH);
            sscanf(s.substr(start,end-start).c_str(),"%d",&x);
            v.push_back(x);
        }
        return *this;
    }
    BigInteger operator + (const BigInteger &b){
        BigInteger c;
        c.v.clear();
        int i,g;
        int x;
        for(i=0,g=0;;i++){
            if(g==0&&i>=v.size()&&i>=b.v.size()){//无进位，两个BigInteger实例均已遍历完成
                break;
            }
            x=g;
            if(i<v.size())
                x+=v[i];
            if(i<b.v.size())
                x+=b.v[i];
            c.v.push_back(x%BASE);
            g=x/BASE;
        }
        return c;
    }
    bool operator < (const BigInteger &b) const{
        if (v.size() != b.v.size()) return v.size() < b.v.size();
        for (int i = v.size()-1; i >= 0 ; --i) {
            if(v[i] != b.v[i]) return v[i] < b.v[i];
        }
        return false;
    }
};

istream& operator >> (istream &in, BigInteger &b){
    string x;
    if(!(in>>x)) return in;
    b=x;
    return in;
}

ostream& operator << (ostream &out,const BigInteger &b){
    int i;
    char buf[20];
    out<<b.v.back();//最高位不足8位的预防处理
    for(i=b.v.size()-2;i>=0;i--){
        sprintf(buf,"%08d",b.v[i]);//不足8位补0
        for (int j = 0; j < strlen(buf); ++j) {
            out << buf[j];
        }
    }
    return out;
}

typedef struct _candidate
{
    BigInteger num;
    int id;
}candidate;

bool cmp(candidate c1,candidate c2)
{
    return !(c1.num < c2.num);
}
int main(){
    freopen("in.txt","r",stdin);
    candidate a[22];
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >>a[i].num;
        a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    cout<< a[1].id <<endl;
    cout << a[1].num;
    return 0;
}


