
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
int solution(int n) {
    int answer = 0;
    int cnt=GetCount(n);
    while(cnt!=GetCount(++n)){
        
    }
    answer=n;
    return answer;
}
