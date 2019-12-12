//
//  MinimumMake.h
//  Algorithm
//
//  Created by 민수 정  on 12/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef MinimumMake_h
#define MinimumMake_h

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    for(int i=0;i<A.size();i++)
    {
        answer+=A[i]*B[i];
    }
    return answer;
}
#endif /* MinimumMake_h */
