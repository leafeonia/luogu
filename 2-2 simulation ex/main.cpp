#include <iostream>
#include<cmath>
#include<string.h>
using namespace std;
int amount[10002];
int pre(int i)
{
    for (int j = i-1; j > 0; --j) {
        if(amount[j]!= -1) return j;
    }
}
int after(int i)
{
    for (int j = i+1; j < 10002; ++j) {
        if(amount[j]!= -1) return j;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int gov;
    cin >> gov;
    memset(amount,-1, sizeof(amount));
    int price,num;
    int cost;
    int flag = 0;
    int rec = 0;
    while(cin >> price >> num && !(price == -1 && num == -1))
    {
        amount[price] = num;
        rec = price;
        if(!flag)
        {
            cost = price;
            flag = 1;
        }
    }
    int decr;
    cin >> decr;
    int temp = rec+1;
    while(amount[temp-1] - decr > 0)
    {
        amount[temp] = amount[temp-1] - decr;
        temp++;
    }
    for (int i = cost+1; i < temp; ++i) { //此时temp是最后一个销量大于0的价格的下标+1
        if(amount[i] == -1) amount[i] = amount[pre(i)]-(amount[pre(i)] - amount[after(i)])/(after(i) - pre(i));
    }
    int result = 10003,govprofit,tempprofit;
    for (int j = -10002; j < 10002; ++j) {
        govprofit = (gov - cost + j)*amount[gov];
        int flag = 1;
        for (int i = cost; i < temp; ++i) {
            tempprofit = (i - cost + j)*amount[i];
            if(tempprofit > govprofit)
            {flag = 0;
                break;}
        }
        if(flag && abs(j) < abs(result)) result = j;

    }
    if(result == 10003) cout << "NO SOLUTION" << endl;
    else cout << result <<endl;
    return 0;
}

