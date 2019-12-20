//
//   WayToSchool.h
//  Algorithm
//
//  Created by 민수 정  on 20/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef _WayToSchool_h
#define _WayToSchool_h
#include <string>
#include <vector>
#include<cstring>

using namespace std;
int dp[101][101];
bool map[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    memset(map,true,sizeof(map));
    for(int i=0;i<puddles.size();i++)
    {
        map[puddles[i][1]][puddles[i][0]]=false;
    }
    dp[1][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j])dp[i][j]=(dp[i][j-1]+dp[i-1][j])%1000000007;
        }
    }
    answer=dp[n][m];
    return answer;
}

#endif /* _WayToSchool_h */
