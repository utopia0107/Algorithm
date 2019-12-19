//
//  LongJump .h
//  Algorithm
//
//  Created by 민수 정  on 19/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef LongJump__h
#define LongJump__h
#include <string>
#include <vector>

using namespace std;
long long dp[2000][2];
long long solution(int n) {
    long long answer = 0;
    dp[1][0]=1;
    dp[2][0]=1;
    dp[2][1]=1;
    dp[2][0]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%1234567;
        dp[i][1]=(dp[i-2][0]+dp[i-2][1])%1234567;
    }
    answer= (dp[n][0]+dp[n][1])%1234567;
    return answer;
}

#endif /* LongJump__h */
