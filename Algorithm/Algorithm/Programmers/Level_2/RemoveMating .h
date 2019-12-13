//
//  RemoveMating .h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef RemoveMating__h
#define RemoveMating__h

#include<string>
#include <vector>
using namespace std;


int solution(string s)
{
    int answer = 1;
    int sum=0;
    if(s.size()%2==1)return 0;
     for(int i=0;i<s.size();i++)
     {
         if(i%2==0)
         {
             sum+=s[i];
         }
         else
         {
             sum-=s[i];
         }
     }
    answer=sum==0?1:0;

    return answer;
}

#endif /* RemoveMating__h */
