//
//  Scale.h
//  Algorithm
//
//  Created by 민수 정  on 18/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Scale_h
#define Scale_h

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
    long long answer = 1;
    //누적값
    vector<int> accumulate;
    accumulate.resize(weight.size());
    sort(weight.begin(),weight.end());
    accumulate[0]=weight[0];
    for(int i=1;i<weight.size();i++)
    {
        accumulate[i]=accumulate[i-1]+weight[i];
    }
    
    for(int i=0;i<weight.size()-1;i++)
    {
        if(accumulate[i]+1<weight[i+1])
        {
            return accumulate[i]+1;
        }
    }
    return accumulate[weight.size()-1]+1;
}

#endif /* Scale_h */
