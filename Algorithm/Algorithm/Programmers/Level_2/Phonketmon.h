//
//  Phonketmon.h
//  Algorithm
//
//  Created by 민수 정  on 12/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Phonketmon_h
#define Phonketmon_h
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> phonketmonType;
    for(int i=0;i<nums.size();i++)
    {
        phonketmonType.insert(nums[i]);
    }
    answer=nums.size()/2>phonketmonType.size()?phonketmonType.size():nums.size()/2;
    return answer;
}


#endif /* Phonketmon_h */
