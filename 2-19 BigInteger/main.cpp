#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
struct BigInteger{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> v;

    BigInteger (long long int num = 0){*this = num;}
    BigInteger operator = (long long num){
        v.clear();
        do{
            v.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInteger operator = (string s){
        v.clear();
        int x,len = ((s.length()-1) / WIDTH) + 1;
        for (int i = 0; i < len; ++i) {
            int end = s.length() - i*WIDTH;
            int start = max(0,end - WIDTH);
            sscanf(s.substr(start,end - start).c_str(),"%d",&x);
            v.push_back(x);
        }
        return *this;
    }

    BigInteger operator + (BigInteger &b){
        BigInteger c;
        c.v.clear();
        for(int i = 0,g = 0;;++i){
            if(g == 0 && i >= v.size() && i >= b.v.size()) break;
            int x = g;
            if (i < v.size()) x += v[i];
            if (i < b.v.size()) x += b.v[i];
            c.v.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
};
istream& operator >> (istream& in,BigInteger &b){
    string s;
    if(!(in >> s)) return in;
    b = s;
    return in;
}
ostream& operator << (ostream& out,BigInteger &b){
    out << b.v.back();
    for (int i = b.v.size() - 2; i >= 0;--i) {
        char buf[20];
        sprintf(buf,"%08d",b.v[i]);
        for (int j = 0; j < strlen(buf); ++j) {
            out << buf[j];
        }
    }
    return out;
}
int main() {
    freopen("in.txt","r",stdin);
    BigInteger a,b,c;
    cin >> a >> b;
    c = a + b;
    cout << c;
    return 0;
}