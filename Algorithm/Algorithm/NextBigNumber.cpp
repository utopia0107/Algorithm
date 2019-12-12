#include <iostream>
using namespace std;

int GetCount(int n)
{
    int cnt=0;
    while(n>0){
        if(n%2==1)cnt++;
        n/=2;
    }
    return cnt;
}
int main()
{
    
    int n,cnt;
    cin>>n;
    cnt=GetCount(n);
    while(cnt!=GetCount(++n)){}
    cout<<n;
}

