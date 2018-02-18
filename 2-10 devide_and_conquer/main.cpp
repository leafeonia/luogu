
#include <iostream>
#include <cstring>
using namespace std;
long long int quick(long long int b,long long int p,long long int k){
    int ans = 1;
    b = b % k;
    while(p!=0){
        if(p&1!=0) ans = (ans*b)%k;
        p>>=1;
        b = (b*b)%k;
    }
    return ans;
}
int main(){
    freopen("in.txt","r",stdin);
    long long int b,p,k;
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k <<"=" << quick(b,p,k);
    return 0;
}