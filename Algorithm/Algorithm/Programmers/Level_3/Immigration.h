//
//  Immigration.h
//  Algorithm
//
//  Created by 정민수 on 2020/04/30.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Immigration_h
#define Immigration_h
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
long long CheckTime(vector<int> v ,long long maxTime)
{
    long long count=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>maxTime)break;
        count+=maxTime/(long long)v[i];
    }
    return count;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long start=0,end=times[times.size()-1]*(long long)n;
    while(start<end)
    {
        long long mid = (start+end)/2;
        if(CheckTime(times,mid)>=n)
        {
            end=mid;
        }else
        {
            start=mid+1;
        }
    }
    answer=end;
    return answer;
}

#endif /* Immigration_h */
