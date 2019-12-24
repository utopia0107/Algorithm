//
//  NumberGame.h
//  Algorithm
//
//  Created by 민수 정  on 24/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef NumberGame_h
#define NumberGame_h
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int length=A.size();
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    int cnt=0;
    for(int i=0;i<length;i++)
    {
        if(A[i]<B[i-cnt])
        {
            answer++;
        }
        else
        {
            cnt++;
        }
    }
    return answer;
}

#endif /* NumberGame_h */
