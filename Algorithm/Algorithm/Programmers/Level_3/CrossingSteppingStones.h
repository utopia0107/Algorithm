//
//  CrossingSteppingStones.h
//  Algorithm
//
//  Created by 정민수 on 2020/04/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef CrossingSteppingStones_h
#define CrossingSteppingStones_h
#include <string>
#include <vector>

using namespace std;

bool CheckCross(vector<int>stones,int k,int N)
{
    int cnt=0;
    for(int i=0;i<stones.size();i++)
    {
        if(stones[i]<N)
        {
            cnt++;
        }
        else cnt=0;
        if(cnt>=k)return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int start=0,end=200000000;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(CheckCross(stones,k,mid))
        {
            answer=mid;
            start=mid+1;
        }else
        {
            end=mid;
        }
    }
    return answer;
}

#endif /* CrossingSteppingStones_h */
