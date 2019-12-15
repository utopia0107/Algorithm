//
//  2xNTiling.h
//  Algorithm
//
//  Created by 민수 정  on 15/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef _xNTiling_h
#define _xNTiling_h
#include <string>
#include <vector>

using namespace std;
int dp[60001];
int solution(int n) {
    int answer = 0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
    }
    answer=dp[n];
    return answer;
}

#endif /* _xNTiling_h */
