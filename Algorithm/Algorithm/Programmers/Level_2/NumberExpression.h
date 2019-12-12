//
//  NumberExpression.h
//  Algorithm
//
//  Created by 민수 정  on 12/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef NumberExpression_h
#define NumberExpression_h
#include <string>
#include <vector>

using namespace std;
bool Check(int start,int n)
{
    int num=0;
    for(int i=start;i<=n;i++)
    {
        num+=i;
        if(num==n)return true;
        if(num>n)return false;
    }
}
int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        if(Check(i,n))answer++;
    }
    return answer;
}

#endif /* NumberExpression_h */
