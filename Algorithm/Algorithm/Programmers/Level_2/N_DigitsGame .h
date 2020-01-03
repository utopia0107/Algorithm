//
//  N_DigitsGame .h
//  Algorithm
//
//  Created by 민수 정  on 03/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef N_DigitsGame__h
#define N_DigitsGame__h

#include <string>
#include <vector>
using namespace std;
string numbers[]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
int base;
void AddN_Convert(int num,int memberCnt,int myNumber,int* curOrder,string* answer)
{
     string convert="";
    if(num==0)convert+=numbers[0];
    else{
        while(num>0)
        {
            convert+=numbers[num%base];
            num/=base;
        }
    }
    for(int i=convert.size()-1;i>=0;i--)
    {
        if(*curOrder==myNumber)
        {
            answer->append(convert.substr(i,1));
        }
         *curOrder= (*curOrder+1)%memberCnt;
    }
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    int number=0;
    int curOrder=0;
    base=n;
    while(answer.size()<=t)
    {
        AddN_Convert(number++,m,p-1,&curOrder,&answer);
    }
    answer=answer.substr(0,t);
    return answer;
}
#endif /* N_DigitsGame__h */
