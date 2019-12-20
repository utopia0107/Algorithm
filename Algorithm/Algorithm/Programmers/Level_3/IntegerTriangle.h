//
//  IntegerTriangle.h
//  Algorithm
//
//  Created by 민수 정  on 20/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef IntegerTriangle_h
#define IntegerTriangle_h
#include <string>
#include <vector>
using namespace std;
int dp[500][500];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
        
   
    for(int i=1;i<triangle.size();i++)
    {
        //가장 좌측 노드
        dp[i][0]=triangle[i][0]+dp[i-1][0];
        //가운데 노드
        for(int j=1;j<i;j++)
        {
            dp[i][j]=triangle[i][j]+ max(dp[i-1][j-1],dp[i-1][j]);
        }
        //가장 우측 노드
        dp[i][i]=triangle[i][i]+dp[i-1][i-1];
    }
  
    for(int i=0;i<triangle.size();i++)
    {
        answer=max(answer,dp[triangle.size()-1][i]);
    }
    return answer;
}

#endif /* IntegerTriangle_h */
