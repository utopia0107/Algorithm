//
//  BestSet.h
//  Algorithm
//
//  Created by 민수 정  on 19/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef BestSet_h
#define BestSet_h

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s){
        answer.push_back(-1);
    }
    else
    {
        int num=s/n;
        int remainder = s%n;
        for(int i=n-1;i>=0;i--)
        {
            if(remainder>i)
            {
                answer.push_back(num+1);
            }
            else
            {
                answer.push_back(num);
            }
        }
    }
    return answer;
}

#endif /* BestSet_h */
