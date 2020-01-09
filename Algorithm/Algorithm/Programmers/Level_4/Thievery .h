//
//  Thievery .h
//  Algorithm
//
//  Created by 민수 정  on 09/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Thievery__h
#define Thievery__h
#include <string>
#include <vector>
using namespace std;
int dp1[1000000][2];
int dp2[1000000][2];
int solution(vector<int> money)
{
    int answer = 0;
    int size=money.size();
    dp1[0][1]=money[0];
    for(int i=1;i<size-1;i++)
    {
        dp1[i][0]=max(dp1[i-1][1],dp1[i-1][0]);
        dp1[i][1]=dp1[i-1][0]+money[i];
    }
    for(int i=1;i<size-1;i++)
    {
        dp2[i][0]=max(dp2[i-1][1],dp2[i-1][0]);
        dp2[i][1]=dp2[i-1][0]+money[i];
    }
    
    answer=max(max(dp2[size-2][1],dp2[size-2][0]+money[size-1])
               ,max(dp1[size-2][1],dp1[size-2][0]));
    return answer;
}

#endif /* Thievery__h */
