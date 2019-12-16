//
//  TileDecorations.h
//  Algorithm
//
//  Created by 민수 정  on 16/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef TileDecorations_h
#define TileDecorations_h

#include <string>

using namespace std;
long long dp[81];
long long solution(int N) {
    long long answer = 0;
    dp[1]=dp[2]=1;
    for(int i=3;i<=N;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    answer=dp[N]*2+(dp[N]+dp[N-1])*2;
    return answer;
}
#endif /* TileDecorations_h */
