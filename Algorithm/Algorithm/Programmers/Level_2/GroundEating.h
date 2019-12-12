//
//  GroundEating.h
//  Algorithm
//
//  Created by 민수 정  on 12/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef GroundEating_h
#define GroundEating_h
#include <iostream>
#include <vector>
using namespace std;
int dp[100000][4];
int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i=0;i<4;i++)
    {
        dp[0][i]=land[0][i];
    }
    for(int i=1;i<land.size();i++)
    {
        dp[i][0]=land[i][0] +max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
        dp[i][1]=land[i][1] +max(dp[i-1][0],max(dp[i-1][2],dp[i-1][3]));
        dp[i][2]=land[i][2] +max(dp[i-1][0],max(dp[i-1][1],dp[i-1][3]));
        dp[i][3]=land[i][3] +max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
    }
    int index=land.size()-1;
    answer=max(dp[index][0],max(dp[index][1],max(dp[index][2],dp[index][3])));

    return answer;
}


#endif /* GroundEating_h */
